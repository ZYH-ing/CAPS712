/***************************************************************************//**
 * @file     mod_key.c
 * @version  V1.0.0
 * @author   sz414
 * @date     2020-11-02 AM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 *****************************************************************************/

// Include header file.
#include "mod_key.h"
#include "mod_display.h"
#include "app_init.h"
#include "app_main.h"

#include "app_state_machine.h"
#include "mod_input_output.h"
#include "mod_queue.h"
#include "mod_coulomb.h"
#include "mod_adc_convert.h"
#include "app_typec_deal.h"

BANK_KEY key_t	key_data;
BANK_KEY key_t	key2_data;
BANK_KEY uint8_t Vaule1;


BANK_KEY uint8_t Set_3S_to_into_IAP;

BANK_KEY uint8_t short_key_to_IAPtime;
BANK_KEY uint8_t short_key_to_IAP_Cnt;

BANK_KEY uint8_t F_A1_ON;
BANK_KEY uint8_t F_A1ON_TIME;

BANK_KEY uint8_t key_down_5S_Flage;
BANK_KEY uint16_t key_down_5S_Cnt;


BANK_KEY uint8_t key_down_10S_Flage;
BANK_KEY uint16_t key_down_10S_Cnt;



/**@brief key initialization.
 * 
 * @param[in]  null.
 * @param[out] null.
 * 
 * @return  null.
 */
void mod_key_init(void)
{
	//param init
	key_data.key_value= key_null;
}


/**@brief key value scan.
 * 
 * @param[in]  null.
 * @param[out] null.
 * 
 * @return  null.
 */

 void key_scan(void)//// 按键扫描检测////
{
// 	//////////////////
// 	if(Sleep_up_shor_do)
// 	{
// 	  Sleep_up_shor_do=0;
// 	  key_data.key_cnt= C_KEY_CNT_SHORT+2;
// 	}
// ////////// 按键1处理/////////////////
// 	if(key_data.double_press_cnt)
// 	{
// 		key_data.double_press_cnt--;
// 	}

// 	if(!mod_key_get_data())////按键按下 电平为低电平
// 	{
// 		if(!key_data.flag.long_press)
// 		{
// 			//  key press
// 			if(key_data.key_cnt++> C_KEY_CNT_LONG)
// 			{
// 			//  key value refresh(long)
// 				key_data.key_value= key_long;
// 				key_data.flag.value_refresh= true;
// 				key_data.flag.long_press= true;
// 				key_data.key_cnt= 0;
// 				key_data.double_press_cnt= 0;
// 			}
// 			else
// 			{
// 			//	key_data.key_value= key_null;
// 			}
// 		}
// 	}
// 	else//// 按键起来 电平为高电平
// 	{
// 		//key release
// 		key_data.flag.long_press= false;

// 		if(key_data.key_cnt> C_KEY_CNT_SHORT)
// 		{
// 			key_data.key_value= key_short;
// 			key_data.flag.value_refresh= true;

// 			if(key_data.double_press_cnt)/// 0.5S 内单机两次 则为双击///
// 			{
// 				key_data.key_value= key_double;
// 				key_data.flag.value_refresh= true;
// 				key_data.double_press_cnt= 0;
// 			}
// 			else
// 			{
// 				key_data.double_press_cnt= C_KEY_CNT_DOUBLE;
// 			}
// 		}
// 		key_data.key_cnt= 0;
// 	}
// 	////////////
// #if 1
// 	if(!mod_key_get_data())
// 	{
//           key_down_5S_Cnt++;
// 	     if(key_down_5S_Cnt==500)
//         {
// //           if(key_down_5S_Flage)
// //             key_down_5S_Flage=0;
// //           else
// //             key_down_5S_Flage=1;
//           if(!Change_lauge_Cnt)
//           {
//             Change_lauge_Cnt=1;
//             WHITE_ON=0;
//             Change_lauge_Time_Cnt=0;
//             discharge_displed=1;
//             Change_lauge_Flage=iic_receive_24C02_byte(RCR_Lange_cnt_addr);
//           }
//         }
//         if(key_down_5S_Cnt>600)
//          key_down_5S_Cnt=600;
// 	}
// 	else
// 	{
// //	     if(key_down_5S_Cnt>=500)
// //        {
// //           if(key_down_5S_Flage)
// //             key_down_5S_Flage=0;
// //           else
// //             key_down_5S_Flage=1;
// //        }
// 			key_down_5S_Cnt=0;
// //			Change_lauge_Cnt=0;
// 	}
// #else
//   key_down_5S_Flage=0;
// #endif


// #if 0
// 	if(!mod_key_get_data())
// 	{
//         key_down_10S_Cnt++;
//         if(key_down_10S_Cnt>1100)
//         {
//          key_down_10S_Cnt=1100;
//          if(!key_down_10S_Flage)
//          {
//             key_down_10S_Flage=1;
//          }
//         }
// 	}
// 	else
// 	{
// //	     if(key_down_10S_Cnt>=1000)
// //        {
// //           if(key_down_10S_Flage)
// //             key_down_10S_Flage=0;
// //           else
// //             key_down_10S_Flage=1;
// //        }
//         key_down_10S_Cnt=0;
// 	}
// #else
//   key_down_10S_Flage=0;
// #endif
}

void key2_scan(void)//// 按键扫描检测////
{
//      if(key2_data.double_press_cnt)
//	{
//		key2_data.double_press_cnt--;
//	}	
//	
//	if(!KEY2)////按键按下 电平为低电平
//	{
//		if(!key2_data.flag.long_press)
//		{
//			//  key press
//			if(key2_data.key_cnt++> C_KEY_CNT_LONG)
//			{
//			//  key value refresh(long)
//				key2_data.key_value= key_long;
//				key2_data.flag.value_refresh= true;
//				key2_data.flag.long_press= true;
//				key2_data.key_cnt= 0;
//				key2_data.double_press_cnt= 0;
//			}
//			else
//			{
//			//	key_data.key_value= key_null;
//			}
//		}
//	}
//	else//// 按键起来 电平为高电平
//	{
//		//key release
//		key2_data.flag.long_press= false;
//
//		if(key2_data.key_cnt> C_KEY_CNT_SHORT)
//		{
//			key2_data.key_value= key_short;
//			key2_data.flag.value_refresh= true;
//
//			if(key2_data.double_press_cnt)/// 0.5S 内单机两次 则为双击///
//			{
//				key2_data.key_value= key_double;
//				key2_data.flag.value_refresh= true;
//				key2_data.double_press_cnt= 0;
//			}
//			else
//			{
//				key2_data.double_press_cnt= C_KEY_CNT_DOUBLE;
//			}
//		}
//		key2_data.key_cnt= 0;
//	}
/////////////////////////////
}


/**@brief key handler.
 * 
 * @param[in]  null.
 * @param[out] null.
 * 
 * @return  null.
 */
void key_proc(void)//// 按键处理/////
{
//   	if(key_data.double_press_cnt)
//   	{
//   	   return;
//   	}
// 	if(key_data.flag.value_refresh)
// 	{
// 		key_data.flag.value_refresh= false;
// 		switch(key_data.key_value)
// 		{
// 			case key_short://// 短按处理
// 		 	  Out_Protest_Flage=0;
// 		      Discharge_MinCur=0;	
// 		      hour2_dis_flage=0;
//               hour2_dis_cnt=0;
// 			  R_DisCharge_SmallCurCnt=0;
// 			  R_DisCharge_OutTime=0;
			  
			  
// 			  if(Change_lauge_Cnt)
// 			{
// 			  Change_lauge_Flage++;
// 			  if(Change_lauge_Flage>3)
// 			  Change_lauge_Flage=1;
// 			  discharge_displed=1;
// 			  Change_lauge_Time_Cnt=0;///重新计时///
// 			}
			  
			  
// //	     #if __IF_DEBUG__
// //          Sub_sim_tx(0xCC);
// //		  Sub_sim_tx(0x01); 
// //		  #endif		  
// 			  ////////////////////
// 			if(Frist_Bat_Protest_do==Frist_start_sink)
// 			{
// 			  Frist_start_sink=Frist_normal_do;
// 			  typec_break(&h_typeca);	
// 			}
			  
// 			  EN_SYS_IN;
//              /////////////////////////保护取消处理//////验证OK///// 
//                if(Bat_low_sleep_flage)
// 			   {
// 			    typec_break(&h_typeca);
// 			    peripheral_typec_DRP_init(&h_typeca);
// 			    Bat_low_sleep_flage=0;
// 			    sleepcnt=0;
// 			   }
// 			 /////////////////////////  
//                F_A1_ON=1;
// 			   Sleep_up_close_Car_ignition=0;		
// 			   if(Bat_low_Cnt>=30)//// 持续测试到低电平30S
// 			   {
// 				  Bat_low_Cnt=40;
// 				  Err_diply=1;/// 报警闪烁4次 按键
// 				  Err_diply_check_time_cnt=0;
				  
// 				  discharge_displed=displaytime-5;
// 				  break;
// 			   }
			   
// 			   if(discharge_displed>=displaytime)
// 			   {
// 			     Star_Cartoon=1;
// 			   }
			   
// 			   discharge_displed=1;  UTX_8_data1=10;////按键电量显示初始化显示30S
			   
// 			if(R_SysMode_OK==COULOMB_CHARGE)
// 			{
// 				if(BatCap_Value==100)
// 				{
// 				   if(hex_greater_than_compare(close_lcd_light_cnt,(closelcdtime-1)))/////充饱灭屏处理////
// 				   {
// 				       close_lcd_light_cnt=(closelcdtime-12);
// 				   }
// 				}		
// 			}
			   
			   
			   
// //		  #if __IF_DEBUG__
// //          Sub_sim_tx(0xCC);
// //		  Sub_sim_tx(0x02); 
// //		  #endif
			   
			   
// //			   if((WHITE_ON||RED_ON)&&(R_SysMode_OK!= COULOMB_CHARGE)&&(Temp.DischargeTemp_OK))/// SOS 显示更新 达到2级后 关掉输出
//                if(((WHITE_ON==Power_long_LED)||(WHITE_ON==Power_Doule_LED))&&(R_SysMode_OK!= COULOMB_CHARGE)
//                &&(Temp.DischargeTemp_OK))
// 			   {
// 					SOS_LEVEL++;
// 					if(SOS_LEVEL>2)///// 长按开灯后在短按 切换灯显模式////
// 					{
// 					    SOS_LEVEL=0;
// 						WHITE_ON=0;
// 					}
// 				}
// 			   break;
// 			case key_double:// 双击处理 红灯SOS模式
// //			     Out_Protest_Flage=0; 
// //			    	     
// //                 if((Bat_low_Cnt>30)||(!Temp.DischargeTemp_OK))
// //				  {
// //				    if(R_SysMode_OK!= COULOMB_CHARGE)
// //				    {
// //						Discharge_MinCur=1;
// //				    }
// //				    break;
// //				  }

// 		  if(R_SysMode_OK== COULOMB_CHARGE)
// 			  break;
// 			if((Bat_low_Cnt>30)||(!Temp.DischargeTemp_OK))
// 		   {
// 			if(R_SysMode_OK!= COULOMB_CHARGE)
// 			{
// 				Discharge_MinCur=1;
// 			}
// 			break;
// 		   }
		   
// //			if(WHITE_ON)
// //			{
// //             if((WHITE_ON!=Power_Doule_LED))
// //			  break;
// //			}
			
// //			if((!WHITE_ON))
// //			{
// //			   WHITE_ON=Power_Doule_LED;
// //			}
// //			else  
// //			{
// //			   WHITE_ON=0;
// //			}
// //			   SOS_LEVEL=0;
// //			   flash_count=0;
// //			   sos_count=0;
// //			   sos_state=1;
// //			   coulomb_data.output.b_batt_full=0;
// //
// 				break;
// 			case key_long://// 长按处理  白灯SOS模式
// 			    Out_Protest_Flage=0;
// 				if((Bat_low_Cnt>30)||(!Temp.DischargeTemp_OK))
// 			   {
// 				if(R_SysMode_OK!= COULOMB_CHARGE)
// 				{
// 					Discharge_MinCur=1;
// 				}
// 				 break;
// 			   }
			   
// //			    if((WHITE_ON!=Power_long_LED)&&(WHITE_ON))
// //			   	 break;
			   
// 			    if(Change_lauge_Cnt)
// 			    {
// 			      if(Change_lauge_Time_Cnt<=40)
// 			         Change_lauge_Time_Cnt=40;
// 			      break;
// 			    }
			   
			   
			   
// 		        if((!WHITE_ON)&&(R_SysMode_OK!= COULOMB_CHARGE))
// 				{
// 					{
// 					   WHITE_ON=Power_long_LED;
// 					}
// 				}
// 			    else  
// 				{
// 				   WHITE_ON=0;
// 				}
// 				 SOS_LEVEL=0;
// 				 flash_count=0;
// 				 sos_count=0;
// 				 sos_state=1;
// 				 coulomb_data.output.b_batt_full=0;
// 				break;
// 			default:
// 				break;
// 		}
// 	    key_data.key_value=key_null;
// 	}
// }


// void key2_proc(void)//// 按键2处理/////
// {
//   	if(key2_data.double_press_cnt)
//   	{
//   	   return;
//   	}
// 	if(key2_data.flag.value_refresh)
// 	{
// 		key2_data.flag.value_refresh= false;
// 		switch(key2_data.key_value)
// 		{
// 			case key_short://// 短按处理
			
// 			if(R_SysMode_OK== COULOMB_CHARGE)
// 			  break;
// 			if((Bat_low_Cnt>30)||(!Temp.DischargeTemp_OK))
// 		   {
		   
// 			if(R_SysMode_OK!= COULOMB_CHARGE)
// 			{
// 				Discharge_MinCur=1;
// 			}
// 			break;
// 		   }
		   
// 			if(WHITE_ON)
// 			{
// //			  if((WHITE_ON!=Led_short_LED)||(WHITE_ON!=Power_Doule_LED))
//               if((WHITE_ON!=Led_short_LED))
// 			  break;
// 			}
			
// 			if((!WHITE_ON))
// 			{
// 			   WHITE_ON=Led_short_LED;
// 			   SOS_LEVEL=0;
// 			   flash_count=0;
// 			   sos_count=0;
// 			   sos_state=1;
// 			   coulomb_data.output.b_batt_full=0;
// 			}
// 			else  
// 			{
// 				SOS_LEVEL++;
// 				if(SOS_LEVEL>2)///// 长按开灯后在短按 切换灯显模式////
// 				{
// 					SOS_LEVEL=0;
// 					WHITE_ON=0;
// 					flash_count=0;
// 				    sos_count=0;
// 				    sos_state=1;
// 				    coulomb_data.output.b_batt_full=0;
// 				}
// 			}
// 		    break;
		    
// 			case key_double:// 双击处理
// //			 if(R_SysMode_OK== COULOMB_CHARGE)
// //			  break;
// //			if((Bat_low_Cnt>30)||(!Temp.DischargeTemp_OK))
// //		   {
// //			if(R_SysMode_OK!= COULOMB_CHARGE)
// //			{
// //				Discharge_MinCur=1;
// //			}
// //			break;
// //		   }
// //		   
// //			if(WHITE_ON)
// //			{
// //             if((WHITE_ON!=Power_Doule_LED))
// //			  break;
// //			}
// //			
// //			if((!WHITE_ON))
// //			{
// //			   WHITE_ON=Power_Doule_LED;
// //			}
// //			else  
// //			{
// //			   WHITE_ON=0;
// //			}
// //			   SOS_LEVEL=0;
// //			   flash_count=0;
// //			   sos_count=0;
// //			   sos_state=1;
// //			   coulomb_data.output.b_batt_full=0;
	
// 			break;
// 			case key_long://// 长按处理
			
// 			break;	
// 			default:
			
// 			break;
// 		}
// 	    key2_data.key_value=key_null;
// 	}
}


/**@brief get key value.
 * 
 * @param[in]  null.
 * @param[out] null.
 * 
 * @return  key_value_t  key_value.
 */
key_value_t key_get_value(void)
{
	return key_data.key_value;
}



