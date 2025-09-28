/***************************************************************************//**
 * @file     lib_prot_typec.h
 * @version  V1.0.0
 * @author   0431
 * @date     2021-02-03 PM
 * @brief    该文件包含了Type-C模块函数库
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
 * <tr><td>2021/02/03  <td>1.0      <td>0431	  <td>创建初始版本
 * </table>
 *
 *****************************************************************************/

#ifndef __LIB_PROT_TYPEC_H__
#define __LIB_PROT_TYPEC_H__

// Include external header file.
#include "csu39fx10_typec.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @addtogroup csu39fx10_sdk_protocolib	csu39fx10_sdk_protocolib
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_protocolib_typec	typec 
 * @{
 */

/**
 * @addtogroup typec_data_define	data_define
 * @{
 */
/**
 * @brief  端口角色类型.
 */
typedef enum
{
	TYPEC_PORT_CONSUMER,			/*!< 只会受电 			*/
	TYPEC_PORT_PROVIDER,			/*!< 只会供电 			*/
	TYPEC_PORT_DRP,					/*!< 随机供受电 		*/
	TYPEC_PORT_DRP_TRY_SRC,			/*!< 尽力供电,备选受电 	*/
}typec_port_type_t;


/**
 * @brief  typec_current_capcity.
 */
typedef enum
{
	TYPEC_CURRENT_CAPCITY_3A0= 3000,	/*!< typec_current_capcity_3a0	*/
	TYPEC_CURRENT_CAPCITY_1A5= 1500,  	/*!< typec_current_capcity_1a5	*/
	TYPEC_CURRENT_CAPCITY_0A9= 900,  	/*!< typec_current_capcity_0a9	*/
}typec_current_capacity_t;


/**
 * @brief 输入参数
 */
typedef struct
{
	/*! 端口号{TYPECA， TYPECB}*/
	volatile typec_instance_t instance;
	
	/*! 华为5A线配置{置1代表支持检测华为5A线,	置0代表不支持检测华为5A线}*/
	volatile status_t b_huawei_support;
	
	/*! vbus退出标志*/
	volatile status_t b_vbus_isexist;
	
	/*! 第一次上电配置{置1代表第一次上电,TYPEC 不会try,		置0代表不是第一次上电} */
	volatile status_t b_power_on;
	
	/*! 电池电压配置{置1代表电池电压低于3.3V,	置0代表电池电压高于3.5V}*/
	volatile status_t b_low_battery;
	
	/*! 上拉电流源配置*/
	volatile typec_current_source_t current_source;
	
	/*! 端口角色配置*/
	volatile typec_port_type_t port_type;
	
	/*! attachwait.snk时间配置*/
	volatile uint8_t b_tim_attachwaitsnk_en;
	volatile uint16_t tim_attachwaitsnk_x1ms;
	
	/*! DRP_TRY时间配置*/
	volatile uint16_t tim_drp_try;
}typec_param_input_t;


/**
 * @brief 输出参数
 */
typedef struct
{
	/*! 线是否有 EMAKER 芯片{1->代表有,	0->代表没有}*/
	volatile status_t b_emarker_isexist;

	/*! TYPEC 接口的连接状态*/
	volatile typec_state_t state;

	/*! 作为 SINK 时 对方适配器的电流能力*/
	// volatile typec_current_capacity_t current_capacity;
	volatile uint16_t current_capacity;

	/*! PD选择的通信脚*/
	volatile typec_cc_pin_t cc_pin_sel;
}typec_param_output_t;


/**
 * @brief 私有参数
 */
typedef struct
{
	volatile uint16_t t_breaker;
	volatile uint8_t auto_status;
	volatile uint8_t auto_status_copy;
	volatile uint16_t t_isexist;
	volatile uint16_t t_isnotexist;
	volatile uint16_t t_cc_magic;
	volatile typec_state_t state_copy;
	volatile uint8_t t_try_src_times;
	volatile uint16_t t_typec_halted;
	volatile uint8_t cnt_typec_halted;
	volatile uint8_t callback_switch_branch;

	volatile uint8_t b_trysrc_insurance_n;
	
	volatile uint8_t b_typec_hard_reset_lock;
}typec_param_private_t;


/**
 * @brief  typec结构体
 */
typedef struct
{
	/*! 输入参数*/
	typec_param_input_t 	input;

	/*! 输出参数*/
	typec_param_output_t 	output;

	/*! 私有参数*/
	typec_param_private_t 	private;
}typec_handle_t;
/**@}*/ /*** end of group typec_data_define */
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
 * @brief 	<b>Description:</b> typec初始化.
 * @details <b>Function prototype:</b> void typec_init(TC_BANK typec_handle_t * p_h_typec);
 * @param[in]  TC_BANK typec_handle_t * p_h_typec		typec结构体指针.
 * @param[out] null.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *			TC_BANK typec_handle_t	h_typeca;
 *
 *			h_typeca.input.instance= TYPECA;
 *			h_typeca.input.b_huawei_support= true;
 *			h_typeca.input.b_power_on= true;
 *			h_typeca.input.b_vbus_isexist= true;
 *			h_typeca.input.current_source= TYPEC_CCX_CUR_330UA;
 *			h_typeca.input.port_type= TYPEC_PORT_DRP_TRY_SRC;
 *
 *			typec_init(&h_typeca);
 *		}
 * @endcode
 */
void typec_init(TC_BANK typec_handle_t * p_h_typec);


/**
 * @brief 	<b>Description:</b> typec time.
 * @details <b>Function prototype:</b> void typec_time(TC_BANK typec_handle_t * p_h_typec);
 * @param[in]  TC_BANK typec_handle_t * p_h_typec		typec结构体指针.
 * @param[out] null.
 * @attention <b> called every 1 millisecond</b>
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *			while(1)
 * 			{
 *				if(sys_flag.timer_1ms)
 *				{
 *					sys_flag.timer_1ms= false;
 *					typec_time(&h_typeca);
 *				}
 * 			}
 *		}
 * @endcode
 */
void typec_time(TC_BANK typec_handle_t * p_h_typec);


/**
 * @brief 	<b>Description:</b> typec polling.
 * @details <b>Function prototype:</b> void typec_polling(TC_BANK typec_handle_t * p_h_typec,uint8_t b_limit_condition);
 * @param[in]  TC_BANK typec_handle_t * p_h_typec		typec结构体指针.
 * @param[in]  uint8_t b_limit_condition				limit condition标志.
 * @param[out] null.
 * @attention <b> called every 1 millisecond</b>
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *			while(1)
 * 			{
 *				if(sys_flag.timer_1ms)
 *				{
 *					sys_flag.timer_1ms= false;
 *					typec_polling(&h_typeca, pd_get_limit_condition());
 *				}
 * 			}
 *		}
 * @endcode
 */
void typec_polling(TC_BANK typec_handle_t * p_h_typec,uint8_t b_limit_condition);


/**
 * @brief 	<b>Description:</b> typec sleep.
 * @details <b>Function prototype:</b> typec_sleep(typec_instance_t instance);
 * @param[in]  typec_instance_t instance	typec端口号.
 * @param[out] null.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *			typec_sleep(TYPECA);
 *		}
 * @endcode
 */
void typec_sleep(typec_instance_t instance);


/**
 * @brief 	<b>Description:</b> typec break.
 * @details <b>Function prototype:</b> void typec_break(TC_BANK typec_handle_t * p_h_typec);
 * @param[in]  TC_BANK typec_handle_t * p_h_typec		typec结构体指针.
 * @param[out] null.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *			typec_break(&h_typeca);
 *		}
 * @endcode
 */
void typec_break(TC_BANK typec_handle_t * p_h_typec);
uint16_t typec_lib_version_number(void);

/**@}*/ /*** end of name typec_api */
/**@}*/ /*** end of group typec_api */




/******************************** dividing line ********************************/
/** 
 * @addtogroup typec_global_variable	global_variable
 * @{
 */
/**
 * @name global_variable
 * @{
 */
extern TC_BANK typec_handle_t h_typeca;
extern TC_BANK typec_handle_t h_typecb;
/**@}*/ /*** end of name global_variable */
/**@}*/ /*** end of name typec_global_variable */




/******************************** dividing line ********************************/
/** 
 * @addtogroup typec_callback_function	callback_function
 * @{
 */
/**
 * @name callback_function
 * @{
 */
extern void typecx_hard_reset_cb(bank1 typec_handle_t * p_h_typec);
extern void typeca_pr_swap_cb(void);
extern void typecb_pr_swap_cb(void);
extern bool typeca_vbus_exist_cb(void);
extern bool typecb_vbus_exist_cb(void);
extern void typeca_attached_src_cb(void);
extern void typecb_attached_src_cb(void);
extern void typeca_attached_snk_cb(void);
extern void typecb_attached_snk_cb(void);
extern void typeca_unattached_cb(void);
extern void typecb_unattached_cb(void);
//用于打印typec_state等各种参数
extern void typecx_param_cb(bank1 typec_handle_t * p_h_typec);

/**@}*/ /*** end of name callback_function */
/**@}*/ /*** end of name typec_callback_function */

/**@}*/ /*** end of group csu39fx10_sdk_protocolib_typec */
/**@}*/ /*** end of group csu39fx10_sdk_protocolib */
/*******************************************************************************/




#ifdef __cplusplus
}
#endif

#endif  //__LIB_PROT_TYPEC_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/

