/***************************************************************************
 * @file     mod_coulomb.h
 * @version  V1.0.0
 * @author   0531
 * @date     2020-11-17 PM
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

#ifndef __MOD_COULOMB_H__
#define __MOD_COULOMB_H__

// Include external header file.
#include "drv_gpio.h"
#include "cs_common.h"


#ifdef __cplusplus
extern "C" {
#endif




/**
 * @addtogroup csu39fx10_sdk_module	csu39fx10_sdk_module
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_module_coulomb	coulomb 
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_module_coulomb_cfg	coulomb_config
 * @{
 */
/**
 * @name	vbus_port
 * @{
 */
 
#define BANK_COULOMB						bank4

#define CFG_BATT_CAPACITY					(10000)		/*!< 单并电池容量, 毫安时*/
#define CFG_BATT_CELLS_P					(1)			/*!< 并联电池数量, {总电池容量= CFG_BATT_CAPACITY* CFG_BATT_CELLS_P}*/
#define CFG_BATT_CELLS_S					(4)			/*!< 串联电池数量*/
//#define CFG_BATT_CELLS_S					(3)			/*!< 串联电池数量*/

#define CFG_VBAT_CV							(4100)		/*!< 单串电池恒压充电阈值	*/
#define CFG_VBAT_LOW						(3000)		/*!< 单串电池低电量阈值		*/
#define CFG_VBAT_ALARM						(3200)		/*!< 单串电池电量报警阈值	*/
#define CFG_IBAT_SAMLLCURR					(500)		/*!< 单并电池充电小电流阈值	*/


/**@}*/ /*** end of name vbus_port */
/**@}*/ /*** end of group csu39fx10_sdk_chip_module_coulomb_cfg */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup coulomb_compile	attention: users do not need to care
 * @attention <b>users do not need to care</b>
 * @{
 */
/** 
 * @name coulomb_compile_port
 * @{
 */



/**@}*/ /*** end of name coulomb_compile_port */
/**@}*/ /*** end of group coulomb_compile */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup coulomb_enum	enum
 * @{
 */
/**
 * @brief  coulomb.
 */
typedef enum
{
	COULOMB_NULL		= 0x00,		/*!< No charge and no discharge state	*/
	COULOMB_CHARGE,					/*!< charging status*/
	COULOMB_DISCHARGE,				/*!< Discharge status*/
}coulomb_charge_status_t;


/**@}*/ /*** end of group coulomb_enum */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup coulomb_struct	struct
 * @{
 */
/**
 * @brief  coulomb_struct.
 */
typedef struct
{
	uint16_t batt_capacity;							/*!< Battery capacity, {unit: mah}								*/
	uint8_t batt_cells_p;							/*!< Number of batteries in parallel							*/
	uint8_t batt_cells_s;							/*!< Number of batteries in series								*/

	uint16_t vbat_cv;								/*!< Battery constant voltage charging value, {unit: mv}		*/
	uint16_t vbat_low;								/*!< Low battery level, {unit: mv}								*/
	uint16_t vbat_alarm;							/*!< Battery voltage alarm value, {unit: mv}					*/
	uint16_t ibat_samllcurr;						/*!< Battery charging low current, {unit: ma}					*/
}coulomb_input_t;


typedef struct
{
	uint8_t batt_energy;							/*!< Battery charge percentage {unit: 1%}						*/
	uint8_t b_batt_full;							/*!< Battery full flag 											*/
	uint8_t b_batt_low;								/*!< Low battery flag 											*/
	uint8_t b_batt_alarm;							/*!< Battery level alarm flag									*/
	uint8_t b_pstop;								/*!< Stop charging flag, {DCDC charging should be turned off}	*/
}coulomb_output_t;


typedef struct
{
	coulomb_input_t		input;
	coulomb_output_t	output;
}coulomb_t;

extern BANK_COULOMB coulomb_t	coulomb_data;

/**@}*/ /*** end of group coulomb_struct */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup coulomb_api	api
 * @{
 */
/**
 * @name coulomb_api
 * @{
 */
/**
 * @brief 	<b>Description:</b> display initialization.
 * @details <b>Function prototype:</b> void mod_coulomb_batt_energy_measure(uint16_t vbat);
 * @param[in]  null .
 * @param[out] null .
 * 
 * @return  null .
 * @par Example
 * @code
 *		void test( void )
 *		{
 *			mod_coulomb_batt_energy_measure(4200);
 *		}
 * @endcode
 */
void mod_coulomb_init(void);
void mod_coulomb_batt_energy_measure(uint16_t vbat);
void mod_coulomb_coulomb_algo(coulomb_charge_status_t charge_status,	\
								uint16_t ibat, uint16_t vbat,			\
								bool b_eoc);

/**@}*/ /*** end of group coulomb_api */
/**@}*/ /*** end of group csu39fx10_sdk_chip_module_coulomb */
/**@}*/ /*** end of group csu39fx10_sdk_module */
/*******************************************************************************/




#ifdef __cplusplus
}
#endif

#endif  //__MOD_COULOMB_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/
