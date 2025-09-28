/***************************************************************************//**
 * @file     mod_input_output.c
 * @version  V1.0.0
 * @author   0531
 * @date     2020-11-10 PM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 *****************************************************************************/

// Include header file.
#include "drv_adc.h"
#include "mod_adc_convert.h"
#include "mod_dcdc.h "
#include "mod_queue.h"

#include "mod_input_output.h"
#include "app_state_machine.h"
#include "app_main.h"

#include "lib_prot_pd.h"
#include "app_init.h"
#include "app_typec_deal.h"

#include "lib_multi_protocol.h"

BANK_IO inoutput_t			inoutput_data;
BANK_IO misc_interface_t	misc_interface;
BANK_IO uint8_t *inoutput_p= NULL;

BANK_IO uint8_t CA_IN_Flage;
BANK_IO uint8_t CB_IN_Flage;
BANK_IO uint8_t MirB_IN_Flage;

BANK_IO  TOUCH_OUT_CNT;

/**@brief inoutput initialization.
 * 
 * @param[in]  null.
 * @param[out] null.
 * 
 * @return  null.
 */
static void mod_io_init_vbus_discharge(void)
{
	/** vbus dischar port**/
#if CFG_SIMP_GPIO
	/** PT37 init, func_gpio**/
	PT37FUNC_1= 0;
	PT37FUNC_0= 0;
	PT3EN7= 1;
#else
	gpio_config_t		gpio_cfg;
	
	gpio_cfg.gpio_portx= PRE_PORT_VBUS_DISC;
	gpio_cfg.gpio_pinx= PRE_PIN_VBUS_DISC;
	gpio_cfg.gpio_pinmux= pinmux_func0;
	gpio_cfg.gpio_dir= dir_output;
	gpio_cfg.gpio_mode= mode_pp;
	gpio_cfg.gpio_pull= no_pull;
	gpio_init(&gpio_cfg);
#endif
}
 
static void mod_io_init_ta1_curr(void)
{
	/** typea_1 current detection port**/
#if CFG_SIMP_GPIO
	/** PT37 init, func_ain7**/
	PT37FUNC_1= 0;
	PT37FUNC_0= 1;
#else
	gpio_config_t		gpio_cfg;
	
	gpio_cfg.gpio_portx= PRE_PORT_TA1_CURR;
	gpio_cfg.gpio_pinx= PRE_PIN_TA1_CURR;
	gpio_cfg.gpio_pinmux= pinmux_func1;
	gpio_cfg.gpio_dir= dir_input;
	gpio_cfg.gpio_mode= mode_pp;
	gpio_cfg.gpio_pull= no_pull;
	gpio_init(&gpio_cfg);
#endif

}
 
 
 
void mod_inoutput_init(void)
{

    TCA_PIN_OFF;
//    MIR_B_PIN_OFF;
//    USBA_PIN_OFF;
   //gpio init
#if CFG_SIMP_GPIO
	PT37= 0;
#else
	gpio_config_t		gpio_cfg;
	gpio_cfg.gpio_portx= PRE_PORT_TA1_CURR;
	gpio_cfg.gpio_pinx= PRE_PIN_TA1_CURR;
	gpio_cfg.gpio_pinmux= pinmux_func1;
	gpio_cfg.gpio_dir= dir_input;
	gpio_cfg.gpio_mode= mode_pp;
	gpio_cfg.gpio_pull= no_pull;
	gpio_init(&gpio_cfg);
	gpio_cfg.gpio_portx= PRE_PORT_TCB_CURR;
	gpio_cfg.gpio_pinx= PRE_PIN_TCB_CURR;
	gpio_cfg.gpio_pinmux= pinmux_func1;
	gpio_cfg.gpio_dir= dir_input;
	gpio_cfg.gpio_mode= mode_pp;
	gpio_cfg.gpio_pull= no_pull;
	gpio_init(&gpio_cfg);
	
	/** dcdc pstop port**/
	/**
	 *	@csu39fx10_syscfg.h
	 */
	gpio_cfg.gpio_portx= PRE_PORT_PSTOP;
	gpio_cfg.gpio_pinx= PRE_PIN_PSTOP;
	gpio_cfg.gpio_pinmux= pinmux_func0;
	gpio_cfg.gpio_dir= dir_output;
	gpio_cfg.gpio_mode= mode_pp;
	gpio_cfg.gpio_pull= no_pull;
	gpio_init(&gpio_cfg);
	
	/** dcdc interrupt port is set as input, External interrupt is configured in function {exi_init();}**/
	/**
	 *	@csu39fx10_syscfg.h
	 */
	gpio_cfg.gpio_portx= PRE_SC_PORT_INT;
	gpio_cfg.gpio_pinx= PRE_SC_PIN_INT;
	gpio_cfg.gpio_pinmux= pinmux_func0;
	gpio_cfg.gpio_dir= dir_input;
	gpio_cfg.gpio_mode= mode_pp;
	gpio_cfg.gpio_pull= pull_up;
	gpio_init(&gpio_cfg);
	
	/** tcb_acin port**/
	/**
	 *	@csu39fx10_syscfg.h
	 */
	gpio_cfg.gpio_portx= PRE_PORT_TCB_ACIN;
	gpio_cfg.gpio_pinx= PRE_PIN_TCB_ACIN;
	gpio_cfg.gpio_pinmux= pinmux_func0;
	gpio_cfg.gpio_dir= dir_input;
	gpio_cfg.gpio_mode= mode_pp;
	gpio_cfg.gpio_pull= pull_up;
	gpio_init(&gpio_cfg);
	
	/** tcb_vbus switch port**/
	/**
	 *	@csu39fx10_syscfg.h
	 */
	gpio_cfg.gpio_portx= PRE_PORT_TCB_VBUS;
	gpio_cfg.gpio_pinx= PRE_PIN_TCB_VBUS;
	gpio_cfg.gpio_pinmux= pinmux_func0;
	gpio_cfg.gpio_dir= dir_output;
	gpio_cfg.gpio_mode= mode_pp;
	gpio_cfg.gpio_pull= no_pull;
	gpio_init(&gpio_cfg);

	gpio_write_bit(P_PSTOP, false^ PRE_PSTOP_POLARITY);				//stop
	gpio_write_bit(P_VBUS_DISC, false^ PRE_VBUS_DISC_POLARITY);		//dischar close
	gpio_write_bit(P_TCB_VBUS, false^ PRE_TCB_VBUS_POLARITY);		//tcb_vbus close
#endif
	
//	mod_dcdc_write_pgate_ctrl(false^ PRE_TCA_VBUS_POLARITY);			//tca_vbus close 待处理
//	mod_dcdc_write_gpo_ctrl(false^ PRE_TA1_VBUS_POLARITY);				//ta1_vbus close  待处理
//	inoutput_data.vbus_switch.vbus_type_a1_delay_cnt= 0;
	inoutput_data.vbus_switch.vbus_type_b1_delay_cnt= 0;
	inoutput_data.vbus_switch.vbus_type_ca_delay_cnt= 0;
//	inoutput_data.vbus_switch.vbus_type_cb_delay_cnt= 0;
	inoutput_data.vbus_switch.vbus_discharge_delay_cnt= 0;
	inoutput_data.vbus_switch.pstop_delay_cnt= 0;
	
//	USBA_PIN_OFF;
	Mod_Dis_USBA_EN(0);
	
	
//	inoutput_data.vbus_switch.sw.type_a1= false;
    inoutput_data.vbus_switch.sw.type_b1= false;
	inoutput_data.vbus_switch.sw.type_ca= false;
//	inoutput_data.vbus_switch.sw.type_cb= false;
	inoutput_data.vbus_switch.sw.discharge= false;
	inoutput_data.vbus_switch.sw.pstop= true;/// 初始化先放电////
}
 

void mod_inoutput_disable(void)
{
	//gpio init
	// gpio_config_t		gpio_cfg;
	
	/** vbus dischar port**/
	// gpio_cfg.gpio_portx= PRE_PORT_VBUS_DISC;
	// gpio_cfg.gpio_pinx= PRE_PIN_VBUS_DISC;
	// gpio_cfg.gpio_pinmux= pinmux_func0;
	// gpio_cfg.gpio_dir= dir_output;
	// gpio_cfg.gpio_mode= mode_pp;
	// gpio_cfg.gpio_pull= no_pull;
	// gpio_init(&gpio_cfg);
	
	// /** typea_1 current detection port**/
	// gpio_cfg.gpio_portx= PRE_PORT_TA1_CURR;
	// gpio_cfg.gpio_pinx= PRE_PIN_TA1_CURR;
	// gpio_cfg.gpio_pinmux= pinmux_func1;
	// gpio_cfg.gpio_dir= dir_input;
	// gpio_cfg.gpio_mode= mode_pp;
	// gpio_cfg.gpio_pull= no_pull;
	// gpio_init(&gpio_cfg);
	
	/** typec_a current detection port**/
	// gpio_cfg.gpio_portx= PRE_PORT_TCA_CURR;
	// gpio_cfg.gpio_pinx= PRE_PIN_TCA_CURR;
	// gpio_cfg.gpio_pinmux= pinmux_func1;
	// gpio_cfg.gpio_dir= dir_input;
	// gpio_cfg.gpio_mode= mode_pp;
	// gpio_cfg.gpio_pull= no_pull;
	// gpio_init(&gpio_cfg);
	
	/** typec_b current detection port**/
	// gpio_cfg.gpio_portx= PRE_PORT_TCB_CURR;
	// gpio_cfg.gpio_pinx= PRE_PIN_TCB_CURR;
	// gpio_cfg.gpio_pinmux= pinmux_func1;
	// gpio_cfg.gpio_dir= dir_output;
	// gpio_cfg.gpio_mode= mode_pp;
	// gpio_cfg.gpio_pull= no_pull;
	// gpio_init(&gpio_cfg);
	
	/** dcdc pstop port**/
	// gpio_cfg.gpio_portx= PRE_PORT_PSTOP;
	// gpio_cfg.gpio_pinx= PRE_PIN_PSTOP;
	// gpio_cfg.gpio_pinmux= pinmux_func0;
	// gpio_cfg.gpio_dir= dir_output;
	// gpio_cfg.gpio_mode= mode_pp;
	// gpio_cfg.gpio_pull= no_pull;
	// gpio_init(&gpio_cfg);
	
	/** dcdc interrupt port is set as input, External interrupt is configured in function {exi_init();}**/
	// gpio_cfg.gpio_portx= PRE_SC_PORT_INT;
	// gpio_cfg.gpio_pinx= PRE_SC_PIN_INT;
	// gpio_cfg.gpio_pinmux= pinmux_func0;
	// gpio_cfg.gpio_dir= dir_input;
	// gpio_cfg.gpio_mode= mode_pp;
	// gpio_cfg.gpio_pull= no_pull;
	// gpio_init(&gpio_cfg);
	
	/** tcb_acin port**/
	// gpio_cfg.gpio_portx= PRE_PORT_TCB_ACIN;
	// gpio_cfg.gpio_pinx= PRE_PIN_TCB_ACIN;
	// gpio_cfg.gpio_pinmux= pinmux_func0;
	// gpio_cfg.gpio_dir= dir_input;
	// gpio_cfg.gpio_mode= mode_pp;
	// gpio_cfg.gpio_pull= no_pull;
	// gpio_init(&gpio_cfg);
	
	/** tcb_vbus switch port**/
	// gpio_cfg.gpio_portx= PRE_PORT_TCB_VBUS;
	// gpio_cfg.gpio_pinx= PRE_PIN_TCB_VBUS;
	// gpio_cfg.gpio_pinmux= pinmux_func0;
	// gpio_cfg.gpio_dir= dir_output;
	// gpio_cfg.gpio_mode= mode_pp;
	// gpio_cfg.gpio_pull= no_pull;
	// gpio_init(&gpio_cfg);
	
	// gpio_write_bit(P_PSTOP, false^ PRE_PSTOP_POLARITY);				//stop
	// gpio_write_bit(P_VBUS_DISC, false^ PRE_VBUS_DISC_POLARITY);		//dischar close
	// gpio_write_bit(P_TCB_VBUS, false^ PRE_TCB_VBUS_POLARITY);		//tcb_vbus close
}
 

//Generate port switch event
//plug_event_t
void mod_inoutput_plug_check_proc(void)//// 10ms 检测一次////
{
	uint8_t USBA_IN;
	
//	if(PT25)
//	USBA_IN=0;
//	else
//	USBA_IN=1;
	
//#if(CFG_INOUT_PORT_TA1_LOADIN== LIST_REG_INDET1)
//	if(M_DCDC_REG_GET(dcdc_data.reg.status, INDET1, 1))
//	if(USBA_IN)
//#elif(CFG_INOUT_PORT_TA1_LOADIN== LIST_REG_INDET2)
//  if(M_DCDC_REG_GET(dcdc_data.reg.status, INDET2, 1))////如果插入检测为1时

    if(USBA_sleep_up)
	{
      USBA_sleep_up++;
      if(USBA_sleep_up>=100)
       {
         USBA_sleep_up=0;
         misc_interface.typea1.b_level=0;
       }
	}
	
     if(USBA_IN)
//#endif
	{
		if(!misc_interface.typea1.b_level)
		{
			misc_interface.typea1.b_level= true;
			misc_interface.typea1.b_raising= true;////misc_interface.typea1.b_level  变成0-1 产生上升沿/////
		}
	}
	else////如果插入检测为0时，A口拔出
	{
		if(misc_interface.typea1.b_level)
		{
			misc_interface.typea1.b_level= false;
		}
	}
	
	/** 禁止期间清下降沿标志,这是喘振，不是真的负载拔出再插入**/
	if(misc_interface.typea1.t_prohbit_check)//// 拔出2S内不检查 插入///
	{
		misc_interface.typea1.t_prohbit_check--;
	}

	if(misc_interface.typea1.t_prohbit_check) ////重复插拔直接退出//////
	{
		misc_interface.typea1.b_raising= false;
		return;
	}
		if(plug_state_context.state.byte& _N___N___N__CAC__N___N_)////C 口充电不开A口////
	{
		misc_interface.typea1.b_raising= false;
	    return;
	}
		if(Type_cb_charge_in)////C 口充电不开A口////
	{
		misc_interface.typea1.b_raising= false;
	    return;
	}
	
	 if(Bat_low_Cnt>=30)
	 {
	 	misc_interface.typea1.b_raising= false;
		return;	
	 }
	 
	 if(!Temp.DischargeTemp_OK)
	 {
	 	misc_interface.typea1.b_raising= false;
		return;	
	 }
	
	/** IO检负载,只要在非禁止期间,有下降沿产生就好**/
	if(!misc_interface.typea1.b_load_sta) ////< 负载存在标志(SET,在;RESET,不在) */
	{
		misc_interface.typea1.t_isnotexist= 0;
		if(misc_interface.typea1.t_isexist++> C_CHECK_LOAD_TIME)///// 累计 200mS 更新一次A口插入检测////
		{
			misc_interface.typea1.t_isexist= 0;
			if(misc_interface.typea1.b_raising)//// 有上升沿则确定负载有插入
			{
				/** 禁止过后,拔出过负载,然后又插入了负载**/
				misc_interface.typea1.b_raising= false;
				misc_interface.typea1.b_load_sta= true;//// 确定插入
				misc_interface.typea1.t_isnotexist= 0;
				
				mod_queue_send(PLUG_A1D_IN);
			}
		}
	}
	else
	{
		misc_interface.typea1.t_isexist= 0;  //// 插入计时清零
	}
	
	/** 泄放时禁止A口小电流检测**/
	if(!inoutput_data.vbus_switch.sw.discharge)
	{
		/** 负载存在,则判小电流丢负载情况,之后禁止2S负载检测**/
		if(misc_interface.typea1.b_load_sta)//// 有插入确定
		{
		//	if(adc_convert.typea_1.result_sl< C_ADC_SMALL_CURR)/////  A 口电流小于 70ma 取消掉A口 插入配置
		   if(adc_convert.typea_1.adc_code_sl< C_ADC_SMALL_CURR)/////  A 口电流小于 70ma 取消掉A口 插入配置
			{
				if(misc_interface.typea1.t_isnotexist++> C_LITTLE_CURRENT_TIME)/////t_isnotexist 是8位  C_LITTLE_CURRENT_TIME=10000 不符合
				{
					misc_interface.typea1.b_load_sta= false;
					misc_interface.typea1.t_isnotexist= 0;
					misc_interface.typea1.t_prohbit_check= C_PROHBIT_CHECKLOAD;//// 重置2S 负载检测///
					
					mod_queue_send(PLUG_A1D_OUT);
					USBA_IN_DIS=0;
//					if((plug_state_context.state.byte& CBD_CBC_CAD_CAC__N___N_)&&(!WR_IN_DIS))///只有CA口连接时
//					{
//						h_pd.input.local_source_cap_count = PDO_SOURCECAP_COUNT;///// A口移除 CACB口有插入则恢复输出快充/////
//						
//						plug_state_context.event_flag.b_cax_break= true;
//					//	plug_state_context.event_flag.b_cbx_break= true;
//					}
				}
			}
		}	
	}
}
void mod_inoutput_plug_check_proc_USBA2(void)
{
	uint8_t USBA2_IN;
    if(TOUCH_OUT)
	{
	  TOUCH_OUT_CNT++;
    if(TOUCH_OUT_CNT>=50)////1S 钟一直都是高电平///
	 {
	   TOUCH_OUT_CNT=0;
	   USBA2_IN=1;
	 }
	}
	else
	{
	   TOUCH_OUT_CNT=0;
	   USBA2_IN=0;
	}
    if(USBA2_IN)
	{
		if(!misc_interface.typea2.b_level)
		{
			misc_interface.typea2.b_level= true;
			misc_interface.typea2.b_raising= true;//// 	misc_interface.typea1.b_level  变成0-1 产生上升沿/////
		}
	}
	else////如果插入检测为0时，A2口拔出
	{
		if(misc_interface.typea2.b_level)
		{
			misc_interface.typea2.b_level= false;
		}
	}
	
	/** 禁止期间清下降沿标志,这是喘振，不是真的负载拔出再插入**/
	if(misc_interface.typea2.t_prohbit_check)//// 拔出2S内不检查 插入///
	{
		misc_interface.typea2.t_prohbit_check--;
	}

	if(misc_interface.typea2.t_prohbit_check) ////重复插拔直接退出//////
	{
		misc_interface.typea2.b_raising= false;
		return;
	}
	
	 if(Bat_low_Cnt>=30)
	 {
	 	misc_interface.typea2.b_raising= false;
		return;	
	 }
	
	 if(!Temp.DischargeTemp_OK)
	 {
	 	misc_interface.typea2.b_raising= false;
		return;	
	 }
	
	/** IO检负载,只要在非禁止期间,有下降沿产生就好**/
	if(!misc_interface.typea2.b_load_sta) ////< 负载存在标志(SET,在;RESET,不在) */
	{
		misc_interface.typea2.t_isnotexist= 0;
		if(misc_interface.typea2.t_isexist++> C_CHECK_LOAD_TIME)///// 累计 200mS 更新一次A口插入检测////
		{
			misc_interface.typea2.t_isexist= 0;
			if(misc_interface.typea2.b_raising)//// 有上升沿则确定负载有插入
			{
				/** 禁止过后,拔出过负载,然后又插入了负载**/
				misc_interface.typea2.b_raising= false;
				misc_interface.typea2.b_load_sta= true;//// 确定插入
				misc_interface.typea2.t_isnotexist= 0;
				
		  	    ///	mod_queue_send(PLUG_A1D_IN);
			    mod_queue_send(PLUG_CBD_IN);
			}
		}
	}
	else
	{
		misc_interface.typea2.t_isexist= 0;  //// 插入计时清零
	}
	//  if(!W_ID_PIN)
	//  {
	//  asm("nop");
	//  }
	/** 泄放时禁止A口小电流检测**/
//	if(!inoutput_data.vbus_switch.sw.discharge)
//	{
//		/** 负载存在,则判小电流丢负载情况,之后禁止2S负载检测**/
		if(misc_interface.typea2.b_load_sta)//// 有插入确定
		{
	    //	adc_convert.typea_2.adc_code_sl=0;
		//	if(adc_convert.typea_1.result_sl< C_ADC_SMALL_CURR)/////  A 口电流小于 70ma 取消掉A口 插入配置
//		   if(adc_convert.typea_2.adc_code_sl< C_ADC_SMALL_CURR)/////  A 口电流小于 70ma 取消掉A口 插入配置
//            if(!W_ID_PIN)
// 			{
// 				if(misc_interface.typea2.t_isnotexist++> C_LITTLE_CURRENT_TIME)/////t_isnotexist 是8位  C_LITTLE_CURRENT_TIME=10000 不符合
// 				{
// 					misc_interface.typea2.b_load_sta= false;
// 					misc_interface.typea2.t_isnotexist= 0;
// 					misc_interface.typea2.t_prohbit_check= C_PROHBIT_CHECKLOAD;//// 重置2S 负载检测///
// 					WR_5V9V_out_in=0;
// 					inoutput_data.vbus_switch.sw.type_cb=0;
					
// //					mod_queue_send(PLUG_A1D_OUT);
//                     mod_queue_send(PLUG_CBX_OUT);
// 			    	WR_IN_DIS=0;
// //					if(plug_state_context.state.byte& CBD_CBC_CAD_CAC__N___N_)
// //	                if((plug_state_context.state.byte& _N___N__CAD_CAC__N___N_)&&(!USBA_IN_DIS))/// 只有A口有输入输出时
// //					{
// //						h_pd.input.local_source_cap_count = PDO_SOURCECAP_COUNT;///// A口移除 CACB口有插入则恢复输出快充/////
// //						plug_state_context.event_flag.b_cax_break= true;
// //					}
// 				}
// 			}
// 			else
// 			misc_interface.typea2.t_isnotexist= 0;
		}	
//	}
}

void mod_io_vbus_switch(void)
{
	static bool port_reuse_vbus_disc= false;
	
	/** type-a_1 vbus(reg: gpo) switch**//// USBA 口开关MOS管理 GPO_CTRL
//	if((inoutput_data.vbus_switch.sw.type_a1)&& 				\
//		(!inoutput_data.vbus_switch.vbus_type_a1_delay_cnt))
//	{
////      USBA_PIN_ON;
//	}
//	else
//	{
////      USBA_PIN_OFF;
//	}
	
	/** type-b_1 vbus(reserved) switch**/
//	if((inoutput_data.vbus_switch.sw.type_b1)&& 				\
//		(!inoutput_data.vbus_switch.vbus_type_b1_delay_cnt))
//	{
//	  MIR_B_PIN_ON;
//	}
//	else
//	{
//	  MIR_B_PIN_OFF;
//	}
	
	/** type-c_a vbus(reg: pgate) switch**/// TCA MOS 管理 EN_PGATE
	if((inoutput_data.vbus_switch.sw.type_ca)&& 				\
		(!inoutput_data.vbus_switch.vbus_type_ca_delay_cnt))
	{
		/** open type-c_a vbus**/
		/** dcdc open pgate**/
        TCA_PIN_ON;
       	multi_protocol.dcp.mos_open_flag|= 0x01;//// CA
	}
	else
	{
		/** close type-c_a vbus**/
		/** dcdc close pgate**/
		TCA_PIN_OFF;
		multi_protocol.dcp.mos_open_flag&= 0xfe;
	}
	
//	/** type-c_b vbus(io) switch**////TCB MOS 管理
//	if((inoutput_data.vbus_switch.sw.type_cb)&& 				\
//		(!inoutput_data.vbus_switch.vbus_type_cb_delay_cnt))
//	{
//		/** open type-c_b vbus**/
//		/** io open**/
////#if CFG_SIMP_GPIO
////		PT20= true^ PRE_TCB_VBUS_POLARITY;
////#else
////		gpio_write_bit(P_TCB_VBUS, true^ PRE_TCB_VBUS_POLARITY);
////#endif
////       TCB_EN_OPEN;
//       USBA2_EN_ON=1;
//	}else
//	{
//	   USBA2_EN_ON=0;
//		/** close type-c_b vbus**/
//		/** io close**/
////#if CFG_SIMP_GPIO
////		PT20= false^ PRE_TCB_VBUS_POLARITY;
////#else
////		gpio_write_bit(P_TCB_VBUS, false^ PRE_TCB_VBUS_POLARITY);
////#endif
////        TCB_EN_Close;
//	}

	/** vbus discharge(io) switch**///// VBUS 泄放开关///////
	if((inoutput_data.vbus_switch.sw.discharge)&& 				\
		(inoutput_data.vbus_switch.vbus_discharge_delay_cnt))
	{
		/** open discharge**/
		/** io open**/
		if(!port_reuse_vbus_disc)
		{
			port_reuse_vbus_disc= true;
			//////////////////
			SW7203VbusDischarge(1);//打开泄放电
			///////////////////////
//			mod_io_init_vbus_discharge();//// PT37 变成IO状态	
//#if CFG_SIMP_GPIO
//			PT37= true^ PRE_VBUS_DISC_POLARITY;
//#else
//			gpio_write_bit(P_VBUS_DISC, true^ PRE_VBUS_DISC_POLARITY);
//#endif
		}
	}
	else
	{
		/** close discharge**/
		/** io close**/
		if(port_reuse_vbus_disc)
		{
			port_reuse_vbus_disc= false;
			inoutput_data.vbus_switch.sw.discharge= false;
			//////////////
			SW7203VbusDischarge(0);//关闭泄放电
		///////////////////////	
//#if CFG_SIMP_GPIO
//			PT37= false^ PRE_VBUS_DISC_POLARITY;
//#else
//			gpio_write_bit(P_VBUS_DISC, false^ PRE_VBUS_DISC_POLARITY);
//#endif
			
//			mod_io_init_ta1_curr();/// PT37 变成ADC检测口状态
		}
	}//	/** dcdc pstop(io) switch**///// 8815 STOP 脚管理
//	if((inoutput_data.vbus_switch.sw.pstop)&& 					\
//		(!inoutput_data.vbus_switch.pstop_delay_cnt))
//	{
//		/** open pstop**/
//		/** io open**/
////#if CFG_SIMP_GPIO
////		PT22= true^ PRE_PSTOP_POLARITY;
////#else
////		gpio_write_bit(P_PSTOP, true^ PRE_PSTOP_POLARITY);
////#endif
//	}
//	else
//	{
//		/** close pstop**/
//		/** io close**/
////#if CFG_SIMP_GPIO
////		PT22= false^ PRE_PSTOP_POLARITY;
////#else
////		gpio_write_bit(P_PSTOP, false^ PRE_PSTOP_POLARITY);
////#endif
//	}
}


//Called in the 1ms loop
void mod_io_vbus_switch_timer(void)
{
	inoutput_p= &inoutput_data.vbus_switch.vbus_type_a1_delay_cnt;
	for(uint8_t i= 0; i< 6; i++)
	{
		if(*inoutput_p){(*inoutput_p)--;}
		inoutput_p++;
	}
	inoutput_p= NULL;
	// if(inoutput_data.vbus_switch.vbus_type_a1_delay_cnt){inoutput_data.vbus_switch.vbus_type_a1_delay_cnt--;}
	// if(inoutput_data.vbus_switch.vbus_type_b1_delay_cnt){inoutput_data.vbus_switch.vbus_type_b1_delay_cnt--;}
	// if(inoutput_data.vbus_switch.vbus_type_ca_delay_cnt){inoutput_data.vbus_switch.vbus_type_ca_delay_cnt--;}
	// if(inoutput_data.vbus_switch.vbus_type_cb_delay_cnt){inoutput_data.vbus_switch.vbus_type_cb_delay_cnt--;}
	// if(inoutput_data.vbus_switch.vbus_discharge_delay_cnt){inoutput_data.vbus_switch.vbus_discharge_delay_cnt--;}
	// if(inoutput_data.vbus_switch.pstop_delay_cnt){inoutput_data.vbus_switch.pstop_delay_cnt--;}
}


/** vbus_in, is-> true, break-> false**/
bool mod_io_typeca_acin(void)
{
//	return M_DCDC_REG_GET(dcdc_data.reg.status, AC_OK, 1)^ PRE_TCA_ACIN_POLARITY;
	///PRE_TCA_ACIN_POLARITY=0;/// M_DCDC_REG_GET(dcdc_data.reg.status, AC_OK, 1)=0 返回1 CA_IN_Flage=0;
//	return CA_IN_Flage^ PRE_TCA_ACIN_POLARITY;//0-1  1-0
//return

//  unsigned char CA_data;
//    if(CA_IN_Flage)
//  CA_data=0;///----0
//  else
//  CA_data=1;////--1
//  return CA_data;
  return CA_IN_Flage^0;
}


/** vbus_in, is-> true, break-> false**/
bool mod_io_typecb_acin(void)
{

  return CB_IN_Flage^0;
  
//  unsigned char CB_data;
//  if(CB_IN_Flage)1-0 0-1
//  CB_data=0;///----0
//  else
//  CB_data=1;////--1
////return CB_data;
//#if CFG_SIMP_GPIO
//	return CB_data^ PRE_TCB_ACIN_POLARITY;
//#else
//	return CB_data^ PRE_TCB_ACIN_POLARITY;
//#endif
  
//#if CFG_SIMP_GPIO
//	return PT13^ PRE_TCB_ACIN_POLARITY;
//#else
//	return gpio_read_bit(P_TCB_ACIN)^ PRE_TCB_ACIN_POLARITY;
//#endif
/////PRE_TCB_ACIN_POLARITY==1；PT13==1；返回1 ==  没有电 CB_IN_Flage=0;
}

void adc_irq(void)
{
	if(__ADC_SRADIE_GET_SHIFT()!= 0)
	{
		adc_convert.flag.convert_refresh= true;//// ADC 中断更新数据
		adc_convert.code_rt= adc_get_srad();/// 数据放到 adc_convert.code_rt
		
//		adc_branch_cnt=0;
	}
}
// void adc_irq(void)
//{
//	if(__ADC_SRADIE_GET_SHIFT()!= 0)
//	{
//		adc_convert.flag.convert_refresh= true;
//		adc_convert.code_rt= adc_get_srad();
//	}
//}
 
 
 
void mod_io_a1d_out(void)
{
	misc_interface.typea1.b_load_sta= false;	
	misc_interface.typea1.t_isnotexist= 0;	
	misc_interface.typea1.t_prohbit_check= C_PROHBIT_CHECKLOAD;
	mod_queue_send(PLUG_A1D_OUT);
}

