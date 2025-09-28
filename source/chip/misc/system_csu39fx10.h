/***************************************************************************//**
 * @file     system_csu39fx10.h
 * @version  V1.0.0
 * @author   0531
 * @date     2020-09-22 PM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 ****************************************************************************
 * @par 头文件
 *       csu39fx10.h \n
 * @attention
 *  硬件平台:	\n
 *  SDK版本：	.0.0
 * 
 * @par 修改日志:
 * <table>
 * <tr><th>Date        <th>Version  <th>Author    <th>Description
 * <tr><td>2018/08/17  <td>1.0      <td>0531	  <td>创建初始版本
 * </table>
 *
 *****************************************************************************/

#ifndef __SYSTEM_CSU39FX10_H__
#define __SYSTEM_CSU39FX10_H__

// Include external header file.
#include "csu39fx10.h"


#ifdef __cplusplus
extern "C" {
#endif




/**
 * @addtogroup csu39fx10_sdk_chip	csu39fx10_sdk_chip
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_misc	misc 
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_misc_system	system_csu39fx10 
 * @{
 */

/** 
 * @addtogroup system_cfg	clock_config
 * @{
 */
/**
 * @details <b>CFG_SYS_WDT_DISABLE</b>
 * - <b>Features: </b> disable watchdog
 * - <b>Param: </b>
 * | config	| Descriptions		|
 * | :----:	| :----:			|
 * | 0*		| enable watchdog	|
 * | 1		| disable watchdog	|
 */
#define CFG_SYS_WDT_DISABLE				(0)
	
/**
 * @details <b>CFG_SYS_SYSTEM_CLOCK</b>
 * - <b>Features: </b> predefined clock setups
 * - <b>Param: </b>
 * | config	| ICK(MHz)	| WDTCLK(KHz)	| SYSCLK(MHz)	| SYSCLK(Mhz)	|
 * | :----:	| :----:	| :----:		| :----:		| :----:		|
 * | 0*		| 24		| 10			| 24			| 24			|
 * | 1		| 24		| 10			| 24			| 12			|
 * | 2		| 24		| 10			| 24			| 6				|
 * | 3		| 24		| 10			| 24			| 24			|
 * | 4		| 24		| 10			| 24			| 12			|
 * | 5		| 24		| 10			| 24			| 6				|
 */
#define CFG_SYS_SYSTEM_CLOCK			(0)

/**
 * @details <b>CFG_SYS_OSC_CURR</b>
 * - <b>Features: </b> crystal oscillator circuit bias current
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| 64uA			|
 * | 1		| 128uA			|
 * | 2		| 256uA			|
 * | 3		| 512uA			|
 */
#define CFG_SYS_OSC_CURR            	(0)

/** 
 * @details <b>CFG_SYS_TC_TRIM</b>
 * - <b>Features: </b> internal high-speed clock temperature trim value
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*~ 7	| Trim value	|
 */
#define CFG_SYS_TC_TRIM					(0)

/**
 * @details <b>CFG_SYS_CLK_T3_SOURCE</b>
 * - <b>Features: </b> timer3 clock source configuration
 * - <b>Param: </b>
 * | config	| CKT3(timer3 source)			|
 * | :----:	| :----:						|
 * | 0*		| CPUCLK (@ref C_CLK_CPUCLK)	|
 * | 1		| SYSCLK (@ref C_CLK_SYSCLK)	|
 * | 2		| ECK (@ref C_CLK_SYSECK)		|
 * | 3		| PT1.2-IN						|
 */
#define	CFG_SYS_CLK_T3_SOURCE			(0)

/**
 * @details <b>CFG_SYS_CLK_T3_DIV</b>
 * - <b>Features: </b> timer3 clock division configuration
 * - <b>Param: </b>
 * | config	| TM3CLK(timer3 clock)				|
 * | :----:	| :----:							|
 * | 0*		| CKT3 (@ref CFG_SYS_CLK_T3_SOURCE) |
 * | 1		| CKT3/ 2							|
 * | 2		| CKT3/ 4							|
 * | 3		| CKT3/ 8							|
 * | 4		| CKT3/ 16							|
 * | 5		| CKT3/ 32							|
 * | 6		| CKT3/ 64							|
 * | 7		| CKT3/ 128							|
 */
#define	CFG_SYS_CLK_T3_DIV				(7)

/**
 * @details <b>CFG_SYS_CLK_T2_SOURCE</b>
 * - <b>Features: </b> timer2 clock source configuration
 * - <b>Param: </b>
 * | config	| CKT2(timer2 source)			|
 * | :----:	| :----:						|
 * | 0*		| CPUCLK (@ref C_CLK_CPUCLK)	|
 * | 1		| SYSCLK (@ref C_CLK_SYSCLK)	|
 * | 2		| ECK (@ref C_CLK_SYSECK)		|
 * | 3		| WDTCLK (@ref C_CLK_WDTCLK)	|
 */
#define	CFG_SYS_CLK_T2_SOURCE			(0)

/**
 * @details <b>CFG_SYS_CLK_T2_DIV</b>
 * - <b>Features: </b> timer2 clock division configuration
 * - <b>Param: </b>
 * | config	| TM2CLK(timer2 clock)				|
 * | :----:	| :----:							|
 * | 0*		| CKT2 (@ref CFG_SYS_CLK_T2_SOURCE) |
 * | 1		| CKT2/ 2							|
 * | 2		| CKT2/ 4							|
 * | 3		| CKT2/ 8							|
 * | 4		| CKT2/ 16							|
 * | 5		| CKT2/ 32							|
 * | 6		| CKT2/ 64							|
 * | 7		| CKT2/ 128							|
 */
//#define	CFG_SYS_CLK_T2_DIV				(7)
#define	CFG_SYS_CLK_T2_DIV				(6)

/**
 * @details <b>CFG_SYS_CLK_T0_SOURCE</b>
 * - <b>Features: </b> timer0 clock source configuration
 * - <b>Param: </b>
 * | config	| CKT0(timer0 source)			|
 * | :----:	| :----:						|
 * | 0*		| CPUCLK (@ref C_CLK_CPUCLK)	|
 * | 1		| SYSCLK (@ref C_CLK_SYSCLK)	|
 * | 2		| ECK (@ref C_CLK_SYSECK)		|
 * | 3		| WDTCLK (@ref C_CLK_WDTCLK)	|
 */
#define	CFG_SYS_CLK_T0_SOURCE			(0)

/**
 * @details <b>CFG_SYS_CLK_T0_DIV</b>
 * - <b>Features: </b> timer0 clock division configuration
 * - <b>Param: </b>
 * | config	| TM0CLK(timer0 clock)				|
 * | :----:	| :----:							|
 * | 0*		| CKT0 (@ref CFG_SYS_CLK_T0_SOURCE)	|
 * | 1		| CKT0/ 2							|
 * | 2		| CKT0/ 4							|
 * | 3		| CKT0/ 8							|
 * | 4		| CKT0/ 16							|
 * | 5		| CKT0/ 32							|
 * | 6		| CKT0/ 64							|
 * | 7		| CKT0/ 128							|
 */
#define	CFG_SYS_CLK_T0_DIV				(7)

/**
 * @details <b>CFG_SYS_URTCKS_SOURCE</b>
 * - <b>Features: </b> uart clock source configuration
 * - <b>Param: </b>
 * | config	| CKUART(uart source)			|
 * | :----:	| :----:						|
 * | 0*		| SYSCLK (@ref C_CLK_SYSCLK)	|
 * | 1		| ECK (@ref C_CLK_SYSECK)		|
 * | 2		| RESERVED						|
 * | 3		| RESERVED						|
 */
#define	CFG_SYS_URTCKS_SOURCE			(0)

/**
 * @details <b>CFG_SYS_CLK_UART_DIV</b>
 * - <b>Features: </b> uart0 clock division configuration
 * - <b>Param: </b>
 * | config	| UART_CLK(uart clock)						|
 * | :----:	| :----:									|
 * | 0*		| CKUART/ 2	(@ref CFG_SYS_URTCKS_SOURCE)	|
 * | 1		| CKUART/ 4									|
 * | 2		| CKUART/ 8									|
 * | 3		| CKUART/ 16								|
 * | 4		| CKUART/ 32								|
 * | 5		| CKUART/ 64								|
 * | 6		| CKUART/ 64								|
 * | 7		| CKUART/ 64								|
 */
#define	CFG_SYS_CLK_UART_DIV			(3)

/**
 * @details <b>CFG_SYS_PDS_SOURCE</b>
 * - <b>Features: </b> pd clock source configuration
 * - <b>Param: </b>
 * | config	| CKPD(pd source)				|
 * | :----:	| :----:						|
 * | 0*		| CPUCLK (@ref C_CLK_CPUCLK)	|
 * | 1		| SYSCLK (@ref C_CLK_SYSCLK)	|
 * | 2		| RESERVED						|
 * | 3		| RESERVED						|
 */
#define	CFG_SYS_PDS_SOURCE				(0)

/**
 * @details <b>CFG_SYS_TYPCS_SOURCE</b>
 * - <b>Features: </b> typec clock source configuration
 * - <b>Param: </b>
 * | config	| CKTYPEC(typec source)				|
 * | :----:	| :----:							|
 * | 0*		| WDTCLK (@ref C_CLK_WDTCLK)		|
 * | 1		| WDTCLK							|
 * | 2		| SYSCLK/ 2048 (@ref C_CLK_SYSCLK)	|
 * | 3		| RESERVED							|
 */
#define	CFG_SYS_TYPCS_SOURCE			(0)

/**
 * @details <b>CFG_SYS_CLK_T4_SOURCE</b>
 * - <b>Features: </b> timer4 clock source configuration
 * - <b>Param: </b>
 * | config	| CKT4(timer4 source)			|
 * | :----:	| :----:						|
 * | 0*		| CPUCLK (@ref C_CLK_CPUCLK)	|
 * | 1		| SYSCLK (@ref C_CLK_SYSCLK)	|
 * | 2		| ECK (@ref C_CLK_SYSECK)		|
 * | 3		| RESERVED						|
 */
#define	CFG_SYS_CLK_T4_SOURCE			(0)

/**
 * @details <b>CFG_SYS_CLK_T4_DIV</b>
 * - <b>Features: </b> timer4 clock division configuration
 * - <b>Param: </b>
 * | config	| TM4CLK(timer4 clock)				|
 * | :----:	| :----:							|
 * | 0*		| CKT4 (@ref CFG_SYS_CLK_T4_SOURCE)	|
 * | 1		| CKT4/ 2							|
 * | 2		| CKT4/ 4							|
 * | 3		| CKT4/ 8							|
 * | 4		| CKT4/ 16							|
 * | 5		| CKT4/ 32							|
 * | 6		| CKT4/ 64							|
 * | 7		| CKT4/ 128							|
 */
#define	CFG_SYS_CLK_T4_DIV				(7)

/**
 * @details <b>CFG_SYS_CLK_ADC_DIV</b>
 * - <b>Features: </b> adc clock division configuration
 * - <b>Param: </b>
 * | config	| CKADC(adc source)				|
 * | :----:	| :----:						|
 * | 0*		| CPUCLK/ 4	(@ref C_CLK_CPUCLK)	|
 * | 1		| CPUCLK/ 4						|
 * | 2		| CPUCLK/ 8						|
 * | 3		| CPUCLK/ 16					|
 */
#define	CFG_SYS_CLK_ADC_DIV				(0)

/**
 * @details <b>CFG_SYS_CLK_SCP_DIV</b>
 * - <b>Features: </b> scp and vooc modules clock division configuration
 * - <b>Param: </b>
 * | config	| CKSCP(scp source)				|
 * | :----:	| :----:						|
 * | 0		| SYSCLK/ 8 (@ref C_CLK_SYSCLK)	|
 * | 1		| SYSCLK/ 16					|
 * | 2*		| SYSCLK/ 24					|
 * | 3		| SYSCLK/ 32					|
 */
#define	CFG_SYS_CLK_SCP_DIV				(2)
/**@}*/ /*** end of group system_cfg */
/*******************************************************************************/


/*******************************************************************************/
/**
 * @addtogroup csu39fx10_sdk_chip_misc_system_clock	system_clock_frequency
 * @details <b>Watchdog clock frequency: </b>
 * @ref C_CLK_WDTCLK		
 * @details <b>ECK clock frequency: </b>
 * @ref C_CLK_SYSECK
 * @details <b>ICK clock frequency: </b>
 * @ref C_CLK_SYSICK
 * @details <b>SYSCLK clock frequency: </b>
 * @ref C_CLK_SYSCLK
 * @details <b>CPUCLK clock frequency: </b>
 * @ref C_CLK_CPUCLK
 * @details <b>Windows watchdog clock frequency: </b>
 * @ref C_CLK_WWDTCLK
 * @details <b>Timer0 source clock frequency: </b>
 * @ref C_CLK_CKT0
 * @details <b>Timer2 source clock frequency: </b>
 * @ref C_CLK_CKT2
 * @details <b>Timer3 source clock frequency: </b>
 * @ref C_CLK_CKT3
 * @details <b>Timer4 source clock frequency: </b>
 * @ref C_CLK_CKT4
 * @details <b>Timer0 clock frequency: </b>
 * @ref C_CLK_TM0CLK
 * @details <b>Timer2 clock frequency: </b>
 * @ref C_CLK_TM2CLK
 * @details <b>Timer3 clock frequency: </b>
 * @ref C_CLK_TM3CLK
 * @details <b>Timer4 clock frequency: </b>
 * @ref C_CLK_TM4CLK
 * @details <b>Adc source clock frequency: </b>
 * @ref C_CLK_CKADC
 * @details <b>Adc clock frequency: </b>
 * @ref C_CLK_ADCCLK
 * @details <b>Scp source clock frequency: </b>
 * @ref C_CLK_CKSCP
 * @details <b>Scp clock frequency: </b>
 * @ref C_CLK_SCPCLK
 * @details <b>Uart source clock frequency: </b>
 * @ref C_CLK_CKUR0
 * @details <b>Uart clock frequency: </b>
 * @ref C_CLK_UR0CLK
 * @details <b>PD source clock frequency: </b>
 * @ref C_PDS_SOURCE
 * @details <b>Type-C source clock frequency: </b>
 * @ref C_TYPCS_SOURCE
 * @{
 */
/**@}*/ /*** end of group csu39fx10_sdk_chip_misc_system_clock */
/*******************************************************************************/


/******************************** dividing line ********************************/
/** 
 * @addtogroup system_compile	attention: users do not need to care
 * @attention	users do not need to care
 * @{
 */
#if(!CFG_SYS_WDT_DISABLE)
	/** @attention	watchdog clock frequency(user cannot modify)**/
	#define C_CLK_WDTCLK				(10000u)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_MCK_CST_WDT				(1)
#else
	/** @attention	watchdog clock frequency(user cannot modify)**/
	#define C_CLK_WDTCLK				(0)
	/** @attention	reg cfg(users do not need to care)**/		
	#define PRE_MCK_CST_WDT				(0)
#endif


#if(CFG_SYS_SYSTEM_CLOCK== 0)
	/** @attention	sys_eck clock frequency(user cannot modify)**/
	#define C_CLK_SYSECK				(-1)
	/** @attention	sys_ick clock frequency(user cannot modify)**/
	#define C_CLK_SYSICK				(24000000u)
	/** @attention	sys_clk clock frequency(user cannot modify)**/
	#define C_CLK_SYSCLK				(24000000u)
	/** @attention	cpu_clk clock frequency(user cannot modify)**/
	#define C_CLK_CPUCLK				(24000000u)
	/** @attention	wwdt_clk clock frequency(user cannot modify)**/
	#define C_CLK_WWDTCLK				(C_CLK_CPUCLK/ 24576)
	/** @attention	reg cfg(users do not need to care)**/		
    #define PRE_MCK_CST_XT				(0)
	/** @attention	reg cfg(users do not need to care)**/		
	#define PRE_MCK_CST_IN				(1)
	/** @attention	reg cfg(users do not need to care)**/		
	#define PRE_MCK_SYSCLK_S			(0)
#elif(CFG_SYS_SYSTEM_CLOCK== 1)
	/** @attention	sys_eck clock frequency(user cannot modify)**/
	#define C_CLK_SYSECK				(-1)
	/** @attention	sys_ick clock frequency(user cannot modify)**/
	#define C_CLK_SYSICK				(24000000u)
	/** @attention	sys_clk clock frequency(user cannot modify)**/
	#define C_CLK_SYSCLK				(24000000u)
	/** @attention	cpu_clk clock frequency(user cannot modify)**/
	#define C_CLK_CPUCLK				(12000000u)
	/** @attention	wwdt_clk clock frequency(user cannot modify)**/
	#define C_CLK_WWDTCLK				(C_CLK_CPUCLK/ 24576)
	/** @attention	reg cfg(users do not need to care)**/		
	#define PRE_MCK_CST_XT				(0)
	/** @attention	reg cfg(users do not need to care)**/		
	#define PRE_MCK_CST_IN				(1)
	/** @attention	reg cfg(users do not need to care)**/		
	#define PRE_MCK_SYSCLK_S			(0)
#elif(CFG_SYS_SYSTEM_CLOCK== 2)
	/** @attention	sys_eck clock frequency(user cannot modify)**/
	#define C_CLK_SYSECK				(-1)
	/** @attention	sys_ick clock frequency(user cannot modify)**/
	#define C_CLK_SYSICK				(24000000u)
	/** @attention	sys_clk clock frequency(user cannot modify)**/
	#define C_CLK_SYSCLK				(24000000u)
	/** @attention	cpu_clk clock frequency(user cannot modify)**/
	#define C_CLK_CPUCLK				(6000000u)
	/** @attention	wwdt_clk clock frequency(user cannot modify)**/
	#define C_CLK_WWDTCLK				(C_CLK_CPUCLK/ 24576)
	/** @attention	reg cfg(users do not need to care)**/		
	#define PRE_MCK_CST_XT				(0)
	/** @attention	reg cfg(users do not need to care)**/		
	#define PRE_MCK_CST_IN				(1)
	/** @attention	reg cfg(users do not need to care)**/		
	#define PRE_MCK_SYSCLK_S			(0)
#elif(CFG_SYS_SYSTEM_CLOCK== 3)
	/** @attention	sys_eck clock frequency(user cannot modify)**/
	#define C_CLK_SYSECK				(24000000u)
	/** @attention	sys_ick clock frequency(user cannot modify)**/
	#define C_CLK_SYSICK				(-1)
	/** @attention	sys_clk clock frequency(user cannot modify)**/
	#define C_CLK_SYSCLK				(24000000u)
	/** @attention	cpu_clk clock frequency(user cannot modify)**/
	#define C_CLK_CPUCLK				(24000000u)
	/** @attention	wwdt_clk clock frequency(user cannot modify)**/
	#define C_CLK_WWDTCLK				(C_CLK_CPUCLK/ 24576)
	/** @attention	reg cfg(users do not need to care)**/		
	#define PRE_MCK_CST_XT				(1)
	/** @attention	reg cfg(users do not need to care)**/		
	#define PRE_MCK_CST_IN				(0)
	/** @attention	reg cfg(users do not need to care)**/		
	#define PRE_MCK_SYSCLK_S			(1)
#elif(CFG_SYS_SYSTEM_CLOCK== 4)
	/** @attention	sys_eck clock frequency(user cannot modify)**/
	#define C_CLK_SYSECK				(24000000u)
	/** @attention	sys_ick clock frequency(user cannot modify)**/
	#define C_CLK_SYSICK				(-1)
	/** @attention	sys_clk clock frequency(user cannot modify)**/
	#define C_CLK_SYSCLK				(24000000u)
	/** @attention	cpu_clk clock frequency(user cannot modify)**/
	#define C_CLK_CPUCLK				(12000000u)
	/** @attention	wwdt_clk clock frequency(user cannot modify)**/
	#define C_CLK_WWDTCLK				(C_CLK_CPUCLK/ 24576)
	/** @attention	reg cfg(users do not need to care)**/		
	#define PRE_MCK_CST_XT				(1)
	/** @attention	reg cfg(users do not need to care)**/		
	#define PRE_MCK_CST_IN				(0)
	/** @attention	reg cfg(users do not need to care)**/		
	#define PRE_MCK_SYSCLK_S			(1)
#elif(CFG_SYS_SYSTEM_CLOCK== 5)
	/** @attention	sys_eck clock frequency(user cannot modify)**/
	#define C_CLK_SYSECK				(24000000u)
	/** @attention	sys_ick clock frequency(user cannot modify)**/
	#define C_CLK_SYSICK				(-1)
	/** @attention	sys_clk clock frequency(user cannot modify)**/
	#define C_CLK_SYSCLK				(24000000u)
	/** @attention	cpu_clk clock frequency(user cannot modify)**/
	#define C_CLK_CPUCLK				(6000000u)
	/** @attention	wwdt_clk clock frequency(user cannot modify)**/
	#define C_CLK_WWDTCLK				((C_CLK_CPUCLK/ 24576)
	/** @attention	reg cfg(users do not need to care)**/		
	#define PRE_MCK_CST_XT				(1)
	/** @attention	reg cfg(users do not need to care)**/		
	#define PRE_MCK_CST_IN				(0)
	/** @attention	reg cfg(users do not need to care)**/		
	#define PRE_MCK_SYSCLK_S			(1)
#elif(CFG_SYS_SYSTEM_CLOCK== 6)
	
#endif


#if(CFG_SYS_OSC_CURR== 0)
	/** @attention	crystal oscillator circuit bias current(user cannot modify)**/
	#define C_OSC_CURR					(64u)
	/** @attention	reg cfg(users do not need to care)**/		
	#define PRE_MCK_XT_GM				(0)
#elif(CFG_SYS_OSC_CURR== 1)
	/** @attention	crystal oscillator circuit bias current(user cannot modify)**/
	#define C_OSC_CURR					(128u)
	/** @attention	reg cfg(users do not need to care)**/		
	#define PRE_MCK_XT_GM				(1)
#elif(CFG_SYS_OSC_CURR== 2)
	/** @attention	crystal oscillator circuit bias current(user cannot modify)**/
	#define C_OSC_CURR					(256u)
	/** @attention	reg cfg(users do not need to care)**/		
	#define PRE_MCK_XT_GM				(2)
#elif(CFG_SYS_OSC_CURR== 3)
	/** @attention	crystal oscillator circuit bias current(user cannot modify)**/
	#define C_OSC_CURR					(512u)
	/** @attention	reg cfg(users do not need to care)**/		
	#define PRE_MCK_XT_GM				(3)
#endif


	/** @attention	reg cfg(users do not need to care)**/		
#define PRE_TCTRIM_TC_TRIM				(CFG_SYS_TC_TRIM& 0x07)


#if(CFG_SYS_CLK_T3_SOURCE== 0)
	/** @attention	timer3 clock source frequency(user cannot modify)**/
	#define C_CLK_CKT3					C_CLK_CPUCLK
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL0_T3CKS			(0)
#elif(CFG_SYS_CLK_T3_SOURCE== 1)
	/** @attention	timer3 clock source frequency(user cannot modify)**/
	#define C_CLK_CKT3					C_CLK_SYSCLK
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL0_T3CKS			(1)
#elif(CFG_SYS_CLK_T3_SOURCE== 2)
	/** @attention	timer3 clock source frequency(user cannot modify)**/
	#define C_CLK_CKT3					C_CLK_SYSECK
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL0_T3CKS			(2)
#elif(CFG_SYS_CLK_T3_SOURCE== 3)
	/** @attention	timer3 clock source frequency(user cannot modify)**/
	#define C_CLK_CKT3					(-1)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL0_T3CKS			(3)
#endif


#if(CFG_SYS_CLK_T2_SOURCE== 0)
	/** @attention	timer2 clock source frequency(user cannot modify)**/
	#define C_CLK_CKT2					C_CLK_CPUCLK
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL0_T2CKS			(0)
#elif(CFG_SYS_CLK_T2_SOURCE== 1)
	/** @attention	timer2 clock source frequency(user cannot modify)**/
	#define C_CLK_CKT2					C_CLK_SYSCLK
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL0_T2CKS			(1)
#elif(CFG_SYS_CLK_T2_SOURCE== 2)
	/** @attention	timer2 clock source frequency(user cannot modify)**/
	#define C_CLK_CKT2					C_CLK_SYSECK
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL0_T2CKS			(2)
#elif(CFG_SYS_CLK_T2_SOURCE== 3)
	/** @attention	timer2 clock source frequency(user cannot modify)**/
	#define C_CLK_CKT2					C_CLK_WDTCLK
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL0_T2CKS			(3)
#endif


#if(CFG_SYS_CLK_T0_SOURCE== 0)
	/** @attention	timer0 clock source frequency(user cannot modify)**/
	#define C_CLK_CKT0					C_CLK_CPUCLK
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL0_T0CKS			(0)
#elif(CFG_SYS_CLK_T0_SOURCE== 1)	
	/** @attention	timer0 clock source frequency(user cannot modify)**/
	#define C_CLK_CKT0					C_CLK_SYSCLK
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL0_T0CKS			(1)
#elif(CFG_SYS_CLK_T0_SOURCE== 2)	
	/** @attention	timer0 clock source frequency(user cannot modify)**/
	#define C_CLK_CKT0					C_CLK_SYSECK
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL0_T0CKS			(2)
#elif(CFG_SYS_CLK_T0_SOURCE== 3)	
	/** @attention	timer0 clock source frequency(user cannot modify)**/
	#define C_CLK_CKT0					C_CLK_WDTCLK
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL0_T0CKS			(3)
#endif


#if(CFG_SYS_URTCKS_SOURCE== 0)
	/** @attention	uart clock source frequency(user cannot modify)**/
	#define C_CLK_CKUR0					C_CLK_SYSCLK
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL1_URTCKS			(0)
#elif(CFG_SYS_URTCKS_SOURCE== 1)
	/** @attention	uart clock source frequency(user cannot modify)**/
	#define C_CLK_CKUR0					C_CLK_SYSECK
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL1_URTCKS			(1)
#elif(CFG_SYS_URTCKS_SOURCE== 2)
	/** @attention	uart clock source frequency(user cannot modify)**/
	#define C_CLK_CKUR0					(-1)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL1_URTCKS			(2)
#elif(CFG_SYS_URTCKS_SOURCE== 3)
	/** @attention	uart clock source frequency(user cannot modify)**/
	#define C_CLK_CKUR0					(-1)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL1_URTCKS			(3)
#endif


#if(CFG_SYS_PDS_SOURCE== 0)
	/** @attention	pd clock source frequency(user cannot modify)**/
	#define C_PDS_SOURCE				C_CLK_CPUCLK
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL2_PDS				(0)
#elif(CFG_SYS_PDS_SOURCE== 1)
	/** @attention	pd clock source frequency(user cannot modify)**/
	#define C_PDS_SOURCE				C_CLK_SYSCLK
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL2_PDS				(1)
#elif(CFG_SYS_PDS_SOURCE== 2)	
	/** @attention	pd clock source frequency(user cannot modify)**/
	#define C_PDS_SOURCE				(-1)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL2_PDS				(2)
#elif(CFG_SYS_PDS_SOURCE== 3)	
	/** @attention	pd clock source frequency(user cannot modify)**/
	#define C_PDS_SOURCE				(-1)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL2_PDS				(3)
#endif


#if(CFG_SYS_TYPCS_SOURCE== 0)
	/** @attention	typec clock source frequency(user cannot modify)**/
	#define C_TYPCS_SOURCE				C_CLK_WDTCLK
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL2_TYPCS			(0)
#elif(CFG_SYS_TYPCS_SOURCE== 1)
	/** @attention	typec clock source frequency(user cannot modify)**/
	#define C_TYPCS_SOURCE				C_CLK_WDTCLK
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL2_TYPCS			(1)
#elif(CFG_SYS_TYPCS_SOURCE== 2)	
	/** @attention	typec clock source frequency(user cannot modify)**/
	#define C_TYPCS_SOURCE				(C_CLK_SYSCLK/ 2048)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL2_TYPCS			(2)
#elif(CFG_SYS_TYPCS_SOURCE== 3)
	/** @attention	typec clock source frequency(user cannot modify)**/
	#define C_TYPCS_SOURCE				(-1)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL2_TYPCS			(3)
#endif


#if(CFG_SYS_CLK_T4_SOURCE== 0)
	/** @attention	timer4 clock source frequency(user cannot modify)**/
	#define C_CLK_CKT4					C_CLK_CPUCLK
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL2_T4CKS			(0)
#elif(CFG_SYS_CLK_T4_SOURCE== 1)	
	/** @attention	timer4 clock source frequency(user cannot modify)**/
	#define C_CLK_CKT4					C_CLK_SYSCLK
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL2_T4CKS			(1)
#elif(CFG_SYS_CLK_T4_SOURCE== 2)	
	/** @attention	timer4 clock source frequency(user cannot modify)**/
	#define C_CLK_CKT4					C_CLK_SYSECK
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL2_T4CKS			(2)
#elif(CFG_SYS_CLK_T4_SOURCE== 3)	
	/** @attention	timer4 clock source frequency(user cannot modify)**/
	#define C_CLK_CKT4					(-1)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKSEL2_T4CKS			(3)
#endif


#if(CFG_SYS_CLK_T0_DIV== 0)
	/** @attention	timer0 clock source frequency(user cannot modify)**/
	#define C_CLK_TM0CLK				C_CLK_CKT0
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV0_T0DIV			(0)
#elif(CFG_SYS_CLK_T0_DIV== 1)
	/** @attention	timer0 clock source frequency(user cannot modify)**/
	#define C_CLK_TM0CLK				(C_CLK_CKT0/ 2)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV0_T0DIV			(1)
#elif(CFG_SYS_CLK_T0_DIV== 2)	
	/** @attention	timer0 clock source frequency(user cannot modify)**/
	#define C_CLK_TM0CLK				(C_CLK_CKT0/ 4)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV0_T0DIV			(2)
#elif(CFG_SYS_CLK_T0_DIV== 3)
	/** @attention	timer0 clock source frequency(user cannot modify)**/
	#define C_CLK_TM0CLK				(C_CLK_CKT0/ 8)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV0_T0DIV			(3)
#elif(CFG_SYS_CLK_T0_DIV== 4)
	/** @attention	timer0 clock source frequency(user cannot modify)**/
	#define C_CLK_TM0CLK				(C_CLK_CKT0/ 16)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV0_T0DIV			(4)
#elif(CFG_SYS_CLK_T0_DIV== 5)
	/** @attention	timer0 clock source frequency(user cannot modify)**/
	#define C_CLK_TM0CLK				(C_CLK_CKT0/ 32)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV0_T0DIV			(5)
#elif(CFG_SYS_CLK_T0_DIV== 6)
	/** @attention	timer0 clock source frequency(user cannot modify)**/
	#define C_CLK_TM0CLK				(C_CLK_CKT0/ 64)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV0_T0DIV			(6)
#elif(CFG_SYS_CLK_T0_DIV== 7)
	/** @attention	timer0 clock source frequency(user cannot modify)**/
	#define C_CLK_TM0CLK				(C_CLK_CKT0/ 128)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV0_T0DIV			(7)
#endif


#if(CFG_SYS_CLK_T3_DIV== 0)
	/** @attention	timer3 clock source frequency(user cannot modify)**/
	#define C_CLK_TM3CLK				C_CLK_CKT3
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV1_T3DIV			(0)
#elif(CFG_SYS_CLK_T3_DIV== 1)
	/** @attention	timer3 clock source frequency(user cannot modify)**/
	#define C_CLK_TM3CLK				(C_CLK_CKT3/ 2)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV1_T3DIV			(1)
#elif(CFG_SYS_CLK_T3_DIV== 2)
	/** @attention	timer3 clock source frequency(user cannot modify)**/
	#define C_CLK_TM3CLK				(C_CLK_CKT3/ 4)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV1_T3DIV			(2)
#elif(CFG_SYS_CLK_T3_DIV== 3)
	/** @attention	timer3 clock source frequency(user cannot modify)**/
	#define C_CLK_TM3CLK				(C_CLK_CKT3/ 8)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV1_T3DIV			(3)
#elif(CFG_SYS_CLK_T3_DIV== 4)
	/** @attention	timer3 clock source frequency(user cannot modify)**/
	#define C_CLK_TM3CLK				(C_CLK_CKT3/ 16)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV1_T3DIV			(4)
#elif(CFG_SYS_CLK_T3_DIV== 5)
	/** @attention	timer3 clock source frequency(user cannot modify)**/
	#define C_CLK_TM3CLK				(C_CLK_CKT3/ 32)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV1_T3DIV			(5)
#elif(CFG_SYS_CLK_T3_DIV== 6)
	/** @attention	timer3 clock source frequency(user cannot modify)**/
	#define C_CLK_TM3CLK				(C_CLK_CKT3/ 64)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV1_T3DIV			(6)
#elif(CFG_SYS_CLK_T3_DIV== 7)
	/** @attention	timer3 clock source frequency(user cannot modify)**/
	#define C_CLK_TM3CLK				(C_CLK_CKT3/ 128)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV1_T3DIV			(7)
#endif


#if(CFG_SYS_CLK_T2_DIV== 0)
	/** @attention	timer2 clock source frequency(user cannot modify)**/
	#define C_CLK_TM2CLK				C_CLK_CKT2
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV1_T2DIV			(0)
#elif(CFG_SYS_CLK_T2_DIV== 1)	
	/** @attention	timer2 clock source frequency(user cannot modify)**/
	#define C_CLK_TM2CLK				(C_CLK_CKT2/ 2)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV1_T2DIV			(1)
#elif(CFG_SYS_CLK_T2_DIV== 2)	
	/** @attention	timer2 clock source frequency(user cannot modify)**/
	#define C_CLK_TM2CLK				(C_CLK_CKT2/ 4)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV1_T2DIV			(2)
#elif(CFG_SYS_CLK_T2_DIV== 3)	
	/** @attention	timer2 clock source frequency(user cannot modify)**/
	#define C_CLK_TM2CLK				(C_CLK_CKT2/ 8)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV1_T2DIV			(3)
#elif(CFG_SYS_CLK_T2_DIV== 4)	
	/** @attention	timer2 clock source frequency(user cannot modify)**/
	#define C_CLK_TM2CLK				(C_CLK_CKT2/ 16)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV1_T2DIV			(4)
#elif(CFG_SYS_CLK_T2_DIV== 5)	
	/** @attention	timer2 clock source frequency(user cannot modify)**/
	#define C_CLK_TM2CLK				(C_CLK_CKT2/ 32)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV1_T2DIV			(5)
#elif(CFG_SYS_CLK_T2_DIV== 6)	
	/** @attention	timer2 clock source frequency(user cannot modify)**/
	#define C_CLK_TM2CLK				(C_CLK_CKT2/ 64)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV1_T2DIV			(6)
#elif(CFG_SYS_CLK_T2_DIV== 7)	
	/** @attention	timer2 clock source frequency(user cannot modify)**/
	#define C_CLK_TM2CLK				(C_CLK_CKT2/ 128)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV1_T2DIV			(7)
#endif


#if(CFG_SYS_CLK_UART_DIV== 0)
	/** @attention	uart clock source frequency(user cannot modify)**/
	#define C_CLK_UR0CLK				(C_CLK_CKUR0/ 2)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV2_URTDIV			(0)
#elif(CFG_SYS_CLK_UART_DIV== 1)	
	/** @attention	uart clock source frequency(user cannot modify)**/
	#define C_CLK_UR0CLK				(C_CLK_CKUR0/ 4)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV2_URTDIV			(1)
#elif(CFG_SYS_CLK_UART_DIV== 2)	
	/** @attention	uart clock source frequency(user cannot modify)**/
	#define C_CLK_UR0CLK				(C_CLK_CKUR0/ 8)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV2_URTDIV			(2)
#elif(CFG_SYS_CLK_UART_DIV== 3)	
	/** @attention	uart clock source frequency(user cannot modify)**/
	#define C_CLK_UR0CLK				(C_CLK_CKUR0/ 16)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV2_URTDIV			(3)
#elif(CFG_SYS_CLK_UART_DIV== 4)	
	/** @attention	uart clock source frequency(user cannot modify)**/
	#define C_CLK_UR0CLK				(C_CLK_CKUR0/ 32)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV2_URTDIV			(4)
#elif(CFG_SYS_CLK_UART_DIV== 5)	
	/** @attention	uart clock source frequency(user cannot modify)**/
	#define C_CLK_UR0CLK				(C_CLK_CKUR0/ 64)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV2_URTDIV			(5)
#elif(CFG_SYS_CLK_UART_DIV== 6)	
	/** @attention	uart clock source frequency(user cannot modify)**/
	#define C_CLK_UR0CLK				(C_CLK_CKUR0/ 64)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV2_URTDIV			(6)
#elif(CFG_SYS_CLK_UART_DIV== 7)	
	/** @attention	uart clock source frequency(user cannot modify)**/
	#define C_CLK_UR0CLK				(C_CLK_CKUR0/ 64)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV2_URTDIV			(7)
#endif


#if(CFG_SYS_CLK_T4_DIV== 0)
	/** @attention	timer4 clock source frequency(user cannot modify)**/
	#define C_CLK_TM4CLK				C_CLK_CKT4
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV3_T4DIV			(0)
#elif(CFG_SYS_CLK_T4_DIV== 1)
	/** @attention	timer4 clock source frequency(user cannot modify)**/
	#define C_CLK_TM4CLK				(C_CLK_CKT4/ 2)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV3_T4DIV			(1)
#elif(CFG_SYS_CLK_T4_DIV== 2)	
	/** @attention	timer4 clock source frequency(user cannot modify)**/
	#define C_CLK_TM4CLK				(C_CLK_CKT4/ 4)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV3_T4DIV			(2)
#elif(CFG_SYS_CLK_T4_DIV== 3)	
	/** @attention	timer4 clock source frequency(user cannot modify)**/
	#define C_CLK_TM4CLK				(C_CLK_CKT4/ 8)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV3_T4DIV			(3)
#elif(CFG_SYS_CLK_T4_DIV== 4)	
	/** @attention	timer4 clock source frequency(user cannot modify)**/
	#define C_CLK_TM4CLK				(C_CLK_CKT4/ 16)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV3_T4DIV			(4)
#elif(CFG_SYS_CLK_T4_DIV== 5)	
	/** @attention	timer4 clock source frequency(user cannot modify)**/
	#define C_CLK_TM4CLK				(C_CLK_CKT4/ 32)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV3_T4DIV			(5)
#elif(CFG_SYS_CLK_T4_DIV== 6)	
	/** @attention	timer4 clock source frequency(user cannot modify)**/
	#define C_CLK_TM4CLK				(C_CLK_CKT4/ 64)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV3_T4DIV			(6)
#elif(CFG_SYS_CLK_T4_DIV== 7)	
	/** @attention	timer4 clock source frequency(user cannot modify)**/
	#define C_CLK_TM4CLK				(C_CLK_CKT4/ 128)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV3_T4DIV			(7)
#endif


/** @attention	adc clock source frequency(user cannot modify)**/
#define C_CLK_CKADC						C_CLK_CPUCLK


#if(CFG_SYS_CLK_ADC_DIV== 0)
	/** @attention	adc clock source frequency(user cannot modify)**/
	#define C_CLK_ADCCLK				(C_CLK_CKADC/ 4)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV3_SRADCKS			(0)
#elif(CFG_SYS_CLK_ADC_DIV== 1)	
	/** @attention	adc clock source frequency(user cannot modify)**/
	#define C_CLK_ADCCLK				(C_CLK_CKADC/ 4)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV3_SRADCKS			(1)
#elif(CFG_SYS_CLK_ADC_DIV== 2)	
	/** @attention	adc clock source frequency(user cannot modify)**/
	#define C_CLK_ADCCLK				(C_CLK_CKADC/ 8)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV3_SRADCKS			(2)
#elif(CFG_SYS_CLK_ADC_DIV== 3)	
	/** @attention	adc clock source frequency(user cannot modify)**/
	#define C_CLK_ADCCLK				(C_CLK_CKADC/ 16)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV3_SRADCKS			(3)
#endif


/** @attention	scp clock source frequency(user cannot modify)**/
#define C_CLK_CKSCP						C_CLK_SYSCLK


#if(CFG_SYS_CLK_SCP_DIV== 0)
	/** @attention	scp clock source frequency(user cannot modify)**/
	#define C_CLK_SCPCLK				(C_CLK_CKSCP/ 8)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV4_SCPDIV			(0)
#elif(CFG_SYS_CLK_SCP_DIV== 1)
	/** @attention	scp clock source frequency(user cannot modify)**/
	#define C_CLK_SCPCLK				(C_CLK_CKSCP/ 16)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV4_SCPDIV			(1)
#elif(CFG_SYS_CLK_SCP_DIV== 2)	
	/** @attention	scp clock source frequency(user cannot modify)**/
	#define C_CLK_SCPCLK				(C_CLK_CKSCP/ 24)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV4_SCPDIV			(2)
#elif(CFG_SYS_CLK_SCP_DIV== 3)	
	/** @attention	scp clock source frequency(user cannot modify)**/
	#define C_CLK_SCPCLK				(C_CLK_CKSCP/ 32)
	/** @attention	reg cfg(users do not need to care)**/	
	#define PRE_CLKDIV4_SCPDIV			(3)
#endif
/**@}*/ /*** end of group system_compile */



/** 
 * @addtogroup system_api api
 * @{
 */
/**@brief system initialization.
 * 
 * @return  null.
 * @par 示例
 * @code
 * 	void main(void)
 * 	{
 * 		//system init
 * 	    SystemInit();
 * 	}
 * @endcode
 */
void SystemInit(void);
/**@}*/ /*** end of group system_api */

/**@}*/ /*** end of group csu39fx10_sdk_chip_misc_system */
/**@}*/ /*** end of group csu39fx10_sdk_chip_misc */
/**@}*/ /*** end of group csu39fx10_sdk_chip */
/*******************************************************************************/




/******************************** dividing line ********************************/
/**
 * RAM MAP
 *			 ______________________________________________________________
 *			|														 		|	0x000
 *			|				core SFR								 		|
 *			|				16Bytes									 		|
 *			|_______________________________________________________________|	0x00F
 *			|														 		|	0x010
 *			|				peripheral SFR							 		|
 *			|				336Bytes								 		|
 *			|_______________________________________________________________|
 *			|		|		|		|								 		|	
 *			| SFR	| SFR	| SFR	| RESERVED						 		|	
 *			| Page0	| Page1	| Page1	|								 		|	
 *			| 112B	| 112B	| 112B	|								 		|	
 *			|_______|_______|_______|_______________________________________|	0x07F
 *			|														 		|	0x080
 *			|               SRAM               						 		|
 *			|               2000Bytes                                       |
 *			|_______________________________________________________________|
 *			|		|		|		|		|		|		|				|
 *			| SRAM	| SRAM	| SRAM	| SRAM	| SRAM	| SRAM	| 				|
 *			| Bank0	| Bank2	| Bank4	| Bank6	| Bank8	| Bank10|				|
 *			| 128B	| 128B	| 128B	| 128B	| 128B	| 80B	|				|
 *			|_______|_______|_______|_______|_______|_______|				|	0x0FF
 *			|		|		|		|		|		|						|	0x100
 *			| SRAM	| SRAM	| SRAM	| SRAM	| SRAM	|		 RESERVED		|
 *			| Bank1	| Bank3	| Bank5	| Bank7	| Bank9	|						|
 *			| 256B	| 256B	| 256B	| 256B	| 256B	|						|
 *			|_______|_______|_______|_______|_______|_______________________|	0x1FF
 *			  Page0	  Page1	  Page2	  Page3	  Page4	  Page5	
**/


#ifdef __cplusplus
}
#endif

#endif  //__SYSTEM_CSU39FX10_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/
