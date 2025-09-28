/***************************************************************************
 * @file     csu39fx10_exti.h
 * @version  V1.0.0
 * @author   0531
 * @date     2020-10-09 PM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 ****************************************************************************
 * @par 头文件
 *       csu39fx10.h \n
 *       cs_common.h \n
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

#ifndef __CSU39FX10_EXTI_H__
#define __CSU39FX10_EXTI_H__

// Include external header file.
#include "csu39fx10.h"
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
 * @addtogroup csu39fx10_sdk_chip_fwlib_exti	exti
 * @{
 */

/** 
 * @addtogroup	exti_reg_exicon	reg: EXICON 
 * @{
 */
//EXICON
//E2M[1:0]
#define EXI_E2M_REG									EXICON
#define EXI_E2M_POS									(4)
#define EXI_E2M_BITS								C_REG_BITS2
#define EXI_E2M_RAISING								(0x00<< EXI_E2M_POS)
#define EXI_E2M_FALLING								(0x01<< EXI_E2M_POS)
#define EXI_E2M_TOGGLE								(0x02<< EXI_E2M_POS)
#define EXI_E2M_MASK								(EXI_E2M_BITS<< EXI_E2M_POS)
#define __EXI_E2M_GET()								M_REG_GET(EXI_E2M_REG, EXI_E2M_POS, EXI_E2M_BITS)
#define __EXI_E2M_SET(SET)							M_REG_SET(EXI_E2M_REG, EXI_E2M_POS, EXI_E2M_BITS, SET)
#define __EXI_E2M_GET_SHIFT()						M_REG_GET_SHIFT(EXI_E2M_REG, EXI_E2M_POS, EXI_E2M_BITS)
#define __EXI_E2M_SET_SHIFT(POS_SET)				M_REG_SET_SHIFT(EXI_E2M_REG, EXI_E2M_POS, EXI_E2M_BITS, POS_SET)

//E1M[1:0]
#define EXI_E1M_REG									EXICON
#define EXI_E1M_POS									(2)
#define EXI_E1M_BITS								C_REG_BITS2
#define EXI_E1M_RAISING								(0x00<< EXI_E1M_POS)
#define EXI_E1M_FALLING								(0x01<< EXI_E1M_POS)
#define EXI_E1M_TOGGLE								(0x02<< EXI_E1M_POS)
#define EXI_E1M_MASK								(EXI_E1M_BITS<< EXI_E1M_POS)
#define __EXI_E1M_GET()								M_REG_GET(EXI_E1M_REG, EXI_E1M_POS, EXI_E1M_BITS)
#define __EXI_E1M_SET(SET)							M_REG_SET(EXI_E1M_REG, EXI_E1M_POS, EXI_E1M_BITS, SET)
#define __EXI_E1M_GET_SHIFT()						M_REG_GET_SHIFT(EXI_E1M_REG, EXI_E1M_POS, EXI_E1M_BITS)
#define __EXI_E1M_SET_SHIFT(POS_SET)				M_REG_SET_SHIFT(EXI_E1M_REG, EXI_E1M_POS, EXI_E1M_BITS, POS_SET)

//E0M[1:0]
#define EXI_E0M_REG									EXICON
#define EXI_E0M_POS									(0)
#define EXI_E0M_BITS								C_REG_BITS2
#define EXI_E0M_RAISING								(0x00<< EXI_E0M_POS)
#define EXI_E0M_FALLING								(0x01<< EXI_E0M_POS)
#define EXI_E0M_TOGGLE								(0x02<< EXI_E0M_POS)
#define EXI_E0M_MASK								(EXI_E0M_BITS<< EXI_E0M_POS)
#define __EXI_E0M_GET()								M_REG_GET(EXI_E0M_REG, EXI_E0M_POS, EXI_E0M_BITS)
#define __EXI_E0M_SET(SET)							M_REG_SET(EXI_E0M_REG, EXI_E0M_POS, EXI_E0M_BITS, SET)
#define __EXI_E0M_GET_SHIFT()						M_REG_GET_SHIFT(EXI_E0M_REG, EXI_E0M_POS, EXI_E0M_BITS)
#define __EXI_E0M_SET_SHIFT(POS_SET)				M_REG_SET_SHIFT(EXI_E0M_REG, EXI_E0M_POS, EXI_E0M_BITS, POS_SET)
/**@}*/ /*** end of group exti_reg_exicon */

/** 
 * @addtogroup	exti_reg_exiie	reg: EXIIE 
 * @{
 */
//EXIIE
//E2IE
#define EXI_E2IE_REG								EXIIE
#define EXI_E2IE_POS								(2)
#define EXI_E2IE_BITS								C_REG_BITS1
#define EXI_E2IE_DIS								(0x00<< EXI_E2IE_POS)
#define EXI_E2IE_EN									(0x01<< EXI_E2IE_POS)
#define EXI_E2IE_MASK								(EXI_E2IE_BITS<< EXI_E2IE_POS)
#define __EXI_E2IE_GET()							M_REG_GET(EXI_E2IE_REG, EXI_E2IE_POS, EXI_E2IE_BITS)
#define __EXI_E2IE_SET(EN)							M_REG_SET(EXI_E2IE_REG, EXI_E2IE_POS, EXI_E2IE_BITS, EN)
#define __EXI_E2IE_GET_SHIFT()						M_REG_GET_SHIFT(EXI_E2IE_REG, EXI_E2IE_POS, EXI_E2IE_BITS)
#define __EXI_E2IE_SET_SHIFT(POS_EN)				M_REG_SET_SHIFT(EXI_E2IE_REG, EXI_E2IE_POS, EXI_E2IE_BITS, POS_EN)

//E1IE
#define EXI_E1IE_REG								EXIIE
#define EXI_E1IE_POS								(1)
#define EXI_E1IE_BITS								C_REG_BITS1
#define EXI_E1IE_DIS								(0x00<< EXI_E1IE_POS)
#define EXI_E1IE_EN									(0x01<< EXI_E1IE_POS)
#define EXI_E1IE_MASK								(EXI_E1IE_BITS<< EXI_E1IE_POS)
#define __EXI_E1IE_GET()							M_REG_GET(EXI_E1IE_REG, EXI_E1IE_POS, EXI_E1IE_BITS)
#define __EXI_E1IE_SET(EN)							M_REG_SET(EXI_E1IE_REG, EXI_E1IE_POS, EXI_E1IE_BITS, EN)
#define __EXI_E1IE_GET_SHIFT()						M_REG_GET_SHIFT(EXI_E1IE_REG, EXI_E1IE_POS, EXI_E1IE_BITS)
#define __EXI_E1IE_SET_SHIFT(POS_EN)				M_REG_SET_SHIFT(EXI_E1IE_REG, EXI_E1IE_POS, EXI_E1IE_BITS, POS_EN)

//E0IE
#define EXI_E0IE_REG								EXIIE
#define EXI_E0IE_POS								(0)
#define EXI_E0IE_BITS								C_REG_BITS1
#define EXI_E0IE_DIS								(0x00<< EXI_E0IE_POS)
#define EXI_E0IE_EN									(0x01<< EXI_E0IE_POS)
#define EXI_E0IE_MASK								(EXI_E0IE_BITS<< EXI_E0IE_POS)
#define __EXI_E0IE_GET()							M_REG_GET(EXI_E0IE_REG, EXI_E0IE_POS, EXI_E0IE_BITS)
#define __EXI_E0IE_SET(EN)							M_REG_SET(EXI_E0IE_REG, EXI_E0IE_POS, EXI_E0IE_BITS, EN)
#define __EXI_E0IE_GET_SHIFT()						M_REG_GET_SHIFT(EXI_E0IE_REG, EXI_E0IE_POS, EXI_E0IE_BITS)
#define __EXI_E0IE_SET_SHIFT(POS_EN)				M_REG_SET_SHIFT(EXI_E0IE_REG, EXI_E0IE_POS, EXI_E0IE_BITS, POS_EN)
/**@}*/ /*** end of group exti_reg_exiie */

/** 
 * @addtogroup	exti_reg_exiif	reg: EXIIF 
 * @{
 */
//EXIIF
//E2IF
#define EXI_E2IF_REG								EXIIF
#define EXI_E2IF_POS								(2)
#define EXI_E2IF_BITS								C_REG_BITS1
#define EXI_E2IF_RESET								(0x00<< EXI_E2IF_POS)
#define EXI_E2IF_SET								(0x01<< EXI_E2IF_POS)
#define EXI_E2IF_CLR								(0x00<< EXI_E2IF_POS)
#define EXI_E2IF_MASK								(EXI_E2IF_BITS<< EXI_E2IF_POS)
#define __EXI_E2IF_GET()							M_REG_GET(EXI_E2IF_REG, EXI_E2IF_POS, EXI_E2IF_BITS)
#define __EXI_E2IF_SET(CLR)							M_REG_SET(EXI_E2IF_REG, EXI_E2IF_POS, EXI_E2IF_BITS, CLR)
#define __EXI_E2IF_GET_SHIFT()						M_REG_GET_SHIFT(EXI_E2IF_REG, EXI_E2IF_POS, EXI_E2IF_BITS)
#define __EXI_E2IF_SET_SHIFT(POS_CLR)				M_REG_SET_SHIFT(EXI_E2IF_REG, EXI_E2IF_POS, EXI_E2IF_BITS, POS_CLR)

//E1IF
#define EXI_E1IF_REG								EXIIF
#define EXI_E1IF_POS								(1)
#define EXI_E1IF_BITS								C_REG_BITS1
#define EXI_E1IF_RESET								(0x00<< EXI_E1IF_POS)
#define EXI_E1IF_SET								(0x01<< EXI_E1IF_POS)
#define EXI_E1IF_CLR								(0x00<< EXI_E1IF_POS)
#define EXI_E1IF_MASK								(EXI_E1IF_BITS<< EXI_E1IF_POS)
#define __EXI_E1IF_GET()							M_REG_GET(EXI_E1IF_REG, EXI_E1IF_POS, EXI_E1IF_BITS)
#define __EXI_E1IF_SET(CLR)							M_REG_SET(EXI_E1IF_REG, EXI_E1IF_POS, EXI_E1IF_BITS, CLR)
#define __EXI_E1IF_GET_SHIFT()						M_REG_GET_SHIFT(EXI_E1IF_REG, EXI_E1IF_POS, EXI_E1IF_BITS)
#define __EXI_E1IF_SET_SHIFT(POS_CLR)				M_REG_SET_SHIFT(EXI_E1IF_REG, EXI_E1IF_POS, EXI_E1IF_BITS, POS_CLR)

//E0IF
#define EXI_E0IF_REG								EXIIF
#define EXI_E0IF_POS								(0)
#define EXI_E0IF_BITS								C_REG_BITS1
#define EXI_E0IF_RESET								(0x00<< EXI_E0IF_POS)
#define EXI_E0IF_SET								(0x01<< EXI_E0IF_POS)
#define EXI_E0IF_CLR								(0x00<< EXI_E0IF_POS)
#define EXI_E0IF_MASK								(EXI_E0IF_BITS<< EXI_E0IE_POS)
#define __EXI_E0IF_GET()							M_REG_GET(EXI_E0IF_REG, EXI_E0IF_POS, EXI_E0IF_BITS)
#define __EXI_E0IF_SET(CLR)							M_REG_SET(EXI_E0IF_REG, EXI_E0IF_POS, EXI_E0IF_BITS, CLR)
#define __EXI_E0IF_GET_SHIFT()						M_REG_GET_SHIFT(EXI_E0IF_REG, EXI_E0IF_POS, EXI_E0IF_BITS)
#define __EXI_E0IF_SET_SHIFT(POS_CLR)				M_REG_SET_SHIFT(EXI_E0IF_REG, EXI_E0IF_POS, EXI_E0IF_BITS, POS_CLR)
/**@}*/ /*** end of group exti_reg_exiif */

/** 
 * @addtogroup	exti_reg_intcfg1	reg: INTCFG1 
 * @{
 */
//INTCFG1
//PT1INT_3
#define EXI_PT1INT_PT15_REG							INTCFG1
#define EXI_PT1INT_PT15_POS							(5)
#define EXI_PT1INT_PT15_BITS						C_REG_BITS1
#define EXI_PT1INT_PT15_DIS							(0x00<< EXI_PT1INT_PT15_POS)
#define EXI_PT1INT_PT15_EN							(0x01<< EXI_PT1INT_PT15_POS)
#define EXI_PT1INT_PT15_MASK						(EXI_PT1INT_PT15_BITS<< EXI_PT1INT_PT15_POS)
#define __EXI_PT1INT_PT15_GET()						M_REG_GET(EXI_PT1INT_PT15_REG, EXI_PT1INT_PT15_POS, EXI_PT1INT_PT15_BITS)
#define __EXI_PT1INT_PT15_SET(EN)					M_REG_SET(EXI_PT1INT_PT15_REG, EXI_PT1INT_PT15_POS, EXI_PT1INT_PT15_BITS, EN)
#define __EXI_PT1INT_PT15_GET_SHIFT()				M_REG_GET_SHIFT(EXI_PT1INT_PT15_REG, EXI_PT1INT_PT15_POS, EXI_PT1INT_PT15_BITS)
#define __EXI_PT1INT_PT15_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(EXI_PT1INT_PT15_REG, EXI_PT1INT_PT15_POS, EXI_PT1INT_PT15_BITS, POS_EN)

//PT1INT_2
#define EXI_PT1INT_PT14_REG							INTCFG1
#define EXI_PT1INT_PT14_POS							(4)
#define EXI_PT1INT_PT14_BITS						C_REG_BITS1
#define EXI_PT1INT_PT14_DIS							(0x00<< EXI_PT1INT_PT14_POS)
#define EXI_PT1INT_PT14_EN							(0x01<< EXI_PT1INT_PT14_POS)
#define EXI_PT1INT_PT14_MASK						(EXI_PT1INT_PT14_BITS<< EXI_PT1INT_PT14_POS)
#define __EXI_PT1INT_PT14_GET()						M_REG_GET(EXI_PT1INT_PT14_REG, EXI_PT1INT_PT14_POS, EXI_PT1INT_PT14_BITS)
#define __EXI_PT1INT_PT14_SET(EN)					M_REG_SET(EXI_PT1INT_PT14_REG, EXI_PT1INT_PT14_POS, EXI_PT1INT_PT14_BITS, EN)
#define __EXI_PT1INT_PT14_GET_SHIFT()				M_REG_GET_SHIFT(EXI_PT1INT_PT14_REG, EXI_PT1INT_PT14_POS, EXI_PT1INT_PT14_BITS)
#define __EXI_PT1INT_PT14_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(EXI_PT1INT_PT14_REG, EXI_PT1INT_PT14_POS, EXI_PT1INT_PT14_BITS, POS_EN)

//PT1INT_1
#define EXI_PT1INT_PT13_REG							INTCFG1
#define EXI_PT1INT_PT13_POS							(3)
#define EXI_PT1INT_PT13_BITS						C_REG_BITS1
#define EXI_PT1INT_PT13_DIS							(0x00<< EXI_PT1INT_PT13_POS)
#define EXI_PT1INT_PT13_EN							(0x01<< EXI_PT1INT_PT13_POS)
#define EXI_PT1INT_PT13_MASK						(EXI_PT1INT_PT13_BITS<< EXI_PT1INT_PT13_POS)
#define __EXI_PT1INT_PT13_GET()						M_REG_GET(EXI_PT1INT_PT13_REG, EXI_PT1INT_PT13_POS, EXI_PT1INT_PT13_BITS)
#define __EXI_PT1INT_PT13_SET(EN)					M_REG_SET(EXI_PT1INT_PT13_REG, EXI_PT1INT_PT13_POS, EXI_PT1INT_PT13_BITS, EN)
#define __EXI_PT1INT_PT13_GET_SHIFT()				M_REG_GET_SHIFT(EXI_PT1INT_PT13_REG, EXI_PT1INT_PT13_POS, EXI_PT1INT_PT13_BITS)
#define __EXI_PT1INT_PT13_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(EXI_PT1INT_PT13_REG, EXI_PT1INT_PT13_POS, EXI_PT1INT_PT13_BITS, POS_EN)

//PT1INT_0
#define EXI_PT1INT_PT12_REG							INTCFG1
#define EXI_PT1INT_PT12_POS							(3)
#define EXI_PT1INT_PT12_BITS						C_REG_BITS1
#define EXI_PT1INT_PT12_DIS							(0x00<< EXI_PT1INT_PT12_POS)
#define EXI_PT1INT_PT12_EN							(0x01<< EXI_PT1INT_PT12_POS)
#define EXI_PT1INT_PT12_MASK						(EXI_PT1INT_PT12_BITS<< EXI_PT1INT_PT12_POS)
#define __EXI_PT1INT_PT12_GET()						M_REG_GET(EXI_PT1INT_PT12_REG, EXI_PT1INT_PT12_POS, EXI_PT1INT_PT12_BITS)
#define __EXI_PT1INT_PT12_SET(EN)					M_REG_SET(EXI_PT1INT_PT12_REG, EXI_PT1INT_PT12_POS, EXI_PT1INT_PT12_BITS, EN)
#define __EXI_PT1INT_PT12_GET_SHIFT()				M_REG_GET_SHIFT(EXI_PT1INT_PT12_REG, EXI_PT1INT_PT12_POS, EXI_PT1INT_PT12_BITS)
#define __EXI_PT1INT_PT12_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(EXI_PT1INT_PT12_REG, EXI_PT1INT_PT12_POS, EXI_PT1INT_PT12_BITS, POS_EN)
/**@}*/ /*** end of group exti_reg_intcfg1 */

/** 
 * @addtogroup	exti_reg_intcfg2	reg: INTCFG2 
 * @{
 */
//INTCFG2
//PT2INT_4
#define EXI_PT2INT_PT26_REG							INTCFG2
#define EXI_PT2INT_PT26_POS							(6)
#define EXI_PT2INT_PT26_BITS						C_REG_BITS1
#define EXI_PT2INT_PT26_DIS							(0x00<< EXI_PT2INT_PT26_POS)
#define EXI_PT2INT_PT26_EN							(0x01<< EXI_PT2INT_PT26_POS)
#define EXI_PT2INT_PT26_MASK						(EXI_PT2INT_PT26_BITS<< EXI_PT2INT_PT26_POS)
#define __EXI_PT2INT_PT26_GET()						M_REG_GET(EXI_PT2INT_PT26_REG, EXI_PT2INT_PT26_POS, EXI_PT2INT_PT26_BITS)
#define __EXI_PT2INT_PT26_SET(EN)					M_REG_SET(EXI_PT2INT_PT26_REG, EXI_PT2INT_PT26_POS, EXI_PT2INT_PT26_BITS, EN)
#define __EXI_PT2INT_PT26_GET_SHIFT()				M_REG_GET_SHIFT(EXI_PT2INT_PT26_REG, EXI_PT2INT_PT26_POS, EXI_PT2INT_PT26_BITS)
#define __EXI_PT2INT_PT26_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(EXI_PT2INT_PT26_REG, EXI_PT2INT_PT26_POS, EXI_PT2INT_PT26_BITS, POS_EN)

//PT2INT_3
#define EXI_PT2INT_PT25_REG							INTCFG2
#define EXI_PT2INT_PT25_POS							(5)
#define EXI_PT2INT_PT25_BITS						C_REG_BITS1
#define EXI_PT2INT_PT25_DIS							(0x00<< EXI_PT2INT_PT25_POS)
#define EXI_PT2INT_PT25_EN							(0x01<< EXI_PT2INT_PT25_POS)
#define EXI_PT2INT_PT25_MASK						(EXI_PT2INT_PT25_BITS<< EXI_PT2INT_PT25_POS)
#define __EXI_PT2INT_PT25_GET()						M_REG_GET(EXI_PT2INT_PT25_REG, EXI_PT2INT_PT25_POS, EXI_PT2INT_PT25_BITS)
#define __EXI_PT2INT_PT25_SET(EN)					M_REG_SET(EXI_PT2INT_PT25_REG, EXI_PT2INT_PT25_POS, EXI_PT2INT_PT25_BITS, EN)
#define __EXI_PT2INT_PT25_GET_SHIFT()				M_REG_GET_SHIFT(EXI_PT2INT_PT25_REG, EXI_PT2INT_PT25_POS, EXI_PT2INT_PT25_BITS)
#define __EXI_PT2INT_PT25_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(EXI_PT2INT_PT25_REG, EXI_PT2INT_PT25_POS, EXI_PT2INT_PT25_BITS, POS_EN)

//PT2INT_2
#define EXI_PT2INT_PT24_REG							INTCFG2
#define EXI_PT2INT_PT24_POS							(4)
#define EXI_PT2INT_PT24_BITS						C_REG_BITS1
#define EXI_PT2INT_PT24_DIS							(0x00<< EXI_PT2INT_PT24_POS)
#define EXI_PT2INT_PT24_EN							(0x01<< EXI_PT2INT_PT24_POS)
#define EXI_PT2INT_PT24_MASK						(EXI_PT2INT_PT24_BITS<< EXI_PT2INT_PT24_POS)
#define __EXI_PT2INT_PT24_GET()						M_REG_GET(EXI_PT2INT_PT24_REG, EXI_PT2INT_PT24_POS, EXI_PT2INT_PT24_BITS)
#define __EXI_PT2INT_PT24_SET(EN)					M_REG_SET(EXI_PT2INT_PT24_REG, EXI_PT2INT_PT24_POS, EXI_PT2INT_PT24_BITS, EN)
#define __EXI_PT2INT_PT24_GET_SHIFT()				M_REG_GET_SHIFT(EXI_PT2INT_PT24_REG, EXI_PT2INT_PT24_POS, EXI_PT2INT_PT24_BITS)
#define __EXI_PT2INT_PT24_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(EXI_PT2INT_PT24_REG, EXI_PT2INT_PT24_POS, EXI_PT2INT_PT24_BITS, POS_EN)

//PT2INT_1
#define EXI_PT2INT_PT23_REG							INTCFG2
#define EXI_PT2INT_PT23_POS							(3)
#define EXI_PT2INT_PT23_BITS						C_REG_BITS1
#define EXI_PT2INT_PT23_DIS							(0x00<< EXI_PT2INT_PT23_POS)
#define EXI_PT2INT_PT23_EN							(0x01<< EXI_PT2INT_PT23_POS)
#define EXI_PT2INT_PT23_MASK						(EXI_PT2INT_PT23_BITS<< EXI_PT2INT_PT23_POS)
#define __EXI_PT2INT_PT23_GET()						M_REG_GET(EXI_PT2INT_PT23_REG, EXI_PT2INT_PT23_POS, EXI_PT2INT_PT23_BITS)
#define __EXI_PT2INT_PT23_SET(EN)					M_REG_SET(EXI_PT2INT_PT23_REG, EXI_PT2INT_PT23_POS, EXI_PT2INT_PT23_BITS, EN)
#define __EXI_PT2INT_PT23_GET_SHIFT()				M_REG_GET_SHIFT(EXI_PT2INT_PT23_REG, EXI_PT2INT_PT23_POS, EXI_PT2INT_PT23_BITS)
#define __EXI_PT2INT_PT23_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(EXI_PT2INT_PT23_REG, EXI_PT2INT_PT23_POS, EXI_PT2INT_PT23_BITS, POS_EN)

//PT2INT_0
#define EXI_PT2INT_PT22_REG							INTCFG2
#define EXI_PT2INT_PT22_POS							(2)
#define EXI_PT2INT_PT22_BITS						C_REG_BITS1
#define EXI_PT2INT_PT22_DIS							(0x00<< EXI_PT2INT_PT22_POS)
#define EXI_PT2INT_PT22_EN							(0x01<< EXI_PT2INT_PT22_POS)
#define EXI_PT2INT_PT22_MASK						(EXI_PT2INT_PT22_BITS<< EXI_PT2INT_PT22_POS)
#define __EXI_PT2INT_PT22_GET()						M_REG_GET(EXI_PT2INT_PT22_REG, EXI_PT2INT_PT22_POS, EXI_PT2INT_PT22_BITS)
#define __EXI_PT2INT_PT22_SET(EN)					M_REG_SET(EXI_PT2INT_PT22_REG, EXI_PT2INT_PT22_POS, EXI_PT2INT_PT22_BITS, EN)
#define __EXI_PT2INT_PT22_GET_SHIFT()				M_REG_GET_SHIFT(EXI_PT2INT_PT22_REG, EXI_PT2INT_PT22_POS, EXI_PT2INT_PT22_BITS)
#define __EXI_PT2INT_PT22_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(EXI_PT2INT_PT22_REG, EXI_PT2INT_PT22_POS, EXI_PT2INT_PT22_BITS, POS_EN)
/**@}*/ /*** end of group exti_reg_intcfg2 */

/** 
 * @addtogroup	exti_reg_intcfg3	reg: INTCFG3 
 * @{
 */
//INTCFG3
//PT3INT_5
#define EXI_PT3INT_PT36_REG							INTCFG3
#define EXI_PT3INT_PT36_POS							(6)
#define EXI_PT3INT_PT36_BITS						C_REG_BITS1
#define EXI_PT3INT_PT36_DIS							(0x00<< EXI_PT3INT_PT36_POS)
#define EXI_PT3INT_PT36_EN							(0x01<< EXI_PT3INT_PT36_POS)
#define EXI_PT3INT_PT36_MASK						(EXI_PT3INT_PT36_BITS<< EXI_PT3INT_PT36_POS)
#define __EXI_PT3INT_PT36_GET()						M_REG_GET(EXI_PT3INT_PT36_REG, EXI_PT3INT_PT36_POS, EXI_PT3INT_PT36_BITS)
#define __EXI_PT3INT_PT36_SET(EN)					M_REG_SET(EXI_PT3INT_PT36_REG, EXI_PT3INT_PT36_POS, EXI_PT3INT_PT36_BITS, EN)
#define __EXI_PT3INT_PT36_GET_SHIFT()				M_REG_GET_SHIFT(EXI_PT3INT_PT36_REG, EXI_PT3INT_PT36_POS, EXI_PT3INT_PT36_BITS)
#define __EXI_PT3INT_PT36_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(EXI_PT3INT_PT36_REG, EXI_PT3INT_PT36_POS, EXI_PT3INT_PT36_BITS, POS_EN)

//PT3INT_4
#define EXI_PT3INT_PT35_REG							INTCFG3
#define EXI_PT3INT_PT35_POS							(5)
#define EXI_PT3INT_PT35_BITS						C_REG_BITS1
#define EXI_PT3INT_PT35_DIS							(0x00<< EXI_PT3INT_PT35_POS)
#define EXI_PT3INT_PT35_EN							(0x01<< EXI_PT3INT_PT35_POS)
#define EXI_PT3INT_PT35_MASK						(EXI_PT3INT_PT35_BITS<< EXI_PT3INT_PT35_POS)
#define __EXI_PT3INT_PT35_GET()						M_REG_GET(EXI_PT3INT_PT35_REG, EXI_PT3INT_PT35_POS, EXI_PT3INT_PT35_BITS)
#define __EXI_PT3INT_PT35_SET(EN)					M_REG_SET(EXI_PT3INT_PT35_REG, EXI_PT3INT_PT35_POS, EXI_PT3INT_PT35_BITS, EN)
#define __EXI_PT3INT_PT35_GET_SHIFT()				M_REG_GET_SHIFT(EXI_PT3INT_PT35_REG, EXI_PT3INT_PT35_POS, EXI_PT3INT_PT35_BITS)
#define __EXI_PT3INT_PT35_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(EXI_PT3INT_PT35_REG, EXI_PT3INT_PT35_POS, EXI_PT3INT_PT35_BITS, POS_EN)

//PT3INT_3
#define EXI_PT3INT_PT34_REG							INTCFG3
#define EXI_PT3INT_PT34_POS							(4)
#define EXI_PT3INT_PT34_BITS						C_REG_BITS1
#define EXI_PT3INT_PT34_DIS							(0x00<< EXI_PT3INT_PT34_POS)
#define EXI_PT3INT_PT34_EN							(0x01<< EXI_PT3INT_PT34_POS)
#define EXI_PT3INT_PT34_MASK						(EXI_PT3INT_PT34_BITS<< EXI_PT3INT_PT34_POS)
#define __EXI_PT3INT_PT34_GET()						M_REG_GET(EXI_PT3INT_PT34_REG, EXI_PT3INT_PT34_POS, EXI_PT3INT_PT34_BITS)
#define __EXI_PT3INT_PT34_SET(EN)					M_REG_SET(EXI_PT3INT_PT34_REG, EXI_PT3INT_PT34_POS, EXI_PT3INT_PT34_BITS, EN)
#define __EXI_PT3INT_PT34_GET_SHIFT()				M_REG_GET_SHIFT(EXI_PT3INT_PT34_REG, EXI_PT3INT_PT34_POS, EXI_PT3INT_PT34_BITS)
#define __EXI_PT3INT_PT34_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(EXI_PT3INT_PT34_REG, EXI_PT3INT_PT34_POS, EXI_PT3INT_PT34_BITS, POS_EN)

//PT3INT_2
#define EXI_PT3INT_PT33_REG							INTCFG3
#define EXI_PT3INT_PT33_POS							(3)
#define EXI_PT3INT_PT33_BITS						C_REG_BITS1
#define EXI_PT3INT_PT33_DIS							(0x00<< EXI_PT3INT_PT33_POS)
#define EXI_PT3INT_PT33_EN							(0x01<< EXI_PT3INT_PT33_POS)
#define EXI_PT3INT_PT33_MASK						(EXI_PT3INT_PT33_BITS<< EXI_PT3INT_PT33_POS)
#define __EXI_PT3INT_PT33_GET()						M_REG_GET(EXI_PT3INT_PT33_REG, EXI_PT3INT_PT33_POS, EXI_PT3INT_PT33_BITS)
#define __EXI_PT3INT_PT33_SET(EN)					M_REG_SET(EXI_PT3INT_PT33_REG, EXI_PT3INT_PT33_POS, EXI_PT3INT_PT33_BITS, EN)
#define __EXI_PT3INT_PT33_GET_SHIFT()				M_REG_GET_SHIFT(EXI_PT3INT_PT33_REG, EXI_PT3INT_PT33_POS, EXI_PT3INT_PT33_BITS)
#define __EXI_PT3INT_PT33_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(EXI_PT3INT_PT33_REG, EXI_PT3INT_PT33_POS, EXI_PT3INT_PT33_BITS, POS_EN)

//PT3INT_1
#define EXI_PT3INT_PT32_REG							INTCFG3
#define EXI_PT3INT_PT32_POS							(2)
#define EXI_PT3INT_PT32_BITS						C_REG_BITS1
#define EXI_PT3INT_PT32_DIS							(0x00<< EXI_PT3INT_PT32_POS)
#define EXI_PT3INT_PT32_EN							(0x01<< EXI_PT3INT_PT32_POS)
#define EXI_PT3INT_PT32_MASK						(EXI_PT3INT_PT32_BITS<< EXI_PT3INT_PT32_POS)
#define __EXI_PT3INT_PT32_GET()						M_REG_GET(EXI_PT3INT_PT32_REG, EXI_PT3INT_PT32_POS, EXI_PT3INT_PT32_BITS)
#define __EXI_PT3INT_PT32_SET(EN)					M_REG_SET(EXI_PT3INT_PT32_REG, EXI_PT3INT_PT32_POS, EXI_PT3INT_PT32_BITS, EN)
#define __EXI_PT3INT_PT32_GET_SHIFT()				M_REG_GET_SHIFT(EXI_PT3INT_PT32_REG, EXI_PT3INT_PT32_POS, EXI_PT3INT_PT32_BITS)
#define __EXI_PT3INT_PT32_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(EXI_PT3INT_PT32_REG, EXI_PT3INT_PT32_POS, EXI_PT3INT_PT32_BITS, POS_EN)

//PT3INT_0
#define EXI_PT3INT_PT31_REG							INTCFG3
#define EXI_PT3INT_PT31_POS							(1)
#define EXI_PT3INT_PT31_BITS						C_REG_BITS1
#define EXI_PT3INT_PT31_DIS							(0x00<< EXI_PT3INT_PT31_POS)
#define EXI_PT3INT_PT31_EN							(0x01<< EXI_PT3INT_PT31_POS)
#define EXI_PT3INT_PT31_MASK						(EXI_PT3INT_PT31_BITS<< EXI_PT3INT_PT31_POS)
#define __EXI_PT3INT_PT31_GET()						M_REG_GET(EXI_PT3INT_PT31_REG, EXI_PT3INT_PT31_POS, EXI_PT3INT_PT31_BITS)
#define __EXI_PT3INT_PT31_SET(EN)					M_REG_SET(EXI_PT3INT_PT31_REG, EXI_PT3INT_PT31_POS, EXI_PT3INT_PT31_BITS, EN)
#define __EXI_PT3INT_PT31_GET_SHIFT()				M_REG_GET_SHIFT(EXI_PT3INT_PT31_REG, EXI_PT3INT_PT31_POS, EXI_PT3INT_PT31_BITS)
#define __EXI_PT3INT_PT31_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(EXI_PT3INT_PT31_REG, EXI_PT3INT_PT31_POS, EXI_PT3INT_PT31_BITS, POS_EN)
/**@}*/ /*** end of group exti_reg_intcfg3 */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup csu39fx10_sdk_chip_fwlib_exti_cfg	exti_config
 * @{
 */
/** 
 * @name exti0 config
 * @{
 */
/**
 * @details <b>CFG_EXI_E0M</b>
 * - <b>Features: </b> external interrupt 0 trigger mode
 * - <b>Param: </b>
 * | config	| Descriptions			|
 * | :----:	| :----:				|
 * | 0*		| rising edge trigger	|
 * | 1		| falling edge trigger	|
 * | 2		| level trigger			|
 * | 3		| level trigger			|
 */
#define	CFG_EXI_E0M						(0)		///< {0~ 3}

/**
 * @details <b>CFG_EXI_E0IE</b>
 * - <b>Features: </b> external interrupt 0 enable
 * - <b>Param: </b>
 * | config	| Descriptions				|
 * | :----:	| :----:					|
 * | 0*		| diasble exit 0 interrupt	|
 * | 1		| enable exit 0 interrupt	|
 */
#define	CFG_EXI_E0IE					(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_EXI0_PT1INT_PT12</b>
 * - <b>Features: </b> pt12 external interrupt 0 enable
 * - <b>Param: </b>
 * | config	| Descriptions				|
 * | :----:	| :----:					|
 * | 0*		| diasble pt12 interrupt	|
 * | 1		| enable pt12 interrupt		|
 */
#define	CFG_EXI0_PT1INT_PT12			(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_EXI0_PT1INT_PT13</b>
 * - <b>Features: </b> pt13 external interrupt 0 enable
 * - <b>Param: </b>
 * | config	| Descriptions				|
 * | :----:	| :----:					|
 * | 0*		| diasble pt13 interrupt	|
 * | 1		| enable pt13 interrupt		|
 */
#define	CFG_EXI0_PT1INT_PT13			(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_EXI0_PT1INT_PT14</b>
 * - <b>Features: </b> pt14 external interrupt 0 enable
 * - <b>Param: </b>
 * | config	| Descriptions				|
 * | :----:	| :----:					|
 * | 0*		| diasble pt14 interrupt	|
 * | 1		| enable pt14 interrupt		|
 */
#define	CFG_EXI0_PT1INT_PT14			(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_EXI0_PT1INT_PT15</b>
 * - <b>Features: </b> pt15 external interrupt 0 enable
 * - <b>Param: </b>
 * | config	| Descriptions				|
 * | :----:	| :----:					|
 * | 0*		| diasble pt15 interrupt	|
 * | 1		| enable pt15 interrupt		|
 */
#define	CFG_EXI0_PT1INT_PT15			(0)		///< 0-> disable, 1-> enable
/**@}*/ /*** end of name exti0 config */


/** 
 * @name exti1 config
 * @{
 */
/**
 * @details <b>CFG_EXI_E1M</b>
 * - <b>Features: </b> external interrupt 1 trigger mode
 * - <b>Param: </b>
 * | config	| Descriptions			|
 * | :----:	| :----:				|
 * | 0*		| rising edge trigger	|
 * | 1		| falling edge trigger	|
 * | 2		| level trigger			|
 * | 3		| level trigger			|
 */
#define	CFG_EXI_E1M						(0)		///< {0~ 3}

/**
 * @details <b>CFG_EXI_E1IE</b>
 * - <b>Features: </b> external interrupt 1 enable
 * - <b>Param: </b>
 * | config	| Descriptions				|
 * | :----:	| :----:					|
 * | 0*		| diasble exit 1 interrupt	|
 * | 1		| enable exit 1 interrupt	|
 */
#define	CFG_EXI_E1IE					(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_EXI1_PT2INT_PT22</b>
 * - <b>Features: </b> pt22 external interrupt 0 enable
 * - <b>Param: </b>
 * | config	| Descriptions				|
 * | :----:	| :----:					|
 * | 0*		| diasble pt22 interrupt	|
 * | 1		| enable pt22 interrupt		|
 */
#define	CFG_EXI1_PT2INT_PT22			(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_EXI1_PT2INT_PT23</b>
 * - <b>Features: </b> pt23 external interrupt 0 enable
 * - <b>Param: </b>
 * | config	| Descriptions				|
 * | :----:	| :----:					|
 * | 0*		| diasble pt23 interrupt	|
 * | 1		| enable pt23 interrupt		|
 */
#define	CFG_EXI1_PT2INT_PT23			(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_EXI1_PT2INT_PT24</b>
 * - <b>Features: </b> pt24 external interrupt 0 enable
 * - <b>Param: </b>
 * | config	| Descriptions				|
 * | :----:	| :----:					|
 * | 0*		| diasble pt24 interrupt	|
 * | 1		| enable pt24 interrupt		|
 */
#define	CFG_EXI1_PT2INT_PT24			(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_EXI1_PT2INT_PT25</b>
 * - <b>Features: </b> pt25 external interrupt 0 enable
 * - <b>Param: </b>
 * | config	| Descriptions				|
 * | :----:	| :----:					|
 * | 0*		| diasble pt25 interrupt	|
 * | 1		| enable pt25 interrupt		|
 */
#define	CFG_EXI1_PT2INT_PT25			(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_EXI1_PT2INT_PT26</b>
 * - <b>Features: </b> pt26 external interrupt 0 enable
 * - <b>Param: </b>
 * | config	| Descriptions				|
 * | :----:	| :----:					|
 * | 0*		| diasble pt26 interrupt	|
 * | 1		| enable pt26 interrupt		|
 */
#define	CFG_EXI1_PT2INT_PT26			(0)		///< 0-> disable, 1-> enable
/**@}*/ /*** end of name exti1 config */

 
/** 
 * @name exti2 config
 * @{
 */
/**
 * @details <b>CFG_EXI_E2M</b>
 * - <b>Features: </b> external interrupt 2 trigger mode
 * - <b>Param: </b>
 * | config	| Descriptions			|
 * | :----:	| :----:				|
 * | 0*		| rising edge trigger	|
 * | 1		| falling edge trigger	|
 * | 2		| level trigger			|
 * | 3		| level trigger			|
 */
#define	CFG_EXI_E2M						(0)		///< {0~ 3}

/**
 * @details <b>CFG_EXI_E2IE</b>
 * - <b>Features: </b> external interrupt 1 enable
 * - <b>Param: </b>
 * | config	| Descriptions				|
 * | :----:	| :----:					|
 * | 0*		| diasble exit 2 interrupt	|
 * | 1		| enable exit 2 interrupt	|
 */
#define	CFG_EXI_E2IE					(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_EXI2_PT3INT_PT31/b>
 * - <b>Features: </b> pt31 external interrupt 0 enable
 * - <b>Param: </b>
 * | config	| Descriptions				|
 * | :----:	| :----:					|
 * | 0*		| diasble pt31 interrupt	|
 * | 1		| enable pt31 interrupt		|
 */
#define	CFG_EXI2_PT3INT_PT31			(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_EXI2_PT3INT_PT32/b>
 * - <b>Features: </b> pt32 external interrupt 0 enable
 * - <b>Param: </b>
 * | config	| Descriptions				|
 * | :----:	| :----:					|
 * | 0*		| diasble pt32 interrupt	|
 * | 1		| enable pt32 interrupt		|
 */
#define	CFG_EXI2_PT3INT_PT32			(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_EXI2_PT3INT_PT33/b>
 * - <b>Features: </b> pt33 external interrupt 0 enable
 * - <b>Param: </b>
 * | config	| Descriptions				|
 * | :----:	| :----:					|
 * | 0*		| diasble pt33 interrupt	|
 * | 1		| enable pt33 interrupt		|
 */
#define	CFG_EXI2_PT3INT_PT33			(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_EXI2_PT3INT_PT34/b>
 * - <b>Features: </b> pt34 external interrupt 0 enable
 * - <b>Param: </b>
 * | config	| Descriptions				|
 * | :----:	| :----:					|
 * | 0*		| diasble pt34 interrupt	|
 * | 1		| enable pt34 interrupt		|
 */
#define	CFG_EXI2_PT3INT_PT34			(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_EXI2_PT3INT_PT35/b>
 * - <b>Features: </b> pt35 external interrupt 0 enable
 * - <b>Param: </b>
 * | config	| Descriptions				|
 * | :----:	| :----:					|
 * | 0*		| diasble pt35 interrupt	|
 * | 1		| enable pt35 interrupt		|
 */
#define	CFG_EXI2_PT3INT_PT35			(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_EXI2_PT3INT_PT36/b>
 * - <b>Features: </b> pt36 external interrupt 0 enable
 * - <b>Param: </b>
 * | config	| Descriptions				|
 * | :----:	| :----:					|
 * | 0*		| diasble pt36 interrupt	|
 * | 1		| enable pt36 interrupt		|
 */
#define	CFG_EXI2_PT3INT_PT36			(0)		///< 0-> disable, 1-> enable
/**@}*/ /*** end of name exti2 config */
/**@}*/ /*** end of group csu39fx10_sdk_chip_fwlib_exti_cfg */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup exti_compile	attention: users do not need to care
 * @attention <b>users do not need to care</b>
 * @{
 */
/** 
 * @name exti_compile_reg_exicon
 * @{
 */
#define PRE_EXI_E2M						(CFG_EXI_E2M& 0x03)
#define PRE_EXI_E1M						(CFG_EXI_E1M& 0x03)
#define PRE_EXI_E0M						(CFG_EXI_E0M& 0x03)
/**@}*/ /*** end of name exti_compile_reg_exicon */

/** 
 * @name exti_compile_reg_exiie
 * @{
 */
#if(CFG_EXI_E2IE!= 0)
	#define PRE_EXI_E2IE				1
#else
	#define PRE_EXI_E2IE				0
#endif

#if(CFG_EXI_E1IE!= 0)
	#define PRE_EXI_E1IE				1
#else
	#define PRE_EXI_E1IE				0
#endif

#if(CFG_EXI_E0IE!= 0)
	#define PRE_EXI_E0IE				1
#else
	#define PRE_EXI_E0IE				0
#endif
/**@}*/ /*** end of name exti_compile_reg_exiie */

/** 
 * @name exti_compile_reg_intcfg1
 * @{
 */
#if(CFG_EXI0_PT1INT_PT15!= 0)
	#define PRE_EXI_PT1INT_PT15			1
#else
	#define PRE_EXI_PT1INT_PT15			0
#endif

#if(CFG_EXI0_PT1INT_PT14!= 0)
	#define PRE_EXI_PT1INT_PT14			1
#else
	#define PRE_EXI_PT1INT_PT14			0
#endif

#if(CFG_EXI0_PT1INT_PT13!= 0)
	#define PRE_EXI_PT1INT_PT13			1
#else
	#define PRE_EXI_PT1INT_PT13			0
#endif

#if(CFG_EXI0_PT1INT_PT12!= 0)
	#define PRE_EXI_PT1INT_PT12			1
#else
	#define PRE_EXI_PT1INT_PT12			0
#endif
/**@}*/ /*** end of name exti_compile_reg_intcfg1 */

/** 
 * @name exti_compile_reg_intcfg2
 * @{
 */
#if(CFG_EXI1_PT2INT_PT26!= 0)
	#define PRE_EXI_PT2INT_PT26			1
#else
	#define PRE_EXI_PT2INT_PT26			0
#endif

#if(CFG_EXI1_PT2INT_PT25!= 0)
	#define PRE_EXI_PT2INT_PT25			1
#else
	#define PRE_EXI_PT2INT_PT25			0
#endif

#if(CFG_EXI1_PT2INT_PT24!= 0)
	#define PRE_EXI_PT2INT_PT24			1
#else
	#define PRE_EXI_PT2INT_PT24			0
#endif

#if(CFG_EXI1_PT2INT_PT23!= 0)
	#define PRE_EXI_PT2INT_PT23			1
#else
	#define PRE_EXI_PT2INT_PT23			0
#endif

#if(CFG_EXI1_PT2INT_PT22!= 0)
	#define PRE_EXI_PT2INT_PT22			1
#else
	#define PRE_EXI_PT2INT_PT22			0
#endif
/**@}*/ /*** end of name exti_compile_reg_intcfg2 */

/** 
 * @name exti_compile_reg_intcfg3
 * @{
 */
#if(CFG_EXI2_PT3INT_PT36!= 0)
	#define PRE_EXI_PT3INT_PT36			1
#else
	#define PRE_EXI_PT3INT_PT36			0
#endif

#if(CFG_EXI2_PT3INT_PT35!= 0)
	#define PRE_EXI_PT3INT_PT35			1
#else
	#define PRE_EXI_PT3INT_PT35			0
#endif

#if(CFG_EXI2_PT3INT_PT34!= 0)
	#define PRE_EXI_PT3INT_PT34			1
#else
	#define PRE_EXI_PT3INT_PT34			0
#endif

#if(CFG_EXI2_PT3INT_PT33!= 0)
	#define PRE_EXI_PT3INT_PT33			1
#else
	#define PRE_EXI_PT3INT_PT33			0
#endif

#if(CFG_EXI2_PT3INT_PT32!= 0)
	#define PRE_EXI_PT3INT_PT32			1
#else
	#define PRE_EXI_PT3INT_PT32			0
#endif

#if(CFG_EXI2_PT3INT_PT31!= 0)
	#define PRE_EXI_PT3INT_PT31			1
#else
	#define PRE_EXI_PT3INT_PT31			0
#endif
/**@}*/ /*** end of name exti_compile_reg_intcfg3 */

/** 
 * @name wdt_compile_warning
 * @attention <b>compile warning message</b>
 * @{
 */
#define WARNING_WDT_TIME_MAX			(256* 1000/ C_CLK_DIVWDTCLK)		//{unit: 1mS}
#define WARNING_WDT_TIME_MIN			(1* 1000/ C_CLK_DIVWDTCLK)			//{unit: 1mS}

#if(CFG_WDT_WDTEN)
	#if(C_CLK_WDTCLK== 0)
		#warning "Warning: watchdog clock disable, turn on the watchdog clock{PRE_SYS_WDT_DISABLE}"
	#endif
	#if(CFG_WDT_TIME> WARNING_WDT_TIME_MAX)
		#warning "Warning: CFG_WDT_TIME define error, decrease CFG_WDT_TIME!"
	#endif
	#if(CFG_WDT_TIME< WARNING_WDT_TIME_MIN)
		#warning "Warning: CFG_WDT_TIME define error, increase CFG_WDT_TIME!"
	#endif
#endif
/**@}*/ /*** end of name wdt_compile_warning */

/** 
 * @name wwdt_compile_reg_wwdtcr
 * @{
 */
#if(CFG_WWDT_WWDTEN!= 0)
	#define PRE_WWDT_WWDTEN				1
#else
	#define PRE_WWDT_WWDTEN				0
#endif

#define PRE_WWDT_TR						0x7F
/**@}*/ /*** end of name wwdt_compile_reg_wwdtcr */

/** 
 * @name wwdt_compile_reg_wwdtwr
 * @{
 */
#define PRE_WWDT_WD						(uint8_t)(((uint16_t)CFG_WWDT_WINDOWS* 1000/ C_CLK_WWDTCLK)+ 0x3F)
/**@}*/ /*** end of name wwdt_compile_reg_wwdtwr */
 
/** 
 * @name exti_compile_warning
 * @attention <b>compile warning message</b>
 * @{
 */
#if(0)
	#warning "Warning: CFG_EXI_XXX define error, will be redefined!"
#endif
/**@}*/ /*** end of name exti_compile_warning */
/**@}*/ /*** end of group exti_compile */
/*******************************************************************************/




/******************************** dividing line ********************************/
/**
 * @addtogroup exti_reg_default	reg_default_value
 * @par 示例
 * @code
 *		void test( void )
 *		{
 *			EXICON= PRE_EXICON_DEFAULT;
 *			EXIIE= PRE_EXIIE_DEFAULT;
 *			EXIIF= PRE_EXIIF_DEFAULT;
 *			INTCFG1= PRE_INTCFG1_DEFAULT;
 *			INTCFG2= PRE_INTCFG2_DEFAULT;
 *			INTCFG3= PRE_INTCFG3_DEFAULT;
 *		#if(PRE_EXIIE_DEFAULT!= 0)
 *			//enable global interrupt
 *			GIE= 1;
 *		#endif
 *		}
 * @endcode
 * @{
 */
/** 
 * @name exti_reg
 * @{
 */
#define PRE_EXICON_DEFAULT				(((PRE_EXI_E2M<< EXI_E2M_POS)& EXI_E2M_MASK)|								\
											((PRE_EXI_E1M<< EXI_E1M_POS)& EXI_E1M_MASK)|							\
											((PRE_EXI_E0M<< EXI_E0M_POS)& EXI_E0M_MASK))
#define PRE_EXIIE_DEFAULT				(((PRE_EXI_E2IE<< EXI_E2IE_POS)& EXI_E2IE_MASK)|							\
											((PRE_EXI_E1IE<< EXI_E1IE_POS)& EXI_E1IE_MASK)|							\
											((PRE_EXI_E0IE<< EXI_E0IE_POS)& EXI_E0IE_MASK))
#define PRE_EXIIF_DEFAULT				0x00
#define PRE_INTCFG1_DEFAULT				(((PRE_EXI_PT1INT_PT15<< EXI_PT1INT_PT15_POS)& EXI_PT1INT_PT15_MASK)|		\
											((PRE_EXI_PT1INT_PT14<< EXI_PT1INT_PT14_POS)& EXI_PT1INT_PT14_MASK)|	\
											((PRE_EXI_PT1INT_PT13<< EXI_PT1INT_PT13_POS)& EXI_PT1INT_PT13_MASK)|	\
											((PRE_EXI_PT1INT_PT12<< EXI_PT1INT_PT12_POS)& EXI_PT1INT_PT12_MASK))
#define PRE_INTCFG2_DEFAULT				(((PRE_EXI_PT2INT_PT26<< EXI_PT2INT_PT26_POS)& EXI_PT2INT_PT26_MASK)|		\
											((PRE_EXI_PT2INT_PT25<< EXI_PT2INT_PT25_POS)& EXI_PT2INT_PT25_MASK)|	\
											((PRE_EXI_PT2INT_PT24<< EXI_PT2INT_PT24_POS)& EXI_PT2INT_PT24_MASK)|	\
											((PRE_EXI_PT2INT_PT23<< EXI_PT2INT_PT23_POS)& EXI_PT2INT_PT23_MASK)|	\
											((PRE_EXI_PT2INT_PT22<< EXI_PT2INT_PT22_POS)& EXI_PT2INT_PT22_MASK))
#define PRE_INTCFG3_DEFAULT				(((PRE_EXI_PT3INT_PT36<< EXI_PT3INT_PT36_POS)& EXI_PT3INT_PT36_MASK)|		\
											((PRE_EXI_PT3INT_PT35<< EXI_PT3INT_PT35_POS)& EXI_PT3INT_PT35_MASK)|	\
											((PRE_EXI_PT3INT_PT34<< EXI_PT3INT_PT34_POS)& EXI_PT3INT_PT34_MASK)|	\
											((PRE_EXI_PT3INT_PT33<< EXI_PT3INT_PT33_POS)& EXI_PT3INT_PT33_MASK)|	\
											((PRE_EXI_PT3INT_PT32<< EXI_PT3INT_PT32_POS)& EXI_PT3INT_PT32_MASK)|	\
											((PRE_EXI_PT3INT_PT31<< EXI_PT3INT_PT31_POS)& EXI_PT3INT_PT31_MASK))
/**@}*/ /*** end of name exti_reg */
/**@}*/ /*** end of group exti_reg_default */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup exti_api	api
 * @{
 */
/** 
 * @name exti0_api
 * @{
 */
/**
 * @brief 	<b>Description:</b> exti initialization.
 * @details <b>Function prototype:</b> void exi_init(void);
 * @param[in]  null	.
 * @param[out] null.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			exi_init();
 *		}
 * @endcode
 */
void exi_init(void);

/**
 * @brief 	<b>Description:</b> external interrupt callback function.
 * @details <b>Function prototype:</b> void exi_int0_irq(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void INT_FUNCTION(void) interrupt
 *		{
 *			if(__EXI_E0IF_GET_SHIFT()!= 0)
 *			{
 *				__EXI_E0IF_SET_SHIFT(EXI_E0IF_CLR);
 *				exi_int0_irq();
 *			}
 *		}
 * @endcode
 */
void exi_int0_irq(void);
/**@}*/ /*** end of name exti0_api */


/** 
 * @name exti1_api
 * @{
 */
/**
 * @brief 	<b>Description:</b> external interrupt callback function.
 * @details <b>Function prototype:</b> void exi_int1_irq(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void INT_FUNCTION(void) interrupt
 *		{
 *			if(__EXI_E1IF_GET_SHIFT()!= 0)
 *			{
 *				__EXI_E1IF_SET_SHIFT(EXI_E1IF_CLR);
 *				exi_int1_irq();
 *			}
 *		}
 * @endcode
 */
void exi_int1_irq(void);

/**
 * @brief 	<b>Description:</b> external interrupt callback function.
 * @details <b>Function prototype:</b> void exi_int2_irq(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void INT_FUNCTION(void) interrupt
 *		{
 *			if(__EXI_E2IF_GET_SHIFT()!= 0)
 *			{
 *				__EXI_E2IF_SET_SHIFT(EXI_E2IF_CLR);
 *				exi_int2_irq();
 *			}
 *		}
 * @endcode
 */
void exi_int2_irq(void);
/**@}*/ /*** end of name exti1_api */
/**@}*/ /*** end of group exti_api */
/**@}*/ /*** end of group csu39fx10_sdk_chip_fwlib_exti */
/**@}*/ /*** end of group csu39fx10_sdk_chip_fwlib */
/**@}*/ /*** end of group csu39fx10_sdk_chip */
/*******************************************************************************/




#ifdef __cplusplus
}
#endif

#endif  //__CSU39FX10_EXTI_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/

