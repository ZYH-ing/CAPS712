/**************************************************************************//**
 * @file     app_debug.c
 * @version  V1.0.0
 * @author   0531
 * @date     2021-01-15 PM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 *****************************************************************************/


// Include header file.
#include "cs_common.h"
#include "system_csu39fx10.h"

//driver
#include "csu39fx10_syscfg.h"
#include "csu39fx10_exti.h"
#include "drv_gpio.h"
#include "drv_timer.h"
#include "drv_uart.h"
#include "drv_wdt.h"
#include "drv_iic.h"
#include "drv_adc.h"
#include "drv_flash.h"

//module
#include "mod_display.h"
#include "mod_key.h"
#include "mod_dcdc.h "
#include "mod_input_output.h"
#include "mod_adc_convert.h"
#include "mod_coulomb.h"

//protocol
#include "lib_prot_pd.h"
#include "lib_prot_typec.h"
#include "lib_prot_typec.h"
#include "lib_multi_protocol.h"

//app
#include "app_init.h"
#include "app_main.h"
#include "app_typec_deal.h"
#include "app_state_machine.h"

#include "app_debug.h"



void test_display(void);
void test_key(void);
void test_dcdc_print(void);
void test_adcconvert_print(void);


void test_display(void)
{

}

void test_key(void)
{
	if(!mod_key_get_data())
	{
//		mod_display_led(p_led_0, true);
	}
}

void test_dcdc_print(void)
{
	static uint8_t switch_branch= 0;
	static uint8_t Flage_adr= 0;
    uint8_t	RE_data_temp8;
    uint16_t RE_data_temp16;
    uint16_t Readdata;
    
	switch_branch++;
   #if  Bat_Cnt
	if(switch_branch>=200)////200*100ms////  20S
   #else
	if(switch_branch>=5)////3*100ms////
   #endif
	{
	    switch_branch= 0;
	#if  Bat_Cnt
	    Sub_sim_tx(0xaa);
		Sub_sim_tx(BatCap_Value);//// 电池电量参数/////
		Sub_sim_tx(Vbat_8_date);/// 电池电压
		Sub_sim_tx(BAT_real);/// 电池换算真实电压
//	
//		Sub_sim_tx(CIbat_8_date>>8);//// 真实的电池电流
		Sub_sim_tx(CIbat_8_date);
		Sub_sim_tx(I_All_IN_Do>>8);////计算的电池电流
		Sub_sim_tx(I_All_IN_Do);
		Sub_sim_tx(UTX_16_data3>>8);///累计的电量值
		Sub_sim_tx(UTX_16_data3);
		Sub_sim_tx(Bat_low_Cnt);
		Sub_sim_tx( coulomb_data.output.b_batt_full);
//		Sub_sim_tx(coulomb_data.output.b_batt_low);/////coulomb_data.output.b_batt_low	
//		Sub_sim_tx(coulomb_data.output.b_batt_full);/////coulomb_data.output.b_batt_low
//		Sub_sim_tx(VBAT_7201_Vaule>>8); ////电流累计值 *1000////
//		Sub_sim_tx(VBAT_7201_Vaule);
	 #else
	    Sub_sim_tx(0xaa);
	    Sub_sim_tx(plug_state_context.state.byte& 0x3F);
	    Sub_sim_tx(discharge_displed);
//	    Sub_sim_tx(TYPE_C_Waittime_Cnt);//// TYPE_C_Waittime_Cnt
//	    Sub_sim_tx(TYPE_CA_18W_Flage); ///TYPE_CA_18W_Flage
//	    Sub_sim_tx(adc_convert.typea_1.adc_code_sl);////adc_convert.typea_1.adc_code_sl
//	    Sub_sim_tx(close_lcd_light_cnt);
	    
//	    RE_data_temp8=iic_receive_byte(0x39);
//	    Sub_sim_tx(RE_data_temp8);
//	    Sub_sim_tx(CIbus_16_date>>8);///累计的电量值
//		Sub_sim_tx(CIbus_16_date);
//	    Sub_sim_tx(CIbus_8_date);
	    
//	    Sub_sim_tx(UTX_8_data1);
//	    Sub_sim_tx(sleepcnt);//// sleepcnt
//	    RE_data_temp8=iic_receive_byte(0x22);
//	    Sub_sim_tx(RE_data_temp8);
//	    Sub_sim_tx(TCA_PIN);///TCA_PIN 
//	    Sub_sim_tx(0xbb);
//	    Sub_sim_tx(!Temp.ChargeTemp_OK);/////
//	    Sub_sim_tx(V_NO_Cha_flage);/////
//	    Sub_sim_tx(V_NO_BAT_Charge);
//	    Sub_sim_tx(Bat_Protest_cnt>=OVP_CHARGE_TIME);
//      Sub_sim_tx(Charge_OCP_Flage);/////
//      Sub_sim_tx(Bat_low_sleep_flage);
//      Sub_sim_tx(Bat_Low_5V_NG_Flage); /////Bat_Low_5V_NG_Flage  
//////////////// 电池老化数据 处理////////////
//		Sub_sim_tx(plug_state_context.state.byte& 0x3F);
//	    Sub_sim_tx(VBAT_7201_Vaule>>8); ////电流累计值 *1000////
//		Sub_sim_tx(VBAT_7201_Vaule);
//		Sub_sim_tx(Vbat_8_date);/// 电池电压
        #if 0
	//////////////////////////// 20组 的存储处理///////	
		RE_data_temp8=iic_receive_24C02_byte(RCR_BAT_Vol_cnt_addr);
		Sub_sim_tx(RE_data_temp8);////记录到哪一个了///
		Sub_sim_tx(Flage_adr);
		RE_data_temp8=Flage_adr;
		RE_data_temp8=Flage_adr*2;
		RE_data_temp8=RCR_BAT_Vol_First_addr+RE_data_temp8;
		RE_data_temp8=iic_receive_24C02_byte(RE_data_temp8);
		Sub_sim_tx(RE_data_temp8);
		RE_data_temp8=Flage_adr*2;
		RE_data_temp8=RE_data_temp8+1;
		RE_data_temp8=RCR_BAT_Vol_First_addr+RE_data_temp8;
		RE_data_temp8=iic_receive_24C02_byte(RE_data_temp8);
		Sub_sim_tx(RE_data_temp8);
		if(Flage_adr)
		{
			if(Flage_adr>=(RCR_BAT_Vol_First_Cnt-1))
			 Flage_adr=0;
			else
			 Flage_adr++;
		}
	     else///////0-1//
		{
			 Flage_adr=1;
		}	
  ///////////////////////////////////////////////    
      #endif
//		Flage_adr++;
//		Sub_sim_tx(RE_data_temp8);/// 电池电压
//		Sub_sim_tx(discharge_displed);
//      Sub_sim_tx(Port_NTC_NG_LOW_POWER_Flage);//// Port_NTC_NG_LOW_POWER_Flage
//		Sub_sim_tx(adc_convert.type_ntc2.adc_code_sl>>8); ////电流累计值 *1000////
//		Sub_sim_tx(adc_convert.type_ntc2.adc_code_sl);
//		Sub_sim_tx(key_down_10S_Flage);
//		Sub_sim_tx(BatCap_Value);
//		Sub_sim_tx(Bat_low_Cnt);////BAT_CO_PIN//// BatCap_Value
//		Sub_sim_tx(0xbb);
//		Sub_sim_tx(Bat_low_RE_Cnt);
//		Sub_sim_tx(R_DisCharge_SmallCurCnt);///Frist_start_sink
//		Sub_sim_tx(discharge_displed);
//		Sub_sim_tx(sleepcnt);
//		Sub_sim_tx(VBAT_7201_Vaule>>8); ////电流累计值 *1000////
     #endif
	}
}

void test_adcconvert_print(void)
{
	static uint8_t switch_branch;
	switch_branch++;
	if(switch_branch>=2)////2*100ms////
	{
	    switch_branch= 0;
//		uart_putchar(0xaa);
//		uart_putchar((plug_state_context.state.byte& 0x3F));
	}
}
