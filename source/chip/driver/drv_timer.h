/***************************************************************************
 * @file     drv_timer.h
 * @version  V1.0.0
 * @author   0531
 * @date     2020-09-23 AM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 ****************************************************************************
 * @par 头文件
 *       csu39fx10.h \n
 *       cs_common.h \n
 *       system_csu39fx10.h
 * @attention
 *  硬件平台:	\n
 *  SDK版本：	.0.0
 * 
 * @par 修改日志:
 * <table>
 * <tr><th>Date        <th>Version  <th>Author    <th>Description
 * <tr><td>2018/08/17  <td>1.0      <td>0531	  <td>创建初始版本
 * </table>
 *
 *****************************************************************************/

#ifndef __DRV_TIMER_H__
#define __DRV_TIMER_H__

// Include external header file.
#include "csu39fx10.h"
#include "cs_common.h"
#include "system_csu39fx10.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * @addtogroup csu39fx10_sdk_chip	csu39fx10_sdk_chip
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_driver	driver 
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_driver_timer	timer 
 * @{
 */

/** 
 * @addtogroup	timer_reg_tm0con	reg: TM0CON 
 * @{
 */
//TM0CON
//T0EN
#define T0_T0EN_REG								TM0CON
#define T0_T0EN_POS								(7)
#define T0_T0EN_BITS							C_REG_BITS1
#define T0_T0EN_DIS								(0x00<< T0_T0EN_POS)
#define T0_T0EN_EN								(0x01<< T0_T0EN_POS)
#define T0_T0EN_MASK							(T0_T0EN_BITS<< T0_T0EN_POS)
#define __T0_T0EN_GET()							M_REG_GET(T0_T0EN_REG, T0_T0EN_POS, T0_T0EN_BITS)
#define __T0_T0EN_SET(EN)						M_REG_SET(T0_T0EN_REG, T0_T0EN_POS, T0_T0EN_BITS, EN)
#define __T0_T0EN_GET_SHIFT()					M_REG_GET_SHIFT(T0_T0EN_REG, T0_T0EN_POS, T0_T0EN_BITS)
#define __T0_T0EN_SET_SHIFT(POS_EN)				M_REG_SET_SHIFT(T0_T0EN_REG, T0_T0EN_POS, T0_T0EN_BITS, POS_EN)

//TM0CON
//TM0IF
#define T0_TM0IF_REG							TM0CON
#define T0_TM0IF_POS							(6)
#define T0_TM0IF_BITS							C_REG_BITS1
#define T0_TM0IF_CLR							(0x00<< T0_TM0IF_POS)
#define T0_TM0IF_MASK							(T0_TM0IF_BITS<< T0_TM0IF_POS)
#define __T0_TM0IF_GET()						M_REG_GET(T0_TM0IF_REG, T0_TM0IF_POS, T0_TM0IF_BITS)
#define __T0_TM0IF_SET(CLR)						M_REG_SET(T0_TM0IF_REG, T0_TM0IF_POS, T0_TM0IF_BITS, CLR)
#define __T0_TM0IF_GET_SHIFT()					M_REG_GET_SHIFT(T0_TM0IF_REG, T0_TM0IF_POS, T0_TM0IF_BITS)
#define __T0_TM0IF_SET_SHIFT(POS_CLR)			M_REG_SET_SHIFT(T0_TM0IF_REG, T0_TM0IF_POS, T0_TM0IF_BITS, POS_CLR)

//TM0CON
//TM0IE
#define T0_TM0IE_REG							TM0CON
#define T0_TM0IE_POS							(5)
#define T0_TM0IE_BITS							C_REG_BITS1
#define T0_TM0IE_DIS							(0x00<< T0_TM0IE_POS)
#define T0_TM0IE_EN								(0x01<< T0_TM0IE_POS)
#define T0_TM0IE_MASK							(T0_TM0IE_BITS<< T0_TM0IE_POS)
#define __T0_TM0IE_GET()						M_REG_GET(T0_TM0IE_REG, T0_TM0IE_POS, T0_TM0IE_BITS)
#define __T0_TM0IE_SET(EN)						M_REG_SET(T0_TM0IE_REG, T0_TM0IE_POS, T0_TM0IE_BITS, EN)
#define __T0_TM0IE_GET_SHIFT()					M_REG_GET_SHIFT(T0_TM0IE_REG, T0_TM0IE_POS, T0_TM0IE_BITS)
#define __T0_TM0IE_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(T0_TM0IE_REG, T0_TM0IE_POS, T0_TM0IE_BITS, POS_EN)

//TM0CON
//T0RSTB
#define T0_T0RSTB_REG							TM0CON
#define T0_T0RSTB_POS							(2)
#define T0_T0RSTB_BITS							C_REG_BITS1
#define T0_T0RSTB_DIS							(0x01<< T0_T0RSTB_POS)
#define T0_T0RSTB_EN							(0x00<< T0_T0RSTB_POS)
#define T0_T0RSTB_MASK							(T0_T0RSTB_BITS<< T0_T0RSTB_POS)
#define __T0_T0RSTB_GET()						M_REG_GET(T0_T0RSTB_REG, T0_T0RSTB_POS, T0_T0RSTB_BITS)
#define __T0_T0RSTB_SET(EN)						M_REG_SET(T0_T0RSTB_REG, T0_T0RSTB_POS, T0_T0RSTB_BITS, EN)
#define __T0_T0RSTB_GET_SHIFT()					M_REG_GET_SHIFT(T0_T0RSTB_REG, T0_T0RSTB_POS, T0_T0RSTB_BITS)
#define __T0_T0RSTB_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(T0_T0RSTB_REG, T0_T0RSTB_POS, T0_T0RSTB_BITS, POS_EN)
/**@}*/ /*** end of group timer_reg_tm0con */

/** 
 * @addtogroup	timer_reg_tm0in	reg: TM0IN 
 * @{
 */
//TM0IN
//TM0IN[7:0]
#define T0_TM0IN_REG							TM0IN
#define T0_TM0IN_POS							(0)
#define T0_TM0IN_VAL
#define T0_TM0IN_MASK							(0xFF<< T0_TM0IN_POS)
#define __T0_TM0IN_GET()						M_REG_GETBYTE(T0_TM0IN_REG, T0_TM0IN_POS)
#define __T0_TM0IN_SET(SET)						M_REG_SETBYTE(T0_TM0IN_REG, T0_TM0IN_POS, SET)
#define __T0_TM0IN_GET_SHIFT()					M_REG_GETBYTE_SHIFT(T0_TM0IN_REG, T0_TM0IN_POS)
#define __T0_TM0IN_SET_SHIFT(POS_SET)			M_REG_SETBYTE_SHIFT(T0_TM0IN_REG, T0_TM0IN_POS, POS_SET)
/**@}*/ /*** end of group timer_reg_tm0in */

/** 
 * @addtogroup	timer_reg_tm0cnt reg: TM0CNT 
 * @attention <b>READ-ONLY</b>
 * @{
 */
//TM0CNT- Read only
//TM0CNT[7:0]
#define T0_TM0CNT_REG							TM0CNT
#define T0_TM0CNT_POS							(0)
#define T0_TM0CNT_VAL
#define T0_TM0CNT_MASK							(0xFF<< T0_TM0CNT_POS)
#define __T0_TM0CNT_GET()						M_REG_GETBYTE(T0_TM0CNT_REG, T0_TM0CNT_POS)
#define __T0_TM0CNT_GET_SHIFT()					M_REG_GETBYTE_SHIFT(T0_TM0CNT_REG, T0_TM0CNT_POS)
/**@}*/ /*** end of group timer_reg_tm0cnt */

/** 
 * @addtogroup	timer_reg_tm2con reg: TM2CON 
 * @{
 */
//TM2CON
//T2EN
#define T2_T2EN_REG								TM2CON
#define T2_T2EN_POS								(7)
#define T2_T2EN_BITS							C_REG_BITS1
#define T2_T2EN_DIS								(0x00<< T2_T2EN_POS)
#define T2_T2EN_EN								(0x01<< T2_T2EN_POS)
#define T2_T2EN_MASK							(T2_T2EN_BITS<< T2_T2EN_POS)
#define __T2_T2EN_GET()							M_REG_GET(T2_T2EN_REG, T2_T2EN_POS, T2_T2EN_BITS)
#define __T2_T2EN_SET(EN)						M_REG_SET(T2_T2EN_REG, T2_T2EN_POS, T2_T2EN_BITS, EN)
#define __T2_T2EN_GET_SHIFT()					M_REG_GET_SHIFT(T2_T2EN_REG, T2_T2EN_POS, T2_T2EN_BITS)
#define __T2_T2EN_SET_SHIFT(POS_EN)				M_REG_SET_SHIFT(T2_T2EN_REG, T2_T2EN_POS, T2_T2EN_BITS, POS_EN)

//TM2CON
//TM2IF
#define T2_TM2IF_REG							TM2CON
#define T2_TM2IF_POS							(6)
#define T2_TM2IF_BITS							C_REG_BITS1
#define T2_TM2IF_CLR							(0x00<< T2_TM2IF_POS)
#define T2_TM2IF_MASK							(T2_TM2IF_BITS<< T2_TM2IF_POS)
#define __T2_TM2IF_GET()						M_REG_GET(T2_TM2IF_REG, T2_TM2IF_POS, T2_TM2IF_BITS)
#define __T2_TM2IF_SET(CLR)						M_REG_SET(T2_TM2IF_REG, T2_TM2IF_POS, T2_TM2IF_BITS, CLR)
#define __T2_TM2IF_GET_SHIFT()					M_REG_GET_SHIFT(T2_TM2IF_REG, T2_TM2IF_POS, T2_TM2IF_BITS)
#define __T2_TM2IF_SET_SHIFT(POS_CLR)			M_REG_SET_SHIFT(T2_TM2IF_REG, T2_TM2IF_POS, T2_TM2IF_BITS, POS_CLR)

//TM2CON
//TM2IE
#define T2_TM2IE_REG							TM2CON
#define T2_TM2IE_POS							(5)
#define T2_TM2IE_BITS							C_REG_BITS1
#define T2_TM2IE_DIS							(0x00<< T2_TM2IE_POS)
#define T2_TM2IE_EN								(0x01<< T2_TM2IE_POS)
#define T2_TM2IE_MASK							(T2_TM2IE_BITS<< T2_TM2IE_POS)
#define __T2_TM2IE_GET()						M_REG_GET(T2_TM2IE_REG, T2_TM2IE_POS, T2_TM2IE_BITS)
#define __T2_TM2IE_SET(EN)						M_REG_SET(T2_TM2IE_REG, T2_TM2IE_POS, T2_TM2IE_BITS, EN)
#define __T2_TM2IE_GET_SHIFT()					M_REG_GET_SHIFT(T2_TM2IE_REG, T2_TM2IE_POS, T2_TM2IE_BITS)
#define __T2_TM2IE_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(T2_TM2IE_REG, T2_TM2IE_POS, T2_TM2IE_BITS, POS_EN)

//TM2CON
//PWM2STALL
#define T2_PWM2STALL_REG						TM2CON
#define T2_PWM2STALL_POS						(4)
#define T2_PWM2STALL_BITS						C_REG_BITS1
#define T2_PWM2STALL_LO							(0x00<< T2_PWM2STALL_POS)
#define T2_PWM2STALL_HI							(0x01<< T2_PWM2STALL_POS)
#define T2_PWM2STALL_MASK						(T2_PWM2STALL_BITS<< T2_PWM2STALL_POS)
#define __T2_PWM2STALL_GET()					M_REG_GET(T2_PWM2STALL_REG, T2_PWM2STALL_POS, T2_PWM2STALL_BITS)
#define __T2_PWM2STALL_SET(EN)					M_REG_SET(T2_PWM2STALL_REG, T2_PWM2STALL_POS, T2_PWM2STALL_BITS, EN)
#define __T2_PWM2STALL_GET_SHIFT()				M_REG_GET_SHIFT(T2_PWM2STALL_REG, T2_PWM2STALL_POS, T2_PWM2STALL_BITS)
#define __T2_PWM2STALL_SET_SHIFT(POS_EN)		M_REG_SET_SHIFT(T2_PWM2STALL_REG, T2_PWM2STALL_POS, T2_PWM2STALL_BITS, POS_EN)

//TM2CON
//T2RSTB
#define T2_T2RSTB_REG							TM2CON
#define T2_T2RSTB_POS							(2)
#define T2_T2RSTB_BITS							C_REG_BITS1
#define T2_T2RSTB_DIS							(0x01<< T2_T2RSTB_POS)
#define T2_T2RSTB_EN							(0x00<< T2_T2RSTB_POS)
#define T2_T2RSTB_MASK							(T2_T2RSTB_BITS<< T2_T2RSTB_POS)
#define __T2_T2RSTB_GET()						M_REG_GET(T2_T2RSTB_REG, T2_T2RSTB_POS, T2_T2RSTB_BITS)
#define __T2_T2RSTB_SET(EN)						M_REG_SET(T2_T2RSTB_REG, T2_T2RSTB_POS, T2_T2RSTB_BITS, EN)
#define __T2_T2RSTB_GET_SHIFT()					M_REG_GET_SHIFT(T2_T2RSTB_REG, T2_T2RSTB_POS, T2_T2RSTB_BITS)
#define __T2_T2RSTB_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(T2_T2RSTB_REG, T2_T2RSTB_POS, T2_T2RSTB_BITS, POS_EN)
/**@}*/ /*** end of group timer_reg_tm2con */

/** 
 * @addtogroup	timer_reg_tm2in reg: TM2IN 
 * @{
 */
//TM2IN
//TM2IN[7:0]
#define T2_TM2IN_REG							TM2IN
#define T2_TM2IN_POS							(0)
#define T2_TM2IN_VAL
#define T2_TM2IN_MASK							(0xFF<< T2_TM2IN_POS)
#define __T2_TM2IN_GET()						M_REG_GETBYTE(T2_TM2IN_REG, T2_TM2IN_POS)
#define __T2_TM2IN_SET(SET)						M_REG_SETBYTE(T2_TM2IN_REG, T2_TM2IN_POS, SET)
#define __T2_TM2IN_GET_SHIFT()					M_REG_GETBYTE_SHIFT(T2_TM2IN_REG, T2_TM2IN_POS)
#define __T2_TM2IN_SET_SHIFT(POS_SET)			M_REG_SETBYTE_SHIFT(T2_TM2IN_REG, T2_TM2IN_POS, POS_SET)
/**@}*/ /*** end of group timer_reg_tm2in */

/** 
 * @addtogroup	timer_reg_tm2cnt reg: TM2CNT 
 * @attention <b>READ-ONLY</b>
 * @{
 */
//TM2CNT- Read only
//TM2CNT[7:0]
#define T2_TM2CNT_REG							TM2CNT
#define T2_TM2CNT_POS							(0)
#define T2_TM2CNT_VAL
#define T2_TM2CNT_MASK							(0xFF<< T2_TM2CNT_POS)
#define __T2_TM2CNT_GET()						M_REG_GETBYTE(T2_TM2CNT_REG, T2_TM2CNT_POS)
#define __T2_TM2CNT_GET_SHIFT()					M_REG_GETBYTE_SHIFT(T2_TM2CNT_REG, T2_TM2CNT_POS)
/**@}*/ /*** end of group timer_reg_tm2cnt */

/** 
 * @addtogroup	timer_reg_tm2r reg: TM2R 
 * @{
 */
//TM2R
//TM2R[7:0]
#define T2_TM2R_REG								TM2R
#define T2_TM2R_POS								(0)
#define T2_TM2R_VAL
#define T2_TM2R_MASK							(0xFF<< T2_TM2R_POS)
#define __T2_TM2R_GET()							M_REG_GETBYTE(T2_TM2R_REG, T2_TM2R_POS)
#define __T2_TM2R_SET(SET)						M_REG_SETBYTE(T2_TM2R_REG, T2_TM2R_POS, SET)
#define __T2_TM2R_GET_SHIFT()					M_REG_GETBYTE_SHIFT(T2_TM2R_REG, T2_TM2R_POS)
#define __T2_TM2R_SET_SHIFT(POS_SET)			M_REG_SETBYTE_SHIFT(T2_TM2R_REG, T2_TM2R_POS, POS_SET)
/**@}*/ /*** end of group timer_reg_tm2r */

/** 
 * @addtogroup	timer_reg_tm3con reg: TM3CON 
 * @{
 */
//TM3CON
//T3EN
#define T3_T3EN_REG								TM3CON
#define T3_T3EN_POS								(7)
#define T3_T3EN_BITS							C_REG_BITS1
#define T3_T3EN_DIS								(0x00<< T3_T3EN_POS)
#define T3_T3EN_EN								(0x01<< T3_T3EN_POS)
#define T3_T3EN_MASK							(T3_T3EN_BITS<< T3_T3EN_POS)
#define __T3_T3EN_GET()							M_REG_GET(T3_T3EN_REG, T3_T3EN_POS, T3_T3EN_BITS)
#define __T3_T3EN_SET(EN)						M_REG_SET(T3_T3EN_REG, T3_T3EN_POS, T3_T3EN_BITS, EN)
#define __T3_T3EN_GET_SHIFT()					M_REG_GET_SHIFT(T3_T3EN_REG, T3_T3EN_POS, T3_T3EN_BITS)
#define __T3_T3EN_SET_SHIFT(POS_EN)				M_REG_SET_SHIFT(T3_T3EN_REG, T3_T3EN_POS, T3_T3EN_BITS, POS_EN)

//TM3CON
//TM3IF
#define T3_TM3IF_REG							TM3CON
#define T3_TM3IF_POS							(6)
#define T3_TM3IF_BITS							C_REG_BITS1
#define T3_TM3IF_CLR							(0x00<< T3_TM3IF_POS)
#define T3_TM3IF_MASK							(T3_TM3IF_BITS<< T3_TM3IF_POS)
#define __T3_TM3IF_GET()						M_REG_GET(T3_TM3IF_REG, T3_TM3IF_POS, T3_TM3IF_BITS)
#define __T3_TM3IF_SET(CLR)						M_REG_SET(T3_TM3IF_REG, T3_TM3IF_POS, T3_TM3IF_BITS, CLR)
#define __T3_TM3IF_GET_SHIFT()					M_REG_GET_SHIFT(T3_TM3IF_REG, T3_TM3IF_POS, T3_TM3IF_BITS)
#define __T3_TM3IF_SET_SHIFT(POS_CLR)			M_REG_SET_SHIFT(T3_TM3IF_REG, T3_TM3IF_POS, T3_TM3IF_BITS, POS_CLR)

//TM3CON
//TM3IE
#define T3_TM3IE_REG							TM3CON
#define T3_TM3IE_POS							(5)
#define T3_TM3IE_BITS							C_REG_BITS1
#define T3_TM3IE_DIS							(0x00<< T3_TM3IE_POS)
#define T3_TM3IE_EN								(0x01<< T3_TM3IE_POS)
#define T3_TM3IE_MASK							(T3_TM3IE_BITS<< T3_TM3IE_POS)
#define __T3_TM3IE_GET()						M_REG_GET(T3_TM3IE_REG, T3_TM3IE_POS, T3_TM3IE_BITS)
#define __T3_TM3IE_SET(EN)						M_REG_SET(T3_TM3IE_REG, T3_TM3IE_POS, T3_TM3IE_BITS, EN)
#define __T3_TM3IE_GET_SHIFT()					M_REG_GET_SHIFT(T3_TM3IE_REG, T3_TM3IE_POS, T3_TM3IE_BITS)
#define __T3_TM3IE_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(T3_TM3IE_REG, T3_TM3IE_POS, T3_TM3IE_BITS, POS_EN)

//TM3CON
//T3RSTB
#define T3_T3RSTB_REG							TM3CON
#define T3_T3RSTB_POS							(2)
#define T3_T3RSTB_BITS							C_REG_BITS1
#define T3_T3RSTB_DIS							(0x01<< T3_T3RSTB_POS)
#define T3_T3RSTB_EN							(0x00<< T3_T3RSTB_POS)
#define T3_T3RSTB_MASK							(T3_T3RSTB_BITS<< T3_T3RSTB_POS)
#define __T3_T3RSTB_GET()						M_REG_GET(T3_T3RSTB_REG, T3_T3RSTB_POS, T3_T3RSTB_BITS)
#define __T3_T3RSTB_SET(EN)						M_REG_SET(T3_T3RSTB_REG, T3_T3RSTB_POS, T3_T3RSTB_BITS, EN)
#define __T3_T3RSTB_GET_SHIFT()					M_REG_GET_SHIFT(T3_T3RSTB_REG, T3_T3RSTB_POS, T3_T3RSTB_BITS)
#define __T3_T3RSTB_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(T3_T3RSTB_REG, T3_T3RSTB_POS, T3_T3RSTB_BITS, POS_EN)
/**@}*/ /*** end of group timer_reg_tm3con */

/** 
 * @addtogroup	timer_reg_tm3in reg: TM3IN 
 * @{
 */
//TM3IN
//TM3IN[7:0]
#define T3_TM3IN_REG							TM3IN
#define T3_TM3IN_POS							(0)
#define T3_TM3IN_VAL
#define T3_TM3IN_MASK							(0xFF<< T3_TM3IN_POS)
#define __T3_TM3IN_GET()						M_REG_GETBYTE(T3_TM3IN_REG, T3_TM3IN_POS)
#define __T3_TM3IN_SET(SET)						M_REG_SETBYTE(T3_TM3IN_REG, T3_TM3IN_POS, SET)
#define __T3_TM3IN_GET_SHIFT()					M_REG_GETBYTE_SHIFT(T3_TM3IN_REG, T3_TM3IN_POS)
#define __T3_TM3IN_SET_SHIFT(POS_SET)			M_REG_SETBYTE_SHIFT(T3_TM3IN_REG, T3_TM3IN_POS, POS_SET)
/**@}*/ /*** end of group timer_reg_tm3in */

/** 
 * @addtogroup	timer_reg_tm3inh reg: TM3INH 
 * @{
 */
//TM3INH
//TM3IN[11:8]
#define T3_TM3INH_REG							TM3INH
#define T3_TM3INH_POS							(0)
#define T3_TM3INH_VAL
#define T3_TM3INH_MASK							(0x0F<< T3_TM3INH_POS)
#define __T3_TM3INH_GET()						M_REG_GETBYTE(T3_TM3INH_REG, T3_TM3INH_POS)
#define __T3_TM3INH_SET(SET)					M_REG_SETBYTE(T3_TM3INH_REG, T3_TM3INH_POS, SET)
#define __T3_TM3INH_GET_SHIFT()					M_REG_GETBYTE_SHIFT(T3_TM3INH_REG, T3_TM3INH_POS)
#define __T3_TM3INH_SET_SHIFT(POS_SET)			M_REG_SETBYTE_SHIFT(T3_TM3INH_REG, T3_TM3INH_POS, POS_SET)
/**@}*/ /*** end of group timer_reg_tm3inh */

/** 
 * @addtogroup	timer_reg_tm3cnt reg: TM3CNT 
 * @attention <b>READ-ONLY</b>
 * @{
 */
//TM3CNT- Read only
//TM3CNT[7:0]
#define T3_TM3CNT_REG							TM3CNT
#define T3_TM3CNT_POS							(0)
#define T3_TM3CNT_VAL
#define T3_TM3CNT_MASK							(0xFF<< T3_TM3CNT_POS)
#define __T3_TM3CNT_GET()						M_REG_GETBYTE(T3_TM3CNT_REG, T3_TM3CNT_POS)
#define __T3_TM3CNT_GET_SHIFT()					M_REG_GETBYTE_SHIFT(T3_TM3CNT_REG, T3_TM3CNT_POS)
/**@}*/ /*** end of group timer_reg_tm3cnt */

/** 
 * @addtogroup	timer_reg_tm3cnth reg: TM3CNTH 
 * @attention <b>READ-ONLY</b>
 * @{
 */
//TM3CNTH- Read only
//TM3CNT[11:8]
#define T3_TM3CNTH_REG							TM3CNTH
#define T3_TM3CNTH_POS							(0)
#define T3_TM3CNTH_VAL
#define T3_TM3CNTH_MASK							(0x0F<< T3_TM3CNTH_POS)
#define __T3_TM3CNTH_GET()						M_REG_GETBYTE(T3_TM3CNTH_REG, T3_TM3CNTH_POS)
#define __T3_TM3CNTH_GET_SHIFT()				M_REG_GETBYTE_SHIFT(T3_TM3CNTH_REG, T3_TM3CNTH_POS)
/**@}*/ /*** end of group timer_reg_tm3cnth */

/** 
 * @addtogroup	timer_reg_tm3r reg: TM3R 
 * @{
 */
//TM3R
//TM3R[7:0]
#define T3_TM3R_REG								TM3R
#define T3_TM3R_POS								(0)
#define T3_TM3R_VAL
#define T3_TM3R_MASK							(0xFF<< T3_TM3R_POS)
#define __T3_TM3R_GET()							M_REG_GETBYTE(T3_TM3R_REG, T3_TM3R_POS)
#define __T3_TM3R_SET(SET)						M_REG_SETBYTE(T3_TM3R_REG, T3_TM3R_POS, SET)
#define __T3_TM3R_GET_SHIFT()					M_REG_GETBYTE_SHIFT(T3_TM3R_REG, T3_TM3R_POS)
#define __T3_TM3R_SET_SHIFT(POS_SET)			M_REG_SETBYTE_SHIFT(T3_TM3R_REG, T3_TM3R_POS, POS_SET)
/**@}*/ /*** end of group timer_reg_tm3r */

/** 
 * @addtogroup	timer_reg_tm3rh reg: TM3RH 
 * @{
 */
//TM3RH
//TM3R[11:8]
#define T3_TM3RH_REG							TM3RH
#define T3_TM3RH_POS							(0)
#define T3_TM3RH_VAL
#define T3_TM3RH_MASK							(0x0F<< T3_TM3RH_POS)
#define __T3_TM3RH_GET()						M_REG_GETBYTE(T3_TM3RH_REG, T3_TM3RH_POS)
#define __T3_TM3RH_SET(SET)						M_REG_SETBYTE(T3_TM3RH_REG, T3_TM3RH_POS, SET)
#define __T3_TM3RH_GET_SHIFT()					M_REG_GETBYTE_SHIFT(T3_TM3RH_REG, T3_TM3RH_POS)
#define __T3_TM3RH_SET_SHIFT(POS_SET)			M_REG_SETBYTE_SHIFT(T3_TM3RH_REG, T3_TM3RH_POS, POS_SET)
/**@}*/ /*** end of group timer_reg_tm3rh */

/** 
 * @addtogroup	timer_reg_tm3con2 reg: TM3CON2 
 * @{
 */
//TM3CON2
//PWM3STALL
#define T3_PWM3STALL_REG						TM3CON2
#define T3_PWM3STALL_POS						(7)
#define T3_PWM3STALL_BITS						C_REG_BITS1
#define T3_PWM3STALL_LO							(0x00<< T3_PWM3STALL_POS)
#define T3_PWM3STALL_HI							(0x01<< T3_PWM3STALL_POS)
#define T3_PWM3STALL_MASK						(T3_PWM3STALL_BITS<< T3_PWM3STALL_POS)
#define __T3_PWM3STALL_GET()					M_REG_GET(T3_PWM3STALL_REG, T3_PWM3STALL_POS, T3_PWM3STALL_BITS)
#define __T3_PWM3STALL_SET(EN)					M_REG_SET(T3_PWM3STALL_REG, T3_PWM3STALL_POS, T3_PWM3STALL_BITS, EN)
#define __T3_PWM3STALL_GET_SHIFT()				M_REG_GET_SHIFT(T3_PWM3STALL_REG, T3_PWM3STALL_POS, T3_PWM3STALL_BITS)
#define __T3_PWM3STALL_SET_SHIFT(POS_EN)		M_REG_SET_SHIFT(T3_PWM3STALL_REG, T3_PWM3STALL_POS, T3_PWM3STALL_BITS, POS_EN)

//TM3CON2
//DT3CNT[3:0]
#define T3_DT3CNT_REG							TM3CON2
#define T3_DT3CNT_POS							(3)
#define T3_DT3CNT_BITS							C_REG_BITS4
#define T3_DT3CNT_VAL
#define T3_DT3CNT_MASK							(T3_DT3CNT_BITS<< T3_DT3CNT_POS)
#define __T3_DT3CNT_GET()						M_REG_GET(T3_DT3CNT_REG, T3_DT3CNT_POS, T3_DT3CNT_BITS)
#define __T3_DT3CNT_SET(SET)					M_REG_SET(T3_DT3CNT_REG, T3_DT3CNT_POS, T3_DT3CNT_BITS, SET)
#define __T3_DT3CNT_GET_SHIFT()					M_REG_GET_SHIFT(T3_DT3CNT_REG, T3_DT3CNT_POS, T3_DT3CNT_BITS)
#define __T3_DT3CNT_SET_SHIFT(POS_SET)			M_REG_SET_SHIFT(T3_DT3CNT_REG, T3_DT3CNT_POS, T3_DT3CNT_BITS, POS_SET)

//TM3CON2
//DT3_EN
#define T3_DT3_EN_REG							TM3CON2
#define T3_DT3_EN_POS							(2)
#define T3_DT3_EN_BITS							C_REG_BITS1
#define T3_DT3_EN_DIS							(0x00<< T3_DT3_EN_POS)
#define T3_DT3_EN_EN							(0x01<< T3_DT3_EN_POS)
#define T3_DT3_EN_MASK							(T3_DT3_EN_BITS<< T3_DT3_EN_POS)
#define __T3_DT3_EN_GET()						M_REG_GET(T3_DT3_EN_REG, T3_DT3_EN_POS, T3_DT3_EN_BITS)
#define __T3_DT3_EN_SET(EN)						M_REG_SET(T3_DT3_EN_REG, T3_DT3_EN_POS, T3_DT3_EN_BITS, EN)
#define __T3_DT3_EN_GET_SHIFT()					M_REG_GET_SHIFT(T3_DT3_EN_REG, T3_DT3_EN_POS, T3_DT3_EN_BITS)
#define __T3_DT3_EN_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(T3_DT3_EN_REG, T3_DT3_EN_POS, T3_DT3_EN_BITS, POS_EN)

//TM3CON2
//P3HINV
#define T3_P3HINV_REG							TM3CON2
#define T3_P3HINV_POS							(1)
#define T3_P3HINV_BITS							C_REG_BITS1
#define T3_P3HINV_DIS							(0x00<< T3_P3HINV_POS)
#define T3_P3HINV_EN							(0x01<< T3_P3HINV_POS)
#define T3_P3HINV_MASK							(T3_P3HINV_BITS<< T3_P3HINV_POS)
#define __T3_P3HINV_GET()						M_REG_GET(T3_P3HINV_REG, T3_P3HINV_POS, T3_P3HINV_BITS)
#define __T3_P3HINV_SET(EN)						M_REG_SET(T3_P3HINV_REG, T3_P3HINV_POS, T3_P3HINV_BITS, EN)
#define __T3_P3HINV_GET_SHIFT()					M_REG_GET_SHIFT(T3_P3HINV_REG, T3_P3HINV_POS, T3_P3HINV_BITS)
#define __T3_P3HINV_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(T3_P3HINV_REG, T3_P3HINV_POS, T3_P3HINV_BITS, POS_EN)

//TM3CON2
//P3LINV
#define T3_P3LINV_REG							TM3CON2
#define T3_P3LINV_POS							(0)
#define T3_P3LINV_BITS							C_REG_BITS1
#define T3_P3LINV_DIS							(0x00<< T3_P3LINV_POS)
#define T3_P3LINV_EN							(0x01<< T3_P3LINV_POS)
#define T3_P3LINV_MASK							(T3_P3LINV_BITS<< T3_P3LINV_POS)
#define __T3_P3LINV_GET()						M_REG_GET(T3_P3LINV_REG, T3_P3LINV_POS, T3_P3LINV_BITS)
#define __T3_P3LINV_SET(EN)						M_REG_SET(T3_P3LINV_REG, T3_P3LINV_POS, T3_P3LINV_BITS, EN)
#define __T3_P3LINV_GET_SHIFT()					M_REG_GET_SHIFT(T3_P3LINV_REG, T3_P3LINV_POS, T3_P3LINV_BITS)
#define __T3_P3LINV_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(T3_P3LINV_REG, T3_P3LINV_POS, T3_P3LINV_BITS, POS_EN)
/**@}*/ /*** end of group timer_reg_tm3con2 */

/** 
 * @addtogroup	timer_reg_tm4con reg: TM4CON 
 * @{
 */
//TM4CON
//T4EN
#define T4_T4EN_REG								TM4CON
#define T4_T4EN_POS								(7)
#define T4_T4EN_BITS							C_REG_BITS1
#define T4_T4EN_DIS								(0x00<< T4_T4EN_POS)
#define T4_T4EN_EN								(0x01<< T4_T4EN_POS)
#define T4_T4EN_MASK							(T4_T4EN_BITS<< T4_T4EN_POS)
#define __T4_T4EN_GET()							M_REG_GET(T4_T4EN_REG, T4_T4EN_POS, T4_T4EN_BITS)
#define __T4_T4EN_SET(EN)						M_REG_SET(T4_T4EN_REG, T4_T4EN_POS, T4_T4EN_BITS, EN)
#define __T4_T4EN_GET_SHIFT()					M_REG_GET_SHIFT(T4_T4EN_REG, T4_T4EN_POS, T4_T4EN_BITS)
#define __T4_T4EN_SET_SHIFT(POS_EN)				M_REG_SET_SHIFT(T4_T4EN_REG, T4_T4EN_POS, T4_T4EN_BITS, POS_EN)

//TM4CON
//TM4IF
#define T4_TM4IF_REG							TM4CON
#define T4_TM4IF_POS							(6)
#define T4_TM4IF_BITS							C_REG_BITS1
#define T4_TM4IF_CLR							(0x00<< T4_TM4IF_POS)
#define T4_TM4IF_MASK							(T4_TM4IF_BITS<< T4_TM4IF_POS)
#define __T4_TM4IF_GET()						M_REG_GET(T4_TM4IF_REG, T4_TM4IF_POS, T4_TM4IF_BITS)
#define __T4_TM4IF_SET(CLR)						M_REG_SET(T4_TM4IF_REG, T4_TM4IF_POS, T4_TM4IF_BITS, CLR)
#define __T4_TM4IF_GET_SHIFT()					M_REG_GET_SHIFT(T4_TM4IF_REG, T4_TM4IF_POS, T4_TM4IF_BITS)
#define __T4_TM4IF_SET_SHIFT(POS_CLR)			M_REG_SET_SHIFT(T4_TM4IF_REG, T4_TM4IF_POS, T4_TM4IF_BITS, POS_CLR)

//TM4CON
//TM4IE
#define T4_TM4IE_REG							TM4CON
#define T4_TM4IE_POS							(5)
#define T4_TM4IE_BITS							C_REG_BITS1
#define T4_TM4IE_DIS							(0x00<< T4_TM4IE_POS)
#define T4_TM4IE_EN								(0x01<< T4_TM4IE_POS)
#define T4_TM4IE_MASK							(T4_TM4IE_BITS<< T4_TM4IE_POS)
#define __T4_TM4IE_GET()						M_REG_GET(T4_TM4IE_REG, T4_TM4IE_POS, T4_TM4IE_BITS)
#define __T4_TM4IE_SET(EN)						M_REG_SET(T4_TM4IE_REG, T4_TM4IE_POS, T4_TM4IE_BITS, EN)
#define __T4_TM4IE_GET_SHIFT()					M_REG_GET_SHIFT(T4_TM4IE_REG, T4_TM4IE_POS, T4_TM4IE_BITS)
#define __T4_TM4IE_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(T4_TM4IE_REG, T4_TM4IE_POS, T4_TM4IE_BITS, POS_EN)

//TM4CON
//PWM4STALL
#define T4_PWM4STALL_REG						TM4CON
#define T4_PWM4STALL_POS						(4)
#define T4_PWM4STALL_BITS						C_REG_BITS1
#define T4_PWM4STALL_LO							(0x00<< T4_PWM4STALL_POS)
#define T4_PWM4STALL_HI							(0x01<< T4_PWM4STALL_POS)
#define T4_PWM4STALL_MASK						(T4_PWM4STALL_BITS<< T4_PWM4STALL_POS)
#define __T4_PWM4STALL_GET()					M_REG_GET(T4_PWM4STALL_REG, T4_PWM4STALL_POS, T4_PWM4STALL_BITS)
#define __T4_PWM4STALL_SET(EN)					M_REG_SET(T4_PWM4STALL_REG, T4_PWM4STALL_POS, T4_PWM4STALL_BITS, EN)
#define __T4_PWM4STALL_GET_SHIFT()				M_REG_GET_SHIFT(T4_PWM4STALL_REG, T4_PWM4STALL_POS, T4_PWM4STALL_BITS)
#define __T4_PWM4STALL_SET_SHIFT(POS_EN)		M_REG_SET_SHIFT(T4_PWM4STALL_REG, T4_PWM4STALL_POS, T4_PWM4STALL_BITS, POS_EN)


//TM4CON
//T4RSTB
#define T4_T4RSTB_REG							TM4CON
#define T4_T4RSTB_POS							(2)
#define T4_T4RSTB_BITS							C_REG_BITS1
#define T4_T4RSTB_DIS							(0x01<< T4_T4RSTB_POS)
#define T4_T4RSTB_EN							(0x00<< T4_T4RSTB_POS)
#define T4_T4RSTB_MASK							(T4_T4RSTB_BITS<< T4_T4RSTB_POS)
#define __T4_T4RSTB_GET()						M_REG_GET(T4_T4RSTB_REG, T4_T4RSTB_POS, T4_T4RSTB_BITS)
#define __T4_T4RSTB_SET(EN)						M_REG_SET(T4_T4RSTB_REG, T4_T4RSTB_POS, T4_T4RSTB_BITS, EN)
#define __T4_T4RSTB_GET_SHIFT()					M_REG_GET_SHIFT(T4_T4RSTB_REG, T4_T4RSTB_POS, T4_T4RSTB_BITS)
#define __T4_T4RSTB_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(T4_T4RSTB_REG, T4_T4RSTB_POS, T4_T4RSTB_BITS, POS_EN)
/**@}*/ /*** end of group timer_reg_tm4con */

/** 
 * @addtogroup	timer_reg_tm4in reg: TM4IN 
 * @{
 */
//TM4IN
//TM4IN[7:0]
#define T4_TM4IN_REG							TM4IN
#define T4_TM4IN_POS							(0)
#define T4_TM4IN_VAL
#define T4_TM4IN_MASK							(0xFF<< T4_TM4IN_POS)
#define __T4_TM4IN_GET()						M_REG_GETBYTE(T4_TM4IN_REG, T4_TM4IN_POS)
#define __T4_TM4IN_SET(SET)						M_REG_SETBYTE(T4_TM4IN_REG, T4_TM4IN_POS, SET)
#define __T4_TM4IN_GET_SHIFT()					M_REG_GETBYTE_SHIFT(T4_TM4IN_REG, T4_TM4IN_POS)
#define __T4_TM4IN_SET_SHIFT(POS_SET)			M_REG_SETBYTE_SHIFT(T4_TM4IN_REG, T4_TM4IN_POS, POS_SET)
/**@}*/ /*** end of group timer_reg_tm4in */

/** 
 * @addtogroup	timer_reg_tm4inh reg: TM4INH 
 * @{
 */
//TM4INH
//TM4IN[11:8]
#define T4_TM4INH_REG							TM4INH
#define T4_TM4INH_POS							(0)
#define T4_TM4INH_VAL
#define T4_TM4INH_MASK							(0x0F<< T4_TM4INH_POS)
#define __T4_TM4INH_GET()						M_REG_GETBYTE(T4_TM4INH_REG, T4_TM4INH_POS)
#define __T4_TM4INH_SET(SET)					M_REG_SETBYTE(T4_TM4INH_REG, T4_TM4INH_POS, SET)
#define __T4_TM4INH_GET_SHIFT()					M_REG_GETBYTE_SHIFT(T4_TM4INH_REG, T4_TM4INH_POS)
#define __T4_TM4INH_SET_SHIFT(POS_SET)			M_REG_SETBYTE_SHIFT(T4_TM4INH_REG, T4_TM4INH_POS, POS_SET)
/**@}*/ /*** end of group timer_reg_tm4inh */

/** 
 * @addtogroup	timer_reg_tm4cnt reg: TM4CNT 
 * @attention <b>READ-ONLY</b>
 * @{
 */
//TM4CNT- Read only
//TM4CNT[7:0]
#define T4_TM4CNT_REG							TM4CNT
#define T4_TM4CNT_POS							(0)
#define T4_TM4CNT_VAL
#define T4_TM4CNT_MASK							(0xFF<< T4_TM4CNT_POS)
#define __T4_TM4CNT_GET()						M_REG_GETBYTE(T4_TM4CNT_REG, T4_TM4CNT_POS)
#define __T4_TM4CNT_GET_SHIFT()					M_REG_GETBYTE_SHIFT(T4_TM4CNT_REG, T4_TM4CNT_POS)
/**@}*/ /*** end of group timer_reg_tm4cnt */

/** 
 * @addtogroup	timer_reg_tm4cnth reg: TM4CNTH 
 * @attention <b>READ-ONLY</b>
 * @{
 */
//TM4CNTH- Read only
//TM4CNT[11:8]
#define T4_TM4CNTH_REG							TM4CNTH
#define T4_TM4CNTH_POS							(0)
#define T4_TM4CNTH_VAL
#define T4_TM4CNTH_MASK							(0x0F<< T4_TM4CNTH_POS)
#define __T4_TM4CNTH_GET()						M_REG_GETBYTE(T4_TM4CNTH_REG, T4_TM4CNTH_POS)
#define __T4_TM4CNTH_GET_SHIFT()				M_REG_GETBYTE_SHIFT(T4_TM4CNTH_REG, T4_TM4CNTH_POS)
/**@}*/ /*** end of group timer_reg_tm4cnth */

/** 
 * @addtogroup	timer_reg_tm4r reg: TM4R 
 * @{
 */
//TM4R
//TM4R[7:0]
#define T4_TM4R_REG								TM4R
#define T4_TM4R_POS								(0)
#define T4_TM4R_VAL
#define T4_TM4R_MASK							(0xFF<< T4_TM4R_POS)
#define __T4_TM4R_GET()							M_REG_GETBYTE(T4_TM4R_REG, T4_TM4R_POS)
#define __T4_TM4R_SET(SET)						M_REG_SETBYTE(T4_TM4R_REG, T4_TM4R_POS, SET)
#define __T4_TM4R_GET_SHIFT()					M_REG_GETBYTE_SHIFT(T4_TM4R_REG, T4_TM4R_POS)
#define __T4_TM4R_SET_SHIFT(POS_SET)			M_REG_SETBYTE_SHIFT(T4_TM4R_REG, T4_TM4R_POS, POS_SET)
/**@}*/ /*** end of group timer_reg_tm4r */

/** 
 * @addtogroup	timer_reg_tm4rh reg: TM4RH 
 * @{
 */
//TM4RH
//TM4R[11:8]
#define T4_TM4RH_REG							TM4RH
#define T4_TM4RH_POS							(0)
#define T4_TM4RH_VAL
#define T4_TM4RH_MASK							(0x0F<< T4_TM4RH_POS)
#define __T4_TM4RH_GET()						M_REG_GETBYTE(T4_TM4RH_REG, T4_TM4RH_POS)
#define __T4_TM4RH_SET(SET)						M_REG_SETBYTE(T4_TM4RH_REG, T4_TM4RH_POS, SET)
#define __T4_TM4RH_GET_SHIFT()					M_REG_GETBYTE_SHIFT(T4_TM4RH_REG, T4_TM4RH_POS)
#define __T4_TM4RH_SET_SHIFT(POS_SET)			M_REG_SETBYTE_SHIFT(T4_TM4RH_REG, T4_TM4RH_POS, POS_SET)
/**@}*/ /*** end of group timer_reg_tm4rh */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup csu39fx10_sdk_chip_driver_timer_cfg	timer_config
 * @{
 */
 
/** 
 * @name timer0 config
 * @{
 */
/**
 * @details <b>CFG_TIMER0_T0EN</b>
 * - <b>Features: </b> timer0 enable configuration
 * - <b>Param: </b>
 * | config	| Descriptions		|
 * | :----:	| :----:			|
 * | 0*		| enable timer0		|
 * | 1		| disable timer0	|
 */
#define	CFG_TIMER0_T0EN					(1)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_TIMER0_TM0IE</b>
 * - <b>Features: </b> timer0 interrupt enable configuration
 * - <b>Param: </b>
 * | config	| Descriptions				|
 * | :----:	| :----:					|
 * | 0*		| enable timer0 interrupt	|
 * | 1		| disable timer0 interrupt	|
 */
#define	CFG_TIMER0_TM0IE				(1)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_TIMER0_T0RSTB</b>
 * - <b>Features: </b> timer0 reset configuration
 * - <b>Param: </b>
 * | config	| Descriptions			|
 * | :----:	| :----:				|
 * | 0*		| enable timer0 reset	|
 * | 1		| disable timer0 reset	|
 */
#define	CFG_TIMER0_T0RSTB				(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_TIMER0_TIME</b>
 * - <b>Features: </b> timer0 timer configuration
 * - <b>Param: </b>
 * | config	| Unit		|
 * | :----:	| :----:	|
 * | timer*	| uS		|
 */
//#define	CFG_TIMER0_TIME					(1000)	///< {unit: 1uS}
//#define	CFG_TIMER0_TIME					(100)	///< {unit: 1uS}
#define	CFG_TIMER0_TIME					(100)	///< {unit: 1uS}

/**@}*/ /*** end of name timer0 config */

/** 
 * @name timer2 config
 * @{
 */
/**
 * @details <b>CFG_TIMER2_T2EN</b>
 * - <b>Features: </b> timer2 enable configuration
 * - <b>Param: </b>
 * | config	| Descriptions		|
 * | :----:	| :----:			|
 * | 0*		| enable timer2		|
 * | 1		| disable timer2	|
 */
#define	CFG_TIMER2_T2EN					(1)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_TIMER2_TM2IE</b>
 * - <b>Features: </b> timer2 interrupt configuration
 * - <b>Param: </b>
 * | config	| Descriptions				|
 * | :----:	| :----:					|
 * | 0*		| enable timer2 interrupt	|
 * | 1		| disable timer2 interrupt	|
 */
//#define	CFG_TIMER2_TM2IE				(0)		///< 0-> disable, 1-> enable
#define	CFG_TIMER2_TM2IE				(1)		///< 0-> disable, 1-> enable
/**
 * @details <b>CFG_TIMER2_T2RSTB</b>
 * - <b>Features: </b> timer2 reset configuration
 * - <b>Param: </b>
 * | config	| Descriptions			|
 * | :----:	| :----:				|
 * | 0*		| enable timer2 reset	|
 * | 1		| disable timer2 reset	|
 */
#define	CFG_TIMER2_T2RSTB				(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_TIMER2_PWM2STALL</b>
 * - <b>Features: </b> when icd debugging stall, timer 2 single-ended pwm output level control
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| high			|
 * | 1		| low			|
 */
#define	CFG_TIMER2_PWM2STALL			(0)		///< 0-> high, 1-> low

/**
 * @details <b>CFG_TIMER2_TIME</b>
 * - <b>Features: </b> timer2 timer configuration
 * - <b>Param: </b>
 * | config	| Unit		|
 * | :----:	| :----:	|
 * | timer*	| uS		|
 */
#define	CFG_TIMER2_TIME					(1000)	///< {unit: 1uS}

/**
 * @details <b>CFG_TIMER2_PWM2PORT</b>
 * - <b>Features: </b> timer2 port configuration
 * - <b>Param: </b>
 * | config		| Descriptions		|
 * | :----:		| :----:			|
 * | GPIO_PT23	| The only option	|
 * @attention <b>fixed configuration cannot be modified!!!</b>
 */
#define	CFG_TIMER2_PWM2PORT				GPIO_PT23	///< {@ref GPIO_PT23}

/**
 * @details <b>CFG_TIMER2_PWM2EN</b>
 * - <b>Features: </b> timer2-PWM2 enable configuration
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| enable PWM2	|
 * | 1		| disable PWM2	|
 */
//#define	CFG_TIMER2_PWM2EN				(1)		///< 0-> disable, 1-> enable
#define	CFG_TIMER2_PWM2EN				(0)		///< 0-> disable, 1-> enable
/**
 * @details <b>CFG_TIMER2_PWM_DUTY_CYCLE</b>
 * - <b>Features: </b> timer2 pwm duty cycle configuration
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0~ 100 | unit: 1%		|
 */
#define	CFG_TIMER2_PWM_DUTY_CYCLE		(50)	///< {0~100 unit: 1%}
/**@}*/ /*** end of name timer2 config */

/** 
 * @name timer3 config
 * @{
 */
/**
 * @details <b>CFG_TIMER3_T3EN</b>
 * - <b>Features: </b> timer3 enable configuration
 * - <b>Param: </b>
 * | config	| Descriptions		|
 * | :----:	| :----:			|
 * | 0*		| enable timer3		|
 * | 1		| disable timer3	|
 */
#define	CFG_TIMER3_T3EN					(1)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_TIMER3_CNT3EN</b>
 * - <b>Features: </b> counter3 enable configuration
 * - <b>Param: </b>
 * | config	| Descriptions		|
 * | :----:	| :----:			|
 * | 0*		| enable counter3	|
 * | 1		| disable counter3	|
 */
#define	CFG_TIMER3_CNT3EN				(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_TIMER3_CNT3_VAl</b>
 * - <b>Features: </b> counter3 count value configuration
 * - <b>Param: </b>
 * | config		| Descriptions	|
 * | :----:		| :----:		|
 * | 0~ 4095	| count value	|
 */
#define	CFG_TIMER3_CNT3_VAl				(0)		

/**
 * @details <b>CFG_TIMER3_TM3IE</b>
 * - <b>Features: </b> timer3 interrupt configuration
 * - <b>Param: </b>
 * | config	| Descriptions				|
 * | :----:	| :----:					|
 * | 0*		| enable timer3 interrupt	|
 * | 1		| disable timer3 interrupt	|
 */
#define	CFG_TIMER3_TM3IE				(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_TIMER3_T3RSTB</b>
 * - <b>Features: </b> timer3 reset configuration
 * - <b>Param: </b>
 * | config	| Descriptions			|
 * | :----:	| :----:				|
 * | 0*		| enable timer3 reset	|
 * | 1		| disable timer3 reset	|
 */
#define	CFG_TIMER3_T3RSTB				(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_TIMER3_PWM3STALL</b>
 * - <b>Features: </b> when icd debugging stall, timer 3 single-ended pwm output level control
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| high			|
 * | 1		| low			|
 */
#define	CFG_TIMER3_PWM3STALL			(0)		///< 0-> high, 1-> low

/**
 * @details <b>CFG_TIMER3_TIME</b>
 * - <b>Features: </b> timer3 timer configuration
 * - <b>Param: </b>
 * | config	| Unit		|
 * | :----:	| :----:	|
 * | timer*	| uS		|
 */
#define	CFG_TIMER3_TIME					(20000)	///< {unit: 1uS}

/**
 * @details <b>CFG_TIMER3_PWM3PORT</b>
 * - <b>Features: </b> timer3 port configuration
 * - <b>Param: </b>
 * | config		| Descriptions		|
 * | :----:		| :----:			|
 * | GPIO_PT24	| The only option	|
 * @attention <b>fixed configuration cannot be modified!!!</b>
 */
#define	CFG_TIMER3_PWM3PORT				GPIO_PT24	///< {@ref GPIO_PT24}

/**
 * @details <b>CFG_TIMER3_PWM3EN</b>
 * - <b>Features: </b> timer3-PWM3 enable configuration
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| enable PWM3	|
 * | 1		| disable PWM3	|
 */
#define	CFG_TIMER3_PWM3EN				(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_TIMER3_PWM_DUTY_CYCLE</b>
 * - <b>Features: </b> timer3 pwm duty cycle configuration
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0~ 100 | unit: 1%		|
 */
#define	CFG_TIMER3_PWM_DUTY_CYCLE		(95)	///< {0~100 unit: 1%}

/**
 * @details <b>CFG_TIMER3_PWM_DT3_EN</b>
 * - <b>Features: </b> timer3 pwm dead zone generator enable configuration
 * - <b>Param: </b>
 * | config	| Descriptions			|
 * | :----:	| :----:				|
 * | 0*		| enable pwm dead zone	|
 * | 1		| disable pwm dead zone	|
 */
#define	CFG_TIMER3_PWM_DT3_EN			(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_TIMER3_PWM_DT3CNT</b>
 * - <b>Features: </b>  timer3 pwm dead time configuration
 * - <b>Param: </b>
 * | config	| Unit		|
 * | :----:	| :----:	|
 * | timer*	| uS		|
 */
#define	CFG_TIMER3_PWM_DT3CNT			(0)		///< {unit: 1uS}

/**
 * @details <b>CFG_TIMER3_PWM_P3HINV</b>
 * - <b>Features: </b> complementary pwm3h output inversion control configuration
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| normal		|
 * | 1		| inverted		|
 */
#define	CFG_TIMER3_PWM_P3HINV			(0)		///< 0-> normal, 1-> inverted

/**
 * @details <b>CFG_TIMER3_PWM_P3LINV</b>
 * - <b>Features: </b> complementary pwm3h output inversion control configuration
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| normal		|
 * | 1		| inverted		|
 */
#define	CFG_TIMER3_PWM_P3LINV			(0)		///< 0-> normal, 1-> inverted
/**@}*/ /*** end of name timer3 config */

/** 
 * @name timer4 config
 * @{
 */
/**
 * @details <b>CFG_TIMER4_T4EN</b>
 * - <b>Features: </b> timer4 enable configuration
 * - <b>Param: </b>
 * | config	| Descriptions		|
 * | :----:	| :----:			|
 * | 0*		| enable timer3		|
 * | 1		| disable timer3	|
 */
#define	CFG_TIMER4_T4EN					(1)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_TIMER4_TM4IE</b>
 * - <b>Features: </b> timer4 interrupt configuration
 * - <b>Param: </b>
 * | config	| Descriptions				|
 * | :----:	| :----:					|
 * | 0*		| enable timer3 interrupt	|
 * | 1		| disable timer3 interrupt	|
 */
#define	CFG_TIMER4_TM4IE				(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_TIMER4_T4RSTB</b>
 * - <b>Features: </b> timer4 reset configuration
 * - <b>Param: </b>
 * | config	| Descriptions			|
 * | :----:	| :----:				|
 * | 0*		| enable timer3 reset	|
 * | 1		| disable timer3 reset	|
 */
#define	CFG_TIMER4_T4RSTB				(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_TIMER4_PWM4STALL</b>
 * - <b>Features: </b> when icd debugging stall, timer 4 single-ended pwm output level control
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| high			|
 * | 1		| low			|
 */
#define	CFG_TIMER4_PWM4STALL			(0)		///< 0-> high, 1-> low

/**
 * @details <b>CFG_TIMER4_TIME</b>
 * - <b>Features: </b> timer4 timer configuration
 * - <b>Param: </b>
 * | config	| Unit		|
 * | :----:	| :----:	|
 * | timer*	| uS		|
 */
#define	CFG_TIMER4_TIME					(10000)	///< {unit: 1uS}

/**
 * @details <b>CFG_TIMER4_PWM4PORT</b>
 * - <b>Features: </b> timer4 port configuration
 * - <b>Param: </b>
 * | config		| Descriptions		|
 * | :----:		| :----:			|
 * | GPIO_PT24	| The only option	|
 * @attention <b>fixed configuration cannot be modified!!!</b>
 */
#define	CFG_TIMER4_PWM4PORT				GPIO_PT12	///< {@ref GPIO_PT12}

/**
 * @details <b>CFG_TIMER4_PWM4EN</b>
 * - <b>Features: </b> timer4-PWM4 enable configuration
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| enable PWM4	|
 * | 1		| disable PWM4	|
 */
#define	CFG_TIMER4_PWM4EN				(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_TIMER4_PWM_DUTY_CYCLE</b>
 * - <b>Features: </b> timer4 pwm duty cycle configuration
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0~ 100 | unit: 1%		|
 */
#define	CFG_TIMER4_PWM_DUTY_CYCLE		(95)	///< {0~100 unit: 1%}

/**@}*/ /*** end of name timer4 config */
/**@}*/ /*** end of group csu39fx10_sdk_chip_driver_timer_cfg */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup timer_compile	attention: users do not need to care
 * @attention <b>users do not need to care</b>
 * @{
 */
/** 
 * @name timer0_compile_reg_tm0con
 * @{
 */
#if(CFG_TIMER0_T0EN!= 0)
	#define PRE_TIMER0_T0EN				1
#else
	#define PRE_TIMER0_T0EN				0
#endif

#if(CFG_TIMER0_TM0IE!= 0)
	#define PRE_TIMER0_TM0IE			1
#else
	#define PRE_TIMER0_TM0IE			0
#endif

#if(CFG_TIMER0_T0RSTB!= 0)
	#define PRE_TIMER0_T0RSTB			1
#else
	#define PRE_TIMER0_T0RSTB			0
#endif
/**@}*/ /*** end of name timer0_compile_reg_tm0con */

/** 
 * @name timer0_compile_reg_tm0in
 * @{
 */
// #define PRE_T0_TM0IN					(uint8_t)(((float)CFG_TIMER0_TIME* C_CLK_TM0CLK/ 1000/ 1000)- 1)
#define PRE_T0_TM0IN					(uint8_t)((float)CFG_TIMER0_TIME* C_CLK_TM0CLK/ 1000/ 1000)
/**@}*/ /*** end of name timer0_compile_reg_tm0in */

/** 
 * @name timer0_compile_reg_tm0cnt
 * @{
 */
#define PRE_T0_TM0CNT					0x00
/**@}*/ /*** end of name timer0_compile_reg_tm0cnt */

/** 
 * @name timer0_compile_warning
 * @attention <b>compile warning message</b>
 * @{
 */
#define	WARNING_TIMER_T0_MAX			(256* 1000* 1000/ C_CLK_TM0CLK)		//{unit: 1nS}
#define WARNING_TIMER_T0_MIN			(1* 1000* 1000/ C_CLK_TM0CLK)		//{unit: 1nS}
#if(PRE_TIMER0_T0EN)
	#if(CFG_TIMER0_TIME> WARNING_TIMER_T0_MAX)
		#warning "Warning: CFG_TIMER0_TIME define error, adjustment CFG_TIMER0_TIME or PRE_SYS_CLK_T0_DIV or PRE_SYS_CLK_T0_SOURCE!"
	#endif
	#if(CFG_TIMER0_TIME< WARNING_TIMER_T0_MIN)
		#warning "Warning: CFG_TIMER0_TIME define error, adjustment CFG_TIMER0_TIME or PRE_SYS_CLK_T0_DIV or PRE_SYS_CLK_T0_SOURCE!"
	#endif
#endif

/**@}*/ /*** end of name timer0_compile_warning */
/*******************************************************************************/


/** 
 * @name timer2_compile_port
 * @{
 */
#if(CFG_TIMER2_PWM2PORT== GPIO_PT23)
	#define P_TIMER2_PWM2_PORT			gpio_2
	#define P_TIMER2_PWM2_PIN			pin_3
#else
	#define P_TIMER2_PWM2_PORT			gpio_2
	#define P_TIMER2_PWM2_PIN			pin_3
#endif
/**@}*/ /*** end of name timer2_compile_port */

/** 
 * @name timer2_compile_reg_tm2con
 * @{
 */
#if(CFG_TIMER2_T2EN!= 0)
	#define PRE_TIMER2_T2EN				1
#else
	#define PRE_TIMER2_T2EN				0
#endif

#if(CFG_TIMER2_TM2IE!= 0)
	#define PRE_TIMER2_TM2IE			1
#else
	#define PRE_TIMER2_TM2IE			0
#endif

#if(CFG_TIMER2_PWM2STALL!= 0)
	#define PRE_TIMER2_PWM2STALL		1
#else
	#define PRE_TIMER2_PWM2STALL		0
#endif

#if(CFG_TIMER2_T2RSTB!= 0)
	#define PRE_TIMER2_T2RSTB			1
#else
	#define PRE_TIMER2_T2RSTB			0
#endif

#if(CFG_TIMER2_PWM2EN!= 0)
	#define PRE_TIMER2_PWM2EN			1
#else
	#define PRE_TIMER2_PWM2EN			0
#endif
/**@}*/ /*** end of name timer2_compile_reg_tm2con */

/** 
 * @name timer2_compile_reg_tm2in
 * @{
 */
// #define PRE_T2_TM2IN					(uint8_t)(((float)CFG_TIMER2_TIME* C_CLK_TM2CLK/ 1000/ 1000)- 1)
#define PRE_T2_TM2IN					(uint8_t)((float)CFG_TIMER2_TIME* C_CLK_TM2CLK/ 1000/ 1000)
/**@}*/ /*** end of name timer2_compile_reg_tm2in */

/** 
 * @name timer2_compile_reg_tm2r
 * @{
 */
#define PRE_T2_TM2R						(uint8_t)((float)PRE_T2_TM2IN/ 100* CFG_TIMER2_PWM_DUTY_CYCLE)
/**@}*/ /*** end of name timer2_compile_reg_tm2r */

/** 
 * @name timer2_compile_reg_tm2cnt
 * @{
 */
#define PRE_T2_TM2CNT					0x00
/**@}*/ /*** end of name timer2_compile_reg_tm2cnt */

/** 
 * @name timer2_compile_warning
 * @attention <b>compile warning message</b>
 * @{
 */
#define	C_TIMER_T2_MAX					(256* 1000* 1000/ C_CLK_TM2CLK)		//{unit: 1uS}
#define C_TIMER_T2_MIN					(1* 1000* 1000/ C_CLK_TM2CLK)		//{unit: 1uS}

#if(PRE_TIMER2_T2EN)
	#if(CFG_TIMER2_TIME> C_TIMER_T2_MAX)
		#warning "Warning: CFG_TIMER2_TIME define error, adjustment CFG_TIMER2_TIME or PRE_SYS_CLK_T2_DIV or PRE_SYS_CLK_T2_SOURCE!"
	#endif
	#if(CFG_TIMER2_TIME< C_TIMER_T2_MIN)
		#warning "Warning: CFG_TIMER2_TIME define error, adjustment CFG_TIMER2_TIME or PRE_SYS_CLK_T2_DIV or PRE_SYS_CLK_T2_SOURCE!"
	#endif
#endif

#if(PRE_TIMER2_PWM2EN)
	#if((CFG_TIMER2_PWM_DUTY_CYCLE<= 0)|| (CFG_TIMER2_PWM_DUTY_CYCLE>= 100))
		#warning "Warning: CFG_TIMER2_PWM_DUTY_CYCLE define error, will be redefined CFG_TIMER2_PWM_DUTY_CYCLE !"
	#endif
#endif
/**@}*/ /*** end of name timer2_compile_warning */
/*******************************************************************************/


/** 
 * @name timer3_compile_pwm_port
 * @{
 */
#if(CFG_TIMER3_PWM3PORT== GPIO_PT24)
	#define P_TIMER3_PWM3_PORT			gpio_2
	#define P_TIMER3_PWM3_PIN			pin_4
#else
	#define P_TIMER3_PWM3_PORT			gpio_2
	#define P_TIMER3_PWM3_PIN			pin_4
#endif

#if(CFG_TIMER3_PWM3EN!= 0)
	#define PRE_TIMER3_PWM3EN			1
#else
	#define PRE_TIMER3_PWM3EN			0
#endif
/**@}*/ /*** end of name timer3_compile_pwm_port */

/** 
 * @name timer3_compile_reg_tm3con
 * @{
 */
#if(CFG_TIMER3_T3EN!= 0)
	#define PRE_TIMER3_T3EN				1
#else
	#define PRE_TIMER3_T3EN				0
#endif

#if(CFG_TIMER3_TM3IE!= 0)
	#define PRE_TIMER3_TM3IE			1
#else
	#define PRE_TIMER3_TM3IE			0
#endif

#if(PRE_TIMER3_T3RSTB!= 0)
	#define PRE_TIMER3_T3RSTB			1
#else
	#define PRE_TIMER3_T3RSTB			0
#endif
/**@}*/ /*** end of name timer3_compile_reg_tm3con */

/** 
 * @name timer3_compile_reg_tm3in
 * @{
 */
#if(PRE_TIMER3_CNT3EN)
	#define PRE_T3_TM3IN					(uint16_t)CFG_TIMER3_CNT3_VAl
	#define PRE_T3_TM3INL					(uint8_t)(PRE_T3_TM3IN& 0xFF)
	#define PRE_T3_TM3INH					(uint8_t)((PRE_T3_TM3IN>> 8)& 0xFF)
#else
	// #define PRE_T3_TM3IN					(uint16_t)(((float)CFG_TIMER3_TIME* C_CLK_TM3CLK/ 1000/ 1000)- 1)
	#define PRE_T3_TM3IN					(uint16_t)((float)CFG_TIMER3_TIME* C_CLK_TM3CLK/ 1000/ 1000)
	#define PRE_T3_TM3INL					(uint8_t)(PRE_T3_TM3IN& 0xFF)
	#define PRE_T3_TM3INH					(uint8_t)((PRE_T3_TM3IN>> 8)& 0xFF)
#endif
/**@}*/ /*** end of name timer3_compile_reg_tm3in */

/** 
 * @name timer3_compile_reg_tm3cnt
 * @{
 */
#define PRE_TM3CNT						0x00
#define PRE_TM3CNTH						0x00
/**@}*/ /*** end of name timer3_compile_reg_tm3cnt */

/** 
 * @name timer3_compile_reg_tm3r
 * @{
 */
#define PRE_T3_TM3R						(uint16_t)((float)PRE_T3_TM3IN/ 100* CFG_TIMER3_PWM_DUTY_CYCLE)
#define PRE_T3_TM3RL					(uint8_t)(PRE_T3_TM3R& 0xFF)
#define PRE_T3_TM3RH					(uint8_t)((PRE_T3_TM3R>> 8)& 0xFF)
/**@}*/ /*** end of name timer3_compile_reg_tm3r */

/** 
 * @name timer3_compile_reg_tm3con2
 * @{
 */
#if(PRE_TIMER3_PWM3STALL!= 0)
	#define PRE_TIMER3_PWM3STALL		1
#else
	#define PRE_TIMER3_PWM3STALL		0
#endif

#define	PRE_T3_DT3CNT					(CFG_TIMER3_PWM_DT3CNT* 1000* 1000/ C_CLK_TM3CLK)

#if(CFG_TIMER3_PWM_DT3_EN!= 0)
	#define PRE_TIMER3_PWM_DT3_EN		1
#else
	#define PRE_TIMER3_PWM_DT3_EN		0
#endif

#if(CFG_TIMER3_PWM_P3HINV!= 0)
	#define PRE_TIMER3_PWM_P3HINV		1
#else
	#define PRE_TIMER3_PWM_P3HINV		0
#endif

#if(CFG_TIMER3_PWM_P3LINV!= 0)
	#define PRE_TIMER3_PWM_P3LINV		1
#else
	#define PRE_TIMER3_PWM_P3LINV		0
#endif
/**@}*/ /*** end of name timer3_compile_reg_tm3con2 */

/** 
 * @name timer3_compile_warning
 * @attention <b>compile warning message</b>
 * @{
 */
#define	WARNING_TIMER_T3_MAX			(4095u* 1000* 1000/ C_CLK_TM3CLK)		//{unit: 1uS}
#define WARNING_TIMER_T3_MIN			(1* 1000* 1000/ C_CLK_TM3CLK)			//{unit: 1uS}

#if(PRE_TIMER3_T3EN)
	#if(CFG_TIMER3_TIME> WARNING_TIMER_T3_MAX)
		#warning "Warning: CFG_TIMER3_TIME define error, adjustment CFG_TIMER3_TIME or PRE_SYS_CLK_T3_DIV or PRE_SYS_CLK_T3_SOURCE!"
	#endif
	#if(CFG_TIMER3_TIME< WARNING_TIMER_T3_MIN)
		#warning "Warning: CFG_TIMER3_TIME define error, adjustment CFG_TIMER3_TIME or PRE_SYS_CLK_T3_DIV or PRE_SYS_CLK_T3_SOURCE!"
	#endif
#endif

#if(PRE_TIMER3_PWM3EN)
	#if((CFG_TIMER3_PWM_DUTY_CYCLE<= 0)|| (CFG_TIMER3_PWM_DUTY_CYCLE>= 100))
		#warning "Warning: CFG_TIMER3_PWM_DUTY_CYCLE define error, will be redefined CFG_TIMER3_PWM_DUTY_CYCLE !"
	#endif
#endif

#if(CFG_TIMER3_PWM_DT3_EN)
	#if(PRE_T3_DT3CNT> 16)
		#warning "Warning: CFG_TIMER3_PWM_DT3CNT define error, will be redefined CFG_TIMER3_PWM_DT3CNT !"
	#endif
#endif
/**@}*/ /*** end of name timer3_compile_warning */
/*******************************************************************************/


/** 
 * @name timer4_compile_pwm_port
 * @{
 */
#if(CFG_TIMER4_PWM4PORT== GPIO_PT12)
	#define P_TIMER4_PWM4_PORT			gpio_1
	#define P_TIMER4_PWM4_PIN			pin_2
#else
	#define P_TIMER4_PWM4_PORT			gpio_1
	#define P_TIMER4_PWM4_PIN			pin_2
#endif

#if(CFG_TIMER4_PWM4EN!= 0)
	#define PRE_TIMER4_PWM4EN			1
#else
	#define PRE_TIMER4_PWM4EN			0
#endif
/**@}*/ /*** end of name timer4_compile_pwm_port */

/** 
 * @name timer4_compile_reg_tm4con
 * @{
 */
#if(PRE_TIMER4_T4EN!= 0)
	#define PRE_TIMER4_T4EN				1
#else
	#define PRE_TIMER4_T4EN				0
#endif

#if(PRE_TIMER4_TM4IE!= 0)
	#define PRE_TIMER4_TM4IE			1
#else
	#define PRE_TIMER4_TM4IE			0
#endif

#if(PRE_TIMER4_PWM4STALL!= 0)
	#define PRE_TIMER4_PWM4STALL		1
#else
	#define PRE_TIMER4_PWM4STALL		0
#endif

#if(PRE_TIMER4_T4RSTB!= 0)
	#define PRE_TIMER4_T4RSTB			1
#else
	#define PRE_TIMER4_T4RSTB			0
#endif
/**@}*/ /*** end of name timer4_compile_reg_tm4con */

/** 
 * @name timer4_compile_reg_tm4in
 * @{
 */
// #define PRE_T4_TM4IN					(uint16_t)(((float)CFG_TIMER4_TIME* C_CLK_TM4CLK/ 1000/ 1000)- 1)
#define PRE_T4_TM4IN					(uint16_t)((float)CFG_TIMER4_TIME* C_CLK_TM4CLK/ 1000/ 1000)
#define PRE_T4_TM4INL					(uint8_t)(PRE_T4_TM4IN& 0xFF)
#define PRE_T4_TM4INH					(uint8_t)((PRE_T4_TM4IN>> 8)& 0xFF)
/**@}*/ /*** end of name timer4_compile_reg_tm4in */

/** 
 * @name timer4_compile_reg_tm4cnt
 * @{
 */
#define PRE_TM4CNT						0x00
#define PRE_TM4CNTH						0x00
/**@}*/ /*** end of name timer3_compile_reg_tm3cnt */

/** 
 * @name timer4_compile_reg_tm4r
 * @{
 */
#define PRE_T4_TM4R						(uint16_t)((float)PRE_T4_TM4IN/ 100 * CFG_TIMER4_PWM_DUTY_CYCLE)
#define PRE_T4_TM4RL					(uint8_t)(PRE_T4_TM4R& 0xFF)
#define PRE_T4_TM4RH					(uint8_t)((PRE_T4_TM4R>> 8)& 0xFF)
/**@}*/ /*** end of name timer4_compile_reg_tm4r */

/** 
 * @name timer4_compile_warning
 * @attention <b>compile warning message</b>
 * @{
 */
#define	WARNING_TIMER_T4_MAX			(4095u* 1000* 1000/ C_CLK_TM4CLK)		//{unit: 1uS}
#define WARNING_TIMER_T4_MIN			(1* 1000* 1000/ C_CLK_TM4CLK)			//{unit: 1uS}

#if(PRE_TIMER4_T4EN)
	#if(CFG_TIMER4_TIME> WARNING_TIMER_T4_MAX)
		#warning "Warning: CFG_TIMER4_TIME define error, adjustment CFG_TIMER4_TIME or PRE_SYS_CLK_T4_DIV or PRE_SYS_CLK_T4_SOURCE!"
	#endif
	#if(CFG_TIMER4_TIME< WARNING_TIMER_T4_MIN)
		#warning "Warning: CFG_TIMER4_TIME define error, adjustment CFG_TIMER4_TIME or PRE_SYS_CLK_T4_DIV or PRE_SYS_CLK_T4_SOURCE!"
	#endif
#endif

#if(PRE_TIMER4_PWM4EN)
	#if((CFG_TIMER4_PWM_DUTY_CYCLE<= 0)|| (CFG_TIMER4_PWM_DUTY_CYCLE>= 100))
		#warning "Warning: CFG_TIMER4_PWM_DUTY_CYCLE define error, will be redefined CFG_TIMER4_PWM_DUTY_CYCLE !"
	#endif
#endif
/**@}*/ /*** end of name timer4_compile_warning */
/**@}*/ /*** end of group timer_compile */
/*******************************************************************************/




/******************************** dividing line ********************************/
/**
 * @addtogroup timer_reg_default	reg_default_value
 * @{
 */
/** 
 * @name timer0_reg
 * @par 示例
 * @code
 *		void test( void )
 *		{
 *			//Initialization register(According to the macro definition CFG_XX_XX)
 *			TM0CON= PRE_TM0CON_DEFAULT;
 *			TM0IN= PRE_TM0IN_DEFAULT;
 *			TM0CNT= PRE_TM0CNT_DEFAULT;
 *		#if(PRE_TIMER0_TM0IE)
 *			GIE= true;
 *		#endif
 *		}
 * @endcode
 * @{
 */
#define PRE_TM0CON_DEFAULT				(((PRE_TIMER0_T0EN<< T0_T0EN_POS)& T0_T0EN_MASK)|				\
											((PRE_TIMER0_TM0IE<< T0_TM0IE_POS)& T0_TM0IE_MASK)|			\
											((PRE_TIMER0_T0RSTB<< T0_T0RSTB_POS)& T0_T0RSTB_MASK))
#define PRE_TM0IN_DEFAULT				((PRE_T0_TM0IN<< T0_TM0IN_POS)& T0_TM0IN_MASK)
#define PRE_TM0CNT_DEFAULT				PRE_T0_TM0CNT
/**@}*/ /*** end of name timer0_reg */


/** 
 * @name timer2_reg
 * @par 示例
 * @code
 *		void test( void )
 *		{
 *		#if(PRE_TIMER2_PWM2EN)
 *			// gpio cfg
 *			//Initialization register(According to the macro definition CFG_XX_XX)
 *			gpio_config_t	gpio_cfg;
 *			gpio_cfg.gpio_portx= P_TIMER2_PWM2_PORT;
 *			gpio_cfg.gpio_pinx= P_TIMER2_PWM2_PIN;
 *			gpio_cfg.gpio_pinmux= pinmux_func3;
 *			gpio_cfg.gpio_dir= dir_output;
 *			gpio_cfg.gpio_mode= mode_pp;
 *			gpio_cfg.gpio_pull= no_pull;
 *			gpio_init(&gpio_cfg);
 *		#endif
 *			TM2CON= PRE_TM2CON_DEFAULT;
 *			TM2IN= PRE_TM2IN_DEFAULT;
 *			TM2CNT= PRE_TM2CNT_DEFAULT;
 *			TM2R= PRE_TM2R_DEFAULT;
 *		#if(PRE_TIMER2_TM2IE)
 *			GIE= true;
 *		#endif
 *		}
 * @endcode
 * @{
 */
#define PRE_TM2CON_DEFAULT				(((PRE_TIMER2_T2EN<< T2_T2EN_POS)& T2_T2EN_MASK)|						\
											((PRE_TIMER2_TM2IE<< T2_TM2IE_POS)& T2_TM2IE_MASK)|					\
											((PRE_TIMER2_PWM2STALL<< T2_PWM2STALL_POS)& T2_PWM2STALL_MASK)|		\
											((PRE_TIMER2_T2RSTB<< T2_T2RSTB_POS)& T2_T2RSTB_MASK))
#define PRE_TM2IN_DEFAULT				((PRE_T2_TM2IN<< T2_TM2IN_POS)& T2_TM2IN_MASK)
#define PRE_TM2CNT_DEFAULT				PRE_T2_TM2CNT
#define PRE_TM2R_DEFAULT				((PRE_T2_TM2R<< T2_TM2R_POS)& T2_TM2R_MASK)
/**@}*/ /*** end of name timer2_reg */


/** 
 * @name timer3_reg
 * @par 示例
 * @code
 *		void test( void )
 *		{
 *		#if(PRE_TIMER3_PWM3EN)
 *			//gpio cfg
 *			gpio_config_t		gpio_cfg;
 *			gpio_cfg.gpio_portx= P_TIMER3_PWM3_PORT;
 *			gpio_cfg.gpio_pinx= P_TIMER3_PWM3_PIN;
 *			gpio_cfg.gpio_pinmux= pinmux_func3;
 *			gpio_cfg.gpio_dir= dir_output;
 *			gpio_cfg.gpio_mode= mode_pp;
 *			gpio_cfg.gpio_pull= no_pull;
 *			gpio_init(&gpio_cfg);
 *		#endif
 *			TM3CON= PRE_TM3CON_DEFAULT;
 *			TM3IN= PRE_TM3IN_DEFAULT;
 *			TM3INH= PRE_TM3INH_DEFAULT;
 *			TM3CNT= PRE_TM3CNT_DEFAULT;
 *			TM3CNTH= PRE_TM3CNTH_DEFAULT;
 *			TM3R= PRE_TM3R_DEFAULT;
 *			TM3RH= PRE_TM3RH_DEFAULT;
 *			TM3CON2= PRE_TM3CON2_DEFAULT;
 *		#if(PRE_TIMER3_TM3IE)
 *			GIE= true;
 *		#endif
 *		}
 * @endcode
 * @{
 */
#define PRE_TM3CON_DEFAULT				(((PRE_TIMER3_T3EN<< T3_T3EN_POS)& T3_T3EN_MASK)|					\
											((PRE_TIMER3_TM3IE<< T3_TM3IE_POS)& T3_TM3IE_MASK)|				\
											((PRE_TIMER3_T3RSTB<< T3_T3RSTB_POS)& T3_T3RSTB_MASK))
#define PRE_TM3IN_DEFAULT				((PRE_T3_TM3INL<< T3_TM3IN_POS)& T3_TM3IN_MASK)
#define PRE_TM3INH_DEFAULT				((PRE_T3_TM3INH<< T3_TM3INH_POS)& T3_TM3INH_MASK)
#define PRE_TM3CNT_DEFAULT				PRE_TM3CNT	
#define PRE_TM3CNTH_DEFAULT				PRE_TM3CNTH
#define PRE_TM3R_DEFAULT				((PRE_T3_TM3RL<< T3_TM3R_POS)& T3_TM3R_MASK)
#define PRE_TM3RH_DEFAULT				((PRE_T3_TM3RH<< T3_TM3RH_POS)& T3_TM3RH_MASK)
#define PRE_TM3CON2_DEFAULT				(((PRE_TIMER3_PWM3STALL<< T3_PWM3STALL_POS)& T3_PWM3STALL_MASK)|	\
											((PRE_T3_DT3CNT<< T3_DT3CNT_POS)& T3_DT3CNT_POS)|				\
											((PRE_TIMER3_PWM_DT3_EN<< T3_DT3_EN_POS)& T3_DT3_EN_MASK)|		\
											((PRE_TIMER3_PWM_P3HINV<< T3_P3HINV_POS)& T3_P3HINV_MASK)|		\
											((PRE_TIMER3_PWM_P3LINV<< T3_P3LINV_POS)& T3_P3LINV_MASK))
/**@}*/ /*** end of name timer3_reg */


/** 
 * @name timer4_reg
 * @par 示例
 * @code
 *		void test( void )
 *		{
 *		#if(PRE_TIMER4_PWM4EN)
 *			//gpio cfg
 *			gpio_config_t		gpio_cfg;
 *			gpio_cfg.gpio_portx= P_TIMER4_PWM4_PORT;
 *			gpio_cfg.gpio_pinx= P_TIMER4_PWM4_PIN;
 *			gpio_cfg.gpio_pinmux= pinmux_func2;
 *			gpio_cfg.gpio_dir= dir_output;
 *			gpio_cfg.gpio_mode= mode_pp;
 *			gpio_cfg.gpio_pull= no_pull;
 *			gpio_init(&gpio_cfg);
 *		#endif
 *			TM4CON= PRE_TM4CON_DEFAULT;
 *			TM4IN= PRE_TM4IN_DEFAULT;
 *			TM4INH= PRE_TM4INH_DEFAULT;
 *			TM4CNT= PRE_TM4CNT_DEFAULT;
 *			TM4CNTH= PRE_TM4CNTH_DEFAULT;
 *			TM4R= PRE_TM4R_DEFAULT;
 *			TM4RH= PRE_TM4RH_DEFAULT;
 *		#if(PRE_TIMER4_TM4IE)
 *			GIE= true;
 *		#endif
 *		}
 * @endcode
 * @{
 */
#define PRE_TM4CON_DEFAULT				(((PRE_TIMER4_T4EN<< T4_T4EN_POS)& T4_T4EN_MASK)|						\
											((PRE_TIMER4_TM4IE<< T4_TM4IE_POS)& T4_TM4IE_MASK)|					\
											((PRE_TIMER4_PWM4STALL<< T4_PWM4STALL_POS)& T4_PWM4STALL_MASK)|		\
											((PRE_TIMER4_T4RSTB<< T4_T4RSTB_POS)& T4_T4RSTB_MASK))
#define PRE_TM4IN_DEFAULT				((PRE_T4_TM4INL<< T4_TM4IN_POS)& T4_TM4IN_MASK)
#define PRE_TM4INH_DEFAULT				((PRE_T4_TM4INH<< T4_TM4INH_POS)& T4_TM4INH_MASK)
#define PRE_TM4CNT_DEFAULT				PRE_TM4CNT	
#define PRE_TM4CNTH_DEFAULT				PRE_TM4CNTH
#define PRE_TM4R_DEFAULT				((PRE_T4_TM4RL<< T4_TM4R_POS)& T4_TM4R_MASK)
#define PRE_TM4RH_DEFAULT				((PRE_T4_TM4RH<< T4_TM4RH_POS)& T4_TM4RH_MASK)
/**@}*/ /*** end of name timer4_reg */
/**@}*/ /*** end of group timer_reg_default */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup timer_api	api
 * @{
 */
/** 
 * @name timer0_api
 * @{
 */
/**
 * @brief 	<b>Description:</b> timer0 initialization.
 * @details <b>Function prototype:</b> void timer0_init(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			timer0_init();
 *		}
 * @endcode
 */
void timer0_init(void);

/**
 * @brief 	<b>Description:</b> timer0 enable.
 * @details <b>Function prototype:</b> void timer0_enable(void);
 * @param[in]  null .
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			timer0_enable();
 *		}
 * @endcode
 */
void timer0_enable(void);

/**
 * @brief 	<b>Description:</b> timer0 disable.
 * @details <b>Function prototype:</b> void timer0_disable(void);
 * @param[in]  null	.
 * @param[out] null	.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			timer0_disable();
 *		}
 * @endcode
 */
void timer0_disable(void);
/**@}*/ /*** end of name timer0_api */


/** 
 * @name timer2_api
 * @{
 */
/**
 * @brief 	<b>Description:</b> timer2 initialization.
 * @details <b>Function prototype:</b> void timer2_init(void);
 * @param[in]  null	.
 * @param[out] null	.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			timer2_init();
 *		}
 * @endcode
 */
void timer2_init(void);

/**
 * @brief 	<b>Description:</b> timer2 enable.
 * @details <b>Function prototype:</b> void timer2_enable(void);
 * @param[in]  null	.
 * @param[out] null	.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			timer2_enable();
 *		}
 * @endcode
 */
void timer2_enable(void);

/**
 * @brief 	<b>Description:</b> timer2 disable.
 * @details <b>Function prototype:</b> void timer2_disable(void);
 * @param[in]  null	.
 * @param[out] null	.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			timer2_disable();
 *		}
 * @endcode
 */
void timer2_disable(void);
/**@}*/ /*** end of name timer2_api */


/** 
 * @name timer3_api
 * @{
 */
/**
 * @brief 	<b>Description:</b> timer3 initialization.
 * @details <b>Function prototype:</b> void timer3_init(void);
 * @param[in]  null	.
 * @param[out] null	.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			timer3_init();
 *		}
 * @endcode
 */
void timer3_init(void);

/**
 * @brief 	<b>Description:</b> timer3 enable.
 * @details <b>Function prototype:</b> void timer3_enable(void);
 * @param[in]  null	.
 * @param[out] null	.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			timer3_enable();
 *		}
 * @endcode
 */
void timer3_enable(void);

/**
 * @brief 	<b>Description:</b> timer3 disable.
 * @details <b>Function prototype:</b> void timer3_disable(void);
 * @param[in]  null	.
 * @param[out] null	.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			timer3_disable();
 *		}
 * @endcode
 */
void timer3_disable(void);
/**@}*/ /*** end of name timer3_api */


/** 
 * @name timer4_api
 * @{
 */
/**
 * @brief 	<b>Description:</b> timer4 initialization.
 * @details <b>Function prototype:</b> void timer4_init(void);
 * @param[in]  null	.
 * @param[out] null	.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			timer4_init();
 *		}
 * @endcode
 */
void timer4_init(void);

/**
 * @brief 	<b>Description:</b> timer4 enable.
 * @details <b>Function prototype:</b> void timer4_enable(void);
 * @param[in]  null	.
 * @param[out] null	.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			timer4_enable();
 *		}
 * @endcode
 */
void timer4_enable(void);

/**
 * @brief 	<b>Description:</b> timer4 disable.
 * @details <b>Function prototype:</b> void timer4_disable(void);
 * @param[in]  null	.
 * @param[out] null	.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			timer4_disable();
 *		}
 * @endcode
 */
void timer4_disable(void);
/**@}*/ /*** end of name timer4_api */
/**@}*/ /*** end of group timer_api */
/**@}*/ /*** end of group csu39fx10_sdk_chip_driver_timer */
/**@}*/ /*** end of group csu39fx10_sdk_chip_driver */
/**@}*/ /*** end of group csu39fx10_sdk_chip */
/*******************************************************************************/




#ifdef __cplusplus
}
#endif

#endif  //__DRV_TIMER_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/
