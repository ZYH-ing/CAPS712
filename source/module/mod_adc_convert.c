/***************************************************************************//**
 * @file     mod_adc_convert.c
 * @version  V1.0.0
 * @author   0531
 * @date     2020-11-23 PM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 *****************************************************************************/

// Include header file.
#include "mod_adc_convert.h"

#include "drv_adc.h"
#include "mod_input_output.h"

#include "app_main.h"
#include "app_init.h"

BANK_ADC adc_convert_t	adc_convert;
BANK_ADC adc_convert_t *p_convert= NULL;
BANK_ADC adc_calculate_t *p_result= NULL;
BANK_ADC uint16_t *p= NULL;

BANK_ADC uint8_t adc_branch;
BANK_ADC uint8_t adc_branch_cnt;

BANK_ADC uint8_t NTC_slide_cnt;
//extern BANK_ADC uint8_t NTC_slide_ok;
//extern BANK_ADC uint8_t NTC_slide_cnt;
BANK_ADC uint16_t NTC_slide_date;
BANK_ADC uint32_t NTC_slide_sum;

//BANK_ADC uint8_t CA_IN_Flage;
//BANK_ADC uint8_t CB_IN_Flage;

BANK_ADC uint8_t Mode_charge_adc;

#define M_ADC_RESULT(_code, _res, _vref, _result)			_result= (uint16_t)((uint32_t)_code* 1000* _vref/ _res/ 0xFFF)
// #define M_ADC_RESULT(_code, _res, _vref, _result)				_result= (uint16_t)(_code* 1000* _vref/ _res/ 0xFFF)


static void adc_convert_channel_switch(adc_curr_chl_t channel);
static void adc_conver_result_refresh(void);

/**@brief inoutput initialization.
 * 
 * @param[in]  null.
 * @param[out] null.
 * 
 * @return  null.
 */
void mod_adc_convert_init(void)
{
	/** adc driver init**/
	
	/////IO 口 初始化/////
	adc_init();
	adc_enable();
	delay_ms(5);

	/** param init**/
	
//	/** get offset**/

     adc_convert.typec_a.result_offset=0;
     adc_convert.typea_1.result_offset=0;
     
     adc_convert.typec_a.flag.result_refresh=0;
     adc_convert.typea_1.flag.result_refresh=0;
     adc_convert.type_ntc.flag.result_refresh=0;
     
     adc_convert.typec_a.slide_cnt=0;
     adc_convert.typea_1.slide_cnt=0;
     adc_convert.type_ntc.slide_cnt=0;
     
	do
	{
		mod_adc_convert();
	}
//		while((!adc_convert.typec_a.flag.result_refresh));

	while((!adc_convert.typec_a.flag.result_refresh)||	\
	     (!adc_convert.typea_1.flag.result_refresh)||(!adc_convert.type_ntc.flag.result_refresh));////
	     //// CA 口电流校准 A口 电流校准  NTC 采样一次////
//	while((!adc_convert.typec_a.flag.result_refresh)||	\
//	     (!adc_convert.typea_1.flag.result_refresh));
					
	adc_convert.typec_a.result_offset= adc_convert.typec_a.adc_code_sl;
	adc_convert.typea_1.result_offset= adc_convert.typea_1.adc_code_sl;
	adc_convert.type_ntc.result_offset=0;
//	adc_convert.typea_2.result_offset= adc_convert.typea_2.adc_code_sl;//// USB2 电流 检测矫正////
}


void mod_adc_convert_disable(void)
{
	/** adc driver disable**/
	adc_disable();
}


/**@brief inoutput initialization.
 * 
 * @param[in]  null.
 * @param[out] null.
 * 
 * @return  null.
 */

void mod_adc_convert(void)
{	
	switch(adc_branch++)
	{
		    case 0:
			adc_convert_channel_switch(CURR_CHL_TCA);
			break;
		    case 1:
			/** calculation**/
			if(adc_convert.flag.convert_refresh)
			{
				adc_convert.flag.convert_refresh= false;
				adc_conver_result_refresh();

				/** channel_ta1 switch**/
				/** !!port multiplexing, ADC collection is not performed during vbus discharge**/
				if(!inoutput_data.vbus_switch.sw.discharge)
				{
					adc_convert_channel_switch(CURR_CHL_TA1);			
				}
			    else 
			    {
                  adc_branch=3;
			      adc_convert_channel_switch(CURR_CHL_NTC);
			    }
			}
			else
			{
				adc_branch--;
			}
			
			break;
		    case 2://///
			/** calculation**/
			/** !!port multiplexing, ADC collection is not performed during vbus discharge**/
			if(!inoutput_data.vbus_switch.sw.discharge)///端口复用，vbus放电时不采集ADC 
			{
				if(adc_convert.flag.convert_refresh)
				{
					adc_convert.flag.convert_refresh= false;
					adc_conver_result_refresh();
					adc_convert_channel_switch(CURR_CHL_NTC);
				}
				else
				{
					adc_branch--;
				}
			}
			else 
			{
				adc_convert_channel_switch(CURR_CHL_NTC);
			}
			break;
		    case 3://///
			if(adc_convert.flag.convert_refresh)
			{
				adc_convert.flag.convert_refresh= false;
				adc_conver_result_refresh();
			   adc_convert_channel_switch(CURR_CHL_LOADIN);
			}
			else
			{
				adc_branch--;
			}
			break;
			case 4://///
			if(adc_convert.flag.convert_refresh)
			{
				adc_convert.flag.convert_refresh= false;
				adc_conver_result_refresh();
                adc_convert_channel_switch(CURR_CHL_USBA_VBUS);
			}
			else
			{
				adc_branch--;
			}
			break;
			case 5://///
			if(adc_convert.flag.convert_refresh)
			{
				adc_convert.flag.convert_refresh= false;
				adc_conver_result_refresh();
                adc_convert_channel_switch(CURR_CHL_NTC2);
			}
			else
			{
				adc_branch--;
			}
			break;
			case 6://///
			if(adc_convert.flag.convert_refresh)
			{
				adc_convert.flag.convert_refresh= false;
				adc_conver_result_refresh();
				adc_branch= 0;
			}
			else
			{
				adc_branch--;
			}
			if(adc_branch>6)
			{
				adc_branch= 0;
			}
			break;
//		    case 7://///
//			if(adc_convert.flag.convert_refresh)
//			{
//				adc_convert.flag.convert_refresh= false;
//				adc_conver_result_refresh();
//				adc_branch= 0;
//			}
//			else
//			{
//				adc_branch--;
//			}
//			if(adc_branch>7)
//			{
//				adc_branch= 0;
//			}
//			break;
			
		    default:
			  adc_branch= 0;
			break;
	}
}


static void adc_convert_channel_switch(adc_curr_chl_t channel)
{
	adc_convert.adc_curr_chl= channel;
	uint8_t i;
		uint8_t SysMode;
	switch(channel)
	{
		case CURR_CHL_TCA:			//typec_a chl--TCA_TCB_I
		
		if(R_SysMode_OK==1)///COULOMB_CHARGE
		{
		   SysMode=0;
		}
		else
		{
		   SysMode=1;
		}
        if(Mode_charge_adc!=SysMode)
		  {
		    adc_convert.typec_a.slide_cnt=0;
	        adc_convert.typec_a.slide_sum=0;
		    Mode_charge_adc=SysMode;
//            Mode_charge_adc=OTG_ON;
		  }
			adc_set_vref(VREFS_1V0);
			SRADCON0=SRADCON0|0x01;
			adc_set_sing_channel(CFG_ADC_CHL_TCA);
			break;
		case CURR_CHL_TA1:			//typea_1 chl
	        SRADCON0=SRADCON0&0xfe;////  以下都不是差分算法
			adc_set_vref(VREFS_1V0);
			adc_set_sing_channel(CFG_ADC_CHL_TA1);
			break;
		case CURR_CHL_NTC:			//type_ntc chl
		    SRADCON0=SRADCON0&0xfe;
			adc_set_vref(VREFS_VDD);
			adc_set_sing_channel(CFG_ADC_CHL_NTC);
//			for(i=0;i<=20;i++)
//			{
//			  	asm("nop"); //nop
//			}
              for(i=0;i<=5;i++)
			{
			  	asm("nop"); //nop
			}
			break;
	case CURR_CHL_NTC2:			//type_ntc chl
		    SRADCON0=SRADCON0&0xfe;
			adc_set_vref(VREFS_VDD);
			adc_set_sing_channel(CFG_ADC_CHL_NTC2);
//			for(i=0;i<=20;i++)
//			{
//			  	asm("nop"); //nop
//			}
              for(i=0;i<=5;i++)
			{
			  	asm("nop"); //nop
			}
			break;
        case CURR_CHL_USBA_VBUS:			//USBA_VBUS
            adc_set_vref(VREFS_VDD);
			adc_set_sing_channel(CFG_ADC_CHL_USBA_VBUS);
			break;
		case CURR_CHL_LOADIN:	//type_LOADIN chl
			adc_set_vref(VREFS_VDD);
			adc_set_sing_channel(CFG_ADC_CHL_LOAD_IN);
			for(i=0;i<=20;i++)
			{
			  	asm("nop"); //nop
			}
			break;
		
		default:
			break;
	}
	adc_start();		
}



static void adc_conver_result_refresh(void)///// 更新ADC数据////
{
     uint8_t SysMode;
	switch(adc_convert.adc_curr_chl)
	{
		case CURR_CHL_TCA:			//typec_a chl
		
		if(R_SysMode_OK==1)///COULOMB_CHARGE
		{
		   SysMode=0;
		}
		else
		{
		   SysMode=1;
		}
		
		p_result= &adc_convert.typec_a;
	///  if(EN_SYS_INOTG)/// 放电模式
	   if(SysMode)/// 放电模式
//		 if(OTG_ON)
       	{
         if(adc_convert.code_rt<=2048)
          adc_convert.code_rt=0;
         else 
          adc_convert.code_rt=adc_convert.code_rt-2048;
       	}
       	else/// 充电模式
       	{
         if(adc_convert.code_rt>=2048)
         adc_convert.code_rt=0;
         else 
         adc_convert.code_rt=2048-adc_convert.code_rt;
       	}
       	
       	if(adc_convert.code_rt>=p_result->result_offset)
		 adc_convert.code_rt=adc_convert.code_rt-p_result->result_offset;
		 else
		 adc_convert.code_rt=0;
       	
		break;
		case CURR_CHL_TA1:			//typea_1 chl
		 p_result= &adc_convert.typea_1;
		 if(adc_convert.code_rt>=p_result->result_offset)
		 adc_convert.code_rt=adc_convert.code_rt-p_result->result_offset;
		 else
		 adc_convert.code_rt=0;
		break;
	    case CURR_CHL_NTC:			//typea_1 chl
		p_result= &adc_convert.type_ntc;
		break;
	    case CURR_CHL_NTC2:			//typea_1 chl
		p_result= &adc_convert.type_ntc2;
		break;
//		case CURR_CHL_VBAT:			//typea_1 chl
//      p_result= &adc_convert.type_vbat;
       case CURR_CHL_USBA_VBUS:
		p_result= &adc_convert.type_usba_vbus;
		break;
		case CURR_CHL_LOADIN:			//typea_1 chl
		p_result= &adc_convert.type_loadin;
		break;
//		case CURR_CHL_TA2:			//typea_1 chl
//		p_result= &adc_convert.typea_2;
//		if(adc_convert.code_rt>=p_result->result_offset)
//		 adc_convert.code_rt=adc_convert.code_rt-p_result->result_offset;
//		 else
//		 adc_convert.code_rt=0;
//		break;
		default:
		break;
	}
	p_result->adc_code_rt= adc_convert.code_rt;////// ADC 中断实时采集的值 付给对应通道的 数值储存
    p_result->slide_cnt++;
    p_result->slide_sum+=p_result->adc_code_rt;
//	if(p_result->slide_cnt>= CFG_ADC_SLIDE_TIMES)//// 当数值中更新有16个以上的值时 启动转换
    	if(p_result->slide_cnt>= CFG_ADC_SLIDE_TIMES)//// 当数值中更新有2个以上的值时 启动转换
	{
		p_result->slide_cnt= 0;//// 赋值寄存器清零  // 开始更新新的一批数据
//	   	p_result->adc_code_sl= p_result->slide_sum>>4;
        p_result->adc_code_sl= p_result->slide_sum>>1;////2次平均得到数值
	    p_result->slide_sum=0;
	    p_result->flag.result_refresh= true;////修正补偿值 取值成功
	}	
}


void mod_adc_convert_result_calculation(adc_curr_chl_t channel)
{

}

//----------------------------------------------------------------------------
//函数名称：
//具体描述：ADC采集( ADC测量8次，前2次丢弃，后6次去掉最大最小取平均)
//----------------------------------------------------------------------------
unsigned int Sub_adc_enhanced(unsigned char AN_CH)
{
	unsigned char i;
	unsigned int ad_max=0;
	unsigned int ad_min=0;
	unsigned int ad_buf=0;
	unsigned int ad_res=0;
	//-------------------------------------
	//     通道配置
	//-------------------------------------
	switch(AN_CH)
	{
        case CFG_ADC_CHL_CC1A:
		{
			SRADCON0=0x10;			//
			SRADCON1=0x80;			//参考电压VDD
            adc_set_vref(ADC_VREFS_VDD);
			adc_set_sing_channel(CHL_ADC_CHL_AIN15);
		}
		break;
		
		case CFG_ADC_CHL_CC2A:
		{
			SRADCON0=0x10;			//
			SRADCON1=0x80;			//参考电压VDD
            adc_set_vref(ADC_VREFS_VDD);
			adc_set_sing_channel(CHL_ADC_CHL_AIN16);
		}
		break;
		
		  case CFG_ADC_CHL_LOAD_IN:
		{
			SRADCON0=0x10;			//
			SRADCON1=0x80;			//参考电压VDD
            adc_set_vref(ADC_VREFS_VDD);
			adc_set_sing_channel(CHL_ADC_CHL_AIN14);
		}
		break;
		
		
		default:
		{
		}
		break;
	}
	//-----------------------------------------------------
	//  ADC测量8次，前两次不用，后6次去掉最大最小取平均
	//-----------------------------------------------------
	SRADS=1;						//前两次转换结果不用
	asm("nop");	  					//
	while(SRADS);	
	asm("nop");	
	SRADS=1;	
	asm("nop");
	while(SRADS);
	asm("nop");	 
	for(i=0;i<6;i++)
	{
		SRADS=1;                        //开始AD 转换                           
		asm("nop");	                                                            
		while(SRADS)					//等待AD 转换  
		;
		ad_buf=SRADH;
		ad_buf<<=8;
		ad_buf+=SRADL;
		if(i<2)
		{
			if(ad_buf>ad_max)
			{
				ad_min=ad_max;
				ad_max=ad_buf;
			}
			else
				ad_min=ad_buf;
		}
		else
		{
			if(ad_buf>ad_max)
			{
				ad_res+=ad_max;
				ad_max=ad_buf;
			}
			else
			{
				if(ad_buf>=ad_min)
				{
					ad_res+=ad_buf;
				}
				else
				{
					ad_res+=ad_min;
					ad_min=ad_buf;
				}
			}
		}
	}
	return (ad_res/4); 
}

