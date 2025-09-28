/**************************************************************************/ /**
																			  * @file     app_main.c
																			  * @version  V1.0.0
																			  * @author   0531
																			  * @date     2020-11-21 PM
																			  * @brief    该文件包含了...
																			  *
																			  * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
																			  *****************************************************************************/
// Include header file.
#include "cs_common.h"
#include "system_csu39fx10.h"
#include "mod_key.h"
// driver
#include "csu39fx10_syscfg.h"
#include "csu39fx10_exti.h"
#include "drv_gpio.h"
#include "drv_timer.h"
#include "drv_uart.h"
#include "drv_wdt.h"
#include "drv_iic.h"
#include "drv_adc.h"
#include "drv_flash.h"
// module
#include "mod_display.h"
#include "mod_key.h"
#include "mod_dcdc.h"
#include "mod_input_output.h"
#include "mod_adc_convert.h"
#include "mod_coulomb.h"
#include "mod_queue.h"
#include "mod_modbus.h"

// protocol
#include "lib_prot_pd.h"
#include "lib_prot_typec.h"
#include "lib_prot_typec.h"
#include "lib_multi_protocol.h"
// app
#include "app_init.h"
#include "app_main.h"
#include "app_typec_deal.h"
#include "app_state_machine.h"
#include "app_interrupt.h"

#include "app_debug.h"

#include "mod_display.h"

extern volatile uint8_t bank2 ACMP1CR4;
extern volatile uint8_t bank2 ACMP0CR4; // ACMP0CR4
volatile uint8_t bank4 _REGx0 @0x78 + 0x00;
volatile uint8_t bank4 _REGx1 @0x78 + 0x01;
volatile uint8_t bank4 _REGx2 @0x78 + 0x02;
volatile uint8_t bank4 _REGx3 @0x78 + 0x03;
volatile uint8_t bank4 _REGx4 @0x78 + 0x04;

volatile unsigned char bank0 APToBoot0 @0xfe;
volatile unsigned char bank0 APToBoot1 @0xff;
volatile sbit bank0 flag_INT @0x80 * 8 + 0;

#define TYPEC_BA1 0x40
volatile unsigned char bank4 CCIE1 @TYPEC_BA1 + 0x00;
volatile unsigned char bank4 CCIF1 @TYPEC_BA1 + 0x01;
volatile unsigned char bank4 CCACTL1 @TYPEC_BA1 + 0x02;
volatile unsigned char bank4 CCBCTL1 @TYPEC_BA1 + 0x03;
volatile unsigned char bank4 AUTODET1 @TYPEC_BA1 + 0x04;
volatile unsigned char bank4 CCARLT1 @TYPEC_BA1 + 0x05;
volatile unsigned char bank4 CCBRLT1 @TYPEC_BA1 + 0x06;
volatile unsigned char bank4 SCNPRD1 @TYPEC_BA1 + 0x07;
volatile unsigned char bank4 CCDRP1 @TYPEC_BA1 + 0x08;

bank0 uint16_t flash_address = 0x0010;
bank0 uint8_t flash_data[2];

uint8_t sleepcnt;
uint8_t VoltFlag;
uint16_t I_ChargePWM_PWM_Be;
uint16_t I_ChargePWM_PWM;
uint8_t R_ChargeCur_DataBuff;
uint8_t R_ChargeCur_PDData;
uint8_t R_ChargeCur_Data;
uint8_t LedData_OK;
uint8_t BatCap_Value;
uint8_t BatCap_Value_Be;
uint8_t Charge_Start;
uint8_t Power_Value_Update;
uint8_t PD_curr_Pro_cnt;
uint8_t USBA_curr_Pro_cnt;
uint8_t USBA2_curr_Pro_cnt;
uint8_t UTX_8_data1;
// uint8_t  UTX_8_data2;
uint16_t UTX_8_data2;
uint16_t UTX_16_data1;
uint16_t UTX_16_data2;
uint16_t VBAT_7201_Vaule;
uint16_t VBUS_out;
uint16_t VBUS_out_Be;
uint8_t discharge_displed;
uint8_t Fast_Show_cnt;
uint8_t Sleep_up_flage;
uint8_t charge_and_discharge_do; ///// 充电和放电一起标志位////
uint8_t Time_1ms_cnt;
uint8_t Time_10ms_cnt;
uint8_t Time_100ms_cnt;
uint8_t Time_1000ms_cnt;
uint8_t Time_1500ms_cnt;
uint8_t WR_5V9V_out_in; /////多口输入输出标志位////

BANK_Add uint8_t SW7203_Data_Cnt;

BANK1_Add unsigned int TX_time_change; /// 数据表更
BANK1_Add unsigned char TX_START;	   //// 开始发送数据
BANK1_Add unsigned int TX_data_temp;   /// 发送数据3
BANK1_Add unsigned char TX_bit_H_time_cnt;
BANK1_Add unsigned char TX_bit_L_time_cnt;
BANK1_Add unsigned int TX_data1; /// 发送数据1
BANK1_Add unsigned int TX_data2; /// 发送数据2
BANK1_Add unsigned char TX_date_done;
BANK1_Add unsigned char TX_bit_vaule; /// 发送的位数值
BANK1_Add unsigned char TX_bit_time_cnt;
BANK1_Add unsigned char TX_bit_cnt; /// 发送数据位  32位就是完成
BANK1_Add unsigned int TX_all_data_statu;
//////////////////////
BANK_Add unsigned char TCB_EN_ON;	//// 开B口充电开关///// 7
BANK_Add unsigned char TCA_EN_ON;	//// 开TCA口充电开关/////6
BANK_Add unsigned char WHITE_ON;	//// 开白灯/////           5
BANK_Add unsigned char RED_ON;		//// 开红灯/////   改成TOUCH-VDD
BANK_Add unsigned char USBA_EN_ON;	//// 开USBA口放电电开关///// 3
BANK_Add unsigned char USBA2_EN_ON; //// 开USBA口放电电开关/////2
BANK_Add unsigned char CHARING_ON;	////开充电脚位充电开关/////1
BANK_Add unsigned char OTG_ON;		//// 开OTG开关/////            0
BANK_Add unsigned char SOS_LEVEL;	////0-常亮 1--频闪 2-SOS
BANK_Add unsigned char CAR_LEVEL;	/////汽车点火 形势 0-无连接  1-连接 2--Ready star 3-Successful jump
BANK_Add unsigned char LED_STATU;	// /// 0-放电或待机 1-充电
BANK_Add unsigned char LED_LEVEL;	/// 电池电压电量等级 0--LED不显示 1 0-5%以下 2-5-25%以下 3-25-50% 以下4-50-75% 以下 5-75-100% 6-充满 7-报警
////////////
BANK_Add uint8_t count_tx_car;		////
BANK_Add uint8_t count_8;			////
BANK_Add uint8_t TX_Car_number;		////
BANK_Add uint8_t f_err_ot;			///
BANK_Add uint8_t f_ph_del;			////
BANK_Add uint8_t f_car_his;			/////
BANK_Add uint16_t count_car_remove; ////
BANK_Add uint8_t count_car_jump;	////
BANK_Add uint8_t data_car_jump;		////
BANK_Add uint8_t Temp_car_ST;		////
BANK_Add uint8_t count_jump;		/////
BANK_Add uint8_t f_car_jump;		//////
BANK_Add uint8_t car_ST;			/////
BANK_Add uint8_t count_clr_time;	////
BANK_Add uint8_t time_noload;		////
BANK_Add uint8_t count_0s5;			/////
BANK_Add uint8_t f_ph_del_time;		////
BANK_Add uint8_t f_jump_start;		////
BANK_Add uint8_t count_2ms;			///
BANK_Add uint8_t count_65ms;		///
BANK_Add uint8_t Charge_cnt_do;		///
BANK_Add uint8_t Charge_get_cnt;	///
BANK_Add uint8_t sink_Vol;
BANK_Add uint8_t sink_Vol1;
// BANK_Add uint8_t  V_NO_Cha_flage;
// BANK_Add uint8_t  V_NO_Charge;
BANK_Add uint8_t bat_low_pwm_do;
BANK_Add uint8_t bat_low_pwm_Cnt;
BANK_Add uint8_t bat_full_pwm_Cnt;
BANK_Add uint8_t bat_full_pwm_do;
BANK_Add uint8_t bat_full_8hour_Cnt;
BANK_Add uint16_t bat_full_1hour_Cnt;
BANK_Add uint8_t bat_full_do_to_charge;
BANK_Add uint8_t Sleep_up_shor_do;
BANK_Add uint8_t Sleep_up_close_Car_ignition;
BANK_Add uint8_t charge_to_sleep_close_Car_ignition;
/////////////
BANK_Add uint8_t USBA_sleep_up;
// BANK_Add uint16_t VBUS_V_Hight;
// BANK_Add uint16_t VBUS_V_Low;
BANK_Add uint8_t VBUS_V_Hight;
BANK_Add uint8_t VBUS_V_Low;

BANK_Add uint16_t VBUS_OVP_CNT;
BANK_Add uint16_t VBUS_USBA_OVP_CNT;
BANK_Add uint8_t Into_IAP_Flage;
BANK_Add uint8_t USBA_VoltFlag;
BANK_Add iap_detect_t iap_detect;
BANK_Add uint8_t request_num_copy;
BANK_Add uint8_t Recharge_cnt;
BANK_Add uint8_t TYPE_CA_18W_Flage;
BANK_Add uint8_t TYPE_CA_18W_Flage_Cnt;
BANK_Add uint8_t Time_2_Flage_do;
BANK_Add uint8_t SYS_in_Sleep_F;
BANK_Add uint8_t Foece_Sleep_F;
BANK_Add uint8_t Foece_Sleep_Time_S;
BANK_Add uint16_t Foece_Sleep_Time_Min;
BANK_Add uint8_t Foece_Sleep_Time_Mon;
BANK_Add uint16_t Exit_Charge_Cnt;
BANK_Add uint8_t CC1_LEVEL_NOW;
BANK_Add uint8_t CC1_LEVEL_BE;
BANK_Add uint8_t CC2_LEVEL_NOW;
BANK_Add uint8_t CC2_LEVEL_BE;
BANK_Add uint8_t CC_Check_Cnt;
BANK_Add uint8_t CC1_Check1_Cnt;
BANK_Add uint8_t CC1_Check2_Cnt;
BANK_Add uint8_t CC2_Check1_Cnt;
BANK_Add uint8_t CC2_Check2_Cnt;
BANK_Add uint16_t TypeC_Slide_CC1_data;
BANK_Add uint16_t TypeC_Slide_CC2_data;
BANK_Add uint16_t TypeC_MicroB_ADC_data;
BANK_Add uint16_t TypeC_VNOW_out_value;
BANK_Add uint16_t TypeC_VBE_out_value;
BANK_Add uint8_t Out_Protest_Flage; //// 输出保护位有输出 就禁止输出要按键消除////
// BANK_Add uint8_t SYS_100ms_date;
// BANK_Add uint8_t SYS_1s_date;
BANK_Add uint8_t Charge_OCP_Flage; //// 充电过流保护////
BANK_Add uint8_t Charge_OCP_cnt;
// BANK_Add uint8_t Charge_Close_En_Flage;
BANK_Add uint8_t Charge_Close_En_cnt;
// BANK_Add uint8_t SYS_1s_date;
BANK_Add uint8_t Charge_BEN_cnt;
BANK_Add uint8_t Vbat_8_date;
BANK_Add uint8_t VBUS_8_date;
BANK_Add uint8_t VBUS_USBA_8_date;
BANK_Add uint8_t CIbat_8_date;
bank2 uint8_t CIbus_8_date;
bank2 uint16_t CIbus_16_date;

BANK_Add uint8_t AIbat_8_date; //// A 口电流处理 转换电池电流处理///
BANK_Add uint8_t LIbat_8_date; //// 灯具电流处理/////
BANK_Add uint16_t Type_C_Ibat_16_date;
BANK_Add uint8_t Car_Cur_data; //// A 口电流处理 转换电池电流处理///

BANK_Add uint8_t f_RX_statu;	//// 当前状态///
BANK_Add uint8_t f_B_RX_statu;	/// 前一次状态
BANK_Add uint8_t f_B2_RX_statu; /// 前前状态

BANK_Add uint8_t TX_Car_number;	  ////
BANK_Add uint8_t f_Rx_do_star;	  /// 收到下降沿开始接收数据处理////
BANK_Add uint8_t Date_bit_cnt;	  /// 收到数据第几位///
BANK_Add uint8_t Time_date_L_cnt; /// 接收数据延时计数///
BANK_Add uint8_t Vule_Rx_date;	  /// 接收数据位移存储///
// BANK_Add uint8_t date1_Cnt;		  ///
// BANK_Add uint8_t date2_Cnt;		  ///
// BANK_Add uint8_t Rx_8date1;		  /// 接收数据1
// BANK_Add uint8_t Rx_8date2;		  /// 接收数据2
// BANK_Add uint8_t Rx_8date3;		  /// 接收数据3
BANK_Add uint8_t f_RX_date_done;  /// 接收数据完成标志
BANK_Add uint8_t Rx_huo;

BANK_Add uint8_t USBA_EN_BK;
BANK_Add uint8_t Flash_bat_Vol_Start_check;

// BANK_Add uint8_t Bat_Car_Protect_Flage;
BANK_Add uint8_t Bat_Car_Protect_Cnt;

BANK_Add uint8_t test_data8_1;

BANK_Add uint8_t UP_data_2402_Flage;
BANK_Add uint8_t BAT_Pro_Charge;

BANK_Add uint8_t Sleep_Down_Close_Power;

BANK_Add uint8_t Boot_NG_Flage;

BANK_Add uint16_t Bat_Low_5V_CNt;
BANK_Add uint8_t Bat_Low_5V_NG_Flage;

BANK_Add uint16_t UTX_16_data3;

Add_data_bank uint8_t LED_test_mode_Cnt;
Add_data_bank uint8_t LED_test_mode_Cnt2;

Add_data_bank uint8_t uart_t_count;
Add_data_bank uint8_t Languagee_C_Flag;

Add_data_bank uint8_t LongKeyFlagtocallword;
Add_data_bank uint8_t marked_word_showtime;
Add_data_bank uint8_t marked_word_cnt;

Add_data_bank uint8_t F_gotodec_levl;
Add_data_bank uint8_t Gotodec_levl_cnt;

Add_data_bank uint8_t DubbleKeyFlag; // DubbleKey2Flag
Add_data_bank uint8_t DubbleKey2Flag;
// Add_data_bank  statusKeyFlag;

Add_data_bank uint8_t open_lcd_light;
Add_data_bank uint8_t Temp_Language;

Add_data_bank uint8_t TFT_maid_mode;
Add_data_bank uint8_t TFT_minor_mode;

Add_data_bank uint8_t Star_Cartoon;
Add_data_bank uint8_t Error_icon_Cnt;
Add_data_bank uint8_t Error_icon_Mode;

Add_data_bank uint8_t USBA_in_Flage;
Add_data_bank uint8_t USBA_in_Cnt;

Add_data_bank uint8_t BAT_VAULE_TEST;
Add_data_bank uint8_t BAT_VAULE_TEST_Cnt;

Add_data_bank uint8_t TYPE_C_Waittime_Cnt;

Add_data_bank uint8_t test_I_data;

Add_data_bank uint16_t close_lcd_light_cnt;

Add_data_bank uint8_t Change_lauge_Cnt;

Add_data_bank uint8_t Change_lauge_Flage;
Add_data_bank uint8_t Change_lauge_Time_Cnt;

uint8_t Flag=0;

//---------------------------------------------
// uint8_t uart_rx_data[10];
// uint8_t uart_rx_data_cnt;
// uart_rx_data_flag;
//---------------------------------------------
sys_flag_t sys_flag;
sys_timer_t sys_timer;
void delay_ms(uint32_t _ms)
{
	sys_timer.time_ruler = 0;
	do
	{
		//	    wdt_feeddog();
		//		wwdt_feeddog();
		asm("CLRWDT");
		asm("nop");
	} while (sys_timer.time_ruler <= _ms);
}

static void branch_100ms(void);
static void branch_1s(void);
static void qc_break(void);
static void output_voltage_adjust(void);
static void protect_ocp_proc(void);
static void sleep_enter_sleep(void);
static void Vbus_level_deal(void);
static void BSP_PDCur_Deal(uint16_t PDCur);
static void Charge_current_deal(void);
static void Discharge_Pro_curr(void);
static void led_deal(void);
static void Data_Tx_inti(void);

#if IAP_deal_EN

asm("org 0810h");

#if Ap_Include_Bootload
////AP版本号---烧录器烧录版本
asm("dw  0001h");
asm("dw  5A3Ch"); // 升级方式标志位，使用烧录器烧录时此位需设为5A3Ch，用于IAP升级时需设为0000h
#else
/////AP版本号---AP升级版本
asm("dw  0002h");
asm("dw  0000h"); // 升级方式标志位，使用烧录器烧录时此位需设为5A3Ch，用于IAP升级时需设为0000h
#endif

asm("dw  0000h"); // 保留区域
asm("dw  0000h"); // 保留区域
#endif

void main(void)
{
	flag_INT = 1; /////IAP 下载脚位
	SYS_in_Sleep_F = 0;
	Port_NTC_NG_LOW_POWER_Cnt = 0;
	Port_NTC_NG_LOW_POWER_Flage = 0;
	app_peripheral_init(); //// 软件MCU初始化/////  ok
	Start_data_init();
	Bootcheck_Deal();

	open_to_12hour_Cnt = 0;

	key_down_5S_Cnt = 0;
	Bat_Low_5V_NG_Flage = 0;
	Bat_Low_5V_CNt = 0;
	key_down_10S_Flage = 0;

	if ((adc_convert.type_ntc.adc_code_rt < C_TempH_DisCharge_Off_Pro) || (adc_convert.type_ntc.adc_code_rt >= C_TempL_DisCharge_Off_Pro))
	{
		Temp.DischargeTemp_OK = 0;
		LCD_display_3S_Cnt = 1;
	}
	adc_convert.type_ntc.adc_code_sl = adc_convert.type_ntc.adc_code_rt;
	TFT_maid_mode = 0;
	TFT_minor_mode = 0;
	Star_Cartoon = 1;

	USBA_in_Flage = 0;
	USBA_in_Cnt = 0;

	BAT_VAULE_TEST = 0;
	BAT_VAULE_TEST_Cnt = 0;
	TYPE_C_Waittime_Cnt = 0;
	test_I_data = 5;

	// 初始化寄存器和缓冲区
	holdingRegisters[0] = 0;
	holdingRegisters[1] = 0;
	holdingRegisters[2] = 0;
	holdingRegisters[3] = 0;
	holdingRegisters[4] = 0;
	holdingRegisters[5] = 0;
	holdingRegisters[6] = 0;
	holdingRegisters[7] = 0;
	init_buffers();
	buf = NULL;
	p_buffer = NULL;
	uint8_t j;
	// uart_putchar(0xAA);

	while (1)
	{
		//  	#endif
#if (!CFG_SYS_WDT_DISABLE)
		/** feed the watchdog**/
		//	   wdt_feeddog();
		//	   wwdt_feeddog();
#endif

#if (!CFG_PD_DISABLE)
		if (plug_state_context.protocol_flag.b_pd_en)
		{
			pd_interrupt_polling();
		}
#endif
		/** multi protocol scan**/
		multi_protocol_scan_process();
		/** vbus switch io port scan**/
		mod_io_vbus_switch(); /////  --ok

		/** adc current acquisition scan**/
		mod_adc_convert(); //// ADC 采样转换通道///---  ok

		if (sys_flag.timer_1ms)
		{
			// uart_putchar(0xCC);
			// uart_putchar(Flag);
			// uart_putchar(0xDD);

			sys_flag.timer_1ms = false;
			wdt_feeddog();
			//	        wwdt_feeddog();

			////////////////////////modbus处理/////////////////////
			modus_event_proc();
			//			lastRxTime--;/// 1ms 计数
			check_frame_timeout();

			for (j = 0; j < 2; j++)
			{
				if (rxBuffers[j].ready)
				{
					// 处理缓冲区
					//					uart_putchar(0x01);
					p_buffer = &rxBuffers[j];
					process_modbus_frame();
				}
			}
			////////////////////////单独计数处理/////////////////////
			Time_10ms_cnt++;
			if (Time_10ms_cnt >= 10)
			{
				Time_10ms_cnt = 0;
				//			  key_scan();///---POWER
				//			  key_proc();///--ok
				/////////////////////
				//			  KEY2_inti;
				//			  key2_scan();///LED---
				//			  key2_proc();///--ok
				//			  Lighting_to_SOS_Dispose();///--ok
			}
			Time_100ms_cnt++;
			if (Time_100ms_cnt >= 100) ///// 100ms/////
			{
				Time_100ms_cnt = 0;
				//		      Car_statu_deal();
				//              Data_Tx_inti();//// 100ms 发一次数据/////
				Time_1500ms_cnt++;
				if (Time_1500ms_cnt >= 15) ////  1.5S 发送一次连接处理/////
				{
					Time_1500ms_cnt = 0;
					if ((car_ST == 0) && (Temp.DischargeTemp_OK)) //&&(!Bat_Car_Protect_Flage))
																  //			   count_tx_car=16;
						count_tx_car = 61;						  //// 新的夹子通讯协议//////
				}
				////////////////////////串口数据发送处理
				// 			#if __IF_DEBUG__
				// //			 if(!BAT_CO_OPEN_CNT)
				// //			{
				//                	#if UR_TX_LUNXUN
				// 	               test_dcdc_print();
				// 	            #endif
				// //			}

				//             #else
				//               	PINC_SIM_TX=0;
				// 	        #endif

#if (__IF_DEBUG__)

				Sub_sim_tx(0xCC);
				// if(f_RX_date_done)
				// {
				// 	f_RX_date_done = 0;
				// 	Sub_sim_tx(Rx_8date1);
				// 	Sub_sim_tx(Rx_8date2);
				// 	Sub_sim_tx(Rx_8date3);
				// }
#endif

#if K_Temp_Protect
				BSP_Temp_Control(); ///// NTC 温度检测/////
#endif

#if Bat_low_Pro_en
				Bat_low_deal(); //// 电池低电压检测//////
#endif
				Time_1000ms_cnt++;
				if (Time_1000ms_cnt >= 10)
				{
					//			   uart_putchar(0x22);
					Time_1000ms_cnt = 0;
					BSP_DisCharge_SmallCur(); //// 小电流检测////-----1S 检测一次///

					if (TYPE_C_Waittime_Cnt)
					{
						TYPE_C_Waittime_Cnt++;
						if (TYPE_C_Waittime_Cnt >= 3)
						{
							TYPE_C_Waittime_Cnt = 0;
						}
					}
				}
			}
			//////////////////
			//		  CA_CB_Port_Statu(adc_convert.type_loadin.adc_code_sl);/// TCA -TCB 端口输入输出值
			CA_CB_Port_Statu();
			/////////////////////////
			/** typec port scan**/
			typec_polling(&h_typeca, pd_get_limit_condition());
			//		  typec_polling(&h_typecb,pd_get_limit_condition());
			typec_time(&h_typeca);
			//		  typec_time(&h_typecb);
			/** pd message sending**/
#if !CFG_PD_DISABLE
			if (plug_state_context.protocol_flag.b_pd_en)
			{
				pd_send();
				//				pd_time();
			}
			pd_time();
#endif
			///////////** output voltage adjustment**////////////////////////
			output_voltage_adjust(); /////  输出电压电流调整/////---ok

#if Dis_Cur_Pro_en
			Discharge_Pro_curr(); /// 端口过流保护/////
#endif
			///// 电池电压转换5V 3.3V ///
			switch (sys_timer.cnt_10ms++)
			{
			case 0:
				plug_state_machine_proc(); ///// 系统动作更新执行
										   //					Miro_in_deal();////取消B口充电///
				Type_cb_charge_in = 0;
				MiroB_charge_in = Type_cb_charge_in;
				break;
			case 1:
				if ((inoutput_data.vbus_switch.sw.type_a1) && (R_SysMode_OK != COULOMB_CHARGE)) //// 100ms处理一次
				{
					Mod_Dis_USBA_EN(1); //// 开关A口处理
					// multi_protocol.dcp.mos_open_flag|= 0x04;//USBA
				}
				else
				{
					Mod_Dis_USBA_EN(0);
					// multi_protocol.dcp.mos_open_flag&= 0xfb;
				}
				qc_break(); ////	QC协议复位
				break;
			case 2:
				BSP_I2C_7203_Data();											   //// 电池电压电流参数///
																				   //                	multi_protocol.input.vbus_vol= adc_convert.type_vbus.adc_code_sl;/// VBUS 电压采样 ok
																				   //                	if(multi_protocol.input.vbus_vol>=1024)
				if (hex_greater_than_compare(multi_protocol.input.vbus_vol, 1024)) //
				{
					VBUS_8_date = 255;
				}
				else
					VBUS_8_date = multi_protocol.input.vbus_vol >> 2; /// 除以4///

				//					if(adc_convert.type_usba_vbus.adc_code_sl>=1024)
				if (hex_greater_than_compare(adc_convert.type_usba_vbus.adc_code_sl, 1024)) //
				{
					VBUS_USBA_8_date = 255;
				}
				else
					VBUS_USBA_8_date = adc_convert.type_usba_vbus.adc_code_sl >> 2; /// 除以4///

				Vbus_level_deal(); /// VBUS 电压等级判定/////--不变 ----ok
				break;
			case 3:
				///////////////////////////////////////
				Frist_sink_deal();
				multi_protocol.input.ibus_cur = adc_convert.typec_a.adc_code_sl * 10; /// 360--3600////IBUS 电流采样 ok

				pdsignal_threshold_switch(); // pd signal threshold

				break;
				//				case 4:
				//
				////				      key_scan();///--ok
				////					  key_proc();///--ok
				////					  Lighting_to_SOS_Dispose();///--ok
				//
				//					break;
				//				case 5:
				//					break;
				//				case 6:
				//					break;
				//				case 7:
				////                    #if !SDWDO_EN
				//////					mod_inoutput_plug_check_proc();//// 插入USBA 口检测 和小电流移除处理///待处理
				////                    #endif
				////                  mod_inoutput_plug_check_proc_USBA2();//// 开无线充功能
				//					break;
			case 8:
				//					plug_state_charge_lag_open_vbus_proc();/// 充电打开MOS管

				break;
			case 9:
				sys_timer.cnt_10ms = 0;
				branch_100ms();
				break;
			default:
				if (sys_timer.cnt_10ms > 9)
					sys_timer.cnt_10ms = 0;
				break;
			}
		}
	}
}

static void branch_100ms(void)
{
	coulomb_charge_status_t charge_status;
	uint32_t Mach_Vbat;
	switch (sys_timer.cnt_100ms++)
	{
	case 0:

		if (Change_lauge_Cnt) ////Change_lauge_Cnt
		{
			Change_lauge_Time_Cnt++;
			if (Change_lauge_Time_Cnt >= 50)
			{
				Change_lauge_Time_Cnt = 0;
				Change_lauge_Cnt = 0;

				iic_transmit_24C02_byte(RCR_Lange_cnt_addr, Change_lauge_Flage);
			}
		}

		//        BSP_I2C_7203_Data();//// 电池电压电流参数///
		if (BAT_CO_OPEN_CNT) ///// 上电第一次处理 电压低处理///
		{
			//		   BAT_CO_ON;
			//		   if(VBAT_7201_Vaule>=800)////电池电压打于5V 则处理
			if (hex_greater_than_compare(VBAT_7201_Vaule, 800)) ////电池电压打于5V 则处理
																//           if(VBAT_7201_Vaule>=660)////电池电压打大于5V 则处理
			{
				BAT_CO_OPEN_CNT++;
			}
			else
			{
				BAT_CO_OPEN_CNT = 1;
				Bat_Low_5V_CNt++;
			}
			//		    if(hex_greater_than_compare(Bat_Low_5V_CNt, 1200))///// 强制充电 2 分钟计时到///
			if (hex_greater_than_compare(Bat_Low_5V_CNt, 1200))
			{
				Bat_Low_5V_CNt = 0;
				BAT_CO_OPEN_CNT = 0;
				Bat_Low_5V_NG_Flage = 1;
			}
			if (BAT_CO_OPEN_CNT >= 20) /// 2S 钟处理//
			{
				BAT_CO_OPEN_CNT = 0;
				//		     BAT_CO_OFF;
			}
		}
		else
		{
			//          #if !__IF_DEBUG__
			BAT_CO_OFF;
			//          #endif
			Bat_Low_5V_CNt = 0;
		}
		break;
	case 1:
		//		    #if K_Temp_Protect
		//		        BSP_Temp_Control();///// NTC 温度检测/////
		//		    #endif
		Poweron_24C02_Self_inspec(); //// 24C02 自检/////
		break;
	case 2:
		if (F_A1_ON) //// 100ms/
		{
			if (R_SysMode_OK != COULOMB_CHARGE)
				F_A1_ON++;
			else
				F_A1_ON = 0;

			//			    if(F_A1_ON>=5)///0.5S
			if (F_A1_ON >= 15) /// 0.5S
			{
				F_A1_ON = 0;
				//					 if((adc_convert.type_ntc.adc_code_rt < C_TempH_DisCharge_Off_Pro)||(adc_convert.type_ntc.adc_code_rt >= C_TempL_DisCharge_Off_Pro))
				if ((hex_less_than_compare(adc_convert.type_ntc.adc_code_rt, C_TempH_DisCharge_Off_Pro)) || (hex_greater_than_compare(adc_convert.type_ntc.adc_code_rt, C_TempL_DisCharge_Off_Pro)))
				{
					if (Temp.DischargeTemp_OK)
					{
						Temp.DischargeTemp_OK = 0;
						LCD_display_3S_Cnt = 1;
					}
				}
				//					 else
				//					{
				//					  if((adc_convert.type_ntc.adc_code_sl >= C_TempH_DisCharge_On_Pro)&&(adc_convert.type_ntc.adc_code_sl < C_TempL_DisCharge_On_Pro))
				//					   Temp.DischargeTemp_OK=1;
				//					}
				if ((Bat_low_Cnt < 30) && (Temp.DischargeTemp_OK) && (R_SysMode_OK != COULOMB_CHARGE) && (!f_car_jump)) //// 不是低电压不是温度保护开A口
				{
					A1_closeTIME = 0;
					Mod_Dis_USBA_EN(1);
					inoutput_data.vbus_switch.sw.type_a1 = 1;
					Sleep_up_close_Car_ignition = 0;
					coulomb_data.output.b_batt_full = 0;
					bat_full_do_to_charge = 0;
				}
				if ((Bat_low_Cnt > 30) || (!Temp.DischargeTemp_OK))
				{
					if (R_SysMode_OK != COULOMB_CHARGE)
					{
						discharge_displed = displaytime - 2;
						Discharge_MinCur = 1;
					}
				}
			}
		}

		//		      Car_statu_deal();
		//			  asm("nop");
		//			  Time_1500ms_cnt++;
		//			  if(Time_1500ms_cnt>=15)
		//			  {
		//			   Time_1500ms_cnt=0;
		//			   if(car_ST==0)
		//			   count_tx_car=16;
		//			  }

		break;
	case 3:
		//		     if(Type_ca_charge_in||MiroB_charge_in)/////---100ms---///////
		if (Type_ca_charge_in) /////---100ms---///////
		{
			if (!Bat_low_sleep_flage)
			{
				if (Bat_low_Cnt >= 30)
				{
					if (Vbat_8_date >= C_Vbat_Low_re_Vol)
					{
						Bat_low_RE_Cnt++;
					}
					else
						Bat_low_RE_Cnt = 0;

					if (Bat_low_RE_Cnt >= 200) //// 持续20S 一直在13V以上
					{
						Bat_low_RE_Cnt = 0;
						Bat_low_Cnt = 0;
						BatCap_Value = 1;
						ADD_IBAT_cnt = 0;
					}
				}
				else
				{
					Bat_low_RE_Cnt = 0;
				}
				//					  Bat_low_Cnt=0;
			}

			WHITE_ON = 0;
			RED_ON = 0;
			SOS_LEVEL = 0;
			inoutput_data.vbus_switch.sw.type_a1 = false;
			F_A1_ON = 0;

			if (!Charge_Start)
			{
				Charge_bat_Full_check(); /////充饱信号处理
				Charge_current_deal();	 //// 充电电流处理///
				Vin_vol_charge_deal();	 ///// 充电电压 锂电保护处理//
				if (Charge_OCP_Flage)
				{
					//					  Sleep_SYS_IN;//// 不需要
					inoutput_data.vbus_switch.sw.type_ca = false;
					inoutput_data.vbus_switch.sw.type_b1 = false;
				}

				//					if((Frist_start_sink!=Frist_Bat_normal_do)&&(Frist_start_sink!=Frist_Bat_Protest_do))

				if ((Frist_start_sink == Frist_normal_do) && (!Bat_low_sleep_flage))
				{
					discharge_displed = 1;												   ///// 充电常亮显示///
					if (hex_greater_than_compare(close_lcd_light_cnt, (closelcdtime - 1))) /////充饱灭屏处理////
						discharge_displed = displaytime;
				}

				UTX_8_data1 = 13; ///// 充电状态就一直显示电量灯///
			}
			else
			{
				Charge_Start++;
				if (Charge_Start >= 2)
				{
					Charge_Start = 0;
				}
			}
		}

		if (plug_state_context.state.bit.b_bcxc) ///  充电状态
		{
			R_SysMode_OK = COULOMB_CHARGE;
		}
		else if (plug_state_context.state.bit.b_acxd) ////  放电状态
		{
			R_SysMode_OK = COULOMB_DISCHARGE;
		}
		else
		{
			R_SysMode_OK = COULOMB_NULL;
		}
		if (R_SysMode_BE != R_SysMode_OK)
		{
			R_SysMode_BE = R_SysMode_OK;
			//////			   if((!WHITE_ON)&&(!RED_ON)) /// 没有灯亮着直接清零
			//////			   {
			////////			     ADD_IBAT_cnt=0;
			//////			   }
			//////			   if(R_SysMode_OK==COULOMB_DISCHARGE)
			//////			   {
			//////				  discharge_displed=1; UTX_8_data1=5;/// 判断状态时放电状态 显示电量灯////
			//////			   }
			UTX_8_data2 = 0x0000;
			UTX_16_data1 = 0x0000; /// 电流累计值

#if Bat_Cnt
			UTX_16_data3 = 0x0000; /// 电流累计值
#endif

			LED_test_mode_Cnt2 = 0;
			LED_test_mode_Cnt = 0;
		}
		break;
	case 4:

		break;
	case 5:
		///////////////////灯显示处理///////////////////
		mod_display_batt_level(BatCap_Value); /// 灯显示等等级 和闪烁 /////灯显示处理/////
		led_deal();							  //// LED 其他处理  报警处理///
		break;
	case 6:
		//            Bat_low_deal();//// 电池低电压检测//////

		/////电池电压12V 以下不发送夹子命令 恢复12.2重新发送////
		//			if(!Bat_Car_Protect_Flage)
		//		   {
		//			  if(Vbat_8_date<=C_VbatLow_Close_Car)
		//			  {
		//			    Bat_Car_Protect_Cnt++;
		//			    if(Bat_Car_Protect_Cnt>=8)
		//			    {
		//			      Bat_Car_Protect_Cnt=0;
		//			      Bat_Car_Protect_Flage=1;
		//			    }
		//			  }
		//			  else
		//			  {
		//			   Bat_Car_Protect_Cnt=0;
		//			  }
		//		   }
		//		   else
		//		   {
		//		       if(Vbat_8_date>=C_VbatLow_Re_Car)
		//			  {
		//			      Bat_Car_Protect_Cnt++;
		//			    if(Bat_Car_Protect_Cnt>=8)
		//			    {
		//			      Bat_Car_Protect_Cnt=0;
		//			      Bat_Car_Protect_Flage=0;
		//			    }
		//			  }
		//			  else
		//			  {
		//			    Bat_Car_Protect_Cnt=0;
		//			  }
		//
		//		   }
		break;
	case 8:
		//// 检测C口放电电流处理////
		if (TYPEC_sleep_time_cnt) ///// 有C口轻载处理////
		{
			//				if(adc_convert.typec_a.adc_code_sl>Ibus_SmallCurL)
			if (hex_greater_than_compare(adc_convert.typec_a.adc_code_sl, Ibus_SmallCurL))
			{
				TYPEC_sleep_distime_cnt++;
				if (TYPEC_sleep_distime_cnt >= 50) /////  5S 钟清零
				{
					TYPEC_sleep_distime_cnt = 0;
					TYPEC_sleep_time_cnt = 0;
				}
			}
			else
				TYPEC_sleep_distime_cnt = 0;
		}
		///////////////////////////

#if EN_Sleep_EN																							  ///// 休眠处理////
		if (((plug_state_context.state.byte & 0x3F) == _N___N___N___N___N___N_) || (Bat_low_sleep_flage)) //// 端口为 空闲状态////
		{
			if ((Discharge_MinCur) && (!f_car_jump) && (R_SysMode_OK != COULOMB_CHARGE) && (!WHITE_ON) && (Key_up_flage)) /// 小电流标志位30S内没有负载接入 置起 或者温度保护或者
			{
				sleepcnt++;
			}
			else
			{
				if (Bat_low_sleep_flage) ///// C口带负载 强制休眠//////
				{
					sleepcnt++;
				}
				else
					sleepcnt = 0;
			}
		}
		else
		{
			sleepcnt = 0;
			SYS_in_Sleep_F = 0;
		}
		if (sleepcnt == 40)
			discharge_displed = displaytime; /// 休眠前1S 灭灯

		if (sleepcnt >= 50)
		{
			sleepcnt = 0;
			// #if __IF_DEBUG__
			//   Sub_sim_tx(0xA2);
			//   Sub_sim_tx(0xA2);
			// #endif
			sleep_enter_sleep(); ////单片机休眠状态/////---ok

			app_peripheral_init();
			Sleep_up_data_init();
			if ((adc_convert.type_ntc.adc_code_rt < C_TempH_DisCharge_Off_Pro) || (adc_convert.type_ntc.adc_code_rt >= C_TempL_DisCharge_Off_Pro))
			{
				Temp.DischargeTemp_OK = 0;
				LCD_display_3S_Cnt = 1;
			}
			adc_convert.type_ntc.adc_code_sl = adc_convert.type_ntc.adc_code_rt;
			SYS_in_Sleep_F = 0;

			// #if __IF_DEBUG__
			//   Sub_sim_tx(0xA3);
			//   Sub_sim_tx(0xA3);
			// #endif
			SOS_LEVEL = 0;
			WHITE_ON = 0;
			RED_ON = 0;
			//			WHITE_PIN_OFF;
			sleepcnt = 0;
			Bat_low_sleep_flage = 0;
			USBA_sleep_up = 1;
			open_to_12hour_Cnt = 0;
			USBA_in_Flage = 0;
			USBA_in_Cnt = 0;
			TYPE_C_Waittime_Cnt = 0;
			//            LCD_display_3S_Cnt=1;
		}
#endif

		/////// 开机3S显示处理////
		if (LCD_display_3S_Cnt)
		{
			discharge_displed = 1; //// 放电休眠灭灯////
			LCD_display_3S_Cnt++;

			if (LCD_display_3S_Cnt >= 31)
			{
				LCD_display_3S_Cnt = 0;

				if (!Temp.DischargeTemp_OK)
					discharge_displed = displaytime; //// 放电休眠灭灯////
			}
		}
		break;
	case 9:
		sys_timer.cnt_100ms = 0;
		branch_1s();
		break;
	default:
		if (sys_timer.cnt_100ms > 9)
			sys_timer.cnt_100ms = 0;
		break;
	}
}
static void branch_1s(void)
{
	switch (sys_timer.cnt_1s++)
	{
	case 0:
		// uart_putchar(multi_protocol.control.scp_protocol_out_en);
		// uart_putchar(multi_protocol.output.B_scp_scan_ok);

		// uart_putchar(multi_protocol.input.vbus_vol >> 8);//*25
		// uart_putchar(multi_protocol.input.vbus_vol & 0xFF);

		// uart_putchar(multi_protocol.input.ibus_cur >> 8);//
		// uart_putchar(multi_protocol.input.ibus_cur & 0xFF);

		// uart_putchar(multi_protocol.output.scp_out_vol >> 8);
		// uart_putchar(multi_protocol.output.scp_out_vol & 0xFF);
		/////////////////////////// close the lcd lighting////
		if (R_SysMode_OK == COULOMB_CHARGE)
		{
			if ((BatCap_Value == 100) || (coulomb_data.output.b_batt_full))
			{
				close_lcd_light_cnt++;
			}
			else
				close_lcd_light_cnt = 0;
		}
		else
			close_lcd_light_cnt = 0;
		/////////////////////////////////////
		if (Boot_NG_Flage) ///// 底层检测处理////
		{
			Bootcheck_Deal();
		}

		if ((Bat_Protest_cnt) && (!Charge_Bat_Start_Cnt)) /// 充电2S 停2分钟
		{
			Bat_Protest_cnt++;
			if (Bat_Protest_cnt >= (OVP_CHARGE_TIME + OVP_STOP_CHARGE_TIME))
			{
				Bat_Protest_cnt = 1;
			}
		}
		//			Frist_sink_deal();
		Bat_Vaule_deal(); //// 电池电压等级检测/---
						  //			BSP_DisCharge_SmallCur();//// 小电流检测////-----
		//// 5秒激活锂电池 在开A口输出检测
		if (BAT_Pro_Charge)
		{
			if (BAT_Pro_Charge++ >= 5)
			{
				BAT_Pro_Charge = 0;
			}
		}
		///////////////////电池充饱电压不正常初始化//////
		Charge_Bat_data_Err_Deal();
		//////电脑反冲 计时///// 4S 内不能有 输出
		if (CA_IN_Frist_No_Soure)
		{
			CA_IN_Frist_No_Soure++;
			if (CA_IN_Frist_No_Soure >= 5)
				CA_IN_Frist_No_Soure = 0;
		}
		break;
	case 1:
		// 			if(Temp.DischargeTemp_OK==0)
		// 			{
		// 				WHITE_ON=0;
		// 				inoutput_data.vbus_switch.sw.type_a1= false;
		// 				F_A1_ON=0;
		// 				SOS_LEVEL=0;
		// 				WHITE_ON=0;
		// 				RED_ON=0;
		// //				WHITE_PIN_OFF;
		// //				RED_PIN_OFF;
		// 				inoutput_data.vbus_switch.sw.type_ca= false;
		// 				inoutput_data.vbus_switch.vbus_type_ca_delay_cnt= 0;
		// 		    	if(!LCD_display_3S_Cnt)
		// 				{

		// 				 if(discharge_displed<displaytime-3)
		// 				 {
		// 				  discharge_displed=displaytime-2;/////NTC保护　一直灭灯////
		// 				 }
		// 				  Discharge_MinCur=1;////// 过流置起 小电流休眠标志位////
		// 				}
		// //	            sleepcnt=2;
		// 			}

		if (R_SysMode_OK != COULOMB_CHARGE)
		{
			//		       if((discharge_displed)&&(!f_car_jump))
			if (!f_car_jump)
			{
#if (!LED_DIS_light_long)
				discharge_displed++; /// 放电灯自加灭灯/////
#endif
			}
			else
			{
				discharge_displed = 1;
				UTX_8_data1 = 6; ///// 夹子接入 显示电量灯///
			}
		}
		break;
	case 2:
		if (UP_data_2402_Flage)
		{
			UP_data_2402_Flage++;
			if (2 == UP_data_2402_Flage)
			{
				iic_transmit_24C02_byte(BAT_Value_24C02_addr, BatCap_Value);
			}
			else if (3 == UP_data_2402_Flage)
			{
				iic_transmit_24C02_byte(BAT_Vol_24C02_addr, Vbat_8_date);
			}
			//		 else if(4==UP_data_2402_Flage)
			//		 {
			//		   iic_transmit_24C02_byte(BAT_Low_24C02_addr,Bat_low_Cnt);
			// 		 }
			else
				UP_data_2402_Flage = 0;
		}
		/////////////////////////////////////////////////////库伦计处理
		BSP_I2C_BATVaule_Deal(); /// 库伦计处理
		////////////////////////////////////////////////
		if (Flash_Bat_Value_data != BatCap_Value)
		{
			Flash_Bat_Value_data = BatCap_Value;
			//			  Flash_update_Deal();
			UP_data_2402_Flage = 1;
			//              if(SYS_in_Sleep_F)//// 强制正常休眠前记录数据////
			//			   iic_transmit_24C02_byte(RCR_24C02_addr,RCR_normal_Close_data);
			//		 	  else // 每次电量变化都记录数据////
			iic_transmit_24C02_byte(RCR_24C02_addr, RCR_Updata_Close_data);
		}

		break;
	case 8:

		//     #if EN_Sleep_EN
		//		 if(((plug_state_context.state.byte& 0x3F)==_N___N___N___N___N___N_)||(Bat_low_sleep_flage))//// 端口为 空闲状态////
		//		{
		//            if((Discharge_MinCur)&&(!f_car_jump)
		//            &&(R_SysMode_OK!=COULOMB_CHARGE)&&(!WHITE_ON)&&(!RED_ON)
		//            &&(!MirB_IN_Flage)&&(Key_up_flage))/// 小电流标志位30S内没有负载接入 置起 或者温度保护或者
		//		   {
		//		      sleepcnt++;
		//		   }
		//		   else
		//		   {
		//		   	   if(Bat_low_sleep_flage)///// C口带负载 强制休眠//////
		//			   {
		//				  sleepcnt++;
		////				  Sleep_SYS_IN;//// 休眠前关闭 NG ///
		//			   }
		//			   else
		//		          sleepcnt=0;
		//		   }
		//		}
		//		else
		//		{
		//		   sleepcnt=0;
		//		   SYS_in_Sleep_F=0;
		//		}
		//		if(sleepcnt==4)
		//		   discharge_displed=displaytime;///休眠前1S 灭灯
		//
		//		if(sleepcnt>=5)
		//		{
		//	        sleepcnt=0;
		//			#if __IF_DEBUG__
		//			  Sub_sim_tx(0xA2);
		//              Sub_sim_tx(0xA2);
		//			#endif
		//		    sleep_enter_sleep();////单片机休眠状态/////---ok
		//
		//		    h_typeca.input.b_power_on= RESET;
		//			h_typecb.input.b_power_on= RESET;
		//
		//
		//		    SOS_LEVEL=0;
		//			WHITE_ON=0;
		//			RED_ON=0;
		//			WHITE_PIN_OFF;
		////			RED_PIN_OFF;
		//            sleepcnt=0;
		//            Bat_low_sleep_flage=0;
		//            USBA_sleep_up=1;
		////          if(Foece_Sleep_F)
		////	        {
		////            Frist_start_sink=1;//// 开机置起 第一次上电充电处理////
		////	        }
		////            Foece_Sleep_F=0;
		//
		////          if(Foece_Sleep_Time_Mon)
		////	        {
		//////	          Power_Value_Update=1;
		////	        }
		////          Foece_Sleep_Time_S=0;
		////			Foece_Sleep_Time_Min=0;
		////			Foece_Sleep_Time_Mon=0;
		//            open_to_12hour_Cnt=0;
		//		}
		//   #endif
		break;
	case 9:
		sys_timer.cnt_1s = 0;
		break;
	default:
		if (sys_timer.cnt_1s > 9)
			sys_timer.cnt_1s = 0;
		break;
	}
}
static void qc_break(void)
{
	if (multi_protocol.output.B_qc_scan_reset)
	{
		/**
		 *	QC协议复位
		 *	标志置1时需将 fastchg_protocol_scan_en 关闭协议
		 *	并将端口VBUS关闭100ms以上再重新打开
		 */
		switch (plug_state_context.protocol_flag.b_multi_chl)
		{
		case CHL_MU_TCA:
			plug_state_context.event_flag.b_qc_break = true;
			mod_queue_send(PLUG_CAX_OUT);

			// 				  #if __IF_DEBUG__
			// 		Sub_sim_tx(0xAC);
			// 		Sub_sim_tx(0x01);
			// //		Sub_sim_tx(0xEE);
			// //		Sub_sim_tx(plug_state_context.state.byte& 0x3f);
			// 	  #endif

			break;
		case CHL_MU_TCB:
			//				plug_state_context.event_flag.b_qc_break= true;
			//				mod_queue_send(PLUG_CBX_OUT);
			break;
		case CHL_MU_TA1:
			/** 关VBUS_A1D 100ms**/
			//				multi_protocol.control.fastchg_protocol_scan_en= false;
			//				inoutput_data.vbus_switch.vbus_type_a1_delay_cnt= 100;
			break;
			//			case CHL_MU_TA2:
			//				/** 关VBUS_A1D 100ms**/
			//				multi_protocol.control.fastchg_protocol_scan_en= false;
			//				inoutput_data.vbus_switch.vbus_type_a1_delay_cnt= 100;
			//			break;

		default:
			break;
		}
	}
	else
	{
		plug_state_context.event_flag.b_qc_break = false;
	}
}

static void output_voltage_adjust(void)
{
	//	static uint8_t request_num_copy= 0;
	static uint16_t pps_request_volt_copy = 0;
	static uint8_t pps_request_cur_copy = 0;
	bool temp_refresh_flag = false;
	uint16_t temp_vbus_ref;
	uint16_t temp_ibus_lim;
	uint8_t RE_data_temp8;
	uint16_t V_cha_vule;

	if (h_pd.output.b_source_ps_rdy)
	{
		/** pd协议**/
		if (h_pd.output.request_num != REQUEST_NULL)
		{
			/** PD固定电压**/
			if ((h_pd.output.request_num != request_num_copy) ||
				(h_pd.output.pps_request_volt != pps_request_volt_copy) ||
				(h_pd.output.pps_request_cur != pps_request_cur_copy))
			{
				if (h_pd.output.request_num < request_num_copy) /// 高电压档位掉到低电压档位时泄放处理
				{
					inoutput_data.vbus_switch.sw.discharge = true;
					inoutput_data.vbus_switch.vbus_discharge_delay_cnt = 200;
				}
				request_num_copy = h_pd.output.request_num;
				pps_request_volt_copy = h_pd.output.pps_request_volt;
				pps_request_cur_copy = h_pd.output.pps_request_cur;
				temp_refresh_flag = true;
				switch (h_pd.output.request_num)
				{
				case CAP_1:
					temp_vbus_ref = Out_PD_5V;
					//                        temp_ibus_lim= Out_PD_A5000;
					break;
				case CAP_2:

					temp_vbus_ref = Out_PD_9V;
					//						temp_ibus_lim= Out_PD_A5000;
					break;
				case CAP_3:

					temp_vbus_ref = Out_PD_12V;
					//						temp_ibus_lim= Out_PD_A5000;
					break;
				case CAP_4:
					temp_vbus_ref = Out_PD_15V;
					//						temp_ibus_lim= Out_PD_A5000;
					break;
				case CAP_5:
					temp_vbus_ref = Out_PD_20V;
					//						temp_ibus_lim= Out_PD_A5000;
					break;
				default:
					temp_vbus_ref = Out_PD_5V;
					//                         temp_ibus_lim= Out_PD_A5000;
					break;
				}
				mod_dcdc_write_ibus_lim_set(Out_PD_A5000);
				iic_transmit_byte(0x26, 0xff); // vbat限流
				mod_dcdc_write_vbusref_e_set(temp_vbus_ref);
			}
		}
	}
	else
	{
		// uart_putchar(0x05);
		/** 多协议放电**/
		switch (multi_protocol.output.request_num)
		{
		/** 多协议固定电压**/
		case 0:
		case 1:
			// uart_putchar(0x06);
			temp_vbus_ref = Out_PD_5V;
			temp_ibus_lim = Out_PD_A3000 + 2; // 加高阈值，刚刚好的话到达就断开
			break;
		case 2:
			// uart_putchar(0x07);
			temp_vbus_ref = Out_PD_9V;
			temp_ibus_lim = Out_PD_A2000 + 2;
			break;
		case 3:
			// uart_putchar(0x08);
			temp_vbus_ref = Out_PD_12V;
			temp_ibus_lim = Out_PD_A1500 + 2;
			break;

		/** 多协议连续调压**/
		case 8:
			temp_ibus_lim = Out_PD_A3000 + 2;
			if (multi_protocol.output.B_qc30_scan_ok)
			{
				temp_vbus_ref = multi_protocol.output.qc30_out_vol * 10 - 300;
				// uart_putchar(0x08);
			}
			else if (multi_protocol.output.B_scp_scan_ok)
			{
				temp_ibus_lim = Out_PD_A5000 + 2;
				temp_vbus_ref = (multi_protocol.output.scp_out_vol - 3000) / 10;
				// uart_putchar(0x09);
			}
			else if (multi_protocol.output.B_vooc_scan_ok ||
					 multi_protocol.output.B_vooc40_scan_ok ||
					 multi_protocol.output.B_svooc_scan_ok)
			{
				// uart_putchar(0x0a);
				temp_vbus_ref = (multi_protocol.output.vooc_out_vol - 3000) / 10;
			}
			break;
		default:
			break;
		}

		mod_dcdc_write_ibus_lim_set(temp_ibus_lim);
		iic_transmit_byte(0x26, 0xff); // vbat限流
		mod_dcdc_write_vbusref_e_set(temp_vbus_ref);

		// uart_putchar(0x0A);

		// uart_putchar(multi_protocol.dir);
		// uart_putchar(multi_protocol.channel);
		// uart_putchar(multi_protocol.control.fastchg_protocol_scan_en);
		// uart_putchar(plug_state_context.protocol_flag.b_multi_chl);
		// uart_putchar(multi_protocol.control.qc_protocol_out_en);
		// uart_putchar(multi_protocol.output.B_qc20_scan_ok);
		// uart_putchar(multi_protocol.output.request_num);
		// uart_putchar(temp_ibus_lim);

		// uart_putchar(temp_vbus_ref>>3);
		// uart_putchar(temp_vbus_ref&0x07);
	}
}

static void protect_ocp_proc(void)
{
}
static void sleep_enter_sleep(void)
{
	SYS_in_Sleep_F = 1;
	Flash_update_Deal(); //// 休眠更新电量和电池电压处理/////
	delay_ms(100);

	//    #if __IF_DEBUG__
	//	  Sub_sim_tx(0xDD);
	//	  Sub_sim_tx(0xDD);
	//	  Sub_sim_tx(0xDD);
	//	  #endif

	Foece_Sleep_F = 0;
	//    Out_Protest_Flage=1;
	//    Sleep_SYS_IN;/// NG ////
	//	  USBA_PIN_OFF;
	//	  Mod_Dis_USBA_EN(0);
	inoutput_data.vbus_switch.sw.type_a1 = false;
	F_A1_ON = 0;
	///////////////disable看门狗/////////////////////
	wdt_disable();
	wwdt_disable();

#if (!CFG_PD_DISABLE)
	peripheral_pd_init();
#endif
	// disable Type-c模块
	if (!Bat_low_sleep_flage) //// 没有强制关机时休眠处理
		typec_sleep(TYPECA);  //// 正常休眠
							  //	fwlib_typec_disable_cc_pinmux(TYPECA, true);
							  //	typec_sleep(TYPECB);
	// disable DCDC模块
	mod_dcdc_disable();
	// disable 总TC_B_VBUS, VBUS_DISC, TC_B_ACIN
	//	mod_inoutput_disable();
	// disable 按键模块
	// mod_key_disable();
	// disable 显示驱动模块
	//	mod_display_disable();
	// disable 队列
	// mod_queue_disable();
	//	//// disable timer2
	//  TM2CON=0x00;///0000 0000
	////disable ADC
	//	mod_adc_convert_disable();
	//
	//	SRADCON0= 0x00;
	//	SRADCON1= 0x00;
	//	SRADCON2= 0x00;////休眠清零

	//   multi_protocol_sleep();
	//   disable uart
	uart_disable();
	UR0_INTE = 0x00;
	// disable timer0
	//	timer0_disable();
	//    TM0CON=0x00;
	//	TM0IN=0x00;
	//	TM0CNT=0x00;

	if (!Bat_low_sleep_flage) //// 没有强制关机时休眠处理
		TM2CON = 0x00;		  /// 0000 0000//// 正常休眠 关闭TIME2

	// disable timer3
	TM3CON = 0x00; /// 0000 0000
	// disable timer4
	TM4CON = 0x00; /// 0000 0000

	//////////////关闭比较器
	CFGR8 = 0x00;
	pd_enable(false);
	////IO 处理/////
	//    PT1=0x80;    ///1000 0000
	if (!Bat_low_sleep_flage) //// 没有强制关机时休眠处理
		PT1 = 0x80;
	else
		PT1 = 0x84; /// 1000 0100

	PT1EN = 0xf4; /// 1111 0100
	PT1PU = 0x09; /// 0000 1001

	PT2 = 0x00;	  /// 0000 0000
	PT2EN = 0x44; /// 0100 0100//// PT2.2 输出0
	PT2PU = 0x80; /// 1000 0000

	//  if(!Bat_low_sleep_flage)//// 没有强制关机时休眠处理
	PT3 = 0x00;
	//  else
	//   PT3=0x04;    ///0000 0100

	PT3EN = 0x38; /// 0011 1000
	PT3PU = 0x00; /// 0000 0000

	Sleep_SYS_IN;
	//  BAT_EN_PIN_OFF;
	//  MCU_TX_PIN_L;

	ACMP1CR4 = ACMP1CR4 & 0xfe;
	_REGx0 = 0x00;
	_REGx1 = 0x00;
	_REGx2 = 0x00;
	_REGx3 = 0x00;
	_REGx4 = 0x00;

	//	EXICON=0x3f;///E0M E1M E2M 任意沿触发
	EXICON = 0x00; /// E0M E1M E2M 下降沿触发

	if (!Bat_low_sleep_flage)
		EXIIE = 0x03; /// 开中断0使能 开中断1使能///正常休眠的情况下////
	else
		EXIIE = 0x01; /// 开中断0使能
					  //    EXICON=0x00;///E0M E1M E2M 任意沿触发
					  //	EXIIE=0x00	;/// 开中断0使能 开中断1使能

	EXIIF = 0x00;	////清零标志位
	INTCFG1 = 0x08; //// 0000 1000 开1 = 使能 PT1.3 外部中断 0
					//    INTCFG1=0x04;//// 0000 0100 开1 = 使能 PT1.2 外部中断 0
					//  INTCFG1=0x00;
					//	INTCFG2=0x60;// 0110 0000 6----1----  1 = 使能 PT2.6 外部中断 1  5--- PT2.5----1

	//  	if(!Bat_low_sleep_flage) ///正常休眠的情况下////开PT2.6休眠唤醒
	//    INTCFG2=0x40;// 0100 0000 6----1----  1 = 使能 PT2.6 外部中断 1  5--- PT2.5----0
	//    else
	INTCFG2 = 0x00; // 0100 0000 6----1----  1 = 使能 PT2.6 外部中断 1  5--- PT2.5----0

	INTCFG3 = 0x00;

	// disable 时钟
	// SystemInit();
	// disable syscfg
	// syscfg_init();
	CFGR5 = 0x00;

	mod_adc_convert_disable();
	SRADCON0 = 0x00;
	SRADCON1 = 0x00;
	SRADCON2 = 0x00; ////休眠清零

	Sleep_Down_Close_Power = 1;
	if (Bat_low_sleep_flage)
	{
		fwlib_typec_cc_pull_high_down_config(TYPECA, TYPEC_CCX_CUR_OFF, ENABLE);
		fwlib_typec_cc_det_set(TYPECA, DISABLE);
		fwlib_typec_detxif_set(TYPECA, RESET);
		fwlib_typec_scnxie_set(TYPECA, DISABLE);
		fwlib_fwlib_typec_cc_drp_set(TYPECA, DISABLE);

		//	    fwlib_typec_vconn_config(h_typec_cpy.input.instance, CC_PIN_CC1, DISABLE);
		//      fwlib_typec_vconn_config(h_typec_cpy.input.instance, CC_PIN_CC2, DISABLE);
		fwlib_typec_vconn_config(TYPECA, CC_PIN_CC1, DISABLE);
		fwlib_typec_vconn_config(TYPECA, CC_PIN_CC2, DISABLE);

		Time_100ms_cnt = 0;
		delay_ms(400);
		//	////////////////强制休眠前 ADC  处理///////
		SRADIE = 0; ///// 不开ADC 中断使能
					//        TypeC_Slide_CC1_data=Sub_adc_enhanced(CFG_ADC_CHL_CC1A);
					//        TypeC_Slide_CC2_data=Sub_adc_enhanced(CFG_ADC_CHL_CC2A);
					//		if(TypeC_Slide_CC1_data>CC_PIN_V_ADC)
					//		{
					//		  CC1_Check1_Cnt=1;
					//		}
					//		else
					//			CC1_Check1_Cnt=0;
					//		if(TypeC_Slide_CC2_data>CC_PIN_V_ADC)
					//		{
					//		  CC2_Check1_Cnt=1;
					//		}
					//		else
					//		  CC2_Check1_Cnt=0;

		delay_ms(200);

		//        TypeC_Slide_CC1_data=Sub_adc_enhanced(CFG_ADC_CHL_CC1A);
		//        TypeC_Slide_CC2_data=Sub_adc_enhanced(CFG_ADC_CHL_CC2A);
		//      TypeC_MicroB_ADC_data=Sub_adc_enhanced(CFG_ADC_CHL_LOAD_IN);
		//		if(TypeC_Slide_CC1_data>CC_PIN_V_ADC)
		//		{
		//		  CC1_Check2_Cnt=1;
		//		}
		//		else
		//		  CC1_Check2_Cnt=0;
		//
		//	    if(TypeC_Slide_CC2_data>CC_PIN_V_ADC)
		//		{
		//		  CC2_Check2_Cnt=1;
		//		}
		//		else
		//			CC2_Check2_Cnt=0;
		//
		//		if(CC1_Check2_Cnt||CC1_Check1_Cnt)
		//		{
		//		   CC1_LEVEL_NOW=1;
		//		}
		//		else
		//			CC1_LEVEL_NOW=0;
		//
		//		if(CC2_Check2_Cnt||CC2_Check1_Cnt)
		//		{
		//		   CC2_LEVEL_NOW=1;
		//		}
		//		else
		//		CC2_LEVEL_NOW=0;
		//
		//		CC1_LEVEL_BE=CC1_LEVEL_NOW;
		//		CC2_LEVEL_BE=CC2_LEVEL_NOW;

		//		#if __IF_DEBUG__
		//		Sub_sim_tx(0xCC);
		//		Sub_sim_tx(0xBB);
		//		Sub_sim_tx(TypeC_Slide_CC1_data>>8);
		//		Sub_sim_tx(TypeC_Slide_CC1_data);
		//		Sub_sim_tx(TypeC_Slide_CC2_data>>8);
		//		Sub_sim_tx(TypeC_Slide_CC2_data);
		////		Sub_sim_tx(CC1_LEVEL_BE);
		////		Sub_sim_tx(CC2_LEVEL_BE);
		////
		////		Sub_sim_tx(CC1_LEVEL_NOW);
		////		Sub_sim_tx(CC2_LEVEL_NOW);
		//		#endif
		delay_ms(400);
		//////// CC 下拉5.1K 休眠前处理动作/////
		CLKSEL0 = CLKSEL0 | 0x03; /////timer0 选10K 计时/////
		TM0CON = 0x00;			  ///// 停止定时器0
		CCDRP1 |= 0x04;			  // 开typec_en
		SCNPRD1 = 0x00;
		CCDRP1 |= 0x02; // 开drp
		CCACTL1 = 0x00; // 开下拉电阻
		//	CCBCTL1 = 0x00;
		AUTODET1 &= (~0xC0); // 关auto det
		CCIE1 = 0x00;
		CCIF1 |= 0x0F;
		//	MCK |= (1<<5);	//开10K lirc
		//	CLKSEL0=CLKSEL0|0x03;/////timer0 选10K 计时/////
		CLKDIV0 = 0x02; // 4分频
		TM0IN = 568 / 4;
		TM0CNT = 0;
		TM0IF = 0;
		T0RSTB = 0;
		TM0IE = 0;
		GIE = 1;
		T0EN = 1;
		while (!TM0IF)
			;
		TM0CON = 0x00; ///// 停止定时器0
					   //		CCDRP1 = 0x02; //关 typec_en	//开drp
		CCDRP1 = 0x00; // 关 typec_en	//关drp
		// 后面是进睡眠
		//		fwlib_typec_cc_pull_high_down_config(TYPECA, TYPEC_CCX_CUR_OFF, ENABLE);

		// disable timer0
		timer0_disable();
		TM0CON = 0x00;
		TM0IN = 0x00;
		TM0CNT = 0x00;
		///// 休眠定时唤醒 定时器2 处理/////
		timer2_init(); /////  T2 唤醒初始化/////
		TM2IE = 1;
		T2EN = 1;
		Foece_Sleep_F = 1;
	}

	//    Foece_Sleep_Time_S=0;
	//    Foece_Sleep_Time_Min=0;
	//    Foece_Sleep_Time_Mon=0;
	while (1)
	{
		// disable ADC
		mod_adc_convert_disable();
		SRADCON0 = 0x00;
		SRADCON1 = 0x00;
		SRADCON2 = 0x00; ////休眠清零
		Time_2_Flage_do = 0;
		GIE = 1;
		asm("nop");
		asm("nop");
		asm("nop");
		asm("sleep");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");

		asm("CLRWDT");
		asm("nop");
		//		Time_2_Flage_do=1;
		///// 正常休眠 有 KEY 按键中断0唤醒和 B端口中断1唤醒 和TYPE_C扫描唤醒 三种唤醒方式///
		///// 强制休眠 只有 KEY 按键中断唤醒和 T2定时唤醒检测唤醒 两种唤醒方式////
		if (Sleep_Down_Close_Power++ >= 4)
		{
			Sleep_Down_Close_Power = 5;
			//		  BAT_EN_PIN_OFF;
		}
		// 		if(!KEY1)
		// 		{
		// 		   Time_2_Flage_do=0;
		// //		   Out_Protest_Flage=0;
		// 		   Bat_low_sleep_flage=0;
		// 		}
		///// 如果是Time2唤醒起来的 使能ADC 检测/////
		//		  if((Time_2_Flage_do)&&(Bat_low_sleep_flage))
		//		{
		//			CC_Check_Cnt++;
		//			///// 使能ADC //////
		//			adc_init();
		//			SRADIE=0;///// 不开ADC 中断使能
		//			adc_enable();
		//
		//			TypeC_Slide_CC1_data=Sub_adc_enhanced(CFG_ADC_CHL_CC1A);
		//			TypeC_Slide_CC2_data=Sub_adc_enhanced(CFG_ADC_CHL_CC2A);
		//			TypeC_MicroB_ADC_data=Sub_adc_enhanced(CFG_ADC_CHL_LOAD_IN);
		//			if(CC_Check_Cnt==1)
		//			{
		//				if(TypeC_Slide_CC1_data>CC_PIN_V_ADC)
		//				{
		//					CC1_Check1_Cnt=1;
		//				}
		//				else
		//					CC1_Check1_Cnt=0;
		//
		//				if(TypeC_Slide_CC2_data>CC_PIN_V_ADC)
		//				{
		//					CC2_Check1_Cnt=1;
		//				}
		//				else
		//					CC2_Check1_Cnt=0;
		//			}
		//			else if(CC_Check_Cnt==2)
		//			{
		//				 CC_Check_Cnt=0;
		//				if(TypeC_Slide_CC1_data>CC_PIN_V_ADC)
		//				{
		//					CC1_Check2_Cnt=1;
		//				}
		//				else
		//					CC1_Check2_Cnt=0;
		//					if(TypeC_Slide_CC2_data>CC_PIN_V_ADC)
		//				{
		//					CC2_Check2_Cnt=1;
		//				}
		//				else
		//					CC2_Check2_Cnt=0;
		//
		//					if(CC1_Check2_Cnt||CC1_Check1_Cnt)
		//				{
		//					 CC1_LEVEL_BE=1;
		//				}
		//				else
		//					CC1_LEVEL_BE=0;
		//
		//				if(CC2_Check2_Cnt||CC2_Check1_Cnt)
		//				{
		//					 CC2_LEVEL_BE=1;
		//				}
		//				else
		//					CC2_LEVEL_BE=0;
		//
		//                if((CC2_LEVEL_BE!=CC2_LEVEL_NOW)||(CC1_LEVEL_BE!=CC1_LEVEL_NOW))
		//				{
		//					Bat_low_sleep_flage=0;
		//					Time_2_Flage_do=0;
		//				}
		//
		////				 #if __IF_DEBUG__
		////					  Sub_sim_tx(0xAA);
		////					  Sub_sim_tx(0xFF);
		////					  Sub_sim_tx(TypeC_Slide_CC1_data>>8);
		////					  Sub_sim_tx(TypeC_Slide_CC1_data);
		////					  Sub_sim_tx(TypeC_Slide_CC2_data>>8);
		////					  Sub_sim_tx(TypeC_Slide_CC2_data);
		////
		////					  Sub_sim_tx(TypeC_MicroB_ADC_data>>8);
		////	                  Sub_sim_tx(TypeC_MicroB_ADC_data);
		//////					  Sub_sim_tx(CC1_LEVEL_BE);
		//////					  Sub_sim_tx(CC2_LEVEL_BE);
		//////					  Sub_sim_tx(CC1_LEVEL_NOW);
		//////	                  Sub_sim_tx(CC2_LEVEL_NOW);
		////
		////					  Sub_sim_tx(Time_2_Flage_do); //// Time_2_Flage_do
		////				 #endif
		//		  }
		//
		////          if(TypeC_MicroB_ADC_data<880)//// B 口ADC 检测唤醒
		////		  {
		////		   Time_2_Flage_do=0;
		////		   Bat_low_sleep_flage=0;
		////		  }
		//		}
		//////////////////////////
		// 		if(!KEY1)///// 按键按下退出 休眠
		// 		{
		// 		   Time_2_Flage_do=0;
		// //		   Out_Protest_Flage=0;
		// 		   Bat_low_sleep_flage=0;
		// 		}
		if (!Bat_low_sleep_flage) //// 不是强制休眠退出//////
		{
			//
			//		     #if __IF_DEBUG__
			//					Sub_sim_tx(0x77);
			//					Sub_sim_tx(0x66);
			//		      #endif
			break;
		}
	}

	EXICON = 0x00;	/// E0M 下降沿触发
	EXIIE = 0x00;	/// 中断清零
	EXIIF = 0x00;	////清零标志位
	INTCFG1 = 0x00; //// 0000 0100 开1 = 使能 PT1.2 外部中断 0
	INTCFG2 = 0x00;
	INTCFG3 = 0x00;

	if (Bat_low_Cnt >= 30)
	{
		Bat_low_sleep_flage = 1;
	}
	////// 按键处理//////
	//      if(!KEY1)
	// 	 {
	// 	   Sleep_up_shor_do=1;
	// //	   Out_Protest_Flage=0;
	//        discharge_displed=1;
	// 	 }
	// 	 else
	// 	  Sleep_up_shor_do=0;
	//
	//	 app_peripheral_init();
	//	 Sleep_up_data_init();
	//	 if((adc_convert.type_ntc.adc_code_rt < C_TempH_DisCharge_Off_Pro)||(adc_convert.type_ntc.adc_code_rt >= C_TempL_DisCharge_Off_Pro))
	//	 Temp.DischargeTemp_OK=0;
	//////    adc_convert.type_ntc.adc_code_sl=adc_convert.type_ntc.adc_code_rt;
	////
	//////  misc_interface.typea1.t_prohbit_check= C_PROHBIT_CHECKLOAD;//// 重置2S 负载检测///
	//////  misc_interface.typea1.t_prohbit_check= 100;//// 重置2S 负载检测///
	//////     	#if __IF_DEBUG__
	//////	  Sub_sim_tx(0xA1);
	//////	  Sub_sim_tx(0xA1);
	//////	  Sub_sim_tx(0xA1);
	//////
	//////	  Sub_sim_tx(adc_convert.type_ntc.adc_code_sl>>8);
	//////	  Sub_sim_tx(adc_convert.type_ntc.adc_code_sl);
	//////
	//////	  Sub_sim_tx(adc_convert.type_ntc.adc_code_rt>>8);
	//////	  Sub_sim_tx(adc_convert.type_ntc.adc_code_rt);
	//////	  Sub_sim_tx(Temp.DischargeTemp_OK);
	//////	   #endif
	////
	//////	  #if __IF_DEBUG__
	//////		Sub_sim_tx(0xD1);
	//////		Sub_sim_tx(0xD1);
	//////		Sub_sim_tx(0xD1);
	//////	  #endif
	//	  adc_convert.type_ntc.adc_code_sl=adc_convert.type_ntc.adc_code_rt;
	//      SYS_in_Sleep_F=0;
}
static void Vbus_level_deal(void)
{
	uint8_t R_VbusVol_Value;
	uint8_t R_VbusUSBA_Value;

	R_VbusVol_Value = VBUS_8_date;
	R_VbusUSBA_Value = VBUS_USBA_8_date;

	if (R_VbusVol_Value > C_Vbus17V)
		VoltFlag = C_QC20V_Flag;
	else if (R_VbusVol_Value > C_Vbus13V)
		VoltFlag = C_QC15V_Flag;
	else if (R_VbusVol_Value > C_Vbus10V)
		VoltFlag = C_QC12V_Flag;
	else if (R_VbusVol_Value > C_Vbus8V)
		VoltFlag = C_QC9V_Flag;
	else if (R_VbusVol_Value > C_Vbus6V)
		VoltFlag = C_QC7V_Flag;
	else if (R_VbusVol_Value > C_Vbus2V)
	{
		VoltFlag = C_QC5V_Flag;
	}
	else
	{
		VoltFlag = C_QC2V_Flag;
	}
	//    if(R_VbusUSBA_Value>C_Vbus17V)
	//		USBA_VoltFlag=C_QC20V_Flag;
	if (R_VbusUSBA_Value > C_Vbus13V)
		USBA_VoltFlag = C_QC15V_Flag;
	else if (R_VbusUSBA_Value > C_Vbus10V)
		USBA_VoltFlag = C_QC12V_Flag;
	else if (R_VbusUSBA_Value > C_Vbus8V)
		USBA_VoltFlag = C_QC9V_Flag;
	else if (R_VbusUSBA_Value > C_Vbus6V)
		USBA_VoltFlag = C_QC7V_Flag;
	else if (R_VbusUSBA_Value > C_Vbus2V)
	{
		USBA_VoltFlag = C_QC5V_Flag;
	}
	else
	{
		USBA_VoltFlag = C_QC2V_Flag;
	}
}
static void BSP_PDCur_Deal(uint16_t PDCur)
{
	if (PDCur)
	{
		//	   	PDCur=PDCur/5; ////300--60---- 8886

		if (PDCur >= 50)
			PDCur = PDCur - 50;
		else
			PDCur = 0;

		PDCur = PDCur / 5; ////300----50---- 7201

		switch (VoltFlag)
		{
		case C_QC5V_Flag:
			if (PDCur > PDO_cuurest_5V) //////////////210 5A
				PDCur = PDO_cuurest_5V;
			//				R_ChargeCur_PDData=PDCur;
			break;

		case C_QC9V_Flag:
			if (PDCur > PDO_cuurest_9V)
				PDCur = PDO_cuurest_9V;
			//				R_ChargeCur_PDData=PDCur;
			break;

		case C_QC12V_Flag:
			if (PDCur > PDO_cuurest_12V)
				PDCur = PDO_cuurest_12V;
			//				R_ChargeCur_PDData=PDCur;
			break;

		case C_QC15V_Flag:
			if (PDCur > PDO_cuurest_15V)
				PDCur = PDO_cuurest_15V;
			//				R_ChargeCur_PDData=PDCur;
			break;

		case C_QC20V_Flag:
			if (PDCur > PDO_cuurest_20V) ////////////////94 3.25A
				PDCur = PDO_cuurest_20V;
			//				R_ChargeCur_PDData=PDCur;
			break;
		default:
			break;
		}
		R_ChargeCur_PDData = PDCur;
	}
}
static void Charge_current_deal(void)
{
	uint8_t temp_I;
	uint8_t temp_I_min;
	uint8_t temp_I_max;
	uint8_t Add_I_max;
	uint8_t RE_data_temp8;
	if (VoltFlag > C_QC5V_Flag) /// 不是PD充电转换/////
	{
		R_ChargeCur_DataBuff = PDO_cuurest_MA2000;
		if (VoltFlag == C_QC7V_Flag)
			R_ChargeCur_DataBuff = PDO_cuurest_MA3000;
		if (VoltFlag == C_QC9V_Flag)
			R_ChargeCur_DataBuff = PDO_cuurest_MA3000;
		if (VoltFlag == C_QC12V_Flag)
			R_ChargeCur_DataBuff = PDO_cuurest_MA1500; /// 1.5A
	}
	else ////  5V充电时
	{
		R_ChargeCur_DataBuff = PDO_cuurest_MA3000;
		if (MiroB_charge_in)
			R_ChargeCur_DataBuff = PDO_cuurest_MA2000;
	}
	if (h_pd.output.source_cap_cur_capacity)
	{
		BSP_PDCur_Deal(h_pd.output.sink_request_current); /// PDO 转电流检测数值转换////
		R_ChargeCur_DataBuff = R_ChargeCur_PDData;

		if ((VoltFlag == C_QC9V_Flag) && (h_pd.output.source_cap_cur_capacity == 55)) // 9V  0.55PDO
		{
			if (!LED_test_mode_Cnt)
			{
				LED_test_mode_Cnt = 1;
				LED_test_mode_Cnt2 = 0;
			}
		}
		else
			LED_test_mode_Cnt = 0;
	}
	if ((!Temp.ChargeTemp_OK) || (V_NO_Cha_flage) || (V_NO_BAT_Charge) ||
		(Bat_Protest_cnt >= OVP_CHARGE_TIME) || (Charge_OCP_Flage) || (Bat_low_sleep_flage) || (Bat_Low_5V_NG_Flage)) /// 充电过温  电压过压欠压过压保护 充电保护
	{
		R_ChargeCur_DataBuff = PDO_cuurest_MA500;
		R_ChargeCur_Data = R_ChargeCur_DataBuff;
		mod_charge_ibat0_limit_deal(0); //// 开启充电使能 没有用
		return;
	}
	else //// 充电不过温
	{
		mod_charge_ibat0_limit_deal(1); //// 开启充电使能 没有用
										//       mod_charge_vol_deal(Vinreg_V45);////0X05-4.48 限制最低充电电流电压值

		//        if(Charge_low_power_F)/// 充电温度保护 0度以下 45度以上 500ma 充电
		//        {
		//            if( R_ChargeCur_DataBuff>=PDO_cuurest_MA500)
		//            R_ChargeCur_DataBuff=PDO_cuurest_MA500;
		//        }
		//////////// 充电复充功能/////
		//       if((Vbat_8_date<C_CV_Fast_charge)&&(adc_convert.typec_a.adc_code_sl<BAT_Full_cuurest))///// 12.3V 以下
		//       {
		//            RE_data_temp8=iic_receive_byte(0x21);
		//              if(RE_data_temp8==0x80)
		//            {
		//                Recharge_cnt++;
		//                if(Recharge_cnt>=30)
		//                {
		//                   Recharge_cnt=0;
		//                    mod_SC8886_Charge_init();
		//                }
		//            }
		//            else
		//            Recharge_cnt=0;
		//
		//       }
		//        else
		//        Recharge_cnt=0;
		if ((Bat_Protest_cnt) || (Charge_low_power_F)) /// 充电温度保护 0度以下 45度以上 500ma 充电
		{
			//          if( R_ChargeCur_DataBuff>=PDO_cuurest_MA500)
			R_ChargeCur_DataBuff = PDO_cuurest_MA500;
			R_ChargeCur_Data = R_ChargeCur_DataBuff;
			mod_charge_cur_deal(R_ChargeCur_Data);
		}
		else
		{
			if (Charge_HIG_Vbat_F) /// 充电电池低电压保护 8.6V 以下处理充电300ma
			{
				//            if( R_ChargeCur_DataBuff>=7)//// 350ma
				//            R_ChargeCur_DataBuff=7;
				R_ChargeCur_DataBuff = R_ChargeCur_DataBuff / 2;
			}
		}
		//    if((R_ChargeCur_DataBuff>PDO_cuurest_MA2900)&&(VoltFlag>=C_QC20V_Flag))///20V --3A 以上 多增加150ma///
		//      if(R_ChargeCur_DataBuff>PDO_cuurest_MA2100)
		//      {
		//	    if(VoltFlag==C_QC5V_Flag)
		//		 R_ChargeCur_DataBuff=R_ChargeCur_DataBuff+2;
		//		if(VoltFlag==C_QC9V_Flag)
		//		 R_ChargeCur_DataBuff=R_ChargeCur_DataBuff+2;
		//		if(VoltFlag==C_QC12V_Flag)
		//		 R_ChargeCur_DataBuff=R_ChargeCur_DataBuff+2;
		//        if(VoltFlag==C_QC15V_Flag)
		//         R_ChargeCur_DataBuff=R_ChargeCur_DataBuff+2;
		//		if(VoltFlag==C_QC20V_Flag)
		//	    {
		//		   R_ChargeCur_DataBuff=R_ChargeCur_DataBuff+5;
		//	    }
		//      }
	}
	///////////////// 电流充电处理/////////
	if (R_ChargeCur_Data != R_ChargeCur_DataBuff)
	{
		if (R_ChargeCur_DataBuff > R_ChargeCur_Data)
		{
			R_ChargeCur_Data++;
		}
		else
		{
			temp_I_max = R_ChargeCur_Data - R_ChargeCur_DataBuff;
			if (temp_I_max > 3)
			{
				R_ChargeCur_Data = R_ChargeCur_Data - 3; //// 150ma 一次 降充电电流////
			}
			else
				R_ChargeCur_Data--;
		}
		mod_charge_cur_deal(R_ChargeCur_Data);
	}

	///////////////IBAT 限流处理 11.6V 以下电压  IBAT 限流 2.5A  12V 以上恢复正常功率充电 /////
	if (Charge_bat_low_power_F)
	{
		if (Vbat_8_date >= C_CV_BAT_recharge)
			Charge_bat_low_power_CNT++;
		else
			Charge_bat_low_power_CNT = 0;

		if (Charge_bat_low_power_CNT >= 5)
		{
			Charge_bat_low_power_CNT = 0;
			Charge_bat_low_power_F = 0;
			mod_SC8886_Charge_init();
			//            	//vbbat限流
			//	       iic_transmit_byte(0x3A,0x77);
		}
	}
	else
	{
		if (Vbat_8_date < C_CV_BAT_low_charge)
			Charge_bat_low_power_CNT++;
		else
			Charge_bat_low_power_CNT = 0;

		if (Charge_bat_low_power_CNT >= 5)
		{
			Charge_bat_low_power_CNT = 0;
			Charge_bat_low_power_F = 1;
			iic_transmit_byte(0x3A, 24); //// IBAT 端 2.5A 限流/////
		}
	}
}

void Discharge_Pro_curr(void)
{
	uint8_t TCA_Pro_cur;
	uint16_t TAA_Pro_cur;
	uint8_t R_VbusVol_Value;
	uint8_t R_Ibus_Value;

	R_VbusVol_Value = VBUS_8_date;
	if (R_SysMode_OK == COULOMB_CHARGE)
		return;
	TCA_Pro_cur = TCA_5V_Pro_current;
	TAA_Pro_cur = TAA_5V_Pro_current;

	VBUS_V_Hight = SYS_VBUS_V60;
	VBUS_V_Low = SYS_VBUS_V38;

	if (h_pd.output.b_source_ps_rdy)
	{
		switch (h_pd.output.request_num) ////PD 输出////
		{
		case CAP_1:
			TCA_Pro_cur = TCA_5V_Pro_current;
			VBUS_V_Hight = SYS_VBUS_V60;
			VBUS_V_Low = SYS_VBUS_V38;
			break;
		case CAP_2:
			TCA_Pro_cur = TCA_9V_Pro_current;
			if (TYPE_CA_18W_Flage)
				TCA_Pro_cur = TCA_9V_Pro_current_18W;
			VBUS_V_Hight = SYS_VBUS_V102;
			VBUS_V_Low = SYS_VBUS_V82;
			break;
		case CAP_3:
			TCA_Pro_cur = TCA_12V_Pro_current;
			if (TYPE_CA_18W_Flage)
				TCA_Pro_cur = TCA_12V_Pro_current_18W;
			VBUS_V_Hight = SYS_VBUS_V135;
			VBUS_V_Low = SYS_VBUS_V105;
			break;
		case CAP_4:
			TCA_Pro_cur = TCA_15V_Pro_current;
			if (TYPE_CA_18W_Flage)
				TCA_Pro_cur = TCA_15V_Pro_current_18W;
			VBUS_V_Hight = SYS_VBUS_V165;
			VBUS_V_Low = SYS_VBUS_V140;
			break;
		case CAP_5:
			if (!h_pd.output.b_emarker_5a)
				TCA_Pro_cur = TCA_20V_Pro_current;
			else
				TCA_Pro_cur = TCA_20V_Pro_current_EMACK;

			if (Port_NTC_NG_LOW_POWER_Flage) ///// 45W 保护处理////
			{
				TCA_Pro_cur = TCA_20V_Pro_current_45W;
			}

			if (TYPE_CA_18W_Flage)
				TCA_Pro_cur = TCA_20V_Pro_current_18W;

			VBUS_V_Hight = SYS_VBUS_V220;
			VBUS_V_Low = SYS_VBUS_V185;
			break;
		}

		if ((R_VbusVol_Value >= VBUS_V_Hight) || (R_VbusVol_Value <= VBUS_V_Low))
		{
			VBUS_OVP_CNT++;
		}
		else
			VBUS_OVP_CNT = 0;
	}
	else
	{
		TCA_Pro_cur = TCA_5V_Pro_current;
		VBUS_V_Hight = SYS_VBUS_V60;
		VBUS_V_Low = SYS_VBUS_V38;
	}

	if (USBA_VoltFlag >= C_QC15V_Flag)
	{
		TAA_Pro_cur = Port_USBA_MA500; /// 0.5A
	}
	else if (USBA_VoltFlag == C_QC12V_Flag)
	{
		TAA_Pro_cur = TAA_12V_Pro_current;
	}
	else if (USBA_VoltFlag == C_QC9V_Flag)
	{
		TAA_Pro_cur = TAA_9V_Pro_current;
	}
	else
	{
		TAA_Pro_cur = TAA_5V_Pro_current;
	}

	//	if(USBA_PIN)//// A口输出电压报警////// 3.8---12.8 正常////
	if (inoutput_data.vbus_switch.sw.type_a1)
	{
		if ((VBUS_USBA_8_date <= SYS_VBUS_V38) || (VBUS_USBA_8_date >= SYS_VBUS_V128)) //// 3.8---12.8
		{
			VBUS_USBA_OVP_CNT++;
		}
		else
		{
			VBUS_USBA_OVP_CNT = 0;
		}
	}
	else
	{
		VBUS_USBA_OVP_CNT = 0;
	}
	//	if(adc_convert.typec_a.adc_code_sl>=0xff)////最大限流4.3A
	if (hex_greater_than_compare(adc_convert.typec_a.adc_code_sl, 0xff)) ////最大限流4.3A
		R_Ibus_Value = 0xff;
	else
		R_Ibus_Value = adc_convert.typec_a.adc_code_sl;
	//   if(adc_convert.typec_a.adc_code_sl>=TCA_Pro_cur)///R_Ibus_Value

	if (R_Ibus_Value >= TCA_Pro_cur) /// R_Ibus_Value
	{
		PD_curr_Pro_cnt++;
	}
	else
		PD_curr_Pro_cnt = 0;
	//////////////////////////////
	//    if(adc_convert.typea_1.adc_code_sl>=TAA_Pro_cur)////
	if (hex_greater_than_compare(adc_convert.typea_1.adc_code_sl, TAA_Pro_cur)) ///
	{
		USBA_curr_Pro_cnt++;
	}
	else
		USBA_curr_Pro_cnt = 0;

	//    if((VBUS_USBA_OVP_CNT>=500)||(VBUS_OVP_CNT>=800)||(USBA_curr_Pro_cnt>=250)||(PD_curr_Pro_cnt>=250))//// 过流过压保护处理/////
	if ((hex_greater_than_compare(VBUS_USBA_OVP_CNT, 500)) || (hex_greater_than_compare(VBUS_OVP_CNT, 800)) || (USBA_curr_Pro_cnt >= 250) || (PD_curr_Pro_cnt >= 250)) //// 过流过压保护处理/////
	{

		//         #if __IF_DEBUG__
		//         Sub_sim_tx(0xbb);
		// // 		  Sub_sim_tx(VBUS_USBA_OVP_CNT);
		// //		  Sub_sim_tx(VBUS_OVP_CNT);
		// 		  Sub_sim_tx(USBA_curr_Pro_cnt);
		// 		  Sub_sim_tx(PD_curr_Pro_cnt);
		//         #endif
		if ((USBA_curr_Pro_cnt >= 250) || (PD_curr_Pro_cnt >= 250))
		{
			holdingRegisters[8] |= (0x01 << 5);
		}
		else
		{
			holdingRegisters[8] &= ~(0x01 << 5);
		}

		VBUS_OVP_CNT = 0;
		PD_curr_Pro_cnt = 0;
		USBA_curr_Pro_cnt = 0;

		//        Sleep_SYS_IN;/// 短路保护关EN
		Mod_Dis_USBA_EN(0);
		F_A1_ON = 0;
		SOS_LEVEL = 0;
		WHITE_ON = 0;
		RED_ON = 0;
		//		WHITE_PIN_OFF;
		//  	    RED_PIN_OFF;

		inoutput_data.vbus_switch.sw.type_a1 = false;
		inoutput_data.vbus_switch.sw.type_ca = false;
		//		inoutput_data.vbus_switch.sw.type_cb= false;
		inoutput_data.vbus_switch.vbus_type_a1_delay_cnt = 0;
		inoutput_data.vbus_switch.vbus_type_b1_delay_cnt = 0;
		inoutput_data.vbus_switch.vbus_type_ca_delay_cnt = 0;
		//		inoutput_data.vbus_switch.vbus_type_cb_delay_cnt= 0;
		Discharge_MinCur = 1;
		sleepcnt = 2;
		discharge_displed = displaytime; //// 放电过流过压欠压保护 灭灯////
		app_power_PDO_rerest();
		TYPE_C_constraint_sleep();
		return;
	}
	holdingRegisters[8] &= ~(0x01 << 5);
}

void led_deal() ////100ms 处理一次
{
	//   	if(Frist_start_sink)
	//	{
	//	  mod_display_led(p_led_1, false);
	//	  mod_display_led(p_led_2, false);
	//	  mod_display_led(p_led_3, false);
	//	  mod_display_led(p_led_4, false);
	//	}
	//
	//  ///////////////报警处理//////////////////////
	//	if(Err_diply)//// 400ms 发送报警信号
	//	{
	//	  discharge_displed=displaytime;//显示关闭//// 报警灭灯
	//	  mod_display_led(p_led_1, false);
	//	  mod_display_led(p_led_2, false);
	//	  mod_display_led(p_led_3, false);
	//	  mod_display_led(p_led_4, false);
	//	  Err_diply_check_time_cnt++;
	//	  if(Err_diply_check_time_cnt>=3)////  300ms 一次闪烁
	//	  {
	//		Err_diply_check_time_cnt=0;
	//		Err_diply++;
	//		if(Err_diply>7)//闪烁5次///  发送4S  LED_LEVEL=7  信号
	//		{
	//			Err_diply=0;////退出报警模式
	//		}
	//	  }
	//	  if((Err_diply==2)||(Err_diply==4)||(Err_diply==6))
	//	  {
	//		mod_display_led(p_led_1, 1);
	//	  }
	//	}
}
void Data_Tx_inti(void)
{
	//   uint8_t   TX_STATU,TX_BAT,Temp_car_date;
	//   uint16_t  RCR_data_16;
	//   uint8_t   RCR_data_8;
	//   uint8_t   temp_data_8,temp_data1_8;
	//   uint16_t   temp_data_16;
	//   //////////////A 口轻载或者带载检测处理/////
	//     if(!USBA_in_Flage)
	//     {
	//       if(hex_greater_than_compare(adc_convert.typea_1.adc_code_sl,(C_DisCharge_5VSmallCurL+4)))
	//         USBA_in_Cnt++;
	//      if(USBA_in_Cnt>=10)
	//      {
	//       USBA_in_Cnt=0;
	//       USBA_in_Flage=1;
	//      }
	//     }
	//     else
	//     {
	// 	 if(hex_less_than_compare(adc_convert.typea_1.adc_code_sl,C_DisCharge_5VSmallCurL))
	// 	   USBA_in_Cnt++;
	// 	 if(USBA_in_Cnt>=15)
	// 	 {
	// 	  USBA_in_Cnt=0;
	// 	  USBA_in_Flage=0;
	// 	 }
	//     }
	//         #if 1
	// 		  uart_t_count++;
	// 		  if(uart_t_count>=5)/////0.5S 发送一次数据  10ms*30=0.3S
	// 		  {
	// 		    uart_t_count=0;

	// 			TX_BAT=0x00;
	// 			TX_STATU=0x00;

	// 			if(BatCap_Value>100)
	// 			{
	// 			   TX_BAT=0x00;
	// 			}
	// 			 else
	// 			{
	// 			   TX_BAT=BatCap_Value;
	// 			}

	// #if 0
	// 			BAT_VAULE_TEST_Cnt++;
	// 			if(BAT_VAULE_TEST_Cnt>=4)
	// 			{
	// 			   BAT_VAULE_TEST_Cnt=0;
	// 			    if(R_SysMode_OK==COULOMB_CHARGE)
	// 			   {
	// 				   BAT_VAULE_TEST++;
	// 			      if(BAT_VAULE_TEST>100)
	// 			       BAT_VAULE_TEST=0;
	// 			   }
	// 			   else///// 放电或者待机的时候处理/////
	// 			   {
	// 			      if(BAT_VAULE_TEST>1)
	// 			      {
	// 			        BAT_VAULE_TEST--;
	// 			      }
	// 			      else
	// 			        BAT_VAULE_TEST=100;
	// 			   }
	// 			}
	// 			TX_BAT=BAT_VAULE_TEST;
	// 			discharge_displed=1;
	// #endif
	// 			 if((discharge_displed>=displaytime)||Boot_NG_Flage)//// 灭屏不显示处理/////
	// 			{
	// 			     discharge_displed=displaytime;
	// 			     TFT_maid_mode=TFT_Clear_Statu;
	// 			     TFT_minor_mode=0x00;
	// 			}
	// 			else//// 正常处理//////
	// 			{
	// 				if(Star_Cartoon)/// 开始动画处理
	// 				{
	// 				  TFT_maid_mode=TFT_Star_Statu;
	// 				  TFT_minor_mode=0x00;
	// 				 if(Change_lauge_Flage==1)
	// 				 {
	// 				   TFT_minor_mode=TFT_minor_mode|0x00;
	// 				 }
	// 				 else if(Change_lauge_Flage==2)
	// 				 {
	// 				   TFT_minor_mode=TFT_minor_mode|0x01;
	// 				 }
	// 				 else
	// 				 {
	// 				   TFT_minor_mode=TFT_minor_mode|0x02;
	// 				 }

	// 				  Star_Cartoon++;
	// 				  if(Star_Cartoon>=5)
	// 				  Star_Cartoon=0;
	// 				}
	// 				else
	// 				{
	// 				  if(Error_icon_Cnt)///// 显示错误程序////
	// 				  {
	// 				    TFT_maid_mode=TFT_Error_Statu;
	// 				      Error_icon_Cnt++;
	// 				    if(Error_icon_Cnt>=5)//// 显示2S钟//
	// 				     Error_icon_Cnt=0;
	// 				  }
	// 				  else
	// 				  {
	// 				     if(car_ST)////夹子接入时////
	// 				     {
	// 				       TFT_maid_mode=TFT_Car_Statu;

	// 				       Temp_car_date=0x00;
	// 					   if(car_ST)////夹子接入时////
	// 					  {
	// 						   if(f_err_ot)
	// 						  {
	// 							Temp_car_date=7;
	// 							Error_icon_Cnt=1;
	// 							TFT_maid_mode=TFT_Error_Statu;
	// 							TFT_minor_mode=TFT_Error_icon_Overheated;
	// 						  }
	// 						  else if(car_ST!=0)
	// 						  {
	// 							if(car_ST==1)		////
	// 							{
	// 							   Temp_car_date=3;
	// 							}
	// 							 if(car_ST==2)
	// 							{
	// //							   if(BatCap_Value>=50)
	// 								 Temp_car_date=4;
	// //							   else
	// //								 Temp_car_date=6;
	// 							}
	// 							if(car_ST==3)		////
	// 							{
	// 								if(f_jump_start)///// 待测试///
	// 									Temp_car_date=5;		/////
	// 								else
	// 									Temp_car_date=5;		/////
	// 							}
	// 							  if((car_ST==6)||(car_ST==7))
	// 							   Temp_car_date=5;

	// 							   if(Temp_car_date==3)
	// 							  {
	// 							   TFT_minor_mode=TFT_Car_icon_Clamp_Cables;
	// 							  }
	// 							   if(Temp_car_date==4)
	// 							  {
	// 							   TFT_minor_mode=TFT_Car_icon_Ready;
	// 							  }
	// 							  if(Temp_car_date==5)
	// 							  {
	// 							   TFT_minor_mode=TFT_Car_icon_Unplug;
	// 							  }
	// 						}
	// 					  }
	// 				     }
	// 				     else//////// 充电放电处理///////
	// 				     {
	// 				       TFT_maid_mode=TFT_Char_Dis_Statu;
	// 				       if(plug_state_context.state.bit.b_cac)/// 单 C 口充电///
	// 				       {
	// 				         TFT_minor_mode=TFT_Char_Dis_icon_TypeC_in;

	// 				         if(coulomb_data.output.b_batt_full)
	// 				           TFT_minor_mode=TFT_Char_Dis_icon_no_inandout;
	// 				       }
	// 				       else
	// 				       {
	// //				         if(plug_state_context.state.bit.b_cad)//// C口放电////
	//                          if(plug_state_context.state.bit.b_cad||TYPE_C_Waittime_Cnt)//// C口放电///
	// 				         {
	// 				           if(USBA_in_Flage)/// A口插入 A口和C口一起放电///
	// 				           {
	// 				             TFT_minor_mode=TFT_Char_Dis_icon_TypeC_USBA_out;
	// 				           }
	// 				           else /// 单独C口放电///
	// 				           {
	// 				              TFT_minor_mode=TFT_Char_Dis_icon_TypeC_out;
	// 				           }
	// 				         }
	// 				         else
	// 				         {
	// 				           if(USBA_in_Flage)/// A口插入
	// 				           {
	// 				            TFT_minor_mode=TFT_Char_Dis_icon_USBA_out;
	// 				           }
	// 				           else
	// 				           {
	// 				            TFT_minor_mode=TFT_Char_Dis_icon_no_inandout;
	// 				           }
	// 				         }
	// 				       }
	// 				     }
	// 				  }
	// 				}
	// 		    }
	// ///////////正常串口程序///////////////////// 0.5S 发送一次处理///////
	// //		if(!battery_do)
	//          temp_data_8=TFT_maid_mode;
	//          temp_data_8=temp_data_8<<5;
	//          temp_data_8=temp_data_8&0xe0;

	// 	     TX_STATU=0x00;
	// 	     TX_STATU=TFT_minor_mode&0x1f;
	// 	     TX_STATU=TX_STATU|temp_data_8;/////显示模式处理////

	// 	     RCR_data_8=0x00;

	// 	     if(Change_lauge_Cnt)////Change_lauge_Cnt
	//          {

	// //           Change_lauge_Time_Cnt++;
	// //             uart_putchar(0xAC);
	// //             uart_putchar(0xAA);
	//              RCR_data_8=RCR_data_8+0xAA;
	//              temp_data_8=0xA0;
	//              if(Change_lauge_Flage==1)
	//              {
	//                temp_data_8=temp_data_8|0x00;
	//              }
	//              else if(Change_lauge_Flage==2)
	//              {
	//                temp_data_8=temp_data_8|0x01;
	//              }
	//              else
	//              {
	//                temp_data_8=temp_data_8|0x02;
	//              }

	//              if(Change_lauge_Time_Cnt>=40)
	//              {
	//               temp_data_8=temp_data_8|0x10;
	//              }

	// //              uart_putchar(temp_data_8);
	//                RCR_data_8=RCR_data_8+temp_data_8;
	//          }
	//          else
	//          {
	//  //        uart_putchar(0xaa);
	//           RCR_data_8=RCR_data_8+0xaa;
	//  //        uart_putchar(TX_STATU);////TX_STATU
	//          RCR_data_8=RCR_data_8+TX_STATU;
	//          if(TFT_Char_Dis_Statu==TFT_maid_mode)
	//          {
	//   //          uart_putchar(TX_BAT);////电池电量//////
	//             RCR_data_8=RCR_data_8+TX_BAT;
	// #if 1
	//             temp_data_8=Data_16_to_8_data_Deal(adc_convert.type_loadin.adc_code_sl/4);
	//  //           uart_putchar(temp_data_8);//// C口电压///
	//             RCR_data_8=RCR_data_8+temp_data_8;
	//             temp_data_16=adc_convert.typec_a.adc_code_sl*10;
	//             temp_data_16=temp_data_16/8;
	//             temp_data_8=Data_16_to_8_data_Deal(temp_data_16);//// C口电流处理////

	//               temp_data1_8=temp_data_8/16;
	//             if(temp_data_8>temp_data1_8)
	//               temp_data_8=temp_data_8-temp_data1_8;/////10% 电流处理///

	//             ///////////////////// 只传100ma 单位的电流值/////
	//             if(temp_data_8<=2)
	//             {
	//                temp_data_8=0;
	//             }
	//             else
	//             {
	//                 temp_data1_8=temp_data_8%5;
	//                 temp_data_8=temp_data_8-temp_data1_8;

	//                if(temp_data1_8>=3)
	//                {
	//                  temp_data_8=temp_data_8+5;
	//                }
	//             }

	//  //           uart_putchar(temp_data_8);//// C口电流///
	//              RCR_data_8=RCR_data_8+temp_data_8;
	//             temp_data_8=Data_16_to_8_data_Deal(adc_convert.type_usba_vbus.adc_code_sl/4);
	//  //           uart_putchar(temp_data_8);//// USBA口电压///
	//              RCR_data_8=RCR_data_8+temp_data_8;
	//             temp_data_16=adc_convert.typea_1.adc_code_sl*5;
	//             temp_data_16=temp_data_16/8;
	//             temp_data_8=Data_16_to_8_data_Deal(temp_data_16);//// C口电流处理////

	//             temp_data1_8=temp_data_8/16;
	//             if(temp_data_8>temp_data1_8)
	//             temp_data_8=temp_data_8-temp_data1_8;//// 10% 电流处理///

	//                  ///////////////////// 只传100ma 单位的电流值/////
	//             if(temp_data_8<=2)
	//             {
	//                temp_data_8=0;
	//             }
	//             else
	//             {
	//                 temp_data1_8=temp_data_8%5;
	//                 temp_data_8=temp_data_8-temp_data1_8;

	//                if(temp_data1_8>=3)
	//                {
	//                  temp_data_8=temp_data_8+5;
	//                }
	//             }

	// //            uart_putchar(temp_data_8);//// USBA口电流///
	//              RCR_data_8=RCR_data_8+temp_data_8;
	// #else
	// //      test_I_data=test_I_data+5;
	// //      if(test_I_data>150)
	// //      test_I_data=5;
	// //
	// //      uart_putchar(200);//// C口电压///
	// //      uart_putchar(temp_data_8);//// C口电流///
	// //      uart_putchar(200);//// USBA口电压///
	// //      uart_putchar(temp_data_8);//// USBA口电流///
	// #endif
	//          }
	//          }
	// //		 uart_putchar(0x55);
	// //         uart_putchar(RCR_data_8);

	// //	     #if __IF_DEBUG__
	// //	       #if Test_TX_data_en
	// //			  Sub_sim_tx(0xC2);
	// //			  Sub_sim_tx(TX_BAT);
	// //			  Sub_sim_tx(TX_STATU);
	// //			  Sub_sim_tx(RCR_data_8);
	// //			  Sub_sim_tx(0xC2);
	// //			  Sub_sim_tx(coulomb_data.output.b_batt_full);
	// //			  Sub_sim_tx(close_lcd_light_cnt); ///close_lcd_light_cnt
	// //		  #endif
	// //		#endif
	//    	  }
	// #endif
}
void pd_firmware_update_cb(void)
{
	GIE = 0;
	APToBoot0 = 0x55;
	APToBoot1 = 0xAA;
	while (1)
		;
}

void Bootcheck_Deal(void)
{
	//  	 M_MEMCPY_ROM2RAM(BANK0, flash_data, flash_address, 1);
	M_MEMCPY_ROM2RAM(BANK0, flash_data, 0x0010, 1);
	if (flash_data[0] == LOADER_PASS)
	{
		Boot_NG_Flage = 0;
	}
	else
		Boot_NG_Flage = 1;
}

void tcpd_debug_cb(uint8_t errno)
{
	// 不需要任何内容
}

void typecx_param_cb(bank1 typec_handle_t *p_h_typec)
{
	// 用于打印typec_state等各种参数
}
void pdsignal_threshold_switch(void)
{
	static uint8_t debounce_cnt = 0;
	//	if(	multi_protocol.input.ibus_cur < 2000)//ibus电流<2a
	if (hex_less_than_compare(multi_protocol.input.ibus_cur, 2000)) // ibus电流<2a
	{
		if (++debounce_cnt >= 10)
		{
			debounce_cnt = 0;
			h_pd.input.src_pd_slow = CTRL_SLOW_3; /*!< SRC,信号边沿斜率 */
			h_pd.input.src_pd_rxvsel = CTRL_RXVSEL_0V68;
			h_pd.input.src_pd_vsel = CTRL_VSEL_1V00;
			fwlib_pd_electric_set(h_pd.input.src_pd_slow, h_pd.input.src_pd_rxvsel, h_pd.input.src_pd_vsel);
		}
	}
	else // ibus电流>=2a
	{
		debounce_cnt = 0;
		h_pd.input.src_pd_slow = CTRL_SLOW_3; /*!< SRC,信号边沿斜率 */
		h_pd.input.src_pd_rxvsel = CTRL_RXVSEL_0V80;
		h_pd.input.src_pd_vsel = CTRL_VSEL_1V20;
		fwlib_pd_electric_set(h_pd.input.src_pd_slow, h_pd.input.src_pd_rxvsel, h_pd.input.src_pd_vsel);
	}
}
