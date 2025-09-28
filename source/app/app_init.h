
#ifndef _INIT_H
#define _INIT_H

#include "app_main.h"

#define	CFG_PDO_PPS_SUPPORT			(1)

#if(CFG_PDO_PPS_SUPPORT)
	#define PDO_SOURCECAP_COUNT		5
//	#define PDO_SOURCECAP_COUNT		7
#else
//	#define PDO_SOURCECAP_COUNT		3
#endif


//#define PDO_SOURCECAP_PPS_POS		4
#define PDO_SOURCECAP_PPS_POS		6


/** 输出低功率 固定档位 30W**/
#define PDO_SRC_VOL_L0				(5000ul)
#define PDO_SRC_VOL_L1				(9000ul)
#define PDO_SRC_VOL_L2				(12000ul)
#define PDO_SRC_VOL_L3				(15000ul)
#define PDO_SRC_VOL_L4				(20000ul)

#define PDO_SRC_CURR_L0				(3000ul)
#define PDO_SRC_CURR_L1				(3000ul)
#define PDO_SRC_CURR_L2				(2500ul)
#define PDO_SRC_CURR_L3				(2000ul)
#define PDO_SRC_CURR_L4				(1500ul)
/** 输出低功率 PPS档位 18W**/
#define APDO_SRC_VOL_L0_H			(6000ul) 
#define APDO_SRC_VOL_L0_L			(3300ul)

#define APDO_SRC_CURR_L0			(3000ul)

////60W
#define PDO_SOURCECAP_H0			((0x280ul << 20) + ( 5000ul/50 << 10) + ( 3000ul/10))		// 5V/2.40A
#define PDO_SOURCECAP_H1			((0x000ul << 20) + ( 9000ul/50 << 10) + ( 3000ul/10))		// 9V/3.00A
#define PDO_SOURCECAP_H2			((0x000ul << 20) + (12000ul/50 << 10) + ( 3000ul/10))		//12V/3.00A
#define PDO_SOURCECAP_H3			((0x000ul << 20) + (15000ul/50 << 10) + ( 3000ul/10))		//15V/3.00A
#define PDO_SOURCECAP_H4			((0x000ul << 20) + (20000ul/50 << 10) + ( 3250ul/10))		//20V/3.00A

#define PDO_SOURCECAP_H4L			((0x000ul << 20) + (20000ul/50 << 10) + ( 2250ul/10))		//20V/2.25A

#define PDO_SOURCECAP_PPS1			(( 0x60ul << 25) + ( 6000ul/100 << 17) + (3300ul/100 << 8) + 3000ul/50)		//3.3V~ 6.0V
#define PDO_SOURCECAP_PPS2			(( 0x60ul << 25) + (11000ul/100 << 17) + (3300ul/100 << 8) + 3000ul/50)		//3.3V~11.0V

//45w
#define PDO_SOURCECAP_H0_1			((0x280ul << 20) + ( 5000ul/50 << 10) + ( 3000ul/10))		// 5V/2.40A
#define PDO_SOURCECAP_H1_1			((0x000ul << 20) + ( 9000ul/50 << 10) + ( 3000ul/10))		// 9V/3.00A
#define PDO_SOURCECAP_H2_1			((0x000ul << 20) + (12000ul/50 << 10) + ( 3000ul/10))		//12V/3.00A
#define PDO_SOURCECAP_H3_1			((0x000ul << 20) + (15000ul/50 << 10) + ( 3000ul/10))		//15V/3.00A
#define PDO_SOURCECAP_H4_1			((0x000ul << 20) + (20000ul/50 << 10) + ( 2250ul/10))		//20V/3.00A

#define PDO_SOURCECAP_H4L_1			((0x000ul << 20) + (20000ul/50 << 10) + ( 1250ul/10))		//20V/2.25A

#define PDO_SOURCECAP_PPS1_1			(( 0x60ul << 25) + ( 6000ul/100 << 17) + (3300ul/100 << 8) + 3000ul/50)		//3.3V~ 6.0V
#define PDO_SOURCECAP_PPS2_1			(( 0x60ul << 25) + (11000ul/100 << 17) + (3300ul/100 << 8) + 3000ul/50)		//3.3V~11.0V

//30w
#define PDO_SOURCECAP_H0_2			((0x280ul << 20) + ( 5000ul/50 << 10) + ( 3000ul/10))		// 5V/2.40A
#define PDO_SOURCECAP_H1_2			((0x000ul << 20) + ( 9000ul/50 << 10) + ( 3000ul/10))		// 9V/3.00A
#define PDO_SOURCECAP_H2_2			((0x000ul << 20) + (12000ul/50 << 10) + ( 2500ul/10))		//12V/3.00A
#define PDO_SOURCECAP_H3_2			((0x000ul << 20) + (15000ul/50 << 10) + ( 2000ul/10))		//15V/3.00A
#define PDO_SOURCECAP_H4_2			((0x000ul << 20) + (20000ul/50 << 10) + ( 1500ul/10))		//20V/3.00A

#define PDO_SOURCECAP_H4L_2			((0x000ul << 20) + (20000ul/50 << 10) + (  500ul/10))		//20V/2.25A

#define PDO_SOURCECAP_PPS1_2			(( 0x60ul << 25) + ( 6000ul/100 << 17) + (3300ul/100 << 8) + 3000ul/50)		//3.3V~ 6.0V
#define PDO_SOURCECAP_PPS2_2			(( 0x60ul << 25) + (11000ul/100 << 17) + (3300ul/100 << 8) + 3000ul/50)		//3.3V~11.0V

//18w
#define PDO_SOURCECAP_H0_3			((0x280ul << 20) + ( 5000ul/50 << 10) + ( 3000ul/10))		// 5V/2.40A
#define PDO_SOURCECAP_H1_3			((0x000ul << 20) + ( 9000ul/50 << 10) + ( 2000ul/10))		// 9V/3.00A
#define PDO_SOURCECAP_H2_3			((0x000ul << 20) + (12000ul/50 << 10) + ( 1500ul/10))		//12V/3.00A
#define PDO_SOURCECAP_H3_3			((0x000ul << 20) + (15000ul/50 << 10) + ( 1200ul/10))		//15V/3.00A
#define PDO_SOURCECAP_H4_3			((0x000ul << 20) + (20000ul/50 << 10) + (  900ul/10))		//20V/3.00A

#define PDO_SOURCECAP_H4L_3			((0x000ul << 20) + (20000ul/50 << 10) + (  500ul/10))		//20V/2.25A

#define PDO_SOURCECAP_PPS1_3			(( 0x60ul << 25) + ( 6000ul/100 << 17) + (3300ul/100 << 8) + 3000ul/50)		//3.3V~ 6.0V
#define PDO_SOURCECAP_PPS2_3			(( 0x60ul << 25) + (11000ul/100 << 17) + (3300ul/100 << 8) + 3000ul/50)		//3.3V~11.0V



//#define PDO_SOURCECAP_COUNT_L					(3)/////18W处理
///** 低功率档位 Source Cap**/
//#define PDO_SOURCECAP_L0			((0x280ul<< 20)+ ((PDO_SRC_VOL_L0/ 50)<< 10)+ (PDO_SRC_CURR_L0/ 10))
//#define PDO_SOURCECAP_L1			((0x000ul<< 20)+ ((PDO_SRC_VOL_L1/ 50)<< 10)+ (PDO_SRC_CURR_L1/ 10))
//#define PDO_SOURCECAP_L2			((0x000ul<< 20)+ ((PDO_SRC_VOL_L2/ 50)<< 10)+ (PDO_SRC_CURR_L2/ 10))
//#define PDO_SOURCECAP_PPS_L0		(( 0x60ul<< 25)+ ((APDO_SRC_VOL_L0_H/ 100)<< 17)+ (APDO_SRC_VOL_L0_L/ 100<< 8)+ APDO_SRC_CURR_L0/ 50)

#define PDO_SOURCECAP_COUNT_L					(5)//////30W 处理
/** 低功率档位 Source Cap**/
#define PDO_SOURCECAP_L0			((0x280ul<< 20)+ ((PDO_SRC_VOL_L0/ 50)<< 10)+ (PDO_SRC_CURR_L0/ 10))
#define PDO_SOURCECAP_L1			((0x000ul<< 20)+ ((PDO_SRC_VOL_L1/ 50)<< 10)+ (PDO_SRC_CURR_L1/ 10))
#define PDO_SOURCECAP_L2			((0x000ul<< 20)+ ((PDO_SRC_VOL_L2/ 50)<< 10)+ (PDO_SRC_CURR_L2/ 10))
#define PDO_SOURCECAP_L3			((0x000ul<< 20)+ ((PDO_SRC_VOL_L3/ 50)<< 10)+ (PDO_SRC_CURR_L3/ 10))
#define PDO_SOURCECAP_L4			((0x000ul<< 20)+ ((PDO_SRC_VOL_L4/ 50)<< 10)+ (PDO_SRC_CURR_L4/ 10))
#define PDO_SOURCECAP_PPS_L0		(( 0x60ul<< 25)+ ((APDO_SRC_VOL_L0_H/ 100)<< 17)+ (APDO_SRC_VOL_L0_L/ 100<< 8)+ APDO_SRC_CURR_L0/ 50)



#define PDO_SINKCAP_COUNT			2
//输入60W////
#define PDO_SINKCAP_H0				((0x380ul << 20) + ( 5000ul/50 << 10) + ( 3000ul/10))		// 5V/3.00A
#define PDO_SINKCAP_H1				((0x000ul << 20) + (20000ul/50 << 10) + ( 3000ul/10))		// 20V/3A

#define PDO_SINKCAP1_H0				((0x380ul << 20) + ( 5000ul/50 << 10) + ( 3000ul/10))		// 5V/3.00A
#define PDO_SINKCAP1_H1 			((0x000ul << 20) + (9000ul/50 << 10) + ( 3000ul/10))		// 20V/3.0A

#define PDO_SINKCAP_H2				((0x000ul << 20) + (12000ul/50 << 10) + ( 1500ul/10))		//12V/1.50A
#define PDO_SINKCAP_H3				((0x000ul << 20) + (15000ul/50 << 10) + ( 2000ul/10))		//15V/2.00A


//输入45W////
#define PDO_SINKCAP_H0_1				((0x380ul << 20) + ( 5000ul/50 << 10) + ( 3000ul/10))		// 5V/3.00A
#define PDO_SINKCAP_H1_1				((0x000ul << 20) + (20000ul/50 << 10) + ( 2250ul/10))		// 20V/3A

//输入30W////_1
#define PDO_SINKCAP_H0_2				((0x380ul << 20) + ( 5000ul/50 << 10) + ( 3000ul/10))		// 5V/3.00A
#define PDO_SINKCAP_H1_2				((0x000ul << 20) + (20000ul/50 << 10) + ( 1500ul/10))		// 20V/3A

//输入18W////_1
#define PDO_SINKCAP_H0_3				((0x380ul << 20) + ( 5000ul/50 << 10) + ( 3000ul/10))		// 5V/3.00A
#define PDO_SINKCAP_H1_3				((0x000ul << 20) + (20000ul/50 << 10) + (  900ul/10))		// 20V/3A


/** 输出高功率 固定档位 45W**/
#define PDO_SRC_VOL_H0				(5000ul)
#define PDO_SRC_VOL_H1				(9000ul)
#define PDO_SRC_VOL_H2				(12000ul)
#define PDO_SRC_VOL_H3				(15000ul)
#define PDO_SRC_VOL_H4				(20000ul)

#define PDO_SRC_CURR_H0				(3000ul)
#define PDO_SRC_CURR_H1				(3000ul)
#define PDO_SRC_CURR_H2				(3000ul)
#define PDO_SRC_CURR_H3				(3000ul)
#define PDO_SRC_CURR_H4				(3250ul)


#define QC_SOURCECAP_COUNT			(3)				/*!< 多协议放电固定档位数量*/
#define QC_SRC_VOL_H0				(5000ul)		/*!< 5v/3a,多协议放电固定档电压*/
#define QC_SRC_CURR_H0				(3000ul)		/*!< 5v/3a,多协议放电固定档电流*/

#define QC_SRC_VOL_H1				(9000ul)		/*!< 9v/2a,多协议放电固定档电压*/
#define QC_SRC_CURR_H1				(2000ul)		/*!< 9v/2a,多协议放电固定档电流*/

#define QC_SRC_VOL_H2				(12000ul)		/*!< 12v/1.5a,多协议放电固定档电压*/
#define QC_SRC_CURR_H2				(1500ul)		/*!< 12v/1.5a,多协议放电固定档电流*/

#define QC_SRC_CURR_H8				(3000ul)		/*!< 3a,多协议放电可调档电流*/


//--------------------------------------------
//
#define C_Temp_InOut_ProH			0x0ff0	


#define C_Temp_InOut_ProL			0x000F
//--------------------------------------------
//// 上拉1M  NTC 100k 3.3V LDO///////////////////////////// 

#define C_TempH_Charge_Off_Pro		    98		//60  ////充电高温保护
#define C_TempH_Charge_On_Pro		    142		//50  ////充电高温恢复温度
#define C_TempH_Charge_low_power_H      171	//45  ////充电低功率温度
#define C_TempH_Charge_low_power_H_R    207	//40  ////充电高功率恢复温度
#define C_TempH_Charge_low_power_L_R    830	//5  ////充电高功率恢复温度
#define C_TempH_Charge_low_power_L      1009	//0  ////充电低功率温度
#define C_TempL_Charge_On_Pro		    1220		//-5   ////充电低温恢复温度
#define C_TempL_Charge_Off_Pro		    1461		//-10  ////充电低温保护


#define C_TempH_DisCharge_Off_Pro	98		//60  ////放电电高温保护
#define C_TempH_DisCharge_On_Pro	118		//55  ////放电高温恢复温度
//#define C_TempL_DisCharge_Off_Pro	1893	//-18 ////放电低温保护
#define C_TempL_DisCharge_Off_Pro	1950	//-19 ////放电低温保护
#define C_TempL_DisCharge_On_Pro	1731	//-15   ///放电低温恢复温度
#define C_PowerdisCharge_limit_pro_on		1461  ////-10度 
#define C_PowerdisCharge_limit_pro_off		1220  ///-5度 42.4906

#define Power_RE_T    	98		//  60度-放电恢复功率处理/////
#define Power_Down_T    43		//  85度-放电恢复功率处理/////


#define	Out_5500_V210	2100
#define	Out_5500_V205	2050
#define	Out_5500_V200	2000
#define	Out_5500_V195	1950
#define	Out_5500_V190	1900
#define	Out_5500_V185	1850
#define	Out_5500_V180	1800
#define	Out_5500_V175	1750
#define	Out_5500_V170	1700
#define	Out_5500_V165	1650
#define	Out_5500_V160	1600
#define	Out_5500_V155	1550
#define	Out_5500_V150	1500
#define	Out_5500_V145	1450
#define	Out_5500_V140	1400
#define	Out_5500_V135	1350
#define	Out_5500_V130	1300
#define	Out_5500_V125	1250
#define	Out_5500_V120	1200
#define	Out_5500_V115	1150
#define	Out_5500_V110	1100
#define	Out_5500_V105	1050
#define	Out_5500_V100	1000
#define	Out_5500_V95	950
#define	Out_5500_V90	900
#define	Out_5500_V85	850
#define	Out_5500_V80	800
#define	Out_5500_V75	750
#define	Out_5500_V70	700
#define	Out_5500_V65	650
#define	Out_5500_V60	600
#define	Out_5500_V55	550
#define	Out_5500_V50	500
#define	Out_5500_V45	450
#define	Out_5500_V40	400

//#define	Out_PD_5V	490  ///5.2--8886
//#define	Out_PD_9V	990  //9.2
//#define	Out_PD_12V	1365 //12.2
//#define	Out_PD_15V	1740 //15.2
//#define	Out_PD_20V	2365 //20.2

//#define	Out_PD_5V	220  ///5.2--8886
//#define	Out_PD_9V	620  //9.2
//#define	Out_PD_12V	920 //12.2
//#define	Out_PD_15V	1220 //15.2
//#define	Out_PD_20V	1720 //20.2
#define	Out_PD_5V	220  ///5.2-- 7201
#define	Out_PD_9V	625//620  //9.2
#define	Out_PD_12V	925//920 //12.2
#define	Out_PD_15V	1225//1220 //15.2
#define	Out_PD_20V	1725//1720 //20.2


//#define	Out_PD_3A 	60////---8886
//#define	Out_PD_4A 	80
//#define	Out_PD_5A 	100
//#define	Out_PD_6A 	120
//#define	Out_PD_3A 	60////---7203
//#define	Out_PD_4A 	80
//#define	Out_PD_5A 	100
//#define	Out_PD_6A 	120
//
#define	Out_PD_A1000 	10
#define	Out_PD_A1500	20
#define	Out_PD_A2000	30
#define	Out_PD_A2500	40
#define	Out_PD_A3000	50
#define	Out_PD_A3500	60
#define	Out_PD_A4000	70
#define	Out_PD_A4500	80
#define	Out_PD_A5000	90
#define	Out_PD_A5500	100
#define	Out_PD_A6000	110
#define	Out_PD_A6500	120


//#define	CAOUT_CBOUT_TO_CAIN_CBOUT	159//3000   ////10K --CA-3.3K ---CB-2.2K 取得的ADC 除以16
//#define	CAIN_CBOUT_TO_CAOUT_CBIN  	54 //880
//#define	CAOUT_CBIN_TO_CAIN_CBIN  	38 //600

#define	CAOUT_CBOUT_TO_CAIN_CBOUT	159//3000   ////10K --CA-3.3K ---CB-2.2K 取得的ADC 除以16
#define	CAIN_CBOUT_TO_CAOUT_CBIN  	54 //880
#define	CAOUT_CBIN_TO_CAIN_CBIN  	38 //600


#define Ibus_SmallCurL  6  //PDO_cuurest_MA100
#define Ibus_SmallCurH  9 //150ma

#define C_DisCharge_5VSmallCurL  8 //PDO_cuurest_MA100//   50ma 以下
#define C_DisCharge_5VSmallCurH  11 //150 ma

#define CA_100mA  8  //PDO_cuurest_MA100
#define CA_150mA  10 //150ma

#define USBA_100mA  12  //PDO_cuurest_MA100
#define USBA_150mA  17 //150ma

//#define C_DisCharge_CA_lowpower  37/////  300ma 
#define C_DisCharge_CA_lowpower  22/////  300ma 5-15 修改 电阻0.033R 改成0.02

//#define C_DisCharge_SmallCurTime  65//// 30S 关机30A 25S
#define C_DisCharge_SmallCurTime  59//// 59S 关机处理-- 关机30A 25S 5-16 /////

#define C_DisCharge_OutTime    2

#define SYS_VBUS_V38   38///170
#define SYS_VBUS_V40   40////4V VUBS 检测电压
#define SYS_VBUS_V41   41//170 ////4.5 
#define SYS_VBUS_V45   45//180/// 4.35V 
#define SYS_VBUS_V48   48//192 ////4.5 
#define SYS_VBUS_V57   57//228 /// 6.25
#define SYS_VBUS_V60   60 //260
#define SYS_VBUS_V65   65//260/// 6.8
#define SYS_VBUS_V77   77//308/// 8.2
#define SYS_VBUS_V79   79//316 ///8.7 
#define SYS_VBUS_V82   82 //330
#define SYS_VBUS_V102  102//430
#define SYS_VBUS_V105  105 ///450
#define SYS_VBUS_V125  125//500 /// 13.75
#define SYS_VBUS_V128  128///800
#define SYS_VBUS_V130  130//520 ///14.5
#define SYS_VBUS_V135  135//580
#define SYS_VBUS_V140  140//600
#define SYS_VBUS_V142  142//600
#define SYS_VBUS_V145  145//600
#define SYS_VBUS_V150  150//600
#define SYS_VBUS_V165  165//717
#define SYS_VBUS_V185  185///800
#define SYS_VBUS_V210  210////956
#define SYS_VBUS_V220  220////956

#define	In_charge_up_time 	3////小于4.7V 
#define	In_charge_down_time 	30////小于4.7V 

#define	In5_charge_up_time 	15////小于4.7V 
#define	In5_charge_down_time 	100////小于4.7V 
#define IBUS_1A0   80   /////C口充电电流小于1A

//#define		PIN_SIM_TX	PT22		//模拟串口  PT22  LED4
//#define		PINC_SIM_TX	PT2EN2

//#define		PIN_SIM_TX	PT31		//模拟串口  PT22  LED4
//#define		PINC_SIM_TX	PT3EN1

#define		PIN_SIM_TX	PT35		//模拟串口  PT22  LED4
#define		PINC_SIM_TX	PT3EN5

//#define		PIN_SIM_TX	PT1PU3		//模拟串口  PT13  ///上拉电阻处理///
//#define		PINC_SIM_TX	PT13



//	#define		PIN_SIM_TX	PT30		//模拟串口  PT26
//	#define		PINC_SIM_TX	PT3EN0

//#define RED_PIN      PT34
//#define RED_PIN_EN   PT3EN4
//#define RED_PIN_ON   {RED_PIN_EN=1; RED_PIN=1;}//  
//#define RED_PIN_OFF  {RED_PIN_EN=1; RED_PIN=0;}//  

 


#define INTF_UART_MASK		0b10000000

#define  A1_close_time   10  ////10S 电流低于70ma 关闭

#define C_TempL_limittime	20		//////功率限制计数次数

//#define Disharge_ADD_percent_accu	4100//放电1% 电流值处理/////  6-18////
//#define Charge_ADD_percent_accu 	4100////充电1% 电流   ////6-18

//#define Disharge_ADD_percent_accu	4800//放电1% 电流值处理/////8-14////
//#define Charge_ADD_percent_accu 	4900////充电1% 电流   //////8-8////

#define Disharge_ADD_percent_accu	4100//放电1% 电流值处理///// 9-9---
#define Charge_ADD_percent_accu 	4100////充电1% 电流   ////9-9---


#define RCR_24C02_addr         0x01
#define BAT_Value_24C02_addr   0x02
#define BAT_Vol_24C02_addr     0x03
#define BAT_Low_24C02_addr     0x04
#define RCR_sum_addr           0x05

#define RCR_BAT_Vol_cnt_addr    0x06
#define RCR_Lange_cnt_addr    0x07

#define RCR_BAT_Vol_First_addr    0x20
#define RCR_BAT_Vol_First_Cnt      20

#define Self_inspe_24C02_addr     0x10
#define Self_inspe_data           0x55

#define RCR_normal_Close_data        0xaa/// 正常手动擦写数据休眠///
#define RCR_Updata_Close_data        0x55/// 开机写数据


#define  closelcdtime  7200  //// 2h
//#define  closelcdtime  15  //// 2h


//#define RCR_Updata_Close_data        0x55
//typedef struct{
//	uint8_t Temp_IN:				 
//	uint8_t DischargeTemp_OK:		 
//	uint8_t DischargeTemp_High:		 
//	uint8_t DischargeTemp_Low:		 
//	uint8_t ChargeTemp_OK:			 
//	uint8_t ChargeTemp_High:		1;
//	uint8_t ChargeTemp_Low:			1;
//	uint8_t Discharge_TempNG_cnt:	1;
//	uint8_t Charge_TempNG_cnt:		1;
//	
//}TypeOfTemp;

extern bank1 uint32_t pdo_src_list[7][2];

typedef struct{
	uint8_t Temp_IN;
	uint8_t DischargeTemp_OK;
	uint8_t DischargeTemp_High;
	uint8_t DischargeTemp_Low;
	uint8_t ChargeTemp_OK;///// 充电温度保护 标志 0=保护 1-正常////
	uint8_t ChargeTemp_High;
	uint8_t ChargeTemp_Low;
	uint8_t Discharge_TempNG_cnt;
	uint8_t Charge_TempNG_cnt;
	uint8_t Charge_TempRE_cnt;
}TypeOfTemp;



extern TypeOfTemp Temp;

extern uint8_t  Frist_start_sink;

typedef enum
{
	REQUEST_NULL= (uint8_t)0,
	CAP_1,
	CAP_2,
	CAP_3,
	CAP_4,
	CAP_5,
	PPS_1,
	PPS_2,
}pd_pdo_num_t;

extern volatile	unsigned char	R_data_tx;
extern volatile	unsigned char	R_count_tx;

extern uint8_t sleepcnt;
extern uint8_t bat_full_cnt;
extern uint8_t R_SysMode_OK;
extern uint8_t R_SysMode_OK_bak;
extern uint8_t R_SysMode_BE;
extern uint8_t Charge_up_Cnt;
extern uint8_t DisCharge_down_Cnt;
extern uint8_t Bat_low_Cnt;

extern uint8_t Discharge_MinCur;
extern uint8_t R_DisCharge_SmallCurCnt;
extern uint8_t R_DisCharge_OutTime;

extern uint8_t R_Charge_level;///// 充电电压等级////
extern uint8_t R_Charge_level_up_Cnt;///// 充电电压等级上升////
extern uint8_t R_Charge_level_down_Cnt;///// 充电电压等级下降////

extern uint8_t MiroB_charge_Cnt;///// MiroB口充电 插入检测计数////
extern uint8_t MiroB_dis_Cnt;/// MiroB口充电 移除检测计数////

extern uint8_t Bat_low_RE_Cnt;


extern BANK_Add uint8_t  V_NO_Cha_flage;
extern BANK_Add uint8_t  V_NO_Charge;
extern BANK_Add uint8_t  V_NO_BAT_Charge;
extern BANK_Add uint8_t  V_NO_BAT_Cnt;

extern BANK_Add uint8_t Charge_low_power_F;
extern BANK_Add uint8_t Charge_low_power_CNT;

extern BANK_Add uint8_t Charge_bat_low_power_F;
extern BANK_Add uint8_t Charge_bat_low_power_CNT;

extern BANK_Add uint8_t Charge_HIG_Vbat_F;
extern BANK_Add uint8_t Charge_low_Vbat_CNT;



extern BANK_Add uint8_t  SOS_lighting_stop;

extern BANK_Add uint8_t bat_dis_full_cnt;

extern BANK_Add  uint8_t statusKeyFlag;
extern BANK_Add uint8_t Be_statusKeyFlag;

extern BANK_Add unsigned char flash_count;/////闪灯计时////
extern BANK_Add unsigned char sos_state;////SOS 步骤数
extern BANK_Add unsigned char sos_count;////SOS 计时/////


extern BANK_Add uint8_t  uart_read_temp;
extern BANK_Add uint16_t A1_closeTIME;

extern BANK_Add uint8_t Car_low_bat_cnt;

extern BANK_Add uint8_t	Temp_limit_discharge;
extern BANK_Add uint8_t	Temp_limit_I;
extern BANK_Add uint8_t	Temp_limit_count;
extern BANK_Add uint8_t	Temp_close_limit_count;

extern BANK_Add uint8_t Bat_Protest_cnt;

extern BANK_Add uint8_t  Bat_low_sleep_flage;
extern BANK_Add uint16_t TYPEC_sleep_time_cnt;
extern BANK_Add uint8_t  TYPEC_sleep_distime_cnt;

extern BANK_Add uint8_t CA_Test_do_no_Slepp;

extern BANK_Add uint8_t delay_Check_C_Vol;////

extern BANK_Add uint8_t  hour2_dis_flage;
extern BANK_Add uint16_t hour2_dis_cnt;

extern BANK_Add uint16_t ADD_IBAT_cnt;
extern BANK_Add uint8_t  ADD_percent_accu;




//extern BANK_Add uint8_t  Disharge_ADD_percent_accu;
//extern BANK_Add uint16_t C_ADD_IBAT_cnt;
//extern BANK_Add uint8_t  C_ADD_percent_accu;

extern BANK_Add uint8_t Charge_Bat_Start_Cnt;
extern BANK_Add uint8_t  Flash_Bat_Vol_data;
extern BANK_Add uint8_t  Flash_Bat_Value_data;
extern BANK_Add uint8_t  Flash_Bat_RCR_data;


extern BANK_Add uint8_t CA_IN_Frist_No_Soure;
extern BANK_Add uint8_t BAT_CO_OPEN_CNT;


extern BANK_Add uint8_t Self_inspe_CNT;

extern BANK_Add uint8_t Frist_Bat_Connect;
extern BANK_Add uint8_t Frist_Bat_100ms_Cnt;

extern BANK_Add uint8_t car_low_bater_Cnt;
extern BANK_Add uint8_t car_OK_Flage;

extern BANK_Add uint8_t Bat_low2_Cnt;
extern BANK_Add uint8_t  DIS_low_bater_Cnt;

extern BANK_Add uint16_t  open_to_12hour_Cnt;

extern BANK_Add uint8_t Port_NTC_NG_LOW_POWER_Flage;
extern BANK_Add uint8_t Port_NTC_NG_LOW_POWER_Cnt;

 extern BANK_Add uint16_t I_All_IN_Do;


extern Add_data_bank uint8_t BAT_real;

extern Add_data_bank uint8_t Car_Cont_NG_Flage;

extern Add_data_bank uint8_t BAT_cnt_recor;


extern Add_data_bank LCD_display_3S_Cnt;

//extern volatile  uint32_t pdo_sourcecap[7];
//extern volatile  uint32_t pdo_sinkcap[2];
extern const uint32_t multi_src_list[QC_SOURCECAP_COUNT+ 1][2];

void app_peripheral_init(void);
void peripheral_typec_init(TC_BANK typec_handle_t * p_h_typec);

void peripheral_typec_UFP_init(TC_BANK typec_handle_t * p_h_typec);
void peripheral_typec_DRP_init(TC_BANK typec_handle_t * p_h_typec);

void peripheral_pd_init(void);
extern void Start_data_init(void);
extern void Sleep_up_data_init(void);
extern void BSP_VBat_Jud(void);
extern void Charge_bat_Full_check(void);
extern void Bat_Vaule_deal(void);
extern void Bat_low_deal(void);
extern void BSP_Temp_Control(void);
extern void BSP_Charge_TempNG(void);
extern void BSP_Discharge_TempNG(void);
extern void BSP_Discharge_TempOK(void);
extern void V_PWM_init(void);
extern void I_PWM_init(void);
extern void V_PWM_Change(uint16_t data);
extern void I_PWM_Change(uint16_t data);
extern void CA_CB_Port_Statu();
extern void BSP_DisCharge_SmallCur(void);
extern void BSP_DisCharge_SmallCur_Deal(void);
extern void Frist_sink_deal(void);
extern void Vin_vol_charge_deal(void);
extern void Car_statu_deal(void);////汽车夹子 点火处理///
extern void Miro_in_deal(void);////Miro B 口充电判断处理///
extern void Sub_sim_tx(unsigned char data);

extern void Sinck_in9V_max(void);
extern void Sinck_in_recover_max(void);
extern void Lighting_to_SOS_Dispose(void);

extern void IAP_inti_deal(void);
extern void IAP_inti_deal_dis(void);

extern void iap_signal_detect(unsigned char receive_data);

extern void app_power_capabilities_switch_h(void);
extern void app_power_capabilities_switch_l(void);
extern void app_power_PDO_rerest(void);
extern void TYPE_C_constraint_sleep(void);

extern uint16_t BSP_I2C_VbatCheck(void);
extern void BSP_I2C_7203_Data(void);
extern void BSP_I2C_BATVaule_Deal(void);///库伦计处理
extern void Flash_Read_Deal(void);
extern void Flash_update_Deal(void);
extern void Poweron_24C02_Self_inspec(void);

extern void Charge_Bat_data_Err_Deal(void);

extern void app_power_capabilities_switch_h_1(void);
extern void app_power_capabilities_switch_h_2(void);
extern void app_power_capabilities_switch_h_3(void);

// extern void app_charge_power_switch_0(void);
// extern void app_charge_power_switch_1(void);
// extern void app_charge_power_switch_2(void);
// extern void app_charge_power_switch_3(void);

extern void LED_PIN_on_off_Deal(uint8_t enble);
extern void LED_PIN_qu_fan_Deal(void);
extern uint8_t Data_16_to_8_data_Deal(uint16_t data16_original);
//extern void Charge_Bat_data_Err_Deal(void);

#endif
