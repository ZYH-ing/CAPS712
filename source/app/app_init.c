#include "app_init.h"
// driver
#include "csu39fx10_syscfg.h"
#include "csu39fx10_exti.h"
#include "drv_gpio.h"
#include "drv_timer.h"
#include "drv_uart.h"
#include "drv_wdt.h"
#include "drv_adc.h"
// module
#include "mod_display.h"
#include "mod_key.h"
#include "mod_dcdc.h "
#include "mod_input_output.h"
#include "mod_adc_convert.h"
#include "mod_coulomb.h"
#include "mod_modbus.h"

// protocol
#include "lib_prot_pd.h"
#include "lib_prot_typec.h"
#include "lib_multi_protocol.h"

// app
#include "app_state_machine.h"
#include "app_main.h"

#include "app_typec_deal.h"
#include "mod_queue.h"
#include "mod_display.h"

#define VID 0x2DC0ul
#define PID 0x020Bul
#define XID 0x00000000ul
#define SVID 0xFF00ul
#define FW_REV 0x30ul
#define HW_REV 0x10ul

TypeOfTemp Temp;

uint8_t Frist_start_sink; ////1---判断锂电保护状态 2---锂电保护则充电判断适配器  没有保护则 确认继续充电 或者不充电///
BANK_Add uint8_t Charge_low_power_F;
BANK_Add uint8_t Charge_low_power_CNT;

BANK_Add uint8_t Charge_bat_low_power_F;
BANK_Add uint8_t Charge_bat_low_power_CNT;

BANK_Add uint8_t Charge_HIG_Vbat_F;
BANK_Add uint8_t Charge_low_Vbat_CNT;

BANK_Add uint8_t uart_read_temp;
BANK_Add uint16_t A1_closeTIME;

BANK_Add uint8_t Car_low_bat_cnt;

BANK_Add uint8_t Temp_limit_discharge;
BANK_Add uint8_t Temp_limit_I;
BANK_Add uint8_t Temp_limit_count;
BANK_Add uint8_t Temp_close_limit_count;

BANK_Add uint8_t Bat_Protest_cnt; /// 电池过充保护处理////

BANK_Add uint8_t Bat_low_sleep_flage;

BANK_Add uint8_t hour2_dis_flage;

BANK_Add uint8_t Flash_Bat_Vol_data;
BANK_Add uint8_t Flash_Bat_Value_data;
BANK_Add uint8_t Flash_Bat_RCR_data;

BANK_Add uint16_t hour2_dis_cnt;
// BANK_Add uint8_t Bat_low_sleep_flage;

BANK_Add uint16_t ADD_IBAT_cnt;
BANK_Add uint8_t ADD_percent_accu;

BANK_Add uint8_t CA_IN_Frist_No_Soure;

BANK_Add uint8_t BAT_CO_OPEN_CNT;

BANK_Add uint8_t Self_inspe_CNT;

BANK_Add uint8_t car_low_bater_Cnt;
BANK_Add uint8_t car_OK_Flage;

BANK_Add uint8_t DIS_low_bater_Cnt;

BANK_Add uint16_t open_to_12hour_Cnt;

BANK_Add uint8_t Port_NTC_NG_LOW_POWER_Flage;
BANK_Add uint8_t Port_NTC_NG_LOW_POWER_Cnt;

BANK_Add uint16_t I_All_IN_Do;

Add_data_bank uint8_t BAT_real;

Add_data_bank uint8_t BAT_cnt_recor;
// BANK_Add uint16_t C_ADD_IBAT_cnt;
// BANK_Add uint8_t  C_ADD_percent_accu;

// BANK_Add uint8_t Disharge_ADD_percent_accu;

Add_data_bank LCD_display_3S_Cnt;

bank1 uint32_t pdo_src_list[7][2];

/** PD 电压电流档位**/
const uint32_t pdo_src_list_h[7][2] =
	{
		{PDO_SRC_VOL_H0, PDO_SRC_CURR_H0},
		{PDO_SRC_VOL_H1, PDO_SRC_CURR_H1},
		{PDO_SRC_VOL_H2, PDO_SRC_CURR_H2},
		{PDO_SRC_VOL_H3, PDO_SRC_CURR_H3},
		{PDO_SRC_VOL_H4, PDO_SRC_CURR_H4},
		{0, 0},
		{0, 0}};

volatile const uint8_t source_capabilities_extended_message[24] =
	{
		(uint8_t)(VID >> 0),
		(uint8_t)(VID >> 8),
		(uint8_t)(PID >> 0),
		(uint8_t)(PID >> 8),
		(uint8_t)(XID >> 0),
		(uint8_t)(XID >> 8),
		(uint8_t)(XID >> 16),
		(uint8_t)(XID >> 24),
		FW_REV,
		HW_REV,
		0x00, /** byte 11**/
		0x00,
		0x00,
		0x02,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x04,
		0x01,
		0x1B,
};

volatile const uint8_t status_message[5] =
	{
		0x00, 0x08, 0x02, 0x00, 0x00};

volatile const uint8_t battery_capabilities_message[9] =
	{
		0xFF,
		0x00,
		0x5A,
		0xA5,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0x00,
};

volatile const uint32_t pdo_sourcecap[] =
	{
		PDO_SOURCECAP_H0,
		PDO_SOURCECAP_H1,
		PDO_SOURCECAP_H2,
		PDO_SOURCECAP_H3,
		PDO_SOURCECAP_H4,
		PDO_SOURCECAP_PPS1,
		PDO_SOURCECAP_PPS2};

volatile const uint32_t pdo_sourcecap_45[] =
	{
		PDO_SOURCECAP_H0_1,
		PDO_SOURCECAP_H1_1,
		PDO_SOURCECAP_H2_1,
		PDO_SOURCECAP_H3_1,
		PDO_SOURCECAP_H4_1,
		PDO_SOURCECAP_PPS1_1,
		PDO_SOURCECAP_PPS2_1};

volatile const uint32_t pdo_sourcecap_30[] =
	{
		PDO_SOURCECAP_H0_2,
		PDO_SOURCECAP_H1_2,
		PDO_SOURCECAP_H2_2,
		PDO_SOURCECAP_H3_2,
		PDO_SOURCECAP_H4_2,
		PDO_SOURCECAP_PPS1_2,
		PDO_SOURCECAP_PPS2_2};

volatile const uint32_t pdo_sourcecap_18[] =
	{
		PDO_SOURCECAP_H0_3,
		PDO_SOURCECAP_H1_3,
		PDO_SOURCECAP_H2_3,
		PDO_SOURCECAP_H3_3,
		PDO_SOURCECAP_H4_3,
		PDO_SOURCECAP_PPS1_3,
		PDO_SOURCECAP_PPS2_3};
// volatile  uint32_t pdo_sourcecap[7]=
//{
//	PDO_SOURCECAP_H0,
//	PDO_SOURCECAP_H1,
//	PDO_SOURCECAP_H2,
//	PDO_SOURCECAP_H3,
//	PDO_SOURCECAP_H4,
//	PDO_SOURCECAP_PPS1,
//	PDO_SOURCECAP_PPS2
// };

// volatile const uint32_t pdo_sourcecap_45W[]=
// {
// 	PDO_SOURCECAP_H0,
// 	PDO_SOURCECAP_H1,
// 	PDO_SOURCECAP_H2,
// 	PDO_SOURCECAP_H3,
// 	PDO_SOURCECAP_H4L,
// 	PDO_SOURCECAP_PPS1,
// 	PDO_SOURCECAP_PPS2
// };

// const uint32_t pdo_sourcecap_l[7]=
// {
// 	PDO_SOURCECAP_L0,
// 	PDO_SOURCECAP_L1,
// 	PDO_SOURCECAP_L2,
// 	PDO_SOURCECAP_L3,
// 	PDO_SOURCECAP_L4,
// 	PDO_SOURCECAP_PPS_L0
// };

const uint32_t multi_src_list[QC_SOURCECAP_COUNT + 1][2] =
	{
		{QC_SRC_VOL_H0, QC_SRC_CURR_H0},
		{QC_SRC_VOL_H1, QC_SRC_CURR_H1},
		{QC_SRC_VOL_H2, QC_SRC_CURR_H2},
		{0, QC_SRC_CURR_H8},
};

volatile const uint32_t pdo_sinkcap[] =
	{
		PDO_SINKCAP_H0,
		PDO_SINKCAP_H1};

// volatile const uint32_t pdo_sinkcap_1[]=
// {
// 	PDO_SINKCAP_H0_1,
// 	PDO_SINKCAP_H1_1
// };

// volatile const uint32_t pdo_sinkcap_2[]=
// {
// 	PDO_SINKCAP_H0_2,
// 	PDO_SINKCAP_H1_2
// };

// volatile const uint32_t pdo_sinkcap_3[]=
// {
// 	PDO_SINKCAP_H0_3,
// 	PDO_SINKCAP_H1_3
// };

// volatile  uint32_t pdo_sinkcap[2]=
//{
//	PDO_SINKCAP_H0,
//	PDO_SINKCAP_H1
// };

volatile const uint32_t pdo_sinkcap_9[] =
	{
		PDO_SINKCAP1_H0,
		PDO_SINKCAP1_H1};

//

// volatile const uint16_t  Vbat_Tab[] = {C_Normal_VBat_Level21,C_Normal_VBat_Level20,C_Normal_VBat_Level19,C_Normal_VBat_Level18,C_Normal_VBat_Level17,
//                                        C_Normal_VBat_Level16,C_Normal_VBat_Level15,C_Normal_VBat_Level14,C_Normal_VBat_Level13,C_Normal_VBat_Level12,
//                                        C_Normal_VBat_Level11,C_Normal_VBat_Level10,C_Normal_VBat_Level9,C_Normal_VBat_Level8,C_Normal_VBat_Level7,
//                                        C_Normal_VBat_Level6,C_Normal_VBat_Level5,C_Normal_VBat_Level4,C_Normal_VBat_Level3,C_Normal_VBat_Level2,
//									   C_Normal_VBat_Level1
//							           };
volatile const uint8_t Vbat_Tab[] = {C_Normal_VBat_Level21, C_Normal_VBat_Level20, C_Normal_VBat_Level19, C_Normal_VBat_Level18, C_Normal_VBat_Level17,
									 C_Normal_VBat_Level16, C_Normal_VBat_Level15, C_Normal_VBat_Level14, C_Normal_VBat_Level13, C_Normal_VBat_Level12,
									 C_Normal_VBat_Level11, C_Normal_VBat_Level10, C_Normal_VBat_Level9, C_Normal_VBat_Level8, C_Normal_VBat_Level7,
									 C_Normal_VBat_Level6, C_Normal_VBat_Level5, C_Normal_VBat_Level4, C_Normal_VBat_Level3, C_Normal_VBat_Level2,
									 C_Normal_VBat_Level1};
volatile const uint8_t VbatDisP_Tab[] = {99, 95, 90, 85, 80,
										 75, 70, 65, 60, 55,
										 50, 45, 40, 35, 30,
										 25, 20, 15, 10, 5,
										 1, 0, 0};

volatile unsigned char R_data_tx;
volatile unsigned char R_count_tx;

uint8_t bat_full_cnt;
uint8_t R_SysMode_OK;
uint8_t R_SysMode_OK_bak;
uint8_t R_SysMode_BE;
uint8_t Charge_up_Cnt;
uint8_t DisCharge_down_Cnt;
uint8_t Bat_low_Cnt;

uint8_t Bat_low_RE_Cnt;

BANK_Add uint8_t Bat_low2_Cnt;

uint8_t Discharge_MinCur;
uint8_t R_DisCharge_SmallCurCnt;
uint8_t R_DisCharge_OutTime;
uint8_t R_Charge_level;			 ///// 充电电压等级////0---正常充电 1---限制充电电流2A   2---限制充电电流1A
uint8_t R_Charge_level_up_Cnt;	 ///// 充电电压等级上升////
uint8_t R_Charge_level_down_Cnt; ///// 充电电压等级下降////
uint8_t MiroB_charge_Cnt;		 ///// MiroB口充电 插入检测计数////
uint8_t MiroB_dis_Cnt;			 /// MiroB口充电 移除检测计数////

static void coulomb_init(void);
BANK_Add uint8_t V_NO_Cha_flage; //// 充电过压标志位 1--过压 0--正常////

BANK_Add uint8_t V_NO_Charge;

BANK_Add uint8_t V_NO_BAT_Charge; ////锂电保护标志位/////

BANK_Add uint8_t V_NO_BAT_Cnt;

BANK_Add uint8_t SOS_lighting_stop;

BANK_Add uint8_t bat_dis_full_cnt;

BANK_Add uint8_t statusKeyFlag;
BANK_Add uint8_t Be_statusKeyFlag;

BANK_Add unsigned char flash_count; /////闪灯计时////
BANK_Add unsigned char sos_state;	////SOS 步骤数
BANK_Add unsigned char sos_count;	////SOS 计时/////

BANK_Add uint16_t TYPEC_sleep_time_cnt;
BANK_Add uint8_t TYPEC_sleep_distime_cnt;

BANK_Add uint8_t CA_Test_do_no_Slepp; //// 输入重新沟通一次

BANK_Add uint8_t delay_Check_C_Vol; ////

BANK_Add uint8_t Charge_Bat_Start_Cnt;

BANK_Add uint8_t Frist_Bat_Connect;

BANK_Add uint8_t Frist_Bat_100ms_Cnt;

Add_data_bank uint8_t Car_Cont_NG_Flage;
void app_peripheral_init(void)
{
	uint8_t SC8886_data_8;
	// 初始化时钟
	SystemInit();
	// 初始化syscfg
	syscfg_init(); ////---ok
	// 初始化外部中断
	//  exi_init();
	// 初始化timer0
	timer0_init(); ///---ok
				   /////////////////////IO初始化 统一处理////////
				   //    PT1=0xa0;    ///1010 0000
				   //    PT1EN=0xf0;  ///1111 0000
				   //    PT1PU=0x09;  ///0000 1001
	PT1 = 0x00;	   /// 0000 0000
	PT1EN = 0xf0;  /// 1111 0000
	PT1PU = 0x09;  /// 0000 1001
	//    PT1PU=0x0d;  ///0000 1101

	PT2 = 0x00;	  /// 0000 0000
	PT2EN = 0x24; /// 0010 0100//// PT2.2 输出0
	PT2PU = 0x80; /// 1000 0000

	PT3 = 0x20;	  /// 0000 0000
	PT3EN = 0x78; /// 0101 1000
	PT3PU = 0x20; /// 0000 0000

	//   BAT_EN_PIN_ON;
	delay_ms(100);
	// C_VDD_ON;
	EN_SYS_IN;
	//  WR_PIN_ON_DIS_WRITE;
	mod_display_init(); ////----ok
	//   KEY1_inti;

	inoutput_data.vbus_switch.vbus_type_b1_delay_cnt = 0;
	inoutput_data.vbus_switch.vbus_type_ca_delay_cnt = 0;
	inoutput_data.vbus_switch.vbus_discharge_delay_cnt = 0;
	inoutput_data.vbus_switch.pstop_delay_cnt = 0;

	inoutput_data.vbus_switch.sw.type_b1 = false;
	inoutput_data.vbus_switch.sw.type_ca = false;
	inoutput_data.vbus_switch.sw.discharge = false;

	BAT_CO_OPEN_CNT = 0;
	// 	if(!KEY1)/// 检测按键按下处理//// 正常开机处理////
	//     {
	//         BAT_CO_OPEN_CNT=0;
	//         Frist_start_sink=Frist_normal_do;

	// //        LCD_display_3S_Cnt=1;

	//     }
	//     else//// 不是按键唤醒处理///开启充电处理 检测电池状态//////
	//     {
	//        BAT_CO_OPEN_CNT=1;
	//        Frist_start_sink=Frist_Bat_Check_do;
	//        TCA_PIN_ON;
	//     }
	//	delay_ms(50);

	//	#if __IF_DEBUG__
	//	 Sub_sim_tx(0x11);
	// 	 Sub_sim_tx(0x21);
	//	 Sub_sim_tx(0x31);
	//	#endif
	//

	delay_ms(100);
	BAT_Pro_Charge = 1;
	while (1)
	{
		mod_SC8886_init();
		delay_ms(10);
		SC8886_data_8 = iic_receive_byte(0x34); //// 充电目标电压 14.4V  ///// 磷酸铁锂电池

		if (SC8886_data_8 == Data_720334)
		{
			break;
		}
		//		 MIR_B_PIN_ON;//// 开充电处理初始化/////
		TCA_PIN_ON;
	}
	//     MIR_B_PIN_OFF;
	TCA_PIN_OFF;
	//  初始化Type-c模块
	peripheral_typec_init(&h_typeca); ////初始化 TYPE—CA 特性
	peripheral_typec_init(&h_typecb); ////初始化 TYPE—CB 特性
#if !CFG_PD_DISABLE
	// 初始化PD模块
	peripheral_pd_init(); //// 初始化PDO///
#endif

#if __DMPM__EN
	/** 初始化多协议**/ ////关闭多协议/////
	multi_protocol_init();

	//    multi_protocol.channel = CHANEL_DMDPC;////  详情见附件 F10功能测试
	//	multi_protocol.channel = CHANEL_DMDPA;
	multi_protocol.channel = CHANEL_DMDPA;				 /// CHL_MU_NULL  CHANEL_NULL
	multi_protocol.control.fastchg_protocol_scan_en = 1; // multi_protocol.control.fastchg_protocol_scan_en
	multi_protocol.control.GPIO_multiplex_DMDPA = 1;
	//	multi_protocol.control.GPIO_multiplex_DMDPA = 1;/// 取消C口 D+D_快充功能
	multi_protocol.control.GPIO_multiplex_DMDPB = 0;
	multi_protocol.control.GPIO_multiplex_DMDPC = 0;
	multi_protocol.control.GPIO_multiplex_DMDPD = 0;

	/** QC2.0**/
	multi_protocol.control.qc_protocol_out_en = 1; /////multi_protocol.control.qc_protocol_out_en
	multi_protocol.control.qc_protocol_out_12v_en = 1;
	multi_protocol.control.qc_protocol_in_en = 1;
	multi_protocol.control.qc_protocol_in_num = QC_IN_NUM_12V;
	// multi_protocol.control.qc_protocol_in_num = QC_IN_NUM_9V;

	/** QC3.0**/
	multi_protocol.control.qc30_protocol_out_en = 1;
	multi_protocol.control.qc30_protocol_3v6_en = 1;
	multi_protocol.control.qc30_protocol_in_en = 0;
	//	multi_protocol.control.qc30_protocol_in_vol = 0xF0;
	multi_protocol.control.qc30_protocol_in_vol = 0x0168; // 9V  360---25mV

	/** FCP**/
	multi_protocol.control.fcp_protocol_out_en = 1;
	multi_protocol.control.fcp_protocol_out_12v_en = 1;
	//	multi_protocol.control.fcp_protocol_in_en = 1;
	multi_protocol.control.fcp_protocol_in_en = 0; // 关掉FCP输入
	//	multi_protocol.control.fcp_protocol_in_num = FCP_IN_NUM_12V;
	multi_protocol.control.fcp_protocol_in_num = FCP_IN_NUM_9V;

	/** SCP**/
	multi_protocol.control.scp_protocol_out_en = 1;
	multi_protocol.control.scp_vbus_compensate = SCP_VBUS_COMPENSATE;

	/** AFC**/
	multi_protocol.control.afc_protocol_out_en = 1;
	multi_protocol.control.afc_protocol_out_12v_en = 1;
	//	multi_protocol.control.afc_protocol_in_en = 1;
	multi_protocol.control.afc_protocol_in_en = 0; // 关掉AFC输入
	multi_protocol.control.afc_protocol_in_num = AFC_IN_NUM_12V;

	/** VOOC**/
	multi_protocol.control.vooc_protocol_out_en = 1;
	multi_protocol.control.vooc_protocol_in_en = 1;
	multi_protocol.control.vooc40_protocol_out_en = 1;
	multi_protocol.control.vooc40_protocol_in_en = 1;
	multi_protocol.control.svooc_protocol_out_en = 1;
	multi_protocol.control.svooc_protocol_in_en = 1;
	multi_protocol.control.typea_vooc_cable_det_en = 1;
	multi_protocol.control.vooc_impedance_compensate = VOOC_IMPEDANCE_COMPENSATE;

	multi_protocol.dir = DIR_DISCHARGE;
#endif

#if (!CFG_SYS_WDT_DISABLE)
	// 初始化看门狗
	wdt_init();
//	wwdt_init();
#endif
	timer2_init();

	//   timer3_init();
	//   timer4_init();
	uart_init();
	//   acmp0_init();

	// 初始化ADC
	mod_adc_convert_init(); ////---
}

void peripheral_typec_init(TC_BANK typec_handle_t *p_h_typec)
{
#if 0
//	if(p_h_typec == &h_typeca)
//	{
//		p_h_typec->input.instance= TYPECA;
//	}
//	else
//	{
////		p_h_typec->input.instance= TYPECB;
//	}
//	p_h_typec->input.b_huawei_support= SET;
//	if(SYS_in_Sleep_F)
//	 p_h_typec->input.b_power_on= RESET;
//	else
//	p_h_typec->input.b_power_on= SET;
////    p_h_typec->input.b_power_on= RESET;
//	p_h_typec->input.b_vbus_isexist= SET;
//	p_h_typec->input.current_source= TYPEC_CCX_CUR_330UA;
//	p_h_typec->input.port_type= TYPEC_PORT_DRP_TRY_SRC;
//	typec_init(p_h_typec);
#endif

	if (p_h_typec == &h_typeca)
	{
		p_h_typec->input.instance = TYPECA;
		p_h_typec->input.port_type = TYPEC_PORT_DRP_TRY_SRC; // 区分CA/CB
	}
	else
	{
		p_h_typec->input.instance = TYPECB;
		p_h_typec->input.port_type = TYPEC_PORT_DRP_TRY_SRC; // 区分CA/CB
	}
	p_h_typec->input.b_huawei_support = SET;
	//	p_h_typec->input.b_power_on= SET;

	if (SYS_in_Sleep_F)
		p_h_typec->input.b_power_on = RESET;
	else
		p_h_typec->input.b_power_on = SET;

	p_h_typec->input.b_vbus_isexist = SET;
	p_h_typec->input.current_source = TYPEC_CCX_CUR_330UA;

	p_h_typec->input.b_tim_attachwaitsnk_en = RESET;
	p_h_typec->input.tim_attachwaitsnk_x1ms = 1000; // 解决三星A71多次插拔有机率不充电的问题，tim_attachwaitsnk_x1ms后强制输出给手机充

	p_h_typec->input.tim_drp_try = 250; // 应智荣要求,引入DRP_TRY时间设置

	typec_init(p_h_typec);
}

void peripheral_typec_UFP_init(TC_BANK typec_handle_t *p_h_typec)
{
	p_h_typec->input.instance = TYPECA;

	p_h_typec->input.b_huawei_support = SET;
	//	p_h_typec->input.b_power_on= SET;
	p_h_typec->input.b_vbus_isexist = SET;
	//	p_h_typec->input.current_source= TYPEC_CCX_CUR_330UA;
	//	p_h_typec->input.port_type= TYPEC_PORT_DRP_TRY_SRC;
	p_h_typec->input.current_source = TYPEC_CCX_CUR_OFF;
	p_h_typec->input.port_type = TYPEC_PORT_CONSUMER;
	typec_init(p_h_typec);
}

void peripheral_typec_DRP_init(TC_BANK typec_handle_t *p_h_typec)
{
	p_h_typec->input.instance = TYPECA;

	p_h_typec->input.b_huawei_support = SET;
	//	p_h_typec->input.b_power_on= SET;
	p_h_typec->input.b_vbus_isexist = SET;
	p_h_typec->input.current_source = TYPEC_CCX_CUR_330UA;
	p_h_typec->input.port_type = TYPEC_PORT_DRP_TRY_SRC;
	//   	p_h_typec->input.current_source= TYPEC_CCX_CUR_OFF;
	//	p_h_typec->input.port_type= TYPEC_PORT_CONSUMER;
	typec_init(p_h_typec);
}

void peripheral_pd_init(void)
{
	//  	h_pd.input.b_judge_message_id= RESET;
	//	h_pd.input.b_accept_dr_swap= RESET;
	//	h_pd.input.b_accept_pr_swap= RESET;
	//	h_pd.input.b_active_send_dr_swap= RESET;
	//	h_pd.input.b_active_send_pr_swap= RESET;
	//	h_pd.input.b_judge_fixed_9v= RESET;
	//
	//	h_pd_of.input.t_src_recover = 850;	//Hard Reset的T_SRC_RECOVER 增加外部接口

	h_pd.input.b_judge_message_id = RESET;
	h_pd.input.b_accept_dr_swap = RESET;
	h_pd.input.b_accept_pr_swap = RESET;
	h_pd.input.b_active_send_dr_swap = RESET;
	h_pd.input.b_active_send_pr_swap = RESET;
	h_pd.input.b_judge_fixed_9v = RESET;

	h_pd_of.input.t_src_recover = 850; // Hard Reset的T_SRC_RECOVER 增加外部接口

	h_pd_of.input.b_pdos_ignore_emarker = false; // 为true时，不侦测emarker线，并发送完整pdos

	h_pd_of.input.t_pn_ps_rdy = 200; // tSrcReady(0~285ms)

	h_pd.input.local_source_cap_count = PDO_SOURCECAP_COUNT;
	h_pd.input.local_pps_pdo_place = PDO_SOURCECAP_PPS_POS;
	h_pd.input.local_sink_cap_count = PDO_SINKCAP_COUNT;

	M_MEMCPY_ROM2RAM(BANK1, pdo_src_list, pdo_src_list_h, sizeof(pdo_src_list)); /////4-9 新增加/////
	M_MEMCPY_ROM2RAM(PD_BANK_NUM, &h_pd.input.local_source_cap[0], pdo_sourcecap, sizeof(pdo_sourcecap));
	M_MEMCPY_ROM2RAM(PD_BANK_NUM, &h_pd.input.local_sink_cap[0], &pdo_sinkcap[0], sizeof(pdo_sinkcap));
	M_MEMCPY_ROM2RAM(PD_BANK_NUM, &h_pd.input.local_best_sink_cap[0], &pdo_sinkcap[1], sizeof(pdo_sinkcap[1]));

	//	pd_init();
	//	/** pd 通信信号调整{必须再pd_init之后}**/
	//	h_pd.input.src_pd_slow          = CTRL_SLOW_3;		/*!< SRC,信号边沿斜率 */
	//	h_pd.input.src_pd_rxvsel        = CTRL_RXVSEL_0V80;
	//	h_pd.input.src_pd_vsel          = CTRL_VSEL_1V20;
	//	fwlib_pd_electric_set(h_pd.input.src_pd_slow,h_pd.input.src_pd_rxvsel,h_pd.input.src_pd_vsel);

	pd_init();
	h_pd.input.src_pd_slow = CTRL_SLOW_3; /*!< SRC,信号边沿斜率 */
	h_pd.input.src_pd_rxvsel = CTRL_RXVSEL_0V80;
	h_pd.input.src_pd_vsel = CTRL_VSEL_1V20;
	fwlib_pd_electric_set(h_pd.input.src_pd_slow, h_pd.input.src_pd_rxvsel, h_pd.input.src_pd_vsel);

#if 0	
//	h_pd.input.b_judge_message_id= RESET;
//	h_pd.input.b_accept_dr_swap= RESET;
//	h_pd.input.b_accept_pr_swap= RESET;
//	h_pd.input.b_active_send_dr_swap= RESET;
//	h_pd.input.b_active_send_pr_swap= RESET;
//	h_pd.input.b_judge_fixed_9v= RESET;
//	
//	h_pd_of.input.t_src_recover = 850;	//Hard Reset的T_SRC_RECOVER 增加外部接口
//
//	h_pd_of.input.b_pdos_ignore_emarker = false;	//为true时，不侦测emarker线，并发送完整pdos
//	
//	h_pd_of.input.t_pn_ps_rdy = 200;		//tSrcReady(0~285ms)
//	 
//	app_power_capabilities_switch_h();
//	pd_init();
//	h_pd.input.src_pd_slow          = CTRL_SLOW_3;		/*!< SRC,信号边沿斜率 */
//	h_pd.input.src_pd_rxvsel        = CTRL_RXVSEL_0V80;	
//	h_pd.input.src_pd_vsel          = CTRL_VSEL_1V20;
//	fwlib_pd_electric_set(h_pd.input.src_pd_slow,h_pd.input.src_pd_rxvsel,h_pd.input.src_pd_vsel);
#endif
}

static void coulomb_init(void)
{
	coulomb_data.input.batt_capacity = CFG_BATT_CAPACITY;
	coulomb_data.input.batt_cells_p = CFG_BATT_CELLS_P;
	coulomb_data.input.batt_cells_s = CFG_BATT_CELLS_S;
	coulomb_data.input.vbat_cv = CFG_VBAT_CV;
	coulomb_data.input.vbat_low = CFG_VBAT_LOW;
	coulomb_data.input.vbat_alarm = CFG_VBAT_ALARM;
	coulomb_data.input.ibat_samllcurr = CFG_IBAT_SAMLLCURR;
	mod_coulomb_init();
}

void Start_data_init(void)
{
	LedData_OK = 0;
	BatCap_Value = 0;
	BatCap_Value_Be = BatCap_Value;
	//    Bat_low_Cnt=0;
	//    Err_diply=0;
	Err_diply_check_time_cnt = 0;
	CA_IN_Flage = 0;
	CB_IN_Flage = 0;
	MirB_IN_Flage = 0;
	Mode_charge_adc = 0;
	Charge_Start = 0;
	PD_curr_Pro_cnt = 0;
	USBA_curr_Pro_cnt = 0;
	//    Discharge_MinCur=1;
	//    sleepcnt=2;
	Flash_Read_Deal();
	Self_inspe_CNT = 1;
	if (Bat_low_Cnt >= 30) //// 持续测试到低电平30S
	{
		Bat_low_Cnt = 40;
		Err_diply = 1; /// 报警闪烁3次  低电报警
		Err_diply_check_time_cnt = 0;
		discharge_displed = displaytime - 10; ////报警休眠 灭灯
		LCD_display_3S_Cnt = 1;
	}
	else
	{
		Err_diply = 0;
		Err_diply_check_time_cnt = 0;
		discharge_displed = 1;
		UTX_8_data1 = 2; //// 第一次上电判断不是低电量 显示灯//
	}

	//    R_DisCharge_SmallCurCnt=55;//// 10S 后关机////
	R_DisCharge_SmallCurCnt = 0; //// 10S 后关机////
	Discharge_MinCur = 0;
	sleepcnt = 0;
	Temp_car_ST = 0;
	car_ST = 0;
	f_car_jump = 0;
	Temp.DischargeTemp_OK = 1;
	Temp.ChargeTemp_OK = 1;
	V_NO_Cha_flage = 0;
	user_flag.bit.charge_vbus_undervol_flag = 0;
	V_NO_BAT_Charge = 0;
	Bat_Protest_cnt = 0;
	bat_low_pwm_Cnt = 0;
	bat_full_pwm_do = 0;
	bat_full_pwm_Cnt = 0;
	bat_full_8hour_Cnt = 0;
	Sleep_up_shor_do = 0;
	Charge_low_power_F = 0;

	SOS_lighting_stop = 0;
	Sleep_up_close_Car_ignition = 1;
	bat_full_do_to_charge = 0;
	statusKeyFlag = 0;
	Be_statusKeyFlag = statusKeyFlag;
	Into_IAP_Flage = 0;
	WHITE_ON = 0;
	RED_ON = 0;
	SOS_LEVEL = 0;
	TYPE_CA_18W_Flage = 0;
	Bat_low_sleep_flage = 0;
	CA_rutren = 0;
	CA_Test_do_no_Slepp = 0;
	//	 Frist_start_sink=1;
	TX_time_change = 0;
	//    Sleep_up_flage=0;
	WHITE_ON = 0;
	RED_ON = 0;
	SOS_LEVEL = 0;
	TCA_EN_ON = 0;
	CAR_LEVEL = 0;
	LED_STATU = 0;
	LED_LEVEL = 0;
	f_err_ot = 0;
	Car_lighting_bright = 0;
	SYS_in_Sleep_F = 0;
	Foece_Sleep_Time_S = 0;
	Foece_Sleep_Time_Min = 0;
	Foece_Sleep_Time_Mon = 0;
#if __IF_DEBUG__
	//     PIN_SIM_TX=1;
	//	 PINC_SIM_TX=1;
#endif
	/////////////////IAP 数据初始化////
	iap_detect.data_count = 0;
	iap_detect.frame_cs_calculate = 0;
	iap_detect.jump_flag = 0;
	Charge_OCP_Flage = 0;
	Charge_OCP_cnt = 0;
	Charge_Close_En_cnt = 0;
	hour2_dis_flage = 0;
	hour2_dis_cnt = 0;
	ADD_IBAT_cnt = 0;

	USBA_EN_BK = 0;
	Charge_Bat_Start_Cnt = 1;
	//    Bat_Car_Protect_Flage=0;
	F_A1_ON = 1;
	UP_data_2402_Flage = 0;
	CA_IN_Frist_No_Soure = 0;
	Frist_Bat_Connect = 0;
	Charge_HIG_Vbat_F = 0;
	DIS_low_bater_Cnt = 0;

	Bat_low_RE_Cnt = 0;

	Car_Cont_NG_Flage = 0;

	LED_test_mode_Cnt2 = 0;
	LED_test_mode_Cnt = 0;
}
void Sleep_up_data_init(void)
{
	Err_diply = 0;
	Err_diply_check_time_cnt = 0;
	//  Discharge_MinCur=0;
	R_DisCharge_SmallCurCnt = 0;
	R_DisCharge_OutTime = 0;

	//	VBUS_out=VBUS_out_Be;
	//  V_PWM_Change(Out_PD_5V);
	//	I_PWM_Change(Out_PD_3A);
	//	Fast_Show_cnt=0;
	//	Sleep_up_flage=1;
	//	R_Charge_level=0;
	//////夹子功能//////
	Temp_car_ST = 0;
	car_ST = 0;
	f_car_jump = 0;
	//	USBA1_2_dis_fast=0;
	//  Temp.DischargeTemp_OK=1;
	Temp.ChargeTemp_OK = 1;
	//	Temp.Temp_IN=1;
	V_NO_Cha_flage = 0;
	user_flag.bit.charge_vbus_undervol_flag = 0;
	Bat_Protest_cnt = 0;
	V_NO_BAT_Charge = 0;
	bat_low_pwm_Cnt = 0;
	bat_full_pwm_do = 0;
	bat_full_pwm_Cnt = 0;
	bat_full_8hour_Cnt = 0;
	Charge_low_power_F = 0;
	Sleep_up_close_Car_ignition = 1;
	//	charge_to_sleep_close_Car_ignition=1;
	bat_full_do_to_charge = 0;
	statusKeyFlag = 0;
	Be_statusKeyFlag = statusKeyFlag;
	Into_IAP_Flage = 0;
	TYPE_CA_18W_Flage = 0;
	Bat_low_sleep_flage = 0;
	CA_rutren = 0;
	CA_Test_do_no_Slepp = 0;
	Charge_OCP_Flage = 0;
	Charge_OCP_cnt = 0;
	Charge_Close_En_cnt = 0;
	hour2_dis_flage = 0;
	hour2_dis_cnt = 0;
	ADD_IBAT_cnt = 0;
	USBA_EN_BK = 0;
	Flash_bat_Vol_Start_check = 0;
	F_A1_ON = 1;
	UP_data_2402_Flage = 0;
	CA_IN_Frist_No_Soure = 0;
	BAT_CO_OPEN_CNT = 0;
	Frist_Bat_Connect = 0;
	Charge_HIG_Vbat_F = 0;

	Car_Cont_NG_Flage = 0;

	LED_test_mode_Cnt2 = 0;
	LED_test_mode_Cnt = 0;
}
void BSP_VBat_Jud(void)
{
}
void Charge_bat_Full_check(void)
{
	uint8_t FuLL_Statu;
	if (coulomb_data.output.b_batt_full == 0)
	{
		/////////////////////充电 8小时//// 要显示充饱/////
		if (bat_full_8hour_Cnt)
		{
			bat_full_1hour_Cnt++;
			//        if(bat_full_1hour_Cnt>=36000)//// 1小时计时 完成
			if (hex_greater_than_compare(bat_full_1hour_Cnt, 36000)) //////
			{
				bat_full_1hour_Cnt = 0;
				bat_full_8hour_Cnt++;
			}
			if (bat_full_8hour_Cnt >= 9)
			{
				bat_full_8hour_Cnt = 0;

				//           BatCap_Value=5;
				BatCap_Value = 100;
				coulomb_data.output.b_batt_full = 1;
				bat_full_do_to_charge = 1;

				/////////改变充饱电压值///////
				iic_transmit_byte(0x34, Data_720334_full);
				iic_transmit_byte(0x35, Data_720335_full);
			}
		}
		//	   if((Vbat_8_date>C_CV_Full)&&(adc_convert.typec_a.adc_code_sl<BAT_Full_cuurest))
		if ((Vbat_8_date > C_CV_Full) && (hex_less_than_compare(adc_convert.typec_a.adc_code_sl, BAT_Full_cuurest)))
		{
			bat_full_cnt++;
			//          if(bat_full_cnt>=50)/////5S钟内都是充饱状态////
			if (bat_full_cnt >= 150) /////15S钟内都是充饱状态////
			{
				bat_full_cnt = 0;
				BatCap_Value++;
				if (BatCap_Value >= 99)
				{
					BatCap_Value = 100;
					coulomb_data.output.b_batt_full = 1;
					bat_full_do_to_charge = 1;
				}
			}
		}
		else
			bat_full_cnt = 0;
	}
	else
	{
		bat_full_cnt = 0;
	}
	//////////////////电池高压 大于14.1V 限制充电电流函数 //////
	Charge_HIG_Vbat_F = 0; ///// 4-9--处理取消这个功能///
						   //		    if(!Charge_HIG_Vbat_F)
						   //		  {
						   //              if(Vbat_8_date>C_CV_HIGH_BAT)
						   //			  {
						   //			    Charge_low_Vbat_CNT++;
						   //			  }
						   //			  else
						   //			  {
						   //			    Charge_low_Vbat_CNT=0;
						   //			  }
						   //		      if(Charge_low_Vbat_CNT>=10)
						   //		      {
						   //		         Charge_low_Vbat_CNT=0;
						   //		         Charge_HIG_Vbat_F=1;
						   //		      }
						   //		  }
						   //		  else
						   //		  {
						   ////		      if((NTC_Slide >= C_TempH_Charge_low_power_H_R)&&(NTC_Slide < C_TempH_Charge_low_power_L_R))
						   //               if(Vbat_8_date>C_CV_LOW_BAT_H)
						   //		      {
						   //			  Charge_low_Vbat_CNT++;
						   //			  }
						   //			  else
						   //			  {
						   //			  Charge_low_Vbat_CNT=0;
						   //			  }
						   //		      if(Charge_low_Vbat_CNT>=10)
						   //		      {
						   //		         Charge_low_Vbat_CNT=0;
						   //		         Charge_HIG_Vbat_F=0;
						   //		      }
						   //		  }
}

void Bat_Vaule_deal(void)
{
	uint8_t i;
	uint8_t R_VbatVol_Value;
	uint8_t R_VbatVol_cha;
	uint8_t R_VbatVol_Be;

	R_VbatVol_Value = Vbat_8_date;

	//////////////////第一次上电读取Flash后  不充电不放电电量再次确定处理///// 跳变两格电量就从新配置电量////
	if (Flash_bat_Vol_Start_check)
	{
		Flash_bat_Vol_Start_check++;
		//     if(Flash_bat_Vol_Start_check>=6)///6S 后开始检测电池电压
		if (Flash_bat_Vol_Start_check >= 3) /// 2S 后开始检测电池电压
		{
			if (RCR_normal_Close_data == Flash_Bat_RCR_data) /// 正常关机模式下电量更新//////
			{
				if ((COULOMB_NULL == R_SysMode_OK) && (!f_car_jump) && (CIbat_8_date < 30)) //// 不是充放电的情况
				{
					if ((Vbat_8_date <= C_Normal_VBat_Level17) && (Vbat_8_date < Flash_Bat_Vol_data)) //// 小于13.2V以下开始处理///
					{
						R_VbatVol_cha = 0;
						if (Flash_Bat_Vol_data > C_Normal_VBat_Level17)
							R_VbatVol_Be = C_Normal_VBat_Level17; ///// 大于13.2V 就按13.2做运算/////
						else
							R_VbatVol_Be = Flash_Bat_Vol_data;

						R_VbatVol_cha = R_VbatVol_Be - Vbat_8_date;

						//		      if(R_VbatVol_cha>17)/// 大于0.5V差异///
						//		      {
						////		         if(BatCap_Value>15)
						////		         BatCap_Value=BatCap_Value-15;
						//                 Power_Value_Update=5;
						//		      }
						//		      else
						//		      if(R_VbatVol_cha>=12)///大于0.3V差异///
						if (R_VbatVol_cha >= 17) /// 大于0.3V差异///
						{
							Power_Value_Update = 5;
						}
						//		      else if(R_VbatVol_cha>=8) ///大于0.2V差异//
						else if (R_VbatVol_cha >= 12) /// 大于0.3V差异//
						{
							if (BatCap_Value > 20)
								BatCap_Value = BatCap_Value - 20;
						}
						//		      else if(R_VbatVol_cha>=4) ///大于0.1V差异//
						else if (R_VbatVol_cha >= 8) /// 大于0.2V差异//
						{
							if (BatCap_Value > 5)
								BatCap_Value = BatCap_Value - 5;
						}
					}
					//			 #if __IF_DEBUG__
					//			 Sub_sim_tx(0xDD);
					//			 Sub_sim_tx(R_VbatVol_cha);
					//			 Sub_sim_tx(0xDD);
					//			 #endif
					//		  if((Vbat_8_date<=C_Normal_VBat_Level9)&&(BatCap_Value>70))//Vbat_8_date
					//		  {
					//			 Power_Value_Update=5;
					//		  }
					//		   if((Vbat_8_date>=C_Normal_VBat_Level18)&&(BatCap_Value<25))
					//		  {
					//			  Power_Value_Update=5;
					//		  }
				}
			}
			else ////非法关机的情况下//// 充电的情况下 看电池电压是否大于13V   非法关机 强制电量置一处理////
			{
				if (R_SysMode_OK == COULOMB_CHARGE) //// 充电的情况下 看电池电压是否大于13V
				{
					if (Vbat_8_date <= C_Normal_VBat_Level12) /// 小于12.9V的电压
					{
						BatCap_Value = 1;
						Bat_low_Cnt = 0;
					}
					else
						Power_Value_Update = 3;

					//				 #if __IF_DEBUG__
					//					 Sub_sim_tx(0xEE);
					//					 Sub_sim_tx(Vbat_8_date);
					//					 Sub_sim_tx(0xEE);
					//				 #endif
				}
				else //// 放电的情况下 看电池电压是否大于12.4V
				{
					if (Vbat_8_date <= C_Normal_VBat_Level7) /// 小于12.4V的电压
					{
						BatCap_Value = 1;
						Bat_low_Cnt = 0;
					}
					else
						Power_Value_Update = 5;
				}
			}
			Flash_bat_Vol_Start_check = 0;
		}

		//       if(Flash_bat_Vol_Start_check>6)
		//       {
		//         Flash_bat_Vol_Start_check=0;
		//       }
	}
	///////////////////////////////////
	if (Power_Value_Update) ////// 确定电池电量处理//////
	{
		for (i = 0; i < sizeof(Vbat_Tab); i++)
		{
			if (R_VbatVol_Value >= Vbat_Tab[i])
				break;
		}
		if (i >= sizeof(Vbat_Tab))
			i++;
		BatCap_Value_Be = VbatDisP_Tab[i];

		//    if(R_VbatVol_Value>=C_Dischagge_BatVaule_75)///4格电显示
		//       BatCap_Value_Be=80;
		//    else if(R_VbatVol_Value>=C_Dischagge_BatVaule_50)///3格电显示
		//       BatCap_Value_Be=55;
		//    else if(R_VbatVol_Value>=C_Dischagge_BatVaule_25)///2格电显示
		//       BatCap_Value_Be=30;
		//    else  if(R_VbatVol_Value>=C_Dischagge_BatVaule_10)///1格电显示
		//       BatCap_Value_Be=15;
		//    else if(R_VbatVol_Value>=C_Normal_VBat_Level4) ///	13.2
		//       BatCap_Value_Be=5;
		//    else
		//      BatCap_Value_Be=1;

		if (Power_Value_Update++ >= 7) /////前5S钟 一直在变化//
			Power_Value_Update = 0;
		BatCap_Value = BatCap_Value_Be;

		if (BatCap_Value > 0)
			Bat_low_Cnt = 0;
	}
}

void Bat_low_deal(void) ////  100ms 处理以一次////
{
	uint8_t R_VbatVol_Value;
	R_VbatVol_Value = Vbat_8_date;

	if (R_SysMode_OK == COULOMB_CHARGE)
		return;

	if (Bat_low_Cnt != 40)
	{
		if (R_VbatVol_Value <= C_VbatLow_30V)
		{
			if (f_car_jump)
			{
				Car_low_bat_cnt++;
				if (Car_low_bat_cnt >= 30) /// 持续3S 后 减少电池电压
				{
					Car_low_bat_cnt = 0;
					if (BatCap_Value <= 5)
					{
						Bat_low_Cnt = 31;
					}
					else
					{
						BatCap_Value--;
					}
				}
			}
			else
			{
				Bat_low_Cnt++;
			}
		}
		else
		{
			Bat_low_Cnt = 0;
			Car_low_bat_cnt = 0;
			if (R_VbatVol_Value <= C_VbatLow_32V) //// 电池在11.2-11.4 之间/////
			{
				Bat_low2_Cnt++;
				if (Bat_low2_Cnt >= 5)
				{
					Bat_low2_Cnt = 0;
					if (BatCap_Value > 1)
						BatCap_Value--;
				}
			}
			else
			{
				Bat_low2_Cnt = 0;
			}
		}

		if (Bat_low_Cnt >= 30) //// 持续测试到低电平30S
		{
			Bat_low_Cnt = 40;
			Err_diply = 1; /// 报警闪烁3次  低电报警
			Err_diply_check_time_cnt = 0;

			SOS_LEVEL = 0;
			WHITE_ON = 0;
			RED_ON = 0;
			//		  WHITE_PIN_OFF;
			//		  RED_PIN_OFF;
			coulomb_data.output.b_batt_full = 0;
			Discharge_MinCur = 1; //// 进入休眠/////
			BatCap_Value = 0;
			SOS_lighting_stop = 1;
			F_A1_ON = 0;
			//	      USBA_PIN_OFF;
			Mod_Dis_USBA_EN(0);
			inoutput_data.vbus_switch.sw.type_a1 = false;
			//	      Mod_Dis_USBA_EN(0);
			inoutput_data.vbus_switch.sw.type_ca = false;
			//		  inoutput_data.vbus_switch.sw.type_cb= false;
			//		  inoutput_data.vbus_switch.vbus_type_a1_delay_cnt= 0;
			inoutput_data.vbus_switch.vbus_type_b1_delay_cnt = 0;
			inoutput_data.vbus_switch.vbus_type_ca_delay_cnt = 0;
			//		  inoutput_data.vbus_switch.vbus_type_cb_delay_cnt= 0;
			discharge_displed = displaytime - 2; //// 低电休眠灭灯///
			app_power_PDO_rerest();
			TYPE_C_constraint_sleep();
		}
	}
}

#if K_Temp_Protect
void BSP_Temp_Control(void) ////  100ms 一次检测/////
{
	uint16_t NTC_Slide;
	NTC_Slide = adc_convert.type_ntc.adc_code_sl;

	if (R_SysMode_OK == COULOMB_CHARGE)
	{
		if (Temp.ChargeTemp_OK)
		{
			//		  if((NTC_Slide < C_TempH_Charge_Off_Pro)||(NTC_Slide >= C_TempL_Charge_Off_Pro))
			if ((hex_less_than_compare(NTC_Slide, C_TempH_Charge_Off_Pro)) || (hex_greater_than_compare(NTC_Slide, C_TempL_Charge_Off_Pro)))
			{
				if (Temp.Charge_TempNG_cnt++ >= 10)
				{
					Temp.Charge_TempNG_cnt = 0;
					BSP_Charge_TempNG();
				}
			}
			else
				Temp.Charge_TempNG_cnt = 0; /// Charge_TempRE_cnt
			///////////////////////////////////////温度限制充电电流函数////////
			if (!Charge_low_power_F)
			{
				//			   if((NTC_Slide < C_TempH_Charge_low_power_H)||(NTC_Slide >= C_TempH_Charge_low_power_L))
				if ((hex_less_than_compare(NTC_Slide, C_TempH_Charge_low_power_H)) || (hex_greater_than_compare(NTC_Slide, C_TempH_Charge_low_power_L)))
				{
					Charge_low_power_CNT++;
				}
				else
				{
					Charge_low_power_CNT = 0;
				}
				if (Charge_low_power_CNT >= 15)
				{
					Charge_low_power_CNT = 0;
					Charge_low_power_F = 1;
					if (plug_state_context.state.byte & _N___N___N__CAC__N___N_)
						typec_break(&h_typeca);
					CA_Test_do_no_Slepp = 1;
				}
			}
			else
			{
				//		      if((NTC_Slide >= C_TempH_Charge_low_power_H_R)&&(NTC_Slide < C_TempH_Charge_low_power_L_R))
				if ((hex_less_than_compare(NTC_Slide, C_TempH_Charge_low_power_L_R)) && (hex_greater_than_compare(NTC_Slide, C_TempH_Charge_low_power_H_R)))
				{
					Charge_low_power_CNT++;
				}
				else
				{
					Charge_low_power_CNT = 0;
				}
				if (Charge_low_power_CNT >= 10)
				{
					Charge_low_power_CNT = 0;
					Charge_low_power_F = 0;
					if (plug_state_context.state.byte & _N___N___N__CAC__N___N_)
						typec_break(&h_typeca);
					CA_Test_do_no_Slepp = 1;
				}
			}

			Temp.Charge_TempRE_cnt = 0; /// Charge_TempRE_cnt
		}
		else
		{
			//		   if((NTC_Slide >= C_TempH_Charge_On_Pro)&&(NTC_Slide < C_TempL_Charge_On_Pro))
			if ((hex_less_than_compare(NTC_Slide, C_TempL_Charge_On_Pro)) && (hex_greater_than_compare(NTC_Slide, C_TempH_Charge_On_Pro)))
			{
				//		       Temp.ChargeTemp_OK=1;
				if (Temp.Charge_TempRE_cnt++ >= 10)
				{
					Temp.Charge_TempRE_cnt = 0;
					Temp.ChargeTemp_OK = 1;
				}
			}
			else
				Temp.Charge_TempRE_cnt = 0;

			Temp.Charge_TempNG_cnt = 0;
			Charge_low_power_CNT = 0;
		}
	}
	else /////放电状态下///
	{
		if (!PIN_EN_SYS_IN)
			return;

		if (Temp.DischargeTemp_OK)
		{
			//			if((adc_convert.type_ntc.adc_code_rt < C_TempH_DisCharge_Off_Pro)||(adc_convert.type_ntc.adc_code_rt >= C_TempL_DisCharge_Off_Pro))
			if ((hex_less_than_compare(adc_convert.type_ntc.adc_code_rt, C_TempH_DisCharge_Off_Pro)) || (hex_greater_than_compare(adc_convert.type_ntc.adc_code_rt, C_TempL_DisCharge_Off_Pro)))
			{
				Temp.Discharge_TempNG_cnt++;
				//			 if(Temp.Discharge_TempNG_cnt++>=10)
				if (Temp.Discharge_TempNG_cnt >= 3)
				{
					Temp.Discharge_TempNG_cnt = 0;
					BSP_Discharge_TempNG();

					app_power_PDO_rerest();
					TYPE_C_constraint_sleep();
				}
			}
			else
				Temp.Discharge_TempNG_cnt = 0;

#if 1
			//////////////////////端口温度 大于85度 ///// 端口输出降功率45W////
			if (Port_NTC_NG_LOW_POWER_Flage)
			{
				if (hex_greater_than_compare(adc_convert.type_ntc2.adc_code_sl, Power_RE_T))
				{
					Port_NTC_NG_LOW_POWER_Cnt++;
				}
				else
					Port_NTC_NG_LOW_POWER_Cnt = 0;

				if (Port_NTC_NG_LOW_POWER_Cnt >= 20)
				{
					Port_NTC_NG_LOW_POWER_Cnt = 0;
					Port_NTC_NG_LOW_POWER_Flage = 0;

					app_power_capabilities_switch_h();
				}
			}
			else
			{
				if (hex_less_than_compare(adc_convert.type_ntc2.adc_code_sl, Power_Down_T))
				{
					Port_NTC_NG_LOW_POWER_Cnt++;
				}
				else
					Port_NTC_NG_LOW_POWER_Cnt = 0;

				if (Port_NTC_NG_LOW_POWER_Cnt >= 20)
				{
					Port_NTC_NG_LOW_POWER_Cnt = 0;
					Port_NTC_NG_LOW_POWER_Flage = 1;

					app_power_capabilities_switch_h();
				}
			}
#else
			Port_NTC_NG_LOW_POWER_Flage = 0;
#endif
		}
		else
		{
			//			if((NTC_Slide >= C_TempH_DisCharge_On_Pro)&&(NTC_Slide < C_TempL_DisCharge_On_Pro))
			if ((hex_less_than_compare(NTC_Slide, C_TempL_DisCharge_On_Pro)) && (hex_greater_than_compare(NTC_Slide, C_TempH_DisCharge_On_Pro)))
				BSP_Discharge_TempOK();
			Temp.Discharge_TempNG_cnt = 0;
		}
	}
}
//	#endif
#endif

//===============================================
//
//===============================================
void BSP_Charge_TempNG(void)
{
	Temp.ChargeTemp_OK = 0;
}

//===============================================
//
//===============================================
void BSP_Discharge_TempNG(void)
{
	Temp.DischargeTemp_OK = 0;
	LCD_display_3S_Cnt = 1;
	WHITE_ON = 0;

	//	Sleep_SYS_IN;///// 温度NG 保护处理/////
	//	USBA_PIN_OFF;
	F_A1_ON = 0;
	Mod_Dis_USBA_EN(0);
	//   WHITE_PIN_OFF;
	//  	RED_PIN_OFF;

	SOS_LEVEL = 0;
	WHITE_ON = 0;
	RED_ON = 0;

	inoutput_data.vbus_switch.sw.type_a1 = false;
	inoutput_data.vbus_switch.sw.type_ca = false;
	//    inoutput_data.vbus_switch.sw.type_cb= false;
	//    inoutput_data.vbus_switch.vbus_type_a1_delay_cnt= 0;
	inoutput_data.vbus_switch.vbus_type_b1_delay_cnt = 0;
	inoutput_data.vbus_switch.vbus_type_ca_delay_cnt = 0;
	//    inoutput_data.vbus_switch.vbus_type_cb_delay_cnt= 0;
	Discharge_MinCur = 1; ////// 过流置起 小电流休眠标志位////
	sleepcnt = 2;
	discharge_displed = displaytime; //// 放电休眠灭灯////
									 //    app_power_PDO_rerest();
									 //    TYPE_C_constraint_sleep();
}

//===============================================
//
//===============================================
void BSP_Discharge_TempOK(void)
{
	Temp.DischargeTemp_OK = 1;
}
void V_PWM_init(void) /// 初始化PWM4-V_PWM
{
	// uint8_t tempdata;
	// tempdata=0;
	// tempdata=CFGR2;
	// tempdata=tempdata&0xcf;
	// tempdata=tempdata|0x20;///// 10 PT1.2 PWM4 输出；
	// CFGR2=tempdata;
	//
	// PT12=0;
	// PT1EN2=1;///输出口
	// PT1PU2=0;/// 不开上拉电阻////
	////////////////PWM4初始化/////////////
	// TM4CON=0x00;///0001 0000
	// tempdata=CLKSEL2;
	// tempdata=tempdata&0xfc;
	// CLKSEL2=tempdata;////CPUCLK
	// tempdata=CLKDIV3;
	// tempdata=tempdata&0x8f;
	// tempdata=tempdata|0x30; ////8 分频  24/8=3M =0.333us
	// ////6:4---000 不分频 001--2分频 010--4分频 011--8分频 100--16分频 101--32分频 110--64分频 111--128分频
	// CLKDIV3=tempdata;////128 分频  24/128=187.5K  1000/187.5=5.3us
	// TM4INH=0x08;
	// TM4IN=0x34;  ////5.3us*100=530us =2K 频率 1.3us*420= 546 ---1.8K  0.333us*2100=699.3us =1,4K
	// TM4RH=0x01;
	// TM4R=0xf4;  ///5V 输出///
}
void I_PWM_init(void) /// 初始化PWM3-I_PWM
{
	// uint8_t tempdata;
	// tempdata=0;
	// tempdata=CFGR5;
	// tempdata=tempdata&0xfc;
	// tempdata=tempdata|0x03;/////11： PWM3 输出
	// CFGR5=tempdata;
	//
	// PT24=0;
	// PT2EN4=1;///输出口
	// PT2PU4=0;/// 不开上拉电阻////
	//
	////////////////PWM3初始化/////////////
	// TM3CON=0x00;///0001 0000
	// TM3CON2=0x00;
	// tempdata=CLKSEL0;
	// tempdata=tempdata&0x3f;
	// CLKSEL0=tempdata;////CPUCLK
	//
	//// tempdata=CLKDIV1;
	//// tempdata=tempdata&0x8f;
	//// tempdata=tempdata|0x70;
	//// CLKDIV1=tempdata;////128 分频  24/128=187.5K  1000/187.5=5.3us
	//
	// tempdata=CLKDIV1;
	// tempdata=tempdata&0x8f;
	//// tempdata=tempdata|0x70;//128 分频
	//// CLKDIV1=tempdata;////128 分频  24/128=187.5K  1000/187.5=5.3us
	//// tempdata=tempdata|0x60;//64 分频
	//// CLKDIV1=tempdata;////64 分频  24/64=375K  1000/375=2.66us
	//
	//
	// tempdata=tempdata|0x50;//32 分频
	// CLKDIV1=tempdata;////64 分频  24/64=375K  1000/375=2.66us
	//
	//
	//
	// TM3INH=0x01;
	// TM3IN=0x90;  ////2.66us*200=533us =2K 频率
	// TM3RH=0x00;
	// TM3R=50;///  10% PWM 输出///
}

// void V_PWM_Change(uint16_t data) ///初始化PWM4-V_PWM
//{
//  uint16_t tempdata_16;
//  tempdata_16=0;
//  tempdata_16=data;;
//
//  PT12=0;
//  PT1EN2=1;///输出口
//  PT1PU2=0;/// 不开上拉电阻////
////////////////PWM4初始化/////////////
// TM4CON=0x00;///0001 0000
// TM4INH=0x08;
// TM4IN=0x34;  ////5.3us*100=530us =2K 频率 1.3us*420= 546 ---1.8K  0.333us*2100=699.3us =1,4K
// TM4RH=tempdata_16>>8;
// TM4R=tempdata_16;///  50% PWM 输出///
// T4EN=1;
//}
// void I_PWM_Change(uint16_t data)  ///初始化PWM3-I_PWM
//{
// uint8_t I_min;
// PT24=0;
// PT2EN4=1;///输出口
// PT2PU4=0;/// 不开上拉电阻////
////////////////PWM3初始化/////////////
// TM3CON=0x00;///0001 0000
//// TM3INH=0x00;
//// TM3IN=0x64;  ////5.3us*100=530us =2K 频率
//// TM3IN=0xC8;  ////5.3us*100=530us =2K 频率0xC8
// TM3INH=0x01;
// TM3IN=0x90;
//
// I_min=data>>8;
// TM3RH=I_min;
// TM3R=data;///  50% PWM 输出///
// T3EN=1;
//}
void CA_CB_Port_Statu()
{
	uint8_t data_8bit;
	//   if(adc_convert.type_loadin.adc_code_sl>2048)
	if (hex_greater_than_compare(adc_convert.type_loadin.adc_code_sl, 2048))
		data_8bit = 255;
	else
		data_8bit = adc_convert.type_loadin.adc_code_sl >> 2; /// 除以4

	//    if(data_8bit<SYS_VBUS_V38)
	if (data_8bit > SYS_VBUS_V38)
	{
		CA_IN_Flage = 1;
	}
	else
		CA_IN_Flage = 0;

	//    if(data_8bit>CAOUT_CBOUT_TO_CAIN_CBOUT)
	//    {
	//     CA_IN_Flage=0;
	//     MirB_IN_Flage=0;
	//    }
	//    else if(data_8bit>CAIN_CBOUT_TO_CAOUT_CBIN)
	//    {
	//      CA_IN_Flage=1;
	//      MirB_IN_Flage=0;
	//    }
	//    else if(data_8bit>CAOUT_CBIN_TO_CAIN_CBIN)
	//    {
	//      CA_IN_Flage=0;
	//	  MirB_IN_Flage=1;
	//    }
	//    else
	//    {
	//      CA_IN_Flage=1;
	//      MirB_IN_Flage=1;
	//    }

	//    if((Type_ca_charge_in||MiroB_charge_in))
	if (Type_ca_charge_in)
	{
		if (VBUS_8_date <= SYS_VBUS_V40)
		{
			if (!Charge_OCP_Flage)
				Exit_Charge_Cnt++;
			//	  	  if(Exit_Charge_Cnt>=2000)
			if (hex_greater_than_compare(Exit_Charge_Cnt, 2000))
			{
				//		     Exit_Charge_Cnt=0;
				CA_IN_Flage = 0;
				MirB_IN_Flage = 0;
			}
		}
		else
			Exit_Charge_Cnt = 0;

		//	     if(MiroB_charge_in)
		//	    {
		//	      if((CA_IN_Flage)&&(!delay_Check_C_Vol))
		//	        Charge_BEN_cnt++;
		//	      else
		//	        Charge_BEN_cnt=0;
		//
		//	      if(Charge_BEN_cnt>=2)////2ms以后
		//	      {
		//	        Charge_BEN_cnt=0;
		//	        inoutput_data.vbus_switch.sw.type_b1=0;
		//	        inoutput_data.vbus_switch.vbus_type_b1_delay_cnt=0;
		//	        MIR_B_PIN_OFF;
		//	      }
		//	    }
	}
}
//===============================================
// 系统小电流检测
//===============================================
void BSP_DisCharge_SmallCur(void) /////  1S 处理一次////
{

	if (R_SysMode_OK == COULOMB_CHARGE)
		return;

	//////////////// 开机12小时强制休眠处理///////
	open_to_12hour_Cnt++;
	//   if(open_to_12hour_Cnt>=43200)
	//    if(open_to_12hour_Cnt>=20)
	if (hex_greater_than_compare(open_to_12hour_Cnt, 43200))
	{
		open_to_12hour_Cnt = 0;
		TYPE_C_constraint_sleep(); //// 强制休眠处理////
		Bat_low_sleep_flage = 1;
	}

	if (f_car_jump)
	{
		Discharge_MinCur = 0;
		R_DisCharge_SmallCurCnt = 0;
		R_DisCharge_OutTime = 0;
		TYPEC_sleep_distime_cnt = 0;
		return;
	}

	if (!inoutput_data.vbus_switch.sw.type_ca)
	{
		adc_convert.typec_a.adc_code_sl = 0;
		//   }
		//   else
		//   {
		if (!hour2_dis_flage)
		{
			//     if((adc_convert.typec_a.adc_code_sl<CA_100mA)&&(adc_convert.typea_1.adc_code_sl<USBA_100mA)&&(!WHITE_ON)&&(!RED_ON))
			//		 if((adc_convert.typea_1.adc_code_sl<USBA_100mA)&&(!WHITE_ON)&&(!RED_ON))
			if ((hex_less_than_compare(adc_convert.typea_1.adc_code_sl, USBA_100mA)) && (!WHITE_ON) && (!RED_ON))
				hour2_dis_cnt++; /////  A 90 ma ---  130ma ++  CA ---120--  170++
								 //		 if((adc_convert.typea_1.adc_code_sl>=USBA_150mA)||(WHITE_ON)||(RED_ON))
			else
				hour2_dis_cnt = 0;
			//         if(hour2_dis_cnt>=6800)
			if (hex_greater_than_compare(hour2_dis_cnt, 6800))
			//		if(hour2_dis_cnt>=120)
			{
				hour2_dis_cnt = 0;
				hour2_dis_flage = 1;
				Discharge_MinCur = 1; /////
			}
		}
	}

	//	 if((adc_convert.typec_a.adc_code_sl<Ibus_SmallCurL)&&(adc_convert.typea_1.adc_code_sl<C_DisCharge_5VSmallCurL)&&(!WHITE_ON)&&(!RED_ON))
	if ((hex_less_than_compare(adc_convert.typec_a.adc_code_sl, Ibus_SmallCurL)) &&
		(hex_less_than_compare(adc_convert.typea_1.adc_code_sl, C_DisCharge_5VSmallCurL)) && (!WHITE_ON) && (!RED_ON))
	{
		//		BSP_DisCharge_SmallCur_Deal();

		{
			//	if(Input.PDBoost)
			TYPEC_sleep_distime_cnt = 0;
			if (plug_state_context.state.byte & _N___N__CAD__N___N___N_)
			{
				TYPEC_sleep_time_cnt++;
				//		 if(TYPEC_sleep_time_cnt>=120)/// 120S
				//		 if(TYPEC_sleep_time_cnt>=7200)////  2-hour
				//				 if(TYPEC_sleep_time_cnt>=6600)////  2-hour
				if (hex_greater_than_compare(TYPEC_sleep_time_cnt, 6600))
				{
					TYPEC_sleep_time_cnt = 0;
					TYPE_C_constraint_sleep();
				}
			}
			else
			{
				R_DisCharge_SmallCurCnt++;
				//				if(R_DisCharge_SmallCurCnt<C_DisCharge_SmallCurTime)
				if (R_DisCharge_SmallCurCnt > C_DisCharge_SmallCurTime)
				{
					//				return;
					Discharge_MinCur = 1; /////
					R_DisCharge_SmallCurCnt = 0;
					sleepcnt = 3;
				}
				//		USBA_PIN_OFF;
				//		F_A1_ON=0;
			}
			//	R_DisCharge_OutTime++;
			//
			//	if(R_DisCharge_OutTime>=C_DisCharge_OutTime)
			//	{
			//		discharge_displed=displaytime;
			//	}
		}
	}
	else
	{
		////		if((adc_convert.typec_a.adc_code_sl>=Ibus_SmallCurH)||(adc_convert.typea_1.adc_code_sl>=C_DisCharge_5VSmallCurH)||(WHITE_ON)||(RED_ON))
		if ((hex_greater_than_compare(adc_convert.typec_a.adc_code_sl, Ibus_SmallCurH)) ||
			(hex_greater_than_compare(adc_convert.typea_1.adc_code_sl, C_DisCharge_5VSmallCurH)) || (WHITE_ON) || (RED_ON))
		{
			if (!hour2_dis_flage)
				Discharge_MinCur = 0;
		}
		R_DisCharge_SmallCurCnt = 0;
		R_DisCharge_OutTime = 0;

		//		 TYPEC_sleep_distime_cnt++;
		//		if(TYPEC_sleep_distime_cnt>=5)
		//		{
		//		  TYPEC_sleep_distime_cnt=0;
		//		  TYPEC_sleep_time_cnt=0;
		//		}
		//		return;
	}

	//	if(USBA_PIN)///// 如果A口打开  10S 内 没有检测到 40±30ma 电流则关闭A口///// 取消10S关闭输出功能
	//	{
	//	   if(adc_convert.typea_1.adc_code_sl<C_DisCharge_5VSmallCurL)
	//	   {
	//		 A1_closeTIME++;
	//		 if(A1_closeTIME>=A1_close_time)
	//		 {
	//			A1_closeTIME=0;
	//		    USBA_PIN_OFF;
	//		    F_A1_ON=0;
	//		 }
	//	   }
	//	   else
	//	   {
	//		if(adc_convert.typea_1.adc_code_sl>=C_DisCharge_5VSmallCurH)
	//		{
	//			A1_closeTIME=0;
	//		}
	//	   }
	//	}
	////////////////////C口降功率处理//////
	if (TYPE_CA_18W_Flage)
	{
		//	   if(adc_convert.typea_1.adc_code_sl<C_DisCharge_5VSmallCurL)
		if (hex_less_than_compare(adc_convert.typea_1.adc_code_sl, C_DisCharge_5VSmallCurL))
		{
			TYPE_CA_18W_Flage_Cnt++;
			if (TYPE_CA_18W_Flage_Cnt >= 5)
			{
				TYPE_CA_18W_Flage_Cnt = 0;
				TYPE_CA_18W_Flage = 0;
				app_power_capabilities_switch_h();
				if (plug_state_context.state.byte & _N___N__CAD__N___N___N_)
					TYPE_C_Waittime_Cnt = 1;
			}
		}
	}
	else
	{
		//	   if(adc_convert.typea_1.adc_code_sl>C_DisCharge_CA_lowpower)
		if (hex_greater_than_compare(adc_convert.typea_1.adc_code_sl, C_DisCharge_CA_lowpower))
		{
			TYPE_CA_18W_Flage_Cnt++;
			if (TYPE_CA_18W_Flage_Cnt >= 3)
			{
				TYPE_CA_18W_Flage_Cnt = 0;
				TYPE_CA_18W_Flage = 1;
				app_power_capabilities_switch_l();

				if (plug_state_context.state.byte & _N___N__CAD__N___N___N_)
					TYPE_C_Waittime_Cnt = 1;
			}
		}
	}
}
//===============================================
// 系统小电流检测处理
//===============================================
void BSP_DisCharge_SmallCur_Deal(void)
{
	//	if(Input.PDBoost)
	TYPEC_sleep_distime_cnt = 0;
	if (plug_state_context.state.byte & _N___N__CAD__N___N___N_)
	{
		TYPEC_sleep_time_cnt++;
		//		 if(TYPEC_sleep_time_cnt>=120)/// 120S
		//		 if(TYPEC_sleep_time_cnt>=7200)////  2-hour
		//         if(TYPEC_sleep_time_cnt>=6600)////  2-hour
		if (hex_greater_than_compare(TYPEC_sleep_time_cnt, 6600))
		{
			TYPEC_sleep_time_cnt = 0;
			TYPE_C_constraint_sleep();
		}
	}
	else
	{
		R_DisCharge_SmallCurCnt++;
		if (R_DisCharge_SmallCurCnt < C_DisCharge_SmallCurTime)
			return;
		Discharge_MinCur = 1; /////
		R_DisCharge_SmallCurCnt = 0;
		sleepcnt = 3;
		//		USBA_PIN_OFF;
		//		F_A1_ON=0;
	}
}
void Frist_sink_deal(void) //// 第一次上电充电处理
{
	//    if(Frist_start_sink)
	//	{
	//		Frist_start_sink++;
	////        if(Frist_start_sink>=6)
	//       if(Frist_start_sink>=8)
	//		{
	//		    Frist_start_sink=0;
	////		 	if(plug_state_context.state.byte& _N___N___N__CAC__N___N_)
	////          	if((plug_state_context.state.byte& _N___N___N__CAC__N___N_)&&(VoltFlag<=C_QC9V_Flag)&&(h_pd.output.sink_request_current))//// 5V 输入重连
	//	        if((plug_state_context.state.byte& _N___N___N__CAC__N___N_)&&(VoltFlag<C_QC9V_Flag)&&(h_pd.output.sink_request_current))//// 5V 输入重连
	//		    {
	//				typec_break(&h_typeca);
	//				CA_Test_do_no_Slepp=1;
	//
	//				CA_IN_Frist_No_Soure=1;
	//		    }
	//		}
	//	}

	if (Frist_normal_do == Frist_start_sink)
		return;

	if (Frist_Bat_Check_do == Frist_start_sink) ///// 检测电池电压处理////
	{
		Frist_Bat_Connect++;
		discharge_displed = displaytime; //// 第一次充电判断电池保护状态 灭灯////

		if (Frist_Bat_Connect >= 30) /// 延时300ms 后检测电池状态 ////
		{
			Frist_Bat_Connect = 0;
			//			if(VBAT_7201_Vaule>=1250)////电池电压打于6V 则处理
			if (hex_greater_than_compare(VBAT_7201_Vaule, 1250)) //
			{
				Frist_start_sink = Frist_Bat_normal_do;
				//			  typec_break(&h_typeca);
				//			  p_h_typec->input.b_power_on= RESET;
				Frist_Bat_100ms_Cnt = 0;
			}
			else
			{
				Frist_start_sink = Frist_Bat_Protest_do; //// 电池保护状态////
				Frist_Bat_100ms_Cnt = 0;
			}
			//			#if __IF_DEBUG__
			//			  Sub_sim_tx(0xB1);
			//			  Sub_sim_tx(Frist_start_sink);
			//			  Sub_sim_tx(0xB1);
			//			#endif
		}
	}
	else /// if(Frist_Bat_Protest_do==Frist_start_sink)//// 电池保护状态处理////
	{
		Frist_Bat_Connect++;
		if (Frist_Bat_Connect >= 10)
		{
			Frist_Bat_Connect = 0;
			Frist_Bat_100ms_Cnt++;
			if (Frist_Bat_100ms_Cnt >= 5) ////0.8S 后处理
			{
				//            Frist_start_sink=Frist_normal_do;
				if ((plug_state_context.state.byte & _N___N___N__CAC__N___N_) &&
					(VoltFlag < C_QC9V_Flag) && (1 == h_pd.output.source_cap_num)) //////(h_pd.output.sink_request_current))//// 5V 输入重连
				{
					if (Frist_Bat_normal_do == Frist_start_sink) /// Frist_start_sink
					{
						typec_break(&h_typeca);
						CA_Test_do_no_Slepp = 1;
						CA_IN_Frist_No_Soure = 1;
						//			    Bat_low_sleep_flage=1;
						Frist_start_sink = Frist_normal_do;
					}
					else ///// 电池电压处于保护状态////// Frist_Bat_Protest_do////
					{
						Frist_Bat_100ms_Cnt = 0;
						inoutput_data.vbus_switch.sw.type_ca = 0;
						discharge_displed = displaytime; ////电池保护正常 发现时电脑充电时 不亮灯
						Mod_Dis_USBA_EN(0);
						inoutput_data.vbus_switch.sw.type_a1 = false;
						F_A1_ON = 0;
						sleepcnt = 3;
					}

					// #if __IF_DEBUG__
					//   Sub_sim_tx(0xB2);
					//   Sub_sim_tx(Frist_start_sink);
					//   Sub_sim_tx(0xB2);
					// #endif
				}
				else
				{
					Frist_start_sink = Frist_normal_do;
					discharge_displed = 1;	 ///// 第一次充电1S判断设备源后 显示电量灯///
					Frist_Bat_100ms_Cnt = 0; //// 充电正常处理

					//				 if(BatCap_Value>= 75)
					//				{
					//					mod_display_led(p_led_1, true);
					//					mod_display_led(p_led_2, true);
					//					mod_display_led(p_led_3, true);
					//					mod_display_led(p_led_4, true);
					//				}
					//				else if(BatCap_Value>= 50)
					//				{
					//					mod_display_led(p_led_1, true);
					//					mod_display_led(p_led_2, true);
					//					mod_display_led(p_led_3, true);
					//				}
					//				else if(BatCap_Value>= 25)
					//				{
					//					mod_display_led(p_led_1, true);
					//					mod_display_led(p_led_2, true);
					//				}
					//				else
					//				{
					//					mod_display_led(p_led_1, true);
					//				}
				}

				//		    #if __IF_DEBUG__
				////			  Sub_sim_tx(0xDD);
				//////			  Sub_sim_tx(Frist_Bat_100ms_Cnt);
				////			  Sub_sim_tx(h_pd.output.source_cap_num);
				//////			  Sub_sim_tx(0xDD);
				//			#endif
			}
		}
	}
}

void Vin_vol_charge_deal(void) //// 输入电压充电电流处理///100ms 一次处理 ///
{
	uint8_t R_VbusVol_Value;
	uint16_t ocp_tempI;
	uint8_t ocp_temp_cnt;
	R_VbusVol_Value = VBUS_8_date;

	///////////////充电电流过流处理////////////
	if (!Charge_OCP_Flage)
	{
		if (MiroB_charge_in) ////  B口充电////
		{
			ocp_tempI = Port_cuurest_MA2700;
		}
		else
			ocp_tempI = Port_cuurest_MA3900;

		//      if(VoltFlag>C_QC15V_Flag)
		////    ocp_tempI=Port_cuurest_MA3100;///// 20V输入充电3.1A保护////
		//      ocp_tempI=Port_cuurest_MA3900;///// 20V输入充电3.1A保护////

		//       if(adc_convert.typec_a.adc_code_sl>=ocp_tempI)
		if (hex_greater_than_compare(adc_convert.typec_a.adc_code_sl, ocp_tempI))
		{
			Charge_OCP_cnt++;
			if (Charge_OCP_cnt >= 50)
			{
				Charge_OCP_cnt = 0;
				Charge_OCP_Flage = 1;
			}
		}
		else
			Charge_OCP_cnt = 0;

		//	  if(R_VbusVol_Value<=SYS_VBUS_V43)
		if (R_VbusVol_Value <= SYS_VBUS_V40)
		{
			Charge_Close_En_cnt++;
			//	     Charge_Close_En_cnt=0;

			if (MiroB_charge_in)
				ocp_temp_cnt = 5;
			else
				ocp_temp_cnt = 50;

			if (Charge_Close_En_cnt >= ocp_temp_cnt)
			{
				Charge_Close_En_cnt = 0;
				Charge_OCP_Flage = 1;
			}
		}
		else
			Charge_Close_En_cnt = 0;
	}
////// 锂电充电保护板保护/////
#if K_BAT_Protect
	//      POWER_OC_EN_inti;
	if (Charge_Bat_Start_Cnt)
	{
		Charge_Bat_Start_Cnt++;
		//         if(Charge_Bat_Start_Cnt>=200)
		if (Charge_Bat_Start_Cnt >= 20)
			Charge_Bat_Start_Cnt = 0;
	}

	//       if((Bat_Protest_cnt)&&(!Charge_Bat_Start_Cnt))
	//       {
	//          Bat_Protest_cnt++;
	//        if(Bat_Protest_cnt>=50)
	//        {
	//         Bat_Protest_cnt=1;
	//        }
	//       }

	if (!V_NO_BAT_Charge)
	{
		//    if(!POWER_OC)
		//    {
		//       if(!Charge_Bat_Start_Cnt)
		// 	   V_NO_BAT_Cnt++;
		//    }
		//    else
		// 	 V_NO_BAT_Cnt=0;

		//		   if(V_NO_BAT_Cnt>=20)///// 2S 检测一次 是不是电池保护
		if (V_NO_BAT_Cnt >= 30) ///// 3S 检测一次 是不是电池保护
		{
			V_NO_BAT_Cnt = 0;
			V_NO_BAT_Charge = 1;

			if (VoltFlag >= C_QC5V_Flag)
				pd_send_request(1); //// 重新申请5V ////

			if (0 == Bat_Protest_cnt)
			{
				Bat_Protest_cnt = 1;
			}
			//			  Bat_Protest_cnt++;
			//			 if(Bat_Protest_cnt>10)
			//			  Bat_Protest_cnt=10;
		}
	}
	else
	{
		//    if(POWER_OC)
		//    {
		// 	 V_NO_BAT_Cnt++;
		//    }
		//    else
		// 	 V_NO_BAT_Cnt=0;
		if (V_NO_BAT_Cnt >= 5) //// 0.5S 解除锂电充电保护
		{
			V_NO_BAT_Cnt = 0;
			V_NO_BAT_Charge = 0;
		}
	}
#endif
	// 充电电压保护设定///////////
	//	if(!V_NO_Cha_flage  && !(user_flag.bit.charge_vbus_undervol_flag))
	if (!V_NO_Cha_flage)
	{
		//		if(MiroB_charge_in)
		//		{
		//             if(((R_VbusVol_Value<=SYS_VBUS_V45)&&(adc_convert.typec_a.adc_code_sl<Port_cuurest_MA200))||(R_VbusVol_Value>=SYS_VBUS_V65))////小于4.5V 大于6.5V
		////            if(R_VbusVol_Value>=SYS_VBUS_V65)////小于3.9V 大于 10.2V
		//			{
		//
		//			  V_NO_Charge++;
		//			}
		//			 else
		//			  V_NO_Charge=0;
		//		}
		//		else
		{
			//           	if(((R_VbusVol_Value<=SYS_VBUS_V45)&&(adc_convert.typec_a.adc_code_sl<Port_cuurest_MA200))||
			//           	((R_VbusVol_Value>=SYS_VBUS_V150)&&(h_pd.output.source_cap_cur_capacity==0))|| /// 非PD 15V以上充电////
			//           	(R_VbusVol_Value>=SYS_VBUS_V220))//// PD 22V以上充电////
			if (((R_VbusVol_Value <= SYS_VBUS_V45) && (hex_less_than_compare(adc_convert.typec_a.adc_code_sl, Port_cuurest_MA200))) ||
				((R_VbusVol_Value >= SYS_VBUS_V150) && (h_pd.output.source_cap_cur_capacity == 0)) || /// 非PD 15V以上充电////
				(R_VbusVol_Value >= SYS_VBUS_V220))													  //// PD 22V以上充电////
			{
				V_NO_Charge++;
			}
			else
				V_NO_Charge = 0;
		}
		if (V_NO_Charge >= 10)
		{
			V_NO_Charge = 0;
			if ((R_VbusVol_Value <= SYS_VBUS_V45) && (hex_less_than_compare(adc_convert.typec_a.adc_code_sl, Port_cuurest_MA200)))
			{
				user_flag.bit.charge_vbus_undervol_flag = 1;
			}
			else
			{
				user_flag.bit.charge_vbus_undervol_flag = 0;
			}
			V_NO_Cha_flage = 1;
		}
		// if(R_VbusVol_Value <= SYS_VBUS_V41)
		// {
		// 	user_flag.bit.charge_vbus_undervol_flag = 1;
		// }
		// else
		// {
		// 	user_flag.bit.charge_vbus_undervol_flag = 0;

		// }
	}
	else
	{
		//	 	if(MiroB_charge_in)
		//		{
		//          if(((R_VbusVol_Value>=SYS_VBUS_V48)&&(R_VbusVol_Value<=SYS_VBUS_V57)))////大于4.1V 小于5.7V
		//		  {
		//			 V_NO_Charge++;
		//		  }
		//		 else
		//		 V_NO_Charge=0;
		//		}
		//		else
		{
			//       if((R_VbusVol_Value>=SYS_VBUS_V48)&&(R_VbusVol_Value<=SYS_VBUS_V145))
			if (h_pd.output.source_cap_cur_capacity == 0)
			{
				//          if((R_VbusVol_Value>=SYS_VBUS_V48)&&(R_VbusVol_Value<=SYS_VBUS_V145))
				if ((R_VbusVol_Value >= SYS_VBUS_V48) && (R_VbusVol_Value <= SYS_VBUS_V142))
				{
					V_NO_Charge++;
				}
				else
					V_NO_Charge = 0;
			}
			else
			{
				if ((R_VbusVol_Value >= SYS_VBUS_V48) && (R_VbusVol_Value <= SYS_VBUS_V210))
				{
					V_NO_Charge++;
				}
				else
					V_NO_Charge = 0;
			}
		}
		if (V_NO_Charge >= 10)
		{
			V_NO_Charge = 0;
			V_NO_Cha_flage = 0;
			user_flag.bit.charge_vbus_undervol_flag = 0;
		}
	}
}
void Car_statu_deal(void) //// 夹子汽车点火系统处理/////100ms 处理一次
{
	if (car_ST != 0)
	{
		if ((car_ST == 3) || (car_ST == 5) || (car_ST == 6)) //// 点火成功
		{
			CAR_LEVEL = 3;
		}
		else if (car_ST == 2)
		{
			CAR_LEVEL = 2;
		}
		else
		{
			//      if(car_ST==1)
			CAR_LEVEL = 1;
			//      else
		}
	}
	else
		CAR_LEVEL = 0;
}
void Miro_in_deal(void) //// 10ms 一次////
{
	if (Type_ca_charge_in)
		return;
	if (Type_cb_charge_in == 0)
	{
		MiroB_dis_Cnt = 0;
		if (MirB_IN_Flage)
		{
			if (!Type_ca_charge_in) ////CA 没有输入
				MiroB_charge_Cnt++;
			if (MiroB_charge_Cnt >= 100) /// 1S 后
			{
				Type_cb_charge_in = 1;
				mod_queue_send(PLUG_B1C_IN); //// MiroB 插入/////
				delay_Check_C_Vol = Type_cb_charge_in;
			}
		}
	}
	else ///// VBUS 电压低并且没有电流时/////
	{
		MiroB_charge_Cnt = 0;
		if (Charge_OCP_Flage)
		{
			if (!MirB_IN_Flage)
				MiroB_dis_Cnt++;
			else
				MiroB_dis_Cnt = 0;
		}
		else
		{
			// if((adc_convert.type_vbus.adc_code_sl<=VBUS_4V0)&&(adc_convert.typec_a.adc_code_sl<=IBUS_1A0))
			if ((VBUS_8_date <= SYS_VBUS_V40) && (adc_convert.typec_a.adc_code_sl <= IBUS_1A0))
				MiroB_dis_Cnt++;
			else
				MiroB_dis_Cnt = 0;
		}
		//     if(MiroB_dis_Cnt>=250)////1S后退出充电
		//	   if(MiroB_dis_Cnt>=50)////0.5S后退出充电
		if (MiroB_dis_Cnt >= 80) ////0.8S后退出充电
		{
			MiroB_dis_Cnt = 0;
			Type_cb_charge_in = 0;
			mod_queue_send(PLUG_B1C_OUT);
			delay_Check_C_Vol = Type_cb_charge_in;
		}
	}
	MiroB_charge_in = Type_cb_charge_in;

	if (delay_Check_C_Vol)
	{
		delay_Check_C_Vol++;
		if (delay_Check_C_Vol >= 50) /// 0.5S
		{
			delay_Check_C_Vol = 0;
		}
	}
}
//==============================================================
//	模拟串口通信
//==============================================================
#if __IF_DEBUG__
void Sub_DEL_BAUD(void)
{						// 波特率=4M/(8+n)
	asm("goto	$+1	"); // n=9  设置230400,实际235294（误差+2.12%）
	asm("nop		"); //

	asm("goto	$+1	");
	asm("goto	$+1	");
	asm("goto	$+1	");
	asm("goto	$+1	");
	asm("goto	$+1	");

	asm("goto	$+1	");
	asm("goto	$+1	");
	asm("goto	$+1	");
	asm("goto	$+1	");
	asm("goto	$+1	");
	asm("nop		"); //
}
#endif
void Sub_sim_tx(unsigned char data)
{
#if __IF_DEBUG__
	R_data_tx = data;
	GIE = 0;
	PIN_SIM_TX = 1;
	PINC_SIM_TX = 1;
	Sub_DEL_BAUD();
	R_count_tx = 8;
	GIE = 0;
	PIN_SIM_TX = 0;
	asm("goto	$+1	");
	asm("nop		");
	// JP_TX_LOOP:
	Sub_DEL_BAUD();
	asm("rrf	_R_data_tx,1");
	asm("btfss	_STATUS,1"); // bit1:C
	asm("goto	$+6");		 // goto	JP_TX_0;
	asm("nop");
	// JP_TX_1:
	PIN_SIM_TX = 1;
	asm("decfsz	_R_count_tx,1");
	asm("goto	$-7	"); // goto	JP_TX_LOOP;
	asm("goto	$+5	"); // goto	JP_TX_END;
	// JP_TX_0:
	PIN_SIM_TX = 0;
	asm("decfsz	_R_count_tx,1");
	asm("goto	$-11	"); // goto	JP_TX_LOOP;
	asm("goto	$+1	");		// goto	JP_TX_END;
	// JP_TX_END:
	Sub_DEL_BAUD();
	asm("nop");
	asm("goto	$+1	");
	PIN_SIM_TX = 1;
	GIE = 1; // 开中断
	asm("nop");
	Sub_DEL_BAUD();
	asm("goto	$+1	");
	asm("goto	$+1	");
	asm("goto	$+1	");
	PINC_SIM_TX = 0;
#endif
}
void Sinck_in9V_max(void)
{
	M_MEMCPY_ROM2RAM(PD_BANK_NUM, &h_pd.input.local_sink_cap[0], &pdo_sinkcap_9[0], sizeof(pdo_sinkcap_9));
	M_MEMCPY_ROM2RAM(PD_BANK_NUM, &h_pd.input.local_best_sink_cap[0], &pdo_sinkcap_9[1], sizeof(pdo_sinkcap_9[1]));
}
void Sinck_in_recover_max(void)
{
	M_MEMCPY_ROM2RAM(PD_BANK_NUM, &h_pd.input.local_sink_cap[0], &pdo_sinkcap[0], sizeof(pdo_sinkcap));
	M_MEMCPY_ROM2RAM(PD_BANK_NUM, &h_pd.input.local_best_sink_cap[0], &pdo_sinkcap[1], sizeof(pdo_sinkcap[1]));
}

void Lighting_to_SOS_Dispose(void)
{
	//    if(WHITE_ON)
	//   {
	//       statusKeyFlag=SOS_LEVEL;
	//     if( Be_statusKeyFlag!=statusKeyFlag)//// 状态改变重新清标志位/////
	//     {
	//        Be_statusKeyFlag=statusKeyFlag;
	//        flash_count=0;
	// 	   sos_count=0;
	// 	   sos_state=1;
	//     }
	//   	if(statusKeyFlag==0)
	//   	{
	// //  	WHITE_PIN_ON;
	//   	    LED_PIN_on_off_Deal(1);
	//   	}
	//     /////////////////////// 频闪 模式1/////////
	// 	else if(statusKeyFlag==1)
	// 	{
	// 	    flash_count++;
	// 		if(flash_count>=7)////80ms 频闪////
	// 		{
	// 			  flash_count=0;
	// 			{
	// //			   WHITE_PIN=~WHITE_PIN;
	// 			   LED_PIN_qu_fan_Deal();
	// 			}
	// 		}
	// 	}
	// 	/////////////////////////////////// SOS 模式1/////////
	// 	else
	// 	{
	// 	    flash_count++;
	// 		if((flash_count>=20)&&(sos_state==1))//////////////// statu 1
	// 		{
	// 			flash_count=0;
	// 			sos_count++;
	// 			{
	// //			   WHITE_PIN=~WHITE_PIN;
	// 			   LED_PIN_qu_fan_Deal();
	// 			}
	// 		    if(sos_count>=6)
	// 		    {
	// 			   sos_count=0;
	// 			   sos_state++;
	// //			   WHITE_PIN_OFF;
	//                 LED_PIN_on_off_Deal(0);
	// 		    }
	// 		}
	// 		if((flash_count>=60)&&(sos_state==2))//////statu 2
	// 		{
	// 			flash_count=0;
	// 			sos_count++;
	// 		   {
	// //			 WHITE_PIN=~WHITE_PIN;
	//              LED_PIN_qu_fan_Deal();
	// 		   }
	// 		    if(sos_count>=7)
	// 		   {
	// 			sos_count=0;
	// 			sos_state=3;
	// 		   }
	// 		}
	// 		if((flash_count>=20)&&(sos_state==3))////statu 3
	// 		{
	// 			flash_count=0;
	// 			sos_count++;
	// 		   {
	// //			 WHITE_PIN=~WHITE_PIN;
	// 			 LED_PIN_qu_fan_Deal();
	// 		   }
	// 		   if(sos_count>=5)
	// 		   {
	// 			sos_count=0;
	// 			sos_state=4;
	// //			WHITE_PIN_OFF;
	// 			 LED_PIN_on_off_Deal(0);
	// 		   }
	// 		}
	// 		if((flash_count>=200)&&(sos_state==4))////statu 4
	// 		{
	// 			flash_count=0;
	// 			sos_count=0;
	// 			sos_state=1;
	// 		}
	// 	}
	//   }
	//   else
	//   {
	//     WHITE_PIN_OFF;
	// //    LED2_PIN_OFF;
	// //    LED3_PIN_OFF
	//   }
}
void IAP_inti_deal()
{
	uint8_t tempdata1;
	uint8_t tempdata2;
	//	CFGR6 = 0b00101000;					//PT3.1复用为UART TX，PT3.2复用为UART RX
	//	PT3PU = 0b00000100;					//使能PT3.2内部30K上拉电阻
	//	PT1EN5 = 1;							//PT1.5设为输出口

#if __DMPM__EN
	/** 初始化多协议**/ ////关闭多协议/////
	multi_protocol_init();
	//	multi_protocol.channel = CHANEL_DMDPA;
	multi_protocol.channel = CHANEL_NULL;				 /// CHL_MU_NULL CHANEL_NULL
	multi_protocol.control.fastchg_protocol_scan_en = 0; // multi_protocol.control.fastchg_protocol_scan_en
	multi_protocol.control.GPIO_multiplex_DMDPA = 0;
#endif

	tempdata1 = CFGR6;
	tempdata1 = tempdata1 & 0xcf;
	tempdata1 = tempdata1 | 0x20; ////，PT3.2复用为UART RX
	CFGR6 = tempdata1;

	tempdata1 = PT3PU;
	tempdata1 = tempdata1 | 0x04; ////PT3.2内部30K上拉电阻
	PT3PU = tempdata1;

	PT3EN1 = 0;
	//    PT3PU1=0;
	PT3PU1 = 1;

	CLKSEL1 = 0b00000000; // UART时钟源选择SYSCLK=24MHz
	CLKDIV2 = 0b00010000; // 时钟分频系数设为4
	UR0_BRR0 = 52;
	UR0_BRR1 = 1;		  // 波特率设为115200
	UR0_CR1 = 0b00001001; // 使能UART模块及接收功能
	UR0_INTF = 0b00000000;
	UR0_INTE = 0b00000100; // 使能接收非空中断

	GIE = 1;
}

void IAP_inti_deal_dis()
{
	uint8_t tempdata1;
	uint8_t tempdata2;

	tempdata1 = CFGR6;
	tempdata1 = tempdata1 & 0xcf;
	//    tempdata1=tempdata1|0x20;////，PT3.2复用为普通IO口
	CFGR6 = tempdata1;

	tempdata1 = PT3PU;
	tempdata1 = tempdata1 & 0xfb; ////取消PT3.2内部30K上拉电阻
	PT3PU = tempdata1;

	CLKSEL1 = 0b00000000; // UART时钟源选择SYSCLK=24MHz
	CLKDIV2 = 0b00010000; // 时钟分频系数设为4
	UR0_BRR0 = 52;
	UR0_BRR1 = 1; // 波特率设为115200
	//	UR0_CR1 = 0b00001001;				//使能UART模块及接收功能
	UR0_CR1 = 0b0000000; // 关闭UART模块及接收功能
	UR0_INTF = 0b00000000;
	UR0_INTE = 0b00000100; // 使能接收非空中断

	//	 #if __IF_DEBUG__
	//     PIN_SIM_TX=1;
	//	 PINC_SIM_TX=1;
	//     #endif

#if __DMPM__EN
	/** 初始化多协议**/ ////关闭多协议/////
	multi_protocol_init();

	multi_protocol.channel = CHANEL_NULL;				 ////  详情见附件 F10功能测试CHL_MU_NULL  CHANEL_NULL
														 //	multi_protocol.channel = CHANEL_DMDPA;
	multi_protocol.control.fastchg_protocol_scan_en = 0; // multi_protocol.control.fastchg_protocol_scan_en
	//	multi_protocol.control.GPIO_multiplex_DMDPA = 1;
	multi_protocol.control.GPIO_multiplex_DMDPA = 0; /// 取消C口 D+D_快充功能
	multi_protocol.control.GPIO_multiplex_DMDPB = 0;
	multi_protocol.control.GPIO_multiplex_DMDPC = 0;
	//	#if UARTX_EN //UARTX_EN
	//	multi_protocol.control.GPIO_multiplex_DMDPC = 0;
	//	#endif
	//	multi_protocol.control.GPIO_multiplex_DMDPD = 1;
	multi_protocol.control.GPIO_multiplex_DMDPD = 0;

	/** QC2.0**/
	multi_protocol.control.qc_protocol_out_en = 0; /////multi_protocol.control.qc_protocol_out_en
	multi_protocol.control.qc_protocol_out_12v_en = 0;
	multi_protocol.control.qc_protocol_in_en = 0;
	//	multi_protocol.control.qc_protocol_in_num = QC_IN_NUM_12V;
	multi_protocol.control.qc_protocol_in_num = QC_IN_NUM_9V;

	/** QC3.0**/
	multi_protocol.control.qc30_protocol_out_en = 0;
	multi_protocol.control.qc30_protocol_3v6_en = 0;
	multi_protocol.control.qc30_protocol_in_en = 0;
	//	multi_protocol.control.qc30_protocol_in_vol = 0xF0;
	multi_protocol.control.qc30_protocol_in_vol = 0x0168; // 9V  360---25mV

	/** FCP**/
	multi_protocol.control.fcp_protocol_out_en = 0;
	multi_protocol.control.fcp_protocol_out_12v_en = 0;
	//	multi_protocol.control.fcp_protocol_in_en = 1;
	multi_protocol.control.fcp_protocol_in_en = 0; // 关掉FCP输入
	//	multi_protocol.control.fcp_protocol_in_num = FCP_IN_NUM_12V;
	multi_protocol.control.fcp_protocol_in_num = FCP_IN_NUM_9V;

	/** SCP**/
	multi_protocol.control.scp_protocol_out_en = 1;
	multi_protocol.control.scp_vbus_compensate = SCP_VBUS_COMPENSATE;

	/** AFC**/
	multi_protocol.control.afc_protocol_out_en = 0;
	multi_protocol.control.afc_protocol_out_12v_en = 0;
	//	multi_protocol.control.afc_protocol_in_en = 1;
	multi_protocol.control.afc_protocol_in_en = 0; // 关掉AFC输入
	multi_protocol.control.afc_protocol_in_num = AFC_IN_NUM_12V;

	/** VOOC**/
	multi_protocol.control.vooc_protocol_out_en = 0;
	multi_protocol.control.vooc_protocol_in_en = 0;
	multi_protocol.control.vooc40_protocol_out_en = 0;
	multi_protocol.control.vooc40_protocol_in_en = 0;
	multi_protocol.control.svooc_protocol_out_en = 0;
	multi_protocol.control.svooc_protocol_in_en = 0;
	multi_protocol.control.typea_vooc_cable_det_en = 0;
	multi_protocol.control.vooc_impedance_compensate = VOOC_IMPEDANCE_COMPENSATE;

	multi_protocol.dir = DIR_DISCHARGE;

#endif
}

void iap_signal_detect(unsigned char receive_data)
{
	switch (iap_detect.data_count)
	{
	case 0:
		if (receive_data != 0x55)
		{
			return;
		}
		iap_detect.frame_cs_calculate = 0;
		break;
	case 1:
		if (receive_data != 0x01)
		{
			iap_detect.data_count = 0;
			return;
		}
		break;
	case 2:
		if (receive_data != 0x21)
		{
			iap_detect.data_count = 0;
			return;
		}
		break;
	case 3:
		break;
	case 4:
		if (receive_data != iap_detect.frame_cs_calculate)
		{
			iap_detect.data_count = 0;
		}
		else
		{
			iap_detect.jump_flag = 1;
		}
		return;
		break;
	default:
		iap_detect.data_count = 0;
		return;
	}
	iap_detect.data_count++;
	iap_detect.frame_cs_calculate += receive_data;
}

void app_power_capabilities_switch_h(void)
{
	h_pd.input.local_source_cap_count = PDO_SOURCECAP_COUNT;

	if (!Port_NTC_NG_LOW_POWER_Flage)
		M_MEMCPY_ROM2RAM(PD_BANK_NUM, &h_pd.input.local_source_cap[0], pdo_sourcecap, sizeof(pdo_sourcecap));
	else
		M_MEMCPY_ROM2RAM(PD_BANK_NUM, &h_pd.input.local_source_cap[0], pdo_sourcecap_18, sizeof(pdo_sourcecap_18));

	if (plug_state_context.state.byte & _N___N__CAD__N___N___N_)
	{
		typec_break(&h_typeca);
	}
}

void app_power_capabilities_switch_h_1(void)
{
	h_pd.input.local_source_cap_count = PDO_SOURCECAP_COUNT;

	if (!Port_NTC_NG_LOW_POWER_Flage)
		M_MEMCPY_ROM2RAM(PD_BANK_NUM, &h_pd.input.local_source_cap[0], pdo_sourcecap_45, sizeof(pdo_sourcecap_45));
	else
		M_MEMCPY_ROM2RAM(PD_BANK_NUM, &h_pd.input.local_source_cap[0], pdo_sourcecap_18, sizeof(pdo_sourcecap_18));

	if (plug_state_context.state.byte & _N___N__CAD__N___N___N_)
	{
		typec_break(&h_typeca);
	}
}

void app_power_capabilities_switch_h_2(void)
{
	h_pd.input.local_source_cap_count = PDO_SOURCECAP_COUNT;

	if (!Port_NTC_NG_LOW_POWER_Flage)
		M_MEMCPY_ROM2RAM(PD_BANK_NUM, &h_pd.input.local_source_cap[0], pdo_sourcecap_30, sizeof(pdo_sourcecap_30));
	else
		M_MEMCPY_ROM2RAM(PD_BANK_NUM, &h_pd.input.local_source_cap[0], pdo_sourcecap_18, sizeof(pdo_sourcecap_18));

	if (plug_state_context.state.byte & _N___N__CAD__N___N___N_)
	{
		typec_break(&h_typeca);
	}
}

void app_power_capabilities_switch_l(void)
{
	h_pd.input.local_source_cap_count = PDO_SOURCECAP_COUNT_L;
	M_MEMCPY_ROM2RAM(PD_BANK_NUM, &h_pd.input.local_source_cap[0], pdo_sourcecap_18, sizeof(pdo_sourcecap_18));

	if (plug_state_context.state.byte & _N___N__CAD__N___N___N_)
	{
		typec_break(&h_typeca);
	}
}

// void app_charge_power_switch_0(void)
// {

// 	M_MEMCPY_ROM2RAM(PD_BANK_NUM, &h_pd.input.local_sink_cap[0], &pdo_sinkcap[0], sizeof(pdo_sinkcap));
//     if(plug_state_context.state.byte& _N___N___N__CAC__N___N_)
//    	{
//          typec_break(&h_typeca);
//    	}
// }

// void app_charge_power_switch_1(void)
// {

// 	M_MEMCPY_ROM2RAM(PD_BANK_NUM, &h_pd.input.local_sink_cap[0], &pdo_sinkcap_1[0], sizeof(pdo_sinkcap));
//     if(plug_state_context.state.byte& _N___N___N__CAC__N___N_)
//    	{
//          typec_break(&h_typeca);
//    	}
// }

// void app_charge_power_switch_2(void)
// {

// 	M_MEMCPY_ROM2RAM(PD_BANK_NUM, &h_pd.input.local_sink_cap[0], &pdo_sinkcap_2[0], sizeof(pdo_sinkcap));
//     if(plug_state_context.state.byte& _N___N___N__CAC__N___N_)
//    	{
//          typec_break(&h_typeca);
//    	}
// }

// void app_charge_power_switch_3(void)
// {

// 	M_MEMCPY_ROM2RAM(PD_BANK_NUM, &h_pd.input.local_sink_cap[0], &pdo_sinkcap_3[0], sizeof(pdo_sinkcap));
//     if(plug_state_context.state.byte& _N___N___N__CAC__N___N_)
//    	{
//          typec_break(&h_typeca);
//    	}
// }

void app_power_PDO_rerest(void)
{
	TYPE_CA_18W_Flage = 0;
	h_pd.input.local_source_cap_count = PDO_SOURCECAP_COUNT;
	M_MEMCPY_ROM2RAM(PD_BANK_NUM, &h_pd.input.local_source_cap[0], pdo_sourcecap, sizeof(pdo_sourcecap));
}

void TYPE_C_constraint_sleep(void)
{
	if (plug_state_context.state.byte & _N___N__CAD__N___N___N_)
	{
		typec_break(&h_typeca);
		peripheral_typec_UFP_init(&h_typeca);
		Bat_low_sleep_flage = 1;
	}
}

uint16_t BSP_I2C_VbatCheck(void)
{
	uint16_t Readdata = 0;
	// 查询BAT
	iic_transmit_byte(0x10, 0x10);
	Readdata = iic_receive_byte(0x11);
	Readdata <<= 4;
	Readdata |= iic_receive_byte(0x12);

	return Readdata;
}

void BSP_I2C_7203_Data(void)
{
	uint16_t Readdata = 0;
	//    uint16_t Mach_Vbat;
	uint8_t Readdata2 = 0;
	switch (SW7203_Data_Cnt) ///
	{
	case 0:
		iic_transmit_byte(0x10, 0xC1); // vbus电压
		break;
	case 1:
		Readdata = 0;
		Readdata = iic_receive_byte(0x11); // vbus电压
		Readdata <<= 4;
		Readdata2 = iic_receive_byte(0x12); //// 7.5/step
		Readdata2 = Readdata2 & 0x0f;
		Readdata = Readdata2 + Readdata;
		//			UTX_16_data1=Readdata;
		VBUS_8_date = Readdata >> 4;

		multi_protocol.input.vbus_vol = Readdata * 3;
		multi_protocol.input.vbus_vol = multi_protocol.input.vbus_vol / 10;
		iic_transmit_byte(0x10, 0xC0); // vbat电压
		break;
	case 2:
		Readdata = 0;
		Readdata = iic_receive_byte(0x11); // vbat电压
		Readdata <<= 4;
		//	        Readdata |= iic_receive_byte(0x12);//// 7.5/step
		Readdata2 = iic_receive_byte(0x12); //// 7.5/step
		Readdata2 = Readdata2 & 0x0f;
		Readdata = Readdata2 + Readdata;
		VBAT_7201_Vaule = Readdata;

		//	        Mach_Vbat=Readdata;
		//            VBAT_7201_Vaule=Readdata;

		//	        if(Readdata>=2293)//// 17V s以上都是显示255
		if (hex_greater_than_compare(Readdata, 2293)) //// 17V s以上都是显示255
		{
			Readdata = 2293;
			Vbat_8_date = 255;
		}
		else
		{
			//			  if(Readdata>=1333)
			if (hex_greater_than_compare(Readdata, 1333)) //	10V 以上
				Readdata = Readdata - 1333;
			else
				Readdata = 0; //// 10V 以下置零

			Readdata = Readdata >> 2;

			//	    	 if(Readdata>=255)
			//	    	   Vbat_8_date=255;
			//	    	 else
			Vbat_8_date = Readdata;
		}

		if (R_SysMode_OK == COULOMB_CHARGE)
			iic_transmit_byte(0x10, 0xC4); ////充电电流IBAT
		else
			iic_transmit_byte(0x10, 0xC6); ////放电电流IBAT

		break;
	case 3:
		Readdata = 0;
		Readdata = iic_receive_byte(0x11);
		Readdata <<= 4;
		//	        Readdata |= iic_receive_byte(0x12);///// 5ma 一个值 100ma--20
		Readdata2 = iic_receive_byte(0x12); //// 7.5/step
		Readdata2 = Readdata2 & 0x0f;
		Readdata = Readdata2 + Readdata;

		Readdata = Readdata >> 2;					 ////  100ma--5 20ma/step
													 //		 	if(Readdata>=250)/// 最大5A
		if (hex_greater_than_compare(Readdata, 250)) //
			Readdata = 250;
		CIbat_8_date = Readdata; ////最大5A输入输出电池端  20ma/step

#if IBUS_Check
		if (R_SysMode_OK == COULOMB_CHARGE)
			iic_transmit_byte(0x10, 0xC5); ////充电电电流IBus
#endif
		break;
#if IBUS_Check

	case 4:
		if (R_SysMode_OK == COULOMB_CHARGE)
		{
			Readdata = 0;
			Readdata = iic_receive_byte(0x11);
			Readdata <<= 4;
			//	        Readdata |= iic_receive_byte(0x12);///// 5ma 一个值 100ma--20
			Readdata2 = iic_receive_byte(0x12); ////5ma 一个值 100ma--20
			Readdata2 = Readdata2 & 0x0f;
			Readdata = Readdata2 + Readdata;

			CIbus_16_date = Readdata;
			Readdata = Readdata >> 2;					 ////  100ma--5 20ma/step
														 //		 	if(Readdata>=250)/// 最大5A
			if (hex_greater_than_compare(Readdata, 250)) //
				Readdata = 250;
			CIbus_8_date = Readdata; ////最大5A输入输出电池端  20ma/step
		}

		if (R_SysMode_OK == COULOMB_DISCHARGE)
			iic_transmit_byte(0x10, 0xC7);
		break;
#endif

	case 5:
		if (R_SysMode_OK == COULOMB_DISCHARGE)
		{
			Readdata = 0;
			Readdata = iic_receive_byte(0x11);
			Readdata <<= 4;
			//	        Readdata |= iic_receive_byte(0x12);///// 5ma 一个值 100ma--20
			Readdata2 = iic_receive_byte(0x12); ////5ma 一个值 100ma--20
			Readdata2 = Readdata2 & 0x0f;
			Readdata = Readdata2 + Readdata;

			CIbus_16_date = Readdata;
		}

		break;

	default:
		SW7203_Data_Cnt = 0;
		break;
	}
	SW7203_Data_Cnt++;
#if IBUS_Check
	if (SW7203_Data_Cnt >= 5)
#else
	if (SW7203_Data_Cnt >= 4) ////增加IBUS 检测///
#endif
		SW7203_Data_Cnt = 0;
}
void BSP_I2C_BATVaule_Deal(void) ////////库伦计处理
{
	//    uint16_t I_All_IN_Do;
	uint16_t tempdata16;
	uint8_t math_8data, BAT_cha;
	uint8_t RE_data_temp8;
	//    uint8_t Car_Cur_data;
	//    uint16_t  Type_C_Ibat_16_date;

	if (R_SysMode_OK == COULOMB_CHARGE)
	{
		I_All_IN_Do = CIbat_8_date;

		RE_data_temp8 = iic_receive_byte(0x22);
		//	RE_data_temp8 &= ~(1<<5);
		RE_data_temp8 = RE_data_temp8 | 0x02;
		iic_transmit_byte(0x22, RE_data_temp8);
	}
	else
	{
#if 0
   	//////A口电流换算/////
   	   AIbat_8_date=0;
   	   AIbat_8_date=adc_convert.typea_1.adc_code_sl/6;///369--64 A口电流/6 C口电流/3 处理 以电池电压按13V 处理/////
//   	  if(USBA_VoltFlag>C_QC5V_Flag)
//   	   AIbat_8_date=AIbat_8_date*2;////  5V 9V 处理
   	   if(C_QC9V_Flag==USBA_VoltFlag)
   	   {
   	     AIbat_8_date=AIbat_8_date*2;////  5V 9V 处理
//   	     math_8data=AIbat_8_date/10;
//   	     AIbat_8_date=AIbat_8_date-math_8data;
   	   }
   	    if(C_QC12V_Flag==USBA_VoltFlag)
   	   {
   	     AIbat_8_date=AIbat_8_date*5;
   	     AIbat_8_date=AIbat_8_date/2;
   	   }
   	   //////C口电流换算/////
   	    Type_C_Ibat_16_date=adc_convert.typec_a.adc_code_sl/3;
   	   if(C_QC9V_Flag==VoltFlag)
   	    Type_C_Ibat_16_date=Type_C_Ibat_16_date*2;
   	   if(C_QC12V_Flag==VoltFlag)
   	   {
   	     Type_C_Ibat_16_date=Type_C_Ibat_16_date*5;
   	     Type_C_Ibat_16_date=Type_C_Ibat_16_date/2;
   	   }
   	   if(C_QC15V_Flag==VoltFlag)
   	    Type_C_Ibat_16_date=Type_C_Ibat_16_date*3;
   	   if(C_QC20V_Flag==VoltFlag)
   	    Type_C_Ibat_16_date=Type_C_Ibat_16_date*4;
   	    
   	    I_All_IN_Do=Type_C_Ibat_16_date+AIbat_8_date;

#else
		I_All_IN_Do = CIbat_8_date;
#endif

		///////////////////照明灯电流计算///// if((WHITE_ON||RED_ON)
		//   	   if(WHITE_ON||RED_ON)
		if (WHITE_ON)
		{
			if (WHITE_ON) /// 白灯亮
			{
				//   	       LIbat_8_date=19;////0模式常亮
				LIbat_8_date = 2; ////0模式常亮
				if (SOS_LEVEL)
				{
					//   	          if(SOS_LEVEL==1)
					//   	           LIbat_8_date=9;
					//   	          else
					//   	           LIbat_8_date=4;
					LIbat_8_date = 1;
				}
			}
			//   	     else///红灯亮///
			//   	     {
			//   	        LIbat_8_date=9;////0模式常亮
			//   	       if(SOS_LEVEL)
			//   	       {
			//   	          if(SOS_LEVEL==1)
			//   	           LIbat_8_date=4;
			//   	          else
			//   	           LIbat_8_date=2;
			//   	       }
			//   	     }
		}
		else
			LIbat_8_date = 0;
		//////////////////////////
		//   	    if(COULOMB_DISCHARGE== R_SysMode_OK)
		//   	   {
		//   	     I_All_IN_Do=CIbat_8_date;
		//             I_All_IN_Do=Type_C_Ibat_16_date+AIbat_8_date+LIbat_8_date;
		I_All_IN_Do = I_All_IN_Do + LIbat_8_date;
		//   	   }
		//   	   else///// A口和灯输出处理////
		//   	   {
		//   	      I_All_IN_Do=AIbat_8_date+LIbat_8_date;
		//   	   }
		//      I_All_IN_Do=CIbat_8_date+AIbat_8_date+LIbat_8_date;

#if 0
            if((Vbat_8_date<=C_VbatLow_batter_Car_change)&&(BatCap_Value>10))///// 电压小于12.6V 且电量大于20% 电量加速2倍
	        {
//	           car_low_bater_Cnt++;
//	          if(car_low_bater_Cnt>=3)/// 3S 钟减少1%////
//	          {
//	              car_low_bater_Cnt=0;
//	            if(BatCap_Value>15)
//	              BatCap_Value--;
//	          }
              I_All_IN_Do=I_All_IN_Do*2;
              DIS_low_bater_Cnt=1;
	        } 
	        else
	        DIS_low_bater_Cnt=0;
#endif

		//////////////////// 放电曲线纠正----//////
#if 1
		BAT_cha = 0;
		tempdata16 = CIbat_8_date / 16;
		tempdata16 = tempdata16 + Vbat_8_date;
		//       if(tempdata16>=250)
		if (hex_greater_than_compare(tempdata16, 250))
			tempdata16 = 250;
		BAT_real = tempdata16;

		if (BAT_real <= 126)
		{
			if (BatCap_Value > 5)
				BAT_cha = BatCap_Value - 5;
		}
		else if (BAT_real <= 138) ////  15  11-28
		{
			if (BatCap_Value > 15)
				BAT_cha = BatCap_Value - 15;
		}
		else if (BAT_real <= 147) /// 25  6-14
		{
			if (BatCap_Value > 25)
				BAT_cha = BatCap_Value - 25;
		}
		else if (BAT_real <= 153) /////35  6-14
		{
			if (BatCap_Value > 35)
				BAT_cha = BatCap_Value - 35;
		}
		else if (BAT_real <= 160) /////50  6-14
		{
			if (BatCap_Value > 50)
				BAT_cha = BatCap_Value - 50;
		}
		else if (BAT_real <= 178) // 65   6-14
		{
			if (BatCap_Value > 65)
				BAT_cha = BatCap_Value - 65;
		}
		else if (BAT_real <= 183) ////75   6-14
		{
			if (BatCap_Value > 75)
				BAT_cha = BatCap_Value - 75;
		}
		else if (BAT_real <= 191) ////85   6-14
		{
			if (BatCap_Value > 85)
				BAT_cha = BatCap_Value - 85;
		}

		if (BAT_cha)
		{
			if (BAT_cha > 10)
				I_All_IN_Do = I_All_IN_Do * 4;
			else if (BAT_cha > 5)
				I_All_IN_Do = I_All_IN_Do * 3;
			else
				I_All_IN_Do = I_All_IN_Do * 2;
		}
#endif
	}
	/////////////都是统一在7201端口 IBAT处检测电池电流///////
	//       I_All_IN_Do=CIbat_8_date;////
	///////////////////电压补偿处理////////////
	/////////////库伦计计算电量/////////////
	//       UTX_8_data1=I_All_IN_Do;
	//       UTX_16_data1=UTX_16_data1+I_All_IN_Do;
	//       if(UTX_16_data1>=1000)
	//       {
	//          UTX_8_data2++;
	//          UTX_16_data1=UTX_16_data1-1000;
	//       }

	///////////////统一7201检测电流 ////
	//        I_All_IN_Do=CIbat_8_date;

	///////////夹子电流处理///////
	if (f_car_jump)
	{
		if ((car_ST == 3) || (car_ST == 5) || (car_ST == 6)) //// 点火成功
		{
			Car_Cur_data = 5;	  // 夹上电平100ma电流计算
			if (car_OK_Flage > 3) ////连接2.5S
			{
				car_OK_Flage = 0;
				if (BatCap_Value > 5)
				{
					BatCap_Value = BatCap_Value - 3;
				}
			}
		}
		else if (car_ST == 2)
		{
			Car_Cur_data = 250; ////夹上电平 2.5A电流计算
								//              if(0==car_OK_Flage)
								//              car_OK_Flage=1;
								//              else
								//              {}
			car_OK_Flage++;
			if (car_OK_Flage >= 4) /// 连接3S以上///
			{
				car_OK_Flage = 4;
			}
		}
		else
		{
			Car_Cur_data = 5; //// 夹子接入100ma 电流
			car_OK_Flage = 0;
		}
		I_All_IN_Do = I_All_IN_Do + Car_Cur_data;
		//////////////当电池电压低于12.6V 时 如果电量大于15% 5S减1%
		if (Vbat_8_date <= C_VbatLow_batter_Car_change)
		{
			car_low_bater_Cnt++;
			if (car_low_bater_Cnt >= 3) /// 3S 钟减少1%////
			{
				car_low_bater_Cnt = 0;
				if (BatCap_Value > 15)
					BatCap_Value--;
			}
		}
	}
	else
	{
		car_OK_Flage = 0;
		Car_Cur_data = 0;
	}

#if Bat_Cnt
	//                  /////////////测试数据////
	//       UTX_16_data2=I_All_IN_Do;
	/////////////测试数据////
	UTX_16_data2 = UTX_16_data2 + CIbat_8_date;
	if (UTX_16_data2 >= 1000)
	{
		UTX_16_data3++;
		UTX_16_data2 = UTX_16_data2 - 1000;
	}
//////////////////
#endif

	////////////////
	ADD_IBAT_cnt = ADD_IBAT_cnt + I_All_IN_Do;
	if (R_SysMode_OK == COULOMB_CHARGE)
	{
		while (ADD_IBAT_cnt >= Charge_ADD_percent_accu)
		{
			ADD_IBAT_cnt = ADD_IBAT_cnt - Charge_ADD_percent_accu;
			if (BatCap_Value < 99)
			{
				if (!Bat_low_Cnt)	///// 没有解除低电保护之前 都不能计电量////
					BatCap_Value++; ////  最大到99
			}
		}
	}
	else
	{
		while (ADD_IBAT_cnt >= Disharge_ADD_percent_accu)
		{
			ADD_IBAT_cnt = ADD_IBAT_cnt - Disharge_ADD_percent_accu;
			if (BatCap_Value > 2)
			{
				BatCap_Value--; ///  最小减小到1
				coulomb_data.output.b_batt_full = 0;
			}
		}
	}
}

void Flash_Read_Deal()
{
	uint8_t temp8data;
	//   uint8_t T24C02_data1,T24C02_data2,T24C02_data3,T24C02_data4,T24C02_data5;
	////   WR_PIN_OFF_EN_WRITE;
	//   T24C02_data1=iic_receive_24C02_byte(RCR_24C02_addr);
	//   T24C02_data2=iic_receive_24C02_byte(BAT_Value_24C02_addr);
	//   T24C02_data3=iic_receive_24C02_byte(BAT_Vol_24C02_addr);
	//   T24C02_data4=iic_receive_24C02_byte(BAT_Low_24C02_addr);
	//   T24C02_data5=iic_receive_24C02_byte(RCR_sum_addr);
	//   temp8data=0;
	//   temp8data=T24C02_data1+T24C02_data2+T24C02_data3+T24C02_data4;
	Flash_Bat_RCR_data = iic_receive_24C02_byte(RCR_24C02_addr);
	if ((RCR_normal_Close_data == Flash_Bat_RCR_data) || (RCR_Updata_Close_data == Flash_Bat_RCR_data))
	//    if(RCR_normal_Close_data==temp8data)
	//   if(T24C02_data5==temp8data)///CS 校验看下是不是第一次 EEPROM 上电/////
	{
		Flash_Bat_Value_data = iic_receive_24C02_byte(BAT_Value_24C02_addr);
		Flash_Bat_Vol_data = iic_receive_24C02_byte(BAT_Vol_24C02_addr);
		Bat_low_Cnt = iic_receive_24C02_byte(BAT_Low_24C02_addr);

		//      Flash_Bat_Value_data=T24C02_data2;
		//      Flash_Bat_Vol_data=T24C02_data3;
		//      Bat_low_Cnt=T24C02_data4;
		Power_Value_Update = 0;
		Flash_bat_Vol_Start_check = 1; /////// 修正电池电量操作 确认长期不用或者非法关机//////
									   //     #if __IF_DEBUG__
									   //	 Sub_sim_tx(0xCC);
									   // 	 Sub_sim_tx(Flash_Bat_RCR_data);
									   //	 Sub_sim_tx(0xCC);
									   //	 #endif
		//////////////////////////////读取储存的个数///
		BAT_cnt_recor = iic_receive_24C02_byte(RCR_BAT_Vol_cnt_addr);

		if (BAT_cnt_recor)
		{
			//        if(BAT_cnt_recor>=19)
			if (BAT_cnt_recor >= (RCR_BAT_Vol_First_Cnt - 1))
				BAT_cnt_recor = 0;
			else
				BAT_cnt_recor++;
		}
		else /// 0-1//
		{
			BAT_cnt_recor = 1;
		}
	}
	else //// 第一次上电
	{
		Flash_Bat_Value_data = 0;
		Flash_Bat_Vol_data = 0;
		Bat_low_Cnt = 0;
		Power_Value_Update = 1; //// 系统第一次上电处理 24C02没有读写过///
		Flash_bat_Vol_Start_check = 0;
	}
	BatCap_Value = Flash_Bat_Value_data;

	Change_lauge_Flage = iic_receive_24C02_byte(RCR_Lange_cnt_addr);
	if (Change_lauge_Flage > 3)
		Change_lauge_Flage = 1;

	if (BatCap_Value > 100)
	{
		BatCap_Value = 0;
		Flash_Bat_Value_data = 0;
		Flash_Bat_Vol_data = 0;
		Bat_low_Cnt = 0;
		Power_Value_Update = 1; //// 系统第一次上电处理 24C02没有读写过///
		Flash_bat_Vol_Start_check = 0;
		//      Change_lauge_Flage=1;
	}
	//     WR_PIN_ON_DIS_WRITE;
	//    #if __IF_DEBUG__
	//	Sub_sim_tx(0xCC);
	//	Sub_sim_tx(0xCC);
	//	Sub_sim_tx(temp8data);///temp8data
	//	Sub_sim_tx(BatCap_Value);
	//    Sub_sim_tx(Flash_Bat_Vol_data);///	Flash_Bat_Vol_data
	////	Sub_sim_tx(Power_Value_Update);
	////    Sub_sim_tx(Flash_bat_Vol_Start_check);////	Flash_bat_Vol_Start_check
	////    test_data8_1=iic_receive_24C02_byte(BAT_Low_24C02_addr);
	////    Sub_sim_tx(test_data8_1);
	//	#endif
	delay_ms(10);
	iic_transmit_24C02_byte(RCR_24C02_addr, RCR_Updata_Close_data);
	delay_ms(10);
}
void Flash_update_Deal()
{
	uint8_t temp8data, temp8data_adr;
	//   WR_PIN_OFF_EN_WRITE;

	delay_ms(50);
	//   if(SYS_in_Sleep_F)//// 强制正常休眠前记录数据////
	iic_transmit_24C02_byte(RCR_24C02_addr, RCR_normal_Close_data);
	//   else // 每次电量变化都记录数据////
	//   iic_transmit_24C02_byte(RCR_24C02_addr,RCR_Updata_Close_data);
	delay_ms(20);
	iic_transmit_24C02_byte(BAT_Value_24C02_addr, BatCap_Value);
	delay_ms(20);
	iic_transmit_24C02_byte(BAT_Vol_24C02_addr, Vbat_8_date);
	delay_ms(20);
	iic_transmit_24C02_byte(BAT_Low_24C02_addr, Bat_low_Cnt);
	delay_ms(20);
	//   WR_PIN_ON_DIS_WRITE;

	//////// 休眠前处理 20个 电池电压参数保存/////
	//     RCR_BAT_Vol_cnt_addr++;
	//    if(BAT_cnt_recor>=20)///
	if (BAT_cnt_recor >= RCR_BAT_Vol_First_Cnt)
		BAT_cnt_recor = 0;

	iic_transmit_24C02_byte(RCR_BAT_Vol_cnt_addr, BAT_cnt_recor);
	delay_ms(20);

	//  if(Car_Cont_NG_Flage)
	temp8data = Car_Cont_NG_Flage;
	temp8data_adr = BAT_cnt_recor * 2;
	temp8data_adr = RCR_BAT_Vol_First_addr + temp8data_adr;
	iic_transmit_24C02_byte(temp8data_adr, temp8data);
	delay_ms(20);
	temp8data = Vbat_8_date;
	temp8data_adr = BAT_cnt_recor * 2;
	temp8data_adr = temp8data_adr + 1;
	temp8data_adr = RCR_BAT_Vol_First_addr + temp8data_adr;
	iic_transmit_24C02_byte(temp8data_adr, temp8data);
	delay_ms(20);
}
void Poweron_24C02_Self_inspec()
{

	uint8_t temp8data;

	if (COULOMB_CHARGE == R_SysMode_OK)
	{
		Self_inspe_CNT = 0;
		// C_VDD_ON;
		return;
	}

	if (Self_inspe_CNT)
	{
		Self_inspe_CNT++;

		if (10 == Self_inspe_CNT) // 1S 以后
		{
			iic_transmit_24C02_byte(Self_inspe_24C02_addr, Self_inspe_data);
		}

		if (15 == Self_inspe_CNT)
		{
			// C_VDD_OFF;
		}
		if (25 == Self_inspe_CNT)
		{
			// C_VDD_ON;
		}

		if (30 == Self_inspe_CNT)
		{
			// C_VDD_ON;
			temp8data = iic_receive_24C02_byte(Self_inspe_24C02_addr);
			if (Self_inspe_data == temp8data)
			//     if(0xff==temp8data)
			{
				Self_inspe_CNT = 0;
			}
			else
			{
				//     POWER_OC_to_low;
			}
		}
		if (Self_inspe_CNT >= 80)
		{
			// C_VDD_ON;
			Self_inspe_CNT = 0;
			//      POWER_OC_EN_inti;
		}
	}
}

void Charge_Bat_data_Err_Deal()
{
	uint8_t Readdata = 0;
	if (COULOMB_CHARGE != R_SysMode_OK)
		return;
	Readdata = iic_receive_byte(0x34);

	if (coulomb_data.output.b_batt_full)
	{
		//   if(Readdata != Data_720334_full)
		//   {
		//      iic_transmit_byte(0x34,Data_720334_full);
		//	  iic_transmit_byte(0x35,Data_720335_full);
		//
		//   }
	}
	else
	{
		if (Readdata != Data_720334)
		{
			// 充电目标电压h8
			iic_transmit_byte(0x34, Data_720334);
			// 涓充电目标电压L3
			iic_transmit_byte(0x35, Data_720335);
			// 涓流电压
			iic_transmit_byte(0x36, Data_720336);
		}
	}
}

void LED_PIN_on_off_Deal(uint8_t enble)
{
	if (WHITE_ON == Power_long_LED)
	{
		//  if(enble)
		//  {
		//    WHITE_PIN_ON;
		//  }
		//  else
		//  {
		//    WHITE_PIN_OFF;
		//  }
	}
	//  else if(WHITE_ON==Led_short_LED)
	//  {
	//      if(enble)
	//     {
	//       LED2_PIN_ON;
	//     }
	//     else
	//     {
	//       LED2_PIN_OFF;
	//     }
	//  }
	//  else
	//  {
	//      if(enble)
	//     {
	//       LED3_PIN_ON;
	//     }
	//     else
	//     {
	//       LED3_PIN_OFF;
	//     }
	//  }
}

void LED_PIN_qu_fan_Deal(void)
{
	if (WHITE_ON == Power_long_LED)
	{
		WHITE_PIN = ~WHITE_PIN;
	}
	//  else if(WHITE_ON==Led_short_LED)
	//  {
	//     LED2_PIN=~LED2_PIN;
	//  }
	//  else
	//  {
	//     LED3_PIN=~LED3_PIN;
	//  }
}

uint8_t Data_16_to_8_data_Deal(uint16_t data16_original)
{
	uint8_t data8_returm;
	if (hex_greater_than_compare(data16_original, 254))
		data8_returm = 254;
	else
		data8_returm = data16_original;

	return data8_returm;
}
