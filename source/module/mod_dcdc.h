/***************************************************************************//**
 * @file     mod_dcdc.h
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

#ifndef __MOD_DCDC_H__
#define __MOD_DCDC_H__

// Include external header file.
#include "drv_iic.h"


#ifdef __cplusplus
extern "C" {
#endif


#define BANK_DCDC									BANK_IIC
#define BANK_DCDC_NUM								BANK_IIC_NUM
#define M_DCDC_REG_GET(REG, POS, BITS)				M_REG_GET(REG, POS, BITS)
#define M_DCDC_REG_SET(REG, POS, BITS, VAL)			M_REG_SET(REG, POS, BITS, VAL)


//#define CFG_BATT_CELLS								(2)
#define CFG_BATT_CELLS								(3)
#define LDO5Vto1_3V3to0     1   /////1---LDO 5V 或是0---3.3V LDO参数/////


//#define WR_PIN       PT26
//#define WR_PIN_EN    PT2EN6
//#define WR_PIN_ON_DIS_WRITE     {WR_PIN_EN=1;WR_PIN=1;}
//#define WR_PIN_OFF_EN_WRITE   {WR_PIN_EN=1;WR_PIN=0;}

#define BAT_CO_PIN    PT26
#define BAT_CO_EN     PT2EN6
#define BAT_CO_ON     {BAT_CO_EN=1;BAT_CO_PIN=1;}
#define BAT_CO_OFF    {BAT_CO_EN=1;BAT_CO_PIN=0;}

#define TCA_PIN       PT14
#define TCA_PIN_EN    PT1EN4
#define TCA_PIN_ON    {TCA_PIN_EN=1;TCA_PIN=1;}
#define TCA_PIN_OFF   {TCA_PIN_EN=1;TCA_PIN=0;}

#define MIR_B_PIN       PT13
#define MIR_B_PIN_EN    PT1EN3
#define MIR_B_PIN_UP    PT1PU3
#define MIR_B_PIN_ON   {MIR_B_PIN_EN=0;MIR_B_PIN=0;MIR_B_PIN_UP=1;}
#define MIR_B_PIN_OFF  {MIR_B_PIN_EN=0;MIR_B_PIN=0;MIR_B_PIN_UP=0;}


//#define USBA_PIN       PT31
//#define USBA_PIN_EN    PT3EN1
//#define USBA_PIN_ON    {USBA_PIN_EN=1;USBA_PIN=1;}
//#define USBA_PIN_OFF   {USBA_PIN_EN=1;USBA_PIN=0;}

#define USBA_PIN       PT34
#define USBA_PIN_EN    PT3EN4
#define USBA_PIN_ON    {USBA_PIN_EN=1;USBA_PIN=1;}
#define USBA_PIN_OFF   {USBA_PIN_EN=1;USBA_PIN=0;}


//
//#define USBA2_PIN      PT32
//#define USBA2_PIN_EN   PT3EN2
//#define USBA2_PIN_ON   {USBA2_PIN_EN=1;USBA2_PIN=1;}
//#define USBA2_PIN_OFF   {USBA2_PIN_EN=1;USBA2_PIN=0;}

#define BAT_EN_PIN      PT12
#define BAT_EN_PIN_EN   PT1EN2
#define BAT_EN_PIN_ON   {BAT_EN_PIN_EN=1;BAT_EN_PIN=1;}
#define BAT_EN_PIN_OFF   {BAT_EN_PIN_EN=1;BAT_EN_PIN=0;}


#define W_ID_PIN  PT34

#if(CFG_BATT_CELLS== 1)		
	#define CFG_BAT_CSEL							SC_CSEL_1S

	#define	CFG_SC_VBUS_RATIO						( 12.5f)
	#define CFG_SC_VBAT_MON_RATIO					(  5.0f)
	#define CFG_SC_IBUS_RATIO						(  6.0f)
	#define CFG_SC_IBAT_RATIO						(  6.0f)
	#define CFG_SC_VINREG_RATIO						(100.0f)
#elif(CFG_BATT_CELLS== 2) 		
	#define CFG_BAT_CSEL							SC_CSEL_2S

	#define	CFG_SC_VBUS_RATIO						( 12.5f)
	#define CFG_SC_VBAT_MON_RATIO					(  5.0f)
	#define CFG_SC_IBUS_RATIO						(  6.0f)
	#define CFG_SC_IBAT_RATIO						(  6.0f)
	#define CFG_SC_VINREG_RATIO						(100.0f)
#elif(CFG_BATT_CELLS== 3) 		
	#define CFG_BAT_CSEL							SC_CSEL_3S

	#define	CFG_SC_VBUS_RATIO						( 12.5f)
	#define CFG_SC_VBAT_MON_RATIO					( 12.5f)
	#define CFG_SC_IBUS_RATIO						(  6.0f)
	#define CFG_SC_IBAT_RATIO						(  6.0f)
	#define CFG_SC_VINREG_RATIO						(100.0f)
#elif(CFG_BATT_CELLS== 4) 
	#define CFG_BAT_CSEL							SC_CSEL_4S

	#define	CFG_SC_VBUS_RATIO						( 12.5f)
	#define CFG_SC_VBAT_MON_RATIO					( 12.5f)
	#define CFG_SC_IBUS_RATIO						(  6.0f)
	#define CFG_SC_IBAT_RATIO						(  6.0f)
	#define CFG_SC_VINREG_RATIO						(100.0f)
#else
	#define CFG_BAT_CSEL							SC_CSEL_NULL
	#define	CFG_SC_VBUS_RATIO						(NULL)
	#define CFG_SC_VBAT_MON_RATIO					(NULL)
	#define CFG_SC_IBUS_RATIO						(NULL)
	#define CFG_SC_IBAT_RATIO						(NULL)
	#define CFG_SC_VINREG_RATIO						(NULL)
#endif


/** vbus voltage detection upper resistance**/
#define CFG_SC_FB_RU								(100000.0f)		//100K
/** Vbus voltage detection lower side resistance**/
#define CFG_SC_FB_RD								(11000.0f)		//11K
/** vbus voltage detection FB voltage**/
#define CFG_SC_FB_VOL								(2.0f)
/** vbus current detection resistance value**/
#define CFG_SC_IBUS_RS1								(10.0f)			//10mR
/** battery current detection resistance value**/
#define CFG_SC_IBAT_RS2								(5.0f)			//5mR


#define M_10BITREG_CAL(_reg_h, _reg_l)				(uint16_t)((_reg_h<< 2)+ (_reg_l>> 6)+ 1)



/** 
 * MACRO: calculate the register value corresponding to the vbus voltage
 * Formula:
 *			VBUSREF_E= (4* VBUSREF_I_SET+ VBUSREF_I_SET2+ 1)* VBUS_RATIO* 2mV
 *			
**/
#define M_VBUSE_ADC(_vol)							(uint16_t)((_vol/ CFG_SC_FB_VOL- 1)/ (1+ CFG_SC_FB_RU/ CFG_SC_FB_RD))
#define M_VBUSE(_code, _code2)						((_code<< 2)+ (_code2>> 6)+ 1)* (uint16_t)(CFG_SC_FB_VOL* (1+ CFG_SC_FB_RU/ CFG_SC_FB_RD))

/** 
 * MACRO: calculate the register value corresponding to the vbus voltage
 * Formula:
 * 			VBUSREF_I= (4* VBUSREF_I_SET+ VBUSREF_I_SET2+ 1)* 2mV
 *			
**/
#define M_VBUSI_ADC(_vol)							(uint16_t)(_vol/ (CFG_SC_VBUS_RATIO* CFG_SC_FB_VOL)- 1)

/** 
 * MACRO: calculate the register value corresponding to IBUS current
 * Formula:
 *			IBUS_LIM_SET= IBUS_LIM(A)* 256* RS1/ (10* Ibus_ratio)- 1
**/
#define M_IBUS_ADC(_curr)							(uint8_t)(_curr* 256* CFG_SC_IBUS_RS1/ (CFG_SC_IBUS_RATIO* 10)- 1)

/** 
 * MACRO: calculate the register value corresponding to IBAT current
 * Formula:
 *			IBAT_LIM (A)= ((IBAT_LIM_SET+ 1)/ 256)* IBAT_RATIO* (10mΩ/ RS2)
 *			IBUS_LIM_SET= IBAT_LIM* 256* RS2/ (10* Ibat_ratio)- 1
**/
#define M_IBAT_ADC(_curr)							(uint8_t)(_curr* 256* CFG_SC_IBAT_RS2/ (CFG_SC_IBAT_RATIO* 10)- 1)

/** 
 * MACRO: calculate the register value corresponding to IBAT current
 * Formula:
 *			VINREG= (VINREG_SET+ 1)* VINREG_RATIO(mV)
 *			
**/
#define M_VINREG_ADC(_vol)							(uint8_t)(_vol/ CFG_SC_VINREG_RATIO- 1)

/** 
 * MACRO: 
 * Formula:
 *			VBUS_FB= (4* VBUSREF_I_SET+ VBUSREF_I_SET2+ 1)* VBUS_RATIO* 2mV
 *			VBUS_FB_VALUE= (4* Hi+ Lo+ 1)* 2* VBUS_RATIO
 *			
**/
#define M_VBUS_FB(_code, _code2)					((_code<< 2)+ (_code2>> 6)+ 1)* (uint8_t)(CFG_SC_VBUS_RATIO* CFG_SC_FB_VOL)
#define M_VBUS_FB_ADC(_vol)							(uint16_t)(_vol/ (CFG_SC_VBUS_RATIO* CFG_SC_FB_VOL)- 1)

/** 
 * MACRO: 
 * Formula:
 *			VBAT_FB= (4* VBAT_FB_VALUE+ VBAT_FB_VALUE2+ 1)* VBAT_MON_RATIO* 2 mV
 *			VBAT_FB_VALUE= (4* Hi+ Lo+ 1)* 2* VBAT_RATIO
 *			
**/
#define M_VBAT_FB(_code, _code2)					((_code<< 2)+ (_code2>> 6)+ 1)* (uint8_t)(CFG_SC_VBAT_MON_RATIO* CFG_SC_FB_VOL)
#define M_VBAT_FB_ADC(_vol)							(uint16_t)(_vol/ (CFG_SC_VBAT_MON_RATIO* CFG_SC_FB_VOL)- 1)

/** 
 * MACRO: 
 * Formula:
 *			IBUS(A)= (4* IBUS_VALUE+ IBUS_VALUE2+ 1)* 2/ 1200* IBUS_RATIO* 10mΩ/ RS1
 *			
**/
#define M_IBUS(_code, _code2)						((_code<< 2)+ (_code2>> 6)+ 1)* (uint8_t)(CFG_SC_IBUS_RATIO* 1000/ 60/ CFG_SC_IBUS_RS1)

/** 
 * MACRO: 
 * Formula:
 *			IBAT(A)= (4* IBAT_VALUE+ IBAT_VALUE2+ 1)* 2/ 1200* BAT_RATIO* 10mΩ/ RS2
 *			
**/
#define M_IBAT(_code, _code2)						((_code<< 2)+ (_code2>> 6)+ 1)* (uint8_t)(CFG_SC_IBAT_RATIO* 1000/ 60/ CFG_SC_IBAT_RS2)
#define M_IBAT_FB_ADC(_curr)						(uint16_t)(_curr* 1200* CFG_SC_IBAT_RS2/ (2* 10* CFG_SC_IBAT_RATIO)- 1)




/** vbus voltage(external) value macro**/
#define SC_VBUSE_05V20								M_VBUSE_ADC( 5200)
#define SC_VBUSE_09V20								M_VBUSE_ADC( 9200)
#define SC_VBUSE_12V20								M_VBUSE_ADC(12200)
#define SC_VBUSE_15V20								M_VBUSE_ADC(15200)
#define SC_VBUSE_20V20								M_VBUSE_ADC(20200)

/** vbus voltage(internal) value macro**/
#define SC_VBUSI_05V20								M_VBUSI_ADC(5200.0f)

/** BUS current value macro**/
#define SC_IBUSLIM_00A05							M_IBUS_ADC(0.05f)
#define SC_IBUSLIM_00A10							M_IBUS_ADC(0.10f)
#define SC_IBUSLIM_00A20							M_IBUS_ADC(0.20f)
#define SC_IBUSLIM_00A30							M_IBUS_ADC(0.30f)
#define SC_IBUSLIM_00A40							M_IBUS_ADC(0.40f)
#define SC_IBUSLIM_01A00							M_IBUS_ADC(1.00f)
#define SC_IBUSLIM_01A50							M_IBUS_ADC(1.70f)
#define SC_IBUSLIM_01A90							M_IBUS_ADC(2.10f)
#define SC_IBUSLIM_02A00							M_IBUS_ADC(2.20f)
#define SC_IBUSLIM_02A25							M_IBUS_ADC(2.45f)
#define SC_IBUSLIM_02A40							M_IBUS_ADC(2.60f)
#define SC_IBUSLIM_02A50							M_IBUS_ADC(3.00f)
#define SC_IBUSLIM_03A00							M_IBUS_ADC(3.20f)
#define SC_IBUSLIM_03A40							M_IBUS_ADC(3.60f)
#define SC_IBUSLIM_04A00							M_IBUS_ADC(4.00f)
#define SC_IBUSLIM_04A50							M_IBUS_ADC(4.50f)
#define SC_IBUSLIM_05A00							M_IBUS_ADC(5.00f)
#define SC_IBUSLIM_06A00							M_IBUS_ADC(6.00f)

/** BAT current value macro**/
#define SC_IBATLIM_02A00							M_IBAT_ADC( 2.00f)
#define SC_IBATLIM_06A00							M_IBAT_ADC( 6.00f)
#define SC_IBATLIM_09A00							M_IBAT_ADC( 9.00f)
#define SC_IBATLIM_12A00							M_IBAT_ADC(12.00f)

/** VINREG reference voltage macro**/
#define SC_VINREG_04V7								M_VINREG_ADC( 4700.0)
#define SC_VINREG_08V7								M_VINREG_ADC( 8700.0)
#define SC_VINREG_11V7								M_VINREG_ADC(11700.0)
#define SC_VINREG_14V7								M_VINREG_ADC(14700.0)
#define SC_VINREG_19V7								M_VINREG_ADC(19700.0)
#define SC_VINREG_22V0								M_VINREG_ADC(22000.0)

/** BUS monitor voltage value**/
#define SC_VBUSFB_03V00								M_VBUS_FB_ADC(3000.0f)
#define SC_VBUSFB_03V80								M_VBUS_FB_ADC(3800.0f)
#define SC_VBUSFB_04V50								M_VBUS_FB_ADC(4500.0f)

/** Battery voltage monitoring value macro**/
/** low battery**/
#define SC_VBAT_LOW_VOLT							M_VBAT_FB_ADC(3000.0f* CFG_BAT_CSEL)
/** battery alarm level**/
#define SC_VBAT_ALARM_VOLT							M_VBAT_FB_ADC(3200.0f* CFG_BAT_CSEL)
/** **/
#define SC_VBAT_CONST_CURRENT_VOLT					M_VBAT_FB_ADC(4000.0f* CFG_BAT_CSEL)
/** full battery**/
#define SC_VBAT_FULL_VOLT							M_VBAT_FB_ADC(4100.0f* CFG_BAT_CSEL)

/** Battery current monitoring value macro**/
#define SC_IBATFB_00A30								M_IBAT_FB_ADC(0.30f)


// Ratio for IBAT back(倍率)
// #define CFG_BAT_CSEL								(uint8_t)(1200*CFG_SC_IBAT_RS2/(2*10*CFG_SC_IBAT_RATIO))

// Ratio for VBUS reference internal(倍率)
// #define SC_VBUSI_N									(uint8_t)(2.0f*CFG_SC_VBUS_RATIO)

/////////////////////////
//2 串电池参数
#if(CFG_BATT_CELLS== 2)	
//============================================
//2串电池参数
//============================================
//#if(LDO5Vto1_3V3to0)
//#define C_Normal_VBat_Level1		0x0280		//3.10V*2	
//#define C_Normal_VBat_Level2		0x02ab		//3.15V*2
//#define C_Normal_VBat_Level3		0x02b4		//3.20V*2
//#define C_Normal_VBat_Level4		0x02ba		//3.25V*2
//#define C_Normal_VBat_Level5		0x02be		//3.30V*2
//
//#define C_Normal_VBat_Level6		0x02c2		//3.35V*2
//#define C_Normal_VBat_Level7		0x02c7		//3.40V*2
//#define C_Normal_VBat_Level8		0x02cb		//3.45V*2
//#define C_Normal_VBat_Level9		0x02ce		//3.50V*2
//#define C_Normal_VBat_Level10		0x02d2		//3.55V*2
//
//#define C_Normal_VBat_Level11		0x02d7		//3.60V*2
//#define C_Normal_VBat_Level12		0x02dc		//3.65V*2
//#define C_Normal_VBat_Level13		0x02e4		//3.70V*2
//#define C_Normal_VBat_Level14		0x02ee		//3.75V*2
//#define C_Normal_VBat_Level15		0x02f8		//3.80V*2
//
//#define C_Normal_VBat_Level16		0x0302		//3.85V*2
//#define C_Normal_VBat_Level17		0x030c		//3.90V*2
//#define C_Normal_VBat_Level18		0x0316		//3.95V*2
//#define C_Normal_VBat_Level19		0x0320		//4.0V*2
//#define C_Normal_VBat_Level20		0x032d		//4.1V*2
//
//#define C_Normal_VBat_Level21		0x033a		//4.2V*2 
//
//#define C_VbatLow_32V				0x0276		//电池电压6.3V
//#define C_VbatLow_30V				0x0258		//电池电压6.0V
//
//#define C_CV_Vol					0x0320		//充电恒压 电压8.0V

#elif(CFG_BATT_CELLS== 3) 

//#define	C_Normal_VBat_Level1	47	////	11.4
//#define	C_Normal_VBat_Level2	55	////	11.65
//#define	C_Normal_VBat_Level3	60	////	11.8
//#define	C_Normal_VBat_Level4	67	////	12
//#define	C_Normal_VBat_Level5	73	////	12.2
//		
//#define	C_Normal_VBat_Level6	78	////	12.35
//#define	C_Normal_VBat_Level7	82	////	12.45
//#define	C_Normal_VBat_Level8	85	////	12.55
//#define	C_Normal_VBat_Level9	88	////	12.65
//#define	C_Normal_VBat_Level10	92	////	12.75
//				
//#define	C_Normal_VBat_Level11	91	////	12.85
//#define	C_Normal_VBat_Level12	97	////	12.91
//#define	C_Normal_VBat_Level13	99	////	12.97
//#define	C_Normal_VBat_Level14	101	////	13.03
//#define	C_Normal_VBat_Level15	102	////	13.09
//				
//#define	C_Normal_VBat_Level16	105	////	13.15
//#define	C_Normal_VBat_Level17	107	////	13.2
//#define	C_Normal_VBat_Level18	111	////	13.3
//#define	C_Normal_VBat_Level19	112	////	13.35
//#define	C_Normal_VBat_Level20	114	////	13.45
//				
//#define	C_Normal_VBat_Level21	127	////	13.8


#define	C_Normal_VBat_Level1	73	////	12.2
#define	C_Normal_VBat_Level2	87	////	12.6
#define	C_Normal_VBat_Level3	100	////	13
#define	C_Normal_VBat_Level4	107	////	13.2
#define	C_Normal_VBat_Level5	113	////	13.4
				
#define	C_Normal_VBat_Level6	120	////	13.6
#define	C_Normal_VBat_Level7	127	////	13.8
#define	C_Normal_VBat_Level8	135	////	14
#define	C_Normal_VBat_Level9	142	////	14.2
#define	C_Normal_VBat_Level10	148	////	14.4
				
#define	C_Normal_VBat_Level11	155	////	14.6
#define	C_Normal_VBat_Level12	163	////	14.8
#define	C_Normal_VBat_Level13	167	////	15
#define	C_Normal_VBat_Level14	173	////	15.2
#define	C_Normal_VBat_Level15	180	////	15.4
				
#define	C_Normal_VBat_Level16	187	////	15.6
#define	C_Normal_VBat_Level17	193	////	15.8
#define	C_Normal_VBat_Level18	200	////	16
#define	C_Normal_VBat_Level19	206	////	16.2
#define	C_Normal_VBat_Level20	214	////	16.4
				
#define	C_Normal_VBat_Level21	217	////	16.6

#define C_VbatLow_Close_Car	    53 		//11.6V ---
#define C_VbatLow_Re_Car	    59 		//11.8V----
//#define C_VbatLow_batter_Car_change	    87 		//12.6V
#define C_VbatLow_batter_Car_change	    120 		//13.6V 


//#define C_VbatLow_32V	 	73 		//电池电压12.2V
//#define C_VbatLow_30V	    67 		//电池电压12V

#define C_VbatLow_32V	 	100 	//电池电压13V
#define C_VbatLow_30V	    87 		//电池电压12.6V

#define C_Vbat_Low_re_Vol	 	100 	//电池电压13V

#define C_CV_Vol					126		//电池电压充电13.6---
#define C_CV_Vol_down				102		//电池电压充电13.1----
//#define C_CV_Full					112		//电池电压充电13.3V	
#define C_CV_Full					207		//电池电压充电16.2V	
#define C_CV_Fast_charge		    126		//电池电压充电13.8V	------
#define C_CV_HIGH_BAT	            133		//电池电压充电13.8V------

//#define C_CV_Full_time_4hour			104		//电池电压充电13.1	
//#define C_CV_Full_time_6hour			67		//电池电压充电12
#define C_CV_Full_time_4hour			183		//电池电压充电15.5	
#define C_CV_Full_time_6hour			150		//电池电压充电14.5

#define C_CV_BAT_recharge	  	67		//电池回到正常充电状态12V  4-9- 沿用 不修改////
#define C_CV_BAT_low_charge	  	55		//电池回到正常充电状态11.6V 



#elif(CFG_BATT_CELLS== 4) 
//#if(LDO5Vto1_3V3to0)
//============================================
//4 串电池参数
//============================================
#endif
#define   C_Dischagge_BatVaule_75   C_Normal_VBat_Level18  // 13.3
#define   C_Dischagge_BatVaule_50   C_Normal_VBat_Level15  ////	13.09
#define   C_Dischagge_BatVaule_25   C_Normal_VBat_Level12  ////	12.91
#define   C_Dischagge_BatVaule_10   C_Normal_VBat_Level7   // 12.4

#define   C_Charge_BatVaule_75  C_Normal_VBat_Level18 // 
#define   C_Charge_BatVaule_50  C_Normal_VBat_Level14 // 
#define   C_Charge_BatVaule_25  C_Normal_VBat_Level10  // 
#define   C_Charge_BatVaule_10  C_Normal_VBat_Level3  // 

/////////////////5500 参数///////
//#define  PIN_EN_SYS_IN    PT16
//#define  PIN_EN_SYS_IN_EN PT1EN6
#define  PIN_EN_SYS_IN    PT15
#define  PIN_EN_SYS_IN_EN PT1EN5
#define  EN_SYS_IN        {PIN_EN_SYS_IN_EN=1; PIN_EN_SYS_IN=1;}
#define  Sleep_SYS_IN     {PIN_EN_SYS_IN_EN=1; PIN_EN_SYS_IN=0;}

//#define  EN_SYS_INOTG         PT20
//#define  EN_SYS_INOTG_EN      PT2EN0
//#define  EN_SYS_IN_Dischar {EN_SYS_INOTG_EN=1; EN_SYS_INOTG=1;}
//#define  EN_SYS_IN_Char    {EN_SYS_INOTG_EN=1; EN_SYS_INOTG=0;}

//#define  Data_888600  0x4A ////00 寄存器 初始化值
//
#define  Data_720334  0xAC ////34  充电目标电压  16.8V///三元电池电压处理////
#define  Data_720335  0x04 ////35  充电目标电压  16.8V
//
//#define  Data_720334  0x78 ////34  充电目标电压 12.6V
//#define  Data_720335  0x00 ////35  充电目标电压 12.6V

//#define  Data_720334  0x8e ////34  充电目标电压 14.4V  ///// 磷酸铁锂电池
//#define  Data_720335  0x04 ////35  充电目标电压 14.4V

//#define  Data_720336  79 ////2.5+X*0.1 36  涓流充电电压/// 10.4V  单节电池2.6V以下涓流
#define  Data_720336  101 ////2.5+X*0.1 36  涓流充电电压/// 12.6V  单节电池3.1V以下涓流


#define  Data_720334_full  0x89 ////34  充电目标电压 14.0V  ///// 磷酸铁锂电池
#define  Data_720335_full   0x04 ////35  充电目标电压 14.0V

typedef enum
{
	SC_CSEL_NULL		= (uint8_t)0x00,
	SC_CSEL_1S,
	SC_CSEL_2S,
	SC_CSEL_3S,
	SC_CSEL_4S,
}sc8812a_CSEL_t;


typedef enum
{
	SC_VBAT_SET			= (uint8_t)0x00,
	SC_VBUSREF_I_SET	= (uint8_t)0x01,
	SC_VBUSREF_I_SET2	= (uint8_t)0x02,
	SC_VBUSREF_E_SET	= (uint8_t)0x03,
	SC_VBUSREF_E_SET2	= (uint8_t)0x04,
	SC_IBUS_LIM_SET		= (uint8_t)0x05,
	SC_IBAT_LIM_SET		= (uint8_t)0x06,
	SC_VINREG_SET		= (uint8_t)0x07,
	SC_RATIO			= (uint8_t)0x08,
	SC_CTRL0_SET		= (uint8_t)0x09,
	SC_CTRL1_SET		= (uint8_t)0x0A,
	SC_CTRL2_SET		= (uint8_t)0x0B,
	SC_CTRL3_SET		= (uint8_t)0x0C,
	SC_VBUS_FB_VALUE	= (uint8_t)0x0D,
	SC_VBUS_FB_VALUE2	= (uint8_t)0x0E,
	SC_VBAT_FB_VALUE	= (uint8_t)0x0F,
	SC_VBAT_FB_VALUE2	= (uint8_t)0x10,
	SC_IBUS_VALUE		= (uint8_t)0x11,
	SC_IBUS_VALUE2		= (uint8_t)0x12,
	SC_IBAT_VALUE		= (uint8_t)0x13,
	SC_IBAT_VALUE2		= (uint8_t)0x14,
	SC_ADIN_VALUE		= (uint8_t)0x15,
	SC_ADIN_VALUE2		= (uint8_t)0x16,
	SC_STATUS			= (uint8_t)0x17,
	SC_REG18			= (uint8_t)0x18,
	SC_MASK				= (uint8_t)0x19,
	SC_DPDM_CTRL		= (uint8_t)0x1A,
	SC_DPDM_READ		= (uint8_t)0x1B,
	SC_REG_NUM,
}sc8812a_regaddr_t;


typedef enum		/** 0x09H**/
{
	DT_SET				= (uint8_t)0,
	FREQ_SET			= (uint8_t)2,
	VINREG_RATIO		= (uint8_t)4,
	ctrl0_Reserved5		= (uint8_t)5,
	ctrl0_Reserved6		= (uint8_t)6,
	EN_OTG				= (uint8_t)7,
}sc8812a_regpos_ctrl0_set_t;

typedef enum		/** 0x0CH**/
{
	EN_PFM				= (uint8_t)0,
	EOC_SET,
	DIS_SFB,
	LOOP_SET,
	ILIM_BW_SEL,
	AD_START,
	GPO_CTRL,
	EN_PGATE,
}sc8812a_regpos_ctrl3_set_t;

typedef enum		/** 0x17H**/
{
	status_reserved0	= (uint8_t)0,
	EOC,
	OTP,
	VBUS_SHORT,
	INDET1,
	INDET2,
	AC_OK,
	DM_L,
}sc8812a_regpos_status_t;

typedef enum		/** 0x19H**/
{
	mask_reserved0		= (uint8_t)0,
	EOC_MASK,
	OTP_MASK,
	VBUS_SHORT_MASK,
	INDET1_MASK,
	INDET2_MASK,
	AC_OK_MASK,
	DM_L_MASK,
}sc8812a_regpos_mask_t;


typedef struct
{
	uint8_t vbat_set;				/** addr, 0x00H**/
	uint8_t vbusref_i_set;          /** addr, 0x01H**/
	uint8_t vbusref_i_set2;         /** addr, 0x02H**/
	uint8_t vbusref_e_set;          /** addr, 0x03H**/
	uint8_t vbusref_e_set2;         /** addr, 0x04H**/
	uint8_t ibus_lim_set;           /** addr, 0x05H**/
	uint8_t ibat_lim_set;           /** addr, 0x06H**/
	uint8_t vinreg_set;             /** addr, 0x07H**/
	uint8_t ratio;                  /** addr, 0x08H**/
	uint8_t ctrl0_set;              /** addr, 0x09H**/
	uint8_t ctrl1_set;              /** addr, 0x0AH**/
	uint8_t ctrl2_set;              /** addr, 0x0BH**/
	uint8_t ctrl3_set;              /** addr, 0x0CH**/
	uint8_t vbus_fb_value;          /** addr, 0x0DH**/
	uint8_t vbus_fb_value2;         /** addr, 0x0EH**/
	uint8_t vbat_fb_value;          /** addr, 0x0FH**/
	uint8_t vbat_fb_value2;         /** addr, 0x10H**/
	uint8_t ibus_value;             /** addr, 0x11H**/
	uint8_t ibus_value2;            /** addr, 0x12H**/
	uint8_t ibat_value;             /** addr, 0x13H**/
	uint8_t ibat_value2;            /** addr, 0x14H**/
	uint8_t adin_value;             /** addr, 0x15H**/
	uint8_t adin_value2;            /** addr, 0x16H**/
	uint8_t status;                 /** addr, 0x17H**/
	uint8_t reg18;                  /** addr, 0x18H**/
	uint8_t mask;                   /** addr, 0x19H**/
	uint8_t dpdm_ctrl;              /** addr, 0x1AH**/
	uint8_t dpdm_read;              /** addr, 0x1BH**/
	
}sc8812a_reg_t;


typedef struct
{
	uint16_t vbus_fb;
	uint16_t vbat_fb;
	uint16_t ibus_fb;
	uint16_t ibat_fb;
	uint16_t vbus_ref;
}sc8812a_value_t;

typedef struct
{
	sc8812a_reg_t	reg;
	sc8812a_value_t	telemetry;
}sc8812a_data_t;

typedef enum
{
	VBUS_VOL_5V	=	0,
	VBUS_VOL_9V		,
	VBUS_VOL_12V	,
	VBUS_VOL_15V	,
	VBUS_VOL_20V	,
}vol_flag_t;

extern vol_flag_t volt_flag;
extern uint8_t    temp_ibus_lim_bk;
extern BANK_DCDC sc8812a_data_t	dcdc_data;


bool mod_dcdc_init(void);
void mod_dcdc_disable(void);
void mod_dcdc_telemetry_calculate(void);
void mod_dcdc_telemetry_reg_partition0(void);
void mod_dcdc_telemetry_reg_partition1(void);
void mod_dcdc_write_vbusref_e_set(uint16_t vbusref_e_set);
void mod_dcdc_write_ibus_lim_set(uint8_t _ibus_limit_set);
void mod_dcdc_write_ibat_lim_set(uint8_t _ibat_limit_set);
void mod_dcdc_write_vinreg_set(uint8_t _vinreg_set);



void mod_dcdc_write_otg_ctrl(bool status);
void mod_dcdc_write_pgate_ctrl(bool status);
void mod_dcdc_write_gpo_ctrl(bool status);

void mod_SC8886_init(void);
void mod_SC8886_Charge_init(void);
void mod_SC8886_DisCharge_init(void);


void mod_charge_cur_deal(uint8_t charge_ibus_limit);
void mod_charge_vol_deal(uint8_t charge_Vbus_limit);
void mod_charge_ibat_deal(uint8_t charge_Ibat_limit);
void  mod_charge_ibat0_limit_deal(uint8_t enable);
void  Mod_Dis_USBA_EN(uint8_t enable);
void SW7203VbusDischarge(bool flag);
BANK_DCDC uint8_t mod_dcdc_telemetry_status(void);
BANK_DCDC uint16_t mod_dcdc_telemetry_vbus(void);
BANK_DCDC uint16_t mod_dcdc_telemetry_vbus_reg(void);
BANK_DCDC uint16_t mod_dcdc_rt_telemetry_vbus_reg(void);
BANK_DCDC uint16_t mod_dcdc_telemetry_vbat(void);
BANK_DCDC uint16_t mod_dcdc_telemetry_vbat_reg(void);
BANK_DCDC uint16_t mod_dcdc_telemetry_ibus(void);
BANK_DCDC uint16_t mod_dcdc_telemetry_ibus_reg(void);
BANK_DCDC uint16_t mod_dcdc_rt_telemetry_ibus_reg(void);
BANK_DCDC uint16_t mod_dcdc_telemetry_ibat(void);
BANK_DCDC uint16_t mod_dcdc_telemetry_ibat_reg(void);
BANK_DCDC uint16_t mod_dcdc_telemetry_vbusref(void);
BANK_DCDC uint16_t mod_dcdc_telemetry_vbusref_reg(void);

extern void vbus_ibus_cheak(void);
extern void app_power_adjust(uint8_t now_power_number);

#ifdef __cplusplus
}
#endif

#endif  //__MOD_DCDC_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/

