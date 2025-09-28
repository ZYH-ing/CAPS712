
#ifndef _STATE_MACHINE_H
#define _STATE_MACHINE_H


#include "csu39fx10.h"
#include "cs_common.h"

#define BANK_STATE_M	bank4

#define SINKCAP_COUNT_L		1
#define SINKCAP_COUNT_H		2

#define QC_CHL_EN_TCA				(1)				/*!< 0-> disable, 1-> enable*/
#define QC_CHL_EN_TCB				(0)				/*!< 0-> disable, 1-> enable*/
#define QC_CHL_EN_TA1				(0)				/*!< 0-> disable, 1-> enable*/
#define	SCP_HYSTERESIS_TIM			(1000/1)		/*!< SCP输出协议滞后时间*/

typedef enum
{
	DL0 = 0,		//立即打开
	DLY = 250,		//延迟打开
	DLT = 100,		//延迟打开
}typex_switch_t;

//Mos Bridge
typedef enum
{
	//typecb_typeca_typeb1_typea1
	SW_NO_NO_NO_NO,
	SW_NO_NO_NO_A1,
	SW_NO_NO_B1_NO,
	SW_NO_NO_B1_A1,
	SW_NO_CA_NO_NO,
	SW_NO_CA_NO_A1,
	SW_NO_CA_B1_NO,
	SW_NO_CA_B1_A1,
	SW_CB_NO_NO_NO,
	SW_CB_NO_NO_A1,
	SW_CB_NO_B1_NO,
	SW_CB_NO_B1_A1,
	SW_CB_CA_NO_NO,
	SW_CB_CA_NO_A1,
	SW_CB_CA_B1_NO,
	SW_CB_CA_B1_A1,
}switch_bridge_t;

typedef enum
{
	_N___N___N___N___N___N_		= (uint8_t)0,
	_N___N___N___N___N__A1D,
	_N___N___N___N__B1C__N_,
	_N___N___N___N__B1C_A1D,
	_N___N___N__CAC__N___N_,
	_N___N___N__CAC__N__A1D,
	_N___N___N__CAC_B1C__N_,
	_N___N___N__CAC_B1C_A1D,
	_N___N__CAD__N___N___N_,
	_N___N__CAD__N___N__A1D,
	_N___N__CAD__N__B1C__N_,
	_N___N__CAD__N__B1C_A1D,
	_N___N__CAD_CAC__N___N_,
	_N___N__CAD_CAC__N__A1D,
	_N___N__CAD_CAC_B1C__N_,
	_N___N__CAD_CAC_B1C_A1D,
	_N__CBC__N___N___N___N_,
	_N__CBC__N___N___N__A1D,
	_N__CBC__N___N__B1C__N_,
	_N__CBC__N___N__B1C_A1D,
	_N__CBC__N__CAC__N___N_,
	_N__CBC__N__CAC__N__A1D,
	_N__CBC__N__CAC_B1C__N_,
	_N__CBC__N__CAC_B1C_A1D,
	_N__CBC_CAD__N___N___N_,
	_N__CBC_CAD__N___N__A1D,
	_N__CBC_CAD__N__B1C__N_,
	_N__CBC_CAD__N__B1C_A1D,
	_N__CBC_CAD_CAC__N___N_,
	_N__CBC_CAD_CAC__N__A1D,
	_N__CBC_CAD_CAC_B1C__N_,
	_N__CBC_CAD_CAC_B1C_A1D,
	CBD__N___N___N___N___N_,
	CBD__N___N___N___N__A1D,
	CBD__N___N___N__B1C__N_,
	CBD__N___N___N__B1C_A1D,
	CBD__N___N__CAC__N___N_,
	CBD__N___N__CAC__N__A1D,
	CBD__N___N__CAC_B1C__N_,
	CBD__N___N__CAC_B1C_A1D,
	CBD__N__CAD__N___N___N_,
	CBD__N__CAD__N___N__A1D,
	CBD__N__CAD__N__B1C__N_,
	CBD__N__CAD__N__B1C_A1D,
	CBD__N__CAD_CAC__N___N_,
	CBD__N__CAD_CAC__N__A1D,
	CBD__N__CAD_CAC_B1C__N_,
	CBD__N__CAD_CAC_B1C_A1D,
	CBD_CBC__N___N___N___N_,
	CBD_CBC__N___N___N__A1D,
	CBD_CBC__N___N__B1C__N_,
	CBD_CBC__N___N__B1C_A1D,
	CBD_CBC__N__CAC__N___N_,
	CBD_CBC__N__CAC__N__A1D,
	CBD_CBC__N__CAC_B1C__N_,
	CBD_CBC__N__CAC_B1C_A1D,
	CBD_CBC_CAD__N___N___N_,
	CBD_CBC_CAD__N___N__A1D,
	CBD_CBC_CAD__N__B1C__N_,
	CBD_CBC_CAD__N__B1C_A1D,
	CBD_CBC_CAD_CAC__N___N_,
	CBD_CBC_CAD_CAC__N__A1D,
	CBD_CBC_CAD_CAC_B1C__N_,
	CBD_CBC_CAD_CAC_B1C_A1D,
}plug_state_t;

typedef union
{
	struct
	{
		uint8_t b_a1d	: 1;					/*!< typea_1 discharge */
		uint8_t b_b1c	: 1;					/*!< typec_1 charge */
		uint8_t b_cac	: 1;					/*!< typec_a charge */
		uint8_t b_cad	: 1;					/*!< typec_a discharge */
		uint8_t b_cbc	: 1;					/*!< typec_b charge */
		uint8_t b_cbd	: 1;					/*!< typec_b discharge */
		uint8_t b_bcxc	: 1;					/*!< typeb_1 or typec_x charge */
		uint8_t b_acxd	: 1;					/*!< typea_1 or typec_x discharge */
	}bit;
	plug_state_t		byte;
}plug_state_bits_t;

typedef struct
{
#if CFG_SIMP_BITFIELD
	uint8_t b_caout_break_cb;					/*!< typec_a plug-out break typec_b */
	uint8_t b_cain_break_cb;					/*!< typec_a plug-in break typec_b */
	uint8_t b_cbout_break_ca;					/*!< typec_b plug-out break typec_a */
	uint8_t b_cbin_break_ca;					/*!< typec_b plug-in break typec_a */
	uint8_t b_a1d_break_cx;						/*!< typea_1 plug-in/out break typec_x */
	uint8_t b_cax_break;						/*!< typec_a breck */
	uint8_t b_cbx_break;						/*!< typec_b breck */
	uint8_t b_qc_break;							/*!< qc breck */
#else
	uint8_t b_caout_break_cb	: 1;			/*!< typec_a plug-out break typec_b */
	uint8_t b_cain_break_cb		: 1;			/*!< typec_a plug-in break typec_b */
	uint8_t b_cbout_break_ca	: 1;			/*!< typec_b plug-out break typec_a */
	uint8_t b_cbin_break_ca		: 1;			/*!< typec_b plug-in break typec_a */
	uint8_t b_a1d_break_cx		: 1;			/*!< typea_1 plug-in/out break typec_x */
	uint8_t b_cax_break			: 1;			/*!< typec_a breck */
	uint8_t b_cbx_break			: 1;			/*!< typec_b breck */
	uint8_t b_qc_break			: 1;			/*!< qc breck */
#endif
}plug_event_flag_t;

typedef struct
{
#if CFG_SIMP_BITFIELD
	uint8_t b_dcdc_en;							/*!< dcdc pstop, 0-> disable, 1-> enable*/
	uint8_t b_dcdc_dir;							/*!< dcdc charge or dischar, 0-> charge, 1-> dischar*/
	uint8_t b_vbus_dischar;						/*!< vbus dischar, 0-> disable, 1-> enable*/
#else
	uint8_t b_dcdc_en			: 1;			/*!< dcdc pstop, 0-> disable, 1-> enable*/
	uint8_t b_dcdc_dir			: 1;			/*!< dcdc charge or dischar, 0-> charge, 1-> dischar*/
	uint8_t b_vbus_dischar		: 1;			/*!< vbus dischar, 0-> disable, 1-> enable*/
#endif
}control_action_t;


typedef enum
{
	CHL_PD_TCA	= (uint8_t) 0x00,
	CHL_PD_TCB,
}protocol_pd_chl_t;

typedef enum
{
	CHL_MU_NULL = 0,
	CHL_MU_TCA,
	CHL_MU_TCB,
	CHL_MU_TA1,
	CHL_MU_TA2,
}protocol_mu_chl_t;


typedef struct
{
#if CFG_SIMP_BITFIELD
	uint8_t b_pd_en;							/*!< pd protocol enable state, 0-> disable, 1-> enable*/
#else
	uint8_t b_pd_en				: 1;			/*!< pd protocol enable state, 0-> disable, 1-> enable*/
#endif
	protocol_pd_chl_t	pd_chl;					/*!< pd protocol channel, 0-> tca, 1-> tcb*/
	protocol_mu_chl_t	b_multi_chl;			/*!< multi protocol enable state, 0-> disable, 1-> enable*/
}protocol_state_t;




typedef struct
{
	// uint8_t			b_in_status;			//充电状态标志位
	plug_state_bits_t	state;					//接口状态
	plug_event_flag_t	event_flag;				//接口事件标志
	control_action_t	control_flag;			//控制动作标志
	protocol_state_t	protocol_flag;			//协议状态标志
	
	uint8_t pd_work;							/*!< true:pd work,	false:no pd work	*/
}plug_state_context_t;

extern BANK_STATE_M plug_state_context_t plug_state_context;
extern  uint8_t USBA_IN_DIS;
extern  uint8_t WR_IN_DIS;
//extern  uint8_t USBA1_2_dis_fast;
//extern  uint8_t WR_OUT_9V;
extern BANK_STATE_M uint8_t requesrt_9V_F;
extern BANK_STATE_M uint8_t CA_rutren;

void plug_state_machine_proc(void);
void plug_state_charge_lag_open_vbus_proc(void);




#endif
