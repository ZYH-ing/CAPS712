/***************************************************************************//**
 * @file     mod_display.c
 * @version  V1.0.0
 * @author   0531
 * @date     2020-11-02 AM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 *****************************************************************************/

// Include header file.
#include "mod_display.h"

#include "app_state_machine.h"
#include "mod_coulomb.h"
#include "app_main.h"
#include "app_init.h"

#include "mod_adc_convert.h"
#include "mod_key.h"

BANK_DISP display_t		display_data;

uint8_t Err_diply;
uint8_t Err_diply_check_time_cnt;

BANK_DISP uint8_t Car_lighting_bright;
BANK_DISP uint8_t Key_up_flage;
/**@brief display initialization.
 * 
 * @param[in]  null.
 * @param[out] null.
 * 
 * @return  null.
 */
void mod_display_init(void)
{
	display_data.disp_data.bit.led_0= false;
	display_data.disp_data.bit.led_1= 0;
	display_data.disp_data.bit.led_3= 0;

	display_data.disp_data.bit.led_2= 0;
	display_data.disp_data.bit.led_6= 0;

	display_data.disp_data.bit.led_4= 0;
	display_data.disp_data.bit.led_5= 0;
	display_data.key_data.key_0= false;
	display_data.disp_refresh_status= 0x00;
}
 
 
void mod_display_disable(void)
{
	/** PT14 init**/
	PT1EN4= 0;
	PT1PU4= 1;
	PT14= 0;
	/** PT15 init**/
	PT1EN5= 1;
	PT1PU5= 0;
	PT15= 0;
	/** PT26 init**/
	PT2EN6= 0;
	PT2PU6= 1;
	PT26= 0;
}


/**@brief led display.
 * 
 * @param[in]  disp_led_t _led 	led number{disp_led_t}.
 * @param[in]  bool _on			true-> on, false-> false.
 * @param[out] null.
 * 
 * @return  null.
 */
void mod_display_led(disp_led_t _led, bool _on)
{
	_on? (display_data.disp_data.byte|= (1<< _led)): (display_data.disp_data.byte&= ~(1<< _led));
}


/**@brief led toggle.
 * 
 * @param[in]  disp_led_t _led 	led number{disp_led_t}.
 * @param[out] null.
 * 
 * @return  null.
 */
void mod_display_led_toggle(disp_led_t _led)
{
	display_data.disp_data.byte^= (1<< _led);
}


/**@brief led and key refresh.
 * 
 * @param[in]  null.
 * @param[out] null.
 * 
 */
void __mod_display_led_key_refresh(void)////没有使用
{
//	//key scan
//	//the display port is configured as input without pull-up(turn off display)
//	
//	PT1EN0= 0;  //P_LED_1_P
//	PT1EN6= 0;  //P_LED_2_P
//	PT1EN1= 0;  //P_LED_3_P
//	// gpio_dir_bit(P_LED_1_P, dir_input);
//	// gpio_dir_bit(P_LED_2_P, dir_input);
//	// gpio_dir_bit(P_LED_3_P, dir_input);
//	
//	PT1PU7= 1;
//	// gpio_pull_bit(P_LED_0, pull_up);
//	PT1EN7= 0;
//	// gpio_dir_bit(P_LED_0, dir_input);
//	
//#if CFG_SIMP_GPIO
//	display_data.key_data.key_0= PT17;
//#else
//	display_data.key_data.key_0= gpio_read_bit(P_LED_0);
//#endif
//	
//	PT1PU7= 0;
//	// gpio_pull_bit(P_LED_0, no_pull);
//	
//	// gpio_dir_bit(P_LED_0, dir_output);
//
//	//display refresh
//	//refresh led0
//	PT1EN7= 1;
//	PT17= display_data.disp_data.bit.led_0;
//	
//	switch(display_data.disp_refresh_status++)
//	{
//		case 0:
//			// refresh led1
//			PT1EN6= 1;
//			PT16= 0;
//			
//			PT1EN0= 1;
//			PT10= display_data.disp_data.bit.led_5;
//			break;
//		case 1:
//			// refresh led2
//			PT1EN0= 1;
//			PT10= 0;
//			
//			PT1EN6= 1;
//			PT16= display_data.disp_data.bit.led_6;
//			break;
//		case 2:
//			// refresh led3
//			PT1EN6= 1;
//			PT16= 0;
//			
//			PT1EN1= 1;
//			PT11= display_data.disp_data.bit.led_4;
//			break;
//		case 3:
//			// refresh led4
//			PT1EN1= 1;
//			PT11= 0;
//			
//			PT1EN6= 1;
//			PT16= display_data.disp_data.bit.led_3;
//
//			// display_data.disp_refresh_status= 0;
//			break;
//		case 4:
//			// refresh led5
//			PT1EN1= 1;
//			PT11= 0;
//			
//			PT1EN0= 1;
//			PT10= display_data.disp_data.bit.led_1;
//			break;
//		case 5:
//			// refresh led6
//			PT1EN0= 1;
//			PT10= 0;
//			
//			PT1EN1= 1;
//			PT11= display_data.disp_data.bit.led_2;
//
//			display_data.disp_refresh_status= 0;
//			break;
//		default:
//			break;
//	}
}

void mod_display_led_key_refresh(void)
{
////	PT1EN5= 0;  //P_LED_1_P
////	PT1EN4= 0;  //P_LED_2_P
////	PT2EN6= 0;  //P_LED_3_P
//    
//   	LED1_PIN_EN= 0;  //P_LED_1_P
//	LED2_PIN_EN= 0;  //P_LED_2_P
//	LED3_PIN_EN= 0;  //P_LED_3_P
//    
//	////////////////按键检测
////	KEY1_inti;
////	display_data.key_data.key_0=1;
//////	PT2PU6=1;
////	asm("nop");
////	asm("nop");
////	asm("nop");
////	asm("nop");
////	asm("nop");
////	asm("nop");
////	asm("nop");
////	asm("nop");
////	asm("nop");
////	asm("nop");
////	asm("nop");
////	asm("nop");
////	asm("nop");
////	asm("nop");
////	asm("nop");
////	asm("nop");
////	asm("nop");
////	asm("nop");
////	asm("nop");
////	asm("nop");
////	if(KEY1)
////	display_data.key_data.key_0=1;
////	else
////	display_data.key_data.key_0=0;
////	PT1PU2=0;
////	Key_up_flage=display_data.key_data.key_0;
//	
//	
//	///////////////////
//	switch(display_data.disp_refresh_status++)
//	{
//		case 0:
//		  	LED2_PIN= 1;  //
//            LED2_PIN_EN= display_data.disp_data.bit.led_2;  //		
//			LED2_PIN= display_data.disp_data.bit.led_2;  //
//
//			LED3_PIN= 1;  //
//			LED3_PIN_EN= display_data.disp_data.bit.led_6;  //			
//			LED3_PIN= display_data.disp_data.bit.led_6;  //
//			
//			
//			if((display_data.disp_data.bit.led_2)||(display_data.disp_data.bit.led_6))
//	    	{
//			  LED1_PIN= 0;  //P_LED_1_P
//			  LED1_PIN_EN= 1;  //P_LED_1_P
//	    	}
//			
//			if(Car_lighting_bright)
//			{
//			
//				LED4_PIN= 1;  //
//			    LED4_PIN_EN= 1;  //
//			}
//			else
//			{
//			  	LED4_PIN= 0;  //
//			    LED4_PIN_EN= 1;  //
//			}
//			break;
//		case 1:
//	    	LED1_PIN= 1;  //
//            LED1_PIN_EN= display_data.disp_data.bit.led_1;  //		
//			LED1_PIN= display_data.disp_data.bit.led_1;  //
//
//			LED3_PIN= 1;  //
//			LED3_PIN_EN= display_data.disp_data.bit.led_3;  //			
//			LED3_PIN= display_data.disp_data.bit.led_3;  //
//			
//			LED2_PIN= 0;  //P_LED_2_P
//			LED2_PIN_EN= 1;  //P_LED_2_P
//			break;
//		case 2:
//		    LED1_PIN= 1; 
//            LED1_PIN_EN= display_data.disp_data.bit.led_5;  	
//			LED1_PIN= display_data.disp_data.bit.led_5;  //
//
//			LED2_PIN= 1;  //
//			LED2_PIN_EN= display_data.disp_data.bit.led_4;  //			
//			LED2_PIN= display_data.disp_data.bit.led_4;  //
//			
//			
//			if((display_data.disp_data.bit.led_4)||(display_data.disp_data.bit.led_5))
//	    	{
//			  LED3_PIN= 0;  //P_LED_3_P
//		      LED3_PIN_EN= 1;  //P_LED_3_P
//	    	}
//			
//			display_data.disp_refresh_status= 0;
//			break;
//		default:
//			break;
//	}
}

void mod_display_batt_level(uint8_t _batt_energy)
{
	static uint8_t disp_cnt= 0;
	static bool disp_batt_flash= 1;
	if(disp_cnt++>= 5)////// 500ms 更新一下显示和 灯闪烁//////
	{
		     disp_cnt= 0;
		if((plug_state_context.state.bit.b_bcxc&		\
//			!coulomb_data.output.b_batt_full)||(_batt_energy<10))//////  充电状态///////
           	!coulomb_data.output.b_batt_full)||(_batt_energy<5))//////  充电状态///////
		{
//            if((!V_NO_BAT_Charge)&&(Temp.ChargeTemp_OK)&&(!V_NO_Cha_flage)&&(Bat_Protest_cnt<10)&&(!Charge_OCP_Flage))
//            if((!V_NO_BAT_Charge)&&(Temp.ChargeTemp_OK)&&(!V_NO_Cha_flage)&&(!Bat_Protest_cnt)&&(!Charge_OCP_Flage))
            if((Temp.ChargeTemp_OK)&&(!V_NO_Cha_flage)&&(!Charge_OCP_Flage))
			disp_batt_flash^= 1;
			else
			disp_batt_flash= 1;
		}
		else
		{
			disp_batt_flash= 1;///// 1亮 0灭 ///// 放电状态灯不闪///////
		}
		
//		mod_display_led(p_led_1, false);
//		mod_display_led(p_led_2, false);
//	    mod_display_led(p_led_3, false);
//		mod_display_led(p_led_4, false);
//	    mod_display_led(p_led_5, false);
//	    mod_display_led(p_led_6, false);
//        Car_lighting_bright=0;///LED7
        
//		if(_batt_energy>= 75)
//		{
//			mod_display_led(p_led_1, true);
//			mod_display_led(p_led_2, true);
//			mod_display_led(p_led_3, true);
//			mod_display_led(p_led_4, disp_batt_flash);
//		}
//		else if(_batt_energy>= 50)
//		{
//			mod_display_led(p_led_1, true);
//			mod_display_led(p_led_2, true);
//			mod_display_led(p_led_3, disp_batt_flash);
//		}
//		else if(_batt_energy>= 25)
//		{
//			mod_display_led(p_led_1, true);
//			mod_display_led(p_led_2, disp_batt_flash);
//		}
//		else 
//		{
//	    	mod_display_led(p_led_1, disp_batt_flash);
//		}
//		////////车充显示处理///////
//		if(R_SysMode_OK!=COULOMB_CHARGE)
//	   {
//		   if(car_ST)
//		  {
//			if((car_ST==3)||(car_ST==5)||(car_ST==6))//// 点火成功
//			{
//              mod_display_led(p_led_5, true);
////                 Car_lighting_bright=1;
//			}
//			else if(car_ST==2)
//			{
//              mod_display_led(p_led_6, true);
//			}
//			else 
//			{
//              Car_lighting_bright=1;
////               mod_display_led(p_led_5, true);
//			}
//		  }
//		  
//		  if((_batt_energy<5)&&(Bat_low_Cnt<25)&&(sleepcnt<2))//// 放电或待机状态 电量小于5 一直显示////
//		  {
//		     discharge_displed=1; UTX_8_data1=1;/// 5% 一下电量 电量灯一直显示/////
//		  }
//		  
////		  if(discharge_displed>=displaytime)
////		  {
////			discharge_displed=displaytime;
////			mod_display_led(p_led_1, false);
////			mod_display_led(p_led_2, false);
////			mod_display_led(p_led_3, false);
////			mod_display_led(p_led_4, false);
////		  }
//		}
   } 
   
   
//   if(Bat_low_sleep_flage)
//   {
//    	mod_display_led(p_led_1, false);
//		mod_display_led(p_led_2, false);
//		mod_display_led(p_led_3, false);
//		mod_display_led(p_led_4, false);
//   }
   
}

/**@brief get key data.
 * 
 * @param[in]  null.
 * @param[out] null.
 * 
 * @return  null.
 */
bool mod_key_get_data(void)
{
	////////////////按键检测
	// KEY1_inti;
	// if(KEY1)
	// display_data.key_data.key_0=1;
	// else
	// display_data.key_data.key_0=0;
	Key_up_flage=display_data.key_data.key_0;
	
	return display_data.key_data.key_0;
}

//mod_key_get_data(void)
//{

