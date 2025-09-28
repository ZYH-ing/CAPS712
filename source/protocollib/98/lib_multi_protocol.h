/***************************************************************************//**
 * @file     lib_multi_protocol.h
 * @version  V1.0.0
 * @author   Tanghr	
 * @date     2021-02-04 AM
 * @brief    该文件包含了多协议模块函数库
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
 * <tr><td>2021/02/04  <td>1.0      <td>Tanghr	  <td>创建初始版本
 * </table>
 *
 *****************************************************************************/
#ifndef     _LIB_MULTI_PROTOCOL_H
#define     _LIB_MULTI_PROTOCOL_H

/* Includes ------------------------------------------------------------------*/
#include "cs_common.h"

#define		multi_bank			bank9
#define		MULTI_BANK_NUM		BANK9
#define		scp_bank			bank8
#define		SCP_BANK_NUM		BANK8
#define		CABLE_BANK_NUM		BANK8
#define		cable_bank			bank8

//编译开关，打包库后修改无效
#define		K_QC20_INPUT_Enable		1
#define		K_QC30_INPUT_Enable		1
#define		K_FCP_INPUT_Enable		0
#define		K_AFC_INPUT_Enable		0

#define		K_QC20_OUTPUT_Enable	1
#define		K_QC30_OUTPUT_Enable	1
#define		K_FCP_OUTPUT_Enable		1
#define		K_AFC_OUTPUT_Enable		1
#define		K_SCP_OUTPUT_Enable		1
#define		K_APPLE_OUTPUT_Enable	1
#define		K_VOOC_Enable			0

#define		QC_IN_NUM_5V				1		//1:5V/2A 2:9V/2A 3:12V/1.5A(若适配器不支持12V会切换至9V档)
#define		QC_IN_NUM_9V				2		//1:5V/2A 2:9V/2A 3:12V/1.5A(若适配器不支持12V会切换至9V档)
#define		QC_IN_NUM_12V				3		//1:5V/2A 2:9V/2A 3:12V/1.5A(若适配器不支持12V会切换至9V档)

#define		FCP_IN_NUM_5V				1		//1:5V/2A 2:9V/2A 3:12V/2A(若适配器不支持12V会切换至9V档)
#define		FCP_IN_NUM_9V				2		//1:5V/2A 2:9V/2A 3:12V/2A(若适配器不支持12V会切换至9V档)
#define		FCP_IN_NUM_12V				3		//1:5V/2A 2:9V/2A 3:12V/2A(若适配器不支持12V会切换至9V档)

#define		AFC_IN_NUM_5V				1		//1:5V/2A 2:9V/1.67A 3:12V/1.5A(若适配器不支持12V会切换至9V档)
#define		AFC_IN_NUM_9V				2		//1:5V/2A 2:9V/1.67A 3:12V/1.5A(若适配器不支持12V会切换至9V档)
#define		AFC_IN_NUM_12V				3		//1:5V/2A 2:9V/1.67A 3:12V/1.5A(若适配器不支持12V会切换至9V档)

#define		INPUT_VBUS_UNIT				25			//VBUS输入单位设置：25mV（客户端配置无效）
#define		INPUT_IBUS_UNIT				1			//IBUS输入单位设置:	1mA（客户端配置无效）

#define		QC30_OUTPUT_UNIT			100			//QC3.0输出电压单位设置:100mV（客户端配置无效）

#define		VOOC_IMPEDANCE_COMPENSATE	20			//VOOC阻抗补偿：补偿采样端到端口端实际的阻抗偏差

#define		SCP_VBUS_COMPENSATE			26			//SCP VBUS补偿  26mV = 0.26Ω(线阻) * 100mA
/**
 * @addtogroup cpwxxxx_sdk_protocolib	cpwxxxx_sdk_protocolib
 * @{
 */

/**
 * @addtogroup cpwxxxx_sdk_protocolib_multi_protocol	multi_protocol 
 * @{
 */

/**
 * @addtogroup multi_protocol_data_define	multi_protocol_define
 * @{
 */

/**
 * @brief  协议通道选择.
 */
typedef enum
{
	CHANEL_DMDPA = 0,	/*!< PT31,PT32,放电方向切换协议通道时需应用层断开当前通道VBUS至少200ms*/
	CHANEL_DMDPB,		/*!< PT23,PT24,放电方向切换协议通道时需应用层断开当前通道VBUS至少200ms*/
	CHANEL_DMDPC,		/*!< PT35,PT36,放电方向切换协议通道时需应用层断开当前通道VBUS至少200ms*/
	CHANEL_DMDPD,		/*!< PT33,PT34,放电方向切换协议通道时需应用层断开当前通道VBUS至少200ms*/
	CHANEL_NULL,
}multi_prtocol_channel_t;

/**
 * @brief  协议方向选择，识别到适配器插入后才将协议方向切换为充电，否则为放电.
 */
typedef enum
{
	DIR_CHARGE = 0,		/*!< 充电（输入）方向协议*/
	DIR_DISCHARGE,		/*!< 放电（输出）方向协议*/
}multi_prtocol_dir_t;

/**
 * @brief  选择输出的苹果协议
*/
typedef enum
{
	APPLE_10,
	APPLE_21,
	APPLE_24,
}multi_prtocol_apple_sel_t;

/**
 * @brief 协议控制参数，应用层配置以下寄存器对协议进行控制
 */
typedef struct
{
	/*! 协议扫描使能配置---{1:开启多协议检测	0:关闭多协议检测（D+,D-只作短接功能）}*/
	volatile uint8_t	fastchg_protocol_scan_en;
	
	/*! 端口复用配置---{1:PT31,PT32端口用来做DMDPA功能,使能后不允许更改	0:当普通IO口,外部可配置}*/
	volatile uint8_t	GPIO_multiplex_DMDPA;	
	
	/*! 端口复用配置---{1:PT23,PT24端口用来做DMDPB功能,使能后不允许更改 0:当普通IO口,外部可配置}*/
	volatile uint8_t	GPIO_multiplex_DMDPB;	
	
	/*! 端口复用配置---{1:PT35,PT36端口用来做DMDPC功能,使能后不允许更改 0:当普通IO口,外部可配置}*/	
	volatile uint8_t	GPIO_multiplex_DMDPC;	
	
	/*! 端口复用配置---{1:PT33,PT34端口用来做DMDPD功能,使能后不允许更改 0:当普通IO口,外部可配置}*/
	volatile uint8_t	GPIO_multiplex_DMDPD;	
	
	/*! QC协议输出使能配置---{1:开启QC协议检测 0:关闭QC协议检测}*/
	volatile uint8_t	qc_protocol_out_en;	
	
	/*! QC协议输出12V使能配置(只控制QC2.0)---{1:QC协议最高可输出12V 0:QC协议最高可输出9V}*/
	volatile uint8_t	qc_protocol_out_12v_en;	
	
	/*! QC协议输入使能配置---{1:开启QC协议检测 0:关闭QC协议检测}*/
	volatile uint8_t	qc_protocol_in_en;		
	
	/*! QC输入诱骗适配器电压档位配置---{0/1:5V,2:9V,3:12V（若适配器无12V会自动诱骗9V）}*/
	volatile uint8_t	qc_protocol_in_num;		
	
	/*! QC3.0协议输出使能配置---{1:开启QC3.0协议检测 0:关闭QC3.0协议检测}*/
	volatile uint8_t	qc30_protocol_out_en;	
	
	/*! QC3.0协议最低输出3.6V使能---{1:最低输出3.6V 0:最低输出5V}*/
	volatile uint8_t	qc30_protocol_3v6_en;	
	
	/*! QC3.0协议输入使能配置---{1:开启QC3.0协议检测 0:关闭QC3.0协议检测}*/
	volatile uint8_t	qc30_protocol_in_en;	
	
	/*! QC3.0协议输入使能配置---{QC3.0输入诱骗适配器电压,25mV为单位,范围3.6~12V}*/
	volatile uint16_t	qc30_protocol_in_vol;	
	
	/*! FCP协议输出使能配置---{1:开启FCP协议检测 0:关闭FCP协议检测}*/
	volatile uint8_t	fcp_protocol_out_en;
	
	/*! FCP协议输出12V使能配置---{1:FCP协议最高可输出12V 0:FCP协议最高可输出9V}*/
	volatile uint8_t	fcp_protocol_out_12v_en;
		
	/*! FCP协议输入使能配置---{1:开启FCP协议检测 0:关闭FCP协议检测}*/
	volatile uint8_t	fcp_protocol_in_en;		
	
	/*! FCP输入诱骗适配器电压档位配置---{0/1:5V,2:9V,3:12V（若适配器无12V会自动诱骗9V）}*/
	volatile uint8_t	fcp_protocol_in_num;	
	
	/*! SCP协议输出使能配置---{1:开启SCP协议检测 0:关闭SCP协议检测}*/
	volatile uint8_t	scp_protocol_out_en;	
	
	/*! SCP协议VBUS电压补偿---{用于补偿输出端与实际采样电压误差,单位需与multi_protocol.input.vbus_vol一致，并且<multi_protocol.input.vbus_vol}*/
	volatile uint8_t	scp_vbus_compensate;

	/*! AFC协议输出使能配置---{1:开启AFC协议检测 0:关闭AFC协议检测}*/
	volatile uint8_t	afc_protocol_out_en;	
	
	/*! AFC协议输出12V使能配置---{1:AFC协议最高可输出12V 0:AFC协议最高可输出9V}*/
	volatile uint8_t	afc_protocol_out_12v_en;
	
	/*! AFC协议输入使能配置---{1:开启AFC协议检测 0:关闭AFC协议检测}*/
	volatile uint8_t	afc_protocol_in_en;		
	
	/*! AFC输入诱骗适配器电压档位配置---{0/1:5V,2:9V,3:12V（若适配器无12V会自动诱骗9V）}*/
	volatile uint8_t	afc_protocol_in_num;	
	
	/*! VOOC协议输出使能配置---{1:开启VOOC协议检测 0:关闭VOOC协议检测}*/
	volatile uint8_t	vooc_protocol_out_en;	
	
	/*! VOOC协议输入使能配置---{1:开启VOOC协议检测 0:关闭VOOC协议检测}*/
	volatile uint8_t	vooc_protocol_in_en;	
	
	/*! VOOC4.0协议输出使能配置---{1:开启VOOC4.0协议检测 0:关闭VOOC4.0协议检测}*/
	volatile uint8_t	vooc40_protocol_out_en;	
	
	/*! VOOC4.0协议输入使能配置---{1:开启VOOC4.0协议检测 0:关闭VOOC4.0协议检测}*/
	volatile uint8_t	vooc40_protocol_in_en;	
	
	/*! SuperVOOC协议输出使能配置---{1:开启SuperVOOC协议检测 0:关闭SuperVOOC协议检测}*/
	volatile uint8_t	svooc_protocol_out_en;	
	
	/*! SuperVOOC协议输入使能配置---{1:开启SuperVOOC协议检测 0:关闭SuperVOOC协议检测}*/
	volatile uint8_t	svooc_protocol_in_en;	
	
	/*! A口OPPO线检测使能配置---{1:使能OPPO线检测（需占用timer2和PT1.4引脚） 0:关闭OPPO线检测（用普通线充电可能会引起不兼容问题）}*/
	volatile uint8_t	typea_vooc_cable_det_en;
	
	/*! VOOC协议阻抗补偿---{用于补偿采样端与输出端的阻抗的偏差,单位为mΩ}*/
	volatile uint8_t	vooc_impedance_compensate;

	/*! 苹果协议选择 */
	volatile multi_prtocol_apple_sel_t apple_sel;
}multi_prtocol_control_t;

/**
 * @brief 协议输出参数，以下寄存器由lib与协议握手后输出，应用层拿到标志位进行相应逻辑操作和处理
 */
typedef struct
{
	/*! BC1.2协议识别dcp成功标志,放电时无需关注，充电时该标志置上代表Source端具备5V/1.5A以上输出能力，否则为普通USB口（如电脑USB）*/
	volatile uint8_t	B_dcp_scan_ok;	

	/*! BC1.2协议识别sdp成功标志,放电时无需关注，充电时该标志置上代表普通USB口（如电脑USB）*/
	volatile uint8_t	B_sdp_scan_ok;	

	/*! BC1.2协议识别cdp成功标志,放电时无需关注，充电时该标志置上代表普通USB口（如电脑USB）*/
	volatile uint8_t	B_cdp_scan_ok;	
	
	/*! QC协议识别成功标志,放电时应用层函数需根据request_num调压,充电时应用层将电流拉到目标电流，输入功率应低于<=18w*/
	volatile uint8_t	B_qc20_scan_ok;	
	
	/*! QC3.0协议识别成功标志,放电时应用层函数需根据qc30_out_vol调压,充电时应用层将电流拉到目标电流，输入功率应低于<=18w*/
	volatile uint8_t	B_qc30_scan_ok;	
	
	/*! VOOC协议识别成功标志,放电时应用层函数需根据vooc_out_vol调压,充电时应用层最高可将电流拉到5V/4A*/
	volatile uint8_t	B_vooc_scan_ok;	
	
	/*! VOOC4.0协议识别成功标志,放电时应用层函数需根据vooc_out_vol调压，充电时应用层最高可将电流拉到5V/6A*/
	volatile uint8_t	B_vooc40_scan_ok;
	
	/*! SuperVOOC协议识别成功标志,放电时应用层函数需根据vooc_out_vol调压，充电时应用层最高可将电流拉到10V/6A*/
	volatile uint8_t	B_svooc_scan_ok; 
	
	/*! fcp协议识别成功标志,放电时应用层函数需根据request_num调压，充电时应用层将电流拉到目标电流，通常输入功率应低于<=18w*/
	volatile uint8_t	B_fcp_scan_ok;	
	
	/*! scp协议识别成功标志,放电时应用层函数需根据scp_out_vol调压*/
	volatile uint8_t	B_scp_scan_ok;	
	
	/*! afc协议识别成功标志,放电时应用层函数需根据request_num调压，充电时应用层将电流拉到目标电流，通常输入功率应低于<=15w*/
	volatile uint8_t	B_afc_scan_ok;

	/*! apple2.4协议识别成功标志,放电时无需关注，充电端口符合5V2.4A，充电时应用层将电流拉到2.4A*/
	volatile uint8_t	B_apple_24_ok;

	/*! apple2.0协议识别成功标志,放电时无需关注，充电端口符合5V2.0A，充电时应用层将电流拉到2.0A*/
	volatile uint8_t	B_apple_20_ok;

	/*! apple1.0协议识别成功标志,放电时无需关注，充电端口符合5V1.0A，充电时应用层将电流拉到1.0A*/
	volatile uint8_t	B_apple_10_ok;
	
	/*! vooc协议btb标志,标志置1后需关闭端口vbus*/
	volatile uint8_t	B_vooc_btb_err;	
	
	/*! vooc协议复位标志,标志置1后需关闭端口vbus 100ms后重启,同时将该位清0*/
	volatile uint8_t	B_vooc_reset;	
	
	/*! 多协议调压返回值：0：忽略 1:5V 2:9V 3:12V 8:连续调压档位，判断协议识别标志位，根据qc30_out_vol,vooc_out_vol,scp_out_vol值进行调压*/
	volatile uint8_t	request_num;
	
	/*! QC3.0调压寄存器,100mV为单位*/
	volatile uint8_t	qc30_out_vol;	
	
	/*! QC协议复位,标志置1时需将fastchg_protocol_scan_en清0关闭协议并将端口VBUS关闭100ms以上再重新打开，识别到端口拔出后再将fastchg_protocol_scan_en置1以便下次协议识别*/
	volatile uint8_t	B_qc_scan_reset;	
	
	/*! VOOC调压寄存器,1mV为单位*/
	volatile uint16_t	vooc_out_vol;	
	
	/*! SCP调压寄存器,1mV为单位*/
	volatile uint16_t	scp_out_vol;
	
}multi_prtocol_return_t;

/**
 * @brief 协议输入参数，以下寄存器由应用层配置,LIB调用
 */
typedef struct
{
	/*! 端口VBUS电压,25mV为单位赋值，10ms内更新*/
	volatile uint16_t	vbus_vol;
	
	/*! 端口IBUS电流,1mA为单位赋值，100ms内更新*/
	volatile uint16_t	ibus_cur;	
}multi_prtocol_input_t;

/**
 * @brief  内部参数，无需关注.
 */
typedef enum
{
	DPDM_LEVEL_0V = 0,
	DPDM_LEVEL_0V6,
	DPDM_LEVEL_1V2,
	DPDM_LEVEL_2V0,
	DPDM_LEVEL_2V2,
	DPDM_LEVEL_2V7,
	DPDM_LEVEL_3V3
}DMDP_level_t;

/**
 * @brief  内部参数，无需关注.
 */
typedef struct
{
	volatile uint8_t	discharge_step;
	volatile uint8_t	charge_step;
	volatile uint8_t	cnt_filit_dcp_en;
	volatile uint8_t	detect_0V6_flag;
	volatile uint16_t	cnt_delay_DMDP_open;
	volatile uint16_t	cnt_delay_dcp_reset;
	volatile uint16_t	cnt_filit_0v6_release;
	volatile uint8_t	cnt_filit_DP_0v6_output;
	volatile uint8_t	cnt_filit_DM_0v6_output;
	volatile uint8_t	cnt_filit_fastchg_adapter;
	volatile uint8_t	cnt_filit_dpdm_apple24;
	volatile uint8_t	cnt_filit_dpdm_apple20;
	volatile uint8_t	cnt_filit_dpdm_apple10;
	volatile uint8_t	cnt_filit_dpdm_delay;
	volatile uint8_t	fastchg_adapter_scan_ok;
	volatile uint8_t	DMDP_short;
	volatile uint16_t	wait_dm_down_time;
	volatile uint16_t	wait_apple_stb_time;
	volatile uint8_t	wait_apple_down_time;
	volatile uint8_t	mos_open_flag;//bit0:ca		bit1:cb		bit2:a1
}dcp_prtocol_base_t;

/**
 * @brief  内部参数，无需关注.
 */
typedef struct
{
	volatile uint8_t	discharge_step;
	volatile uint8_t	charge_step;
	volatile uint8_t	qc_request_num;
#if K_QC20_OUTPUT_Enable
	volatile uint8_t	cnt_filit_qc_9v;
	volatile uint8_t	cnt_filit_qc_12v;
	volatile uint8_t	cnt_filit_qc_5v;
#endif
#if K_QC30_OUTPUT_Enable
	volatile uint8_t	cnt_filit_qc30;
	volatile uint8_t	qc30_pulse_rx_ok;
#endif
#if K_QC20_INPUT_Enable
	volatile uint8_t	send_qc5v_serial_ok;
	volatile uint8_t	send_qc9v_serial_ok;
	volatile uint8_t	send_qc12v_serial_ok;
	volatile uint8_t	cnt_try_qc20;
	volatile uint8_t	B_try_qc_9v;
#endif
#if K_QC30_INPUT_Enable
	volatile uint16_t	qc30_in_vol_max;
	volatile uint16_t	qc30_in_vol_min;
	volatile uint8_t	send_qc30_serial_ok;
	volatile uint8_t	cnt_delay_qc30_pulse;
	volatile uint8_t	send_pulse_dec_ok;
	volatile uint8_t	send_pulse_add_ok;
	volatile uint8_t	cnt_qc30_in_scan_fail;
	volatile uint16_t	vbus_vol_bk;
	volatile uint8_t	cnt_qc30_in_scan_ok;
#endif	
}qc_prtocol_base_t;

/**
 * @brief  内部参数，无需关注.
 */
typedef struct
{
	volatile uint8_t	discharge_step;
	volatile uint8_t	charge_step;
	volatile uint8_t	rx_seq_ok;
	volatile uint16_t	cnt_delay_seq_det;
	volatile uint8_t	cnt_delay_tx_start;
	volatile uint8_t	cnt_tx_100ms;
	volatile uint8_t	cnt_tx_30ms;
	volatile uint8_t	cnt_tx_50ms;
	volatile uint8_t	cnt_tx_80ms;
	volatile uint8_t	cnt_fastchg_err;
	volatile uint8_t	protocol_type;
	volatile uint8_t	impedance;
	volatile uint16_t	path_impedance;
	volatile uint16_t	rx_buf;
	volatile uint16_t	rx_head;
	volatile uint16_t	out_cur;
	volatile uint16_t	out_cur_bk;
	volatile uint16_t	out_cur_max;
	volatile uint16_t	out_cur_min;
	volatile uint16_t	bat_vol;
	volatile uint16_t	bat_vol_bk;
	volatile uint16_t	vbus_vol_bk;
	volatile uint16_t 	bat_array[2][8];
	volatile uint8_t 	bat_array_num;
	volatile uint8_t 	bat_array_cnt;
	volatile uint8_t 	cur_limit_en;
	volatile uint8_t 	cnt_filit_cur_limit;
	volatile uint8_t 	cnt_filit_ibus_reset;
	volatile uint8_t	cnt_filit_impedance_ov_lv1;
	volatile uint8_t	cnt_filit_impedance_ov_lv2;
	volatile uint8_t	cnt_filit_impedance_ov_lv3;
	volatile uint8_t	cc_2a;
	volatile uint8_t	cc_3a;
	volatile uint8_t	rx_password_cnt;
	volatile uint16_t	rx_password1;
	volatile uint16_t	rx_password2;
	volatile uint16_t	rx_password;
	volatile uint16_t	rx_password_old;
	volatile uint16_t	tx_password1;
	volatile uint16_t	tx_password2;
	volatile uint16_t	tx_password3;
	volatile uint16_t	tx_password4;
	volatile uint16_t	tx_password;
	volatile uint8_t	tx_password_cnt;
	volatile uint8_t	tx_charger_id_cnt;
	volatile uint8_t	fastchg_retry_cnt;
	volatile uint8_t	vooc_reset;
	volatile uint8_t	cnt_delay_tx_seq;
	volatile uint16_t	cnt_delay_rx_order_ovtime;
	volatile uint8_t	cnt_vooc_seg_retry;
	volatile uint8_t	cnt_tx_ack;
	volatile uint8_t	password_check_en;
	volatile uint8_t	password_check_step;
	volatile uint8_t	charger_check_en;
	volatile uint8_t	charger_check_step;
	volatile uint8_t	cnt_password_ok;
	volatile uint8_t	rx_reset_en;
	volatile uint8_t	cnt_delay_rx_reset;
	volatile uint16_t	cnt_rand;
	volatile uint16_t	cnt_battary_curve;
}vooc_prtocol_base_t;

/**
 * @brief  内部参数，无需关注.
 */
typedef struct
{
	volatile uint8_t	DP_vol_level;
	volatile uint8_t	DM_vol_level;
	volatile uint8_t	APP_DP_vol_level;
	volatile uint8_t	APP_DM_vol_level;
}DMDP_vol_level_t;

/**
 * @brief  内部参数，无需关注.
 */
typedef struct
{
	volatile uint8_t	B_1ms_flag;
	volatile uint8_t	cnt_1ms_base;
	volatile uint8_t	cnt_5ms_base;
	volatile uint8_t	cnt_10ms_base;
	volatile uint8_t	cnt_20ms_base;
}multi_prtocol_time_base_t;

/**
 * @brief  内部参数，无需关注.
 */
typedef struct
{
	volatile uint8_t	dcp_scan_en;
	volatile uint8_t	qc_scan_en;
	volatile uint8_t	scp_scan_en;
	volatile uint8_t	vooc_scan_en;
	volatile uint8_t	discharge_step;
	volatile uint8_t	charge_step;
	volatile uint8_t	reset_scan_en;
	volatile uint8_t	reset_protocol_en;
	volatile uint8_t	B_vooc_try_fail;
	volatile uint8_t	B_qc_try_fail;
	volatile uint8_t	B_try_scp_fail;
	volatile uint8_t	cnt_filit_protocol_reset;
	volatile uint8_t	B_protocol_reset;
	volatile uint8_t	B_protocol_reset_ok;
	volatile uint8_t	cnt_delay_DMDP_0v_output;
}multi_prtocol_inside_t;

/**
 * @brief  内部参数，无需关注.
 */
typedef struct
{
	volatile uint8_t	discharge_step;
	volatile uint8_t	charge_step;
	volatile uint8_t	huawei_request_num;
	volatile uint8_t	rx_master_ping;
	volatile uint8_t	rx_buffer[8];
	volatile uint8_t	tx_buffer[8];
	volatile uint8_t	tx_num;
	volatile uint8_t	rx_num;
	volatile uint8_t	rx_data_busy;
	volatile uint8_t	tx_data_ok;
	volatile uint8_t	tx_data_cnt;
	volatile uint8_t	cnt_delay_tx_ping;
	volatile uint8_t	cnt_tx_ping_retry;
	volatile uint8_t	tx_ping_retry_en;
	volatile uint8_t	recive_01flag;
	
#if K_SCP_OUTPUT_Enable	
	volatile uint8_t	control0_value;
	volatile uint8_t	control1_value;
	volatile uint8_t	status0_value;
	volatile uint8_t	status1_value;
	volatile uint8_t	status2_value;
	volatile uint8_t	vout_value;
	volatile uint8_t	iout_value;
	volatile uint8_t	vouth_value;
	volatile uint8_t	vol_limit_h;
	volatile uint8_t	cur_limit_h;
	volatile uint8_t	cur_limit_l;
	volatile uint8_t	vol_limit_l;
	volatile uint8_t	voutl_value;
	volatile uint8_t	iouth_value;
	volatile uint8_t	ioutl_value;
	volatile uint8_t	output_cur;
#endif
	
#if K_AFC_OUTPUT_Enable
	volatile uint8_t	afc_request_num;
	volatile uint8_t	cnt_filit_afc_5v;
	volatile uint8_t	cnt_filit_afc_9v;
	volatile uint8_t	cnt_filit_afc_12v;
#endif

#if (K_FCP_INPUT_Enable || K_AFC_INPUT_Enable)
	volatile uint8_t	master_tx_step;
	volatile uint8_t	cnt_delay_vbus_check;
	volatile uint8_t	B_9v_retry;
	
#if K_FCP_INPUT_Enable	
	volatile uint8_t	fcp_adapter_type;
	volatile uint8_t	fcp_adapter_vbus;
	volatile uint8_t	fcp_adapter_max_power;
#endif
	
#if K_AFC_INPUT_Enable	
	volatile uint8_t	cnt_afc_tx_time;
#endif
#endif
	
	
}scp_prtocol_base_t;

/**
 * @brief  内部参数，无需关注.
 */
typedef struct
{

}vooc_cable_base_t;

/**
 * @brief  内部参数，无需关注.
 */
typedef struct
{
	/*! 多协议通道选择*/
    multi_prtocol_channel_t		channel;	
    
    /*! 多协议方向选择*/
    multi_prtocol_dir_t			dir;
    
     /*! 多协议各个协议开关控制*/
    multi_prtocol_control_t		control;	
    
    /*! 多协议输出寄存器,外部应用层程序读取调用*/
    multi_prtocol_return_t		output;		
    
    /*! 多协议输入寄存器,需外部应用层程序赋值*/
    multi_prtocol_input_t		input;		
    
    /*! 内部参数，无需关注*/
    dcp_prtocol_base_t		dcp;
    
    /*! 内部参数，无需关注*/
    qc_prtocol_base_t		qc;
    
    /*! 内部参数，无需关注*/
    vooc_prtocol_base_t		vooc;
    
    /*! 内部参数，无需关注*/
    DMDP_vol_level_t			vol;
    
    /*! 内部参数，无需关注*/
    multi_prtocol_time_base_t	timebase;
    
    /*! 内部参数，无需关注*/
    multi_prtocol_inside_t		inside;
    
    /*! 内部参数，无需关注*/
    volatile uint8_t	channel_bk;
    
    volatile uint8_t	scp_dp_down;
}multi_prtocol_base_t;
/**@}*/ /*** end of group multi_protocol_data_define */
/*******************************************************************************/
typedef struct
{
	/*! SCP输出电压最小最大值*/
	volatile uint8_t	scp_min_vout;
	volatile uint8_t	scp_max_vout;
	
	/*! SCP输出功率最大值*/
	volatile uint8_t	scp_max_pwr;
	
	/*! SCP输出电流最大值*/
	volatile uint8_t	scp_min_iout;
	volatile uint8_t	scp_max_iout;
	
	/* SCP adp type0 处理 */
	volatile uint8_t	scp_adp_type0;

	/* SCP 功率分段 */
	volatile uint8_t	scp_seg_num;
	volatile uint8_t	scp_vout_seg[16];
	volatile uint8_t	scp_iout_seg[16];
	
	/* SCP 降功率设置 */
	volatile uint8_t	scp_reduce_power;
	
	/**
		现像:
			SCP输出状态下
			安克有款无线充magsafe
			英集芯的方案优先QC,所以先进入QC，无线充A2521的QC是正常的；
			芯海方案同时沟通VOOC\ QC \SCP,无线充A2521的SCP正好有问题(第一次0x46，第二次0x48,第三次0x00)，导致输出电流断开。
		措施:
			让39的回ping，滞后其它协议大约10000ms
			带使能
			滞后时间可设
	 */
	volatile bool		B_scp_hysteresis_en;//外部设置
	volatile uint16_t	scp_hysteresis_tm_value;//外部设置
	volatile uint16_t	t_scp_hysteresis;	//私有，外部不用设置
}multi_prtocol_control_extern_t;

typedef struct
{
	multi_prtocol_control_extern_t	control;
}multi_protocol_base_extern_t;

/******************************** dividing line ********************************/
/** 
 * @addtogroup multi_protocol_api	api
 * @{
 */
/**
 * @name multi_protocol_api
 * @{
 */
/**
 * @brief 	<b>Description:</b> 多协议模块初始化.
 * @details <b>Function prototype:</b> void multi_protocol_init(void);
 * @param[in]  null.
 * @param[out] null.
 * @attention <b> called in power on or wakeup  初始化或休眠唤醒时调用</b>
 * @return  null
 * @par Example
 * @code
 *		void peripheral_multi_protocol_init(void)
 *		{
 *			multi_protocol_init();
 *
 *			multi_protocol.channel = CHANEL_DMDPC;
 *			multi_protocol.control.fastchg_protocol_scan_en = 1;
 *			multi_protocol.control.GPIO_multiplex_DMDPA = 1;
 *			multi_protocol.control.GPIO_multiplex_DMDPB = 1;
 *			multi_protocol.control.GPIO_multiplex_DMDPC = 1;
 *
 *			multi_protocol.control.qc_protocol_out_en = 1;
 *			multi_protocol.control.qc_protocol_out_12v_en = 1;
 *	
 *			
 *			multi_protocol.control.qc30_protocol_out_en = 1;
 *			multi_protocol.control.qc30_protocol_3v6_en = 1;
 *				
 *			multi_protocol.control.fcp_protocol_out_en = 1;
 *			multi_protocol.control.fcp_protocol_out_12v_en = 1;
 *			multi_protocol.control.fcp_protocol_in_en = 1;
 *			multi_protocol.control.fcp_protocol_in_num = FCP_IN_NUM_12V;
 *	
 *			multi_protocol.control.scp_protocol_out_en = 1;
 *			multi_protocol.control.scp_vbus_compensate = SCP_VBUS_COMPENSATE;
 *			
 *			multi_protocol.control.afc_protocol_out_en = 1;
 *			multi_protocol.control.afc_protocol_out_12v_en = 1;
 *			multi_protocol.control.afc_protocol_in_en = 1;
 *			multi_protocol.control.afc_protocol_in_num = AFC_IN_NUM_12V;
			
 *			multi_protocol.dir = DIR_DISCHARGE;
 *		}
 * @endcode
 */
extern void multi_protocol_init(void);

/**
 * @brief 	<b>Description:</b> multi_protocol_scan_process.
 * @details <b>Function prototype:</b> void multi_protocol_scan_process(void);
 * @param[in]  null.
 * @param[out] null.
 * @attention <b> called in while(1) 在主循环中扫描</b>
 * 
 * @return  null
 * @par Example
 * @code
 *		void main(void)
 *		{
 *			while(1)
 *			{
 *				multi_protocol_scan_process();
 *			}
 *		}
 * @endcode
 */
extern void multi_protocol_scan_process(void);

/**
 * @brief 	<b>Description:</b> multi_protocol_isr_process.
 * @details <b>Function prototype:</b> void multi_protocol_isr_process(void);
 * @param[in]  null.
 * @param[out] null.
 * @attention <b> called in INT_FUNCTION 在中断服务函数中调用</b>
 * 
 * @return  null
 * @par Example
 * @code
 *		void INT_FUNCTION(void) interrupt
 *		{
 *			multi_protocol_isr_process();	
 *		}
 * @endcode
 */
extern void multi_protocol_isr_process(void);

/**
 * @brief 	<b>Description:</b> multi_protocol_sleep.
 * @details <b>Function prototype:</b> void multi_protocol_sleep(void);
 * @param[in]  null.
 * @param[out] null.
 * @attention <b> called in sleep 在sleep前调用</b>
 * 
 * @return  null
 * @par Example
 * @code
 *		void sleep(void)
 *		{
 *			multi_protocol_sleep();
 *			asm("sleep")
 *		}
 * @endcode
 */
extern void multi_protocol_sleep(void);

/**
 * @brief 	<b>Description:</b> multi_protocol_timebase_callback.
 * @details <b>Function prototype:</b> void multi_protocol_timebase_callback(void);
 * @param[in]  null.
 * @param[out] null.
 * @attention <b> called in 1ms INT_FUNCTION 在1ms中断中调用</b>
 * 
 * @return  null
 * @par Example
 * @code
 *		void timer0_irq(void)
 *		{
 *			if(__T0_TM0IE_GET_SHIFT()!= 0)
 *			{
 *				multi_protocol_timebase_callback();
 *			}
 *		}
 * @endcode
 */
extern void multi_protocol_timebase_callback(void);

/**@}*/ /*** end of name multi_protocol_api */
/**@}*/ /*** end of group multi_protocol_api */

/******************************** dividing line ********************************/
/** 
 * @addtogroup multi_protocol_global_variable	global_variable
 * @{
 */
/**
 * @name global_variable
 * @{
 */
extern multi_bank multi_prtocol_base_t	multi_protocol;
extern scp_bank multi_protocol_base_extern_t	multi_protocol_extern;
extern scp_bank scp_prtocol_base_t	scp_protocol;
/**@}*/ /*** end of name global_variable */
/**@}*/ /*** end of name multi_protocol_global_variable */

void isr_reset(void);

uint16_t multi_lib_version_number(void);
/**@}*/ /*** end of group cpwxxxx_sdk_protocolib_multi_protocol */
/**@}*/ /*** end of group cpwxxxx_sdk_protocolib */
/*******************************************************************************/

#endif
