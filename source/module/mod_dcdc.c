#include "cs_common.h "
#include "drv_iic.h"
#include "mod_dcdc.h "
#include "app_main.h "
#include "app_init.h"
#include "lib_prot_pd.h"

BANK_DCDC sc8812a_data_t	dcdc_data;
BANK_DCDC uint8_t *cs8812a_p= NULL;

vol_flag_t volt_flag;
uint8_t temp_ibus_lim_bk;

/** quickly initialize and set parameter values**/
volatile const uint8_t dcdc_frame_buffer[]=
{
#if (CFG_BATT_CELLS== 1)
	0x42,						/** 0x00 RW	SC_VBAT_SET,	{IRCOMP->20 mΩ, CSEL->1S battery, VCELL_SET->4.25V}	**/
#elif(CFG_BATT_CELLS== 2)
	0x0d,						/** 0x00 RW	SC_VBAT_SET,	{IRCOMP->20 mΩ, CSEL->2S battery, VCELL_SET->4.25V}	**/
#elif(CFG_BATT_CELLS== 3)
	0x11,
#elif(CFG_BATT_CELLS== 4)
	0x19,
#endif
	0x33,						/** 0x01 RW	SC_VBUSREF_I_SET,	**/
	0xC0,						/** 0x02 RW	SC_VBUSREF_I_SET2,	**/
	0x40,						/** 0x03 RW	SC_VBUSREF_E_SET,	**/
	0x40,						/** 0x04 RW	SC_VBUSREF_E_SET2,	**/
	SC_IBUSLIM_03A40,			/** 0x05 RW	SC_IBUS_LIM_SET,	**/
	SC_IBATLIM_12A00,			/** 0x06 RW	SC_IBAT_LIM_SET,	**/
	SC_VINREG_04V7,				/** 0x07 RW	SC_VINREG_SET,	{VINREG-> 4700mV}	**/
//	0x26,						/** 0x08 RW	SC_RATIO,		{IBAT_RATIO->6x, IBUS_RATIO->6x, VBAT_MON_RATIO->5x, VBUS_RATIO->5x}	**/
    #if (CFG_BATT_CELLS== 1)
	 0x26,						/** 0x00 RW	SC_VBAT_SET,	{IRCOMP->20 mΩ, CSEL->1S battery, VCELL_SET->4.25V}	**/
	#elif(CFG_BATT_CELLS== 2)
	 0x24,		/** 0x00 RW	SC_VBAT_SET,	{IRCOMP->20 mΩ, CSEL->2S battery, VCELL_SET->4.25V}	**/
	#elif(CFG_BATT_CELLS== 3)
	 0x24,
	#elif(CFG_BATT_CELLS== 4)
	 0x24,
	#endif
	0x0C,						/** 0x09 RW	SC_CTRL0_SET,	{EN_OTG->charging, VINREG_RATIO->100x, FREQ_SET->450K, DT_SET->20ns}	**/
	// 0x00,					/** 0x09 RW	SC_CTRL0_SET,	{FREQ_SET->150KHz}	**/
	0x91,						/** 0x0A RW	SC_CTRL1_SET,	{ICHAR_SEL->IBAT, DIS_TRICKLE->enable, DIS_TERM->enable, FB_SEL->external, Trickle_SET->70%, DIS_OVP->enable}	**/
	0x08,						/** 0x0B RW	SC_CTRL2_SET,	{SoftStart_SET->0.0625mV/μs, EN_DITHER->disable, SLEW_SET->1mV/μs}	**/
	0xA8,						/** 0x0C RW	SC_CTRL3_SET,	{EN_PGATE->1, GPO_CTRL->0, AD_START->start, ILIM_BW_SEL->5kHz, LOOP_SET->Improve, DIS_ShortFoldBack->enable, EOC_SET->1/25, EN_PFM->disable}	**/
	0x00,						/** 0x0D R	SC_VBUS_FB_VALUE,	**/
	0x00,						/** 0x0E R	SC_VBUS_FB_VALUE2,	**/
	0x00,						/** 0x0F R	SC_VBAT_FB_VALUE,	**/
	0x00,						/** 0x10 R	SC_VBAT_FB_VALUE2,	**/
	0x00,						/** 0x11 R	SC_IBUS_VALUE,	**/
	0x00,						/** 0x12 R	SC_IBUS_VALUE2,	**/
	0x00,						/** 0x13 R	SC_IBAT_VALUE,	**/
	0x00,						/** 0x14 R	SC_IBAT_VALUE2,	**/
	0x00,						/** 0x15 R	SC_ADIN_VALUE,	**/
	0x00,						/** 0x16 R	SC_ADIN_VALUE2,	**/
	0x00,						/** 0x17 R	SC_STATUS,	**/
	0x00,						/** 0x18 R	SC_REG18,	**/
	0xFF,						/** 0x19 RW	SC_MASK,	**/
	0x88,						/** 0x1A RW	SC_DPDM_CTRL,	**/
	0x10,						/** 0x1B RW	SC_DPDM_READ,	**/
};


bool mod_dcdc_init(void)
{
	uint8_t temp;
	uint8_t i;
	
	bool dead_batt= true;
	
	/** iic port init**/
	iic_init();

	/** dcdc reg init**/
#if 0
	M_MEMCPY_ROM2RAM(BANK_DCDC_NUM, &dcdc_data.reg, &dcdc_frame_buffer[0], sizeof(dcdc_frame_buffer));
#else
	cs8812a_p= (BANK_DCDC uint8_t *)&dcdc_data.reg;
	for(i= 0; i< sizeof(dcdc_frame_buffer); i++)
	{
		*cs8812a_p++= dcdc_frame_buffer[i];
	}
#endif
	
	iic_transmit_bytes(SC_VBAT_SET, &dcdc_data.reg.vbat_set, SC_VBUS_FB_VALUE);
	iic_transmit_bytes(SC_MASK, &dcdc_data.reg.mask, SC_REG_NUM- SC_MASK);

	mod_dcdc_telemetry_reg_partition0();		//700uS
	mod_dcdc_telemetry_reg_partition1();		//800uS	
	
	/** dcdc reg check, {when the battery is dead, the initialization of the dcdc register fails}**/

#if 0
	M_MEMCMP(BANK_DCDC_NUM, &dcdc_data.reg, BANK0, &dcdc_frame_buffer[0], 0x0C);
	dead_batt= !r_memcmp_res;
#else
	cs8812a_p= (BANK_DCDC uint8_t *)&dcdc_data.reg;
	for(i= 0; i< 0x0C; i++)
	{
		if(*cs8812a_p++!= dcdc_frame_buffer[i])
		{
			dead_batt&= false;
		}
	}
	cs8812a_p= NULL;
#endif
	return dead_batt;
}


void mod_dcdc_telemetry_calculate(void)
{
	dcdc_data.telemetry.vbus_fb= mod_dcdc_telemetry_vbus();
	dcdc_data.telemetry.vbat_fb= mod_dcdc_telemetry_vbat();
	dcdc_data.telemetry.ibus_fb= mod_dcdc_telemetry_ibus();
	dcdc_data.telemetry.ibat_fb= mod_dcdc_telemetry_ibat();
	dcdc_data.telemetry.vbus_ref= mod_dcdc_telemetry_vbusref();
}

void mod_dcdc_telemetry_reg_partition0(void)
{
	/** read the first 13 registers**/
	iic_receive_bytes(0x00, (BANK_DCDC uint8_t *)&dcdc_data.reg, SC_VBUS_FB_VALUE);
}

void mod_dcdc_telemetry_reg_partition1(void)
{
	/** 15 registers after reading**/
	cs8812a_p= (BANK_DCDC uint8_t *)&dcdc_data.reg;
	cs8812a_p+= SC_VBUS_FB_VALUE;
	iic_receive_bytes(SC_VBUS_FB_VALUE, cs8812a_p, (SC_REG_NUM- SC_VBUS_FB_VALUE));
	cs8812a_p= NULL;
}

void mod_dcdc_write_otg_ctrl(bool status)
{
//    uint8_t data_temp8;
//    uint8_t RE_data_temp8; 
//
////   if(Sleep_up_flage)
////   return;		
//   
//    if(status)//// 1-----放电模式
//    {
////        if(!EN_SYS_INOTG)
//////        if(!OTG_ON)
////		{
////         EN_SYS_IN;///使能5500
////         EN_SYS_IN_Dischar;//// 放电配置
//////         OTG_ON=1;
////		}
//		RE_data_temp8=iic_receive_byte(0x35);
//		RE_data_temp8=RE_data_temp8|0x10;
////		iic_transmit_byte(0x35,RE_data_temp8);///// 放电配置函数控制/////
//    }
//    else///0--- 充电模式////
//    {
////		if(EN_SYS_INOTG)
//////	    if(OTG_ON)//OTG_ON
////		{
////		 EN_SYS_IN;///使能5500
////		 EN_SYS_IN_Char;//// 充电配置
//////         OTG_ON=0;
////		}
////          RE_data_temp8=iic_receive_byte(0x35);
////          RE_data_temp8=RE_data_temp8&0xef;
////          iic_transmit_byte(0x35,RE_data_temp8);//////配置 充电函数控制///// ///已屏蔽
//    }
}

void mod_dcdc_write_pgate_ctrl(bool status)
{
	if(status)
	{
     TCA_PIN_ON;
	}
	else
	{
     TCA_PIN_OFF;
	}
}

void mod_dcdc_write_gpo_ctrl(bool status)//
{
}
void mod_dcdc_write_vbusref_e_set(uint16_t _vbusref_e_set)		//放电vbus电压设置
{
   uint8_t data_temp8;
   uint8_t RE_data_temp8;
   data_temp8=_vbusref_e_set>>3;
   iic_transmit_byte(0x23,data_temp8 );
   data_temp8=_vbusref_e_set&0x07;
   iic_transmit_byte(0x24,data_temp8 );
}
void mod_dcdc_write_ibus_lim_set(uint8_t _ibus_limit_set)		//放电ibus电流设置
{
    _ibus_limit_set=_ibus_limit_set&0x7f;
    iic_transmit_byte(0x25,_ibus_limit_set);	//vus限流
}

void mod_dcdc_write_ibat_lim_set(uint8_t _ibat_limit_set)
{
	dcdc_data.reg.ibat_lim_set= _ibat_limit_set;
	iic_transmit_byte(SC_IBAT_LIM_SET, dcdc_data.reg.ibat_lim_set);
}

void mod_dcdc_write_vinreg_set(uint8_t _vinreg_set)
{
	dcdc_data.reg.vinreg_set= _vinreg_set;
	iic_transmit_byte(SC_VINREG_SET, dcdc_data.reg.vinreg_set);
}


BANK_DCDC uint8_t mod_dcdc_telemetry_status(void)
{
	return dcdc_data.reg.status;
}

BANK_DCDC uint16_t mod_dcdc_telemetry_vbus(void)
{
	return M_VBUS_FB(dcdc_data.reg.vbus_fb_value, dcdc_data.reg.vbus_fb_value2);
}

BANK_DCDC uint16_t mod_dcdc_telemetry_vbus_reg(void)
{
	return M_10BITREG_CAL(dcdc_data.reg.vbus_fb_value, dcdc_data.reg.vbus_fb_value2);
}

BANK_DCDC uint16_t mod_dcdc_rt_telemetry_vbus_reg(void)
{
	cs8812a_p= (BANK_DCDC uint8_t *)&dcdc_data.reg;
	cs8812a_p+= SC_VBUS_FB_VALUE;
	iic_receive_bytes(SC_VBUS_FB_VALUE, cs8812a_p, 2);
	cs8812a_p= NULL;
	return M_10BITREG_CAL(dcdc_data.reg.vbus_fb_value, dcdc_data.reg.vbus_fb_value2);
}

BANK_DCDC uint16_t mod_dcdc_telemetry_vbat(void)
{
	return M_VBAT_FB(dcdc_data.reg.vbat_fb_value, dcdc_data.reg.vbat_fb_value2);
}

BANK_DCDC uint16_t mod_dcdc_telemetry_vbat_reg(void)
{
	return M_10BITREG_CAL(dcdc_data.reg.vbat_fb_value, dcdc_data.reg.vbat_fb_value2);
}

BANK_DCDC uint16_t mod_dcdc_telemetry_ibus(void)
{
	return M_IBUS(dcdc_data.reg.ibus_value, dcdc_data.reg.ibus_value2);
}

BANK_DCDC uint16_t mod_dcdc_telemetry_ibus_reg(void)
{
	return M_10BITREG_CAL(dcdc_data.reg.ibus_value, dcdc_data.reg.ibus_value2);
}

BANK_DCDC uint16_t mod_dcdc_rt_telemetry_ibus_reg(void)
{
	cs8812a_p= (BANK_DCDC uint8_t *)&dcdc_data.reg;
	cs8812a_p+= SC_IBUS_VALUE;
	iic_receive_bytes(SC_IBUS_VALUE, cs8812a_p, 2);
	cs8812a_p= NULL;
	return M_10BITREG_CAL(dcdc_data.reg.ibus_value, dcdc_data.reg.ibus_value2);
}

BANK_DCDC uint16_t mod_dcdc_telemetry_ibat(void)
{
	return M_IBAT(dcdc_data.reg.ibat_value, dcdc_data.reg.ibat_value2);
}

BANK_DCDC uint16_t mod_dcdc_telemetry_ibat_reg(void)
{
	return M_10BITREG_CAL(dcdc_data.reg.ibat_value, dcdc_data.reg.ibat_value2);
}

BANK_DCDC uint16_t mod_dcdc_telemetry_vbusref(void)
{
	return M_VBUSE(dcdc_data.reg.vbusref_e_set, dcdc_data.reg.vbusref_e_set2);
}

BANK_DCDC uint16_t mod_dcdc_telemetry_vbusref_reg(void)
{
	return M_10BITREG_CAL(dcdc_data.reg.vbusref_e_set, dcdc_data.reg.vbusref_e_set2);
}
void mod_SC8886_init(void)
{
    ///////7201 处理///////
    uint8_t RE_data_temp8,TX_BAT,TX_V;
    uint8_t Readdata=0;
	//开A1,A2开关泄放
	Readdata = iic_receive_byte(0x0c);
	Readdata |= 0x0f; 
	iic_transmit_byte(0x0C,Readdata);	
	Readdata &= 0xf0; 
	iic_transmit_byte(0x0C,Readdata);				
	//-------------------------------------------
	//负载接入检测
	iic_transmit_byte(0x18,0x03);		
	//-------------------------------------------
	//充电设置1  电池节数设置 4串
	iic_transmit_byte(0x30,0x03);		
	//-------------------------------------------
	//充电目标电压  16.8V
	iic_transmit_byte(0x34,Data_720334);	
	iic_transmit_byte(0x35,Data_720335);		
	//-------------------------------------------
	//充电VBUS限压  4.5V
	iic_transmit_byte(0x38,0x05);			
	TX_BAT = iic_receive_byte(0x02);
	TX_V   = iic_receive_byte(0x34);		
	//-------------------------------------------
		//关闭充电 关闭放电
	RE_data_temp8 = iic_receive_byte(0x0D);
	RE_data_temp8 &= ~(1<<4);
	RE_data_temp8 &= ~1;
	iic_transmit_byte(0x0D,RE_data_temp8);
	
	
	RE_data_temp8 = iic_receive_byte(0x22);
//	RE_data_temp8 &= ~(1<<5);
    RE_data_temp8 =  RE_data_temp8|0x02;
    iic_transmit_byte(0x22,RE_data_temp8);
	
	
	
	
	if(TX_V != Data_720334)
	{	
		//开A1,A2开关泄放
		Readdata = iic_receive_byte(0x0c);
		Readdata |= 0x0f; 
		iic_transmit_byte(0x0C,Readdata);	
		Readdata &= 0xf0; 
		iic_transmit_byte(0x0C,Readdata);	
		//-------------------------------------------
		//负载接入检测
		iic_transmit_byte(0x18,0x03);		
		//-------------------------------------------
		//充电设置1  电池节数设置 4串
		iic_transmit_byte(0x30,0x03);		
		//-------------------------------------------
		//充电目标电压  16.8V
		iic_transmit_byte(0x34,Data_720334);	
		iic_transmit_byte(0x35,Data_720335);		
		//-------------------------------------------
		//充电VBUS限压  4.5V
		iic_transmit_byte(0x38,0x05);			
		TX_BAT = iic_receive_byte(0x02);
		TX_V   = iic_receive_byte(0x34);		
		//-------------------------------------------	
//		 BAT_Pro_Charge=1;
	}
}
void mod_dcdc_disable(void)
{
   	uint8_t Readdata=0;
   	uint8_t  reg;
	//-------------------------------------------
	//清中断标志1
	iic_transmit_byte(0x04,0xff);	
	//-------------------------------------------
	//清中断标志2
	iic_transmit_byte(0x05,0xff);
	///////////////////
//	BSP_RSET_USBTEST();
  //REG0C vbus泄放先写0再写1后写0
	Readdata = iic_receive_byte(0x0C);
	Readdata &= 0xF4;	
	iic_transmit_byte(0x0C,Readdata);	
	Readdata |= 0x0b;	
	iic_transmit_byte(0x0C,Readdata);
	Readdata &= 0xF4;	
	iic_transmit_byte(0x0C,Readdata);	
    /////////////////////////////////////
	//-------------------------------------------
	//工作模式清零
//	iic_transmit_byte(0x0d,0x00);
	reg = iic_receive_byte(0x0D);
	iic_transmit_byte(0x0D,reg&0xEE);//关闭充放电
	//-------------------------------------------
	//负载接入检测及低功耗模式控制
//	iic_transmit_byte(0x18,0x03);	
    iic_transmit_byte(0x18,0x00);
	//-------------------------------------------
	//关闭所有通路
	iic_transmit_byte(0x19,0x00);
}
void mod_charge_cur_deal(uint8_t charge_ibus_limit)		//充电vus输入限流设置
{
   ///////7201 处理/////// 
    iic_transmit_byte(0x39,charge_ibus_limit);
}
void  mod_charge_vol_deal(uint8_t charge_Vbus_limit)//// 默认 05 4.48V 限电压/////--没有修改////
{
//    uint8_t data_temp8;
//    uint8_t RE_data_temp8; 
//  
//    RE_data_temp8=iic_receive_byte(0x0A);
//    
//    RE_data_temp8=RE_data_temp8&0x3f;
//    iic_transmit_byte(0x0A,RE_data_temp8);
//  
//    RE_data_temp8=iic_receive_byte(0x0b);
//    RE_data_temp8=RE_data_temp8&0x80;
//    data_temp8=charge_Vbus_limit;
//    data_temp8=data_temp8&0x7f;
//    data_temp8=data_temp8|RE_data_temp8;
//    iic_transmit_byte(0x0b,data_temp8);
}

void mod_SC8886_Charge_init(void)
{
   ///////7201 处理///////
	uint8_t ReadData =0;
//	uint8_t RE_data_temp8;
	ReadData = iic_receive_byte(0x22);
//	ReadData &= ~(1<<5);
    ReadData =  ReadData|0x02;
    iic_transmit_byte(0x22,ReadData); 
	
	//充电目标电压h8
	iic_transmit_byte(0x34,Data_720334);		
	//涓充电目标电压L3
	iic_transmit_byte(0x35,Data_720335);	
	//vbus限流
    R_ChargeCur_DataBuff=PDO_cuurest_MA700;
    R_ChargeCur_Data=R_ChargeCur_DataBuff;
//	iic_transmit_byte(0x39,0x1E);
    iic_transmit_byte(0x39,R_ChargeCur_Data);
	//vbbat限流
	iic_transmit_byte(0x3A,0x77);
	//vbus限压
	iic_transmit_byte(0x38,0x05);	
	//涓流电压
	iic_transmit_byte(0x36,Data_720336);		
	//涓流迟滞,电流
//	iic_transmit_byte(0x37,0x00);
    iic_transmit_byte(0x37,0x04);////涓流 200ma 0000 0100
	//禁止适配器移出时清除充电开关控制位；
	ReadData = iic_receive_byte(0x30);
	ReadData |= 0x80;
	iic_transmit_byte(0x30,ReadData);	
	//打开充电
//	ReadData = iic_receive_byte(0x0D);
//	ReadData |= 0x10;
////	iic_transmit_byte(0x0D,ReadData);	
    mod_charge_ibat0_limit_deal(1);
    
    Charge_bat_low_power_F=0;
}

void mod_SC8886_DisCharge_init(void)
{
   ///////7201 处理///////
	uint8_t ReadData =0;
  //内部调压	
	ReadData = iic_receive_byte(0x20);
	ReadData &= 0xfe;
	iic_transmit_byte(0x20,ReadData);
	
	mod_dcdc_write_ibus_lim_set(Out_PD_A5000);
	iic_transmit_byte(0x26,0xff);	//vbat限流
	mod_dcdc_write_vbusref_e_set(Out_PD_5V);

    ///////打开放电 关闭充电
	ReadData = iic_receive_byte(0x0D);
	ReadData |= 1;
	ReadData &= ~(1<<4);
	iic_transmit_byte(0x0D,ReadData);
}

void  mod_charge_ibat_deal(uint8_t charge_Ibat_limit)
{ 

}

void  mod_charge_ibat0_limit_deal(uint8_t enable)
{
  ///////7201 处理///////
    uint8_t data_temp8;
    uint8_t RE_data_temp8; 
    RE_data_temp8=iic_receive_byte(0x0d);
	data_temp8=RE_data_temp8&0x10;
//	RE_data_temp8=RE_data_temp8&0x00;
    if(enable)
    {
		if(!data_temp8)///有关掉输入 则开启
		{
//		   iic_transmit_byte(0x0d,0x10); 
			RE_data_temp8 |= (1<<4);
			RE_data_temp8 &= ~1;
			iic_transmit_byte(0x0D,RE_data_temp8);//打开充电 关闭放电

		}
    }
    else
    {
		if(data_temp8)///有没有关掉输入 则关掉
		{
//		   iic_transmit_byte(0x0d,0x00); 
           	RE_data_temp8 &= ~(1<<4);
			RE_data_temp8 &= ~1;
			iic_transmit_byte(0x0D,RE_data_temp8);//打开充电 关闭放电
		}
    }
}
void  Mod_Dis_USBA_EN(uint8_t enable)
{
    uint8_t data_temp8;
    uint8_t RE_data_temp8;
    
//    if(USBA_EN_BK!=enable)
//    {
//        USBA_EN_BK=enable;
//		RE_data_temp8=iic_receive_byte(0x19);
//		data_temp8=RE_data_temp8&0x02;
		if(enable)
		{  
//		  if(!data_temp8)
//		  {
//			 RE_data_temp8=RE_data_temp8|0x02;
//			 iic_transmit_byte(0x19,RE_data_temp8); 
//		  }
          USBA_PIN_ON;
		}
		else
		{
//		  if(data_temp8)
//		  {
//			 RE_data_temp8=RE_data_temp8&0xfd;
//			 iic_transmit_byte(0x19,RE_data_temp8); 
//		  }
           USBA_PIN_OFF;
		}
//    }
}
void SW7203VbusDischarge(bool flag)//VBUS泄放电
{
	uint8_t reg = 0;
	reg = iic_receive_byte(0x0C);
	if(flag)
	{
		reg |= (1<<3);
		iic_transmit_byte(0x0C,reg);
	}
	else
	{
		reg &= ~(1<<3);
		iic_transmit_byte(0x0C,reg);
	}
}

void vbus_ibus_cheak(void)
{
// 	dcdc_data.telemetry.vbus_fb= multi_protocol.input.vbus_vol*25;
// //	dcdc_data.telemetry.ibus_fb= multi_protocol.input.ibus_cur;
	
// 	if(dcdc_data.telemetry.vbus_fb > 16000)
// 		volt_flag=VBUS_VOL_20V;
// 	else if(dcdc_data.telemetry.vbus_fb>13000)
// 		volt_flag=VBUS_VOL_15V;
// 	else if(dcdc_data.telemetry.vbus_fb>10000)
// 		volt_flag=VBUS_VOL_12V;
// 	else if(dcdc_data.telemetry.vbus_fb>8000)
// 		volt_flag=VBUS_VOL_9V;
// 	else 
// 		volt_flag=VBUS_VOL_5V;

// 	if(multi_protocol.input.vbus_vol > 650)
// 		volt_flag=VBUS_VOL_20V;
// 	else if(multi_protocol.input.vbus_vol>520)
// 		volt_flag=VBUS_VOL_15V;
// 	else if(multi_protocol.input.vbus_vol>400)
// 		volt_flag=VBUS_VOL_12V;
// 	else if(multi_protocol.input.vbus_vol>320)
// 		volt_flag=VBUS_VOL_9V;
// 	else 
// 		volt_flag=VBUS_VOL_5V;		
}

void app_power_adjust(uint8_t now_power_number)
{
	uint8_t temp_ibus_lim;
	
//	temp_ibus_lim= h_pd.output.sink_request_current* 10;
	/** 限制充电电流**/
	switch (volt_flag)
	{
		case VBUS_VOL_5V:
			temp_ibus_lim =50;				
			break;
		case VBUS_VOL_9V:
			if ((now_power_number & 0xF0) == 0x30)
			{
					temp_ibus_lim =35;
					break;
			}
			else
			{
				temp_ibus_lim =50;
			}																
			break;
			
		case VBUS_VOL_12V:
			switch (now_power_number & 0xF0)
			{
				case 0x20:
					temp_ibus_lim =35;
					break;

				case 0x30:
					temp_ibus_lim =20;
					break;
								
				default:
					temp_ibus_lim =50;
					break;
			}
			break;
			
		case VBUS_VOL_20V:
			switch (now_power_number & 0xF0)
			{
				case 0x00:
					temp_ibus_lim =50;
					break;

				case 0x10:
					temp_ibus_lim =35;
					break;

				case 0x20:
					temp_ibus_lim =20;
					break;

				case 0x30:
					temp_ibus_lim =8;
					break;
								
				default:
					temp_ibus_lim =50;
					break;
			}
			break;			
			
		default:
			break;
	}

	// if (temp_ibus_lim > (h_pd.output.sink_request_current* 10))
	// {
	// 	temp_ibus_lim = h_pd.output.sink_request_current* 10;
	// }
	
	if((temp_ibus_lim & 0x7f) != temp_ibus_lim_bk)
	{
		temp_ibus_lim = temp_ibus_lim&0x7f;
	   	iic_transmit_byte(0x39,temp_ibus_lim);
 		
		temp_ibus_lim_bk = temp_ibus_lim;
	}
}