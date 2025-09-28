/***************************************************************************//**
 * @file     csu39fx10_typec.h
 * @version  V1.0.0
 * @author   0431
 * @date     2021-02-04 AM
 * @brief    该文件包含了csu39fx10 typec模块底层函数库，协议库自动调用，用户一般无需关注。
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
 * <tr><td>2021/02/04  <td>1.0      <td>0431	  <td>创建初始版本
 * </table>
 *
 *****************************************************************************/

#ifndef __CSU39FX10_TYPEC_H__
#define __CSU39FX10_TYPEC_H__

// Include external header file.
#include "cs_common.h"
#include "csu39fx10_syscfg.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @addtogroup csu39fx10_sdk_chip	csu39fx10_sdk_chip
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_fwlib	fwlib 
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_fwlib_typec	typec 
 * @{
 */

/**
 * @addtogroup csu39fx10_typec_data_define	data_define
 * @{
 */
/**
  * @brief typec模块数据RAM-bank号，用户一般无需调整
  */
#define TC_BANK								bank7		///< bank号, 用户一般无需修改
/**
  * @brief typec模块数据RAM-bank号，用户一般无需调整
  */
#define TC_BANK_NUM							BANK7		///< bank_num_t 枚举类型 保持与TC_BANK的bank号相同


/**
 * @brief  Type-C端口号.
 */
typedef enum
{
	TYPECA,				/*!< A端口*/
	TYPECB,				/*!< B端口*/
}typec_instance_t;


/**
 * @brief  Type-C CCPIN号.
 */
typedef enum
{
	CC_PIN_CC1,			/*!< CC1 PIN*/
	CC_PIN_CC2,			/*!< CC2 PIN*/
}typec_cc_pin_t;


/**
 * @brief  Type-C 角色.
 */
typedef enum
{
	DISABLED_STATE			= (uint8_t)0x00,	/*!< Disabled State		*/
	UNATTACHED_SNK			= (uint8_t)0x01,	/*!< SINK拔出			*/
	UNATTACHED_SRC			= (uint8_t)0x02,	/*!< SOURCE拔出			*/
	ATTACHWAIT_SNK			= (uint8_t)0x03,	/*!< SINK插入WAIT		*/
	ATTACHWAIT_SRC			= (uint8_t)0x04,	/*!< SOURCE插入WAIT		*/
	TRY_SRC					= (uint8_t)0x05,	/*!< TRY_SOURCE			*/
	TRYWAIT_SNK				= (uint8_t)0x06,	/*!< TRY_WAIT_SOURCE	*/
	ATTACHED_SNK			= (uint8_t)0x07,	/*!< SINK插入			*/
	ATTACHED_SRC			= (uint8_t)0x08,	/*!< SOURCE插入			*/
}typec_state_t;


/**
 * @brief  Type-C CCPIN上拉电流源.
 */
typedef enum
{
	TYPEC_CCX_CUR_OFF		= (uint8_t)0x00,	/*!< 关闭*/
	TYPEC_CCX_CUR_080UA		= (uint8_t)0x01,    /*!< 80uA*/
	TYPEC_CCX_CUR_180UA		= (uint8_t)0x02,    /*!< 180uA*/
	TYPEC_CCX_CUR_330UA		= (uint8_t)0x03,    /*!< 330uA*/
}typec_current_source_t;
/**@}*/ /*** end of group csu39fx10_typec_data_define */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup fwlib_typec_api	api
 * @{
 */
/**
 * @name fwlib_typec_api
 * @{
 */
/**
 * @brief 	<b>Description:</b> fwlib_typec库函数.
 * @attention <b> 协议库函数调用，用户无需关注。</b>
 * 
 */
void fwlib_typec_cc_pull_high_down_set(typec_instance_t instance,status_t status);
void fwlib_typec_cc_pull_high_down_config(typec_instance_t instance,typec_current_source_t cc_current,status_t status);
void fwlib_fwlib_typec_cc_drp_set(typec_instance_t instance,status_t status);
void fwlib_typec_cc_det_set(typec_instance_t instance,status_t status);
void fwlib_typec_scnxie_set(typec_instance_t instance,status_t status);
status_t fwlib_typec_detxif_get(typec_instance_t instance);
void fwlib_typec_detxif_set(typec_instance_t instance,status_t status);
uint8_t fwlib_typec_cc_rlt_get(typec_instance_t instance);
void fwlib_typec_vconn_config(typec_instance_t instance,typec_cc_pin_t cc_pin,status_t status);
void fwlib_typec_cc_pin_config(typec_instance_t instance);
bool fwlib_typec_get_scnaif(void);
void fwlib_typec_clear_scnaif(void);
bool fwlib_typec_get_scnbif(void);
void fwlib_typec_clear_scnbif(void);
void fwlib_typec_disable_cc_pinmux(typec_instance_t instance, status_t status);

/**@}*/ /*** end of name fwlib_typec_api */
/**@}*/ /*** end of group fwlib_typec_api */

/**@}*/ /*** end of group csu39fx10_sdk_chip_fwlib_typec */
/**@}*/ /*** end of group csu39fx10_sdk_chip_fwlib */
/**@}*/ /*** end of group csu39fx10_sdk_chip */
/*******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif  //__CSU39FX10_TYPEC_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/

