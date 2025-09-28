/***************************************************************************
 * @file     mod_key.h
 * @version  V1.0.0
 * @author   0531
 * @date     2020-11-02 AM
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

#ifndef __MOD_KEY_H__
#define __MOD_KEY_H__

// Include external header file.
#include "drv_gpio.h"


#ifdef __cplusplus
extern "C" {
#endif


#define BANK_KEY	bank4

/**
 * @addtogroup csu39fx10_sdk_module	csu39fx10_sdk_module
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_module_key	key 
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_module_key_cfg	key_config
 * @{
 */
/**
 * @name	key_config
 * @{
 */
/**
 * @details <b>C_KEY_CNT_SHORT</b>
 * - <b>Features: </b> key short press time	
 * - <b>Param: </b>
 * | config	| unit		|
 * | :----:	| :----:	|
 * | time	| 10mS		|
 */
#define C_KEY_CNT_SHORT						(6)					///*!< key short press time		*/

/**
 * @details <b>C_KEY_CNT_DOUBLE</b>
 * - <b>Features: </b> key double press time
 * - <b>Param: </b>
 * | config	| unit		|
 * | :----:	| :----:	|
 * | time	| 10mS		|
 */
#define C_KEY_CNT_DOUBLE			        (50)				///*!< key double press time	*/
//#define C_KEY_CNT_DOUBLE			        (8)	
/**
 * @details <b>C_KEY_CNT_LONG</b>
 * - <b>Features: </b> key long press time
 * - <b>Param: </b>
 * | config	| unit		|
 * | :----:	| :----:	|
 * | time	| 10mS		|
 */
#define C_KEY_CNT_LONG			            (200)				///*!< key long press time		*/
/**@}*/ /*** end of name key_config */

/**@}*/ /*** end of group csu39fx10_sdk_chip_module_key_cfg */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup key_enum	enum
 * @{
 */
/**
 * @brief  key - led number.
 */
 
#define  Power_long_LED  1
#define  Led_short_LED   2 
#define  Power_Doule_LED   3  
 
 
typedef enum
{
	key_null	= (uint8_t)0x00,			/*!< key value null 	*/
	key_short,                              /*!< key value short 	*/
	key_double,                             /*!< key value double 	*/
	key_long,                               /*!< key value long, 	*/
}key_value_t;
/**@}*/ /*** end of group key_enum */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup key_struct	struct
 * @{
 */
/**
 * @brief  key_struct.
 */
typedef struct
{
	key_value_t	key_value;						/*!< key value */
	uint16_t key_cnt;							/*!< key counter */
	uint16_t double_press_cnt;					/*!< key double press counter */
	
	struct
	{
#if CFG_SIMP_BITFIELD
		uint8_t long_press;						/*!< key long press flag */
		uint8_t value_refresh;					/*!< key value refresh flag */
#else
		uint8_t long_press		: 1;			/*!< key long press flag */
		uint8_t value_refresh	: 1;			/*!< key value refresh flag */
#endif
	}flag;
}key_t;
/**@}*/ /*** end of group key_struct */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup key_api	api
 * @{
 */
/**
 * @name key_api
 * @{
 */
/**
 * @brief 	<b>Description:</b> key initialization.
 * @details <b>Function prototype:</b> void mod_key_init(void);
 * @param[in]  null .
 * @param[out] null .
 * 
 * @return  null .
 * @par Example
 * @code
 *		void test( void )
 *		{
 *			mod_key_init();
 *		}
 * @endcode
 */
 
 
extern BANK_KEY uint8_t Vaule1;
extern BANK_KEY uint8_t Set_3S_to_into_IAP;

extern BANK_KEY uint8_t F_A1_ON;
extern BANK_KEY uint8_t F_A1ON_TIME;

extern BANK_KEY uint8_t short_key_to_IAPtime;
extern BANK_KEY uint8_t short_key_to_IAP_Cnt;

extern BANK_KEY uint8_t key_down_5S_Flage;
extern BANK_KEY uint16_t key_down_5S_Cnt;


extern BANK_KEY uint8_t key_down_10S_Flage;
extern BANK_KEY uint16_t key_down_10S_Cnt;




void mod_key_init(void);

/**
 * @brief 	<b>Description:</b> key value scan.
 * @details <b>Function prototype:</b> void key_scan(void);
 * @attention <b>Called in the main loop 10ms</b>
 * @param[in]  null .
 * @param[out] null .
 * 
 * @return  null .
 * @par Example
 * @code
 *		void test( void )
 *		{
 *			key_scan();
 *		}
 * @endcode
 */
void key_scan(void);
void key2_scan(void);
/**
 * @brief 	<b>Description:</b> key handler.
 * @details <b>Function prototype:</b> void key_proc(void);
 * @param[in]  null .
 * @param[out] null .
 * 
 * @return  null .
 * @par Example
 * @code
 *		void test( void )
 *		{
 *			key_proc();
 *		}
 * @endcode
 */
void key_proc(void);
void key2_proc(void);
/**
 * @brief 	<b>Description:</b> get key value.
 * @details <b>Function prototype:</b> key_value_t key_get_value(void);
 * @param[in]  null .
 * @param[out] null .
 * 
 * @return  null .
 * @return  key_value_t  key_value.
 * @code
 *		void test( void )
 *		{
 *			key_value_t	key_value;
 *			key_value= key_get_value();
 *		}
 * @endcode
 */
key_value_t key_get_value(void);

/**@}*/ /*** end of group key_api */
/**@}*/ /*** end of group csu39fx10_sdk_chip_module_key */
/**@}*/ /*** end of group csu39fx10_sdk_module */
/*******************************************************************************/




#ifdef __cplusplus
}
#endif

#endif  //__MOD_KEY_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/
