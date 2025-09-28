/***************************************************************************
 * @file     csu39fx10_clkmu.h
 * @version  V1.0.0
 * @author   0531
 * @date     2020-09-23 AM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 ****************************************************************************
 * @par 头文件
 *       csu39fx10.h \n
 *       cs_common.h \n
 *       system_csu39fx10.h
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

#ifndef __CSU39FX10_CLKMU_H__
#define __CSU39FX10_CLKMU_H__

// Include external header file.
#include "csu39fx10.h"
#include "cs_common.h"
#include "system_csu39fx10.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @addtogroup csu39fx10_sdk_chip csu39fx10_sdk_chip
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_fwlib fwlib 
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_fwlib_clkmu clkmu 
 * 
 * @details <b>reg: MCK(0x00H)</b>
 * | bit	| identifier	| descriptions	| defaults(0b01111100)	| reference	|
 * | :----:	| :----:		| :----:		| :----:				| :----:	|
 * | 7		| CST_XT		|External high-speed crystal enable: \n 0*= disable, \n 1= enable| 0	| @ref __CST_XT_EN_GET() \n @ref __CST_XT_EN_SET(EN) \n @ref __CST_XT_EN_GET_SHIFT() \n @ref __CST_XT_EN_SET_SHIFT(POS_EN)	|
 * | 6		| CST_IN		|Internal high-speed RC oscillator enable: \n 0= disable, \n 1*= enable| 1	| @ref __CST_IN_EN_GET() \n @ref __CST_IN_EN_SET(EN) \n @ref __CST_IN_EN_GET_SHIFT() \n @ref __CST_IN_EN_SET_SHIFT(POS_EN)	|
 * | 5		| CST_WDT		|WDT oscillator start switch: \n 0= disable(if WDT_CFG is not configured), \n 1*= enable(if WDT_CFG is not configured)| 1	| @ref __CST_WDT_EN_GET() \n @ref __CST_WDT_EN_SET(EN) \n @ref __CST_WDT_EN_GET_SHIFT() \n @ref __CST_WDT_EN_SET_SHIFT(POS_EN)	|
 * | 4: 2	| XT_GM[2:0]	|Crystal oscillator circuit bias current (control transconductance) selection: \n 000= 64uA, \n 001= 128uA, \n 010= 256uA, \n 011*= 512uA, \n 1xx= Reserved| 011	| @ref __XT_BIAS_CURRENT_GET() \n @ref __XT_BIAS_CURRENT_SET(EN) \n @ref __XT_BIAS_CURRENT_GET_SHIFT() \n @ref __XT_BIAS_CURRENT_SET_SHIFT(POS_EN)	|
 * | 1: 0	| SYSCLK_S[1:0]	|System clock selection: \n 00*= ICK, \n 01= ECK, \n 1x= Reserved| 00	| @ref __SYSCLK_CLK_SOURCE_GET() \n @ref __SYSCLK_CLK_SOURCE_SET(EN) \n @ref __SYSCLK_CLK_SOURCE_GET_SHIFT() \n @ref __SYSCLK_CLK_SOURCE_SET_SHIFT(POS_EN)	|
 * 
 * @details <b>reg: TCTRIM(0x01H)</b>
 * | bit	| identifier	| descriptions	| defaults(0buuuuu100)	| reference	|
 * | :----:	| :----:		| :----:		| :----:				| :----:	|
 * | 7: 3	| Reserved		| | | |
 * | 2: 0	| TC_TRIM[2:0]	|Internal high-speed clock temperature TRIM value: \n 0~ 7| 100	| @ref __TX_CLK_TRIM_GET() \n @ref __TX_CLK_TRIM_SET(EN) \n @ref __TX_CLK_TRIM_GET_SHIFT() \n @ref __TX_CLK_TRIM_SET_SHIFT(POS_EN)	|
 * 
 * @details <b>reg: CLKSEL0(0x02H)</b>
 * | bit	| identifier	| descriptions	| defaults(0b0000uu00)	| reference	|
 * | :----:	| :----:		| :----:		| :----:				| :----:	|
 * | 7: 6	| T3CKS[1:0]	|Timer 3 clock source selection: \n 00*= CPUCLK, \n 01= SYSCLK, \n 10= ECK, \n 11= PT1.2 external event input| 00	| @ref __T3_CLK_SOURCE_GET() \n @ref __T3_CLK_SOURCE_SET(EN) \n @ref __T3_CLK_SOURCE_GET_SHIFT() \n @ref __T3_CLK_SOURCE_SET_SHIFT(POS_EN)	|
 * | 5: 4	| T2CKS[1:0]	|Timer 2 clock source selection: \n 00*= CPUCLK, \n 01= SYSCLK, \n 10= ECK, \n 11= WDT_CLK| 00	| @ref __T2_CLK_SOURCE_GET() \n @ref __T2_CLK_SOURCE_SET(EN) \n @ref __T2_CLK_SOURCE_GET_SHIFT() \n @ref __T2_CLK_SOURCE_SET_SHIFT(POS_EN)	|
 * | 3: 2	| Reserved		| | | |
 * | 1: 0	| T0CKS[1:0]	|Timer 0 clock source selection: \n 00*= CPUCLK, \n 01= SYSCLK, \n 10= ECK, \n 11= WDT_CLK| 00	|@ref __T0_CLK_SOURCE_GET() \n @ref __T0_CLK_SOURCE_SET(EN) \n @ref __T0_CLK_SOURCE_GET_SHIFT() \n @ref __T0_CLK_SOURCE_SET_SHIFT(POS_EN)	|
 * 
 * @details <b>reg: CLKSEL1(0x03H)</b>
 * | bit	| identifier	| descriptions	| defaults(0buuuu00uu)	| reference	|
 * | :----:	| :----:		| :----:		| :----:				| :----:	|
 * | 7: 4	| Reserved		| | | |
 * | 3: 2	| URTCKS[1:0]	|Serial clock source selection: \n 00*= SYSCLK, \n 01= ECK, \n 1x= Reserved| 00	|@ref __UART_CLK_SOURCE_GET() \n @ref __UART_CLK_SOURCE_SET(EN) \n @ref __UART_CLK_SOURCE_GET_SHIFT() \n @ref __UART_CLK_SOURCE_SET_SHIFT(POS_EN)	|
 * | 1: 0	| Reserved		| | | |
 * 
 * @details <b>reg: CLKSEL2(0x04H)</b>
 * | bit	| identifier	| descriptions	| defaults(0buu000000)	| reference	|
 * | :----:	| :----:		| :----:		| :----:				| :----:	|
 * | 7: 6	| Reserved		| | | |
 * | 5: 4	| PDS[1:0]		|USB PD module clock source selection: \n 00*= CPUCLK, \n 01= SYSCLK, \n 1x= Reserved| 00	| @ref __PD_CLK_SOURCE_GET() \n @ref __PD_CLK_SOURCE_SET(EN) \n @ref __PD_CLK_SOURCE_GET_SHIFT() \n @ref __PD_CLK_SOURCE_SET_SHIFT(POS_EN)	|
 * | 3: 2	| TYPCS[1:0]	|USB Type-C module clock source selection: \n 00*= WDT_CLK, \n 01= SYSCLK/ 2048, \n 1x= Reserved| 00	| @ref __TYPEC_CLOCK_SOURCE_GET() \n @ref __TYPEC_CLOCK_SOURCE_SET(EN) \n @ref __TYPEC_CLOCK_SOURCE_GET_SHIFT() \n @ref __TYPEC_CLOCK_SOURCE_SET_SHIFT(POS_EN)	|
 * | 1: 0	| T4CKS[1:0]	|Timer 4 clock source selection: \n 00*= CPUCLK, \n 01= SYSCLK, \n 10= ECK, \n 11= Reserved| 00	| @ref __T4_CLK_SOURCE_GET() \n @ref __T4_CLK_SOURCE_SET(EN) \n @ref __T4_CLK_SOURCE_GET_SHIFT() \n @ref __T4_CLK_SOURCE_SET_SHIFT(POS_EN)	|
 * 
 * @details <b>reg: CLKDIV0(0x05H)</b>
 * | bit	| identifier	| descriptions	| defaults(0buuuuu000)	| reference	|
 * | :----:	| :----:		| :----:		| :----:				| :----:	|
 * | 7: 3	| Reserved		| | | |
 * | 2: 0	| T0DIV[2:0]	|Timer 0 clock division selection: \n 000= CKT0*, \n 001= CKT0/ 2, \n 010= CKT0/ 4, \n 011= CKT0/ 8, \n 100= CKT0/ 16, \n 101= CKT0/ 32, \n 110= CKT0/ 64, \n 111= CKT0/ 128| 000	| @ref __T0_CLK_DIV_GET() \n @ref __T0_CLK_DIV_SET(EN) \n @ref __T0_CLK_DIV_GET_SHIFT() \n @ref __T0_CLK_DIV_SET_SHIFT(POS_EN)	|
 * 
 * @details <b>reg: CLKDIV1(0x06H)</b>
 * | bit	| identifier	| descriptions	| defaults(0bu000uuuu)	| reference	|
 * | :----:	| :----:		| :----:		| :----:				| :----:	|
 * | 7		| Reserved		| | | |
 * | 6: 4	| T3DIV[2:0]	|Timer 3 clock division selection: \n 000= CKT3*, \n 001= CKT3/ 2, \n 010= CKT3/ 4, \n 011= CKT3/ 8, \n 100= CKT3/ 16, \n 101= CKT3/ 32, \n 110= CKT3/ 64, \n 111= CKT3/ 128| 000	| @ref __T3_CLK_DIV_GET() \n @ref __T3_CLK_DIV_SET(EN) \n @ref __T3_CLK_DIV_GET_SHIFT() \n @ref __T3_CLK_DIV_SET_SHIFT(POS_EN)	|
 * | 3		| Reserved		| | | |	
 * | 2: 0	| T2DIV[2:0]	|Timer 2 clock division selection: \n 000= CKT2*, \n 001= CKT2/ 2, \n 010= CKT2/ 4, \n 011= CKT2/ 8, \n 100= CKT2/ 16, \n 101= CKT2/ 32, \n 110= CKT2/ 64, \n 111= CKT2/ 128| 000	| @ref __T2_CLK_DIV_GET() \n @ref __T2_CLK_DIV_SET(EN) \n @ref __T2_CLK_DIV_GET_SHIFT() \n @ref __T2_CLK_DIV_SET_SHIFT(POS_EN)	|
 * 
 * @details <b>reg: CLKDIV2(0x07H)</b>
 * | bit	| identifier	| descriptions	| defaults(0bu0000000)	| reference	|
 * | :----:	| :----:		| :----:		| :----:				| :----:	|
 * | 7		| Reserved		| | | |
 * | 6: 4	| URTDIV[2:0]	|Uart clock division selection: \n 000= CKUART*, \n 001= CKUART/ 2, \n 010= CKUART/ 4, \n 011= CKUART/ 8, \n 100= CKUART/ 16, \n 101= CKUART/ 32, \n 110= CKUART/ 64, \n 111= CKUART/ 128| 000	| @ref __UART_CLK_DIV_GET() \n @ref __UART_CLK_DIV_SET(EN) \n @ref __UART_CLK_DIV_GET_SHIFT() \n @ref __UART_CLK_DIV_SET_SHIFT(POS_EN)	|
 * | 3: 0	| Reserved		| | | |
 * 
 * @details <b>reg: CLKDIV3(0x08H)</b>
 * | bit	| identifier	| descriptions	| defaults(0bu000uu00)	| reference	|
 * | :----:	| :----:		| :----:		| :----:				| :----:	|
 * | 7		| Reserved		| | | |
 * | 6: 4	| T4DIV[2:0]	|Timer 4 clock division selection: \n 000= CKT4*, \n 001= CKT4/ 2, \n 010= CKT4/ 4, \n 011= CKT4/ 8, \n 100= CKT4/ 16, \n 101= CKT4/ 32, \n 110= CKT4/ 64, \n 111= CKT4/ 128| 000	| @ref __T4_CLK_DIV_GET() \n @ref __T4_CLK_DIV_SET(EN) \n @ref __T4_CLK_DIV_GET_SHIFT() \n @ref __T4_CLK_DIV_SET_SHIFT(POS_EN)	|
 * | 3: 2	| Reserved		| | | |
 * | 1: 0	| SRADCKS[1:0]	|ADC clock frequency selection signal: \n 00= CPUCLK/ 4*, \n 01= CPUCLK/ 4, \n 10= CPUCLK/ 8, \n 11= CPUCLK/ 16| 00	| @ref __SRAD_CLK_DIV_GET() \n @ref __SRAD_CLK_DIV_SET(EN) \n @ref __SRAD_CLK_DIV_GET_SHIFT() \n @ref __SRAD_CLK_DIV_SET_SHIFT(POS_EN)	|
 * 
 * @details <b>reg: CLKDIV4(0x09H)</b>
 * | bit	| identifier	| descriptions	| defaults(0buuuuuu00)	| reference	|
 * | :----:	| :----:		| :----:		| :----:				| :----:	|
 * | 7: 2	| Reserved		| | | |
 * | 1: 0	| SCPDIV[1:0]	|SCP and VOOC module clock frequency division to generate 1MHz module working clock: \n 00= SYSCLK/ 8*, \n 01= SYSCLK/ 16, \n 10= SYSCLK/ 24, \n 11= SYSCLK/ 32| 00	| @ref __SCP_CLK_DIV_GET() \n @ref __SCP_CLK_DIV_SET(EN) \n @ref __SCP_CLK_DIV_GET_SHIFT() \n @ref __SCP_CLK_DIV_SET_SHIFT(POS_EN)	|
 * @{
 */

/** 
 * @addtogroup clkmu_reg_mck reg: MCK
 * @details <b>reg: MCK(0x00H)</b>
 * - bit: CST_XT
 * - bit: CST_IN
 * - bit: CST_WDT
 * - bit: XT_GM[4:2]
 * - bit: SYSCLK_S[1:0]
 * @par 示例
 * @code
 *	void test( void )
 *	{
 * 		uint8_t temp_a;
 * 		uint8_t temp_b;
 * 	
 * 		//get reg-bit value
 * 		temp_a= __CST_XT_EN_GET();
 * 		temp_b= __CST_XT_EN_GET_SHIFT();
 * 	
 * 		//set reg-bit value
 * 		__CST_XT_EN_SET(false);
 * 		__CST_XT_EN_SET(true);
 * 		__CST_XT_EN_SET_SHIFT(CLKMU_CST_XT_DIS);
 * 		__CST_XT_EN_SET_SHIFT(CLKMU_CST_XT_EN);
 * }
 * @endcode
 * @{
 */
//MCK
//CST_XT
#define CLKMU_CST_XT_REG							MCK																						///< bit CST_XT reg
#define CLKMU_CST_XT_POS							(7) 																					///< bit CST_XT offset
#define CLKMU_CST_XT_BITS							C_REG_BITS1 																			///< bit CST_XT bits
#define CLKMU_CST_XT_MASK							(CLKMU_CST_XT_BITS<< CLKMU_CST_XT_POS)													///< bit CST_XT mask
#define CLKMU_CST_XT_DIS							(0x00<< CLKMU_CST_XT_POS)																///< bit CST_XT enum disable
#define CLKMU_CST_XT_EN								(0x01<< CLKMU_CST_XT_POS)																///< bit CST_XT enum enable
#define __CST_XT_EN_GET()							M_REG_GET(CLKMU_CST_XT_REG, CLKMU_CST_XT_POS, CLKMU_CST_XT_BITS) 						///< bit CST_XT get 
#define __CST_XT_EN_SET(EN)							M_REG_SET(CLKMU_CST_XT_REG, CLKMU_CST_XT_POS, CLKMU_CST_XT_BITS, EN)					///< bit CST_XT set 
#define __CST_XT_EN_GET_SHIFT()						M_REG_GET_SHIFT(CLKMU_CST_XT_REG, CLKMU_CST_XT_POS, CLKMU_CST_XT_BITS)					///< bit CST_XT get 
#define __CST_XT_EN_SET_SHIFT(POS_EN)				M_REG_SET_SHIFT(CLKMU_CST_XT_REG, CLKMU_CST_XT_POS, CLKMU_CST_XT_BITS, POS_EN)  		///< bit CST_XT set 
       
//MCK
//CST_IN
#define CLKMU_CST_IN_REG							MCK                                                                             		///< bit CST_IN reg
#define CLKMU_CST_IN_POS							(6)                                                                             		///< bit CST_IN offset
#define CLKMU_CST_IN_BITS							C_REG_BITS1                                                                     		///< bit CST_IN bits
#define CLKMU_CST_IN_MASK							(CLKMU_CST_IN_BITS<< CLKMU_CST_IN_POS)                                          		///< bit CST_IN mask
#define CLKMU_CST_IN_DIS							(0x00<< CLKMU_CST_IN_POS)                                                       		///< bit CST_IN enum disabl
#define CLKMU_CST_IN_EN								(0x01<< CLKMU_CST_IN_POS)                                                       		///< bit CST_IN enum enable
#define __CST_IN_EN_GET()							M_REG_GET(CLKMU_CST_IN_REG, CLKMU_CST_IN_POS, CLKMU_CST_IN_BITS)                		///< bit CST_IN get 
#define __CST_IN_EN_SET(EN)							M_REG_SET(CLKMU_CST_IN_REG, CLKMU_CST_IN_POS, CLKMU_CST_IN_BITS, EN)            		///< bit CST_IN set 
#define __CST_IN_EN_GET_SHIFT()						M_REG_GET_SHIFT(CLKMU_CST_IN_REG, CLKMU_CST_IN_POS, CLKMU_CST_IN_BITS)          		///< bit CST_IN get 
#define __CST_IN_EN_SET_SHIFT(POS_EN)				M_REG_SET_SHIFT(CLKMU_CST_IN_REG, CLKMU_CST_IN_POS, CLKMU_CST_IN_BITS, POS_ENS) 		///< bit CST_IN set 

//MCK
//CST_WDT
#define CLKMU_CST_WDT_REG							MCK																						///< bit CST_WDT reg
#define CLKMU_CST_WDT_POS							(5)                                                                             		///< bit CST_WDT offset
#define CLKMU_CST_WDT_BITS							C_REG_BITS1                                                                     		///< bit CST_WDT bits
#define CLKMU_CST_WDT_MASK							(CLKMU_CST_WDT_BITS<< CLKMU_CST_WDT_POS)                                        		///< bit CST_WDT mask
#define CLKMU_CST_WDT_DIS							(0x00<< CLKMU_CST_WDT_POS)                                                      		///< bit CST_WDT enum disabl
#define CLKMU_CST_WDT_EN							(0x01<< CLKMU_CST_WDT_POS)                                                      		///< bit CST_WDT enum enable
#define __CST_WDT_EN_GET()							M_REG_GET(CLKMU_CST_WDT_REG, CLKMU_CST_WDT_POS, CLKMU_CST_WDT_BITS)             		///< bit CST_WDT get 
#define __CST_WDT_EN_SET(EN)						M_REG_SET(CLKMU_CST_WDT_REG, CLKMU_CST_WDT_POS, CLKMU_CST_WDT_BITS, EN)         		///< bit CST_WDT set 
#define __CST_WDT_EN_GET_SHIFT()					M_REG_GET_SHIFT(CLKMU_CST_WDT_REG, CLKMU_CST_WDT_POS, CLKMU_CST_WDT_BITS)       		///< bit CST_WDT get 
#define __CST_WDT_EN_SET_SHIFT(POS_EN)				M_REG_SET_SHIFT(CLKMU_CST_WDT_REG, CLKMU_CST_WDT_POS, CLKMU_CST_WDT_BITS, POS_EN)		///< bit CST_WDT set 

//MCK
//XT_GM[4:2]
#define CLKMU_XT_GM_REG								MCK																						///< bit XT_GM reg
#define CLKMU_XT_GM_POS								(2)                                                                                 	///< bit XT_GM offset
#define CLKMU_XT_GM_BITS							C_REG_BITS3                                                                         	///< bit XT_GM bits
#define CLKMU_XT_GM_MASK							(CLKMU_XT_GM_BITS<< CLKMU_XT_GM_POS)                                                	///< bit XT_GM mask
#define CLKMU_XT_GM_64UA							(0x00<< CLKMU_XT_GM_POS)                                                            	///< bit XT_GM enum 64UA
#define CLKMU_XT_GM_128UA							(0x01<< CLKMU_XT_GM_POS)                                                            	///< bit XT_GM enum 128UA
#define CLKMU_XT_GM_256UA							(0x02<< CLKMU_XT_GM_POS)                                                            	///< bit XT_GM enum 256UA 
#define CLKMU_XT_GM_512UA							(0x03<< CLKMU_XT_GM_POS)                                                            	///< bit XT_GM enum 512UA 
#define __XT_BIAS_CURRENT_GET()						M_REG_GET(CLKMU_XT_GM_REG, CLKMU_XT_GM_POS, CLKMU_XT_GM_BITS)                       	///< bit XT_GM get 
#define __XT_BIAS_CURRENT_SET(CLK)					M_REG_SET(CLKMU_XT_GM_REG, CLKMU_XT_GM_POS, CLKMU_XT_GM_BITS, CLK)                  	///< bit XT_GM set 
#define __XT_BIAS_CURRENT_GET_SHIFT()				M_REG_GET_SHIFT(CLKMU_XT_GM_REG, CLKMU_XT_GM_POS, CLKMU_XT_GM_BITS)                 	///< bit XT_GM get
#define __XT_BIAS_CURRENT_SET_SHIFT(POS_CLK)		M_REG_SET_SHIFT(CLKMU_XT_GM_REG, CLKMU_XT_GM_POS, CLKMU_XT_GM_BITS, POS_CLK)        	///< bit XT_GM set

//MCK
//SYSCLK_S[1:0]
#define CLKMU_SYSCLK_S_REG							MCK		                                                                             	///< bit SYSCLK_S reg
#define CLKMU_SYSCLK_S_POS							(0)                                                                                  	///< bit SYSCLK_S offset
#define CLKMU_SYSCLK_S_BITS							C_REG_BITS2                                                                          	///< bit SYSCLK_S bits
#define CLKMU_SYSCLK_S_MASK							(CLKMU_SYSCLK_S_BITS<< CLKMU_SYSCLK_S_POS)                                           	///< bit SYSCLK_S mask
#define CLKMU_SYSCLK_S_HIRC							(0x00<< CLKMU_SYSCLK_S_POS)                                                          	///< bit SYSCLK_S enum HIRC	
#define CLKMU_SYSCLK_S_HEXT							(0x01<< CLKMU_SYSCLK_S_POS)                                                          	///< bit SYSCLK_S enum HEXT	
#define CLKMU_SYSCLK_S_RES							(0x02<< CLKMU_SYSCLK_S_POS)                                                          	///< bit SYSCLK_S enum RES	
#define __SYSCLK_CLK_SOURCE_GET()					M_REG_GET(CLKMU_SYSCLK_S_REG, CLKMU_SYSCLK_S_POS, CLKMU_SYSCLK_S_BITS)               	///< bit SYSCLK_S get
#define __SYSCLK_CLK_SOURCE_SET(CLK)				M_REG_SET(CLKMU_SYSCLK_S_REG, CLKMU_SYSCLK_S_POS, CLKMU_SYSCLK_S_BITS, CLK)          	///< bit SYSCLK_S set  
#define __SYSCLK_CLK_SOURCE_GET_SHIFT()				M_REG_GET_SHIFT(CLKMU_SYSCLK_S_REG, CLKMU_SYSCLK_S_POS, CLKMU_SYSCLK_S_BITS)         	///< bit SYSCLK_S get  
#define __SYSCLK_CLK_SOURCE_SET_SHIFT(POS_CLK)		M_REG_SET_SHIFT(CLKMU_SYSCLK_S_REG, CLKMU_SYSCLK_S_POS, CLKMU_SYSCLK_S_BITS, POS_CLK)	///< bit SYSCLK_S set 
/**@}*/ /*** end of group clkmu_reg_mck */

/** 
 * @addtogroup clkmu_reg_tctrim reg: TCTRIM
 * @details <b>reg: TCTRIM(0x01H)</b>
 * - bit: TC_TRIM[2:0]
 * @par 示例
 * @code
 *	void test( void )
 *	{
 * 		uint8_t temp_a;
 * 		uint8_t temp_b;
 * 	
 * 		//get reg-bit value
 * 		temp_a= __TX_CLK_TRIM_GET();
 * 		temp_b= __TX_CLK_TRIM_GET_SHIFT();
 * 	
 * 		//set reg-bit value
 * 		__TX_CLK_TRIM_SET(7);
 * 		__TX_CLK_TRIM_SET_SHIFT(7<< CLKMU_TC_TRIM_POS);
 * }
 * @endcode
 * @{
 */
//TCTRIM
//TC_TRIM[2:0]
#define CLKMU_TC_TRIM_REG							TCTRIM                                                                                	///< bit TC_TRIM reg
#define CLKMU_TC_TRIM_POS							(0)                                                                                   	///< bit TC_TRIM offset
#define CLKMU_TC_TRIM_BITS							C_REG_BITS3                                                                           	///< bit TC_TRIM bits
#define CLKMU_TC_TRIM_MASK							(CLKMU_TC_TRIM_BITS<< CLKMU_TC_TRIM_POS)                                              	///< bit TC_TRIM mask
#define CLKMU_TC_TRIM_VAL							                                                                                      	///< bit TC_TRIM value
#define __TX_CLK_TRIM_GET()							M_REG_GET(CLKMU_TC_TRIM_REG, CLKMU_TC_TRIM_POS, CLKMU_TC_TRIM_BITS)                   	///< bit TC_TRIM get
#define __TX_CLK_TRIM_SET(CLK)						M_REG_SET(CLKMU_TC_TRIM_REG, CLKMU_TC_TRIM_POS, CLKMU_TC_TRIM_BITS, CLK)              	///< bit TC_TRIM set	
#define __TX_CLK_TRIM_GET_SHIFT()					M_REG_GET_SHIFT(CLKMU_TC_TRIM_REG, CLKMU_TC_TRIM_POS, CLKMU_TC_TRIM_BITS)               ///< bit TC_TRIM get
#define __TX_CLK_TRIM_SET_SHIFT(POS_CLK)			M_REG_SET_SHIFT(CLKMU_TC_TRIM_REG, CLKMU_TC_TRIM_POS, CLKMU_TC_TRIM_BITS, POS_CLK)      ///< bit TC_TRIM set    
/**@}*/ /*** end of group clkmu_reg_tctrim */

/** 
 * @addtogroup clkmu_reg_clksel0 reg: CLKSEL0
 * @details <b>reg: CLKSEL0(0x02H)</b>
 * - bit: T3CKS[7:6]
 * - bit: T2CKS[5:4]
 * - bit: T0CKS[1:0]
 * @par 示例
 * @code
 *	void test( void )
 *	{
 * 		uint8_t temp_a;
 * 		uint8_t temp_b;
 * 	
 * 		//get reg-bit value
 * 		temp_a= __T3_CLK_SOURCE_GET();
 * 		temp_b= __T3_CLK_SOURCE_GET_SHIFT();
 * 	
 * 		//set reg-bit value
 * 		__T3_CLK_SOURCE_SET(0);
 * 		__T3_CLK_SOURCE_SET(1);
 * 		__T3_CLK_SOURCE_SET(2);
 * 		__T3_CLK_SOURCE_SET(3);
 * 		__T3_CLK_SOURCE_SET_SHIFT(CLKMU_T3CKS_CPUCLK);
 * 		__T3_CLK_SOURCE_SET_SHIFT(CLKMU_T3CKS_SYSCLK);
 * 		__T3_CLK_SOURCE_SET_SHIFT(CLKMU_T3CKS_ECK);
 * 		__T3_CLK_SOURCE_SET_SHIFT(CLKMU_T3CKS_EX_EVENT);
 * }
 * @endcode
 * @{
 */
//CLKSEL0
//T3CKS[7:6]
#define CLKMU_T3CKS_REG								CLKSEL0																					///< bit T3CKS reg
#define CLKMU_T3CKS_POS								(6)                                                                                     ///< bit T3CKS offset
#define CLKMU_T3CKS_BITS							C_REG_BITS2                                                                             ///< bit T3CKS bits
#define CLKMU_T3CKS_MASK							(CLKMU_T3CKS_BITS<< CLKMU_T3CKS_POS)                                                    ///< bit T3CKS mask
#define CLKMU_T3CKS_CPUCLK							(0x00<< CLKMU_T3CKS_POS)                                                                ///< bit T3CKS enum CPUCLK	
#define CLKMU_T3CKS_SYSCLK							(0x01<< CLKMU_T3CKS_POS)                                                                ///< bit T3CKS enum SYSCLK	
#define CLKMU_T3CKS_ECK								(0x02<< CLKMU_T3CKS_POS)                                                                ///< bit T3CKS enum ECK		
#define CLKMU_T3CKS_EX_EVENT						(0x03<< CLKMU_T3CKS_POS)                                                                ///< bit T3CKS enum EX_EVENT
#define __T3_CLK_SOURCE_GET()						M_REG_GET(CLKMU_T3CKS_REG, CLKMU_T3CKS_POS, CLKMU_T3CKS_BITS)                           ///< bit T3CKS get 
#define __T3_CLK_SOURCE_SET(CLK)					M_REG_SET(CLKMU_T3CKS_REG, CLKMU_T3CKS_POS, CLKMU_T3CKS_BITS, CLK)                      ///< bit T3CKS set 
#define __T3_CLK_SOURCE_GET_SHIFT()					M_REG_GET_SHIFT(CLKMU_T3CKS_REG, CLKMU_T3CKS_POS, CLKMU_T3CKS_BITS)                     ///< bit T3CKS get
#define __T3_CLK_SOURCE_SET_SHIFT(POS_CLK)			M_REG_SET_SHIFT(CLKMU_T3CKS_REG, CLKMU_T3CKS_POS, CLKMU_T3CKS_BITS, POS_CLK)            ///< bit T3CKS set

//CLKSEL0
//T2CKS[5:4]
#define CLKMU_T2CKS_REG								CLKSEL0																					///< bit T2CKS reg
#define CLKMU_T2CKS_POS								(4)                                                                                     ///< bit T2CKS offset
#define CLKMU_T2CKS_BITS							C_REG_BITS2                                                                             ///< bit T2CKS bits
#define CLKMU_T2CKS_MASK							(CLKMU_T2CKS_BITS<< CLKMU_T2CKS_POS)                                                    ///< bit T2CKS mask
#define CLKMU_T2CKS_CPUCLK							(0x00<< CLKMU_T2CKS_POS)                                                                ///< bit T2CKS enum CPUCLK	
#define CLKMU_T2CKS_SYSCLK							(0x01<< CLKMU_T2CKS_POS)                                                                ///< bit T2CKS enum SYSCLK	
#define CLKMU_T2CKS_ECK								(0x02<< CLKMU_T2CKS_POS)                                                                ///< bit T2CKS enum ECK
#define CLKMU_T2CKS_10KHZ							(0x03<< CLKMU_T2CKS_POS)                                                                ///< bit T2CKS enum 10KHZ	
#define __T2_CLK_SOURCE_GET()						M_REG_GET(CLKMU_T2CKS_REG, CLKMU_T2CKS_POS, CLKMU_T2CKS_BITS)                           ///< bit T2CKS get 
#define __T2_CLK_SOURCE_SET(CLK)                    M_REG_SET(CLKMU_T2CKS_REG, CLKMU_T2CKS_POS, CLKMU_T2CKS_BITS, CLK)                      ///< bit T2CKS set 
#define __T2_CLK_SOURCE_GET_SHIFT()                 M_REG_GET_SHIFT(CLKMU_T2CKS_REG, CLKMU_T2CKS_POS, CLKMU_T2CKS_BITS)                     ///< bit T2CKS get
#define __T2_CLK_SOURCE_SET_SHIFT(POS_CLK)          M_REG_SET_SHIFT(CLKMU_T2CKS_REG, CLKMU_T2CKS_POS, CLKMU_T2CKS_BITS, POS_CLK)            ///< bit T2CKS set

//CLKSEL0
//T0CKS[1:0]
#define CLKMU_T0CKS_REG								CLKSEL0																					///< bit T0CKS reg
#define CLKMU_T0CKS_POS								(4)                                                                                     ///< bit T0CKS offset
#define CLKMU_T0CKS_BITS							C_REG_BITS2                                                                             ///< bit T0CKS bits
#define CLKMU_T0CKS_MASK							(CLKMU_T0CKS_BITS<< CLKMU_T0CKS_POS)                                                    ///< bit T0CKS mask
#define CLKMU_T0CKS_CPUCLK							(0x00<< CLKMU_T0CKS_POS)                                                                ///< bit T0CKS enum CPUCLK
#define CLKMU_T0CKS_SYSCLK							(0x01<< CLKMU_T0CKS_POS)                                                                ///< bit T0CKS enum SYSCLK
#define CLKMU_T0CKS_ECK								(0x02<< CLKMU_T0CKS_POS)                                                                ///< bit T0CKS enum ECK
#define CLKMU_T0CKS_10KHZ							(0x03<< CLKMU_T0CKS_POS)                                                                ///< bit T0CKS enum 10KHZ
#define __T0_CLK_SOURCE_GET()						M_REG_GET(CLKMU_T0CKS_REG, CLKMU_T0CKS_POS, CLKMU_T0CKS_BITS)                           ///< bit T0CKS get 
#define __T0_CLK_SOURCE_SET(CLK)					M_REG_SET(CLKMU_T0CKS_REG, CLKMU_T0CKS_POS, CLKMU_T0CKS_BITS, CLK)                      ///< bit T0CKS set 
#define __T0_CLK_SOURCE_GET_SHIFT()					M_REG_GET_SHIFT(CLKMU_T0CKS_REG, CLKMU_T0CKS_POS, CLKMU_T0CKS_BITS)                     ///< bit T0CKS get
#define __T0_CLK_SOURCE_SET_SHIFT(POS_CLK)			M_REG_SET_SHIFT(CLKMU_T0CKS_REG, CLKMU_T0CKS_POS, CLKMU_T0CKS_BITS, POS_CLK)		    ///< bit T0CKS set
/**@}*/ /*** end of group clkmu_reg_clksel0 */

/** 
 * @addtogroup clkmu_reg_clksel1 reg: CLKSEL1
 * @details <b>reg: CLKSEL1(0x03H)</b>
 * - bit: URTCKS[3:2]
 * @par 示例
 * @code
 *	void test( void )
 *	{
 * 		uint8_t temp_a;
 * 		uint8_t temp_b;
 * 	
 * 		//get reg-bit value
 * 		temp_a= __UART_CLK_SOURCE_GET();
 * 		temp_b= __UART_CLK_SOURCE_GET_SHIFT();
 * 	
 * 		//set reg-bit value
 * 		__UART_CLK_SOURCE_SET(0);
 * 		__UART_CLK_SOURCE_SET(1);
 * 		__UART_CLK_SOURCE_SET_SHIFT(CLKMU_URTCKS_SYSCLK);
 * 		__UART_CLK_SOURCE_SET_SHIFT(CLKMU_URTCKS_ECK);
 * }
 * @endcode
 * @{
 */
//CLKSEL1
//URTCKS[3:2]
#define CLKMU_URTCKS_REG							CLKSEL1																					///< bit URTCKS reg
#define CLKMU_URTCKS_POS							(2)                                                                                     ///< bit URTCKS offset
#define CLKMU_URTCKS_BITS							C_REG_BITS2                                                                             ///< bit URTCKS bits
#define CLKMU_URTCKS_MASK							(CLKMU_URTCKS_BITS<< CLKMU_URTCKS_POS)                                                  ///< bit URTCKS mask
#define CLKMU_URTCKS_SYSCLK							(0x00<< CLKMU_URTCKS_POS)                                                               ///< bit URTCKS enum SYSCLK	
#define CLKMU_URTCKS_ECK							(0x01<< CLKMU_URTCKS_POS)                                                               ///< bit URTCKS enum ECK	
#define __UART_CLK_SOURCE_GET()						M_REG_GET(CLKMU_URTCKS_REG, CLKMU_URTCKS_POS, CLKMU_URTCKS_BITS)                        ///< bit URTCKS get 
#define __UART_CLK_SOURCE_SET(CLK)                  M_REG_SET(CLKMU_URTCKS_REG, CLKMU_URTCKS_POS, CLKMU_URTCKS_BITS, CLK)                   ///< bit URTCKS set 
#define __UART_CLK_SOURCE_GET_SHIFT()               M_REG_GET_SHIFT(CLKMU_URTCKS_REG, CLKMU_URTCKS_POS, CLKMU_URTCKS_BITS)                  ///< bit URTCKS get
#define __UART_CLK_SOURCE_SET_SHIFT(POS_CLK)		M_REG_SET_SHIFT(CLKMU_URTCKS_REG, CLKMU_URTCKS_POS, CLKMU_URTCKS_BITS, POS_CLK)         ///< bit URTCKS set
/**@}*/ /*** end of group clkmu_reg_clksel1 */

/** 
 * @addtogroup clkmu_reg_clksel2 reg: CLKSEL2
 * @details <b>reg: CLKSEL2(0x04H)</b>
 * - bit: PDS[5:4]
 * - bit: TYPCS[3:2]
 * - bit: T4CKS[1:0]
 * @par 示例
 * @code
 *	void test( void )
 *	{
 * 		uint8_t temp_a;
 * 		uint8_t temp_b;
 * 	
 * 		//get reg-bit value
 * 		temp_a= __PD_CLK_SOURCE_GET();
 * 		temp_b= __PD_CLK_SOURCE_GET_SHIFT();
 * 	
 * 		//set reg-bit value
 * 		__PD_CLK_SOURCE_SET(0);
 * 		__PD_CLK_SOURCE_SET(1);
 * 		__PD_CLK_SOURCE_SET_SHIFT(CLKMU_PDS_CPUCLK);
 * 		__PD_CLK_SOURCE_SET_SHIFT(CLKMU_PDS_SYSCLK);
 * }
 * @endcode
 * @{
 */
//CLKSEL2
//PDS[5:4]
#define CLKMU_PDS_REG								CLKSEL2																					///< bit PDS reg
#define CLKMU_PDS_POS								(4)                                                                                     ///< bit PDS offset
#define CLKMU_PDS_BITS								C_REG_BITS2                                                                             ///< bit PDS bits
#define CLKMU_PDS_MASK								(CLKMU_PDS_BITS<< CLKMU_PDS_POS)                                                        ///< bit PDS mask
#define CLKMU_PDS_CPUCLK							(0x00<< CLKMU_PDS_POS)                                                                  ///< bit PDS enum CPUCLK
#define CLKMU_PDS_SYSCLK							(0x01<< CLKMU_PDS_POS)                                                                  ///< bit PDS enum SYSCLK
#define __PD_CLK_SOURCE_GET()						M_REG_GET(CLKMU_PDS_REG, CLKMU_PDS_POS, CLKMU_PDS_BITS)                                 ///< bit PDS get 
#define __PD_CLK_SOURCE_SET(CLK)			        M_REG_SET(CLKMU_PDS_REG, CLKMU_PDS_POS, CLKMU_PDS_BITS, CLK)                            ///< bit PDS set 
#define __PD_CLK_SOURCE_GET_SHIFT()					M_REG_GET_SHIFT(CLKMU_PDS_REG, CLKMU_PDS_POS, CLKMU_PDS_BITS)                           ///< bit PDS get
#define __PD_CLK_SOURCE_SET_SHIFT(POS_CLK)			M_REG_SET_SHIFT(CLKMU_PDS_REG, CLKMU_PDS_POS, CLKMU_PDS_BITS, POS_CLK)                  ///< bit PDS set

//CLKSEL2
//TYPCS[3:2]
#define CLKMU_TYPCS_REG								CLKSEL2																					///< bit TYPCS reg
#define CLKMU_TYPCS_POS								(2)                                                                                     ///< bit TYPCS offset
#define CLKMU_TYPCS_BITS							C_REG_BITS2                                                                             ///< bit TYPCS bits
#define CLKMU_TYPCS_MASK							(CLKMU_TYPCS_BITS<< CLKMU_TYPCS_POS)                                                    ///< bit TYPCS mask
#define CLKMU_TYPCS_LIRC							(0x00<< CLKMU_TYPCS_POS)                                                                ///< bit TYPCS enum LIRC	
#define CLKMU_TYPCS_CPUCLK							(0x01<< CLKMU_TYPCS_POS)                                                                ///< bit TYPCS enum CPUCLK	
#define CLKMU_TYPCS_SYSCLLK							(0x02<< CLKMU_TYPCS_POS)                                                                ///< bit TYPCS enum SYSCLLK
#define __TYPEC_CLOCK_SOURCE_GET()					M_REG_GET(CLKMU_TYPCS_REG, CLKMU_TYPCS_POS, CLKMU_TYPCS_BITS)                           ///< bit TYPCS get 
#define __TYPEC_CLOCK_SOURCE_SET(CLK)               M_REG_SET(CLKMU_TYPCS_REG, CLKMU_TYPCS_POS, CLKMU_TYPCS_BITS, CLK)                      ///< bit TYPCS set
#define __TYPEC_CLOCK_SOURCE_GET_SHIFT()			M_REG_GET_SHIFT(CLKMU_TYPCS_REG, CLKMU_TYPCS_POS, CLKMU_TYPCS_BITS)                     ///< bit TYPCS get
#define __TYPEC_CLOCK_SOURCE_SET_SHIFT(POS_CLK)		M_REG_SET_SHIFT(CLKMU_TYPCS_REG, CLKMU_TYPCS_POS, CLKMU_TYPCS_BITS, POS_CLK)            ///< bit TYPCS set

//CLKSEL2
//T4CKS[1:0]
#define CLKMU_T4CKS_REG								CLKSEL2																					///< bit T4CKS reg
#define CLKMU_T4CKS_POS								(4)                                                                                     ///< bit T4CKS offset
#define CLKMU_T4CKS_BITS							C_REG_BITS2                                                                             ///< bit T4CKS bits
#define CLKMU_T4CKS_MASK							(CLKMU_T4CKS_BITS<< CLKMU_T4CKS_POS)                                                    ///< bit T4CKS mask
#define CLKMU_T4CKS_CPUCLK							(0x00<< CLKMU_T4CKS_POS)                                                                ///< bit T4CKS enum CPUCLK
#define CLKMU_T4CKS_SYSCLK							(0x01<< CLKMU_T4CKS_POS)                                                                ///< bit T4CKS enum SYSCLK
#define CLKMU_T4CKS_ECK								(0x02<< CLKMU_T4CKS_POS)                                                                ///< bit T4CKS enum ECK
#define CLKMU_T4CKS_RES								(0x03<< CLKMU_T4CKS_POS																	///< bit T4CKS enum RES
#define __T4_CLK_SOURCE_GET()						M_REG_GET(CLKMU_T4CKS_REG, CLKMU_T4CKS_POS, CLKMU_T4CKS_BITS)                           ///< bit T4CKS get
#define __T4_CLK_SOURCE_SET(CLK)					M_REG_SET(CLKMU_T4CKS_REG, CLKMU_T4CKS_POS, CLKMU_T4CKS_BITS, CLK)                      ///< bit T4CKS set
#define __T4_CLK_SOURCE_GET_SHIFT()					M_REG_GET_SHIFT(CLKMU_T4CKS_REG, CLKMU_T4CKS_POS, CLKMU_T4CKS_BITS)                     ///< bit T4CKS get
#define __T4_CLK_SOURCE_SET_SHIFT(POS_CLK)			M_REG_SET_SHIFT(CLKMU_T4CKS_REG, CLKMU_T4CKS_POS, CLKMU_T4CKS_BITS, POS_CLK)	        ///< bit T4CKS set
/**@}*/ /*** end of group clkmu_reg_clksel2 */

/** 
 * @addtogroup clkmu_reg_clkdiv0 reg: CLKDIV0
 * @details <b>reg: CLKDIV0(0x05H)</b>
 * - bit: T0DIV[2:0]
 * @par 示例
 * @code
 *	void test( void )
 *	{
 * 		uint8_t temp_a;
 * 		uint8_t temp_b;
 * 	
 * 		//get reg-bit value
 * 		temp_a= __T0_CLK_DIV_GET();
 * 		temp_b= __T0_CLK_DIV_GET_SHIFT();
 * 	
 * 		//set reg-bit value
 * 		__T0_CLK_DIV_SET(0);
 * 		__T0_CLK_DIV_SET(1);
 * 		__T0_CLK_DIV_SET(2);
 * 		__T0_CLK_DIV_SET(3);
 * 		__T0_CLK_DIV_SET(4);
 * 		__T0_CLK_DIV_SET(5);
 * 		__T0_CLK_DIV_SET(6);
 * 		__T0_CLK_DIV_SET(7);
 * 		__T0_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_0);
 * 		__T0_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_2);
 * 		__T0_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_4);
 * 		__T0_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_8);
 * 		__T0_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_16);
 * 		__T0_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_32);
 * 		__T0_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_64);
 * 		__T0_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_128);
 * }
 * @endcode
 * @{
 */
//CLKDIV0
//T0DIV[2:0]
#define CLKMU_T0DIV_REG								CLKDIV0																					///< bit T0DIV reg
#define CLKMU_T0DIV_POS								(0)                                                                                     ///< bit T0DIV offset
#define CLKMU_T0DIV_BITS							C_REG_BITS3                                                                             ///< bit T0DIV bits
#define CLKMU_T0DIV_MASK							(CLKMU_T0DIV_BITS<< CLKMU_T0DIV_POS)                                                    ///< bit T0DIV mask
#define CLKMU_T0DIV_0								(0x00<< CLKMU_T0DIV_POS)                                                                ///< bit T0DIV enum 0	
#define CLKMU_T0DIV_2								(0x01<< CLKMU_T0DIV_POS)                                                                ///< bit T0DIV enum 2	
#define CLKMU_T0DIV_4								(0x02<< CLKMU_T0DIV_POS)                                                                ///< bit T0DIV enum 4	
#define CLKMU_T0DIV_8								(0x03<< CLKMU_T0DIV_POS)                                                                ///< bit T0DIV enum 8	
#define CLKMU_T0DIV_16								(0x04<< CLKMU_T0DIV_POS)                                                                ///< bit T0DIV enum 16	
#define CLKMU_T0DIV_32								(0x05<< CLKMU_T0DIV_POS)                                                                ///< bit T0DIV enum 32	
#define CLKMU_T0DIV_64								(0x06<< CLKMU_T0DIV_POS)                                                                ///< bit T0DIV enum 64	
#define CLKMU_T0DIV_128								(0x07<< CLKMU_T0DIV_POS)                                                                ///< bit T0DIV enum 128
#define __T0_CLK_DIV_GET()							M_REG_GET(CLKMU_T0DIV_REG, CLKMU_T0DIV_POS, CLKMU_T0DIV_BITS)							///< bit T0DIV get
#define __T0_CLK_DIV_SET(CLK)						M_REG_SET(CLKMU_T0DIV_REG, CLKMU_T0DIV_POS, CLKMU_T0DIV_BITS, CLK)                      ///< bit T0DIV set
#define __T0_CLK_DIV_GET_SHIFT()					M_REG_GET_SHIFT(CLKMU_T0DIV_REG, CLKMU_T0DIV_POS, CLKMU_T0DIV_BITS)                     ///< bit T0DIV get
#define __T0_CLK_DIV_SET_SHIFT(POS_CLK)				M_REG_SET_SHIFT(CLKMU_T0DIV_REG, CLKMU_T0DIV_POS, CLKMU_T0DIV_BITS, POS_CLK)            ///< bit T0DIV set
/**@}*/ /*** end of group clkmu_reg_clkdiv0 */

/** 
 * @addtogroup clkmu_reg_clkdiv1 reg: CLKDIV1
 * @details <b>reg: CLKDIV1(0x06H)</b>
 * - T3DIV[6:4]
 * - T2DIV[2:0]
 * @par 示例
 * @code
 *	void test( void )
 *	{
 * 		uint8_t temp_a;
 * 		uint8_t temp_b;
 * 	
 * 		//get reg-bit value
 * 		temp_a= __T3_CLK_DIV_GET();
 * 		temp_b= __T3_CLK_DIV_GET_SHIFT();
 * 	
 * 		//set reg-bit value
 * 		__T3_CLK_DIV_SET(0);
 * 		__T3_CLK_DIV_SET(1);
 * 		__T3_CLK_DIV_SET(2);
 * 		__T3_CLK_DIV_SET(3);
 * 		__T3_CLK_DIV_SET(4);
 * 		__T3_CLK_DIV_SET(5);
 * 		__T3_CLK_DIV_SET(6);
 * 		__T3_CLK_DIV_SET(7);
 * 		__T3_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_0);
 * 		__T3_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_2);
 * 		__T3_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_4);
 * 		__T3_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_8);
 * 		__T3_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_16);
 * 		__T3_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_32);
 * 		__T3_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_64);
 * 		__T3_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_128);
 * }
 * @endcode
 * @{
 */
//CLKDIV1
//T3DIV[6:4]
#define CLKMU_T3DIV_REG								CLKDIV1																					///< bit T3DIV reg
#define CLKMU_T3DIV_POS								(4)                                                                                     ///< bit T3DIV offset
#define CLKMU_T3DIV_BITS							C_REG_BITS3                                                                             ///< bit T3DIV bits
#define CLKMU_T3DIV_MASK							(CLKMU_T3DIV_BITS<< CLKMU_T3DIV_POS)                                                    ///< bit T3DIV mask
#define CLKMU_T3DIV_0								(0x00<< CLKMU_T3DIV_POS)                                                                ///< bit T3DIV enum 0	
#define CLKMU_T3DIV_2								(0x01<< CLKMU_T3DIV_POS)                                                                ///< bit T3DIV enum 2	
#define CLKMU_T3DIV_4								(0x02<< CLKMU_T3DIV_POS)                                                                ///< bit T3DIV enum 4	
#define CLKMU_T3DIV_8								(0x03<< CLKMU_T3DIV_POS)                                                                ///< bit T3DIV enum 8	
#define CLKMU_T3DIV_16								(0x04<< CLKMU_T3DIV_POS)                                                                ///< bit T3DIV enum 16	
#define CLKMU_T3DIV_32								(0x05<< CLKMU_T3DIV_POS)                                                                ///< bit T3DIV enum 32	
#define CLKMU_T3DIV_64								(0x06<< CLKMU_T3DIV_POS)                                                                ///< bit T3DIV enum 64	
#define CLKMU_T3DIV_128								(0x07<< CLKMU_T3DIV_POS)                                                                ///< bit T3DIV enum 128
#define __T3_CLK_DIV_GET()							M_REG_GET(CLKMU_T3DIV_REG, CLKMU_T3DIV_POS, CLKMU_T3DIV_BITS)                           ///< bit T3DIV get
#define __T3_CLK_DIV_SET(CLK)						M_REG_SET(CLKMU_T3DIV_REG, CLKMU_T3DIV_POS, CLKMU_T3DIV_BITS, CLK)                      ///< bit T3DIV set
#define __T3_CLK_DIV_GET_SHIFT()					M_REG_GET_SHIFT(CLKMU_T3DIV_REG, CLKMU_T3DIV_POS, CLKMU_T3DIV_BITS)	                    ///< bit T3DIV get
#define __T3_CLK_DIV_SET_SHIFT(POS_CLK)				M_REG_SET_SHIFT(CLKMU_T3DIV_REG, CLKMU_T3DIV_POS, CLKMU_T3DIV_BITS, POS_CLK)	        ///< bit T3DIV set

//CLKDIV1
//T2DIV[2:0]
#define CLKMU_T2DIV_REG								CLKDIV1																					///< bit T2DIV reg
#define CLKMU_T2DIV_POS								(0)                                                                                     ///< bit T2DIV offset
#define CLKMU_T2DIV_BITS							C_REG_BITS3                                                                             ///< bit T2DIV bits
#define CLKMU_T2DIV_MASK							(CLKMU_T2DIV_BITS<< CLKMU_T2DIV_POS)                                                    ///< bit T2DIV mask
#define CLKMU_T2DIV_0								(0x00<< CLKMU_T2DIV_POS)                                                                ///< bit T2DIV enum 0	
#define CLKMU_T2DIV_2								(0x01<< CLKMU_T2DIV_POS)                                                                ///< bit T2DIV enum 2	
#define CLKMU_T2DIV_4								(0x02<< CLKMU_T2DIV_POS)                                                                ///< bit T2DIV enum 4	
#define CLKMU_T2DIV_8								(0x03<< CLKMU_T2DIV_POS)                                                                ///< bit T2DIV enum 8	
#define CLKMU_T2DIV_16								(0x04<< CLKMU_T2DIV_POS)                                                                ///< bit T2DIV enum 16	
#define CLKMU_T2DIV_32								(0x05<< CLKMU_T2DIV_POS)                                                                ///< bit T2DIV enum 32	
#define CLKMU_T2DIV_64								(0x06<< CLKMU_T2DIV_POS)                                                                ///< bit T2DIV enum 64	
#define CLKMU_T2DIV_128								(0x07<< CLKMU_T2DIV_POS)                                                                ///< bit T2DIV enum 128
#define __T2_CLK_DIV_GET()							M_REG_GET(CLKMU_T2DIV_REG, CLKMU_T2DIV_POS, CLKMU_T2DIV_BITS)                           ///< bit T2DIV get
#define __T2_CLK_DIV_SET(CLK)						M_REG_SET(CLKMU_T2DIV_REG, CLKMU_T2DIV_POS, CLKMU_T2DIV_BITS, CLK)                      ///< bit T2DIV set
#define __T2_CLK_DIV_GET_SHIFT()					M_REG_GET_SHIFT(CLKMU_T2DIV_REG, CLKMU_T2DIV_POS, CLKMU_T2DIV_BITS)	                    ///< bit T2DIV get
#define __T2_CLK_DIV_SET_SHIFT(POS_CLK)				M_REG_SET_SHIFT(CLKMU_T2DIV_REG, CLKMU_T2DIV_POS, CLKMU_T2DIV_BITS, POS_CLK)	        ///< bit T2DIV set
/**@}*/ /*** end of group clkmu_reg_clkdiv1 */

/** 
 * @addtogroup clkmu_reg_clkdiv2 reg: CLKDIV2
 * @details <b>reg: CLKDIV2(0x07H)</b>
 * - URTDIV[6:4]
 * @par 示例
 * @code
 *	void test( void )
 *	{
 * 		uint8_t temp_a;
 * 		uint8_t temp_b;
 * 	
 * 		//get reg-bit value
 * 		temp_a= __UART_CLK_DIV_GET();
 * 		temp_b= __UART_CLK_DIV_GET_SHIFT();
 * 	
 * 		//set reg-bit value
 * 		__UART_CLK_SET(0);
 * 		__UART_CLK_SET(1);
 * 		__UART_CLK_SET(2);
 * 		__UART_CLK_SET(3);
 * 		__UART_CLK_SET(4);
 * 		__UART_CLK_SET(5);
 * 		__UART_CLK_SET_SHIFT(CLKMU_T0DIV_2);
 * 		__UART_CLK_SET_SHIFT(CLKMU_T0DIV_4);
 * 		__UART_CLK_SET_SHIFT(CLKMU_T0DIV_8);
 * 		__UART_CLK_SET_SHIFT(CLKMU_T0DIV_16);
 * 		__UART_CLK_SET_SHIFT(CLKMU_T0DIV_32);
 * 		__UART_CLK_SET_SHIFT(CLKMU_T0DIV_64);
 * }
 * @endcode
 * @{
 */
//CLKDIV2
//URTDIV[6:4]
#define CLKMU_URTDIV_REG							CLKDIV2																					///< bit URTDIV reg
#define CLKMU_URTDIV_POS							(4)                                                                                     ///< bit URTDIV offset
#define CLKMU_URTDIV_BITS							C_REG_BITS3                                                                             ///< bit URTDIV bits
#define CLKMU_URTDIV_MASK							(CLKMU_URTDIV_BITS<< CLKMU_URTDIV_POS)                                                  ///< bit URTDIV mask
#define CLKMU_URTDIV_2								(0x00<< CLKMU_URTDIV_POS)                                                               ///< bit URTDIV enum 2	
#define CLKMU_URTDIV_4								(0x01<< CLKMU_URTDIV_POS)                                                               ///< bit URTDIV enum 4	
#define CLKMU_URTDIV_8								(0x02<< CLKMU_URTDIV_POS)                                                               ///< bit URTDIV enum 8	
#define CLKMU_URTDIV_16								(0x03<< CLKMU_URTDIV_POS)                                                               ///< bit URTDIV enum 16
#define CLKMU_URTDIV_32								(0x04<< CLKMU_URTDIV_POS)                                                               ///< bit URTDIV enum 32	
#define CLKMU_URTDIV_64								(0x05<< CLKMU_URTDIV_POS)                                                               ///< bit URTDIV enum 64	
#define __UART_CLK_DIV_GET()						M_REG_GET(CLKMU_URTDIV_REG, CLKMU_URTDIV_POS, CLKMU_URTDIV_BITS)                        ///< bit URTDIV get
#define __UART_CLK_DIV_SET(CLK)                     M_REG_SET(CLKMU_URTDIV_REG, CLKMU_URTDIV_POS, CLKMU_URTDIV_BITS, CLK)                   ///< bit URTDIV set
#define __UART_CLK_DIV_GET_SHIFT()                  M_REG_GET_SHIFT(CLKMU_URTDIV_REG, CLKMU_URTDIV_POS, CLKMU_URTDIV_BITS)	                ///< bit URTDIV get
#define __UART_CLK_DIV_SET_SHIFT(POS_CLK)			M_REG_SET_SHIFT(CLKMU_URTDIV_REG, CLKMU_URTDIV_POS, CLKMU_URTDIV_BITS, POS_CLK)         ///< bit URTDIV set
/**@}*/ /*** end of group clkmu_reg_clkdiv2 */

/** 
 * @addtogroup clkmu_reg_clkdiv3 reg: CLKDIV3
 * @details <b>reg: CLKDIV3(0x08H)</b>
 * - T4DIV[6:4]
 * - SRADCKS[1:0]
 * @par 示例
 * @code
 *	void test( void )
 *	{
 * 		uint8_t temp_a;
 * 		uint8_t temp_b;
 * 	
 * 		//get reg-bit value
 * 		temp_a= __T4_CLK_DIV_GET();
 * 		temp_b= __T4_CLK_DIV_GET_SHIFT();
 * 	
 * 		//set reg-bit value
 * 		__T4_CLK_DIV_SET(0);
 * 		__T4_CLK_DIV_SET(1);
 * 		__T4_CLK_DIV_SET(2);
 * 		__T4_CLK_DIV_SET(3);
 * 		__T4_CLK_DIV_SET(4);
 * 		__T4_CLK_DIV_SET(5);
 * 		__T4_CLK_DIV_SET(6);
 * 		__T4_CLK_DIV_SET(7);
 * 		__T4_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_0);
 * 		__T4_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_2);
 * 		__T4_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_4);
 * 		__T4_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_8);
 * 		__T4_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_16);
 * 		__T4_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_32);
 * 		__T4_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_64);
 * 		__T4_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_128);
 * }
 * @endcode
 * @{
 */
//CLKDIV3
//T4DIV[6:4]
#define CLKMU_T4DIV_REG								CLKDIV3																					///< bit T4DIV reg
#define CLKMU_T4DIV_POS								(4)                                                                                     ///< bit T4DIV offset
#define CLKMU_T4DIV_BITS							C_REG_BITS3                                                                             ///< bit T4DIV bits
#define CLKMU_T4DIV_MASK							(CLKMU_T4DIV_BITS<< CLKMU_T4DIV_POS)                                                    ///< bit T4DIV mask
#define CLKMU_T4DIV_0								(0x00<< CLKMU_T4DIV_POS)                                                                ///< bit T4DIV enum 0	
#define CLKMU_T4DIV_2								(0x01<< CLKMU_T4DIV_POS)                                                                ///< bit T4DIV enum 2	
#define CLKMU_T4DIV_4								(0x02<< CLKMU_T4DIV_POS)                                                                ///< bit T4DIV enum 4	
#define CLKMU_T4DIV_8								(0x03<< CLKMU_T4DIV_POS)                                                                ///< bit T4DIV enum 8	
#define CLKMU_T4DIV_16								(0x04<< CLKMU_T4DIV_POS)                                                                ///< bit T4DIV enum 16	
#define CLKMU_T4DIV_32								(0x05<< CLKMU_T4DIV_POS)                                                                ///< bit T4DIV enum 32	
#define CLKMU_T4DIV_64								(0x06<< CLKMU_T4DIV_POS)                                                                ///< bit T4DIV enum 64	
#define CLKMU_T4DIV_128								(0x07<< CLKMU_T4DIV_POS)                                                                ///< bit T4DIV enum 128
#define __T4_CLK_DIV_GET()							M_REG_GET(CLKMU_T4DIV_REG, CLKMU_T4DIV_POS, CLKMU_T4DIV_BITS)                           ///< bit T4DIV get
#define __T4_CLK_DIV_SET(CLK)               		M_REG_SET(CLKMU_T4DIV_REG, CLKMU_T4DIV_POS, CLKMU_T4DIV_BITS, CLK)                      ///< bit T4DIV set
#define __T4_CLK_DIV_GET_SHIFT()					M_REG_GET_SHIFT(CLKMU_T4DIV_REG, CLKMU_T4DIV_POS, CLKMU_T4DIV_BITS)		                ///< bit T4DIV get
#define __T4_CLK_DIV_SET_SHIFT(POS_CLK)				M_REG_SET_SHIFT(CLKMU_T4DIV_REG, CLKMU_T4DIV_POS, CLKMU_T4DIV_BITS, POS_CLK)            ///< bit T4DIV set

//CLKDIV3
//SRADCKS[1:0]
#define CLKMU_SRADCKS_REG							CLKDIV3																					///< bit SRADCKS reg
#define CLKMU_SRADCKS_POS							(0)                                                                                     ///< bit SRADCKS offset
#define CLKMU_SRADCKS_BITS							C_REG_BITS2                                                                             ///< bit SRADCKS bits
#define CLKMU_SRADCKS_MASK							(CLKMU_SRADCKS_BITS<< CLKMU_SRADCKS_POS)                                                ///< bit SRADCKS mask
#define CLKMU_SRADCKS_2								(0x00<< CLKMU_SRADCKS_POS)                                                              ///< bit SRADCKS enum 2		
#define CLKMU_SRADCKS_4								(0x01<< CLKMU_SRADCKS_POS)                                                              ///< bit SRADCKS enum 4		
#define CLKMU_SRADCKS_8								(0x02<< CLKMU_SRADCKS_POS)                                                              ///< bit SRADCKS enum 8		
#define CLKMU_SRADCKS_16							(0x03<< CLKMU_SRADCKS_POS)                                                              ///< bit SRADCKS enum 16	
#define __SRAD_CLK_DIV_GET()						M_REG_GET(CLKMU_SRADCKS_REG, CLKMU_SRADCKS_POS, CLKMU_SRADCKS_BITS)                     ///< bit SRADCKS get
#define __SRAD_CLK_DIV_SET(CLK)						M_REG_SET(CLKMU_SRADCKS_REG, CLKMU_SRADCKS_POS, CLKMU_SRADCKS_BITS, CLK)                ///< bit SRADCKS set
#define __SRAD_CLK_DIV_GET_SHIFT()					M_REG_GET_SHIFT(CLKMU_SRADCKS_REG, CLKMU_SRADCKS_POS, CLKMU_SRADCKS_BITS)			    ///< bit SRADCKS get
#define __SRAD_CLK_DIV_SET_SHIFT(POS_CLK)			M_REG_SET_SHIFT(CLKMU_SRADCKS_REG, CLKMU_SRADCKS_POS, CLKMU_SRADCKS_BITS, POS_CLK)		///< bit SRADCKS set
/**@}*/ /*** end of group clkmu_reg_clkdiv3 */

/** 
 * @addtogroup clkmu_reg_clkdiv4 reg: CLKDIV4
 * @details <b>reg: CLKDIV4(0x09H)</b>
 * - SCPDIV[1:0]
 * @par 示例
 * @code
 *	void test( void )
 *	{
 * 		uint8_t temp_a;
 * 		uint8_t temp_b;
 * 	
 * 		//get reg-bit value
 * 		temp_a= __SCP_CLK_DIV_GET();
 * 		temp_b= __SCP_CLK_DIV_GET_SHIFT();
 * 	
 * 		//set reg-bit value
 * 		__SCP_CLK_DIV_SET(0);
 * 		__SCP_CLK_DIV_SET(1);
 * 		__SCP_CLK_DIV_SET(2);
 * 		__SCP_CLK_DIV_SET(3);
 * 		__SCP_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_8);
 * 		__SCP_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_16);
 * 		__SCP_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_24);
 * 		__SCP_CLK_DIV_SET_SHIFT(CLKMU_T0DIV_32);
 * }
 * @endcode
 * @{
 */
//CLKDIV4                                                                                                                                   
//SCPDIV[1:0]
#define CLKMU_SCPDIV_REG							CLKDIV4																					///< bit SCPDIV reg
#define CLKMU_SCPDIV_POS							(0)                                                                                     ///< bit SCPDIV offset
#define CLKMU_SCPDIV_BITS							C_REG_BITS2                                                                             ///< bit SCPDIV bits
#define CLKMU_SCPDIV_MASK							(CLKMU_SCPDIV_BITS<< CLKMU_SCPDIV_POS)                                                  ///< bit SCPDIV mask
#define CLKMU_SCPDIV_8								(0x00<< CLKMU_SCPDIV_POS)                                                               ///< bit SCPDIV enum 8	
#define CLKMU_SCPDIV_16								(0x01<< CLKMU_SCPDIV_POS)                                                               ///< bit SCPDIV enum 16
#define CLKMU_SCPDIV_24								(0x02<< CLKMU_SCPDIV_POS)                                                               ///< bit SCPDIV enum 24
#define CLKMU_SCPDIV_32								(0x03<< CLKMU_SCPDIV_POS)                                                               ///< bit SCPDIV enum 32
#define __SCP_CLK_DIV_GET()							M_REG_GET(CLKMU_SCPDIV_REG, CLKMU_SCPDIV_POS, CLKMU_SCPDIV_BITS)                        ///< bit SCPDIV get
#define __SCP_CLK_DIV_SET(CLK)                      M_REG_SET(CLKMU_SCPDIV_REG, CLKMU_SCPDIV_POS, CLKMU_SCPDIV_BITS, CLK)                   ///< bit SCPDIV set
#define __SCP_CLK_DIV_GET_SHIFT()                   M_REG_GET_SHIFT(CLKMU_SCPDIV_REG, CLKMU_SCPDIV_POS, CLKMU_SCPDIV_BITS)			        ///< bit SCPDIV get
#define __SCP_CLK_DIV_SET_SHIFT(POS_CLK)            M_REG_SET_SHIFT(CLKMU_SCPDIV_REG, CLKMU_SCPDIV_POS, CLKMU_SCPDIV_BITS, POS_CLK)         ///< bit SCPDIV set
/**@}*/ /*** end of group clkmu_reg_clkdiv4 */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup clkmu_compile	attention: users do not need to care
 * @attention	users do not need to care
 * @{
 */
#ifndef PRE_MCK_CST_XT
	#define PRE_MCK_CST_XT			0			///< Register bit definition to prevent compilation errors
#endif
#ifndef PRE_MCK_CST_IN
	#define PRE_MCK_CST_IN			1			///< Register bit definition to prevent compilation errors
#endif	
#ifndef PRE_MCK_CST_WDT
	#define PRE_MCK_CST_WDT			1			///< Register bit definition to prevent compilation errors
#endif
#ifndef PRE_MCK_XT_GM
	#define PRE_MCK_XT_GM			0			///< Register bit definition to prevent compilation errors
#endif
#ifndef PRE_MCK_SYSCLK_S
	#define PRE_MCK_SYSCLK_S		0			///< Register bit definition to prevent compilation errors
#endif
#ifndef PRE_TCTRIM_TC_TRIM
	#define	PRE_TCTRIM_TC_TRIM		4			///< Register bit definition to prevent compilation errors
#endif
#ifndef	PRE_CLKSEL0_T3CKS
	#define PRE_CLKSEL0_T3CKS		0			///< Register bit definition to prevent compilation errors
#endif
#ifndef	PRE_CLKSEL0_T2CKS
	#define PRE_CLKSEL0_T2CKS		0			///< Register bit definition to prevent compilation errors
#endif
#ifndef	PRE_CLKSEL0_T0CKS
	#define PRE_CLKSEL0_T0CKS		0			///< Register bit definition to prevent compilation errors
#endif
#ifndef	PRE_CLKSEL1_URTCKS
	#define PRE_CLKSEL1_URTCKS		0			///< Register bit definition to prevent compilation errors
#endif
#ifndef	PRE_CLKSEL2_PDS
	#define PRE_CLKSEL2_PDS			0			///< Register bit definition to prevent compilation errors
#endif
#ifndef	PRE_CLKSEL2_TYPCS
	#define PRE_CLKSEL2_TYPCS		0			///< Register bit definition to prevent compilation errors
#endif
#ifndef	PRE_CLKSEL2_T4CKS
	#define PRE_CLKSEL2_T4CKS		0			///< Register bit definition to prevent compilation errors
#endif
#ifndef	PRE_CLKDIV0_T0DIV
	#define PRE_CLKDIV0_T0DIV		0			///< Register bit definition to prevent compilation errors
#endif
#ifndef	PRE_CLKDIV1_T3DIV
	#define PRE_CLKDIV1_T3DIV		0			///< Register bit definition to prevent compilation errors
#endif
#ifndef	PRE_CLKDIV1_T2DIV
	#define PRE_CLKDIV1_T3DIV		0			///< Register bit definition to prevent compilation errors
#endif
#ifndef	PRE_CLKDIV2_URTDIV
	#define PRE_CLKDIV2_URTDIV		0			///< Register bit definition to prevent compilation errors
#endif
#ifndef	PRE_CLKDIV3_T4DIV
	#define PRE_CLKDIV3_T4DIV		0			///< Register bit definition to prevent compilation errors
#endif
#ifndef	PRE_CLKDIV3_SRADCKS
	#define PRE_CLKDIV3_SRADCKS		0			///< Register bit definition to prevent compilation errors
#endif
#ifndef	PRE_CLKDIV4_SCPDIV
	#define PRE_CLKDIV4_SCPDIV		0			///< Register bit definition to prevent compilation errors
#endif
/**@}*/ /*** end of group clkmu_compile */


/**
 * @addtogroup clkmu_reg_default	reg_default_value
 * @{
 */
/** 
 * @name clkmu_reg_default
 * @par 示例
 * @code
 *		void test( void )
 *		{
 *			//Initialization register(According to the macro definition CFG_XX_XX)
 *			MCK= PRE_MCK_DEFAULT;
 *			TCTRIM= PRE_TCTRIM_DEFAULT;
 * 			CLKSEL0= PRE_CLKSEL0_DEFAULT;
 * 			CLKSEL1= PRE_CLKSEL1_DEFAULT;
 * 			CLKSEL2= PRE_CLKSEL2_DEFAULT;
 * 			CLKDIV0= PRE_CLKDIV0_DEFAULT;
 * 			CLKDIV1= PRE_CLKDIV1_DEFAULT;
 * 			CLKDIV2= PRE_CLKDIV2_DEFAULT;
 * 			CLKDIV3= PRE_CLKSEL3_DEFAULT;
 * 			CLKDIV4= PRE_CLKDIV4_DEFAULT;
 *		}
 * @endcode
 * @{
 */
#define PRE_MCK_DEFAULT				(((PRE_MCK_CST_XT<< CLKMU_CST_XT_POS)& CLKMU_CST_XT_MASK)|			\
										((PRE_MCK_CST_IN<< CLKMU_CST_IN_POS)& CLKMU_CST_IN_MASK)|		\
										((PRE_MCK_CST_WDT<< CLKMU_CST_WDT_POS)& CLKMU_CST_WDT_MASK)|	\
										((PRE_MCK_XT_GM<< CLKMU_XT_GM_POS)& CLKMU_XT_GM_MASK)|			\
										((PRE_MCK_SYSCLK_S<< CLKMU_SYSCLK_S_POS)& CLKMU_SYSCLK_S_MASK))
#define PRE_TCTRIM_DEFAULT			((PRE_TCTRIM_TC_TRIM<< CLKMU_TC_TRIM_POS)& CLKMU_TC_TRIM_MASK)
#define PRE_CLKSEL0_DEFAULT			(((PRE_CLKSEL0_T3CKS<< CLKMU_T3CKS_POS)& CLKMU_T3CKS_MASK)|			\
										((PRE_CLKSEL0_T2CKS<< CLKMU_T2CKS_POS)& CLKMU_T2CKS_MASK)|		\
										((PRE_CLKSEL0_T0CKS<< CLKMU_T2CKS_POS)& CLKMU_T0CKS_MASK))
#define PRE_CLKSEL1_DEFAULT			((PRE_CLKSEL1_URTCKS<< CLKMU_URTCKS_POS)& CLKMU_URTCKS_MASK)
#define PRE_CLKSEL2_DEFAULT			(((PRE_CLKSEL2_PDS<< CLKMU_PDS_POS)& CLKMU_PDS_MASK)|				\
										((PRE_CLKSEL2_TYPCS<< CLKMU_TYPCS_POS)& CLKMU_TYPCS_MASK)|		\
										((PRE_CLKSEL2_T4CKS<< CLKMU_T4CKS_POS)& CLKMU_T4CKS_MASK))
#define PRE_CLKDIV0_DEFAULT			((PRE_CLKDIV0_T0DIV<< CLKMU_T0DIV_POS)& CLKMU_T0DIV_MASK)
#define PRE_CLKDIV1_DEFAULT			(((PRE_CLKDIV1_T3DIV<< CLKMU_T3DIV_POS)& CLKMU_T3DIV_MASK)|			\
										((PRE_CLKDIV1_T2DIV<< CLKMU_T2DIV_POS)& CLKMU_T2DIV_MASK))
#define PRE_CLKDIV2_DEFAULT			((PRE_CLKDIV2_URTDIV<< CLKMU_URTDIV_POS)& CLKMU_URTDIV_MASK)
//#define PRE_CLKSEL3_DEFAULT			(((PRE_CLKDIV3_T4DIV<< CLKMU_T4DIV_POS)& CLKMU_T4DIV_MASK)|			\
//										((CLKMU_SRADCKS_POS<< CLKMU_T2CKS_POS)& CLKMU_SRADCKS_MASK))
#define PRE_CLKSEL3_DEFAULT			(((CLKMU_T4DIV_128<< CLKMU_T4DIV_POS)& CLKMU_T4DIV_MASK)|			\
										((CLKMU_SRADCKS_POS<< CLKMU_T2CKS_POS)& CLKMU_SRADCKS_MASK))
#define PRE_CLKDIV4_DEFAULT			((PRE_CLKDIV4_SCPDIV<< CLKMU_SCPDIV_POS)& CLKMU_SCPDIV_MASK)
/**@}*/ /*** end of name clkmu_reg_default */
/**@}*/ /*** end of group clkmu_reg_default */

/** 
 * @addtogroup clkmu_api	api
 * @{
 */
/** 
 * @name clkmu_api
 * @{
 */
/**
 * @brief system clock initialization.
 * 
 * @return  null.
 * @par 示例
 * @code
 * 		void SystemInit(void)
 * 		{
 *			//system clock init
 *			SetSysClock();
 * 		}
 * @endcode
 */
void SetSysClock(void);

/**@}*/ /*** end of name clkmu_api */
/**@}*/ /*** end of group clkmu_api */
/**@}*/ /*** end of group csu39fx10_sdk_chip_fwlib_clkmu */
/**@}*/ /*** end of group csu39fx10_sdk_chip_fwlib */
/**@}*/ /*** end of group csu39fx10_sdk_chip */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** Register description**/
/**
 * @details <b>reg: MCK(address: 0x00H, default value: 0b01111100)</b>
 * @note <b>Register description</b>
 * -  Bit7 CST_XT: External high-speed crystal enable
 * -	0= disable*
 * -	1= enable
 * - 
 * -  Bit6 CST_IN: Internal high-speed RC oscillator enable
 * - 	0= disable
 * - 	1= enable*
 * - 
 * -  Bit5 CST_WDT: WDT oscillator start switch
 * - 	0= disable(if WDT_CFG is not configured)
 * - 	1= enable(if WDT_CFG is not configured)*
 * - 
 * -  Bit4~ 2 XT_GM[2:0]: Crystal oscillator circuit bias current (control transconductance) selection
 * - 	000= 64uA
 * - 	001= 128uA
 * - 	010= 256uA
 * - 	011= 512uA        ???*
 * - 	1xx= Reserved
 * - 
 * -  Bit1~ 0 SYSCLK_S[1:0]: System clock selection
 * - 	00= ICK*
 * - 	01= ECK
 * - 	1x= Reserved
 */


/**
 * @details <b>reg: TCTRIM(address: 0x01H, default value: 0buuuuu100)</b>
 * @note <b>Register description</b>
 * -  Bit7~ 3: 
 * -  
 * -  Bit2~ 0 TC_TRIM[2:0]: Internal high-speed clock temperature TRIM value
 * -	0~ 7
 */


/**
 * @details <b>reg: CLKSEL0(address: 0x02H, default value: 0b0000uu00)</b>
 * @note <b>Register description</b>
 * -  Bit7~ 6 T3CKS[1:0]: Timer 3 clock source selection
 * -	00= CPUCLK*
 * -	01= SYSCLK
 * -	10= ECK
 * -	11= PT1.2 external event input
 * -  
 * -  Bit5~ 4 T2CKS[1:0]: Timer 2 clock source selection
 * -	00= CPUCLK*
 * -	01= SYSCLK
 * -	10= ECK
 * -	11= WDT_CLK
 * -  
 * -  Bit3~ 2: Reserved
 * -  
 * -  Bit1~ 0 T0CKS[1:0]: Timer 0 clock source selection
 * -	00= CPUCLK*
 * -	01= SYSCLK
 * -	10= ECK
 * -	11= WDT_CLK
 */


/**
 * @details <b>reg: CLKSEL1(address: 0x03H, default value: 0buuuu00uu)</b>
 * @note <b>Register description</b>
 * -  Bit7~ 4: Reserved
 * -  
 * -  Bit3~ 2 URTCKS[1:0]: Serial clock source selection
 * -	00= SYSCLK*
 * -	01= ECK
 * -	1x= Reserved
 * -  
 * -  Bit1~ 0: Reserved
**/


/**
 * @details <b>reg: CLKSEL2(address: 0x04H, default value: 0buu000000)</b>
 * @note <b>Register description</b>
 * -  Bit7~ 6: Reserved
 * -  
 * -  Bit5~ 4 PDS[1:0]: USB PD module clock source selection
 * -	00= CPUCLK*
 * -	01= SYSCLK
 * -	1x= Reserved
 * -  
 * -  Bit3~ 2 TYPCS[1:0]: USB Type-C module clock source selection
 * -	0x= WDT_CLK*
 * -	10= SYSCLK/ 2048
 * -	11= Reserved
 * -  
 * -  Bit1~ 0 T4CKS[1:0]: Timer 4 clock source selection
 * -	00= CPUCLK*
 * -	01= SYSCLK
 * -	10= ECK
 * -	11= Reserved
**/


/**
 * @details <b>reg: CLKDIV0(address: 0x05H, default value: 0buuuuu000)</b>
 * @note <b>Register description</b>
 * -  Bit7~ 3: Reserved
 * -  
 * -  Bit2~ 0 T0DIV[2:0]: Timer 0 clock division selection
 * -	000= CKT0*
 * -	001= CKT0/ 2
 * -	010= CKT0/ 4
 * -	011= CKT0/ 8
 * -	100= CKT0/ 16
 * -	101= CKT0/ 32
 * -	110= CKT0/ 64
 * -	111= CKT0/ 128
**/


/**
 * @details <b>reg: CLKDIV1(address: 0x06H, default value: 0bu000u000)</b>
 * @note <b>Register description</b>
 * -  Bit7: Reserved
 * -  
 * -  Bit6~ 4 T3DIV[2:0]: Timer 3 clock division selection
 * -	000= CKT3*
 * -	001= CKT3/ 2
 * -	010= CKT3/ 4
 * -	011= CKT3/ 8
 * -	100= CKT3/ 16
 * -	101= CKT3/ 32
 * -	110= CKT3/ 64
 * -	111= CKT3/ 128
 * -  
 * -  Bit3: Reserved
 * -  
 * -  Bit2~ 0 T2DIV[2:0]: Timer 2 clock division selection
 * -	000= CKT2*
 * -	001= CKT2/ 2
 * -	010= CKT2/ 4
 * -	011= CKT2/ 8
 * -	100= CKT2/ 16
 * -	101= CKT2/ 32
 * -	110= CKT2/ 64
 * -	111= CKT2/ 128
**/


/**
 * @details <b>reg: CLKDIV2(address: 0x07H, default value: 0bu0000000)</b>
 * @note <b>Register description</b>
 * -  Bit7: Reserved
 * -  
 * -  Bit6~ 4 URTDIV[2:0]: Uart clock division selection
 * -	000= CKUART/ 2*
 * -	001= CKUART/ 4
 * -	010= CKUART/ 8
 * -	011= CKUART/ 16
 * -	100= CKUART/ 32
 * -	1xx= CKUART/ 64
 * -  
 * -  Bit3~ 0: Reserved
**/


/**
 * @details <b>reg: CLKDIV3(address: 0x08H, default value: 0bu000uu00)</b>
 * @note <b>Register description</b>
 * -  Bit7: Reserved
 * -  
 * -  Bit6~ 4 T4DIV[2:0]: Timer 4 clock division selection
 * -	000= CKT4*
 * -	001= CKT4/ 2
 * -	010= CKT4/ 4
 * -	011= CKT4/ 8
 * -	100= CKT4/ 16
 * -	101= CKT4/ 32
 * -	110= CKT4/ 64
 * -	111= CKT4/ 128
 * -  
 * -  Bit3~ 2: Reserved
 * -  
 * -  Bit1~ 0 SRADCKS[1:0]: ADC clock frequency selection signal
 * -	00= CPUCLK/ 4*
 * -	01= CPUCLK/ 4
 * -	10= CPUCLK/ 8
 * -	11= CPUCLK/ 16
**/


/**
 * @details <b>reg: CLKDIV4(address: 0x09H, default value: 0buuuuuu00)</b>
 * @note <b>Register description</b>
 * -  Bit7~ 2: Reserved
 * -  
 * -  Bit1~ 0 SCPDIV[1:0]: SCP and VOOC module clock frequency division to generate 1MHz module working clock
 * -	00= SYSCLK/ 8*
 * -	01= SYSCLK/ 16
 * -	10= SYSCLK/ 24
 * -	11= SYSCLK/ 32
**/
/*******************************************************************************/




#ifdef __cplusplus
}
#endif

#endif  //__CSU39FX10_CLKMU_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/
