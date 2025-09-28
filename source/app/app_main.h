/***************************************************************************//**
 * @file     app_main.h
 * @version  V1.0.0
 * @author   0531
 * @date     2020-11-21 PM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 ****************************************************************************
 * @attention
 *  硬件平台:  \n
 *  SDK版本： .0.0
 * 
 * @par 修改日志:
 * <table>
 * <tr><th>Date        <th>Version  <th>Author    <th>Description
 * <tr><td>2018/08/17  <td>1.0      <td>0531	  <td>创建初始版本
 * </table>
 *
 *****************************************************************************/

#ifndef __APP_MAIN_H__
#define __APP_MAIN_H__

// Include external header file.
#include "lib_prot_typec.h"

#define Add_data_bank  bank6
#define BANK_Add  	bank3
#define BANK1_Add  	bank1

#define IAP_deal_EN           1//// 0---不位移处理//// 1---- 位移IAP升级处理/////
#define Ap_Include_Bootload   0 /////1--合成底层和AP烧录器烧录设置   0---IAP_AP升级设置
#define K_UARTX_RX_Upgrade    0  //// 使能串口升级处理要配合串口底层 使用////

#define SDWDO_EN            0   /////调试模式使能  1--PT2.5 SWD功能  0--PT2.5 I/O 功能 //////
#define UARTX_EN            0   /////调试模式使能  1--PT3.5 串口功能  0--PT3.5 DP_C功能 //////
/////////////////手动串口处理/////

#define __IF_DEBUG__		0   //1----开启调试用虚拟串口 0---模拟串口失效 PT10
#define  UR_TX_LUNXUN       0 /// 轮询固定时间串口处理///
#define  Test_TX_data_en    0 /// 32P20 串口数据处理///
#define  Bat_Cnt            0 /// 电池充电处理 打印

#define  BAT_showEN         0 //// 1----给华创老化显示用的的 0-----正常生产

#define K_Temp_Protect      1   ///  充放电温度处理
#define K_BAT_Protect       1   ///  充电锂电池保护检测处理
#define Dis_Cur_Pro_en      1   ///  放电温度保护处理
#define Bat_low_Pro_en      0   ///  电池低压保护处理
#define EN_Sleep_EN         0   ///  休眠使能

#define  LOADER_PASS        0x01//// 华艺底层加密值////
#define __DMPM__EN	      	1 	//=1: 开启DMDP功能 PT31 PT32

#define LED_DIS_light_long  0  ////电量灯 放电常亮产线老化使能 1--放电常亮  0--正常出货模式

#define IBUS_Check         1//////SW7201 检测IBUS电流处理/////


#define Frist_normal_do		    	0//// 正常上电处理
#define Frist_Bat_Check_do			1/// 检测电池状态处理
#define Frist_Bat_Protest_do		2///检测到电池保护状态处理
#define Frist_Bat_normal_do	  	    3///检测到电池正常处理

#define OVP_CHARGE_TIME			    10 //// OVP 充电时间
#define OVP_STOP_CHARGE_TIME		5 //// OVP 充电停顿时间

#define C_QC2V_Flag			0
#define C_QC5V_Flag			1
#define C_QC7V_Flag			2
#define C_QC9V_Flag			3
#define C_QC12V_Flag		4
#define C_QC15V_Flag		5
#define C_QC20V_Flag		6
#define C_Vbus2V			25
#define C_Vbus6V			65
#define C_Vbus8V			70
#define C_Vbus10V			105
#define C_Vbus13V			135
#define C_Vbus17V			175

#define C_Vbus_5V_vol_min		176 ///5V 电压上限 5.6V
#define C_Vbus_5V_vol_max		224 ///5V 电压下限
#define C_Vbus_9V_vol_min		336 ///9V 电压上限 9.6V
#define C_Vbus_9V_vol_max		384 ///9V 电压下限
#define C_Vbus_12V_vol_min		456 ///12V 电压上限12.6V
#define C_Vbus_12V_vol_max		504 ///12V 电压下限
#define C_Vbus_15V_vol_min		576 ///15V 电压上限 15.6V
#define C_Vbus_15V_vol_max		624 ///15V 电压下限
#define C_Vbus_20V_vol_min		776 ///20V 电压上限20.6V
#define C_Vbus_20V_vol_max		820 ///20V 电压下限
//#define	PDO_cuurest_MA100	2
//#define	PDO_cuurest_MA200	4
//#define	PDO_cuurest_MA300	6
//#define	PDO_cuurest_MA400	8
//#define	PDO_cuurest_MA500	10
//#define	PDO_cuurest_MA600	12
//#define	PDO_cuurest_MA700	14
//#define	PDO_cuurest_MA800	16
//#define	PDO_cuurest_MA900	18
//#define	PDO_cuurest_MA1000	20
//#define	PDO_cuurest_MA1100	22
//#define	PDO_cuurest_MA1200	24
//#define	PDO_cuurest_MA1300	26
//#define	PDO_cuurest_MA1400	28
//#define	PDO_cuurest_MA1500	30
//#define	PDO_cuurest_MA1600	32
//#define	PDO_cuurest_MA1700	34
//#define	PDO_cuurest_MA1800	36
//#define	PDO_cuurest_MA1900	38
//#define	PDO_cuurest_MA2000	40
//#define	PDO_cuurest_MA2100	42
//#define	PDO_cuurest_MA2200	44
//#define	PDO_cuurest_MA2300	46
//#define	PDO_cuurest_MA2400	48
//#define	PDO_cuurest_MA2500	50
//#define	PDO_cuurest_MA2600	52
//#define	PDO_cuurest_MA2700	54
//#define	PDO_cuurest_MA2800	56
//#define	PDO_cuurest_MA2900	58
//#define	PDO_cuurest_MA3000	60
//#define	PDO_cuurest_MA3100	62
//#define	PDO_cuurest_MA3200	64
//#define	PDO_cuurest_MA3300	66
//#define	PDO_cuurest_MA3400	68
//#define	PDO_cuurest_MA3500	70
//#define	PDO_cuurest_MA3600	72
//#define	PDO_cuurest_MA3700	74
//#define	PDO_cuurest_MA3800	76
//#define	PDO_cuurest_MA3900	78
//#define	PDO_cuurest_MA4000	80

#define	PDO_cuurest_MA500	0
#define	PDO_cuurest_MA600	2
#define	PDO_cuurest_MA700	4
#define	PDO_cuurest_MA800	6
#define	PDO_cuurest_MA900	8
#define	PDO_cuurest_MA1000	10
#define	PDO_cuurest_MA1100	12
#define	PDO_cuurest_MA1200	14
#define	PDO_cuurest_MA1300	16
#define	PDO_cuurest_MA1400	18
#define	PDO_cuurest_MA1500	20
#define	PDO_cuurest_MA1600	22
#define	PDO_cuurest_MA1700	24
#define	PDO_cuurest_MA1800	26
#define	PDO_cuurest_MA1900	28
#define	PDO_cuurest_MA2000	30
#define	PDO_cuurest_MA2100	32
#define	PDO_cuurest_MA2200	34
#define	PDO_cuurest_MA2300	36
#define	PDO_cuurest_MA2400	38
#define	PDO_cuurest_MA2500	40
#define	PDO_cuurest_MA2600	42
#define	PDO_cuurest_MA2700	44
#define	PDO_cuurest_MA2800	46
#define	PDO_cuurest_MA2900	48
#define	PDO_cuurest_MA3000	50
#define	PDO_cuurest_MA3100	52
#define	PDO_cuurest_MA3200	54
#define	PDO_cuurest_MA3300	56
#define	PDO_cuurest_MA3400	58
#define	PDO_cuurest_MA3500	60
#define	PDO_cuurest_MA3600	62
#define	PDO_cuurest_MA3700	64
#define	PDO_cuurest_MA3800	66
#define	PDO_cuurest_MA3900	68
#define	PDO_cuurest_MA4000	70

#define	PDO_cuurest_5V	PDO_cuurest_MA3000 
#define	PDO_cuurest_9V	PDO_cuurest_MA3000 
#define	PDO_cuurest_12V	PDO_cuurest_MA3000 
#define	PDO_cuurest_15V	PDO_cuurest_MA3000 
#define	PDO_cuurest_20V	PDO_cuurest_MA3200   ////45W 参数  PDO 参数

/////C口电流过流参数/////////

//////////0.03R ////////////////
//#define	Port_cuurest_MA5000	295
//#define	Port_cuurest_MA4900	289
//#define	Port_cuurest_MA4800	283
//#define	Port_cuurest_MA4700	277
//#define	Port_cuurest_MA4600	271
//#define	Port_cuurest_MA4500	266
//#define	Port_cuurest_MA4400	260
//#define	Port_cuurest_MA4300	254
//#define	Port_cuurest_MA4200	248
//#define	Port_cuurest_MA4100	242
//#define	Port_cuurest_MA4000	236
//#define	Port_cuurest_MA3900	230
//#define	Port_cuurest_MA3800	224
//#define	Port_cuurest_MA3700	218
//#define	Port_cuurest_MA3600	212
//#define	Port_cuurest_MA3500	207
//#define	Port_cuurest_MA3400	201
//#define	Port_cuurest_MA3300	195
//#define	Port_cuurest_MA3200	189
//#define	Port_cuurest_MA3100	183
//#define	Port_cuurest_MA3000	177
//#define	Port_cuurest_MA2900	171
//#define	Port_cuurest_MA2800	165
//#define	Port_cuurest_MA2700	159
//#define	Port_cuurest_MA2600	153
//#define	Port_cuurest_MA2500	148
//#define	Port_cuurest_MA2400	142
//#define	Port_cuurest_MA2300	136
//#define	Port_cuurest_MA2200	130
//#define	Port_cuurest_MA2100	124
//#define	Port_cuurest_MA2000	118
//#define	Port_cuurest_MA1900	112
//#define	Port_cuurest_MA1800	106
//#define	Port_cuurest_MA1700	100
//#define	Port_cuurest_MA1600	94
//#define	Port_cuurest_MA1500	89
//#define	Port_cuurest_MA1400	83
//#define	Port_cuurest_MA1300	77
//#define	Port_cuurest_MA1200	71
//#define	Port_cuurest_MA1100	65
//#define	Port_cuurest_MA1000	59
//#define	Port_cuurest_MA900	53
//#define	Port_cuurest_MA800	47
//#define	Port_cuurest_MA700	41
//#define	Port_cuurest_MA600	35
//#define	Port_cuurest_MA500	30
//#define	Port_cuurest_MA400	24
//#define	Port_cuurest_MA300	18
//#define	Port_cuurest_MA200	12
//#define	Port_cuurest_MA100	6

//////////0.02R ////////////////
#define	Port_cuurest_MA5000	205 
#define	Port_cuurest_MA4900	201 
#define	Port_cuurest_MA4800	197 
#define	Port_cuurest_MA4700	193 
#define	Port_cuurest_MA4600	188 
#define	Port_cuurest_MA4500	184 
#define	Port_cuurest_MA4400	180 
#define	Port_cuurest_MA4300	176 
#define	Port_cuurest_MA4200	172 
#define	Port_cuurest_MA4100	168 
#define	Port_cuurest_MA4000	164 
#define	Port_cuurest_MA3900	160 
#define	Port_cuurest_MA3800	156 
#define	Port_cuurest_MA3700	152 
#define	Port_cuurest_MA3600	147 
#define	Port_cuurest_MA3500	143 
#define	Port_cuurest_MA3400	139 
#define	Port_cuurest_MA3300	135 
#define	Port_cuurest_MA3200	131 
#define	Port_cuurest_MA3100	127 
#define	Port_cuurest_MA3000	123 
#define	Port_cuurest_MA2900	119 
#define	Port_cuurest_MA2800	115 
#define	Port_cuurest_MA2700	111 
#define	Port_cuurest_MA2600	106 
#define	Port_cuurest_MA2500	102 
#define	Port_cuurest_MA2400	98 
#define	Port_cuurest_MA2300	94 
#define	Port_cuurest_MA2200	90 
#define	Port_cuurest_MA2100	86 
#define	Port_cuurest_MA2000	82 
#define	Port_cuurest_MA1900	78 
#define	Port_cuurest_MA1800	74 
#define	Port_cuurest_MA1700	70 
#define	Port_cuurest_MA1600	66 
#define	Port_cuurest_MA1500	61 
#define	Port_cuurest_MA1400	57 
#define	Port_cuurest_MA1300	53 
#define	Port_cuurest_MA1200	49 
#define	Port_cuurest_MA1100	45 
#define	Port_cuurest_MA1000	41 
#define	Port_cuurest_MA900	37 
#define	Port_cuurest_MA800	33 
#define	Port_cuurest_MA700	29 
#define	Port_cuurest_MA600	25 
#define	Port_cuurest_MA500	20 
#define	Port_cuurest_MA400	16 
#define	Port_cuurest_MA300	12 
#define	Port_cuurest_MA200	8 
#define	Port_cuurest_MA100	4 


//////////A口电流过流参数//////
//// 0.03R ///////////////
//#define	Port_USBA_MA5000	614 
//#define	Port_USBA_MA4900	602 
//#define	Port_USBA_MA4800	590 
//#define	Port_USBA_MA4700	578 
//#define	Port_USBA_MA4600	565 
//#define	Port_USBA_MA4500	553 
//#define	Port_USBA_MA4400	541 
//#define	Port_USBA_MA4300	528 
//#define	Port_USBA_MA4200	516 
//#define	Port_USBA_MA4100	504 
//#define	Port_USBA_MA4000	492 
//#define	Port_USBA_MA3900	479 
//#define	Port_USBA_MA3800	467 
//#define	Port_USBA_MA3700	455 
//#define	Port_USBA_MA3600	442 
//#define	Port_USBA_MA3500	430 
//#define	Port_USBA_MA3400	418 
//#define	Port_USBA_MA3300	406 
//#define	Port_USBA_MA3200	393 
//#define	Port_USBA_MA3100	381 
//#define	Port_USBA_MA3000	369 
//#define	Port_USBA_MA2900	356 
//#define	Port_USBA_MA2800	344 
//#define	Port_USBA_MA2700	332 
//#define	Port_USBA_MA2600	319 
//#define	Port_USBA_MA2500	307 
//#define	Port_USBA_MA2400	295 
//#define	Port_USBA_MA2300	283 
//#define	Port_USBA_MA2200	270 
//#define	Port_USBA_MA2100	258 
//#define	Port_USBA_MA2000	246 
//#define	Port_USBA_MA1900	233 
//#define	Port_USBA_MA1800	221 
//#define	Port_USBA_MA1700	209 
//#define	Port_USBA_MA1600	197 
//#define	Port_USBA_MA1500	184 
//#define	Port_USBA_MA1400	172 
//#define	Port_USBA_MA1300	160 
//#define	Port_USBA_MA1200	147 
//#define	Port_USBA_MA1100	135 
//#define	Port_USBA_MA1000	123 
//#define	Port_USBA_MA900	111 
//#define	Port_USBA_MA800	98 
//#define	Port_USBA_MA700	86 
//#define	Port_USBA_MA600	74 
//#define	Port_USBA_MA500	61 
//#define	Port_USBA_MA400	49 
//#define	Port_USBA_MA300	37 
//#define	Port_USBA_MA200	25 
//#define	Port_USBA_MA100	12
 
////////////0.02R //////////////////
#define	Port_USBA_MA5000	410 
#define	Port_USBA_MA4900	401 
#define	Port_USBA_MA4800	393 
#define	Port_USBA_MA4700	385 
#define	Port_USBA_MA4600	377 
#define	Port_USBA_MA4500	369 
#define	Port_USBA_MA4400	360 
#define	Port_USBA_MA4300	352 
#define	Port_USBA_MA4200	344 
#define	Port_USBA_MA4100	336 
#define	Port_USBA_MA4000	328 
#define	Port_USBA_MA3900	319 
#define	Port_USBA_MA3800	311 
#define	Port_USBA_MA3700	303 
#define	Port_USBA_MA3600	295 
#define	Port_USBA_MA3500	287 
#define	Port_USBA_MA3400	279 
#define	Port_USBA_MA3300	270 
#define	Port_USBA_MA3200	262 
#define	Port_USBA_MA3100	254 
#define	Port_USBA_MA3000	246 
#define	Port_USBA_MA2900	238 
#define	Port_USBA_MA2800	229 
#define	Port_USBA_MA2700	221 
#define	Port_USBA_MA2600	213 
#define	Port_USBA_MA2500	205 
#define	Port_USBA_MA2400	197 
#define	Port_USBA_MA2300	188 
#define	Port_USBA_MA2200	180 
#define	Port_USBA_MA2100	172 
#define	Port_USBA_MA2000	164 
#define	Port_USBA_MA1900	156 
#define	Port_USBA_MA1800	147 
#define	Port_USBA_MA1700	139 
#define	Port_USBA_MA1600	131 
#define	Port_USBA_MA1500	123 
#define	Port_USBA_MA1400	115 
#define	Port_USBA_MA1300	106 
#define	Port_USBA_MA1200	98 
#define	Port_USBA_MA1100	90 
#define	Port_USBA_MA1000	82 
#define	Port_USBA_MA900  	74 
#define	Port_USBA_MA800 	66 
#define	Port_USBA_MA700 	57 
#define	Port_USBA_MA600 	49 
#define	Port_USBA_MA500 	41 
#define	Port_USBA_MA400 	33 
#define	Port_USBA_MA300 	25 
#define	Port_USBA_MA200 	16 
#define	Port_USBA_MA100 	8 
/////////////////////////////////////////////////////////////////


#define	BAT_Full_cuurest	Port_cuurest_MA300//////  300ma 

//#define TCA_5V_Pro_current      Port_cuurest_MA3400
//#define TCA_9V_Pro_current      Port_cuurest_MA3400
//#define TCA_12V_Pro_current     Port_cuurest_MA3400
//#define TCA_15V_Pro_current     Port_cuurest_MA3400
//#define TCA_20V_Pro_current     Port_cuurest_MA3400/// CA口 PD 45W 参数  2.8A 过流 ////45W 参数  过电流参数
//#define TCA_20V_Pro_current_EMACK     Port_cuurest_MA3600/// CA口 PD 45W 参数  2.8A 过流 ////45W 参数  过电流参数
//#define TCA_20V_Pro_current_45W  Port_cuurest_MA2800

#define TCA_5V_Pro_current      Port_cuurest_MA3500/// 6-24 普通线 增加100ma 5A线增加200ma 
#define TCA_9V_Pro_current      Port_cuurest_MA3500
#define TCA_12V_Pro_current     Port_cuurest_MA3500
#define TCA_15V_Pro_current     Port_cuurest_MA3500
#define TCA_20V_Pro_current     Port_cuurest_MA3500/// CA口 PD 45W 参数  2.8A 过流 ////45W 参数  过电流参数
#define TCA_20V_Pro_current_EMACK     Port_cuurest_MA3800/// CA口 PD 45W 参数  2.8A 过流 ////45W 参数  过电流参数
#define TCA_20V_Pro_current_45W  Port_cuurest_MA3000

#define TCA_9V_Pro_current_18W      Port_cuurest_MA3800
#define TCA_12V_Pro_current_18W     Port_cuurest_MA3400
#define TCA_15V_Pro_current_18W     Port_cuurest_MA2800
#define TCA_20V_Pro_current_18W     Port_cuurest_MA2300/// CA口 PD 降功率30 W 参数  过电流参数

//////////USBA 口处理///////////////
#define TAA_5V_Pro_current      Port_USBA_MA3600  ////USBA1口端口过流
//#define TAA_9V_Pro_current      Port_USBA_MA2300
//#define TAA_12V_Pro_current     Port_USBA_MA1800
//
#define TAA_9V_Pro_current      Port_USBA_MA3000
#define TAA_12V_Pro_current     Port_USBA_MA3000

//#define TAA_5V_Pro_current      442  ////USBA1口端口过流
//#define TAA_9V_Pro_current      330
//#define TAA_12V_Pro_current     246

//#define TAA2_5V_Pro_current      430  //// 改成无线充端口过流
////#define TAA2_9V_Pro_current      307
//#define TAA2_9V_Pro_current      330
//#define TAA2_12V_Pro_current     246

#define Err_5_time     1 ///报警闪5次
#define Err_4_time     2 // 电池低电压报警
#define Err_3_time     3 //NTC 高温保护 低温保护
#define Err_2_time     4 //NTC 没有接

//#define displaytime  28 //// 关灯时间 28S
#define displaytime    31 //// 关灯时间 30S  5-16///修改灭灯时间////

#ifdef __cplusplus
extern "C" {
#endif

#define CFG_PD_DISABLE			0

//#define MCU_TX_PIN     PT15
//#define MCU_TX_PIN_EN  PT1EN5
//#define MCU_TX_PIN_UP  PT1PU5
//
//#define MCU_TX_PIN_OUT {MCU_TX_PIN_EN=1;}
//#define MCU_TX_PIN_IN  {MCU_TX_PIN_EN=0;}
//#define MCU_TX_PIN_H   {MCU_TX_PIN_EN=1;MCU_TX_PIN=1;}
//#define MCU_TX_PIN_L   {MCU_TX_PIN_EN=1;MCU_TX_PIN=0;}

//#define  one_H  2  //// 400低电平 400高电平
//#define  one_L  2
//
//#define  zro_H  1  //// 200低电平 200高电平
//#define  zro_L  1

#define  one_H  4  //// 400低电平 400高电平
#define  one_L  4

#define  zro_H  2  //// 200低电平 200高电平
#define  zro_L  2



#define  Car_statu_PIN  PT11
#define  Car_statu_PIN_EN  PT1EN1
#define  Car_statu_PIN_MODE_IN Car_statu_PIN_EN=0;

#define  Rxdate  PT11

#define  Car_Out_PIN  PT16
#define  Car_Out_PIN_EN  PT1EN6
#define  Car_Out_PIN_H  { Car_Out_PIN_EN=1;Car_Out_PIN=1;}
#define  Car_Out_PIN_L  { Car_Out_PIN_EN=1;Car_Out_PIN=0;}

//#define SYS_VBUS_V38  152///170 
//#define SYS_VBUS_V60  240 //260
//
//#define SYS_VBUS_V78   312 //330
//#define SYS_VBUS_V102  408//430
//
//#define SYS_VBUS_V105  420 ///450
//#define SYS_VBUS_V135  540//580
//
//#define SYS_VBUS_V140 560//600
//#define SYS_VBUS_V165 660//717
//
//#define SYS_VBUS_V185   740///800
//#define SYS_VBUS_V220   880////956
//
//#define SYS_VBUS_V128   512///800
#define Vinreg_V45 0x05 
//#define Vinreg_V78 0x05;
#define CC_PIN_V_ADC 250 

//#define Car_in_number 0x30 ////  126夹子协议
//#define Car_in_number 0x31
#define Car_in_number 0x33 


#define  J_out_icon_Flash 0x0008
#define  J_car_icon_Flash 0x0004 
#define  J_in_icon_Flash  0x0002

#define  TFT_Clear_Statu   0
#define  TFT_Star_Statu    1
#define  TFT_Char_Dis_Statu     2
#define  TFT_Car_Statu     3
#define  TFT_Error_Statu   4

#define  TFT_Char_Dis_icon_no_inandout         0
#define  TFT_Char_Dis_icon_USBA_out            1
#define  TFT_Char_Dis_icon_TypeC_out           2
#define  TFT_Char_Dis_icon_TypeC_USBA_out      3
#define  TFT_Char_Dis_icon_TypeC_in            4

#define  TFT_Car_icon_Clamp_Cables            0
#define  TFT_Car_icon_Ready                   1
#define  TFT_Car_icon_Jump_Start              2
#define  TFT_Car_icon_Unplug                  3

#define  TFT_Error_icon_Charge_Above50        0
#define  TFT_Error_icon_Overheated            1
#define  TFT_Error_icon_Wrong_Connection      2
#define  TFT_Error_icon_Abnormal_Voltage      3
#define  TFT_Error_icon_Time_Out              4
#define  TFT_Error_icon_Short_Circuit         5
#define  TFT_Error_icon_Connection_Failure    6

#if !CFG_PD_DISABLE
#endif

typedef struct
{
#if CFG_SIMP_BITFIELD
	uint8_t timer_1ms;
	uint8_t timer_10ms;
#else
	uint8_t timer_1ms	: 1;
	uint8_t timer_10ms	: 1;
#endif
}sys_flag_t;

typedef struct
{
	uint8_t cnt_10ms;
	uint8_t cnt_100ms;
	uint8_t cnt_1s;
	uint32_t time_ruler;
}sys_timer_t;


typedef volatile struct
{
	unsigned char data_count;
	unsigned char frame_cs_calculate;
	unsigned char jump_flag;
}iap_detect_t;


extern uint16_t I_ChargePWM_PWM_Be;
extern uint16_t I_ChargePWM_PWM;
extern uint8_t VoltFlag;
extern uint8_t R_ChargeCur_DataBuff;
extern uint8_t R_ChargeCur_PDData;
extern uint8_t R_ChargeCur_Data;
extern uint8_t LedData_OK;
extern uint8_t BatCap_Value;
extern uint8_t BatCap_Value_Be;
extern uint8_t Charge_Start;
extern uint8_t Power_Value_Update;
extern uint8_t PD_curr_Pro_cnt;
extern uint8_t USBA_curr_Pro_cnt;
extern uint8_t USBA2_curr_Pro_cnt;
extern uint8_t UTX_8_data1;
//extern uint8_t UTX_8_data2;
extern uint16_t  UTX_8_data2;
extern uint16_t UTX_16_data1;
extern uint16_t UTX_16_data2;
extern uint16_t VBAT_7201_Vaule;
extern uint16_t VBUS_out;
extern uint16_t VBUS_out_Be;
extern uint8_t discharge_displed;
extern uint8_t Fast_Show_cnt;
extern uint8_t Sleep_up_flage;

extern uint8_t Time_1ms_cnt;
extern uint8_t Time_10ms_cnt;
extern uint8_t Time_100ms_cnt;
extern uint8_t Time_1000ms_cnt;
extern uint8_t Time_1500ms_cnt;
extern uint8_t charge_and_discharge_do;
extern uint8_t WR_5V9V_out_in;/////无线充输出5V 或9V 标志位////

extern bank0  uint8_t  flash_data[2];



extern BANK1_Add unsigned int TX_time_change;/// 数据表更
extern BANK1_Add unsigned char TX_START;//// 开始发送数据
extern BANK1_Add unsigned int TX_data_temp;/// 发送数据3
extern BANK1_Add unsigned char TX_bit_H_time_cnt;
extern BANK1_Add unsigned char TX_bit_L_time_cnt;
extern BANK1_Add unsigned int TX_data1;/// 发送数据1
extern BANK1_Add unsigned int TX_data2;/// 发送数据2
extern BANK1_Add unsigned char TX_date_done;
extern BANK1_Add unsigned char TX_bit_vaule;/// 发送的位数值
extern BANK1_Add unsigned char TX_bit_time_cnt;
extern BANK1_Add unsigned char TX_bit_cnt;/// 发送数据位  32位就是完成
extern BANK1_Add unsigned int TX_all_data_statu;
//////////////////////
extern BANK_Add unsigned char TCB_EN_ON;//// 开B口充电开关///// 7
extern BANK_Add unsigned char TCA_EN_ON;//// 开TCA口充电开关/////6
extern BANK_Add unsigned char WHITE_ON;//// 开白灯/////           5
extern BANK_Add unsigned char RED_ON;//// 开红灯/////              4
extern BANK_Add unsigned char USBA_EN_ON;//// 开USBA口放电电开关///// 3
extern BANK_Add unsigned char USBA2_EN_ON;//// 开USBA口放电电开关/////2
extern BANK_Add unsigned char CHARING_ON;////开充电脚位充电开关/////1
extern BANK_Add unsigned char OTG_ON;//// 开OTG开关/////            0

extern BANK_Add unsigned char SOS_LEVEL;////0-常亮 1--频闪 2-SOS
extern BANK_Add unsigned char CAR_LEVEL;/////汽车点火 形势 0-无连接  1-连接 2--Ready star 3-Successful jump
extern BANK_Add unsigned char LED_STATU;// /// 0-放电或待机 1-充电 
extern BANK_Add unsigned char LED_LEVEL;///电池电压电量等级 0--LED不显示 1 0-5%以下 2-5-25%以下 3-25-50% 以下4-50-75% 以下 5-75-100% 6-充满 7-报警

////////////
extern BANK_Add uint8_t count_tx_car;   ////
extern BANK_Add uint8_t count_8;////
extern BANK_Add uint8_t TX_Car_number;////

extern BANK_Add uint8_t f_err_ot; ///
extern BANK_Add uint8_t f_ph_del;  ////
extern BANK_Add uint8_t f_car_his;   /////
extern BANK_Add uint16_t count_car_remove;  ////
extern BANK_Add uint8_t count_car_jump;  ////
extern BANK_Add uint8_t data_car_jump;  ////
extern BANK_Add uint8_t Temp_car_ST;  ////
extern BANK_Add uint8_t count_jump;/////
extern BANK_Add uint8_t f_car_jump;  //////
extern BANK_Add uint8_t car_ST;/////
extern BANK_Add uint8_t count_clr_time;////
extern BANK_Add uint8_t time_noload; ////
extern BANK_Add uint8_t count_0s5;/////
extern BANK_Add uint8_t f_ph_del_time;////
extern BANK_Add uint8_t f_jump_start;////
extern BANK_Add uint8_t count_2ms;///
extern BANK_Add uint8_t count_65ms;///
/////////////
extern BANK_Add uint8_t Charge_cnt_do;///
extern BANK_Add uint8_t Charge_get_cnt;///

extern BANK_Add uint8_t sink_Vol;
extern BANK_Add uint8_t sink_Vol1;
extern BANK_Add uint8_t bat_low_pwm_do;
extern BANK_Add uint8_t bat_low_pwm_Cnt;

extern BANK_Add uint8_t bat_full_pwm_Cnt;
extern BANK_Add uint8_t bat_full_pwm_do;


extern BANK_Add uint8_t bat_full_8hour_Cnt;
extern BANK_Add uint16_t bat_full_1hour_Cnt;
extern BANK_Add uint8_t bat_full_do_to_charge;
extern BANK_Add uint8_t Sleep_up_shor_do;
extern BANK_Add uint8_t Sleep_up_close_Car_ignition;
extern BANK_Add uint8_t charge_to_sleep_close_Car_ignition;

extern BANK_Add uint8_t VBUS_V_Hight;
extern BANK_Add uint8_t VBUS_V_Low;
extern BANK_Add uint16_t VBUS_OVP_CNT;
extern BANK_Add uint16_t VBUS_USBA_OVP_CNT;

extern BANK_Add uint8_t Into_IAP_Flage;
extern BANK_Add uint8_t USBA_VoltFlag;

extern BANK_Add iap_detect_t iap_detect;

extern BANK_Add uint8_t request_num_copy;

extern BANK_Add uint8_t Recharge_cnt;

extern BANK_Add uint8_t TYPE_CA_18W_Flage;
extern BANK_Add uint8_t TYPE_CA_18W_Flage_Cnt;

extern BANK_Add uint8_t Time_2_Flage_do;

extern BANK_Add uint8_t SYS_in_Sleep_F;
extern BANK_Add uint8_t Foece_Sleep_F;

extern BANK_Add uint8_t Foece_Sleep_Time_S;
extern BANK_Add uint16_t Foece_Sleep_Time_Min;
extern BANK_Add uint8_t Foece_Sleep_Time_Mon;

extern BANK_Add uint16_t Exit_Charge_Cnt;

extern BANK_Add uint8_t CC1_LEVEL_NOW;
extern BANK_Add uint8_t CC1_LEVEL_BE;
extern BANK_Add uint8_t CC2_LEVEL_NOW;
extern BANK_Add uint8_t CC2_LEVEL_BE;
extern BANK_Add uint8_t CC_Check_Cnt;
extern BANK_Add uint8_t CC1_Check1_Cnt;
extern BANK_Add uint8_t CC1_Check2_Cnt;
extern BANK_Add uint8_t CC2_Check1_Cnt;
extern BANK_Add uint8_t CC2_Check2_Cnt;
extern BANK_Add uint16_t TypeC_MicroB_ADC_data;


extern BANK_Add uint16_t TypeC_Slide_CC1_data;
extern BANK_Add uint16_t TypeC_Slide_CC2_data;

extern BANK_Add uint16_t TypeC_VNOW_out_value;
extern BANK_Add uint16_t TypeC_VBE_out_value;

extern BANK_Add uint8_t Out_Protest_Flage;


extern BANK_Add uint8_t Charge_OCP_Flage;
extern BANK_Add uint8_t Charge_OCP_cnt;
//extern BANK_Add uint8_t SYS_100ms_date;
//extern BANK_Add uint8_t SYS_1s_date;
//extern BANK_Add uint8_t Charge_Close_En_Flage;
extern BANK_Add uint8_t Charge_Close_En_cnt;

extern BANK_Add uint8_t Charge_BEN_cnt;

extern BANK_Add uint8_t Vbat_8_date;
extern BANK_Add uint8_t VBUS_8_date;
extern BANK_Add uint8_t VBUS_USBA_8_date;

extern BANK_Add uint8_t SW7203_Data_Cnt;
extern BANK_Add uint8_t CIbat_8_date;
extern bank2 uint8_t  CIbus_8_date;
extern bank2 uint16_t CIbus_16_date;

extern BANK_Add uint8_t AIbat_8_date;
extern BANK_Add uint8_t LIbat_8_date;
extern BANK_Add uint16_t Type_C_Ibat_16_date;
extern BANK_Add uint8_t Car_Cur_data;////  

extern BANK_Add uint8_t f_RX_statu;//// 当前状态///
extern BANK_Add uint8_t f_B_RX_statu;/// 前一次状态
extern BANK_Add uint8_t f_B2_RX_statu;///前前状态

extern BANK_Add uint8_t f_Rx_do_star;///收到下降沿开始接收数据处理////
extern BANK_Add uint8_t Date_bit_cnt;///收到数据第几位/// 
extern BANK_Add uint8_t Time_date_L_cnt;/// 接收数据延时计数///
extern BANK_Add uint8_t Vule_Rx_date;/// 接收数据位移存储///
// extern BANK_Add uint8_t date1_Cnt; ///  
// extern BANK_Add uint8_t date2_Cnt;///  
// extern BANK_Add uint8_t Rx_8date1;/// 接收数据1
// extern BANK_Add uint8_t Rx_8date2;/// 接收数据2
// extern BANK_Add uint8_t Rx_8date3;/// 接收数据3
extern BANK_Add uint8_t f_RX_date_done;/// 接收数据完成标志
extern BANK_Add uint8_t Rx_huo;

extern BANK_Add uint8_t USBA_EN_BK;
extern BANK_Add uint8_t Flash_bat_Vol_Start_check;

//extern BANK_Add uint8_t Bat_Car_Protect_Flage;
extern BANK_Add uint8_t Bat_Car_Protect_Cnt;

extern BANK_Add uint8_t test_data8_1;
extern BANK_Add uint8_t UP_data_2402_Flage;
extern BANK_Add uint8_t BAT_Pro_Charge;
extern BANK_Add uint8_t Sleep_Down_Close_Power;
extern BANK_Add uint8_t Boot_NG_Flage;

//extern BANK_Add uint8_t key_down_5S_Flage;
//extern BANK_Add uint16_t key_down_5S_Cnt;
extern BANK_Add uint16_t Bat_Low_5V_CNt;
extern BANK_Add uint8_t  Bat_Low_5V_NG_Flage;
extern BANK_Add uint16_t UTX_16_data3;

extern Add_data_bank uint8_t LED_test_mode_Cnt;
extern Add_data_bank uint8_t LED_test_mode_Cnt2;

extern Add_data_bank uint8_t uart_t_count;

extern Add_data_bank uint8_t Languagee_C_Flag;

extern Add_data_bank uint8_t  LongKeyFlagtocallword;
extern Add_data_bank uint8_t  marked_word_showtime;
extern Add_data_bank uint8_t  marked_word_cnt;

extern Add_data_bank uint8_t  F_gotodec_levl;
extern Add_data_bank uint8_t Gotodec_levl_cnt;

extern Add_data_bank uint8_t  DubbleKeyFlag;  //DubbleKey2Flag
extern Add_data_bank uint8_t  DubbleKey2Flag; 
//extern Add_data_bank  statusKeyFlag;

extern Add_data_bank uint8_t  open_lcd_light; 
extern Add_data_bank uint8_t  Temp_Language;

extern Add_data_bank uint8_t TFT_maid_mode;
extern Add_data_bank uint8_t TFT_minor_mode;
extern Add_data_bank uint8_t Star_Cartoon;
extern Add_data_bank uint8_t Error_icon_Cnt;
extern Add_data_bank uint8_t Error_icon_Mode;

extern Add_data_bank uint8_t USBA_in_Flage;
extern Add_data_bank uint8_t USBA_in_Cnt;

extern Add_data_bank uint8_t BAT_VAULE_TEST;
extern Add_data_bank uint8_t BAT_VAULE_TEST_Cnt;

extern Add_data_bank uint8_t TYPE_C_Waittime_Cnt;
extern Add_data_bank uint8_t test_I_data;

extern Add_data_bank uint16_t close_lcd_light_cnt;

extern Add_data_bank uint8_t Change_lauge_Cnt;
extern Add_data_bank uint8_t Change_lauge_Flage;
extern Add_data_bank uint8_t Change_lauge_Time_Cnt;

extern sys_flag_t	sys_flag;
extern sys_timer_t	sys_timer;
extern BANK_Add uint8_t USBA_sleep_up;

extern uint8_t Flag;


//---------------------------------------------
// extern uint8_t uart_rx_data[10];
// extern uint8_t uart_rx_data_cnt;
// extern bool uart_rx_data_flag;
//---------------------------------------------



void delay_ms(uint32_t _ms);
void pd_firmware_update_cb(void);
void Bootcheck_Deal(void);

void pdsignal_threshold_switch(void);

#ifdef __cplusplus
}
#endif
#endif  //__APP_MAIN_H__
/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/
