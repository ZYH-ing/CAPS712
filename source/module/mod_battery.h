/***************************************************************************
 * @file     mod_battery.h
 * @version  V1.0.0
 * @author   0531
 * @date     2020-11-30 PM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 ****************************************************************************
 * @par 头文件
 *       drv_gpio.h
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

#ifndef __MOD_BATTERY_H__
#define __MOD_BATTERY_H__

// Include external header file.
#include "cs_common.h"
#include "system_csu39fx10.h"


#ifdef __cplusplus
extern "C" {
#endif


#define BANK_BATT				bank3

/**
 * @addtogroup csu39fx10_sdk_module	csu39fx10_sdk_module
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_module_adc_convert	adc_convert 
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_module_adc_convert_cfg	adc_convert_config
 * @{
 */
/**
 * @name	dcdc_interrupt_port
 * @{
 */

#define CFG_BATT_POWERON_TIME_DELAY			2000	//{ms}
 
 
 
/**
 * @details <b>CFG_INOUT_PORT_INT</b>
 * - <b>Features: </b> dcdc interrupt port configuration
 * - <b>Param: </b>
 * | config		| Descriptions	|
 * | :----:		| :----:		|
 * | GPIO_PT10	| pt10			|
 * | ....		| ....			|
 * | GPIO_PT37	| pt37			|
 */
// #define CFG_INOUT_PORT_INT				GPIO_PT22

/**@}*/ /*** end of name dcdc_interrupt_port */
 
/**
 * @name	dcdc_pstop_port
 * @{
 */
/**
 * @details <b>CFG_INOUT_PORT_PSTOP</b>
 * - <b>Features: </b> dcdc pstop port configuration
 * - <b>Param: </b>
 * | config		| Descriptions	|
 * | :----:		| :----:		|
 * | GPIO_PT10	| pt10			|
 * | ....		| ....			|
 * | GPIO_PT37	| pt37			|
 */
// #define CFG_INOUT_PORT_PSTOP			GPIO_PT14

/**
 * @details <b>CFG_INOUT_VBUS_DISC_POLARITY</b>
 * - <b>Features: </b> vbus discharge port polarity configuration
 * - <b>Param: </b>
 * | config		| Descriptions								|
 * | :----:		| :----:									|
 * | 0			| negative polarity, 1-> close, 0-> open	|
 * | 1			| positive polarity, 0-> close, 1-> open	|
 */
// #define CFG_INOUT_PORT_PSTOP_POLARITY	(0)
/**@}*/ /*** end of name dcdc_pstop_port */
 
/**
 * @name	vbus_port
 * @{
 */
/**
 * @details <b>CFG_INOUT_PORT_VBUS_DISC</b>
 * - <b>Features: </b> vbus discharge port configuration
 * - <b>Param: </b>
 * | config		| Descriptions	|
 * | :----:		| :----:		|
 * | GPIO_PT10	| pt10			|
 * | ....		| ....			|
 * | GPIO_PT37	| pt37			|
 */
// #define CFG_INOUT_PORT_VBUS_DISC		GPIO_PT37

/**
 * @details <b>CFG_INOUT_VBUS_DISC_POLARITY</b>
 * - <b>Features: </b> vbus discharge port polarity configuration
 * - <b>Param: </b>
 * | config		| Descriptions								|
 * | :----:		| :----:									|
 * | 0			| negative polarity, 1-> close, 0-> open	|
 * | 1			| positive polarity, 0-> close, 1-> open	|
 */
// #define CFG_INOUT_VBUS_DISC_POLARITY	(1)
/**@}*/ /*** end of name vbus_port */
 
/**
 * @name	type_c_a_port
 * @{
 */
/**
 * @details <b>CFG_INOUT_PORT_TCA_ACIN</b>
 * - <b>Features: </b> type_c_a charge detection configuration
 * - <b>Param: </b>
 * | config			| Descriptions	|
 * | :----:			| :----:		|
 * | GPIO_PT10		| pt10			|
 * | ....			| ....			|
 * | GPIO_PT37		| pt37			|
 * | LIST_REG_AC_OK	| DCDC-AC_OK	|
 */
// #define LIST_REG_AC_OK					0xF0		
// #define CFG_INOUT_PORT_TCA_ACIN			LIST_REG_AC_OK

/**
 * @details <b>CFG_INOUT_TCA_ACIN_POLARITY</b>
 * - <b>Features: </b> type_c_a vbus acin port polarity configuration
 * - <b>Param: </b>
 * | config		| Descriptions							|
 * | :----:		| :----:								|
 * | 0			| negative polarity, 1-> break, 0-> is	|
 * | 1			| positive polarity, 0-> break, 1-> is	|
 */
// #define CFG_INOUT_TCA_ACIN_POLARITY		(1)

/**
 * @details <b>CFG_INOUT_PORT_TCA_VBUS</b>
 * - <b>Features: </b> type_c_a vbus switch port configuration
 * - <b>Param: </b>
 * | config			| Descriptions	|
 * | :----:			| :----:		|
 * | GPIO_PT10		| pt10			|
 * | ....			| ....			|
 * | GPIO_PT37		| pt37			|
 * | LIST_REG_PGATE	| DCDC-PGATE	|
 */
// #define LIST_REG_PGATE					0xF0		
// #define CFG_INOUT_PORT_TCA_VBUS			LIST_REG_PGATE

/**
 * @details <b>CFG_INOUT_TCA_VBUS_POLARITY</b>
 * - <b>Features: </b> type_c_a vbus switch port polarity configuration
 * - <b>Param: </b>
 * | config		| Descriptions								|
 * | :----:		| :----:									|
 * | 0			| negative polarity, 1-> close, 0-> open	|
 * | 1			| positive polarity, 0-> close, 1-> open	|
 */
// #define CFG_INOUT_TCA_VBUS_POLARITY		(1)

/**
 * @details <b>CFG_INOUT_PORT_TCA_CURR</b>
 * - <b>Features: </b> typec_a current detection port configuration
 * - <b>Param: </b>
 * | config		| Descriptions	|
 * | :----:		| :----:		|
 * | GPIO_PT10	| pt10			|
 * | ....		| ....			|
 * | GPIO_PT37	| pt37			|
 */
// #define CFG_INOUT_PORT_TCA_CURR			GPIO_PT25
/**@}*/ /*** end of name type_c_a_port */


/**
 * @name	type_c_b_port
 * @{
 */
/**
 * @details <b>CFG_INOUT_PORT_TCB_ACIN</b>
 * - <b>Features: </b> type_c_b charge detection configuration
 * - <b>Param: </b>
 * | config		| Descriptions	|
 * | :----:		| :----:		|
 * | GPIO_PT10	| pt10			|
 * | ....		| ....			|
 * | GPIO_PT37	| pt37			|
 */
// #define CFG_INOUT_PORT_TCB_ACIN			GPIO_PT13

/**
 * @details <b>CFG_INOUT_TCB_ACIN_POLARITY</b>
 * - <b>Features: </b> type_c_b vbus acin port polarity configuration
 * - <b>Param: </b>
 * | config		| Descriptions							|
 * | :----:		| :----:								|
 * | 0			| negative polarity, 1-> break, 0-> is	|
 * | 1			| positive polarity, 0-> break, 1-> is	|
 */
// #define CFG_INOUT_TCB_ACIN_POLARITY		(0)

/**
 * @details <b>CFG_INOUT_PORT_TCB_VBUS</b>
 * - <b>Features: </b> type_c_b vbus switch port configuration
 * - <b>Param: </b>
 * | config		| Descriptions	|
 * | :----:		| :----:		|
 * | GPIO_PT10	| pt10			|
 * | ....		| ....			|
 * | GPIO_PT37	| pt37			|
 */
// #define CFG_INOUT_PORT_TCB_VBUS			GPIO_PT12

/**
 * @details <b>CFG_INOUT_TCB_VBUS_POLARITY</b>
 * - <b>Features: </b> type_c_b vbus switch port polarity configuration
 * - <b>Param: </b>
 * | config		| Descriptions								|
 * | :----:		| :----:									|
 * | 0			| negative polarity, 1-> close, 0-> open	|
 * | 1			| positive polarity, 0-> close, 1-> open	|
 */
// #define CFG_INOUT_TCB_VBUS_POLARITY		(1)

/**
 * @details <b>CFG_INOUT_PORT_TCB_CURR</b>
 * - <b>Features: </b> typec_a current detection port configuration
 * - <b>Param: </b>
 * | config		| Descriptions	|
 * | :----:		| :----:		|
 * | GPIO_PT10	| pt10			|
 * | ....		| ....			|
 * | GPIO_PT37	| pt37			|
 */
// #define CFG_INOUT_PORT_TCB_CURR			GPIO_PT26
/**@}*/ /*** end of name type_c_b_port */


/**
 * @name	type_a_1_port
 * @{
 */
/**
 * @details <b>CFG_INOUT_PORT_TA1_LOADIN</b>
 * - <b>Features: </b> type_a_1 charge detection configuration
 * - <b>Param: </b>
 * | config				| Descriptions	|
 * | :----:				| :----:		|
 * | GPIO_PT10			| pt10			|
 * | ....				| ....			|
 * | GPIO_PT37			| pt37			|
 * | LIST_REG_INDET1	| DCDC-INDET1	|
 * | LIST_REG_INDET2	| DCDC-INDET2	|
 */
// #define LIST_REG_INDET1					0xF0		
// #define LIST_REG_INDET2					0xF1		
// #define CFG_INOUT_PORT_TA1_LOADIN		LIST_REG_INDET2

/**
 * @details <b>CFG_INOUT_PORT_TA1_VBUS</b>
 * - <b>Features: </b> type_a_1 vbus switch port configuration
 * - <b>Param: </b>
 * | config		| Descriptions	|
 * | :----:		| :----:		|
 * | GPIO_PT10	| pt10			|
 * | ....		| ....			|
 * | GPIO_PT37	| pt37			|
 * | REG_GPO	| DCDC-GPO		|
 */
// #define LIST_REG_GPO					0xF0		
// #define CFG_INOUT_PORT_TA1_VBUS			LIST_REG_GPO

/**
 * @details <b>CFG_INOUT_PORT_TA1_CURR</b>
 * - <b>Features: </b> typea_1 current detection port configuration
 * - <b>Param: </b>
 * | config		| Descriptions	|
 * | :----:		| :----:		|
 * | GPIO_PT10	| pt10			|
 * | ....		| ....			|
 * | GPIO_PT37	| pt37			|
 */
// #define CFG_INOUT_PORT_TA1_CURR			GPIO_PT37

/**
 * @details <b>CFG_INOUT_TA1_VBUS_POLARITY</b>
 * - <b>Features: </b> type_a_1 vbus switch port polarity configuration
 * - <b>Param: </b>
 * | config		| Descriptions								|
 * | :----:		| :----:									|
 * | 0			| negative polarity, 1-> close, 0-> open	|
 * | 1			| positive polarity, 0-> close, 1-> open	|
 */
// #define CFG_INOUT_TA1_VBUS_POLARITY		(1)

/**@}*/ /*** end of name type_a_1_port */


/**
 * @name	inoutput_config
 * @{
 */
// #define CFG_CHECK_ACOK_TIME				(1000)					//1S
// #define CFG_CHECK_LOAD_TIME				(200)					//200ms
// #define CFG_PROHBIT_CHECKLOAD			(2000)					//2S
// #define CFG_LITTLE_CURRENT_TIME			(10000)					//10S
// #define CFG_ADC_SMALL_CURR				(7)						//ma
 
/**@}*/ /*** end of name inoutput_config */




/**@}*/ /*** end of group csu39fx10_sdk_chip_module_adc_convert_cfg */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup adc_convert_compile	attention: users do not need to care
 * @attention <b>users do not need to care</b>
 * @{
 */
/** 
 * @name adc_convert_compile_port
 * @{
 */
// #define PRE_SC_PORT_INT					(CFG_INOUT_PORT_INT/ 8)
// #define PRE_SC_PIN_INT					(CFG_INOUT_PORT_INT% 8)
// #define P_SC_INT						PRE_SC_PORT_INT, PRE_SC_PIN_INT

// #define PRE_PORT_PSTOP					(CFG_INOUT_PORT_PSTOP/ 8)
// #define PRE_PIN_PSTOP					(CFG_INOUT_PORT_PSTOP% 8)
// #define P_PSTOP							PRE_PORT_PSTOP, PRE_PIN_PSTOP

// #if(CFG_INOUT_PSTOP_POLARITY== 1)
	// #define	PRE_PSTOP_POLARITY			false
// #else
	// #define	PRE_PSTOP_POLARITY			true
// #endif


// #define PRE_PORT_VBUS_DISC				(CFG_INOUT_PORT_TCB_VBUS/ 8)
// #define PRE_PIN_VBUS_DISC				(CFG_INOUT_PORT_TCB_VBUS% 8)
// #define P_VBUS_DISC						PRE_PORT_VBUS_DISC, PRE_PIN_VBUS_DISC

// #if(CFG_INOUT_VBUS_DISC_POLARITY== 1)
	// #define	PRE_VBUS_DISC_POLARITY		false
// #else
	// #define	PRE_VBUS_DISC_POLARITY		true
// #endif


// #if(CFG_INOUT_PORT_TCA_ACIN== LIST_REG_AC_OK)
	// #define PRE_PORT_TCA_ACIN_REG		SC_MASK
	// #define PRE_PORT_TCA_ACIN_POS		(6)
// #else
// #endif

// #if(CFG_INOUT_TCA_ACIN_POLARITY== 1)
	// #define	PRE_TCA_ACIN_POLARITY		false
// #else
	// #define	PRE_TCA_ACIN_POLARITY		true
// #endif

// #if(CFG_INOUT_PORT_TCA_VBUS== LIST_REG_PGATE)
	// #define PRE_PORT_TCB_VBUS_REG		SC_CTRL3_SET
	// #define PRE_PORT_TCB_VBUS_POS		(7)
// #else
// #endif

// #if(CFG_INOUT_TCA_VBUS_POLARITY== 1)
	// #define	PRE_TCA_VBUS_POLARITY		false
// #else
	// #define	PRE_TCA_VBUS_POLARITY		true
// #endif

 
// #if(CFG_INOUT_PORT_TCB_ACIN== LIST_REG_AC_OK)
// #else
	// #define PRE_PORT_TCB_ACIN			(CFG_INOUT_PORT_TCB_ACIN/ 8)
	// #define PRE_PIN_TCB_ACIN			(CFG_INOUT_PORT_TCB_ACIN% 8)
	// #define P_TCB_ACIN					PRE_PORT_TCB_ACIN, PRE_PIN_TCB_ACIN
// #endif
 
// #if(CFG_INOUT_TCB_ACIN_POLARITY== 1)
	// #define	PRE_TCB_ACIN_POLARITY		false
// #else
	// #define	PRE_TCB_ACIN_POLARITY		true
// #endif

// #if(CFG_INOUT_PORT_TCB_VBUS== LIST_REG_PGATE)
// #else
	// #define PRE_PORT_TCB_VBUS			(CFG_INOUT_PORT_TCB_VBUS/ 8)
	// #define PRE_PIN_TCB_VBUS			(CFG_INOUT_PORT_TCB_VBUS% 8)
	// #define P_TCB_VBUS					PRE_PORT_TCB_VBUS, PRE_PIN_TCB_VBUS
// #endif
 
// #if(CFG_INOUT_TCB_VBUS_POLARITY== 1)
	// #define	PRE_TCB_VBUS_POLARITY		false
// #else
	// #define	PRE_TCB_VBUS_POLARITY		true
// #endif


// #if(CFG_INOUT_PORT_TA1_LOADIN== LIST_REG_INDET1)
	// #define PRE_PORT_TA1_LOADIN_REG		SC_STATUS
	// #define PRE_PORT_TA1_LOADIN_POS		(4)
// #elif(CFG_INOUT_PORT_TA1_LOADIN== LIST_REG_INDET2)
	// #define PRE_PORT_TA1_LOADIN_REG		SC_STATUS
	// #define PRE_PORT_TA1_LOADIN_POS		(5)
// #else
// #endif
 
// #if(CFG_INOUT_PORT_TA1_VBUS== LIST_REG_GPO)
	// #define PRE_PORT_TA1_VBUS_REG		SC_STATUS
	// #define PRE_PORT_TA1_VBUS_POS		(6)
// #else
// #endif

// #if(CFG_INOUT_TA1_VBUS_POLARITY== 1)
	// #define	PRE_TA1_VBUS_POLARITY		false
// #else
	// #define	PRE_TA1_VBUS_POLARITY		true
// #endif


// #define PRE_PORT_TCA_CURR				(CFG_INOUT_PORT_TCA_CURR/ 8)
// #define PRE_PIN_TCA_CURR				(CFG_INOUT_PORT_TCA_CURR% 8)
// #define P_TCA_CURR						PRE_PORT_TCA_CURR, PRE_PIN_TCA_CURR

// #define PRE_PORT_TCB_CURR				(CFG_INOUT_PORT_TCB_CURR/ 8)
// #define PRE_PIN_TCB_CURR				(CFG_INOUT_PORT_TCB_CURR% 8)
// #define P_TCB_CURR						PRE_PORT_TCB_CURR, PRE_PIN_TCB_CURR

// #define PRE_PORT_TA1_CURR				(CFG_INOUT_PORT_TA1_CURR/ 8)
// #define PRE_PIN_TA1_CURR				(CFG_INOUT_PORT_TA1_CURR% 8)
// #define P_TA1_CURR						PRE_PORT_TA1_CURR, PRE_PIN_TA1_CURR




// #define C_CHECK_ACOK_TIME				(CFG_CHECK_ACOK_TIME/ 100)
// #define C_CHECK_LOAD_TIME				(CFG_CHECK_LOAD_TIME/ 10)
// #define C_PROHBIT_CHECKLOAD				(CFG_PROHBIT_CHECKLOAD/ 10)
// #define C_LITTLE_CURRENT_TIME			(CFG_LITTLE_CURRENT_TIME/ 10)
// #define C_ADC_SMALL_CURR				CFG_ADC_SMALL_CURR
/**@}*/ /*** end of name adc_convert_compile_port */
/**@}*/ /*** end of group adc_convert_compile */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup adc_convert_enum	enum
 * @{
 */
/**
 * @brief  adc_convert - plug event.
 */
// typedef enum
// {
	// CURR_CHL_TCA		= (uint8_t)0,			/*!< typec_a channel*/
	// CURR_CHL_TCB,								/*!< typec_b channel*/
	// CURR_CHL_TA1,								/*!< typea_1 channel*/
// }adc_curr_chl_t;


/**@}*/ /*** end of group adc_convert_enum */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup adc_convert_struct	struct
 * @{
 */
/**
 * @brief  adc_convert_struct.
 */
 
typedef struct
{
	struct
	{
#if CFG_SIMP_BITFIELD
		uint8_t timer_1ms;							/*!< 1ms clock flag	*/
#else
		uint8_t timer_1ms	: 1;					/*!< 1ms clock flag	*/
#endif
	}flag;
	
	uint8_t poweron_energy;							/*!< initial battery power value after power-on {1%}	*/
	
}batt_t;
 
extern BANK_BATT batt_t	battery_data;
/**@}*/ /*** end of group adc_convert_struct */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup adc_convert_api	api
 * @{
 */
/**
 * @name adc_convert_api
 * @{
 */
/**
 * @brief 	<b>Description:</b> display initialization.
 * @details <b>Function prototype:</b> void mod_display_init(void);
 * @param[in]  null .
 * @param[out] null .
 * 
 * @return  null .
 * @par Example
 * @code
 *		void test( void )
 *		{
 *			mod_display_init();
 *		}
 * @endcode
 */
// void mod_adc_convert_init(void);
// void mod_adc_convert(void);
void mod_batt_timer(void);
void mod_batt_energy_measure(void);


/**@}*/ /*** end of group adc_convert_api */
/**@}*/ /*** end of group csu39fx10_sdk_chip_module_adc_convert */
/**@}*/ /*** end of group csu39fx10_sdk_module */
/*******************************************************************************/




#ifdef __cplusplus
}
#endif

#endif  //__MOD_BATTERY_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/
