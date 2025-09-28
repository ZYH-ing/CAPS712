#include "app_state_machine.h"
#include "app_main.h"
#include "mod_coulomb.h"
#include "mod_input_output.h"
#include "mod_queue.h"
#include "lib_prot_typec.h"
#include "lib_prot_pd.h"
#include "mod_display.h"
#include "lib_multi_protocol.h"
#include "app_init.h"
#include "mod_modbus.h"
#include "app_typec_deal.h"
#include "mod_adc_convert.h"
#include "mod_key.h"
#include "app_init.h"


BANK_STATE_M plug_state_context_t	plug_state_context;
 uint8_t USBA_IN_DIS=0;
 uint8_t WR_IN_DIS=0;
// uint8_t USBA1_2_dis_fast;
// uint8_t WR_OUT_9V;
 BANK_STATE_M uint8_t requesrt_9V_F;
 BANK_STATE_M uint8_t CA_rutren;
 

static void plug_vbus_switch_process(uint8_t dly_a1, uint8_t dly_b1, uint8_t dly_ca, uint8_t dly_cb);
static void plug_multi_protocol_break_process(void);
static void plug_typec_break_process(void);
static void plug_pd_getsrccap_process(void);
static void plug_dcdc_control_process(void);
static void plug_dcdc_charge_process(void);
static void multi_pd_switch(void);
void out_mul_switch_open(void);

void plug_state_init(void)
{
	//初始化队列
	mod_queue_create();

	plug_state_context.event_flag.b_caout_break_cb= false;
	plug_state_context.event_flag.b_cain_break_cb= false;
	plug_state_context.event_flag.b_cbout_break_ca= false;
	plug_state_context.event_flag.b_cbin_break_ca= false;
	plug_state_context.event_flag.b_a1d_break_cx= false;
	plug_state_context.event_flag.b_cax_break= false;
	plug_state_context.event_flag.b_cbx_break= false;
}


void plug_state_machine_proc(void)
{

//    uint8_t sink_Vol,sink_Vol1;
	plug_event_t message;
   
	message= mod_queue_receive();///////跟新获取数组可以得到当前动作0-9 数组 怎么获取的信息
	if(message== NULL)
	{
		return;
	}
	//reset sleep
	// real_time.t_sleep_interval= SLEEP_INTERVAL_TIME;


	//   #if __IF_DEBUG__
	// 	Sub_sim_tx(0xEE);
	// 	Sub_sim_tx(message);
	// 	Sub_sim_tx(0xEE);
	// 	Sub_sim_tx(plug_state_context.state.byte& 0x3f);
	//   #endif

	switch(message)
	{
		/** A1放电插入**/
		case PLUG_A1D_IN:
//		     discharge_displed=1;
//		     if((Bat_low_Cnt>=30)||(!Temp.DischargeTemp_OK))/// 低温保护 不开输出
//			 {
//			   inoutput_data.vbus_switch.sw.type_a1=0;
//			   discharge_displed=displaytime;
//			   break;
//			 }
//			 
//		    if(Type_ca_charge_in||MiroB_charge_in)////CA充电状态//// 没有边冲边放功能
//			{
//			  plug_state_context.state.bit.b_a1d= 0;		//置位A1放电标志
//			  plug_state_context.state.bit.b_acxd= 0;		//置位放电标志
//			  break;
//			}
//			
//		    USBA_IN_DIS=1;
//		    
//		    plug_state_context.state.bit.b_a1d= true;		//置位A1放电标志
//			plug_state_context.state.bit.b_acxd= true;		//置位放电标志
//			plug_vbus_switch_process(DLY, DL0, DL0, DL0);//// A1 口延时打开 
			break;
		/** A1放电拔出**/
		case PLUG_A1D_OUT:
//		    USBA_IN_DIS=0;
//			plug_state_context.state.bit.b_a1d= false;		//复位A1充电标志
//			plug_vbus_switch_process(DL0, DL0, DL0, DL0);
			break;
		/** B1充电插入**/
		case PLUG_B1C_IN:
//		      Bat_low_Cnt=0;
//		      SOS_lighting_stop=0;
////		      USBA_PIN_OFF;
////              Mod_Dis_USBA_EN(0);
//              inoutput_data.vbus_switch.sw.type_a1= false;
//		      F_A1_ON=0;
//		      EN_SYS_IN;
//		      Charge_OCP_cnt=0;
//		      Charge_OCP_Flage=0;
//		      Charge_Close_En_cnt=0;
//		    if(plug_state_context.state.byte& _N___N___N__CAC__N___N_)
//			{
//			   Type_cb_charge_in=0;
//			   break;
//			}
//			   plug_state_context.state.bit.b_b1c=true;
//		       plug_vbus_switch_process(DL0,DLT, DL0, DL0);/// 延时开PMOS
//		       
//		    if(plug_state_context.state.byte& _N___N__CAD__N___N___N_)//// 有CA口充电退出 充电模式/////_N___N___N__CAC__N___N_
//			{
//			     inoutput_data.vbus_switch.sw.type_ca=0;//// 关C口放电/////
//			     plug_state_context.state.bit.b_cad= false;	//复位CA放电
//			}
			break;
		/** B1充电拔出**/
		case PLUG_B1C_OUT:
//		      V_NO_Cha_flage=0;
//			  V_NO_BAT_Charge=0;
//			  Bat_Protest_cnt=0;
//			  Charge_OCP_cnt=0;
//		      Charge_OCP_Flage=0;
//		      Charge_Close_En_cnt=0;
//			  plug_state_context.state.bit.b_b1c=false;
//		      plug_vbus_switch_process(DL0, DL0, DL0, DL0);
//			 if(plug_state_context.state.byte& _N___N__CAD_CAC__N___N_)
//			 {    
//			    
//			 }
//			 else
//			 {
//			  discharge_displed=displaytime;
//			  Discharge_MinCur=1;
//			  sleepcnt=4;
//			  Sleep_up_close_Car_ignition=1;
//			 }
			break;
		/** CA充电插入**/
		case PLUG_CAC_IN:   //////5
//		    if(Frist_Bat_normal_do==Frist_start_sink)
//			Frist_start_sink=Frist_normal_do;
//		    if(!Frist_Bat_normal_do)

            CA_IN_Frist_No_Soure=0;
//		    discharge_displed=1;//// UTX_8_data1=7; //// 充电插入亮电量灯////
//            if(!Bat_low_sleep_flage)
//		    Bat_low_Cnt=0;
		    SOS_lighting_stop=0;
			plug_state_context.state.bit.b_cac= true;		//置位CA充电标志
			plug_vbus_switch_process(DL0, DL0, DLY, DL0);
			inoutput_data.vbus_switch.vbus_type_ca_delay_cnt= 20;
//			USBA_PIN_OFF;
//			Mod_Dis_USBA_EN(0);
            inoutput_data.vbus_switch.sw.type_a1= false;
			EN_SYS_IN;
			F_A1_ON=0;
			Charge_OCP_cnt=0;
		    Charge_OCP_Flage=0;
		    Charge_Close_En_cnt=0;
//			if((USBA_IN_DIS)||(MiroB_charge_in))
          	if(MiroB_charge_in)
			{
//			   	if(USBA_IN_DIS)////CA 口输入 关闭--USBA口
//			    {
//		            USBA_PIN_OFF;
//		            F_A1_ON=0;
////                    inoutput_data.vbus_switch.sw.type_a1=0;
////                    inoutput_data.vbus_switch.vbus_type_a1_delay_cnt= 0;
//			    }
//			    
//				if(MiroB_charge_in)//// B 口充电的情况下/// 关闭B口充电////C口优先充电
//				{
				  Type_cb_charge_in=0;
				  MiroB_charge_in=0;
				  plug_state_context.state.bit.b_b1c=0;
                  inoutput_data.vbus_switch.sw.type_b1=0;
                  inoutput_data.vbus_switch.vbus_type_b1_delay_cnt=0;
//				}
			}
			plug_state_context.event_flag.b_cbin_break_ca= false;
			break;
		/** CA放电插入**/
		case PLUG_CAD_IN:  ////6
//		     discharge_displed=1; UTX_8_data1=8;//// 放电插入亮电量灯///
		     EN_SYS_IN;
		     
		     if((adc_convert.type_ntc.adc_code_rt < C_TempH_DisCharge_Off_Pro)||(adc_convert.type_ntc.adc_code_rt >= C_TempL_DisCharge_Off_Pro))
			{
				  if(Temp.DischargeTemp_OK)
				   {
					Temp.DischargeTemp_OK=0;
//					LCD_display_3S_Cnt=1;
				   }
				   LCD_display_3S_Cnt=1;
			}
	         
//		     if((Bat_low_Cnt>=30)||(!Temp.DischargeTemp_OK)||(CA_IN_Frist_No_Soure))/// 低温保护 不开输出
////            if((Bat_low_Cnt>=30)||(!Temp.DischargeTemp_OK)||(Frist_Bat_normal_do==Frist_start_sink))/// 低温保护 不开输出
//			 {
//			   if(Frist_Bat_normal_do==Frist_start_sink)
//			   Frist_start_sink=Frist_normal_do;
//			   
////			   CA_IN_Frist_No_Soure=0;
//			   
//			   inoutput_data.vbus_switch.sw.type_ca=0;
//			   CA_rutren=1;
//			   break;
//			 }
			 F_A1_ON=1;
			 
			 plug_state_context.state.bit.b_cad= true;	//置位CA放电
			 plug_vbus_switch_process(DL0, DL0, DLT, DL0);
//            if((USBA_IN_DIS)||(MiroB_charge_in))///// 有USBA口插入时//////
//			{
//			  multi_protocol.control.fastchg_protocol_scan_en = 0;  
			  
			    if(MiroB_charge_in)//// B口充电
			  {
//			     plug_vbus_switch_process(DL0, DL0, DLT, DL0);//// 没有边冲边放功能/////
			     inoutput_data.vbus_switch.sw.type_ca=0;
			  }
//			  else
//			  {
//			     if(USBA_IN_DIS)/// A1口放电
//			     {
//			        plug_vbus_switch_process(DLY, DL0, DLT, DL0);
//			     }
//			  }
//			}
			plug_state_context.event_flag.b_cbin_break_ca= false;
			break;
		/**CA拔出**/
		case PLUG_CAX_OUT:
		   	 Charge_OCP_cnt=0;
		     Charge_OCP_Flage=0;
		     Charge_Close_En_cnt=0;
		     
		     Charge_HIG_Vbat_F=0;
		     Bat_Protest_cnt=0;
		     now_power_number &= 0X0F;
		     if(Type_ca_charge_in)
			{
			    V_NO_Cha_flage=0;
				user_flag.bit.charge_vbus_undervol_flag = 0;
		        Type_ca_charge_in=0;
//		        Bat_Protest_cnt=0;
		         
		        V_NO_BAT_Charge=0;
			    discharge_displed=displaytime;/// C口充电拔出灭灯///
			    Discharge_MinCur=1;
			    if(!MirB_IN_Flage)
			    {
			       sleepcnt=30;
			    }
			    
			     if(CA_Test_do_no_Slepp)
			    {
			       sleepcnt=0;
			       CA_Test_do_no_Slepp=0;
			    }
				Sleep_up_close_Car_ignition=1;
				
				R_ChargeCur_DataBuff=PDO_cuurest_MA700;
				R_ChargeCur_Data=R_ChargeCur_DataBuff;
				mod_charge_cur_deal(R_ChargeCur_Data);
			}
			
			if(plug_state_context.state.byte& _N___N__CAD_CAC__N___N_)
			{
				plug_state_context.state.bit.b_cac= false;	//复位CA充电
				plug_state_context.state.bit.b_cad= false;	//复位CA放电
				plug_vbus_switch_process(DL0, DL0, DL0, DL0);////
				
				plug_state_context.pd_work = false;	
			}
			
//			request_num_copy=
			request_num_copy=0;
			break;
		/** CB充电插入**/
		case PLUG_CBC_IN:
			break;
		/** CB放电插入**/
		case PLUG_CBD_IN:
			break;
		/** CB拔出**/
		case PLUG_CBX_OUT:
			break;
		case PLUG_CA_RST_P:
			if(plug_state_context.state.byte& _N___N__CAD_CAC__N___N_)
			{
				/** 关MOS**/
				inoutput_data.vbus_switch.sw.type_ca= false;
				/** VBUS降到5V**/
				/** 设为放电模式**/
				plug_state_context.control_flag.b_dcdc_dir= true;
				/** 泄放**/
				plug_state_context.control_flag.b_vbus_dischar= true;
			}
			break;
		case PLUG_CA_RST_N:
			/** 开MOS**/
			if(plug_state_context.state.byte& _N___N__CAD_CAC__N___N_)
			{
				inoutput_data.vbus_switch.sw.type_ca= true;
			}
			break;
		case PLUG_CB_RST_P:
			if(plug_state_context.state.byte& CBD_CBC__N___N___N___N_)
			{
				/** 关MOS**/
				inoutput_data.vbus_switch.sw.type_cb= false;
				/** 降压**/
				/** VBUS降到5V**/
				/** 设为放电模式**/
				plug_state_context.control_flag.b_dcdc_dir= true;
				/** 泄放**/
				plug_state_context.control_flag.b_vbus_dischar= true;
			}
			break;
		case PLUG_CB_RST_N:
			if(plug_state_context.state.byte& CBD_CBC__N___N___N___N_)
			{
				/** 开MOS**/
				inoutput_data.vbus_switch.sw.type_cb= true;
			}
			break;
		case PLUG_CA_SWAP_SRC:
			break;
		case PLUG_CA_SWAP_SNK:
			break;
		case PLUG_CA_SWAP_N:
			break;
		case PLUG_CB_SWAP_SRC:
			break;
		case PLUG_CB_SWAP_SNK:
			break;
		case PLUG_CB_SWAP_N:
			break;
		default:
			break;
	}
	
	if(plug_state_context.state.byte& _N__CBC__N__CAC_B1C__N_)
	{
		plug_state_context.state.bit.b_bcxc= true;			//置位充电标志
	}
	else
	{
		plug_state_context.state.bit.b_bcxc= false;			//复位充电标志
	}

	if(plug_state_context.state.byte& CBD__N__CAD__N___N__A1D)
	{
		plug_state_context.state.bit.b_acxd= true;			//置位放电标志
	}
	else
	{
		plug_state_context.state.bit.b_acxd= false;			//复位放电标志
	}

//	 if((Bat_low_Cnt>=30)||(!Temp.DischargeTemp_OK))/// 低温保护 退出放电 
       if(CA_rutren)
	 {
	  CA_rutren=0;
//	  inoutput_data.vbus_switch.sw.type_a1= 0;
	  inoutput_data.vbus_switch.sw.type_ca= 0;
//	  inoutput_data.vbus_switch.sw.type_cb= 0;
     if(Temp.DischargeTemp_OK)
	  discharge_displed=displaytime-2;
	  if(CA_IN_Frist_No_Soure)
	  {
	     CA_IN_Frist_No_Soure=0;
	     discharge_displed=displaytime;
	  }
//      discharge_displed=displaytime;
//	  Sleep_SYS_IN;/// 端口重新检测 低电和放电温度保护充电温度保护 关EN
//	  USBA_PIN_OFF
      Mod_Dis_USBA_EN(0);
      inoutput_data.vbus_switch.sw.type_a1= false;
	  F_A1_ON=0;
	  Bat_low_sleep_flage=1;
	  sleepcnt=3;
//	 #if __IF_DEBUG__
////	  Sub_sim_tx(0xca);
////	  Sub_sim_tx(0xca);
////	  Sub_sim_tx(Bat_low_sleep_flage);
//	 #endif
	   return;
	 }
	 
	 EN_SYS_IN;
	 
#if K_UARTX_RX_Upgrade	 
	if(Set_3S_to_into_IAP)
	{
//	  if(mod_key_get_data())//// 没有按下高电平
//	   Set_3S_to_into_IAP++;
//	   if(Set_3S_to_into_IAP>=200)//// 2S 后自动退出
//	   {
		  Set_3S_to_into_IAP=0;
		  Into_IAP_Flage=0; 
		  IAP_inti_deal_dis();//// 取消进入IAP升级
//	   }
	}
#endif	
	
	
	plug_multi_protocol_break_process();////多协议退出功能////
	plug_typec_break_process();//// TCA TCB 断开处理和 单口快充协议和PD协议处理/////
	plug_pd_getsrccap_process();/////充电配置////多口充放电输入电压 只有5V//////取消充电降档设置优先C口充电///
	plug_dcdc_control_process(); ////// DCDC 处理和泄放处理///////
	multi_pd_switch();
}


static void plug_vbus_switch_process(uint8_t dly_a1,		\
										uint8_t dly_b1,		\
										uint8_t dly_ca,		\
										uint8_t dly_cb)
{
//	inoutput_data.vbus_switch.vbus_type_a1_delay_cnt= dly_a1;  ///inoutput_data.vbus_switch.vbus_type_a1_delay_cnt
	inoutput_data.vbus_switch.vbus_type_b1_delay_cnt= dly_b1;
	inoutput_data.vbus_switch.vbus_type_ca_delay_cnt= dly_ca;
//	inoutput_data.vbus_switch.vbus_type_cb_delay_cnt= dly_cb;

	/** {typea_1放电} 时 开typea_1**/
//	inoutput_data.vbus_switch.sw.type_a1= plug_state_context.state.bit.b_a1d;


	/** {typeb_1充电, 且typec_x不充电} 开typeb_1**/
	inoutput_data.vbus_switch.sw.type_b1= (plug_state_context.state.bit.b_b1c&&		\
											(!plug_state_context.state.bit.b_cac&&	\
											!plug_state_context.state.bit.b_cbc));

	/** {typec_a充电, 且typec_b不充电} 或{typec_a放电} 时 开typec_a**/
	inoutput_data.vbus_switch.sw.type_ca= ((plug_state_context.state.bit.b_cac&&	\
											!plug_state_context.state.bit.b_cbc)||	\
											plug_state_context.state.bit.b_cad);

	/** {typec_b充电 且 typec_不充电} 或{typec_b放电} 时 开typec_b**/
//	inoutput_data.vbus_switch.sw.type_cb= ((plug_state_context.state.bit.b_cbc&&		\
//											!plug_state_context.state.bit.b_cac)||		\
//											plug_state_context.state.bit.b_cbd);
}


static void plug_multi_protocol_break_process(void)
{
//	if(plug_state_context.event_flag.b_qc_break)
//	{
//		plug_state_context.event_flag.b_qc_break= false;
//		multi_protocol.control.fastchg_protocol_scan_en= false;
//	}
//	else
//	{
//		multi_protocol.control.fastchg_protocol_scan_en= true;
//	}

	if(plug_state_context.event_flag.b_qc_break)
	{
		plug_state_context.event_flag.b_qc_break= false;
		multi_protocol.control.fastchg_protocol_scan_en= false;
	}else
	{
		if(plug_state_context.pd_work)
		{
			multi_protocol.control.fastchg_protocol_scan_en= false;
		}else
		{
			multi_protocol.control.fastchg_protocol_scan_en= true;
		}
	}
}


/**
 *	1、{单A1放电}, 5V慢放
 *	2、{单CA放电}, pd放电
 *	3、{单CA充电}, pd_9V_18W充电
 *	4、{单CB放电}, pd放电
 *	5、{单CB充电}, pd_9V_18W充电
 *	6、{CA and A1 discharge}, 5V慢放
 *	7、{CB and A1 discharge}, 5V慢放
 *	8、{CA and CB discharge}, 5V慢放
 *	9、{CA and CB and A1 discharge}, 5V慢放
 * 10、{CA and CB charge}, CA_pd_9V_18W充电, CB关断
 * 11、{CA charge and A1 discharge}, 5V电源bypass
 * 12、{CB charge and A1 discharge}, 5V电源bypass
 * 13、{CA charge and CB discharge}, 5V电源bypass
 * 14、{CB charge and CA discharge}, 5V电源bypass
 * 15、{CA and CB charge and A1 discharge}, CA_A1电源bypass, CB关断
 */

//static void plug_typec_break_process(void)
static void plug_typec_break_process(void)
{
   	   /**A1口 break C口**/
//	 if(plug_state_context.event_flag.b_a1d_break_cx)
//	 {
//	  plug_state_context.event_flag.b_a1d_break_cx= false;
//	  typec_break(&h_typeca);     //CA断开
////	  typec_break(&h_typecb);     //CB断开
//	 }

	if(plug_state_context.event_flag.b_cax_break)
	{
		plug_state_context.event_flag.b_cax_break= false;
		typec_break(&h_typeca);					//CA断开
	}

//	if(plug_state_context.event_flag.b_cbx_break)
//	{
//		plug_state_context.event_flag.b_cbx_break= false;
////		typec_break(&h_typecb);					//CB断开
//	}

//	if((plug_state_context.event_flag.b_cain_break_cb)||	\
//		(plug_state_context.event_flag.b_cbin_break_ca))
////	if((plug_state_context.event_flag.b_cain_break_cb)||	\
////		(plug_state_context.event_flag.b_cbin_break_ca)||(plug_state_context.state.bit.b_a1d))
//	{
//		plug_state_context.protocol_flag.b_pd_en= false;
//		pd_enable(false);//// PD 取消设置
//		return;
//	}

	/** pd and multi switch**///// 开PD 和开快充协议//// 单口输入 输出/////
	switch(plug_state_context.state.byte& 0x3F)
	{
		case _N___N___N__CAC__N___N_:
		case _N___N__CAD__N___N___N_:///  单CA 插入////
			/** {only CA charge or discharge}, set pd enable**/
			
//			h_pd.input.local_source_cap_count = PDO_SOURCECAP_COUNT;

     	   if(TYPE_CA_18W_Flage)
     		h_pd.input.local_source_cap_count = PDO_SOURCECAP_COUNT_L;
           else
            h_pd.input.local_source_cap_count = PDO_SOURCECAP_COUNT;

	        h_pd.input.local_pps_pdo_place = PDO_SOURCECAP_PPS_POS;
	        h_pd.input.local_sink_cap_count = PDO_SINKCAP_COUNT;
	        
			plug_state_context.protocol_flag.b_pd_en= true;
			pd_enable(true);

			/** set pd channel**/
//			plug_state_context.protocol_flag.pd_chl= CHL_PD_TCA;	/*!< pd protocol channel, 0-> tca, 1-> tcb*/
//			/** set multi channel**/
//			multi_protocol.control.fastchg_protocol_scan_en = 0; 
//			plug_state_context.protocol_flag.b_multi_chl= CHL_MU_NULL;
               
//            #if !__IF_DEBUG__
           #if __DMPM__EN
				plug_state_context.protocol_flag.b_multi_chl= CHL_MU_TCA;
				multi_protocol.channel= CHANEL_DMDPA;
				/** set multi dir**/
				if(plug_state_context.state.bit.b_cac)
				{
					multi_protocol.dir= DIR_CHARGE;
				}
				else
				{
					multi_protocol.dir= DIR_DISCHARGE;
				}
			#endif
			
			break;
		case _N__CBC__N___N___N___N_:
		case CBD__N___N___N___N___N_: ///  单CB  插入////无线充--插入时
			break;
			
			break;
		case _N___N___N___N___N__A1D: ///  单USBA 插入////
			break;
		case _N___N___N___N___N___N_:
			plug_state_context.protocol_flag.b_pd_en= false;
			pd_enable(false);
			plug_state_context.protocol_flag.b_multi_chl= CHL_MU_NULL;
			multi_protocol.dir= DIR_DISCHARGE;
			break;
		default:
			plug_state_context.protocol_flag.b_pd_en= false;
			pd_enable(false);
			plug_state_context.protocol_flag.b_multi_chl= CHL_MU_NULL;
			multi_protocol.dir= DIR_DISCHARGE;
			multi_protocol.control.fastchg_protocol_scan_en = 0; 
			break;
	}
}




static void plug_pd_getsrccap_process(void)////// 充电配置////多口充放电输入电压 只有5V//////
{
//	if(!(plug_state_context.state.byte& CBD__N__CAD__N___N__A1D)&&	\
//		(plug_state_context.state.byte& _N__CBC__N__CAC_B1C__N_)&&	\
//		(plug_state_context.state.bit.b_cac^ plug_state_context.state.bit.b_cbc))
//	{
//		/** {不放电}且 {充电}且 {CA和 CB不同时充电}**/
//		h_pd.input.local_sink_cap_count= SINKCAP_COUNT_H;
//	}else
//	{
//		h_pd.input.local_sink_cap_count= SINKCAP_COUNT_L;
//	}
	
//	if((Type_ca_charge_in)&&(WR_IN_DIS)&&(!USBA_IN_DIS))//// 无线充和输入都存在 则两档输入
//	{
//	
//	  	h_pd.input.local_sink_cap_count= SINKCAP_COUNT_H;
//	  	plug_state_context.protocol_flag.b_pd_en= 1;
//	    pd_enable(1);
//	}
     if(!Charge_low_power_F)
	{
		/** {不放电}且 {充电}且 {CA和 CB不同时充电}**/
		h_pd.input.local_sink_cap_count= SINKCAP_COUNT_H;
	}
	else
	{
		h_pd.input.local_sink_cap_count= SINKCAP_COUNT_L;
	}
}


static void plug_dcdc_control_process(void)
{
  uint8_t RE_data_temp8;
   requesrt_9V_F=0;
	if(plug_state_context.state.bit.b_bcxc&&			\
		!plug_state_context.state.bit.b_acxd)
	{
		/** dcdc charge**/
		/** {CA charge only}or {CB charge only}**/
		/** 开dcdc**/
		inoutput_data.vbus_switch.sw.pstop= true;
		inoutput_data.vbus_switch.pstop_delay_cnt= DLY;
		/** 设为充电模式**/
		plug_state_context.control_flag.b_dcdc_dir= false;
		/** 泄放**/
		plug_state_context.control_flag.b_vbus_dischar= true;
		
		requesrt_9V_F=1;
	}
	else if(!plug_state_context.state.bit.b_bcxc&&		\
			plug_state_context.state.bit.b_acxd)
	{
		/** dcdc discharge**/
		if(coulomb_data.output.b_batt_low)				//低电池电量不放电
			return;
		 if(Bat_low_Cnt>=30)	
		return;	
			
		/** 开dcdc**/
		inoutput_data.vbus_switch.sw.pstop= true;
		inoutput_data.vbus_switch.pstop_delay_cnt= DLY;
		/** VBUS降到5V**/
		/** 设为放电模式**/
		plug_state_context.control_flag.b_dcdc_dir= true;
		/** 泄放**/
		plug_state_context.control_flag.b_vbus_dischar= true;
		
		requesrt_9V_F=2;
	}
	else if(!plug_state_context.state.bit.b_bcxc^		\
			plug_state_context.state.bit.b_acxd)
	{
		/** dcdc pstop({charge and discharge}or {halt})**/
		/** VBUS降到5V**/ 
         mod_SC8886_DisCharge_init();
          
		/** 关dcdc**/
		inoutput_data.vbus_switch.sw.pstop= false;
		/** 泄放**/
		plug_state_context.control_flag.b_vbus_dischar= true;
		
			requesrt_9V_F=3;
	}

	if(plug_state_context.control_flag.b_dcdc_dir)
	{
		/** 设为放电模式**/
		/** VBUS降到5V**/
        mod_SC8886_DisCharge_init();
        Sleep_up_close_Car_ignition=0;
	    coulomb_data.output.b_batt_full=0;
	    bat_full_do_to_charge=0;
	    
	    requesrt_9V_F=4;
	}
	else
	{
		/** 设为充电模式**/
        mod_SC8886_Charge_init();
        Charge_Start=1;
        if(Vbat_8_date>C_CV_Full_time_4hour)
        bat_full_8hour_Cnt=5;
        else if(Vbat_8_date>C_CV_Full_time_6hour)
        bat_full_8hour_Cnt=3;
        else
        bat_full_8hour_Cnt=1;
        
        bat_full_1hour_Cnt=0;
//      coulomb_data.output.b_batt_full=0;  
        bat_full_do_to_charge=0;
        
        	requesrt_9V_F=5;
	}
	if(plug_state_context.control_flag.b_vbus_dischar)
	{
		plug_state_context.control_flag.b_vbus_dischar= false;
		/** 泄放**/
	       if(!BAT_Pro_Charge)//// 5S 内 VBUS 不放电处理///
		{
			inoutput_data.vbus_switch.sw.discharge= true;
			inoutput_data.vbus_switch.vbus_discharge_delay_cnt= 50;
		}
		
		requesrt_9V_F=requesrt_9V_F+10;
	}
//	  #if __IF_DEBUG__
//	  Sub_sim_tx(0xee);
//	  Sub_sim_tx(0xff);
//	  Sub_sim_tx(requesrt_9V_F);
////	  RE_data_temp8=iic_receive_byte(0x35);
////	  Sub_sim_tx(RE_data_temp8);
////	  Sub_sim_tx(Temp.DischargeTemp_OK);
//	 #endif
}


static void plug_dcdc_charge_process(void)
{
	uint8_t sc_ibuslim_xxaxx;
	uint16_t _curr;
	_curr= h_pd.output.source_cap_cur_capacity;

	if(_curr>= 3000)/////_curr PD 接收到的Sink 充电数据
	{
		sc_ibuslim_xxaxx= SC_IBUSLIM_03A00;
	}else if(_curr>= 2500)
	{
		sc_ibuslim_xxaxx= SC_IBUSLIM_02A50;
	}else if(_curr>= 2000)
	{
		sc_ibuslim_xxaxx= SC_IBUSLIM_02A00;
	}else if(_curr>= 1500)
	{
		sc_ibuslim_xxaxx= SC_IBUSLIM_01A50;
	}else
	{
		sc_ibuslim_xxaxx= SC_IBUSLIM_01A00;//// 有PD 则充电1A
	}

	/** 设为充电电流**/
	if(h_pd.output.source_cap_choose_num)	/*! 作为Sink时候选择对方的PDO档位*/
	{
		mod_dcdc_write_ibus_lim_set(sc_ibuslim_xxaxx);
	}else
	{
		mod_dcdc_write_ibus_lim_set(SC_IBUSLIM_03A00);/// 不是PD得就选择3A充电
	}
}




void plug_state_charge_lag_open_vbus_proc(void)
{
	static bool b_sink_psrdy_lock= false;

#if !CFG_PD_DISABLE
	if(h_pd.output.b_sink_read_ps_rdy)//// 有PD的情况下,收到PS.RDY置1,
	{
		if(b_sink_psrdy_lock== false)
		{
			b_sink_psrdy_lock= true;
			if(h_typeca.output.state== ATTACHED_SNK)
			{
				/** 打开MOS**/
				inoutput_data.vbus_switch.sw.type_ca= true;
			}
			
//			if(h_typecb.output.state== ATTACHED_SNK)
//			{
//				/** 打开MOS**/
//				inoutput_data.vbus_switch.sw.type_cb= true;
//			}

		}
	}
	else
	{
		b_sink_psrdy_lock= false;
	}
#endif
}

static void multi_pd_switch(void)
{
	// if((plug_state_context.event_flag.b_x_break_cb)
	// ||(plug_state_context.event_flag.b_x_break_ca))
	// {														
	// 	inoutput_data.vbus_switch.vbus_type_a1_delay_cnt = DLY;				//break期间持续断开A口mos
	// }
	
	switch(plug_state_context.state.byte& 0x3F)
	{
		case _N___N___N__CAC__N___N_:
		case _N___N__CAD__N___N___N_:
			plug_state_context.protocol_flag.b_pd_en= true;					//set pd enable
			pd_enable(true);

#if	(QC_CHL_EN_TCA)
			plug_state_context.protocol_flag.b_multi_chl= CHL_MU_TCA;
			multi_protocol.channel= CHANEL_DMDPA;
			if((plug_state_context.state.byte& 0x3F)==_N___N___N__CAC__N___N_)
			{
				multi_protocol.dir= DIR_CHARGE;
			}else
			{
				multi_protocol.dir= DIR_DISCHARGE;
			}
			out_mul_switch_open();
#endif
			break;
		case _N__CBC__N___N___N___N_:
		case CBD__N___N___N___N___N_:
			plug_state_context.protocol_flag.b_pd_en= true;
			pd_enable(true);

#if	(QC_CHL_EN_TCB)
			plug_state_context.protocol_flag.b_multi_chl= CHL_MU_TCB;
			multi_protocol.channel = QC_CHL_TCB;
			if((plug_state_context.state.byte& 0x3F)==_N__CBC__N___N___N___N_)
			{
				multi_protocol.dir= DIR_CHARGE;
			}else
			{
				multi_protocol.dir= DIR_DISCHARGE;
			}
			out_mul_switch_open();
#endif
			break;
		case _N___N___N___N___N__A1D:
			plug_state_context.protocol_flag.b_pd_en= false;
			pd_enable(false);

#if	(QC_CHL_EN_TA1)
			plug_state_context.protocol_flag.b_multi_chl= CHL_MU_TA1;
			multi_protocol.channel = QC_CHL_TA1;
			multi_protocol.dir= DIR_DISCHARGE;
			out_mul_switch_open();
#endif
			break;
		default:
			plug_state_context.protocol_flag.b_pd_en= false;
			pd_enable(false);
			
			plug_state_context.protocol_flag.b_multi_chl= CHL_MU_NULL;
			multi_protocol.channel = CHANEL_NULL;
			multi_protocol.dir= DIR_DISCHARGE;
//			out_mul_switch_close();
			multi_protocol.control.qc_protocol_out_en = 0;								/** QC2.0close**/
			multi_protocol.control.qc30_protocol_out_en = 0;							/** QC3.0close**/
			multi_protocol.control.fcp_protocol_out_en = 0;								/** FCP close**/
			multi_protocol.control.scp_protocol_out_en = 1;								/** SCP close**/
			multi_protocol.control.afc_protocol_out_en = 0;								/** AFC close**/
			multi_protocol.control.vooc_protocol_out_en = 0;							/** vooc close**/
			multi_protocol.control.vooc40_protocol_out_en = 0;
			multi_protocol.control.svooc_protocol_out_en = 0;
			break;
	}
}

void out_mul_switch_open(void)
{
	multi_protocol.control.qc_protocol_out_en = 1;			/** QC2.0close**/
	multi_protocol.control.qc30_protocol_out_en = 1;			/** QC3.0close**/
	multi_protocol.control.fcp_protocol_out_en = 1;			/** FCP close**/
	multi_protocol.control.scp_protocol_out_en = 1;			/** SCP close**/
	multi_protocol.control.afc_protocol_out_en = 1;			/** AFC close**/
	multi_protocol.control.vooc_protocol_out_en = 1;			/** vooc close**/
	multi_protocol.control.vooc40_protocol_out_en = 1;
	multi_protocol.control.svooc_protocol_out_en = 1;
}