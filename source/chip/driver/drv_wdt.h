/***************************************************************************
 * @file     drv_wdt.h
 * @version  V1.0.0
 * @author   0531
 * @date     2020-09-23 PM
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
 *  SDK版本		.0.0
 * 
 * @par 修改日志:
 * <table>
 * <tr><th>Date        <th>Version  <th>Author    <th>Description
 * <tr><td>2018/08/17  <td>1.0      <td>0531	  <td>创建初始版本
 * </table>
 *
 *****************************************************************************/

#ifndef __DRV_WDT_H__
#define __DRV_WDT_H__

// Include external header file.
#include "csu39fx10.h"
#include "cs_common.h"
#include "system_csu39fx10.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * @addtogroup csu39fx10_sdk_chip	csu39fx10_sdk_chip
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_driver	driver 
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_driver_wdt	wdt_wwdt 
 * @{
 */

/** 
 * @addtogroup	wdt_reg_wdtcon	reg: WDTCON 
 * @{
 */
//WDTCON
//WDTEN
#define WDT_WDTEN_REG							WDTCON
#define WDT_WDTEN_POS							(7)
#define WDT_WDTEN_BITS							C_REG_BITS1
#define WDT_WDTEN_DIS							(0x00<< WDT_WDTEN_POS)
#define WDT_WDTEN_EN							(0x01<< WDT_WDTEN_POS)
#define WDT_WDTEN_MASK							(WDT_WDTEN_BITS<< WDT_WDTEN_POS)
#define __WDT_WDTEN_GET()						M_REG_GET(WDT_WDTEN_REG, WDT_WDTEN_POS, WDT_WDTEN_BITS)
#define __WDT_WDTEN_SET(EN)						M_REG_SET(WDT_WDTEN_REG, WDT_WDTEN_POS, WDT_WDTEN_BITS, EN)
#define __WDT_WDTEN_GET_SHIFT()					M_REG_GET_SHIFT(WDT_WDTEN_REG, WDT_WDTEN_POS, WDT_WDTEN_BITS)
#define __WDT_WDTEN_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(WDT_WDTEN_REG, WDT_WDTEN_POS, WDT_WDTEN_BITS, POS_EN)

//WDTCON
//WDTS[2:0]
#define WDT_WDTS_REG							WDTCON
#define WDT_WDTS_POS							(0)
#define WDT_WDTS_BITS							C_REG_BITS3
#define WDT_WDTS_DIV256							(0x00<< WDT_WDTS_POS)
#define WDT_WDTS_DIV128							(0x01<< WDT_WDTS_POS)
#define WDT_WDTS_DIV64							(0x02<< WDT_WDTS_POS)
#define WDT_WDTS_DIV32							(0x03<< WDT_WDTS_POS)
#define WDT_WDTS_DIV16							(0x04<< WDT_WDTS_POS)
#define WDT_WDTS_DIV8							(0x05<< WDT_WDTS_POS)
#define WDT_WDTS_DIV4							(0x06<< WDT_WDTS_POS)
#define WDT_WDTS_DIV2							(0x07<< WDT_WDTS_POS)
#define WDT_WDTS_MASK							(WDT_WDTS_BITS<< WDT_WDTS_POS)
#define __WDT_WDTS_GET()						M_REG_GET(WDT_WDTS_REG, WDT_WDTS_POS, WDT_WDTS_BITS)
#define __WDT_WDTS_SET(SET)						M_REG_SET(WDT_WDTS_REG, WDT_WDTS_POS, WDT_WDTS_BITS, SET)
#define __WDT_WDTS_GET_SHIFT()					M_REG_GET_SHIFT(WDT_WDTS_REG, WDT_WDTS_POS, WDT_WDTS_BITS)
#define __WDT_WDTS_SET_SHIFT(POS_SET)			M_REG_SET_SHIFT(WDT_WDTS_REG, WDT_WDTS_POS, WDT_WDTS_BITS, POS_SET)
/**@}*/ /*** end of group wdt_reg_wdtcon */

/** 
 * @addtogroup	wdt_reg_wdtin	reg: WDTIN 
 * @{
 */
//WDTIN
//WDTIN[7:0]
#define WDT_WDTIN_REG							WDTIN
#define WDT_WDTIN_POS							(0)
#define WDT_WDTIN_VAL
#define WDT_WDTIN_MASK							(0xFF<< WDT_WDTIN_POS)
#define __WDT_WDTIN_GET()						M_REG_GETBYTE(WDT_WDTIN_REG, WDT_WDTIN_POS)
#define __WDT_WDTIN_SET(SET)					M_REG_SETBYTE(WDT_WDTIN_REG, WDT_WDTIN_POS, SET)
#define __WDT_WDTIN_GET_SHIFT()					M_REG_GETBYTE_SHIFT(WDT_WDTIN_REG, WDT_WDTIN_POS)
#define __WDT_WDTIN_SET_SHIFT(POS_SET)			M_REG_SETBYTE_SHIFT(WDT_WDTIN_REG, WDT_WDTIN_POS, POS_SET)
/**@}*/ /*** end of group wdt_reg_wdtin */

/** 
 * @addtogroup	wdt_reg_wwdtcr	reg: WWDTCR 
 * @{
 */
//WWDTCR
//WWDTEN
#define WWT_WWDTEN_REG							WWDTCR
#define WWT_WWDTEN_POS							(7)
#define WWT_WWDTEN_BITS							C_REG_BITS1
#define WWT_WWDTEN_DIS							(0x00<< WWT_WWDTEN_POS)
#define WWT_WWDTEN_EN							(0x01<< WWT_WWDTEN_POS)
#define WWT_WWDTEN_MASK							(WWT_WWDTEN_BITS<< WWT_WWDTEN_POS)
#define __WWDT_WWDTEN_GET()						M_REG_GET(WWT_WWDTEN_REG, WWT_WWDTEN_POS, WWT_WWDTEN_BITS)
#define __WWDT_WWDTEN_SET(EN)					M_REG_SET(WWT_WWDTEN_REG, WWT_WWDTEN_POS, WWT_WWDTEN_BITS, EN)
#define __WWDT_WWDTEN_GET_SHIFT()				M_REG_GET_SHIFT(WWT_WWDTEN_REG, WWT_WWDTEN_POS, WWT_WWDTEN_BITS)
#define __WWDT_WWDTEN_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(WWT_WWDTEN_REG, WWT_WWDTEN_POS, WWT_WWDTEN_BITS, POS_EN)

//WWDTCR
//TR[6:0]
#define WWDT_TR_REG								WWDTCR
#define WWDT_TR_POS								(0)
#define WWDT_TR_BITS							C_REG_BITS7
#define WWDT_TR_VAL
#define WWDT_TR_MASK							(WWDT_TR_BITS<< WWDT_TR_POS)
#define __WWDT_TR_GET()							M_REG_GET(WWDT_TR_REG, WWDT_TR_POS, WWDT_TR_BITS)
#define __WWDT_TR_SET(SET)						M_REG_SET(WWDT_TR_REG, WWDT_TR_POS, WWDT_TR_BITS, SET)
#define __WWDT_TR_GET_SHIFT()					M_REG_GET_SHIFT(WWDT_TR_REG, WWDT_TR_POS, WWDT_TR_BITS)
#define __WWDT_TR_SET_SHIFT(POS_SET)			M_REG_SET_SHIFT(WWDT_TR_REG, WWDT_TR_POS, WWDT_TR_BITS, POS_SET)
/**@}*/ /*** end of group wdt_reg_wwdtcr */

/** 
 * @addtogroup	wdt_reg_wwdtwr	reg: WWDTWR 
 * @{
 */
//WWDTWR
//WD[6:0]
#define WWDT_WD_REG								WWDTWR
#define WWDT_WD_POS								(0)
#define WWDT_WD_BITS							C_REG_BITS7
#define WWDT_WD_VAL
#define WWDT_WD_MASK							(WWDT_WD_BITS<< WWDT_WD_POS)
#define __WWDT_WD_GET()							M_REG_GET(WWDT_WD_REG, WWDT_WD_POS, WWDT_WD_BITS)
#define __WWDT_WD_SET(SET)						M_REG_SET(WWDT_WD_REG, WWDT_WD_POS, WWDT_WD_BITS, SET)
#define __WWDT_WD_GET_SHIFT()					M_REG_GET_SHIFT(WWDT_WD_REG, WWDT_WD_POS, WWDT_WD_BITS)
#define __WWDT_WD_SET_SHIFT(POS_SET)			M_REG_SET_SHIFT(WWDT_WD_REG, WWDT_WD_POS, WWDT_WD_BITS, POS_SET)
/**@}*/ /*** end of group wdt_reg_wwdtwr */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup csu39fx10_sdk_chip_driver_wdt_cfg	wdt_config
 * @{
 */
/** 
 * @name wdt config
 * @{
 */
/**
 * @details <b>CFG_WDT_WDTEN</b>
 * - <b>Features: </b> watchdog enable configuration
 * - <b>Param: </b>
 * | config	| Descriptions		|
 * | :----:	| :----:			|
 * | 0*		| enable watchdog	|
 * | 1		| disable watchdog	|
 */
//#define	CFG_WDT_WDTEN				(0)			///< 0-> disable, 1-> enable
#define	CFG_WDT_WDTEN				(1)			///< 0-> disable, 1-> enable
/**
 * @details <b>CFG_WDT_WDTCLK_DIV</b>
 * - <b>Features: </b> watchdog clock division configuration
 * - <b>Param: </b>
 * | config	| Descriptions							|
 * | :----:	| :----:								|
 * | 0*		| WDTCLK/ 256	, max_time-> 6553.6ms	|
 * | 1		| WDTCLK/ 128 , max_time-> 3276.8ms		|
 * | 2		| WDTCLK/ 64  , max_time-> 1638.4ms		|
 * | 3		| WDTCLK/ 32  , max_time-> 819.2ms		|
 * | 4		| WDTCLK/ 16  , max_time-> 409.6ms		|
 * | 5		| WDTCLK/ 8   , max_time-> 204.8ms		|
 * | 6		| WDTCLK/ 4   , max_time-> 102.4ms		|
 * | 7		| WDTCLK/ 2   , max_time-> 51.2ms		|
 */
#define	CFG_WDT_WDTCLK_DIV			(0)			///< {0~ 7}

/**
 * @details <b>CFG_WDT_TIME</b>
 * - <b>Features: </b> watchdog timer configuration
 * - <b>Param: </b>
 * | config	| Unit		|
 * | :----:	| :----:	|
 * | timer*	| mS		|
 */
#define	CFG_WDT_TIME				(1000)		///< {unit: 1mS}
/**@}*/ /*** end of name wdt config */


/** 
 * @name wwdt config
 * @{
 */
/**
 * @details <b>CFG_WWDT_WWDTEN</b>
 * - <b>Features: </b> wwatchdog enable configuration
 * - <b>Param: </b>
 * | config	| Descriptions			|
 * | :----:	| :----:				|
 * | 0*		| enable w-watchdog		|
 * | 1		| disable w-watchdog	|
 */
#define	CFG_WWDT_WWDTEN				(0)			///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_WWDT_WINDOWS</b>
 * - <b>Features: </b> wwatchdog window value configuration
 * - <b>Param: </b>
 * | config	| Unit		|
 * | :----:	| :----:	|
 * | timer*	| mS		|
 */
#define	CFG_WWDT_WINDOWS	(50)		///< {unit: 1mS}
/**@}*/ /*** end of name wwdt config */
/**@}*/ /*** end of group csu39fx10_sdk_chip_driver_wdt_cfg */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup wdt_compile	attention: users do not need to care
 * @attention <b>users do not need to care</b>
 * @{
 */
/** 
 * @name wdt_compile_reg_wdtcon
 * @{
 */
#if(CFG_WDT_WDTEN!= 0)
	#define PRE_WDT_WDTEN				1
#else
	#define PRE_WDT_WDTEN				0
#endif

#if(CFG_WDT_WDTCLK_DIV== 0)
	#define C_CLK_DIVWDTCLK				(C_CLK_WDTCLK/ 256)
	#define PRE_WDT_WDTS				0
#elif(CFG_WDT_WDTCLK_DIV== 1)
	#define C_CLK_DIVWDTCLK				(C_CLK_WDTCLK/ 128)
	#define PRE_WDT_WDTS				1
#elif(CFG_WDT_WDTCLK_DIV== 2)
	#define C_CLK_DIVWDTCLK				(C_CLK_WDTCLK/ 64)
	#define PRE_WDT_WDTS				2
#elif(CFG_WDT_WDTCLK_DIV== 3)
	#define C_CLK_DIVWDTCLK				(C_CLK_WDTCLK/ 32)
	#define PRE_WDT_WDTS				3
#elif(CFG_WDT_WDTCLK_DIV== 4)
	#define C_CLK_DIVWDTCLK				(C_CLK_WDTCLK/ 16)
	#define PRE_WDT_WDTS				4
#elif(CFG_WDT_WDTCLK_DIV== 5)
	#define C_CLK_DIVWDTCLK				(C_CLK_WDTCLK/ 8)
	#define PRE_WDT_WDTS				5
#elif(CFG_WDT_WDTCLK_DIV== 6)
	#define C_CLK_DIVWDTCLK				(C_CLK_WDTCLK/ 4)
	#define PRE_WDT_WDTS				6
#elif(CFG_WDT_WDTCLK_DIV== 7)
	#define C_CLK_DIVWDTCLK				(C_CLK_WDTCLK/ 2)
	#define PRE_WDT_WDTS				7
#endif
/**@}*/ /*** end of name wdt_compile_reg_wdtcon */

/** 
 * @name wdt_compile_reg_wdtin
 * @{
 */
#define PRE_WDT_WDTIN					(uint8_t)((CFG_WDT_TIME* C_CLK_DIVWDTCLK/ 1000)- 1)
/**@}*/ /*** end of name wdt_compile_reg_wdtin */

/** 
 * @name wdt_compile_warning
 * @attention <b>compile warning message</b>
 * @{
 */
#define WARNING_WDT_TIME_MAX			(256* 1000/ C_CLK_DIVWDTCLK)		//{unit: 1mS}
#define WARNING_WDT_TIME_MIN			(1* 1000/ C_CLK_DIVWDTCLK)			//{unit: 1mS}

#if(CFG_WDT_WDTEN)
	#if(C_CLK_WDTCLK== 0)
		#warning "Warning: watchdog clock disable, turn on the watchdog clock{PRE_SYS_WDT_DISABLE}"
	#endif
	#if(CFG_WDT_TIME> WARNING_WDT_TIME_MAX)
		#warning "Warning: CFG_WDT_TIME define error, decrease CFG_WDT_TIME!"
	#endif
	#if(CFG_WDT_TIME< WARNING_WDT_TIME_MIN)
		#warning "Warning: CFG_WDT_TIME define error, increase CFG_WDT_TIME!"
	#endif
#endif
/**@}*/ /*** end of name wdt_compile_warning */

/** 
 * @name wwdt_compile_reg_wwdtcr
 * @{
 */
#if(CFG_WWDT_WWDTEN!= 0)
	#define PRE_WWDT_WWDTEN				1
#else
	#define PRE_WWDT_WWDTEN				0
#endif

#define PRE_WWDT_TR						0x7F
/**@}*/ /*** end of name wwdt_compile_reg_wwdtcr */

/** 
 * @name wwdt_compile_reg_wwdtwr
 * @{
 */
#define PRE_WWDT_WD						(uint8_t)(((uint16_t)CFG_WWDT_WINDOWS* 1000/ C_CLK_WWDTCLK)+ 0x3F)
/**@}*/ /*** end of name wwdt_compile_reg_wwdtwr */
 
/** 
 * @name wwdt_compile_warning
 * @attention <b>compile warning message</b>
 * @{
 */
#define	C_WWATCHDOG_TIME_MAX			(0x40* 1000/ C_CLK_WWDTCLK)		//{unit: 1mS}
#define C_WWATCHDOG_TIME_MIN			(1* 1000/ C_CLK_WWDTCLK)		//{unit: 1mS}

#if(CFG_WWDT_WWDTEN)
	#if(C_CLK_WDTCLK== 0)
		#warning "Warning: watchdog clock disable, turn on the watchdog clock"
	#endif
	#if((CFG_WWDT_WINDOWS> C_WWATCHDOG_TIME_MAX)|| 	\
		(CFG_WWDT_WINDOWS< C_WWATCHDOG_TIME_MIN))
		#warning "Warning: CFG_WWDT_WINDOWS define error, will be redefined!"
	#endif
#endif
/**@}*/ /*** end of name wwdt_compile_warning */
/**@}*/ /*** end of group wdt_compile */
/*******************************************************************************/




/******************************** dividing line ********************************/
/**
 * @addtogroup wdt_reg_default	reg_default_value
 * @{
 */
/**
 * @name wdt
 * @par 示例
 * @code
 *		void test( void )
 *		{
 *			WDTCON= PRE_WDTCON_DEFAULT;
 *			WDTIN= PRE_WDTIN_DEFAULT;
 *		}
 * @endcode
 * @{
 */
#define PRE_WDTCON_DEFAULT				(((PRE_WDT_WDTEN<< WDT_WDTEN_POS)& WDT_WDTEN_MASK)|				\
											((PRE_WDT_WDTS<< WDT_WDTS_POS)& WDT_WDTS_MASK))
#define PRE_WDTIN_DEFAULT				((PRE_WDT_WDTIN<< WDT_WDTIN_POS)& WDT_WDTIN_MASK)
/**@}*/ /*** end of name wwdt */


/**
 * @name wwdt
 * @par 示例
 * @code
 *		void test( void )
 *		{
 *			WWDTWR= PRE_WWDTWR_DEFAULT;
 *			WWDTCR= PRE_WWDTCR_DEFAULT;
 *		}
 * @endcode
 * @{
 */
#define PRE_WWDTCR_DEFAULT				(uint8_t)(((PRE_WWDT_WWDTEN<< WWT_WWDTEN_POS)& WWT_WWDTEN_MASK)|		\
											((PRE_WWDT_TR<< WWDT_TR_POS)& WWDT_TR_MASK))
#define PRE_WWDTWR_DEFAULT				(uint8_t)((PRE_WWDT_WD<< WWDT_WD_POS)& WWDT_WD_MASK)
/**@}*/ /*** end of name wwdt */
/**@}*/ /*** end of group wdt_reg_default */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup wdt_api	api
 * @{
 */
/**
 * @name wdt_api
 * @{
 */
/**
 * @brief 	<b>Description:</b> watchdog initialization.
 * @details <b>Function prototype:</b> void wdt_init(void);
 * @param[in]  null	.
 * @param[out] null.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			wdt_init();
 *		}
 * @endcode
 */
void wdt_init(void);
void wdt_disable(void);


/**
 * @brief 	<b>Description:</b> watchdog feeddog.
 * @details <b>Function prototype:</b> void wdt_feeddog(void);
 * @param[in]  null	.
 * @param[out] null.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			wdt_init();
 *		}
 * @endcode
 */
void wdt_feeddog(void);
/**@}*/ /*** end of name wdt_api */
 
/**
 * @name wwdt_api
 * @{
 */
/**
 * @brief 	<b>Description:</b> windows watchdog initialization.
 * @details <b>Function prototype:</b> void wwdt_init(void);
 * @param[in]  null	.
 * @param[out] null.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			wwdt_init();
 *		}
 * @endcode
 */
void wwdt_init(void);
void wwdt_disable(void);

/**
 * @brief 	<b>Description:</b> windows watchdog feeddog.
 * @details <b>Function prototype:</b> void wwdt_feeddog(void);
 * @param[in]  null	.
 * @param[out] null.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			wwdt_feeddog();
 *		}
 * @endcode
 */
void wwdt_feeddog(void);
/**@}*/ /*** end of name wwdt_api */
/**@}*/ /*** end of group wdt_api */
/**@}*/ /*** end of group csu39fx10_sdk_chip_driver_wdt */
/**@}*/ /*** end of group csu39fx10_sdk_chip_driver */
/**@}*/ /*** end of group csu39fx10_sdk_chip */
/*******************************************************************************/




#ifdef __cplusplus
}
#endif

#endif  //__DRV_WDT_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/
