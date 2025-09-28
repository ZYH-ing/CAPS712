/***************************************************************************//**
 * @file	 lib_prot_pd.h
 * @version	 V1.0.0
 * @author	 0431
 * @date	 2021-02-04 AM
 * @brief	 该文件包含了PD模块函数库
 *
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 ****************************************************************************
 * @attention
 *	硬件平台:  \n
 *	SDK版本： .0.0
 *
 * @par 修改日志:
 * <table>
 * <tr><th>Date		   <th>Version	<th>Author	  <th>Description
 * <tr><td>2021/02/04  <td>1.0		<td>0431	  <td>创建初始版本
 * </table>
 *
 *****************************************************************************/

#ifndef __LIB_PROT_PD_H__
#define __LIB_PROT_PD_H__

// Include external header file.
#include "csu39fx10_pd.h"
#include "lib_prot_typec.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup csu39fx10_sdk_protocolib csu39fx10_sdk_protocolib
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_protocolib_pd	pd
 * @{
 */

/**
 * @addtogroup pd_data_define	data_define
 * @{
 */
/**
 * @brief  大步骤.
 */
typedef enum
{
	PD_PSTEP_FREE							= (uint8_t)0x00,	/*!< PD协议处理状态机, 无需关注*/
	PD_PSTEP_SEND_SOURCE_CAP_TRIM_3A		= (uint8_t)0x01,	/*!< PD协议处理状态机, 无需关注*/
	PD_PSTEP_SEND_DISCOVER_IDENTITY			= (uint8_t)0x02,	/*!< PD协议处理状态机, 无需关注*/
	PD_PSTEP_SEND_SOURCE_CAP				= (uint8_t)0x03,	/*!< PD协议处理状态机, 无需关注*/
	PD_PSTEP_SEND_DR_SWAP					= (uint8_t)0x04,	/*!< PD协议处理状态机, 无需关注*/
	PD_PSTEP_SEND_PR_SWAP					= (uint8_t)0x05,	/*!< PD协议处理状态机, 无需关注*/
	PD_PSTEP_SEND_SOFT_RESET				= (uint8_t)0x06,	/*!< PD协议处理状态机, 无需关注*/
	PD_PSTEP_SEND_SINK_CAP					= (uint8_t)0x07,	/*!< PD协议处理状态机, 无需关注*/
	PD_PSTEP_SEND_GOODCRC					= (uint8_t)0x08,	/*!< PD协议处理状态机, 无需关注*/
	PD_PSTEP_SEND_NOT_SUPPORTED				= (uint8_t)0x09,	/*!< PD协议处理状态机, 无需关注*/
	PD_PSTEP_SEND_GET_SOURCE_CAP			= (uint8_t)0x0A,	/*!< PD协议处理状态机, 无需关注*/

	PD_PSTEP_READ_SOURCE_CAP				= (uint8_t)0x10,	/*!< PD协议处理状态机, 无需关注*/
	PD_PSTEP_READ_PR_SWAP					= (uint8_t)0x11,	/*!< PD协议处理状态机, 无需关注*/
	PD_PSTEP_READ_DR_SWAP					= (uint8_t)0x12,	/*!< PD协议处理状态机, 无需关注*/
	PD_PSTEP_READ_SOFT_RESET				= (uint8_t)0x13,	/*!< PD协议处理状态机, 无需关注*/
	PD_PSTEP_READ_VCONN_SWAP				= (uint8_t)0x14,	/*!< PD协议处理状态机, 无需关注*/

	PD_PSTEP_QC40_PPS						= (uint8_t)0x15,	/*!< PD协议处理状态机, 无需关注*/
	PD_PSTEP_PD30_PPS						= (uint8_t)0x16,	/*!< PD协议处理状态机, 无需关注*/
}pd_pstep_t;


/**
 * @brief  小步骤.
 */
typedef enum
{
	PD_SSTEP_FREE							= (uint8_t)0x00,	/*!< PD协议处理状态机, 无需关注*/

	PD_SSTEP_GOTOMIN						= (uint8_t)0x01,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_ACCEPT							= (uint8_t)0x02,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_REJECT							= (uint8_t)0x03,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_PING							= (uint8_t)0x04,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_PS_RDY							= (uint8_t)0x05,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_GET_SOURCE_CAP					= (uint8_t)0x06,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_GET_SINK_CAP					= (uint8_t)0x07,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_DR_SWAP						= (uint8_t)0x08,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_PR_SWAP						= (uint8_t)0x09,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_VCONN_SWAP						= (uint8_t)0x0A,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_WAIT							= (uint8_t)0x0B,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_SOFT_RESET						= (uint8_t)0x0C,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_DATA_RESET						= (uint8_t)0x0D,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_DATA_RESET_COMPLETE			= (uint8_t)0x0E,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_NOT_SUPPORTED					= (uint8_t)0x0F,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_GET_SOURCE_CAP_EXTENDED		= (uint8_t)0x10,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_GET_STATUS						= (uint8_t)0x11,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_FR_SWAP						= (uint8_t)0x12,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_GET_PPS_STATUS					= (uint8_t)0x13,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_GET_COUNTRY_CODES				= (uint8_t)0x14,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_GET_SINK_CAP_EXTENDED			= (uint8_t)0x15,	/*!< PD协议处理状态机, 无需关注*/

	PD_SSTEP_SOURCE_CAPABILITIES			= (uint8_t)0x20,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_REQUEST						= (uint8_t)0x21,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_BIST							= (uint8_t)0x22,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_SINK_CAPABILITIES				= (uint8_t)0x23,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_BATTERY_STATUS					= (uint8_t)0x24,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_ALERT							= (uint8_t)0x25,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_GET_COUNTRY_INFO				= (uint8_t)0x26,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_ENTER_USB						= (uint8_t)0x27,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_VENDOR_DEFINED					= (uint8_t)0x28,	/*!< PD协议处理状态机, 无需关注*/

	PD_SSTEP_SOURCE_CAPABILITIES_EXTENDED	= (uint8_t)0x30,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_STATUS							= (uint8_t)0x31,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_GET_BATTERY_CAP				= (uint8_t)0x32,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_GET_BATTERY_STATUS				= (uint8_t)0x33,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_BATTERY_CAPABILITIES			= (uint8_t)0x34,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_GET_MANUFACTURER_INFO			= (uint8_t)0x35,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_MANUFACTURER_INFO				= (uint8_t)0x36,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_SECURITY_REQUEST				= (uint8_t)0x37,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_SECURITY_RESPONSE				= (uint8_t)0x38,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_FIRMWARE_UPDATE_REQUEST		= (uint8_t)0x39,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_FIRMWARE_UPDATE_RESPONSE		= (uint8_t)0x3A,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_PPS_STATUS						= (uint8_t)0x3B,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_COUNTRY_INFO					= (uint8_t)0x3C,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_COUNTRY_CODES					= (uint8_t)0x3D,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_SINK_CAPABILITIES_EXTENDED		= (uint8_t)0x3E,	/*!< PD协议处理状态机, 无需关注*/

	PD_SSTEP_DISCOVER_IDENTITY				= (uint8_t)0x40,	/*!< PD协议处理状态机, 无需关注*/
	PD_SSTEP_QC40_VDM						= (uint8_t)0x41,	/*!< PD协议处理状态机, 无需关注*/
}pd_sstep_t;


/**
 * @brief 输入参数
 */
typedef struct
{
	/*! MessageID判断配置---{1:判断MessageID		0:不判断MessageID}		*/
	volatile uint8_t b_judge_message_id;

	/*! 固定档位5V判断配置---{1:判断固定档5V		0:不判断固定档5V}		*/
	volatile uint8_t b_judge_fixed_5v;

	/*! 电源角色交换配置----{1:接受电源角色交换		0:不接受电源角色交换}	*/
	volatile uint8_t b_accept_pr_swap;

	/*! 数据角色交换配置----{1:接受数据角色交换		0:不接受数据角色交换}	*/
	volatile uint8_t b_accept_dr_swap;

	/*! 电源角色交换配置----{1:主动电源角色交换		0:不主动电源角色交换}	*/
	volatile uint8_t b_active_send_pr_swap;

	/*! 数据角色交换配置----{1:主动数据角色交换		0:不主动数据角色交换}	*/
	volatile uint8_t b_active_send_dr_swap;

	/*! PDO的数量配置*/
	volatile uint8_t local_source_cap_count;

	/*! PPS的PDO位置配置*/
	volatile uint8_t local_pps_pdo_place;

	/*! PDO的数据配置*/
	volatile uint8_t local_source_cap[PD_NUMBER_OF_DATA_OBJECT* 4];

	/*! RDO的数量配置*/
	volatile uint8_t local_sink_cap_count;

	/*! RDO的数据配置*/
	volatile uint8_t local_sink_cap[PD_NUMBER_OF_DATA_OBJECT* 4];

	/*! 最佳RDO数据配置*/
	volatile uint8_t local_best_sink_cap[4];

	/*! EPDO的数据配置*/
	volatile uint8_t local_source_cap_extended[24];

	/*! 状态信息的数据配置*/
	volatile uint8_t local_status_message[5];

	/*! 电池能力信息的数据配置*/
	volatile uint8_t local_battery_cap_message[9];
	
	/*! 作为source 时, PD通信方波边沿控制---{0~ 7, 0-> 信号方波边沿变陡, 4-> 边沿正常(> 300nS, 7-> 边沿变缓}	*/
	volatile pd_ctrl_slow_t		src_pd_slow;

	/*! 作为source 时, PD通信接收阈值-------{0~ 4, 0-> 0.32V, 1-> 0.44V, 2-> 0.68V, 3-> 0.80V, 4-> 0.56V}		*/
	volatile pd_ctrl_rxvsel_t	src_pd_rxvsel;
	
	/*! 作为source 时, PD通信高电平电压-----{0~ 7, 0-> 1.0V, 1-> 1.05V, 7-> 1.35V}								*/
	volatile pd_ctrl_vsel_t		src_pd_vsel;
	
	/*! 作为sink 时, PD通信方波边沿控制-----{0~ 7, 0-> 信号方波边沿变陡, 4-> 边沿正常(> 300nS, 7-> 边沿变缓}	*/
	volatile pd_ctrl_slow_t		snk_pd_slow;

	/*! 作为sink 时, PD通信接收阈值---------{0~ 4, 0-> 0.32V, 1-> 0.44V, 2-> 0.68V, 3-> 0.80V, 4-> 0.56V}		*/
	volatile pd_ctrl_rxvsel_t	snk_pd_rxvsel;
	
	/*! 作为sink 时, PD通信高电平电压-------{0~ 7, 0-> 1.0V, 1-> 1.05V, 7-> 1.35V}								*/
	volatile pd_ctrl_vsel_t		snk_pd_vsel;

}pd_param_input_t;


/**
 * @brief 输出参数
 */
typedef struct
{
	/*! Emaker 线材信息-----{1:线材支持5A电流		0:线材不支持5A电流}			*/
	volatile uint8_t b_emarker_5a;

	/*! PPS 状态信息--------{1:PPS状态				0:不是PPS状态}				*/
	volatile uint8_t b_pps_apdo;

	/*! Sink硬件复位信息----{1:Sink硬件复位			0:不是Sink硬件复位}			*/
	volatile uint8_t b_sink_read_hard;

	/*! Source硬件复位信息--{1:Source硬件复位		0:不是Source硬件复位}		*/
	volatile uint8_t b_source_read_hard;

	/*! 电源角色交换--------{1:电源角色交换			0:不是电源角色交换}			*/
	volatile uint8_t b_pr_swap_en;

	/*! Source电源角色交换--{1:Source电源角色交换	0:不是Source电源角色交换}	*/
	volatile uint8_t b_source_read_pr_swap;

	/*! Sink电源角色交换----{1:Sink电源角色交换		0:不是Sink电源角色交换}		*/
	volatile uint8_t b_sink_read_pr_swap;

	/*! 有PD的情况下,收到PS.RDY置1,用户打开MOS后清零(无PD通信的设备,用户在attached.snk处实现超时打开)	*/
	volatile uint8_t b_sink_read_ps_rdy;

	/*! 有PD的情况下,发送PS.RDY时置位----{source时做有PD标志, enable PD时清零}	*/
	volatile uint8_t b_source_ps_rdy;

	/*! 作为sink 时, 对方的PDO 档位数量*/
	volatile uint8_t source_cap_num;

	/*! 作为sink 时, 对方的PDO信息*/
	volatile uint8_t source_cap_msg[28];

	/*! 作为Sink时, 选择对方的 SRC-PDO 档位*/
	volatile uint8_t source_cap_choose_num;

	/*! 作为Sink时, 对方PDO的电压能力{当前档位, 50mV/单位}		*/
	volatile uint16_t source_cap_vol_capacity;

	/*! 作为Sink时, 对方PDO的电流能力{当前档位, 10mA/单位}		*/
	volatile uint16_t source_cap_cur_capacity;

	/*! 作为Sink时, 请求对方提供的电流能力{当前档位, 10mA/单位}	*/
	volatile uint16_t sink_request_current;

	/*! 作为source 时, 对方选择的PDO档位{根据该档位调压}		*/
	volatile uint8_t request_num;

	/*! 作为source 时, 对方Request_PPS电压{20mV/单位}*/
	volatile uint16_t pps_request_volt;

	/*! 作为source 时, 对方Request_PPS电流{50mA/单位}*/
	volatile uint8_t pps_request_cur;
	
	/*! 缓存rcv_sop, 仅在pd_read()函数执行过后有效 */
	volatile uint8_t rcv_sop;
	
	/*! 接收hardReset计数 */
	volatile uint8_t n_hard_reset;
}pd_param_output_t;


/**
 * @brief 私有参数
 */
typedef struct
{
	/*! 私有参数, 无需关注*/
	volatile typec_instance_t			b_pd_typec_instance;
	volatile typec_cc_pin_t				b_pd_typec_ccpin;
	volatile typec_current_source_t		b_pd_typec_rp;
	volatile bool						b_pd_typec_emark;
	
	volatile uint8_t	b_pd_plicy_reset;
	volatile uint8_t	b_pd_timeout_if;
	volatile uint8_t	b_pd_receive_if;
	volatile uint8_t	b_pd_trans_if;
	volatile uint8_t	b_first_enter_bist;					/*!< 每一项第一次进BIST */

//	volatile uint8_t	b_wait_retry_send_en;
	volatile uint8_t	b_hard_reset_en;

	volatile uint8_t	b_spec_rev_30;
	volatile uint8_t	b_spec_rev_done;
	volatile uint8_t	b_emarker_spec_rev_20_done;
	volatile uint8_t	b_emarker_spec_rev_done;

	volatile uint8_t	b_read_pr_swap_en;
	volatile uint8_t	b_sink_read_pr_swap_nb;
	volatile uint8_t	b_vconn_source;
	volatile uint8_t	b_pdo_has_great_3a;

	volatile uint8_t	primary_step;
	volatile uint8_t	pd_step_device_policy_copy;
	volatile uint8_t	secondary_step;

	volatile uint16_t	t_pd_send_delay;					/*!< 发送延时timer */
	volatile uint8_t	t_pd_send_wait_retry;
	volatile uint16_t	t_sender_response;
	volatile uint8_t	t_src_transition;

	volatile uint16_t	t_hard_reset;
	volatile uint8_t	t_pr_swap;
	volatile uint16_t	t_pps_time_out;

	volatile uint8_t	remote_request_num;
	volatile uint8_t	n_retry_count;
	volatile uint8_t	n_caps_count;						/*!< nCapsCount(50) */
	volatile uint8_t	n_discover_identity_count;			/*!< nDiscoverIdentityCount(20) */

	volatile uint8_t	pd_send_buffer[PD_NUMBER_OF_DATA_OBJECT* 4];
	volatile uint8_t	pd_receive_buffer[PD_NUMBER_OF_DATA_OBJECT* 4];
}pd_param_private_t;


/**
 * @brief  pd结构体
 */
typedef struct
{
	/*! 输入参数*/
	pd_param_input_t	input;

	/*! 输出参数*/
	pd_param_output_t	output;

	/*! 私有参数*/
	pd_param_private_t	private;
}pd_handle_t;
/**@}*/ /*** end of group pd_data_define */
/*******************************************************************************/




/******************************** dividing line ********************************/
/**
 * @addtogroup typec_api	api
 * @{
 */
/**
 * @name typec_api
 * @{
 */
/**
 * @brief	<b>Description:</b> pd模块初始化.
 * @details <b>Function prototype:</b> void pd_init(void);;
 * @param[in]  null.
 * @param[out] null.
 *
 * @return	null
 * @par Example
 * @code
 *		void peripheral_pd_init(void)
 *		{
 *			h_pd.input.b_judge_message_id = SET;
 *			h_pd.input.b_accept_dr_swap = SET;
 *			h_pd.input.b_accept_pr_swap = SET;
 *			h_pd.input.b_active_send_dr_swap = RESET;
 *			h_pd.input.b_active_send_pr_swap = RESET;
 *
 *			h_pd.input.local_source_cap_count = PDO_SOURCECAP_COUNT;
 *			h_pd.input.local_pps_pdo_place = PDO_SOURCECAP_PPS_POS;
 *
 *			h_pd.input.local_sink_cap_count = PDO_SINKCAP_COUNT;
 *
 *			M_MEMCPY(PD_BANK_NUM, &h_pd.input.local_source_cap[0], BANK0, &pdo_sourcecap[0], sizeof(pdo_sourcecap));
 *			M_MEMCPY(PD_BANK_NUM, &h_pd.input.local_sink_cap[0], BANK0, &pdo_sinkcap[0], sizeof(pdo_sinkcap));
 *			M_MEMCPY(PD_BANK_NUM, &h_pd.input.local_best_sink_cap[0], BANK0, &pdo_sinkcap[1], sizeof(pdo_sinkcap[1]));
 *
 *			pd_init();
 *		}
 * @endcode
 */
void pd_init(void);


/**
 * @brief	<b>Description:</b> pd_time_out_handler.
 * @details <b>Function prototype:</b> void pd_time_out_handler(void);;
 * @param[in]  null.
 * @param[out] null.
 * @attention <b> called in PD timeout interrupt</b>
 *
 * @return	null
 * @par Example
 * @code
 *		void test(void)
 *		{
 *			while(1)
 *			{
 *				if(h_pd.private.b_pd_timeout_if)
 *				{
 *					h_pd.private.b_pd_timeout_if= false;
 *					pd_time_out_handler();
 *				}
 *			}
 *		}
 * @endcode
 */
void pd_time_out_handler(void);


/**
 * @brief	<b>Description:</b> pd_trans_complete_handler.
 * @details <b>Function prototype:</b> void pd_trans_complete_handler(typec_instance_t instance);
 * @param[in]  typec_instance_t instance		typec端口号.
 * @param[out] null.
 * @attention <b> called in PD transmit interrupt</b>
 *
 * @return	null
 * @par Example
 * @code
 *		void test(void)
 *		{
 *			while(1)
 *			{
 *				if(h_pd.private.b_pd_trans_if)
 *				{
 *					h_pd.private.b_pd_trans_if= false;
 *					pd_trans_complete_handler(TYPECA);
 *				}
 *			}
 *		}
 * @endcode
 */
void pd_trans_complete_handler(void);


/**
 * @brief	<b>Description:</b> pd_read.
 * @details <b>Function prototype:</b> void pd_read(typec_instance_t instance,typec_current_source_t current_source);
 * @param[in]  typec_instance_t instance		typec端口号.
 * @param[in]  typec_current_source_t current_source	上拉电流源配置.
 * @param[out] null.
 * @attention <b> called in PD receive interrupt</b>
 *
 * @return	null
 * @par Example
 * @code
 *		void test(void)
 *		{
 *			while(1)
 *			{
 *				if(h_pd.private.b_pd_receive_if)
 *				{
 *					h_pd.private.b_pd_receive_if= false;
 *					pd_read(TYPECA, h_typeca.input.current_source);
 *				}
 *			}
 *		}
 * @endcode
 */
void pd_read(void);


/**
 * @brief	<b>Description:</b> pd_send.
 * @details <b>Function prototype:</b> void pd_send(typec_instance_t instance);
 * @param[in]  typec_instance_t instance		typec端口号.
 * @param[out] null.
 * @attention <b> called every 1 millisecond</b>
 *
 * @return	null
 * @par Example
 * @code
 *		void test(void)
 *		{
 *			while(1)
 *			{
 *				if(sys_flag.timer_1ms)
 *				{
 *					pd_send(TYPECA);
 *				}
 *			}
 *		}
 * @endcode
 */
void pd_send(void);


/**
 * @brief	<b>Description:</b> pd_get_limit_condition.
 * @details <b>Function prototype:</b> uint8_t pd_get_limit_condition(void);
 * @param[in]  null.
 * @param[out] uin8_t(bool)		true, false.
 * @attention <b> called every 1 millisecond</b>
 *
 * @return	null
 * @par Example
 * @code
 *		void test(void)
 *		{
 *			while(1)
 *			{
 *				if(sys_flag.timer_1ms)
 *				{
 *					typec_polling(&h_typeca, pd_get_limit_condition());
 *				}
 *			}
 *		}
 * @endcode
 */
uint8_t pd_get_limit_condition(void);


/**
 * @brief	<b>Description:</b> pd_time.
 * @details <b>Function prototype:</b> void pd_time(typec_instance_t instance);
 * @param[in]  typec_instance_t instance		typec端口号.
 * @param[out] null.
 * @attention <b> called every 1 millisecond</b>
 *
 * @return	null
 * @par Example
 * @code
 *		void test(void)
 *		{
 *			while(1)
 *			{
 *				if(sys_flag.timer_1ms)
 *				{
 *					pd_time(TYPECA);
 *				}
 *			}
 *		}
 * @endcode
 */
void pd_time(void);

/**
 * @brief	<b>Description:</b> pd模块使能开关.
 * @details <b>Function prototype:</b> void pd_enable(bool _enable);
 * @param[in]  bool _enable.
 * @param[out] null.
 * @attention <b> called every 1 millisecond</b>
 *
 * @return	null
 * @par Example
 * @code
 *		void test(void)
 *		{
 *			pd_enable(true);
 *			pd_enable(false);
 *		}
 * @endcode
 */
void pd_enable(bool _enable);


/**
 * @brief	<b>Description:</b> AS source 主动发送source cap.
 * @details <b>Function prototype:</b> void pd_send_source_cap(void);
 * @param[in]  null.
 * @param[out] null.
 *
 * @return	null
 * @par Example
 * @code
 *		void test(void)
 *		{
 *			pd_send_source_cap();
 *		}
 * @endcode
 */
void pd_send_source_cap(void);


/**
 * @brief	<b>Description:</b> AS sink 获取对方source cap.
 * @details <b>Function prototype:</b> void pd_get_source_cap(void);
 * @param[in]  null.
 * @param[out] null.
 *
 * @return	null
 * @par Example
 * @code
 *		void test(void)
 *		{
 *			pd_get_source_cap();
 *		}
 * @endcode
 */
void pd_get_source_cap(void);


/**
 * @brief	<b>Description:</b> 重新请求电压档位.
 * @details <b>Function prototype:</b> char pd_send_request(uint8_t request_num);
 * @param[in]  null.
 * @param[out] null.
 *
 * @return	null
 * @par Example
 * @code
 *		void test(void)
 *		{
 *			pd_send_request(1);
 *		}
 * @endcode
 */
char pd_send_request(uint8_t request_num);


/**
 * @brief	<b>Description:</b> 获取lib库版本号.
 * @details <b>Function prototype:</b> uint16_t pd_lib_version_number(void);
 * @param[in]  null.
 * @param[out] null.
 *
 * @return	null
 * @par Example
 * @code
 *		void test(void)
 *		{
 *			uint16_t pd_version;
 *			pd_version= pd_lib_version_number();
 *		}
 * @endcode
 */
uint16_t pd_lib_version_number(void);


/**@}*/ /*** end of name typec_api */
/**@}*/ /*** end of group typec_api */
/*******************************************************************************/




/******************************** dividing line ********************************/
/**
 * @addtogroup typec_global_variable	global_variable
 * @{
 */
/**
 * @name global_variable
 * @{
 */
extern PD_BANK pd_handle_t	h_pd;
/**@}*/ /*** end of name global_variable */
/**@}*/ /*** end of name typec_global_variable */




/**@}*/ /*** end of group csu39fx10_sdk_protocolib_pd */
/**@}*/ /*** end of group csu39fx10_sdk_protocolib */
/*******************************************************************************/


#ifdef __cplusplus
}
#endif

#endif	//__LIB_PROT_PD_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/



