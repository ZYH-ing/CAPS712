/***************************************************************************
 * @file     mod_input_output.h
 * @version  V1.0.0
 * @author   0531
 * @date     2020-11-10 PM
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

#ifndef __MOD_INPUT_OUTPUT_H__
#define __MOD_INPUT_OUTPUT_H__

// Include external header file.
#include "drv_gpio.h"
#include "mod_dcdc.h "


#ifdef __cplusplus
extern "C" {
#endif


#define BANK_IO				bank4

/**
 * @addtogroup csu39fx10_sdk_module	csu39fx10_sdk_module
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_module_input_output	input_output 
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_module_input_output_cfg	input_output_config
 * @{
 */
/**
 * @name	dcdc_interrupt_port
 * @{
 */
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
#define CFG_INOUT_PORT_INT				GPIO_PT12
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
#define CFG_INOUT_PORT_PSTOP			GPIO_PT22
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
#define CFG_INOUT_PSTOP_POLARITY	(0)
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
#define CFG_INOUT_PORT_VBUS_DISC		GPIO_PT37

/**
 * @details <b>CFG_INOUT_VBUS_DISC_POLARITY</b>
 * - <b>Features: </b> vbus discharge port polarity configuration
 * - <b>Param: </b>
 * | config		| Descriptions								|
 * | :----:		| :----:									|
 * | 0			| negative polarity, 1-> close, 0-> open	|
 * | 1			| positive polarity, 0-> close, 1-> open	|
 */
#define CFG_INOUT_VBUS_DISC_POLARITY	(1)
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
#define LIST_REG_AC_OK					0xF0		
#define CFG_INOUT_PORT_TCA_ACIN			LIST_REG_AC_OK

/**
 * @details <b>CFG_INOUT_TCA_ACIN_POLARITY</b>
 * - <b>Features: </b> type_c_a vbus acin port polarity configuration
 * - <b>Param: </b>
 * | config		| Descriptions							|
 * | :----:		| :----:								|
 * | 0			| negative polarity, 1-> break, 0-> is	|
 * | 1			| positive polarity, 0-> break, 1-> is	|
 */
#define CFG_INOUT_TCA_ACIN_POLARITY		(1)

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
#define LIST_REG_PGATE					0xF0		
#define CFG_INOUT_PORT_TCA_VBUS			LIST_REG_PGATE

/**
 * @details <b>CFG_INOUT_TCA_VBUS_POLARITY</b>
 * - <b>Features: </b> type_c_a vbus switch port polarity configuration
 * - <b>Param: </b>
 * | config		| Descriptions								|
 * | :----:		| :----:									|
 * | 0			| negative polarity, 1-> close, 0-> open	|
 * | 1			| positive polarity, 0-> close, 1-> open	|
 */
#define CFG_INOUT_TCA_VBUS_POLARITY		(1)

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
#define CFG_INOUT_PORT_TCA_CURR			GPIO_PT21
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
#define CFG_INOUT_PORT_TCB_ACIN			GPIO_PT13

/**
 * @details <b>CFG_INOUT_TCB_ACIN_POLARITY</b>
 * - <b>Features: </b> type_c_b vbus acin port polarity configuration
 * - <b>Param: </b>
 * | config		| Descriptions							|
 * | :----:		| :----:								|
 * | 0			| negative polarity, 1-> break, 0-> is	|
 * | 1			| positive polarity, 0-> break, 1-> is	|
 */
#define CFG_INOUT_TCB_ACIN_POLARITY		(0)

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
#define CFG_INOUT_PORT_TCB_VBUS			GPIO_PT20
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
#define CFG_INOUT_TCB_VBUS_POLARITY		(1)

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
#define CFG_INOUT_PORT_TCB_CURR			GPIO_PT26
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
#define LIST_REG_INDET1					0xF0		
#define LIST_REG_INDET2					0xF1		
#define CFG_INOUT_PORT_TA1_LOADIN		LIST_REG_INDET2

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
#define LIST_REG_GPO					0xF0		
#define CFG_INOUT_PORT_TA1_VBUS			LIST_REG_GPO

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
#define CFG_INOUT_PORT_TA1_CURR			GPIO_PT37

/**
 * @details <b>CFG_INOUT_TA1_VBUS_POLARITY</b>
 * - <b>Features: </b> type_a_1 vbus switch port polarity configuration
 * - <b>Param: </b>
 * | config		| Descriptions								|
 * | :----:		| :----:									|
 * | 0			| negative polarity, 1-> close, 0-> open	|
 * | 1			| positive polarity, 0-> close, 1-> open	|
 */
#define CFG_INOUT_TA1_VBUS_POLARITY		(1)

/**@}*/ /*** end of name type_a_1_port */


/**
 * @name	inoutput_config
 * @{
 */
#define CFG_CHECK_ACOK_TIME				(1000)					//1S
#define CFG_CHECK_LOAD_TIME				(200)					//200ms
#define CFG_PROHBIT_CHECKLOAD			(2000)					//2S
//#define CFG_LITTLE_CURRENT_TIME		(100000)				//100S
#define CFG_LITTLE_CURRENT_TIME			(10000)				//10S

#define CFG_ADC_SMALL_CURR				(70)					//ma

/**@}*/ /*** end of name inoutput_config */




/**@}*/ /*** end of group csu39fx10_sdk_chip_module_input_output_cfg */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup input_output_compile	attention: users do not need to care
 * @attention <b>users do not need to care</b>
 * @{
 */
/** 
 * @name input_output_compile_port
 * @{
 */
#define PRE_SC_PORT_INT					(CFG_INOUT_PORT_INT/ 8)
#define PRE_SC_PIN_INT					(CFG_INOUT_PORT_INT% 8)
#define P_SC_INT						PRE_SC_PORT_INT, PRE_SC_PIN_INT

#define PRE_PORT_PSTOP					(CFG_INOUT_PORT_PSTOP/ 8)
#define PRE_PIN_PSTOP					(CFG_INOUT_PORT_PSTOP% 8)
#define P_PSTOP							PRE_PORT_PSTOP, PRE_PIN_PSTOP

#if(CFG_INOUT_PSTOP_POLARITY== 1)
	#define	PRE_PSTOP_POLARITY			false
#else
	#define	PRE_PSTOP_POLARITY			true
#endif


#define PRE_PORT_VBUS_DISC				(CFG_INOUT_PORT_VBUS_DISC/ 8)
#define PRE_PIN_VBUS_DISC				(CFG_INOUT_PORT_VBUS_DISC% 8)
#define P_VBUS_DISC						PRE_PORT_VBUS_DISC, PRE_PIN_VBUS_DISC

#if(CFG_INOUT_VBUS_DISC_POLARITY== 1)
	#define	PRE_VBUS_DISC_POLARITY		false
#else
	#define	PRE_VBUS_DISC_POLARITY		true
#endif


#if(CFG_INOUT_PORT_TCA_ACIN== LIST_REG_AC_OK)
	#define PRE_PORT_TCA_ACIN_REG		SC_MASK
	#define PRE_PORT_TCA_ACIN_POS		(6)
#else
#endif

#if(CFG_INOUT_TCA_ACIN_POLARITY== 1)
	#define	PRE_TCA_ACIN_POLARITY		false
#else
	#define	PRE_TCA_ACIN_POLARITY		true
#endif

#if(CFG_INOUT_PORT_TCA_VBUS== LIST_REG_PGATE)
	#define PRE_PORT_TCB_VBUS_REG		SC_CTRL3_SET
	#define PRE_PORT_TCB_VBUS_POS		(7)
#else
#endif

#if(CFG_INOUT_TCA_VBUS_POLARITY== 1)
	#define	PRE_TCA_VBUS_POLARITY		false
#else
	#define	PRE_TCA_VBUS_POLARITY		true
#endif

 
#if(CFG_INOUT_PORT_TCB_ACIN== LIST_REG_AC_OK)
#else
	#define PRE_PORT_TCB_ACIN			(CFG_INOUT_PORT_TCB_ACIN/ 8)
	#define PRE_PIN_TCB_ACIN			(CFG_INOUT_PORT_TCB_ACIN% 8)
	#define P_TCB_ACIN					PRE_PORT_TCB_ACIN, PRE_PIN_TCB_ACIN
#endif
 
#if(CFG_INOUT_TCB_ACIN_POLARITY== 1)
	#define	PRE_TCB_ACIN_POLARITY		false
#else
	#define	PRE_TCB_ACIN_POLARITY		true
#endif

#if(CFG_INOUT_PORT_TCB_VBUS== LIST_REG_PGATE)
#else
	#define PRE_PORT_TCB_VBUS			(CFG_INOUT_PORT_TCB_VBUS/ 8)
	#define PRE_PIN_TCB_VBUS			(CFG_INOUT_PORT_TCB_VBUS% 8)
	#define P_TCB_VBUS					PRE_PORT_TCB_VBUS, PRE_PIN_TCB_VBUS
#endif
 
#if(CFG_INOUT_TCB_VBUS_POLARITY== 1)
	#define	PRE_TCB_VBUS_POLARITY		false
#else
	#define	PRE_TCB_VBUS_POLARITY		true
#endif


#if(CFG_INOUT_PORT_TA1_LOADIN== LIST_REG_INDET1)
	#define PRE_PORT_TA1_LOADIN_REG		SC_STATUS
	#define PRE_PORT_TA1_LOADIN_POS		(4)
#elif(CFG_INOUT_PORT_TA1_LOADIN== LIST_REG_INDET2)
	#define PRE_PORT_TA1_LOADIN_REG		SC_STATUS
	#define PRE_PORT_TA1_LOADIN_POS		(5)
#else
#endif
 
#if(CFG_INOUT_PORT_TA1_VBUS== LIST_REG_GPO)
	#define PRE_PORT_TA1_VBUS_REG		SC_STATUS
	#define PRE_PORT_TA1_VBUS_POS		(6)
#else
#endif

#if(CFG_INOUT_TA1_VBUS_POLARITY== 1)
	#define	PRE_TA1_VBUS_POLARITY		false
#else
	#define	PRE_TA1_VBUS_POLARITY		true
#endif


#define PRE_PORT_TCA_CURR				(CFG_INOUT_PORT_TCA_CURR/ 8)
#define PRE_PIN_TCA_CURR				(CFG_INOUT_PORT_TCA_CURR% 8)
#define P_TCA_CURR						PRE_PORT_TCA_CURR, PRE_PIN_TCA_CURR

#define PRE_PORT_TCB_CURR				(CFG_INOUT_PORT_TCB_CURR/ 8)
#define PRE_PIN_TCB_CURR				(CFG_INOUT_PORT_TCB_CURR% 8)
#define P_TCB_CURR						PRE_PORT_TCB_CURR, PRE_PIN_TCB_CURR

#define PRE_PORT_TA1_CURR				(CFG_INOUT_PORT_TA1_CURR/ 8)
#define PRE_PIN_TA1_CURR				(CFG_INOUT_PORT_TA1_CURR% 8)
#define P_TA1_CURR						PRE_PORT_TA1_CURR, PRE_PIN_TA1_CURR




#define C_CHECK_ACOK_TIME				(CFG_CHECK_ACOK_TIME/ 100)
#define C_CHECK_LOAD_TIME				(CFG_CHECK_LOAD_TIME/ 10)
#define C_PROHBIT_CHECKLOAD				(CFG_PROHBIT_CHECKLOAD/ 10)
#define C_LITTLE_CURRENT_TIME			(CFG_LITTLE_CURRENT_TIME/ 10)
//#define C_ADC_SMALL_CURR				CFG_ADC_SMALL_CURR
#define C_ADC_SMALL_CURR				6

//#define  TCA_EN_PIN     PT13
//#define  TCA_EN_PIN_EN  PT1EN3
//#define  TCA_EN_PIN_PU  PT1PU3
//#define  TCA_EN_OPEN    {TCA_EN_PIN_EN=1;TCA_EN_PIN=1;PT1PU3=1;}
//#define  TCA_EN_Close   {TCA_EN_PIN_EN=0;TCA_EN_PIN=0;PT1PU3=0;}

//#define  TCB_EN_PIN     PT11
//#define  TCB_EN_PIN_EN  PT1EN1
//#define  TCB_EN_OPEN    {TCB_EN_PIN_EN=1;TCB_EN_PIN=1;}
//#define  TCB_EN_Close   {TCB_EN_PIN_EN=1;TCB_EN_PIN=0;}

//
//#define  TAA_EN_PIN     
//#define  TAA_EN_PIN_EN  PT1EN0
//#define  TAA_EN_OPEN    {TAA_EN_PIN_EN=1;TAA_EN_PIN=1;}
//#define  TAA_EN_Close   {TAA_EN_PIN_EN=1;TAA_EN_PIN=0;}
#define    POWER_OC   PT10
#define    POWER_OC_EN  PT1EN0
#define    POWER_OC_PU  PT1PU0
#define    POWER_OC_EN_inti  {POWER_OC_PU=1;POWER_OC_EN=0;POWER_OC=0;}

#define    POWER_OC_to_low  {POWER_OC_EN=1;POWER_OC=0;}

/**@}*/ /*** end of name input_output_compile_port */
/**@}*/ /*** end of group input_output_compile */
/*******************************************************************************/

//#define  USBA1_check  PT25
#define  USBA2_check  PT14

#define  TOUCH_OUT  PT14

/******************************** dividing line ********************************/
/** 
 * @addtogroup input_output_enum	enum
 * @{
 */
/**
 * @brief  input_output - plug event.
 * A1D:	typea1 discharge
 * B1C:	typeb1 charge
 * CAC:	typeca charge
 * CAD:	typeca discharge
 * CBC:	typecb charge
 * CBD:	typecb discharge
 */
typedef enum
{
	PLUG_NULL		= (uint8_t)0,			/*!< 0, plug_event null 			*/
	PLUG_A1D_IN,                            /*!< 1, type-a_1(load) plug 		*/
	PLUG_A1D_OUT,                           /*!< 2, type-a_1 unplug 			*/
	PLUG_B1C_IN,                         	/*!< 3, type-b_1(charge) plug		*/ /// miro 口
	PLUG_B1C_OUT,                        	/*!< 4, type-b_1 unplug 			*/
	PLUG_CAC_IN,                            /*!< 5, type-c_a(charge) plug 		*/
	PLUG_CAD_IN,                            /*!< 6, type-c_a(discharge) plug 	*/
	PLUG_CAX_OUT,                           /*!< 7, type-c_a unplug 			*/
	PLUG_CBC_IN,                            /*!< 8, type-c_b(charge) plug 		*/
	PLUG_CBD_IN,                            /*!< 9, type-c_b(discharge) plug 	*/
	PLUG_CBX_OUT,                           /*!< 10, type-c_b unplug 			*/
	PLUG_CA_RST_P,							/*!< 11, type-c_a reset				*/
	PLUG_CA_RST_N,							/*!< 12, type-c_a reset				*/
	PLUG_CB_RST_P,							/*!< 13, type-c_b reset				*/
	PLUG_CB_RST_N,							/*!< 14, type-c_b reset				*/
	PLUG_CA_SWAP_SRC,						/*!< 15, type-c_a swap				*/
	PLUG_CA_SWAP_SNK,						/*!< 16, type-c_a swap				*/
	PLUG_CA_SWAP_N,							/*!< 17, type-c_a swap				*/
	PLUG_CB_SWAP_SRC,                    	/*!< 18, type-c_b swap				*/
	PLUG_CB_SWAP_SNK,                    	/*!< 19, type-c_b swap				*/
	PLUG_CB_SWAP_N,                    		/*!< 20, type-c_b swap				*/
}plug_event_t;


/**@}*/ /*** end of group input_output_enum */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup input_output_struct	struct
 * @{
 */
/**
 * @brief  input_output_struct.
 */
typedef struct
{
	struct
	{
#if CFG_SIMP_BITFIELD
		uint8_t type_a1;						/*!< type-a_1 vbus, true-> on, false-> off 			*/
		uint8_t type_b1;						/*!< type-b_1 vbus, true-> on, false-> off 			*/
		uint8_t type_ca;						/*!< type-c_a vbus, true-> on, false-> off 			*/
		uint8_t type_cb;						/*!< type-c_b vbus, true-> on, false-> off 			*/
		uint8_t discharge;						/*!< vbus discharge, true-> on, false-> off 		*/
		uint8_t pstop;							/*!< dcdc pstop, true-> dcdc-on, false-> dcdc-off	*/
#else
		uint8_t type_a1		: 1;				/*!< type-a_1 vbus, true-> on, false-> off 			*/
		uint8_t type_b1		: 1;				/*!< type-b_1 vbus, true-> on, false-> off 			*/
		uint8_t type_ca		: 1;				/*!< type-c_a vbus, true-> on, false-> off 			*/
		uint8_t type_cb		: 1;				/*!< type-c_b vbus, true-> on, false-> off 			*/
		uint8_t discharge	: 1;				/*!< vbus discharge, true-> on, false-> off 		*/
		uint8_t pstop		: 1;				/*!< dcdc pstop, true-> dcdc-on, false-> dcdc-off	*/
#endif
	}sw;

	uint8_t vbus_type_a1_delay_cnt;				/*!< type-a_1 vbus switch delay counter, {uint-> 10ms} 	*/
	uint8_t vbus_type_b1_delay_cnt;     		/*!< type-a_1 vbus switch delay counter, {uint-> 10ms} 	*/
	uint8_t vbus_type_ca_delay_cnt;     		/*!< type-a_1 vbus switch delay counter, {uint-> 10ms} 	*/
	uint8_t vbus_type_cb_delay_cnt;     		/*!< type-a_1 vbus switch delay counter, {uint-> 10ms} 	*/
	uint8_t vbus_discharge_delay_cnt;			/*!< vbus discharge switch delay counter, {uint-> 10ms} */
	uint8_t pstop_delay_cnt;					/*!< dcdc pstop switch delay counter, {uint-> 10ms} 	*/
}vbus_switch_t;


typedef struct
{
	uint8_t b_level;							/*!< Load IN引脚电平 */
	uint8_t b_raising;							/*!< Load IN上升沿产生 */
	uint8_t b_load_sta;							/*!< 负载存在标志(SET,在;RESET,不在) */
	uint16_t t_prohbit_check;					/*!< 小负载时，负载仪出喘振，在一段时间内禁止IO检负载 */
	uint8_t t_isexist;
	uint32_t t_isnotexist;
}typeax_t;



typedef struct
{
	uint8_t b_level;
	uint8_t t_isexist;
	uint8_t t_isnotexist;
}dcdc_acok_t;

typedef struct
{
	typeax_t		typea1;
	typeax_t		typea2;
	dcdc_acok_t		dcdc_acok;
}misc_interface_t;


typedef struct
{
	union
	{
		struct
		{
#if CFG_SIMP_BITFIELD
			uint8_t b_a1d;						/*!< type-a_1 discharge, highly effective */
			uint8_t b_b1c;						/*!< type-b_1 charge, highly effective */
			uint8_t b_cac;						/*!< type-c_a charge, highly effective */
			uint8_t b_cad;						/*!< type-c_a discharge, highly effective */
			uint8_t b_cbc;						/*!< type-c_b charge, highly effective */
			uint8_t b_cbd;						/*!< type-c_b discharge, highly effective */
#else
			uint8_t b_a1d: 1;					/*!< type-a_1 discharge, highly effective */
			uint8_t b_b1c: 1;					/*!< type-b_1 charge, highly effective */
			uint8_t b_cac: 1;					/*!< type-c_a charge, highly effective */
			uint8_t b_cad: 1;					/*!< type-c_a discharge, highly effective */
			uint8_t b_cbc: 1;					/*!< type-c_b charge, highly effective */
			uint8_t b_cbd: 1;					/*!< type-c_b discharge, highly effective */
#endif
		}flag;
	    uint8_t r_plug;
	}plug_status;
	
	vbus_switch_t	vbus_switch;
}inoutput_t;




extern BANK_IO inoutput_t			inoutput_data;
extern BANK_IO misc_interface_t		misc_interface;

extern BANK_IO uint8_t CA_IN_Flage;
extern BANK_IO uint8_t CB_IN_Flage;
extern BANK_IO uint8_t MirB_IN_Flage;

extern BANK_IO  TOUCH_OUT_CNT;
/**@}*/ /*** end of group input_output_struct */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup input_output_api	api
 * @{
 */
/**
 * @name input_output_api
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
// void mod_display_init(void);
void mod_inoutput_init(void);
void mod_inoutput_disable(void);
void mod_inoutput_plug_check_proc(void);
void mod_inoutput_plug_check_proc_USBA2(void);
void mod_io_vbus_switch(void);
void mod_io_vbus_switch_timer(void);
bool mod_io_typeca_acin(void);
bool mod_io_typecb_acin(void);

/**@}*/ /*** end of group input_output_api */
/**@}*/ /*** end of group csu39fx10_sdk_chip_module_input_output */
/**@}*/ /*** end of group csu39fx10_sdk_module */
/*******************************************************************************/


void mod_io_a1d_out(void);


#ifdef __cplusplus
}
#endif

#endif  //__MOD_INPUT_OUTPUT_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/
