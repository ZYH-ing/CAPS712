/***************************************************************************//**
 * @file     csu39fx10_pd.h
 * @version  V1.0.0
 * @author   0431
 * @date     2021-02-04 PM
 * @brief    该文件包含了csu39fx10 pd模块底层函数库，协议库自动调用，用户一般无需关注。
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

#ifndef __CSU39FX10_PD_H__
#define __CSU39FX10_PD_H__

// Include external header file.
#include "cs_common.h"

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
 * @addtogroup csu39fx10_sdk_chip_fwlib_pd	pd 
 * @{
 */

/**
 * @addtogroup csu39fx10_pd_data_define	data_define
 * @{
 */
/**
  * @brief pd模块数据RAM-bank号，用户一般无需调整
  */
#define PD_BANK									bank5	///< bank号, 用户一般无需修改
#define PD_BANK_OF								bank6	///< bank号, 用户一般无需修改
/**
  * @brief pd模块数据RAM-bank号，用户一般无需调整
  */
#define PD_BANK_NUM								BANK5	///< bank_num_t 枚举类型 保持与PD_BANK的bank号相同
#define PD_BANK_NUM_OF							BANK6	///< bank_num_t 枚举类型 保持与PD_BANK的bank号相同

/** Type-C PD 调试信息**/
#define CC_ERRNO_CC_							(0x10)
#define CC_ERRNO_CC_MAGIC						(0x11)
#define CC_ERRNO_CC_HALTED						(0x12)
#define PD_ERRNO_PD_							(0x80)
#define PD_ERRNO_PD_MAGIC						(0x81)
#define PD_ERRNO_TXST_TIMEOUT					(0x82)
#define PD_ERRNO_BUSY_TIMEOUT					(0x83)
#define PD_ERRNO_IDLE_TIMEOUT					(0x84)

/**
  * @brief 配置
  */
#define PD_NUMBER_OF_DATA_OBJECT				(7)
/**
  * @brief 配置
  */
#define PD_RCV_EXTD								(1)

/** PD通信信号配置**/
/**
 *	PD通信时BMC方波边沿控制
 *		作Source时,	默认为 CTRL_SLOW_3
 *		作Sink时,	默认为 CTRL_SLOW_1
 */
typedef enum
{
	CTRL_SLOW_0= (uint8_t)0x00,
	CTRL_SLOW_1,
	CTRL_SLOW_2,
	CTRL_SLOW_3,
	CTRL_SLOW_4,
	CTRL_SLOW_5,
	CTRL_SLOW_6,
	CTRL_SLOW_7,
}pd_ctrl_slow_t;

/**
 *	PD通信时信号接收阈值
 *		作Source时,	默认为 CTRL_RXVSEL_0V68
 *		作Sink时,	默认为 CTRL_RXVSEL_0V44
 */
typedef enum
{
	CTRL_RXVSEL_0V32= (uint8_t)0x00,
	CTRL_RXVSEL_0V44,
	CTRL_RXVSEL_0V68,
	CTRL_RXVSEL_0V80,
	CTRL_RXVSEL_0V56,
}pd_ctrl_rxvsel_t;

/**
 *	PD通信时信号高电平阈值
 *		作Source时,	默认为 CTRL_VSEL_1V00
 *		作Sink时,	默认为 CTRL_VSEL_1V00
 */
typedef enum
{
	CTRL_VSEL_1V00= (uint8_t)0x00,
	CTRL_VSEL_1V05,
	CTRL_VSEL_1V10,
	CTRL_VSEL_1V15,
	CTRL_VSEL_1V20,
	CTRL_VSEL_1V25,
	CTRL_VSEL_1V30,
	CTRL_VSEL_1V35,
}pd_ctrl_vsel_t;

/**
 * @brief  PD电源角色.
 */
typedef enum
{
	PD_PR_SINK,			/*!< sink角色（受电端）*/
	PD_PR_SOURCE,		/*!< source角色（供电端）*/
}pd_power_role_t;

/**
 * @brief  PD数据角色.
 */
typedef enum
{
	PD_DR_UFP,			/*!< 数据下行端口（Host）*/
	PD_DR_DFP,			/*!< 数据上行端口（Device）*/
}pd_data_role_t;

/**
 * @brief  pd spec rev.
 */
typedef enum
{
	PD_SPEC_REV_10,		/*!< rev 1.0*/
	PD_SPEC_REV_20,		/*!< rev 2.0*/
	PD_SPEC_REV_30,		/*!< rev 3.0*/
}pd_spec_rev_t;


/**
 * @brief  pd_sop_type_t.
 */
typedef enum
{
	PD_SOP0 = 0x01,		/*!< 消息类型*/
	PD_SOP1,			/*!< 消息类型*/
	PD_SOP2,			/*!< 消息类型*/
	PD_HARD_RESET,		/*!< 消息类型*/
	PD_CABLE_RESET,     /*!< 消息类型*/
	PD_SOP1_DEBUG,      /*!< 消息类型*/
	PD_SOP2_DEBUG,      /*!< 消息类型*/
}pd_sop_type_t;

/**
 * @brief  控制消息，用户无需关注。
 */
typedef enum
{
	/*!< 消息类型-控制消息，用户无需关注*/
 	PD_MSG_CTRL_RES0					= 0x00,
 	PD_MSG_GOODCRC						= 0x01,
 	PD_MSG_GOTOMIN						= 0x02,
 	PD_MSG_ACCEPT						= 0x03,
 	PD_MSG_REJECT						= 0x04,
 	PD_MSG_PING							= 0x05,
 	PD_MSG_PS_RDY						= 0x06,
 	PD_MSG_GET_SOURCE_CAP				= 0x07,
 	PD_MSG_GET_SINK_CAP					= 0x08,
 	PD_MSG_DR_SWAP						= 0x09,
 	PD_MSG_PR_SWAP						= 0x0A,
 	PD_MSG_VCONN_SWAP					= 0x0B,
 	PD_MSG_WAIT							= 0x0C,
 	PD_MSG_SOFT_RESET					= 0x0D,
 	PD_MSG_DATA_RESET					= 0x0E,
 	PD_MSG_DATA_RESET_COMPLETE			= 0x0F,
 	PD_MSG_NOT_SUPPORTED				= 0x10,
 	PD_MSG_GET_SOURCE_CAP_EXTENDED		= 0x11,
 	PD_MSG_GET_STATUS					= 0x12,
 	PD_MSG_FR_SWAP						= 0x13,
 	PD_MSG_GET_PPS_STATUS				= 0x14,
 	PD_MSG_GET_COUNTRY_CODES			= 0x15,
 	PD_MSG_GET_SINK_CAP_EXTENDED		= 0x16,
 	PD_MSG_CTRL_RES17					= 0x17,
 	PD_MSG_CTRL_RES18					= 0x18,
	PD_MSG_CTRL_RES19					= 0x19,
	PD_MSG_CTRL_RES1A					= 0x1A,
	PD_MSG_CTRL_RES1B					= 0x1B,
	PD_MSG_CTRL_RES1C					= 0x1C,
	PD_MSG_CTRL_RES1D					= 0x1D,
	PD_MSG_CTRL_RES1E					= 0x1E,
	PD_MSG_CTRL_RES1F					= 0x1F,
}pd_ctrl_message_t;

/**
 * @brief  数据消息，用户无需关注。.
 */
typedef enum
{
	/*!< 消息类型-数据消息，用户无需关注*/
	PD_MSG_DATA_RES0					= 0x00,
	PD_MSG_SOURCE_CAPABILITIES			= 0x01,
	PD_MSG_REQUEST						= 0x02,
	PD_MSG_BIST							= 0x03,
	PD_MSG_SINK_CAPABILITIES			= 0x04,
	PD_MSG_BATTERY_STATUS				= 0x05,
	PD_MSG_ALERT						= 0x06,
	PD_MSG_GET_COUNTRY_INFO				= 0x07,
	PD_MSG_ENTER_USB					= 0x08,
	PD_MSG_DATA_RES9					= 0x09,
	PD_MSG_DATA_RESA					= 0x0A,
	PD_MSG_DATA_RESB					= 0x0B,
	PD_MSG_DATA_RESC					= 0x0C,
	PD_MSG_DATA_RESD					= 0x0D,
	PD_MSG_DATA_RESE					= 0x0E,
	PD_MSG_VENDOR_DEFINED				= 0x0F,
	PD_MSG_DATA_RES10					= 0x10,
	PD_MSG_DATA_RES11					= 0x11,
	PD_MSG_DATA_RES12					= 0x12,
	PD_MSG_DATA_RES13					= 0x13,
	PD_MSG_DATA_RES14					= 0x14,
	PD_MSG_DATA_RES15					= 0x15,
	PD_MSG_DATA_RES16					= 0x16,
	PD_MSG_DATA_RES17					= 0x17,
	PD_MSG_DATA_RES18					= 0x18,
	PD_MSG_DATA_RES19					= 0x19,
	PD_MSG_DATA_RES1A					= 0x1A,
	PD_MSG_DATA_RES1B					= 0x1B,
	PD_MSG_DATA_RES1C					= 0x1C,
	PD_MSG_DATA_RES1D					= 0x1D,
	PD_MSG_DATA_RES1E					= 0x1E,
	PD_MSG_DATA_RES1F					= 0x1F,
}pd_data_message_t;

/**
 * @brief  扩展消息，用户无需关注。.
 */
typedef enum
{
	/*!< 消息类型-扩展消息，用户无需关注*/
	PD_MSG_EXT_RES00					= 0x00,
	PD_MSG_SOURCE_CAPABILITIES_EXTENDED	= 0x01,
	PD_MSG_STATUS						= 0x02,
	PD_MSG_GET_BATTERY_CAP				= 0x03,
	PD_MSG_GET_BATTERY_STATUS			= 0x04,
	PD_MSG_BATTERY_CAPABILITIES			= 0x05,
	PD_MSG_GET_MANUFACTURER_INFO		= 0x06,
	PD_MSG_MANUFACTURER_INFO			= 0x07,
	PD_MSG_SECURITY_REQUEST				= 0x08,
	PD_MSG_SECURITY_RESPONSE			= 0x09,
	PD_MSG_FIRMWARE_UPDATE_REQUEST		= 0x0A,
	PD_MSG_FIRMWARE_UPDATE_RESPONSE		= 0x0B,
	PD_MSG_PPS_STATUS					= 0x0C,
	PD_MSG_COUNTRY_INFO					= 0x0D,
	PD_MSG_COUNTRY_CODES				= 0x0E,
	PD_MSG_SINK_CAPABILITIES_EXTENDED	= 0x0F,
	PD_MSG_EXT_RES10					= 0x10,
	PD_MSG_EXT_RES11					= 0x11,
	PD_MSG_EXT_RES12					= 0x12,
	PD_MSG_EXT_RES13					= 0x13,
	PD_MSG_EXT_RES14					= 0x14,
	PD_MSG_EXT_RES15					= 0x15,
	PD_MSG_EXT_RES16					= 0x16,
	PD_MSG_EXT_RES17					= 0x17,
	PD_MSG_EXT_RES18					= 0x18,
	PD_MSG_EXT_RES19					= 0x19,
	PD_MSG_EXT_RES1A					= 0x1A,
	PD_MSG_EXT_RES1B					= 0x1B,
	PD_MSG_EXT_RES1C					= 0x1C,
	PD_MSG_EXT_RES1D					= 0x1D,
	PD_MSG_EXT_RES1E					= 0x1E,
	PD_MSG_EXT_RES1F					= 0x1F,
}pd_extent_message_t;

/**@}*/ /*** end of group csu39fx10_pd_data_define */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup fwlib_pd_api	api
 * @{
 */
/**
 * @name fwlib_pd_api
 * @{
 */
/**
 * @brief 	<b>Description:</b> fwlib_pd库函数.
 * @attention <b> 协议库函数调用，用户无需关注。</b>
 * 
 */
void fwlib_pd_electric_set(pd_ctrl_slow_t slow, pd_ctrl_rxvsel_t rxvsel, pd_ctrl_vsel_t vsel);
void fwlib_pd_txd_spec_rev_set(uint8_t rev);
void fwlib_pd_send_message(PD_BANK uint8_t * arr,uint8_t sop_type,uint8_t pd_message,uint8_t words);
void fwlib_pd_send_chunk_message(PD_BANK uint8_t * arr,uint8_t sop_type,uint8_t pd_message,uint8_t words);
void fwlib_pd_read_pddata(PD_BANK uint8_t * arr);
bool fwlib_pd_get_tmoutif(void);
void fwlib_pd_clear_tmoutif(void);
bool fwlib_pd_get_rxif(void);
void fwlib_pd_clear_rxif(void);
bool fwlib_pd_get_txif(void);
void fwlib_pd_clear_txif(void);

extern void tcpd_debug_cb(uint8_t errno);


/**@}*/ /*** end of name fwlib_pd_api */
/**@}*/ /*** end of group fwlib_pd_api */

/**@}*/ /*** end of group csu39fx10_sdk_chip_fwlib_pd */
/**@}*/ /*** end of group csu39fx10_sdk_chip_fwlib */
/**@}*/ /*** end of group csu39fx10_sdk_chip */
/*******************************************************************************/


#ifdef __cplusplus
}
#endif

#endif  //__CSU39FX10_PD_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/



