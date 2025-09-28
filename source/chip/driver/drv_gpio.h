/***************************************************************************
 * @file     drv_gpio.h
 * @version  V1.0.0
 * @author   0531
 * @date     2020-10-10 AM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 ****************************************************************************
 * @par 头文件
 *       csu39fx10.h \n
 *       cs_common.h \n
 * @attention
 *  硬件平台:	\n
 *  SDK版本:	.0.0
 * 
 * @par 修改日志:
 * <table>
 * <tr><th>Date        <th>Version  <th>Author    <th>Description
 * <tr><td>2018/08/17  <td>1.0      <td>0531	  <td>创建初始版本
 * </table>
 *
 *****************************************************************************/

#ifndef __DRV_GPIO_H__
#define __DRV_GPIO_H__

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
 * @addtogroup csu39fx10_sdk_chip_driver	driver 
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_driver_gpio	gpio 
 * @{
 */

/** 
 * @addtogroup	gpio_reg_pt1	reg: PT1 
 * @{
 */
//PT1
//PT1[7:0]
#define GPIO_PT1_REG								PT1
#define GPIO_PT1_POS								(0)
#define GPIO_PT1_BITS								C_REG_BITS7
#define GPIO_PT1_VAL	
#define GPIO_PT1_MASK								(GPIO_PT1_BITS<< GPIO_PT1_POS)
#define __GPIO_PT1_GET()							M_REG_GETBYTE(GPIO_PT1_REG, GPIO_PT1_POS)
#define __GPIO_PT1_SET(VAL)							M_REG_SETBYTE(GPIO_PT1_REG, GPIO_PT1_POS, VAL)
#define __GPIO_PT1_GET_SHIFT()						M_REG_GETBYTE_SHIFT(GPIO_PT1_REG, GPIO_PT1_POS)
#define __GPIO_PT1_SET_SHIFT(POS_VAL)				M_REG_SETBYTE_SHIFT(GPIO_PT1_REG, GPIO_PT1_POS, POS_VAL)
/**@}*/ /*** end of group gpio_reg_pt1 */

/** 
 * @addtogroup	gpio_reg_pt1en	reg: PT1EN 
 * @{
 */
//PT1EN
//PT1EN[7:0]
#define GPIO_PT1EN_REG								PT1EN
#define GPIO_PT1EN_POS								(0)
#define GPIO_PT1EN_BITS								C_REG_BITS7
#define GPIO_PT1EN_VAL	
#define GPIO_PT1EN_MASK								(GPIO_PT1EN_BITS<< GPIO_PT1EN_POS)
#define __GPIO_PT1EN_GET()							M_REG_GETBYTE(GPIO_PT1EN_REG, GPIO_PT1EN_POS)
#define __GPIO_PT1EN_SET(VAL)						M_REG_SETBYTE(GPIO_PT1EN_REG, GPIO_PT1EN_POS, VAL)
#define __GPIO_PT1EN_GET_SHIFT()					M_REG_GETBYTE_SHIFT(GPIO_PT1EN_REG, GPIO_PT1EN_POS)
#define __GPIO_PT1EN_SET_SHIFT(POS_VAL)				M_REG_SETBYTE_SHIFT(GPIO_PT1EN_REG, GPIO_PT1EN_POS, POS_VAL)
/**@}*/ /*** end of group gpio_reg_pt1en */

/** 
 * @addtogroup	gpio_reg_pt1pu	reg: PT1PU
 * @{
 */
//PT1PU
//PT1PU[7:0]
#define GPIO_PT1PU_REG								PT1PU
#define GPIO_PT1PU_POS								(0)
#define GPIO_PT1PU_BITS								C_REG_BITS7
#define GPIO_PT1PU_VAL	
#define GPIO_PT1PU_MASK								(GPIO_PT1PU_BITS<< GPIO_PT1PU_POS)
#define __GPIO_PT1PU_GET()							M_REG_GETBYTE(GPIO_PT1PU_REG, GPIO_PT1PU_POS)
#define __GPIO_PT1PU_SET(VAL)						M_REG_SETBYTE(GPIO_PT1PU_REG, GPIO_PT1PU_POS, VAL)
#define __GPIO_PT1PU_GET_SHIFT()					M_REG_GETBYTE_SHIFT(GPIO_PT1PU_REG, GPIO_PT1PU_POS)
#define __GPIO_PT1PU_SET_SHIFT(POS_VAL)				M_REG_SETBYTE_SHIFT(GPIO_PT1PU_REG, GPIO_PT1PU_POS, POS_VAL)
/**@}*/ /*** end of group gpio_reg_pt1pu */

/** 
 * @addtogroup	gpio_reg_pt2	reg: PT2
 * @{
 */
//PT2
//PT2[6:0]
#define GPIO_PT2_REG								PT2
#define GPIO_PT2_POS								(0)
#define GPIO_PT2_BITS								C_REG_BITS6
#define GPIO_PT2_VAL	
#define GPIO_PT2_MASK								(GPIO_PT2_BITS<< GPIO_PT2_POS)
#define __GPIO_PT2_GET()							M_REG_GETBYTE(GPIO_PT2_REG, GPIO_PT2_POS)
#define __GPIO_PT2_SET(VAL)							M_REG_SETBYTE(GPIO_PT2_REG, GPIO_PT2_POS, VAL)
#define __GPIO_PT2_GET_SHIFT()						M_REG_GETBYTE_SHIFT(GPIO_PT2_REG, GPIO_PT2_POS)
#define __GPIO_PT2_SET_SHIFT(POS_VAL)				M_REG_SETBYTE_SHIFT(GPIO_PT2_REG, GPIO_PT2_POS, POS_VAL)
/**@}*/ /*** end of group gpio_reg_pt2 */

/** 
 * @addtogroup	gpio_reg_pt2en	reg: PT2EN
 * @{
 */
//PT2EN
//PT2EN[6:0]
#define GPIO_PT2EN_REG								PT2EN
#define GPIO_PT2EN_POS								(0)
#define GPIO_PT2EN_BITS								C_REG_BITS6
#define GPIO_PT2EN_VAL	
#define GPIO_PT2EN_MASK								(GPIO_PT2EN_BITS<< GPIO_PT2EN_POS)
#define __GPIO_PT2EN_GET()							M_REG_GETBYTE(GPIO_PT2EN_REG, GPIO_PT2EN_POS)
#define __GPIO_PT2EN_SET(VAL)						M_REG_SETBYTE(GPIO_PT2EN_REG, GPIO_PT2EN_POS, VAL)
#define __GPIO_PT2EN_GET_SHIFT()					M_REG_GETBYTE_SHIFT(GPIO_PT2EN_REG, GPIO_PT2EN_POS)
#define __GPIO_PT2EN_SET_SHIFT(POS_VAL)				M_REG_SETBYTE_SHIFT(GPIO_PT2EN_REG, GPIO_PT2EN_POS, POS_VAL)
/**@}*/ /*** end of group gpio_reg_pt2en */

/** 
 * @addtogroup	gpio_reg_pt2pu	reg: PT2PU
 * @{
 */
//PT2PU
//PT2PU[6:0]
#define GPIO_PT2PU_REG								PT2PU
#define GPIO_PT2PU_POS								(0)
#define GPIO_PT2PU_BITS								C_REG_BITS6
#define GPIO_PT2PU_VAL	
#define GPIO_PT2PU_MASK								(GPIO_PT2PU_BITS<< GPIO_PT2PU_POS)
#define __GPIO_PT2PU_GET()							M_REG_GETBYTE(GPIO_PT2PU_REG, GPIO_PT2PU_POS)
#define __GPIO_PT2PU_SET(VAL)						M_REG_SETBYTE(GPIO_PT2PU_REG, GPIO_PT2PU_POS, VAL)
#define __GPIO_PT2PU_GET_SHIFT()					M_REG_GETBYTE_SHIFT(GPIO_PT2PU_REG, GPIO_PT2PU_POS)
#define __GPIO_PT2PU_SET_SHIFT(POS_VAL)				M_REG_SETBYTE_SHIFT(GPIO_PT2PU_REG, GPIO_PT2PU_POS, POS_VAL)
/**@}*/ /*** end of group gpio_reg_pt2pu */

/** 
 * @addtogroup	gpio_reg_pt2otype	reg: PT2OTYPE
 * @{
 */
//PT2OTYPE
//PT2OTYPE_PT21
#define GPIO_PT2OTYPE_PT21_REG						PT2OTYPE
#define GPIO_PT2OTYPE_PT21_POS						(1)
#define GPIO_PT2OTYPE_PT21_BITS						C_REG_BITS1
#define GPIO_PT2OTYPE_PT21_PP						(0x00<< GPIO_PT2OTYPE_PT21_POS)
#define GPIO_PT2OTYPE_PT21_OD						(0x01<< GPIO_PT2OTYPE_PT21_POS)
#define GPIO_PT2OTYPE_PT21_MASK						(GPIO_PT2OTYPE_PT21_BITS<< GPIO_PT2OTYPE_PT21_POS)
#define __GPIO_PT2OTYPE_PT21_GET()					M_REG_GET(GPIO_PT2OTYPE_PT21_REG, GPIO_PT2OTYPE_PT21_POS, GPIO_PT2OTYPE_PT21_BITS)
#define __GPIO_PT2OTYPE_PT21_SET(SET)				M_REG_SET(GPIO_PT2OTYPE_PT21_REG, GPIO_PT2OTYPE_PT21_POS, GPIO_PT2OTYPE_PT21_BITS, SET)
#define __GPIO_PT2OTYPE_PT21_GET_SHIFT()			M_REG_GET_SHIFT(GPIO_PT2OTYPE_PT21_REG, GPIO_PT2OTYPE_PT21_POS, GPIO_PT2OTYPE_PT21_BITS)
#define __GPIO_PT2OTYPE_PT21_SET_SHIFT(POS_SET)		M_REG_SET_SHIFT(GPIO_PT2OTYPE_PT21_REG, GPIO_PT2OTYPE_PT21_POS, GPIO_PT2OTYPE_PT21_BITS, POS_SET)

//PT2OTYPE_PT20
#define GPIO_PT2OTYPE_PT20_REG						PT2OTYPE
#define GPIO_PT2OTYPE_PT20_POS						(0)
#define GPIO_PT2OTYPE_PT20_BITS						C_REG_BITS1
#define GPIO_PT2OTYPE_PT20_PP						(0x00<< GPIO_PT2OTYPE_PT20_POS)
#define GPIO_PT2OTYPE_PT20_OD						(0x01<< GPIO_PT2OTYPE_PT20_POS)
#define GPIO_PT2OTYPE_PT20_MASK						(GPIO_PT2OTYPE_PT20_BITS<< GPIO_PT2OTYPE_PT20_POS)
#define __GPIO_PT2OTYPE_PT20_GET()					M_REG_GET(GPIO_PT2OTYPE_PT20_REG, GPIO_PT2OTYPE_PT20_POS, GPIO_PT2OTYPE_PT20_BITS)
#define __GPIO_PT2OTYPE_PT20_SET(SET)				M_REG_SET(GPIO_PT2OTYPE_PT20_REG, GPIO_PT2OTYPE_PT20_POS, GPIO_PT2OTYPE_PT20_BITS, SET)
#define __GPIO_PT2OTYPE_PT20_GET_SHIFT()			M_REG_GET_SHIFT(GPIO_PT2OTYPE_PT20_REG, GPIO_PT2OTYPE_PT20_POS, GPIO_PT2OTYPE_PT20_BITS)
#define __GPIO_PT2OTYPE_PT20_SET_SHIFT(POS_SET)		M_REG_SET_SHIFT(GPIO_PT2OTYPE_PT20_REG, GPIO_PT2OTYPE_PT20_POS, GPIO_PT2OTYPE_PT20_BITS, POS_SET)
/**@}*/ /*** end of group gpio_reg_pt2otype */

/** 
 * @addtogroup	gpio_reg_pt3	reg: PT3
 * @{
 */
//PT3
//PT3[7:0]
#define GPIO_PT3_REG								PT3
#define GPIO_PT3_POS								(0)
#define GPIO_PT3_BITS								C_REG_BITS7
#define GPIO_PT3_VAL	
#define GPIO_PT3_MASK								(GPIO_PT3_BITS<< GPIO_PT3_POS)
#define __GPIO_PT3_GET()							M_REG_GETBYTE(GPIO_PT3_REG, GPIO_PT3_POS)
#define __GPIO_PT3_SET(VAL)							M_REG_GETBYTE(GPIO_PT3_REG, GPIO_PT3_POS, VAL)
#define __GPIO_PT3_GET_SHIFT()						M_REG_GETBYTE_SHIFT(GPIO_PT3_REG, GPIO_PT3_POS)
#define __GPIO_PT3_SET_SHIFT(POS_VAL)				M_REG_GETBYTE_SHIFT(GPIO_PT3_REG, GPIO_PT3_POS, POS_VAL)
/**@}*/ /*** end of group gpio_reg_pt3 */

/** 
 * @addtogroup	gpio_reg_pt3en	reg: PT3EN
 * @{
 */
//PT3EN
//PT3EN[7:0]
#define GPIO_PT3EN_REG								PT3EN
#define GPIO_PT3EN_POS								(0)
#define GPIO_PT3EN_BITS								C_REG_BITS7
#define GPIO_PT3EN_VAL	
#define GPIO_PT3EN_MASK								(GPIO_PT3EN_BITS<< GPIO_PT3EN_POS)
#define __GPIO_PT3EN_GET()							M_REG_GETBYTE(GPIO_PT3EN_REG, GPIO_PT3EN_POS)
#define __GPIO_PT3EN_SET(VAL)						M_REG_GETBYTE(GPIO_PT3EN_REG, GPIO_PT3EN_POS, VAL)
#define __GPIO_PT3EN_GET_SHIFT()					M_REG_GETBYTE_SHIFT(GPIO_PT3EN_REG, GPIO_PT3EN_POS)
#define __GPIO_PT3EN_SET_SHIFT(POS_VAL)				M_REG_GETBYTE_SHIFT(GPIO_PT3EN_REG, GPIO_PT3EN_POS, POS_VAL)
/**@}*/ /*** end of group gpio_reg_pt3en */

/** 
 * @addtogroup	gpio_reg_pt3pu	reg: PT3PU
 * @{
 */
//PT3PU
//PT3PU[7:0]
#define GPIO_PT3PU_REG								PT3PU
#define GPIO_PT3PU_POS								(0)
#define GPIO_PT3PU_BITS								C_REG_BITS7
#define GPIO_PT3PU_VAL	
#define GPIO_PT3PU_MASK								(GPIO_PT3PU_BITS<< GPIO_PT3PU_POS)
#define __GPIO_PT3PU_GET()							M_REG_GETBYTE(GPIO_PT3PU_REG, GPIO_PT3PU_POS)
#define __GPIO_PT3PU_SET(VAL)						M_REG_GETBYTE(GPIO_PT3PU_REG, GPIO_PT3PU_POS, VAL)
#define __GPIO_PT3PU_GET_SHIFT()					M_REG_GETBYTE_SHIFT(GPIO_PT3PU_REG, GPIO_PT3PU_POS)
#define __GPIO_PT3PU_SET_SHIFT(POS_VAL)				M_REG_GETBYTE_SHIFT(GPIO_PT3PU_REG, GPIO_PT3PU_POS, POS_VAL)
/**@}*/ /*** end of group gpio_reg_pt3pu */

/** 
 * @addtogroup	gpio_reg_ptoffdin	reg: PTOFFDIN
 * @{
 */
//PTOFFDIN
//PT2OFFDIN_PT24
#define GPIO_PT2OFFDIN_PT24_REG						PTOFFDIN
#define GPIO_PT2OFFDIN_PT24_POS						(7)
#define GPIO_PT2OFFDIN_PT24_BITS					C_REG_BITS1
#define GPIO_PT2OFFDIN_PT24_OPEN					(0x00<< GPIO_PT2OFFDIN_PT24_POS)
#define GPIO_PT2OFFDIN_PT24_CLOSE					(0x01<< GPIO_PT2OFFDIN_PT24_POS)
#define GPIO_PT2OFFDIN_PT24_MASK					(GPIO_PT2OFFDIN_PT24_BITS<< GPIO_PT2OFFDIN_PT24_POS)
#define __GPIO_PT2OFFDIN_PT24_GET()					M_REG_GET(GPIO_PT2OFFDIN_PT24_REG, GPIO_PT2OFFDIN_PT24_POS, GPIO_PT2OFFDIN_PT24_BITS)
#define __GPIO_PT2OFFDIN_PT24_SET(SET)				M_REG_SET(GPIO_PT2OFFDIN_PT24_REG, GPIO_PT2OFFDIN_PT24_POS, GPIO_PT2OFFDIN_PT24_BITS, SET)
#define __GPIO_PT2OFFDIN_PT24_GET_SHIFT()			M_REG_GET_SHIFT(GPIO_PT2OFFDIN_PT24_REG, GPIO_PT2OFFDIN_PT24_POS, GPIO_PT2OFFDIN_PT24_BITS)
#define __GPIO_PT2OFFDIN_PT24_SET_SHIFT(POS_SET)	M_REG_SET_SHIFT(GPIO_PT2OFFDIN_PT24_REG, GPIO_PT2OFFDIN_PT24_POS, GPIO_PT2OFFDIN_PT24_BITS, POS_SET)

//PT2OFFDIN_PT23
#define GPIO_PT2OFFDIN_PT23_REG						PTOFFDIN
#define GPIO_PT2OFFDIN_PT23_POS						(6)
#define GPIO_PT2OFFDIN_PT23_BITS					C_REG_BITS1
#define GPIO_PT2OFFDIN_PT23_OPEN					(0x00<< GPIO_PT2OFFDIN_PT23_POS)
#define GPIO_PT2OFFDIN_PT23_CLOSE					(0x01<< GPIO_PT2OFFDIN_PT23_POS)
#define GPIO_PT2OFFDIN_PT23_MASK					(GPIO_PT2OFFDIN_PT23_BITS<< GPIO_PT2OFFDIN_PT23_POS)
#define __GPIO_PT2OFFDIN_PT23_GET()					M_REG_GET(GPIO_PT2OFFDIN_PT23_REG, GPIO_PT2OFFDIN_PT23_POS, GPIO_PT2OFFDIN_PT23_BITS)
#define __GPIO_PT2OFFDIN_PT23_SET(SET)				M_REG_SET(GPIO_PT2OFFDIN_PT23_REG, GPIO_PT2OFFDIN_PT23_POS, GPIO_PT2OFFDIN_PT23_BITS, SET)
#define __GPIO_PT2OFFDIN_PT23_GET_SHIFT()			M_REG_GET_SHIFT(GPIO_PT2OFFDIN_PT23_REG, GPIO_PT2OFFDIN_PT23_POS, GPIO_PT2OFFDIN_PT23_BITS)
#define __GPIO_PT2OFFDIN_PT23_SET_SHIFT(POS_SET)	M_REG_SET_SHIFT(GPIO_PT2OFFDIN_PT23_REG, GPIO_PT2OFFDIN_PT23_POS, GPIO_PT2OFFDIN_PT23_BITS, POS_SET)

//PT3OFFDIN_PT36
#define GPIO_PT3OFFDIN_PT36_REG						PTOFFDIN
#define GPIO_PT3OFFDIN_PT36_POS						(5)
#define GPIO_PT3OFFDIN_PT36_BITS					C_REG_BITS1
#define GPIO_PT3OFFDIN_PT36_OPEN					(0x00<< GPIO_PT3OFFDIN_PT36_POS)
#define GPIO_PT3OFFDIN_PT36_CLOSE					(0x01<< GPIO_PT3OFFDIN_PT36_POS)
#define GPIO_PT3OFFDIN_PT36_MASK					(GPIO_PT3OFFDIN_PT36_BITS<< GPIO_PT3OFFDIN_PT36_POS)
#define __GPIO_PT3OFFDIN_PT36_GET()					M_REG_GET(GPIO_PT3OFFDIN_PT36_REG, GPIO_PT3OFFDIN_PT36_POS, GPIO_PT3OFFDIN_PT36_BITS)
#define __GPIO_PT3OFFDIN_PT36_SET(SET)				M_REG_SET(GPIO_PT3OFFDIN_PT36_REG, GPIO_PT3OFFDIN_PT36_POS, GPIO_PT3OFFDIN_PT36_BITS, SET)
#define __GPIO_PT3OFFDIN_PT36_GET_SHIFT()			M_REG_GET_SHIFT(GPIO_PT3OFFDIN_PT36_REG, GPIO_PT3OFFDIN_PT36_POS, GPIO_PT3OFFDIN_PT36_BITS)
#define __GPIO_PT3OFFDIN_PT36_SET_SHIFT(POS_SET)	M_REG_SET_SHIFT(GPIO_PT3OFFDIN_PT36_REG, GPIO_PT3OFFDIN_PT36_POS, GPIO_PT3OFFDIN_PT36_BITS, POS_SET)

//PT3OFFDIN_PT35
#define GPIO_PT3OFFDIN_PT35_REG						PTOFFDIN
#define GPIO_PT3OFFDIN_PT35_POS						(4)
#define GPIO_PT3OFFDIN_PT35_BITS					C_REG_BITS1
#define GPIO_PT3OFFDIN_PT35_OPEN					(0x00<< GPIO_PT3OFFDIN_PT35_POS)
#define GPIO_PT3OFFDIN_PT35_CLOSE					(0x01<< GPIO_PT3OFFDIN_PT35_POS)
#define GPIO_PT3OFFDIN_PT35_MASK					(GPIO_PT3OFFDIN_PT35_BITS<< GPIO_PT3OFFDIN_PT35_POS)
#define __GPIO_PT3OFFDIN_PT35_GET()					M_REG_GET(GPIO_PT3OFFDIN_PT35_REG, GPIO_PT3OFFDIN_PT35_POS, GPIO_PT3OFFDIN_PT35_BITS)
#define __GPIO_PT3OFFDIN_PT35_SET(SET)				M_REG_SET(GPIO_PT3OFFDIN_PT35_REG, GPIO_PT3OFFDIN_PT35_POS, GPIO_PT3OFFDIN_PT35_BITS, SET)
#define __GPIO_PT3OFFDIN_PT35_GET_SHIFT()			M_REG_GET_SHIFT(GPIO_PT3OFFDIN_PT35_REG, GPIO_PT3OFFDIN_PT35_POS, GPIO_PT3OFFDIN_PT35_BITS)
#define __GPIO_PT3OFFDIN_PT35_SET_SHIFT(POS_SET)	M_REG_SET_SHIFT(GPIO_PT3OFFDIN_PT35_REG, GPIO_PT3OFFDIN_PT35_POS, GPIO_PT3OFFDIN_PT35_BITS, POS_SET)

//PT3OFFDIN_PT34
#define GPIO_PT3OFFDIN_PT34_REG						PTOFFDIN
#define GPIO_PT3OFFDIN_PT34_POS						(3)
#define GPIO_PT3OFFDIN_PT34_BITS					C_REG_BITS1
#define GPIO_PT3OFFDIN_PT34_OPEN					(0x00<< GPIO_PT3OFFDIN_PT34_POS)
#define GPIO_PT3OFFDIN_PT34_CLOSE					(0x01<< GPIO_PT3OFFDIN_PT34_POS)
#define GPIO_PT3OFFDIN_PT34_MASK					(GPIO_PT3OFFDIN_PT34_BITS<< GPIO_PT3OFFDIN_PT34_POS)
#define __GPIO_PT3OFFDIN_PT34_GET()					M_REG_GET(GPIO_PT3OFFDIN_PT34_REG, GPIO_PT3OFFDIN_PT34_POS, GPIO_PT3OFFDIN_PT34_BITS)
#define __GPIO_PT3OFFDIN_PT34_SET(SET)				M_REG_SET(GPIO_PT3OFFDIN_PT34_REG, GPIO_PT3OFFDIN_PT34_POS, GPIO_PT3OFFDIN_PT34_BITS, SET)
#define __GPIO_PT3OFFDIN_PT34_GET_SHIFT()			M_REG_GET_SHIFT(GPIO_PT3OFFDIN_PT34_REG, GPIO_PT3OFFDIN_PT34_POS, GPIO_PT3OFFDIN_PT34_BITS)
#define __GPIO_PT3OFFDIN_PT34_SET_SHIFT(POS_SET)	M_REG_SET_SHIFT(GPIO_PT3OFFDIN_PT34_REG, GPIO_PT3OFFDIN_PT34_POS, GPIO_PT3OFFDIN_PT34_BITS, POS_SET)

//PT3OFFDIN_PT33
#define GPIO_PT3OFFDIN_PT33_REG						PTOFFDIN
#define GPIO_PT3OFFDIN_PT33_POS						(2)
#define GPIO_PT3OFFDIN_PT33_BITS					C_REG_BITS1
#define GPIO_PT3OFFDIN_PT33_OPEN					(0x00<< GPIO_PT3OFFDIN_PT33_POS)
#define GPIO_PT3OFFDIN_PT33_CLOSE					(0x01<< GPIO_PT3OFFDIN_PT33_POS)
#define GPIO_PT3OFFDIN_PT33_MASK					(GPIO_PT3OFFDIN_PT33_BITS<< GPIO_PT3OFFDIN_PT33_POS)
#define __GPIO_PT3OFFDIN_PT33_GET()					M_REG_GET(GPIO_PT3OFFDIN_PT33_REG, GPIO_PT3OFFDIN_PT33_POS, GPIO_PT3OFFDIN_PT33_BITS)
#define __GPIO_PT3OFFDIN_PT33_SET(SET)				M_REG_SET(GPIO_PT3OFFDIN_PT33_REG, GPIO_PT3OFFDIN_PT33_POS, GPIO_PT3OFFDIN_PT33_BITS, SET)
#define __GPIO_PT3OFFDIN_PT33_GET_SHIFT()			M_REG_GET_SHIFT(GPIO_PT3OFFDIN_PT33_REG, GPIO_PT3OFFDIN_PT33_POS, GPIO_PT3OFFDIN_PT33_BITS)
#define __GPIO_PT3OFFDIN_PT33_SET_SHIFT(POS_SET)	M_REG_SET_SHIFT(GPIO_PT3OFFDIN_PT33_REG, GPIO_PT3OFFDIN_PT33_POS, GPIO_PT3OFFDIN_PT33_BITS, POS_SET)

//PT3OFFDIN_PT32
#define GPIO_PT3OFFDIN_PT32_REG						PTOFFDIN
#define GPIO_PT3OFFDIN_PT32_POS						(1)
#define GPIO_PT3OFFDIN_PT32_BITS					C_REG_BITS1
#define GPIO_PT3OFFDIN_PT32_OPEN					(0x00<< GPIO_PT3OFFDIN_PT32_POS)
#define GPIO_PT3OFFDIN_PT32_CLOSE					(0x01<< GPIO_PT3OFFDIN_PT32_POS)
#define GPIO_PT3OFFDIN_PT32_MASK					(GPIO_PT3OFFDIN_PT32_BITS<< GPIO_PT3OFFDIN_PT32_POS)
#define __GPIO_PT3OFFDIN_PT32_GET()					M_REG_GET(GPIO_PT3OFFDIN_PT32_REG, GPIO_PT3OFFDIN_PT32_POS, GPIO_PT3OFFDIN_PT32_BITS)
#define __GPIO_PT3OFFDIN_PT32_SET(SET)				M_REG_SET(GPIO_PT3OFFDIN_PT32_REG, GPIO_PT3OFFDIN_PT32_POS, GPIO_PT3OFFDIN_PT32_BITS, SET)
#define __GPIO_PT3OFFDIN_PT32_GET_SHIFT()			M_REG_GET_SHIFT(GPIO_PT3OFFDIN_PT32_REG, GPIO_PT3OFFDIN_PT32_POS, GPIO_PT3OFFDIN_PT32_BITS)
#define __GPIO_PT3OFFDIN_PT32_SET_SHIFT(POS_SET)	M_REG_SET_SHIFT(GPIO_PT3OFFDIN_PT32_REG, GPIO_PT3OFFDIN_PT32_POS, GPIO_PT3OFFDIN_PT32_BITS, POS_SET)

//PT3OFFDIN_PT31
#define GPIO_PT3OFFDIN_PT31_REG						PTOFFDIN
#define GPIO_PT3OFFDIN_PT31_POS						(0)
#define GPIO_PT3OFFDIN_PT31_BITS					C_REG_BITS1
#define GPIO_PT3OFFDIN_PT31_OPEN					(0x00<< GPIO_PT3OFFDIN_PT31_POS)
#define GPIO_PT3OFFDIN_PT31_CLOSE					(0x01<< GPIO_PT3OFFDIN_PT31_POS)
#define GPIO_PT3OFFDIN_PT31_MASK					(GPIO_PT3OFFDIN_PT31_BITS<< GPIO_PT3OFFDIN_PT31_POS)
#define __GPIO_PT3OFFDIN_PT31_GET()					M_REG_GET(GPIO_PT3OFFDIN_PT31_REG, GPIO_PT3OFFDIN_PT31_POS, GPIO_PT3OFFDIN_PT31_BITS)
#define __GPIO_PT3OFFDIN_PT31_SET(SET)				M_REG_SET(GPIO_PT3OFFDIN_PT31_REG, GPIO_PT3OFFDIN_PT31_POS, GPIO_PT3OFFDIN_PT31_BITS, SET)
#define __GPIO_PT3OFFDIN_PT31_GET_SHIFT()			M_REG_GET_SHIFT(GPIO_PT3OFFDIN_PT31_REG, GPIO_PT3OFFDIN_PT31_POS, GPIO_PT3OFFDIN_PT31_BITS)
#define __GPIO_PT3OFFDIN_PT31_SET_SHIFT(POS_SET)	M_REG_SET_SHIFT(GPIO_PT3OFFDIN_PT31_REG, GPIO_PT3OFFDIN_PT31_POS, GPIO_PT3OFFDIN_PT31_BITS, POS_SET)
/**@}*/ /*** end of group gpio_reg_ptoffdin */

/** 
 * @addtogroup	gpio_reg_ptshort	reg: PTSHORT
 * @{
 */
//PTSHORT
//SHORT_2023
#define GPIO_SHORT_2023_REG							PTSHORT
#define GPIO_SHORT_2023_POS							(3)
#define GPIO_SHORT_2023_BITS						C_REG_BITS1
#define GPIO_SHORT_2023_CLOSE						(0x00<< GPIO_SHORT_2023_POS)
#define GPIO_SHORT_2023_OPEN						(0x01<< GPIO_SHORT_2023_POS)
#define GPIO_SHORT_2023_MASK						(GPIO_SHORT_2023_BITS<< GPIO_SHORT_2023_POS)
#define __GPIO_SHORT_2023_GET()						M_REG_GET(GPIO_SHORT_2023_REG, GPIO_SHORT_2023_POS, GPIO_SHORT_2023_BITS)
#define __GPIO_SHORT_2023_SET(SET)					M_REG_SET(GPIO_SHORT_2023_REG, GPIO_SHORT_2023_POS, GPIO_SHORT_2023_BITS, SET)
#define __GPIO_SHORT_2023_GET_SHIFT()				M_REG_GET_SHIFT(GPIO_SHORT_2023_REG, GPIO_SHORT_2023_POS, GPIO_SHORT_2023_BITS)
#define __GPIO_SHORT_2023_SET_SHIFT(POS_SET)		M_REG_SET_SHIFT(GPIO_SHORT_2023_REG, GPIO_SHORT_2023_POS, GPIO_SHORT_2023_BITS, POS_SET)

//SHORT_2124
#define GPIO_SHORT_2124_REG							PTSHORT
#define GPIO_SHORT_2124_POS							(2)
#define GPIO_SHORT_2124_BITS						C_REG_BITS1
#define GPIO_SHORT_2124_CLOSE						(0x00<< GPIO_SHORT_2124_POS)
#define GPIO_SHORT_2124_OPEN						(0x01<< GPIO_SHORT_2124_POS)
#define GPIO_SHORT_2124_MASK						(GPIO_SHORT_2124_BITS<< GPIO_SHORT_2124_POS)
#define __GPIO_SHORT_2124_GET()						M_REG_GET(GPIO_SHORT_2124_REG, GPIO_SHORT_2124_POS, GPIO_SHORT_2124_BITS)
#define __GPIO_SHORT_2124_SET(SET)					M_REG_SET(GPIO_SHORT_2124_REG, GPIO_SHORT_2124_POS, GPIO_SHORT_2124_BITS, SET)
#define __GPIO_SHORT_2124_GET_SHIFT()				M_REG_GET_SHIFT(GPIO_SHORT_2124_REG, GPIO_SHORT_2124_POS, GPIO_SHORT_2124_BITS)
#define __GPIO_SHORT_2124_SET_SHIFT(POS_SET)		M_REG_SET_SHIFT(GPIO_SHORT_2124_REG, GPIO_SHORT_2124_POS, GPIO_SHORT_2124_BITS, POS_SET)

//SHORT_2225
#define GPIO_SHORT_2225_REG							PTSHORT
#define GPIO_SHORT_2225_POS							(1)
#define GPIO_SHORT_2225_BITS						C_REG_BITS1
#define GPIO_SHORT_2225_CLOSE						(0x00<< GPIO_SHORT_2225_POS)
#define GPIO_SHORT_2225_OPEN						(0x01<< GPIO_SHORT_2225_POS)
#define GPIO_SHORT_2225_MASK						(GPIO_SHORT_2225_BITS<< GPIO_SHORT_2225_POS)
#define __GPIO_SHORT_2225_GET()						M_REG_GET(GPIO_SHORT_2225_REG, GPIO_SHORT_2225_POS, GPIO_SHORT_2225_BITS)
#define __GPIO_SHORT_2225_SET(SET)					M_REG_SET(GPIO_SHORT_2225_REG, GPIO_SHORT_2225_POS, GPIO_SHORT_2225_BITS, SET)
#define __GPIO_SHORT_2225_GET_SHIFT()				M_REG_GET_SHIFT(GPIO_SHORT_2225_REG, GPIO_SHORT_2225_POS, GPIO_SHORT_2225_BITS)
#define __GPIO_SHORT_2225_SET_SHIFT(POS_SET)		M_REG_SET_SHIFT(GPIO_SHORT_2225_REG, GPIO_SHORT_2225_POS, GPIO_SHORT_2225_BITS, POS_SET)

//SHORT_3730
#define GPIO_SHORT_3730_REG							PTSHORT
#define GPIO_SHORT_3730_POS							(0)
#define GPIO_SHORT_3730_BITS						C_REG_BITS1
#define GPIO_SHORT_3730_CLOSE						(0x00<< GPIO_SHORT_3730_POS)
#define GPIO_SHORT_3730_OPEN						(0x01<< GPIO_SHORT_3730_POS)
#define GPIO_SHORT_3730_MASK						(GPIO_SHORT_3730_BITS<< GPIO_SHORT_3730_POS)
#define __GPIO_SHORT_3730_GET()						M_REG_GET(GPIO_SHORT_3730_REG, GPIO_SHORT_3730_POS, GPIO_SHORT_3730_BITS)
#define __GPIO_SHORT_3730_SET(SET)					M_REG_SET(GPIO_SHORT_3730_REG, GPIO_SHORT_3730_POS, GPIO_SHORT_3730_BITS, SET)
#define __GPIO_SHORT_3730_GET_SHIFT()				M_REG_GET_SHIFT(GPIO_SHORT_3730_REG, GPIO_SHORT_3730_POS, GPIO_SHORT_3730_BITS)
#define __GPIO_SHORT_3730_SET_SHIFT(POS_SET)		M_REG_SET_SHIFT(GPIO_SHORT_3730_REG, GPIO_SHORT_3730_POS, GPIO_SHORT_3730_BITS, POS_SET)
/**@}*/ /*** end of group gpio_reg_ptshort */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup gpio_port_definition		port_definition
 * @details <b>gpio port definition</b> 
 * @{
 */
/** 
 * @name gpio port number
 * @{
 */
#define GPIO_1							PT1				///< gpio data port 1
#define GPIO_1EN						PT1EN			///< gpio dir port 1
#define GPIO_1PU						PT1PU			///< gpio pull-up port 1
	
#define GPIO_2							PT2				///< gpio data port 2
#define GPIO_2EN						PT2EN           ///< gpio dir port 2
#define GPIO_2PU						PT2PU           ///< gpio pull-up port 2
	
#define GPIO_3							PT3				///< gpio data port 3
#define GPIO_3EN						PT3EN           ///< gpio dir port 3
#define GPIO_3PU						PT3PU           ///< gpio pull-up port 3
/**@}*/ /*** end of name gpio port number */


/** 
 * @name gpio pin number
 * @{
 */
#define GPIO_BIT0						0x00			///< gpio pin 0
#define GPIO_BIT1						0x01			///< gpio pin 1
#define GPIO_BIT2						0x02            ///< gpio pin 2
#define GPIO_BIT3						0x03            ///< gpio pin 3
#define GPIO_BIT4						0x04            ///< gpio pin 4
#define GPIO_BIT5						0x05            ///< gpio pin 5
#define GPIO_BIT6						0x06            ///< gpio pin 6
#define GPIO_BIT7						0x07            ///< gpio pin 7
/**@}*/ /*** end of name gpio pin number */

/** 
 * @name gpio port-pin number
 * @{
 */
#define GPIO_PT10						0x00			///< gpio port-pin PT10
#define GPIO_PT11						0x01			///< gpio port-pin PT11
#define GPIO_PT12						0x02            ///< gpio port-pin PT12
#define GPIO_PT13						0x03            ///< gpio port-pin PT13
#define GPIO_PT14						0x04            ///< gpio port-pin PT14
#define GPIO_PT15						0x05            ///< gpio port-pin PT15
#define GPIO_PT16						0x06            ///< gpio port-pin PT16
#define GPIO_PT17						0x07            ///< gpio port-pin PT17
#define GPIO_PT20						0x08            ///< gpio port-pin PT20
#define GPIO_PT21						0x09            ///< gpio port-pin PT21
#define GPIO_PT22						0x0A            ///< gpio port-pin PT22
#define GPIO_PT23						0x0B            ///< gpio port-pin PT23
#define GPIO_PT24						0x0C            ///< gpio port-pin PT24
#define GPIO_PT25						0x0D            ///< gpio port-pin PT25
#define GPIO_PT26						0x0E            ///< gpio port-pin PT26(reserved)
#define GPIO_PT27						0x0F            ///< gpio port-pin PT27
#define GPIO_PT30						0x10            ///< gpio port-pin PT30
#define GPIO_PT31						0x11            ///< gpio port-pin PT31
#define GPIO_PT32						0x12            ///< gpio port-pin PT32
#define GPIO_PT33						0x13            ///< gpio port-pin PT33
#define GPIO_PT34						0x14            ///< gpio port-pin PT34
#define GPIO_PT35						0x15            ///< gpio port-pin PT35
#define GPIO_PT36						0x16            ///< gpio port-pin PT36
#define GPIO_PT37						0x17            ///< gpio port-pin PT37
/**@}*/ /*** end of name gpio port-pin number */
/**@}*/ /*** end of group gpio_port_definition */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup gpio_enum	enum
 * @{
 */
/**
 * @brief  gpio - port number.
 */
typedef enum
{
	gpio_1	= (uint8_t)0x00,			/*!< gpio port 1 */
	gpio_2,								/*!< gpio port 2 */
	gpio_3,								/*!< gpio port 3 */
}port_gpio_t;

/**
 * @brief  gpio - pin number.
 */
typedef enum
{
	pin_0	= (uint8_t)0x00,			/*!< gpio pin 0	*/
	pin_1,                          	/*!< gpio pin 1	*/
	pin_2,                          	/*!< gpio pin 2	*/
	pin_3,                          	/*!< gpio pin 3	*/
	pin_4,                          	/*!< gpio pin 4	*/
	pin_5,                          	/*!< gpio pin 5	*/
	pin_6,                          	/*!< gpio pin 6	*/
	pin_7,                          	/*!< gpio pin 7	*/
}port_pin_t;

/**
 * @brief  gpio - port-pin number.
 */
typedef enum 
{
	pt10	= (uint8_t)0x00,			/*!< gpio pt10 */
	pt11	= (uint8_t)0x01,        	/*!< gpio pt11 */
	pt12	= (uint8_t)0x02,        	/*!< gpio pt12 */
	pt13	= (uint8_t)0x03,        	/*!< gpio pt13 */
	pt14	= (uint8_t)0x04,        	/*!< gpio pt14 */
	pt15	= (uint8_t)0x05,        	/*!< gpio pt15 */
	pt16	= (uint8_t)0x06,        	/*!< gpio pt16 */
	pt17	= (uint8_t)0x07,        	/*!< gpio pt17 */
	pt20	= (uint8_t)0x08,        	/*!< gpio pt20 */
	pt21	= (uint8_t)0x09,        	/*!< gpio pt21 */
	pt22	= (uint8_t)0x0A,        	/*!< gpio pt22 */
	pt23	= (uint8_t)0x0B,        	/*!< gpio pt23 */
	pt24	= (uint8_t)0x0C,        	/*!< gpio pt24 */
	pt25	= (uint8_t)0x0D,        	/*!< gpio pt25 */
	pt26	= (uint8_t)0x0E,        	/*!< gpio pt26 */
	pt27	= (uint8_t)0x0F,        	/*!< gpio pt27(reserved) */
	pt30	= (uint8_t)0x10,        	/*!< gpio pt30 */
	pt31	= (uint8_t)0x11,        	/*!< gpio pt31 */
	pt32	= (uint8_t)0x12,        	/*!< gpio pt32 */
	pt33	= (uint8_t)0x13,        	/*!< gpio pt33 */
	pt34	= (uint8_t)0x14,        	/*!< gpio pt34 */
	pt35	= (uint8_t)0x15,        	/*!< gpio pt35 */
	pt36	= (uint8_t)0x16,        	/*!< gpio pt36 */
	pt37	= (uint8_t)0x17,        	/*!< gpio pt37 */
	pt20_23	= (uint8_t)0x18,        	/*!< gpio pt20_23 */
	pt21_24	= (uint8_t)0x19,        	/*!< gpio pt21_24 */
	pt22_25	= (uint8_t)0x1A,        	/*!< gpio pt22_25 */
	pt37_30	= (uint8_t)0x1B,        	/*!< gpio pt37_30 */
}port_t;

/**
 * @brief  gpio - pinmux_func number.
 */
typedef enum
{
	pinmux_func0	= (uint8_t)0x00,	/*!< gpio pinmux func 0	*/
	pinmux_func1,						/*!< gpio pinmux func 1	*/
	pinmux_func2,						/*!< gpio pinmux func 2	*/
	pinmux_func3,						/*!< gpio pinmux func 3	*/
}pinmux_t;

/**
 * @brief  gpio - mode number.
 */
typedef enum
{
	mode_pp			= (uint8_t)0x00,	/*!< gpio mode push output			*/
	mode_od,                            /*!< gpio mode open drain output	*/
	mode_digital_in_open,               /*!< gpio mode digital input on		*/
	mode_digital_in_close,              /*!< gpio mode digital input closed	*/
	mode_bypass_close,                  /*!< gpio mode bypass close			*/
	mode_bypass_open,                   /*!< gpio mode bypass open			*/
}gpio_mode_t;

/**
 * @brief  gpio - direction number.
 */
typedef enum
{
	dir_input		= (uint8_t)0x00,	/*!< gpio input		*/
	dir_output,							/*!< gpio output	*/
}gpio_direction_t;

/**
 * @brief  gpio - pullup number.
 */
typedef enum
{
	no_pull			= (uint8_t)0x00,	/*!< gpio close pull up	*/
	pull_up,                            /*!< gpio pull up	*/
}gpio_pull_t;

/**
 * @brief  gpio - operate number.
 */
typedef enum
{
	bit_reset		= (uint8_t)0x00,	/*!< gpio bit reset	 */
	bit_set,                            /*!< gpio bit set	 */
	bit_toggle,                         /*!< gpio bit toggle */
}gpio_bit_t;
/**@}*/ /*** end of group gpio_enum */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup gpio_struct	struct
 * @{
 */
/**
 * @brief gpio - register layout typedef
 */
typedef struct
{
	uint8_t PTx;                              	//!< port data register,				offset: 0x00
	uint8_t PTxEN;                              //!< port dir  register,				offset: 0x01
	uint8_t PTxPU;                              //!< port pullup output register,	offset: 0x02
	// uint8_t PTxXX;                              /*! port special function register,	offset: 0x03
	// uint8_t PTxXX;                              /*! port special function register,	offset: 0x04
}gpio_type_t;

/**
 * @brief gpio configuration structure
 */
typedef struct
{
	port_t				gpio_pin;				//!< Specifies the GPIO pins to be configured                                       
    port_gpio_t			gpio_portx;				//!< Specifies the GPIO pins to be configured                                       
    port_pin_t			gpio_pinx;				//!< Specifies the GPIO pins to be configured                                       
    pinmux_t			gpio_pinmux;			//!< Specifies the GPIO pinmux
    gpio_direction_t	gpio_dir;				//!< Specifies the operating mode for the selected pins
    gpio_mode_t        	gpio_mode;				//!< Specifies the operating mode for the selected pins
    gpio_pull_t			gpio_pull;				//!< Specifies the operating Pull-up/Pull down for the selected pins
}gpio_config_t;
/**@}*/ /*** end of group gpio_struct */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup gpio_api	api
 * @details <b>APPENDIX: TRUE LOVE GIFT</b>
 * @details gpio pin_mux map
 * | port	| func0	| func1		| func2		| func3		|		
 * | :----:	| :----:| :----:	| :----:	| :----:	|
 * | PT2.0	| gpio	| reserved	| reserved	| reserved	|
 * | PT2.1	| gpio	| reserved	| reserved	| reserved	|
 * | PT2.2	| gpio	| analog	| pwm4		| t3_in		|
 * | PT2.3	| gpio	| reserved	| reserved	| reserved	|
 * | PT2.4	| gpio	| xout		| reserved	| reserved	|
 * | PT2.5	| gpio	| xin		| reserved	| reserved	|
 * | PT2.6	| gpio	| reserved	| reserved	| reserved	|
 * | PT2.7	| gpio	| reserved	| reserved	| reserved	|
 * | pt2.0	| gpio	| ain8		| reserved	| reserved	|
 * | pt2.1	| gpio	| ain9		| reserved	| reserved	|
 * | pt2.2	| gpio	| ain10		| reserved	| reserved	|
 * | pt2.3	| gpio	| ain11		| dp_b		| pwm2		|
 * | pt2.4	| gpio	| ain12		| dm_b		| pwm3		|
 * | pt2.5	| gpio	| ain13		| pwm3h		| icd		|
 * | pt2.6	| gpio	| ain14		| pwm3l		| reserved	|
 * | pt3.0	| gpio	| ain0		| reserved	| reserved	|
 * | pt3.1	| gpio	| ain1		| uart_tx	| dp_a		|
 * | pt3.2	| gpio	| ain2		| uart_rx	| dm_a		|
 * | pt3.3	| gpio	| ain3		| uart_tx	| dp_d		|
 * | pt3.4	| gpio	| ain4		| uart_rx	| dm_d		|
 * | pt3.5	| gpio	| ain5		| uart_tx	| dp_c		|
 * | pt3.6	| gpio	| ain6		| uart_rx	| dm_c		|
 * | pt3.7	| gpio	| ain7		| reserved	| reserved	|
 * @{
 */
/** 
 * @name gpio_api: config
 * @{
 */
/**
 * @brief 	<b>Description:</b> gpio port multiplexing configuration.
 * @details <b>Function prototype:</b> void gpio_pinmux_config(gpio_config_t *_gpio_config);
 * @param[in]  gpio_config_t					gpio configuration structure.
 * @param[in]  gpio_config_t->gpio_portx		gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  gpio_config_t->gpio_pinx			gpio pin number{pin_0~ pin_7}.
 * @param[in]  gpio_config_t->gpio_pinmux		gpio port multiplex number{pinmux_func0~ pinmux_func3}.
 * @param[out] null.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *		 	gpio_config_t	gpio_cfg;
 *		 	gpio_cfg.gpio_portx= gpio_1;
 *		 	gpio_cfg.gpio_pinx= pin_0;
 *		 	gpio_cfg.gpio_pinmux= pinmux_func0;
 *		 	gpio_pinmux_config(&gpio_cfg);
 *		}
 * @endcode
 */
void gpio_pinmux_config(gpio_config_t *_gpio_config);

/**
 * @brief 	<b>Description:</b> gpio port input and output direction configuration.
 * @details <b>Function prototype:</b> void gpio_direction_config(gpio_config_t *_gpio_config);
 * @param[in]  gpio_config_t					gpio configuration structure.
 * @param[in]  gpio_config_t->gpio_portx		gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  gpio_config_t->gpio_pinx			gpio pin number{pin_0~ pin_7}.
 * @param[in]  gpio_config_t->gpio_dir			gpio port input and output direction{dir_input, dir_output}.
 * @param[out] null	.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *		 	gpio_config_t	gpio_cfg;
 *		 	gpio_cfg.gpio_portx= gpio_1;
 *		 	gpio_cfg.gpio_pinx= pin_0;
 *		 	gpio_cfg.gpio_dir= dir_input;
 *		 	gpio_direction_config(&gpio_cfg);
 *		}
 * @endcode
 */
void gpio_direction_config(gpio_config_t *_gpio_config);

/**
 * @brief 	<b>Description:</b> gpio port input and output pull-up configuration.
 * @details <b>Function prototype:</b> void gpio_pull_config(gpio_config_t *_gpio_config);
 * @param[in]  gpio_config_t					gpio configuration structure.
 * @param[in]  gpio_config_t->gpio_portx		gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  gpio_config_t->gpio_pinx			gpio pin number{pin_0~ pin_7}.
 * @param[in]  gpio_config_t->gpio_pull			gpio port pull-up{no_pull, pull_up}.
 * @param[out] null	.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *		 	gpio_config_t	gpio_cfg;
 *		 	gpio_cfg.gpio_portx= gpio_1;
 *		 	gpio_cfg.gpio_pinx= pin_0;
 *		 	gpio_cfg.gpio_pull= pull_up;
 *		 	gpio_pull_config(&gpio_cfg);
 *		}
 * @endcode
 */
void gpio_pull_config(gpio_config_t *_gpio_config);

/**
 * @brief 	<b>Description:</b> gpio port input and output mode configuration.
 * @details <b>Function prototype:</b> void gpio_mode_config(gpio_config_t *_gpio_config);
 * @param[in]  gpio_config_t					gpio configuration structure.
 * @param[in]  gpio_config_t->gpio_pin			gpio port_pin number{enum->port_t}.
 * @param[in]  gpio_config_t->gpio_mode			gpio port input and output mode{enum->gpio_mode_t}.
 * @param[out] null	.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *		 	gpio_config_t	gpio_cfg;
 *		 	gpio_cfg.gpio_pin= pt10;
 *		 	gpio_cfg.gpio_mode= mode_pp;
 *		 	gpio_mode_config(&gpio_cfg);
 *		}
 * @endcode
 */
void gpio_mode_config(gpio_config_t *_gpio_config);

/**
 * @brief 	<b>Description:</b> gpio initialization.
 * @details <b>Function prototype:</b> void gpio_init(gpio_config_t *_gpio_config);
 * @param[in]  gpio_config_t					gpio configuration structure.
 * @param[in]  gpio_config_t->gpio_pin			gpio port_pin number{enum->port_t}.
 * @param[in]  gpio_config_t->gpio_portx		gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  gpio_config_t->gpio_pinx			gpio pin number{pin_0~ pin_7}.
 * @param[in]  gpio_config_t->gpio_pinmux		gpio port multiplex number{pinmux_func0~ pinmux_func3}.
 * @param[in]  gpio_config_t->gpio_dir			gpio port input and output direction{dir_input, dir_output}.
 * @param[in]  gpio_config_t->gpio_pull			gpio port pull-up{no_pull, pull_up}.
 * @param[in]  gpio_config_t->gpio_mode			gpio port input and output mode{gpio_mode_t}.
 * @param[out] null	.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *		 	gpio_config_t	gpio_cfg;
 *		 	gpio_cfg.gpio_pin= pt10;
 *		 	gpio_cfg.gpio_portx= gpio_1;
 *		 	gpio_cfg.gpio_pinx= pin_0;
 *		 	gpio_cfg.gpio_pinmux= pinmux_func0;
 *		 	gpio_cfg.gpio_dir= dir_input;
 *		 	gpio_cfg.gpio_mode= mode_pp;
 *		 	gpio_cfg.gpio_pull= pull_up;
 *		 	gpio_init(&gpio_cfg);
 *		}
 * @endcode
 */
void gpio_init(gpio_config_t *_gpio_config);
/**@}*/ /*** end of name gpio_api: config */


/** 
 * @name gpio_api: port operation
 * @{
 */
/**
 * @brief 	<b>Description:</b> gpio pull-up bit.
 * @details <b>Function prototype:</b> void gpio_dir_bit(port_gpio_t _port, port_pin_t _pin, gpio_direction_t _dir);
 * @param[in]  port_gpio_t _port		gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  port_pin_t _pin			gpio pin number{pin_0~ pin_7}.
 * @param[in]  gpio_pull_t _pull		gpio pull-up{no_pull, pull_up}.
 * @param[out] null	.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *		 	gpio_pull_bit(gpio_1, pin_0, no_pull);
 *		 	gpio_pull_bit(gpio_1, pin_1, pull_up);
 *		}
 * @endcode
 */
void gpio_pull_bit(port_gpio_t _port, port_pin_t _pin, gpio_pull_t _pull);

/**
 * @brief 	<b>Description:</b> gpio dir bit.
 * @details <b>Function prototype:</b> void gpio_dir_bit(port_gpio_t _port, port_pin_t _pin, gpio_direction_t _dir);
 * @param[in]  port_gpio_t _port		gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  port_pin_t _pin			gpio pin number{pin_0~ pin_7}.
 * @param[in]  gpio_direction_t _dir	gpio input and output direction{dir_input, dir_output}.
 * @param[out] null	.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *		 	gpio_dir_bit(gpio_1, pin_0, dir_input);
 *		 	gpio_dir_bit(gpio_1, pin_1, dir_output);
 *		}
 * @endcode
 */
void gpio_dir_bit(port_gpio_t _port, port_pin_t _pin, gpio_direction_t _dir);

/**
 * @brief 	<b>Description:</b> gpio reset bit.
 * @details <b>Function prototype:</b> void gpio_reset_bit(port_gpio_t _port, port_pin_t _pin);
 * @param[in]  port_gpio_t _port	gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  port_pin_t _pin		gpio pin number{pin_0~ pin_7}.
 * @param[out] null	.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *		 	gpio_reset_bit(gpio_1, pin_0);
 *		}
 * @endcode
 */
void gpio_reset_bit(port_gpio_t _port, port_pin_t _pin);

/**
 * @brief 	<b>Description:</b> gpio set bit.
 * @details <b>Function prototype:</b> void gpio_set_bit(port_gpio_t _port, port_pin_t _pin);
 * @param[in]  port_gpio_t _port	gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  port_pin_t _pin		gpio pin number{pin_0~ pin_7}.
 * @param[out] null	.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *		 	gpio_set_bit(gpio_1, pin_0);
 *		}
 * @endcode
 */
void gpio_set_bit(port_gpio_t _port, port_pin_t _pin);

/**
 * @brief 	<b>Description:</b> gpio toggle bit.
 * @details <b>Function prototype:</b> void gpio_toggle_bit(port_gpio_t _port, port_pin_t _pin);
 * @param[in]  port_gpio_t _port	gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  port_pin_t _pin		gpio pin number{pin_0~ pin_7}.
 * @param[out] null	.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *		 	gpio_toggle_bit(gpio_1, pin_0);
 *		}
 * @endcode
 */
void gpio_toggle_bit(port_gpio_t _port, port_pin_t _pin);

/**
 * @brief 	<b>Description:</b> gpio write bit.
 * @details <b>Function prototype:</b> void gpio_write_bit(port_gpio_t _port, port_pin_t _pin, bool _set);
 * @param[in]  port_gpio_t _port	gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  port_pin_t _pin		gpio pin number{pin_0~ pin_7}.
 * @param[in]  bool _set			gpio pin set{true, false}.
 * @param[out] null	.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *		 	gpio_write_bit(gpio_1, pin_0, true);
 *		}
 * @endcode
 */
void gpio_write_bit(port_gpio_t _port, port_pin_t _pin, bool _set);

/**
 * @brief 	<b>Description:</b> gpio read bit.
 * @details <b>Function prototype:</b> bool gpio_read_bit(port_gpio_t _port, port_pin_t _pin);
 * @param[in]  port_gpio_t _port	gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  port_pin_t _pin		gpio pin number{pin_0~ pin_7}.
 * @param[out] null	.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *		 	bool 	gpio1_1_value;
 *		 	gpio1_1_value= gpio_read_bit(gpio_1, pin_0);
 *		}
 * @endcode
 */
bool gpio_read_bit(port_gpio_t _port, port_pin_t _pin);

/**
 * @brief 	<b>Description:</b> gpio write port.
 * @details <b>Function prototype:</b> void gpio_write_port(uint8_t _port, uint8_t _data);
 * @param[in]  port_gpio_t _port	gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  uint8_t _data		gpio pin data.
 * @param[out] null	.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *		 	gpio_write_port(gpio_1, 0xFF);
 *		}
 * @endcode
 */
void gpio_write_port(uint8_t _port, uint8_t _data);

/**
 * @brief 	<b>Description:</b> gpio write port.
 * @details <b>Function prototype:</b> uint8_t gpio_read_port(port_gpio_t _port);
 * @param[in]  port_gpio_t _port	gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[out] null	.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *		 	uint8_t		gpio1_value;
 *		 	gpio1_value= gpio_read_port(gpio_1);
 *		}
 * @endcode
 */
uint8_t gpio_read_port(port_gpio_t _port);

/**@}*/ /*** end of name gpio_api: port operation */


/** 
 * @name gpio_api: port operation macro
 * - <b>Features: </b> Fast gpio-pin operation
 * @param[in] port		gpio port{GPIO_1, GPIO_2, GPIO_3}
 * @param[in] bit		gpio pin{GPIO_BIT0~ GPIO_BIT7}
 * @param[in] set		gpio output set{true, false}
 * @param[in] port_dir	gpio port{GPIO_1EN, GPIO_2EN, GPIO_3EN}
 * @return  value		gpio input data{true, false}
 * @{
 */
#define PTXOUT(port, bit, set)			M_REG_SET(port, bit, 0x01, set)
#define PTXIN(port, bit)				M_REG_GET(port, bit, 0x01)
#define PTXTOGGLE(port, bit)			M_REG_TOGGLEBIT(port, bit)
#define PTX_DIR_IN(port_dir, bit)		M_REG_SET(port_dir, bit, 0x01, 0)
#define PTX_DIR_OUT(port_dir, bit)		M_REG_SET(port_dir, bit, 0x01, 1)

#define PT1OUT(bit, set)				M_REG_SET(GPIO_PT1_REG, bit, 0x01, set)
#define PT1IN(bit)						M_REG_GET(GPIO_PT1_REG, bit, 0x01)
#define PT1TOGGLE(bit)					M_REG_TOGGLEBIT(GPIO_PT1_REG, bit)
	
#define PT2OUT(bit, set)				M_REG_SET(GPIO_PT2_REG, bit, 0x01, set)
#define PT2IN(bit)						M_REG_GET(GPIO_PT2_REG, bit, 0x01)
#define PT2TOGGLE(bit)					M_REG_TOGGLEBIT(GPIO_PT2_REG, bit)
	
#define PT3OUT(bit, set)				M_REG_SET(GPIO_PT3_REG, bit, 0x01, set)
#define PT3IN(bit)						M_REG_GET(GPIO_PT3_REG, bit, 0x01)
#define PT3TOGGLE(bit)					M_REG_TOGGLEBIT(GPIO_PT3_REG, bit)
/**@}*/ /*** end of name gpio_api: port operation macro */
/**@}*/ /*** end of group gpio_api */
/**@}*/ /*** end of group csu39fx10_sdk_chip_driver_gpio */
/**@}*/ /*** end of group csu39fx10_sdk_chip_driver */
/**@}*/ /*** end of group csu39fx10_sdk_chip */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 *	appendix: true love gift
 *
 *	gpio pin_mux map
 *			 ___________________________________________________________
 *			|	port	|	func0	|	func1	|	func2	|	func3	|														 		|
 *			|___________|___________|___________|___________|___________|
 *			|	PT2.0	|	gpio	|	reserved|	reserved|	reserved|
 *			|___________|___________|___________|___________|___________|
 *			|	PT2.1	|	gpio	|	reserved|	reserved|	reserved|
 *			|___________|___________|___________|___________|___________|
 *			|	PT2.2	|	gpio	|	analog	|	pwm4	|	t3_in	|
 *			|___________|___________|___________|___________|___________|
 *			|	PT2.3	|	gpio	|	reserved|	reserved|	reserved|
 *			|___________|___________|___________|___________|___________|
 *			|	PT2.4	|	gpio	|	xout	|	reserved|	reserved|
 *			|___________|___________|___________|___________|___________|
 *			|	PT2.5	|	gpio	|	xin		|	reserved|	reserved|
 *			|___________|___________|___________|___________|___________|
 *			|	PT2.6	|	gpio	|	reserved|	reserved|	reserved|
 *			|___________|___________|___________|___________|___________|
 *			|	PT2.7	|	gpio	|	reserved|	reserved|	reserved|
 *			|___________|___________|___________|___________|___________|
 *			|	pt2.0	|	gpio	|	ain8	|	reserved|	reserved|
 *			|___________|___________|___________|___________|___________|
 *			|	pt2.1	|	gpio	|	ain9	|	reserved|	reserved|
 *			|___________|___________|___________|___________|___________|
 *			|	pt2.2	|	gpio	|	ain10	|	reserved|	reserved|
 *			|___________|___________|___________|___________|___________|
 *			|	pt2.3	|	gpio	|	ain11	|	dp_b	|	pwm2	|
 *			|___________|___________|___________|___________|___________|
 *			|	pt2.4	|	gpio	|	ain12	|	dm_b	|	pwm3	|
 *			|___________|___________|___________|___________|___________|
 *			|	pt2.5	|	gpio	|	ain13	|	pwm3h	|	icd		|
 *			|___________|___________|___________|___________|___________|
 *			|	pt2.6	|	gpio	|	ain14	|	pwm3l	|	reserved|
 *			|___________|___________|___________|___________|___________|
 *			|	pt3.0	|	gpio	|	ain0	|	reserved|	reserved|
 *			|___________|___________|_vref,_ntc_|___________|___________|
 *			|	pt3.1	|	gpio	|	ain1	|	uart_tx	|	dp_a	|
 *			|___________|___________|___________|___________|___________|
 *			|	pt3.2	|	gpio	|	ain2	|	uart_rx	|	dm_a	|
 *			|___________|___________|___________|___________|___________|
 *			|	pt3.3	|	gpio	|	ain3	|	uart_tx	|	dp_d	|
 *			|___________|___________|___cc1_b___|___________|___________|
 *			|	pt3.4	|	gpio	|	ain4	|	uart_rx	|	dm_d	|
 *			|___________|___________|___cc2_b___|___________|___________|
 *			|	pt3.5	|	gpio	|	ain5	|	uart_tx	|	dp_c	|
 *			|___________|___________|___________|___________|___________|
 *			|	pt3.6	|	gpio	|	ain6	|	uart_rx	|	dm_c	|
 *			|___________|___________|___________|___________|___________|
 *			|	pt3.7	|	gpio	|	ain7	|	reserved|	reserved|
 *			|___________|___________|___________|___________|___________|
 *
**/


#ifdef __cplusplus
}
#endif

#endif  //__DRV_GPIO_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/
