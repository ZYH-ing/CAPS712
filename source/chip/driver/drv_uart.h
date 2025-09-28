/***************************************************************************
 * @file     drv_uart.h
 * @version  V1.0.0
 * @author   0531
 * @date     2020-09-23 PM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 ****************************************************************************
 * @par 头文件
 *       csu39fx10.h \n
 *       cs_common.h \n
 *       system_csu39fx10.h \n
 *       drv_gpio.h 
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

#ifndef __DRV_UART_H__
#define __DRV_UART_H__

// Include external header file.
#include "csu39fx10.h"
#include "cs_common.h"
#include "system_csu39fx10.h"
#include "drv_gpio.h"


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
 * @addtogroup csu39fx10_sdk_chip_driver_uart	uart 
 * @{
 */

/** 
 * @addtogroup	uart_reg_ur0_cr1	reg: UR0_CR1 
 * @{
 */
//UR0_CR1
//TX9D
#define UR0_TX9D_REG							UR0_CR1
#define UR0_TX9D_POS							(7)
#define UR0_TX9D_BITS							C_REG_BITS1
#define UR0_TX9D_RESET							(0x00<< UR0_TX9D_POS)
#define UR0_TX9D_SET							(0x01<< UR0_TX9D_POS)
#define UR0_TX9D_MASK							(UR0_TX9D_BITS<< UR0_TX9D_POS)
#define __UR0_TX9D_GET()						M_REG_GET(UR0_TX9D_REG, UR0_TX9D_POS, UR0_TX9D_BITS)
#define __UR0_TX9D_SET(SET)						M_REG_SET(UR0_TX9D_REG, UR0_TX9D_POS, UR0_TX9D_BITS, SET)
#define __UR0_TX9D_GET_SHIFT()					M_REG_GET_SHIFT(UR0_TX9D_REG, UR0_TX9D_POS, UR0_TX9D_BITS)
#define __UR0_TX9D_SET_SHIFT(POS_SET)			M_REG_SET_SHIFT(UR0_TX9D_REG, UR0_TX9D_POS, UR0_TX9D_BITS, POS_SET)

//UR0_CR1
//RX9D, READ-ONLY
#define UR0_RX9D_REG							UR0_CR1
#define UR0_RX9D_POS							(6)
#define UR0_RX9D_BITS							C_REG_BITS1
#define UR0_RX9D_VAL
#define UR0_RX9D_MASK							(UR0_RX9D_BITS<< UR0_RX9D_POS)
#define __UR0_RX9D_GET()						M_REG_GET(UR0_RX9D_REG, UR0_RX9D_POS, UR0_RX9D_BITS)
#define __UR0_RX9D_GET_SHIFT()					M_REG_GET_SHIFT(UR0_RX9D_REG, UR0_RX9D_POS, UR0_RX9D_BITS)

//UR0_CR1
//TX9_EN
#define UR0_TX9_EN_REG							UR0_CR1
#define UR0_TX9_EN_POS							(5)
#define UR0_TX9_EN_BITS							C_REG_BITS1
#define UR0_TX9_EN_DIS							(0x00<< UR0_TX9_EN_POS)
#define UR0_TX9_EN_EN							(0x01<< UR0_TX9_EN_POS)
#define UR0_TX9_EN_MASK							(UR0_TX9_EN_BITS<< UR0_TX9_EN_POS)
#define __UR0_TX9_EN_GET()						M_REG_GET(UR0_TX9_EN_REG, UR0_TX9_EN_POS, UR0_TX9_EN_BITS)
#define __UR0_TX9_EN_SET(EN)					M_REG_SET(UR0_TX9_EN_REG, UR0_TX9_EN_POS, UR0_TX9_EN_BITS, EN)
#define __UR0_TX9_EN_GET_SHIFT()				M_REG_GET_SHIFT(UR0_TX9_EN_REG, UR0_TX9_EN_POS, UR0_TX9_EN_BITS)
#define __UR0_TX9_EN_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(UR0_TX9_EN_REG, UR0_TX9_EN_POS, UR0_TX9_EN_BITS, POS_EN)

//UR0_CR1
//RX9_EN
#define UR0_RX9_EN_REG							UR0_CR1
#define UR0_RX9_EN_POS							(4)
#define UR0_RX9_EN_BITS							C_REG_BITS1
#define UR0_RX9_EN_DIS							(0x00<< UR0_RX9_EN_POS)
#define UR0_RX9_EN_EN							(0x01<< UR0_RX9_EN_POS)
#define UR0_RX9_EN_MASK							(UR0_RX9_EN_BITS<< UR0_RX9_EN_POS)
#define __UR0_RX9_EN_GET()						M_REG_GET(UR0_RX9_EN_REG, UR0_RX9_EN_POS, UR0_RX9_EN_BITS)
#define __UR0_RX9_EN_SET(EN)					M_REG_SET(UR0_RX9_EN_REG, UR0_RX9_EN_POS, UR0_RX9_EN_BITS, EN)
#define __UR0_RX9_EN_GET_SHIFT()				M_REG_GET_SHIFT(UR0_RX9_EN_REG, UR0_RX9_EN_POS, UR0_RX9_EN_BITS)
#define __UR0_RX9_EN_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(UR0_RX9_EN_REG, UR0_RX9_EN_POS, UR0_RX9_EN_BITS, POS_EN)

//UR0_CR1
//RX_EN
#define UR0_RX_EN_REG							UR0_CR1
#define UR0_RX_EN_POS							(3)
#define UR0_RX_EN_BITS							C_REG_BITS1
#define UR0_RX_EN_DIS							(0x00<< UR0_RX_EN_POS)
#define UR0_RX_EN_EN							(0x01<< UR0_RX_EN_POS)
#define UR0_RX_EN_MASK							(UR0_RX_EN_BITS<< UR0_RX_EN_POS)
#define __UR0_RX_EN_GET()						M_REG_GET(UR0_RX_EN_REG, UR0_RX_EN_POS, UR0_RX_EN_BITS)
#define __UR0_RX_EN_SET(EN)						M_REG_SET(UR0_RX_EN_REG, UR0_RX_EN_POS, UR0_RX_EN_BITS, EN)
#define __UR0_RX_EN_GET_SHIFT()					M_REG_GET_SHIFT(UR0_RX_EN_REG, UR0_RX_EN_POS, UR0_RX_EN_BITS)
#define __UR0_RX_EN_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(UR0_RX_EN_REG, UR0_RX_EN_POS, UR0_RX_EN_BITS, POS_EN)

//UR0_CR1
//TX_EN
#define UR0_TX_EN_REG							UR0_CR1
#define UR0_TX_EN_POS							(2)
#define UR0_TX_EN_BITS							C_REG_BITS1
#define UR0_TX_EN_DIS							(0x00<< UR0_TX_EN_POS)
#define UR0_TX_EN_EN							(0x01<< UR0_TX_EN_POS)
#define UR0_TX_EN_MASK							(UR0_TX_EN_BITS<< UR0_TX_EN_POS)
#define __UR0_TX_EN_GET()						M_REG_GET(UR0_TX_EN_REG, UR0_TX_EN_POS, UR0_TX_EN_BITS)
#define __UR0_TX_EN_SET(EN)						M_REG_SET(UR0_TX_EN_REG, UR0_TX_EN_POS, UR0_TX_EN_BITS, EN)
#define __UR0_TX_EN_GET_SHIFT()					M_REG_GET_SHIFT(UR0_TX_EN_REG, UR0_TX_EN_POS, UR0_TX_EN_BITS)
#define __UR0_TX_EN_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(UR0_TX_EN_REG, UR0_TX_EN_POS, UR0_TX_EN_BITS, POS_EN)

//UR0_CR1
//UART0_EN
#define UR0_UART0_EN_REG						UR0_CR1
#define UR0_UART0_EN_POS						(0)
#define UR0_UART0_EN_BITS						C_REG_BITS1
#define UR0_UART0_EN_DIS						(0x00<< UR0_UART0_EN_POS)
#define UR0_UART0_EN_EN							(0x01<< UR0_UART0_EN_POS)
#define UR0_UART0_EN_MASK						(UR0_UART0_EN_BITS<< UR0_UART0_EN_POS)
#define __UR0_UART0_EN_GET()					M_REG_GET(UR0_UART0_EN_REG, UR0_UART0_EN_POS, UR0_UART0_EN_BITS)
#define __UR0_UART0_EN_SET(EN)					M_REG_SET(UR0_UART0_EN_REG, UR0_UART0_EN_POS, UR0_UART0_EN_BITS, EN)
#define __UR0_UART0_EN_GET_SHIFT()				M_REG_GET_SHIFT(UR0_UART0_EN_REG, UR0_UART0_EN_POS, UR0_UART0_EN_BITS)
#define __UR0_UART0_EN_SET_SHIFT(POS_EN)		M_REG_SET_SHIFT(UR0_UART0_EN_REG, UR0_UART0_EN_POS, UR0_UART0_EN_BITS, POS_EN)
/**@}*/ /*** end of group uart_reg_ur0_cr1 */

/** 
 * @addtogroup	uart_reg_ur0_brr0	reg: UR0_BRR0 
 * @{
 */
//UR0_BRR0
//BRR0[7:0]
#define UR0_BRR0_REG							UR0_BRR0
#define UR0_BRR0_POS							(0)
#define UR0_BRR0_VAL
#define UR0_BRR0_MASK							(0xFF<< UR0_BRR0_POS)
#define __UR0_BRR0_GET()						M_REG_GETBYTE(UR0_BRR0_REG, UR0_BRR0_POS)
#define __UR0_BRR0_SET(SET)						M_REG_SETBYTE(UR0_BRR0_REG, UR0_BRR0_POS, SET)
#define __UR0_BRR0_GET_SHIFT()					M_REG_GETBYTE_SHIFT(UR0_BRR0_REG, UR0_BRR0_POS)
#define __UR0_BRR0_SET_SHIFT(POS_SET)			M_REG_SETBYTE_SHIFT(UR0_BRR0_REG, UR0_BRR0_POS, POS_SET)
/**@}*/ /*** end of group uart_reg_ur0_brr0 */

/** 
 * @addtogroup	uart_reg_ur0_brr1	reg: UR0_BRR1 
 * @{
 */
//UR0_BRR1
//AUTO_BR
#define UR0_AUTO_BR_REG							UR0_BRR1
#define UR0_AUTO_BR_POS							(7)
#define UR0_AUTO_BR_BITS						C_REG_BITS1
#define UR0_AUTO_BR_DIS							(0x00<< UR0_AUTO_BR_POS)
#define UR0_AUTO_BR_EN							(0x01<< UR0_AUTO_BR_POS)
#define UR0_AUTO_BR_MASK						(UR0_AUTO_BR_BITS<< UR0_AUTO_BR_POS)
#define __UR0_AUTO_BR_GET()						M_REG_GET(UR0_AUTO_BR_REG, UR0_AUTO_BR_POS, UR0_AUTO_BR_BITS)
#define __UR0_AUTO_BR_SET(EN)					M_REG_SET(UR0_AUTO_BR_REG, UR0_AUTO_BR_POS, UR0_AUTO_BR_BITS, EN)
#define __UR0_AUTO_BR_GET_SHIFT()				M_REG_GET_SHIFT(UR0_AUTO_BR_REG, UR0_AUTO_BR_POS, UR0_AUTO_BR_BITS)
#define __UR0_AUTO_BR_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(UR0_AUTO_BR_REG, UR0_AUTO_BR_POS, UR0_AUTO_BR_BITS, POS_EN)

//UR0_BRR1
//BRR1[3:0]
#define UR0_BRR1_REG							UR0_BRR1
#define UR0_BRR1_POS							(0)
#define UR0_BRR1_BITS							C_REG_BITS4
#define UR0_BRR1_VAL
#define UR0_BRR1_MASK							(UR0_BRR1_BITS<< UR0_BRR1_POS)
#define __UR0_BRR1_GET()						M_REG_GET(UR0_BRR1_REG, UR0_BRR1_POS, UR0_BRR1_BITS)
#define __UR0_BRR1_SET(SET)						M_REG_SET(UR0_BRR1_REG, UR0_BRR1_POS, UR0_BRR1_BITS, SET)
#define __UR0_BRR1_GET_SHIFT()					M_REG_GET_SHIFT(UR0_BRR1_REG, UR0_BRR1_POS, UR0_BRR1_BITS)
#define __UR0_BRR1_SET_SHIFT(POS_SET)			M_REG_SET_SHIFT(UR0_BRR1_REG, UR0_BRR1_POS, UR0_BRR1_BITS, POS_SET)
/**@}*/ /*** end of group uart_reg_ur0_brr1 */

/** 
 * @addtogroup	uart_reg_ur0_tx_reg	reg: UR0_TX_REG 
 * @{
 */
//UR0_TX_REG
//TX_REG[7:0]
#define UR0_TX_REG_REG							UR0_TX_REG
#define UR0_TX_REG_POS							(0)
#define UR0_TX_REG_VAL
#define UR0_TX_REG_MASK							(0xFF<< UR0_TX_REG_POS)
#define __UR0_TX_REG_GET()						M_REG_GETBYTE(UR0_TX_REG_REG, UR0_TX_REG_POS)
#define __UR0_TX_REG_SET(SET)					M_REG_SETBYTE(UR0_TX_REG_REG, UR0_TX_REG_POS, SET)
#define __UR0_TX_REG_GET_SHIFT()				M_REG_GETBYTE_SHIFT(UR0_TX_REG_REG, UR0_TX_REG_POS)
#define __UR0_TX_REG_SET_SHIFT(POS_SET)			M_REG_SETBYTE_SHIFT(UR0_TX_REG_REG, UR0_TX_REG_POS, POS_SET)
/**@}*/ /*** end of group uart_reg_ur0_tx_reg */

/** 
 * @addtogroup	uart_reg_ur0_rx_reg	reg: UR0_RX_REG 
 * @{
 */
//UR0_RX_REG
//RX_REG[7:0]
#define UR0_RX_REG_REG							UR0_RX_REG
#define UR0_RX_REG_POS							(0)
#define UR0_RX_REG_VAL
#define UR0_RX_REG_MASK							(0xFF<< UR0_RX_REG_POS)
#define __UR0_RX_REG_GET()						M_REG_GETBYTE(UR0_RX_REG_REG, UR0_RX_REG_POS)
#define __UR0_RX_REG_SET(SET)					M_REG_SETBYTE(UR0_RX_REG_REG, UR0_RX_REG_POS, SET)
#define __UR0_RX_REG_GET_SHIFT()				M_REG_GETBYTE_SHIFT(UR0_RX_REG_REG, UR0_RX_REG_POS)
#define __UR0_RX_REG_SET_SHIFT(POS_SET)			M_REG_SETBYTE_SHIFT(UR0_RX_REG_REG, UR0_RX_REG_POS, POS_SET)
/**@}*/ /*** end of group uart_reg_ur0_rx_reg */

/** 
 * @addtogroup	uart_reg_ur0_st	reg: UR0_ST 
 * @{
 */
//UR0_ST
//UR_TINV
#define UR0_UR_TINV_REG							UR0_ST
#define UR0_UR_TINV_POS							(7)
#define UR0_UR_TINV_BITS						C_REG_BITS1
#define UR0_UR_TINV_DIS							(0x00<< UR0_UR_TINV_POS)
#define UR0_UR_TINV_EN							(0x01<< UR0_UR_TINV_POS)
#define UR0_UR_TINV_MASK						(UR0_UR_TINV_BITS<< UR0_UR_TINV_POS)
#define __UR0_UR_TINV_GET()						M_REG_GET(UR0_UR_TINV_REG, UR0_UR_TINV_POS, UR0_UR_TINV_BITS)
#define __UR0_UR_TINV_SET(EN)					M_REG_SET(UR0_UR_TINV_REG, UR0_UR_TINV_POS, UR0_UR_TINV_BITS, EN)
#define __UR0_UR_TINV_GET_SHIFT()				M_REG_GET_SHIFT(UR0_UR_TINV_REG, UR0_UR_TINV_POS, UR0_UR_TINV_BITS)
#define __UR0_UR_TINV_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(UR0_UR_TINV_REG, UR0_UR_TINV_POS, UR0_UR_TINV_BITS, POS_EN)

//UR0_ST
//UR_RINV
#define UR0_UR_RINV_REG							UR0_ST
#define UR0_UR_RINV_POS							(6)
#define UR0_UR_RINV_BITS						C_REG_BITS1
#define UR0_UR_RINV_DIS							(0x00<< UR0_UR_RINV_POS)
#define UR0_UR_RINV_EN							(0x01<< UR0_UR_RINV_POS)
#define UR0_UR_RINV_MASK						(UR0_UR_RINV_BITS<< UR0_UR_RINV_POS)
#define __UR0_UR_RINV_GET()						M_REG_GET(UR0_UR_RINV_REG, UR0_UR_RINV_POS, UR0_UR_RINV_BITS)
#define __UR0_UR_RINV_SET(EN)					M_REG_SET(UR0_UR_RINV_REG, UR0_UR_RINV_POS, UR0_UR_RINV_BITS, EN)
#define __UR0_UR_RINV_GET_SHIFT()				M_REG_GET_SHIFT(UR0_UR_RINV_REG, UR0_UR_RINV_POS, UR0_UR_RINV_BITS)
#define __UR0_UR_RINV_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(UR0_UR_RINV_REG, UR0_UR_RINV_POS, UR0_UR_RINV_BITS, POS_EN)

//UR0_ST
//TXFIFO_EMPTY
#define UR0_TXFIFO_EMPTY_REG					UR0_ST
#define UR0_TXFIFO_EMPTY_POS					(4)
#define UR0_TXFIFO_EMPTY_BITS					C_REG_BITS1
#define UR0_TXFIFO_EMPTY_VAL
#define UR0_TXFIFO_EMPTY_MASK					(UR0_TXFIFO_EMPTY_BITS<< UR0_TXFIFO_EMPTY_POS)
#define __UR0_TXFIFO_EMPTY_GET()				M_REG_GET(UR0_TXFIFO_EMPTY_REG, UR0_TXFIFO_EMPTY_POS, UR0_TXFIFO_EMPTY_BITS)
#define __UR0_TXFIFO_EMPTY_GET_SHIFT()			M_REG_GET_SHIFT(UR0_TXFIFO_EMPTY_REG, UR0_TXFIFO_EMPTY_POS, UR0_TXFIFO_EMPTY_BITS)

//UR0_ST
//RX_BUSY
#define UR0_RX_BUSY_REG							UR0_ST
#define UR0_RX_BUSY_POS							(3)
#define UR0_RX_BUSY_BITS						C_REG_BITS1
#define UR0_RX_BUSY_VAL
#define UR0_RX_BUSY_MASK						(UR0_RX_BUSY_BITS<< UR0_RX_BUSY_POS)
#define __UR0_RX_BUSY_GET()						M_REG_GET(UR0_RX_BUSY_REG, UR0_RX_BUSY_POS, UR0_RX_BUSY_BITS)
#define __UR0_RX_BUSY_GET_SHIFT()				M_REG_GET_SHIFT(UR0_RX_BUSY_REG, UR0_RX_BUSY_POS, UR0_RX_BUSY_BITS)

//UR0_ST
//TX_BUSY
#define UR0_TX_BUSY_REG							UR0_ST
#define UR0_TX_BUSY_POS							(2)
#define UR0_TX_BUSY_BITS						C_REG_BITS1
#define UR0_TX_BUSY_UNBUSY						(0x00<< UR0_TX_BUSY_POS)
#define UR0_TX_BUSY_BUSY						(0x01<< UR0_TX_BUSY_POS)
#define UR0_TX_BUSY_MASK						(UR0_TX_BUSY_BITS<< UR0_TX_BUSY_POS)
#define __UR0_TX_BUSY_GET()						M_REG_GET(UR0_TX_BUSY_REG, UR0_TX_BUSY_POS, UR0_TX_BUSY_BITS)
#define __UR0_TX_BUSY_GET_SHIFT()				M_REG_GET_SHIFT(UR0_TX_BUSY_REG, UR0_TX_BUSY_POS, UR0_TX_BUSY_BITS)

//UR0_ST
//RX_OV_ERR
#define UR0_RX_OV_ERR_REG						UR0_ST
#define UR0_RX_OV_ERR_POS						(1)
#define UR0_RX_OV_ERR_BITS						C_REG_BITS1
#define UR0_RX_OV_ERR_VAL
#define UR0_RX_OV_ERR_MASK						(UR0_RX_OV_ERR_BITS<< UR0_RX_OV_ERR_POS)
#define __UR0_RX_OV_ERR_GET()					M_REG_GET(UR0_RX_OV_ERR_REG, UR0_RX_OV_ERR_POS, UR0_RX_OV_ERR_BITS)
#define __UR0_RX_OV_ERR_GET_SHIFT()				M_REG_GET_SHIFT(UR0_RX_OV_ERR_REG, UR0_RX_OV_ERR_POS, UR0_RX_OV_ERR_BITS)

//UR0_ST
//STOP_ERR
#define UR0_STOP_ERR_REG						UR0_ST
#define UR0_STOP_ERR_POS						(0)
#define UR0_STOP_ERR_BITS						C_REG_BITS1
#define UR0_STOP_ERR_VAL
#define UR0_STOP_ERR_MASK						(UR0_STOP_ERR_POS<< UR0_STOP_ERR_POS)
#define __UR0_STOP_ERR_GET()					M_REG_GET(UR0_STOP_ERR_REG, UR0_STOP_ERR_POS, UR0_STOP_ERR_POS)
#define __UR0_STOP_ERR_GET_SHIFT()				M_REG_GET_SHIFT(UR0_STOP_ERR_REG, UR0_STOP_ERR_POS, UR0_STOP_ERR_POS)
/**@}*/ /*** end of group uart_reg_ur0_st */

/** 
 * @addtogroup	uart_reg_ur0_intf	reg: UR0_INTF 
 * @{
 */
//UR0_INTF
//UR0ERRIF
#define UR0_UR0ERRIF_REG						UR0_INTF
#define UR0_UR0ERRIF_POS						(4)
#define UR0_UR0ERRIF_BITS						C_REG_BITS1
#define UR0_UR0ERRIF_VAL
#define UR0_UR0ERRIF_MASK						(UR0_UR0ERRIF_BITS<< UR0_UR0ERRIF_POS)
#define __UR0_UR0ERRIF_GET()					M_REG_GET(UR0_UR0ERRIF_REG, UR0_UR0ERRIF_POS, UR0_UR0ERRIF_BITS)
#define __UR0_UR0ERRIF_GET_SHIFT()				M_REG_GET_SHIFT(UR0_UR0ERRIF_REG, UR0_UR0ERRIF_POS, UR0_UR0ERRIF_BITS)

//UR0_INTF
//UR0_RHIF
#define UR0_UR0_RHIF_REG						UR0_INTF
#define UR0_UR0_RHIF_POS						(3)
#define UR0_UR0_RHIF_BITS						C_REG_BITS1
#define UR0_UR0_RHIF_VAL
#define UR0_UR0_RHIF_MASK						(UR0_UR0_RHIF_BITS<< UR0_UR0_RHIF_POS)
#define __UR0_UR0_RHIF_GET()					M_REG_GET(UR0_UR0_RHIF_REG, UR0_UR0_RHIF_POS, UR0_UR0_RHIF_BITS)
#define __UR0_UR0_RHIF_GET_SHIFT()				M_REG_GET_SHIFT(UR0_UR0_RHIF_REG, UR0_UR0_RHIF_POS, UR0_UR0_RHIF_BITS)

//UR0_INTF
//UR0_RNIF
#define UR0_UR0_RNIF_REG						UR0_INTF
#define UR0_UR0_RNIF_POS						(2)
#define UR0_UR0_RNIF_BITS						C_REG_BITS1
#define UR0_UR0_RNIF_VAL
#define UR0_UR0_RNIF_MASK						(UR0_UR0_RNIF_BITS<< UR0_UR0_RNIF_POS)
#define __UR0_UR0_RNIF_GET()					M_REG_GET(UR0_UR0_RNIF_REG, UR0_UR0_RNIF_POS, UR0_UR0_RNIF_BITS)
#define __UR0_UR0_RNIF_GET_SHIFT()				M_REG_GET_SHIFT(UR0_UR0_RNIF_REG, UR0_UR0_RNIF_POS, UR0_UR0_RNIF_BITS)

//UR0_INTF
//UR0WK_IF
#define UR0_UR0WK_IF_REG						UR0_INTF
#define UR0_UR0WK_IF_POS						(1)
#define UR0_UR0WK_IF_BITS						C_REG_BITS1
#define UR0_UR0WK_IF_VAL
#define UR0_UR0WK_IF_MASK						(UR0_UR0WK_IF_BITS<< UR0_UR0WK_IF_POS)
#define __UR0_UR0WK_IF_GET()					M_REG_GET(UR0_UR0WK_IF_REG, UR0_UR0WK_IF_POS, UR0_UR0WK_IF_BITS)
#define __UR0_UR0WK_IF_GET_SHIFT()				M_REG_GET_SHIFT(UR0_UR0WK_IF_REG, UR0_UR0WK_IF_POS, UR0_UR0WK_IF_BITS)

//UR0_INTF
//UR0_TEIF
#define UR0_UR0_TEIF_REG						UR0_INTF
#define UR0_UR0_TEIF_POS						(0)
#define UR0_UR0_TEIF_BITS						C_REG_BITS1
#define UR0_UR0_TEIF_VAL
#define UR0_UR0_TEIF_MASK						(UR0_UR0_TEIF_BITS<< UR0_UR0_TEIF_POS)
#define __UR0_UR0_TEIF_GET()					M_REG_GET(UR0_UR0_TEIF_REG, UR0_UR0_TEIF_POS, UR0_UR0_TEIF_BITS)
#define __UR0_UR0_TEIF_GET_SHIFT()				M_REG_GET_SHIFT(UR0_UR0_TEIF_REG, UR0_UR0_TEIF_POS, UR0_UR0_TEIF_BITS)
/**@}*/ /*** end of group uart_reg_ur0_intf */

/** 
 * @addtogroup	uart_reg_ur0_inte	reg: UR0_INTE 
 * @{
 */
//UR0_INTE
//UR0ERRIE
#define UR0_UR0ERRIE_REG						UR0_INTE
#define UR0_UR0ERRIE_POS						(4)
#define UR0_UR0ERRIE_BITS						C_REG_BITS1
#define UR0_UR0ERRIE_DIS						(0x00<< UR0_UR0ERRIE_POS)
#define UR0_UR0ERRIE_EN							(0x01<< UR0_UR0ERRIE_POS)
#define UR0_UR0ERRIE_MASK						(UR0_UR0ERRIE_BITS<< UR0_UR0ERRIE_POS)
#define __UR0_UR0ERRIE_GET()					M_REG_GET(UR0_UR0ERRIE_REG, UR0_UR0ERRIE_POS, UR0_UR0ERRIE_BITS)
#define __UR0_UR0ERRIE_SET(EN)					M_REG_SET(UR0_UR0ERRIE_REG, UR0_UR0ERRIE_POS, UR0_UR0ERRIE_BITS, EN)
#define __UR0_UR0ERRIE_GET_SHIFT()				M_REG_GET_SHIFT(UR0_UR0ERRIE_REG, UR0_UR0ERRIE_POS, UR0_UR0ERRIE_BITS)
#define __UR0_UR0ERRIE_SET_SHIFT(POS_EN)		M_REG_SET_SHIFT(UR0_UR0ERRIE_REG, UR0_UR0ERRIE_POS, UR0_UR0ERRIE_BITS, POS_EN)

//UR0_INTE
//UR0_RHIE
#define UR0_UR0_RHIE_REG						UR0_INTE
#define UR0_UR0_RHIE_POS						(3)
#define UR0_UR0_RHIE_BITS						C_REG_BITS1
#define UR0_UR0_RHIE_DIS						(0x00<< UR0_UR0_RHIE_POS)
#define UR0_UR0_RHIE_EN							(0x01<< UR0_UR0_RHIE_POS)
#define UR0_UR0_RHIE_MASK						(UR0_UR0_RHIE_BITS<< UR0_UR0_RHIE_POS)
#define __UR0_UR0_RHIE_GET()					M_REG_GET(UR0_UR0_RHIE_REG, UR0_UR0_RHIE_POS, UR0_UR0_RHIE_BITS)
#define __UR0_UR0_RHIE_SET(EN)					M_REG_SET(UR0_UR0_RHIE_REG, UR0_UR0_RHIE_POS, UR0_UR0_RHIE_BITS, EN)
#define __UR0_UR0_RHIE_GET_SHIFT()				M_REG_GET_SHIFT(UR0_UR0_RHIE_REG, UR0_UR0_RHIE_POS, UR0_UR0_RHIE_BITS)
#define __UR0_UR0_RHIE_SET_SHIFT(POS_EN)		M_REG_SET_SHIFT(UR0_UR0_RHIE_REG, UR0_UR0_RHIE_POS, UR0_UR0_RHIE_BITS, POS_EN)

//UR0_INTE
//UR0_RNIE
#define UR0_UR0_RNIE_REG						UR0_INTE
#define UR0_UR0_RNIE_POS						(2)
#define UR0_UR0_RNIE_BITS						C_REG_BITS1
#define UR0_UR0_RNIE_DIS						(0x00<< UR0_UR0_RNIE_POS)
#define UR0_UR0_RNIE_EN							(0x01<< UR0_UR0_RNIE_POS)
#define UR0_UR0_RNIE_MASK						(UR0_UR0_RNIE_BITS<< UR0_UR0_RNIE_POS)
#define __UR0_UR0_RNIE_GET()					M_REG_GET(UR0_UR0_RNIE_REG, UR0_UR0_RNIE_POS, UR0_UR0_RNIE_BITS)
#define __UR0_UR0_RNIE_SET(EN)					M_REG_SET(UR0_UR0_RNIE_REG, UR0_UR0_RNIE_POS, UR0_UR0_RNIE_BITS, EN)
#define __UR0_UR0_RNIE_GET_SHIFT()				M_REG_GET_SHIFT(UR0_UR0_RNIE_REG, UR0_UR0_RNIE_POS, UR0_UR0_RNIE_BITS)
#define __UR0_UR0_RNIE_SET_SHIFT(POS_EN)		M_REG_SET_SHIFT(UR0_UR0_RNIE_REG, UR0_UR0_RNIE_POS, UR0_UR0_RNIE_BITS, POS_EN)

//UR0_INTE
//UR0WK_IE
#define UR0_UR0WK_IE_REG						UR0_INTE
#define UR0_UR0WK_IE_POS						(1)
#define UR0_UR0WK_IE_BITS						C_REG_BITS1
#define UR0_UR0WK_IE_DIS						(0x00<< UR0_UR0WK_IE_POS)
#define UR0_UR0WK_IE_EN							(0x01<< UR0_UR0WK_IE_POS)
#define UR0_UR0WK_IE_MASK						(UR0_UR0WK_IE_BITS<< UR0_UR0WK_IE_POS)
#define __UR0_UR0WK_IE_GET()					M_REG_GET(UR0_UR0WK_IE_REG, UR0_UR0WK_IE_POS, UR0_UR0WK_IE_BITS)
#define __UR0_UR0WK_IE_SET(EN)					M_REG_SET(UR0_UR0WK_IE_REG, UR0_UR0WK_IE_POS, UR0_UR0WK_IE_BITS, EN)
#define __UR0_UR0WK_IE_GET_SHIFT()				M_REG_GET_SHIFT(UR0_UR0WK_IE_REG, UR0_UR0WK_IE_POS, UR0_UR0WK_IE_BITS)
#define __UR0_UR0WK_IE_SET_SHIFT(POS_EN)		M_REG_SET_SHIFT(UR0_UR0WK_IE_REG, UR0_UR0WK_IE_POS, UR0_UR0WK_IE_BITS, POS_EN)

//UR0_INTE
//UR0_TEIE
#define UR0_UR0_TEIE_REG						UR0_INTE
#define UR0_UR0_TEIE_POS						(0)
#define UR0_UR0_TEIE_BITS						C_REG_BITS1
#define UR0_UR0_TEIE_DIS						(0x00<< UR0_UR0_TEIE_POS)
#define UR0_UR0_TEIE_EN							(0x01<< UR0_UR0_TEIE_POS)
#define UR0_UR0_TEIE_MASK						(UR0_UR0_TEIE_BITS<< UR0_UR0_TEIE_POS)
#define __UR0_UR0_TEIE_GET()					M_REG_GET(UR0_UR0_TEIE_REG, UR0_UR0_TEIE_POS, UR0_UR0_TEIE_BITS)
#define __UR0_UR0_TEIE_SET(EN)					M_REG_SET(UR0_UR0_TEIE_REG, UR0_UR0_TEIE_POS, UR0_UR0_TEIE_BITS, EN)
#define __UR0_UR0_TEIE_GET_SHIFT()				M_REG_GET_SHIFT(UR0_UR0_TEIE_REG, UR0_UR0_TEIE_POS, UR0_UR0_TEIE_BITS)
#define __UR0_UR0_TEIE_SET_SHIFT(POS_EN)		M_REG_SET_SHIFT(UR0_UR0_TEIE_REG, UR0_UR0_TEIE_POS, UR0_UR0_TEIE_BITS, POS_EN)
/**@}*/ /*** end of group uart_reg_ur0_inte */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup csu39fx10_sdk_chip_driver_uart_cfg	uart_config
 * @{
 */
 
/** 
 * @name uart0 config
 * @{
 */
/**
 * @details <b>CFG_PORT_IO_TX</b>
 * - <b>Features: </b> uart0 port gpio pinmux configuration
 * - <b>Param: </b>
 * | config		| Descriptions		|
 * | :----:		| :----:			|
 * | GPIO_PT31	| pt31				|
 * | GPIO_PT33	| pt33				|
 * | GPIO_PT35	| pt35				|
 */
//#define CFG_PORT_IO_TX					GPIO_PT33
#define CFG_PORT_IO_TX					GPIO_PT35
//#define CFG_PORT_IO_TX					GPIO_PT31

/**
 * @details <b>CFG_PORT_IO_RX</b>
 * - <b>Features: </b> uart0 port gpio pinmux configuration
 * - <b>Param: </b>
 * | config		| Descriptions		|
 * | :----:		| :----:			|
 * | GPIO_PT32	| pt32				|
 * | GPIO_PT34	| pt34				|
 * | GPIO_PT36	| pt36				|
 */
#define CFG_PORT_IO_RX					GPIO_PT36

/**
 * @details <b>CFG_AUTO_BAUDRATE</b>
 * - <b>Features: </b> uart0 auto baudrate enable configuration
 * - <b>Param: </b>
 * | config	| Descriptions					|
 * | :----:	| :----:						|
 * | 0*		| disable uart auto baudrate	|
 * | 1		| enable uart auto baudrate		|
 */
#define	CFG_AUTO_BAUDRATE				(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_UART_BAUDRATE</b>
 * - <b>Features: </b> uart0 baudrate configuration
 * - <b>Param: </b>
 * | config	| Descriptions					|
 * | :----:	| :----:						|
 * | 9600	| baudrate 9600					|
 * | ....	| baudrate ....					|
 * | 115200	| baudrate 115200				|
 */
//#define	CFG_UART_BAUDRATE				115200	///< <= 115200
#define	CFG_UART_BAUDRATE				9600	///< <= 115200
//#define	CFG_UART_BAUDRATE				38400	///< <= 115200
/**
 * @details <b>CFG_UR0_TX9_EN</b>
 * - <b>Features: </b> uart0 tx 9bit enable configuration
 * - <b>Param: </b>
 * | config	| Descriptions			|
 * | :----:	| :----:				|
 * | 0*		| disable uart tx 9bit	|
 * | 1		| enable uart tx 9bit	|
 */
#define CFG_UR0_TX9_EN					(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_UR0_RX9_EN</b>
 * - <b>Features: </b> uart0 rx 9bit enable configuration
 * - <b>Param: </b>
 * | config	| Descriptions			|
 * | :----:	| :----:				|
 * | 0*		| disable uart rx 9bit	|
 * | 1		| enable uart rx 9bit	|
 */
#define CFG_UR0_RX9_EN					(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_UR0_TX_EN</b>
 * - <b>Features: </b> uart0 tx enable configuration
 * - <b>Param: </b>
 * | config	| Descriptions		|
 * | :----:	| :----:			|
 * | 0*		| disable uart tx	|
 * | 1		| enable uart tx	|
 */
#define CFG_UR0_TX_EN					(1)     ///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_UR0_RX_EN</b>
 * - <b>Features: </b> uart0 rx enable configuration
 * - <b>Param: </b>
 * | config	| Descriptions		|
 * | :----:	| :----:			|
 * | 0*		| disable uart rx	|
 * | 1		| enable uart rx	|
 */
#define CFG_UR0_RX_EN					(1)     ///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_UART0_EN</b>
 * - <b>Features: </b> uart0 enable configuration
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| disable uart	|
 * | 1		| enable uart	|
 */
#define CFG_UART0_EN					(1)     ///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_UR0_UR_TINV</b>
 * - <b>Features: </b> uart0 output signal reverse configuration
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| disable		|
 * | 1		| enable		|
 */
#define CFG_UR0_UR_TINV					(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_UR0_UR_RINV</b>
 * - <b>Features: </b> uart0 input signal reverse configuration
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| disable		|
 * | 1		| enable		|
 */
#define CFG_UR0_UR_RINV					(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_UR0_UR0ERRIE</b>
 * - <b>Features: </b> uart0 receive error interrupt configuration
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| disable		|
 * | 1		| enable		|
 */
#define CFG_UR0_UR0ERRIE				(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_UR0_UR0_RHIE</b>
 * - <b>Features: </b> uart0 receive fifo half full interrupt configuration
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| disable		|
 * | 1		| enable		|
 */
#define CFG_UR0_UR0_RHIE				(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_UR0_UR0_RNIE</b>
 * - <b>Features: </b> uart0 receive fifo not empty interrupt configuration
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| disable		|
 * | 1		| enable		|
 */
#define CFG_UR0_UR0_RNIE				(1)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_UR0_UR0WK_IE</b>
 * - <b>Features: </b> uart0 receive wakeup interrupt configuration
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| disable		|
 * | 1		| enable		|
 */
#define CFG_UR0_UR0WK_IE				(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_UR0_UR0_TEIE</b>
 * - <b>Features: </b> uart0 send fifo empty interrupt configuration
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| disable		|
 * | 1		| enable		|
 */
#define CFG_UR0_UR0_TEIE				(0)		///< 0-> disable, 1-> enable
/**@}*/ /*** end of name uart0 config */
/**@}*/ /*** end of group csu39fx10_sdk_chip_driver_uart_cfg */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup uart_compile	attention: users do not need to care
 * @attention <b>users do not need to care</b>
 * @{
 */
/** 
 * @name uart0_compile_port
 * @{
 */
#if(CFG_PORT_IO_TX== GPIO_PT31)
	#define PORT_UR0_TX_PORTX			gpio_3
	#define PORT_UR0_TX_PINX			pin_1
#elif(CFG_PORT_IO_TX== GPIO_PT33)
	#define PORT_UR0_TX_PORTX			gpio_3
	#define PORT_UR0_TX_PINX			pin_3
#elif(CFG_PORT_IO_TX== GPIO_PT35)
	#define PORT_UR0_TX_PORTX			gpio_3
	#define PORT_UR0_TX_PINX			pin_5
#else
	// #define PORT_UR0_TX_PORTX			gpio_3
	// #define PORT_UR0_TX_PINX			pin_1
	#define PORT_UR0_TX_PORTX			gpio_3
	#define PORT_UR0_TX_PINX			pin_5
#endif

#if(CFG_PORT_IO_RX== GPIO_PT32)
	#define PORT_UR0_RX_PORTX			gpio_3
	#define PORT_UR0_RX_PINX			pin_2
#elif(CFG_PORT_IO_RX== GPIO_PT34)
	#define PORT_UR0_RX_PORTX			gpio_3
	#define PORT_UR0_RX_PINX			pin_4
#elif(CFG_PORT_IO_RX== GPIO_PT36)
	#define PORT_UR0_RX_PORTX			gpio_3
	#define PORT_UR0_RX_PINX			pin_6
#else
	// #define PORT_UR0_RX_PORTX			gpio_3
	// #define PORT_UR0_RX_PINX			pin_2
	#define PORT_UR0_RX_PORTX			gpio_3
	#define PORT_UR0_RX_PINX			pin_6
#endif
/**@}*/ /*** end of name uart0_compile_port */

/** 
 * @name uart0_compile_reg_ur0_cr1
 * @{
 */
#if(CFG_UR0_TX9_EN!= 0)
	#define PRE_UR0_TX9_EN				1
#else
	#define PRE_UR0_TX9_EN				0
#endif

#if(CFG_UR0_RX9_EN!= 0)
	#define PRE_UR0_RX9_EN				1
#else
	#define PRE_UR0_RX9_EN				0
#endif

#if(CFG_UR0_RX_EN!= 0)
	#define PRE_UR0_RX_EN				1
#else
	#define PRE_UR0_RX_EN				0
#endif

#if(CFG_UR0_TX_EN!= 0)
	#define PRE_UR0_TX_EN				1
#else
	#define PRE_UR0_TX_EN				0
#endif

#if(CFG_UART0_EN!= 0)
	#define PRE_UART0_EN				1
#else
	#define PRE_UART0_EN				0
#endif
/**@}*/ /*** end of name uart0_compile_reg_ur0_cr1 */
 
/** 
 * @name uart0_compile_reg_ur0_brr0
 * @{
 */
#define PRE_UR0_BRR0					(uint8_t)(C_CLK_UR0CLK/ CFG_UART_BAUDRATE)
/**@}*/ /*** end of name uart0_compile_reg_ur0_brr0 */
 
/** 
 * @name uart0_compile_reg_ur0_brr1
 * @{
 */
#if(CFG_AUTO_BAUDRATE!= 0)
	#define	PRE_AUTO_BR					1
#else
	#define	PRE_AUTO_BR					0
#endif

#define PRE_UR0_BRR1					(uint8_t)(((float)(C_CLK_UR0CLK/ (float)CFG_UART_BAUDRATE)- (uint8_t)(C_CLK_UR0CLK/ CFG_UART_BAUDRATE)+ 0.05)* 10)

#if(CFG_UR0_UR_TINV!= 0)
	#define PRE_UR0_UR_TINV				1
#else
	#define PRE_UR0_UR_TINV				0
#endif

#if(CFG_UR0_UR_RINV!= 0)
	#define PRE_UR0_UR_RINV				1
#else
	#define PRE_UR0_UR_RINV				0
#endif
/**@}*/ /*** end of name uart0_compile_reg_ur0_brr1 */

/** 
 * @name uart0_compile_reg_ur0_intf
 * @{
 */
#define PRE_UR0_INTF					0x00
/**@}*/ /*** end of name uart0_compile_reg_ur0_intf */

/** 
 * @name uart0_compile_reg_ur0_inte
 * @{
 */
#if(CFG_UR0_UR0ERRIE!= 0)
	#define PRE_UR0_UR0ERRIE			1
#else
	#define PRE_UR0_UR0ERRIE			0
#endif

#if(CFG_UR0_UR0_RHIE!= 0)
	#define PRE_UR0_UR0_RHIE			1
#else
	#define PRE_UR0_UR0_RHIE			0
#endif

#if(CFG_UR0_UR0_RNIE!= 0)
	#define PRE_UR0_UR0_RNIE			1
#else
	#define PRE_UR0_UR0_RNIE			0
#endif

#if(CFG_UR0_UR0WK_IE!= 0)
	#define PRE_UR0_UR0WK_IE			1
#else
	#define PRE_UR0_UR0WK_IE			0
#endif

#if(CFG_UR0_UR0_TEIE!= 0)
	#define PRE_UR0_UR0_TEIE			1
#else
	#define PRE_UR0_UR0_TEIE			0
#endif
/**@}*/ /*** end of name uart0_compile_reg_ur0_inte */

/** 
 * @name uart0_compile_warning
 * @attention <b>compile warning message</b>
 * @{
 */
#if((CFG_PORT_IO_TX!= GPIO_PT31)&& 		\
	(CFG_PORT_IO_TX!= GPIO_PT33)&& 		\
	(CFG_PORT_IO_TX!= GPIO_PT35))
	#warning "Warning: CFG_PORT_IO_TX define error, will be redefined, CFG_PORT_IO_TX!"
#endif

#if((CFG_PORT_IO_RX!= GPIO_PT32)&& 		\
	(CFG_PORT_IO_RX!= GPIO_PT34)&& 		\
	(CFG_PORT_IO_RX!= GPIO_PT36))
	#warning "Warning: CFG_PORT_IO_RX define error, will be redefined, CFG_PORT_IO_RX!"
#endif

#define WARNING_UR0_BRR0				(C_CLK_UR0CLK/ CFG_UART_BAUDRATE)
#if(WARNING_UR0_BRR0< 8)
	#warning "Warning: CFG_SYS_CLK_UART_DIV define error, will be redefined, CFG_SYS_CLK_UART_DIV- 1!"
#endif
#if(WARNING_UR0_BRR0> 100)
	#warning "Warning: CFG_SYS_CLK_UART_DIV define error, will be redefined, CFG_SYS_CLK_UART_DIV+ 1!"
#endif
/**@}*/ /*** end of name uart0_compile_warning */
/**@}*/ /*** end of group uart_compile */
/*******************************************************************************/




/******************************** dividing line ********************************/
/**
 * @addtogroup uart0_reg_default	reg_default_value
 * @{
 */
/**
 * @name uart0_reg
 * @par 示例
 * @code
 *		void test( void )
 *		{
 *			//gpio cfg
 *			gpio_config_t		gpio_cfg;
 *			gpio_cfg.gpio_portx= PORT_UR0_RX_PORTX;
 *			gpio_cfg.gpio_pinx= PORT_UR0_RX_PINX;
 *			gpio_cfg.gpio_pinmux= pinmux_func2;
 *			gpio_cfg.gpio_dir= dir_output;
 *			gpio_cfg.gpio_mode= mode_pp;
 *			gpio_cfg.gpio_pull= no_pull;
 *			gpio_init(&gpio_cfg);
 *			
 *			gpio_cfg.gpio_portx= PORT_UR0_TX_PORTX;
 *			gpio_cfg.gpio_pinx= PORT_UR0_TX_PINX;
 *			gpio_cfg.gpio_pinmux= pinmux_func2;
 *			gpio_cfg.gpio_dir= dir_output;
 *			gpio_cfg.gpio_mode= mode_pp;
 *			gpio_cfg.gpio_pull= no_pull;
 *			gpio_init(&gpio_cfg);
 *			
 *			UR0_CR1= PRE_UR0_CR1_DEFAULT;
 *			UR0_BRR0= PRE_UR0_BRR0_DEFAULT;
 *			UR0_BRR1= PRE_UR0_BRR1_DEFAULT;
 *			UR0_ST= PRE_UR0_ST_DEFAULT;
 *			UR0_INTE= PRE_UR0_INTE_DEFAULT;
 *			UR0_INTF= PRE_UR0_INTF_DEFAULT;
 *			UR0_TX_REG= 0x00;
 *			
 *		#if(PRE_UR0_INTE_DEFAULT!= 0)
 *			GIE= true;
 *		#endif
 *		}
 * @endcode
 * @{
 */
#define PRE_UR0_CR1_DEFAULT				(((PRE_UR0_TX9_EN<< UR0_TX9_EN_POS)& UR0_TX9_EN_MASK)|				\
											((PRE_UR0_RX9_EN<< UR0_RX9_EN_POS)& UR0_RX9_EN_MASK)|			\
											((PRE_UR0_RX_EN<< UR0_RX_EN_POS)& UR0_RX_EN_MASK)|				\
											((PRE_UR0_TX_EN<< UR0_TX_EN_POS)& UR0_TX_EN_MASK)|				\
											((PRE_UART0_EN<< UR0_UART0_EN_POS)& UR0_UART0_EN_MASK))
#define PRE_UR0_BRR0_DEFAULT			((PRE_UR0_BRR0<< UR0_BRR0_POS)& UR0_BRR0_MASK)
#define PRE_UR0_BRR1_DEFAULT			(((PRE_AUTO_BR<< UR0_AUTO_BR_POS)& UR0_AUTO_BR_MASK)|				\
											((PRE_UR0_BRR1<< UR0_BRR1_POS)& UR0_BRR1_MASK))	
#define PRE_UR0_ST_DEFAULT				(((PRE_UR0_UR_TINV<< UR0_UR_TINV_POS)& UR0_UR_TINV_MASK)|			\
											((PRE_UR0_UR_RINV<< UR0_UR_RINV_POS)& UR0_UR_RINV_MASK))
#define PRE_UR0_INTF_DEFAULT			PRE_UR0_INTF
#define PRE_UR0_INTE_DEFAULT			(((PRE_UR0_UR0ERRIE<< UR0_UR0ERRIE_POS)& UR0_UR0ERRIE_MASK)|		\
											((PRE_UR0_UR0_RHIE<< UR0_UR0_RHIE_POS)& UR0_UR0_RHIE_MASK)|		\
											((PRE_UR0_UR0_RNIE<< UR0_UR0_RNIE_POS)& UR0_UR0_RNIE_MASK)|		\
											((PRE_UR0_UR0WK_IE<< UR0_UR0WK_IE_POS)& UR0_UR0WK_IE_MASK)|		\
											((PRE_UR0_UR0_TEIE<< UR0_UR0_TEIE_POS)& UR0_UR0_TEIE_MASK))
/**@}*/ /*** end of name uart0_reg */
/**@}*/ /*** end of group uart0_reg_default */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup uart_api	api
 * @{
 */
/**
 * @name uart0_api
 * @{
 */
/**
 * @brief 	<b>Description:</b> uart0 initialization.
 * @details <b>Function prototype:</b> void uart_init(void);
 * @param[in]  null	.
 * @param[out] null.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			uart_init();
 *		}
 * @endcode
 */
void uart_init(void);
void uart_disable(void);

/**
 * @brief 	<b>Description:</b> uart0 send one byte.
 * @details <b>Function prototype:</b> void uart_putchar(uint8_t data);
 * @param[in]  uint8_t data  send data.
 * @param[out] null.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			uart_putchar(0xA5);
 *		}
 * @endcode
 */
void uart_putchar(uint8_t data);

/**
 * @brief 	<b>Description:</b> uart0 receive one byte.
 * @details <b>Function prototype:</b> uint8_t uart_getchar(void);
 * @param[in]  null.
 * @param[out] null.
 * 
 * @return  uint8_t data  receive data.
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			uint8_t re_data;
 * 			re_data= uart_getchar();
 *		}
 * @endcode
 */
uint8_t uart_getchar(void);

/**@}*/ /*** end of name uart0_api */
/**@}*/ /*** end of group uart_api */
/**@}*/ /*** end of group csu39fx10_sdk_chip_driver_uart */
/**@}*/ /*** end of group csu39fx10_sdk_chip_driver */
/**@}*/ /*** end of group csu39fx10_sdk_chip */
/*******************************************************************************/




#ifdef __cplusplus
}
#endif

#endif  //__DRV_UART_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/
