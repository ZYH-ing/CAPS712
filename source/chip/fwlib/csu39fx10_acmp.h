/***************************************************************************
 * @file     csu39fx10_acmp.h
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
 *       system_csu39fx10.h
 * @attention
 *  硬件平台:	\n
 *  SDK版本： 	.0.0
 * 
 * @par 修改日志:
 * <table>
 * <tr><th>Date        <th>Version  <th>Author    <th>Description
 * <tr><td>2018/08/17  <td>1.0      <td>0531	  <td>创建初始版本
 * </table>
 *
 *****************************************************************************/

#ifndef __CSU39FX10_ACMP_H__
#define __CSU39FX10_ACMP_H__

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
 * @addtogroup csu39fx10_sdk_chip_fwlib	fwlib 
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_fwlib_acmp	acmp 
 * @{
 */

/** 
 * @addtogroup	acmp_reg_acmp0cr1	reg: ACMP0CR1 
 * @{
 */
//ACMP0CR1
//CAL_CNT0[5:0]
#define ACMP_CAL_CNT0_REG						ACMP0CR1
#define ACMP_CAL_CNT0_POS						(2)
#define ACMP_CAL_CNT0_BITS						C_REG_BITS5
#define ACMP_CAL_CNT0_VAL
#define ACMP_CAL_CNT0_MASK						(ACMP_CAL_CNT0_BITS<< ACMP_CAL_CNT0_POS)
/** 
 * @name acmp0_reg_acmp0cr1
 * @{
 */
#define __ACMP_CAL_CNT0_GET()					M_REG_GET(ACMP_CAL_CNT0_REG, ACMP_CAL_CNT0_POS, ACMP_CAL_CNT0_BITS)
#define __ACMP_CAL_CNT0_SET(SET)				M_REG_SET(ACMP_CAL_CNT0_REG, ACMP_CAL_CNT0_POS, ACMP_CAL_CNT0_BITS, SET)
#define __ACMP_CAL_CNT0_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_CAL_CNT0_REG, ACMP_CAL_CNT0_POS, ACMP_CAL_CNT0_BITS)
#define __ACMP_CAL_CNT0_SET_SHIFT(POS_SET)		M_REG_SET_SHIFT(ACMP_CAL_CNT0_REG, ACMP_CAL_CNT0_POS, ACMP_CAL_CNT0_BITS, POS_SET)
/**@}*/ /*** end of group acmp_reg_acmp0cr1 */

//CAL_FT0
#define ACMP_CAL_FT0_REG						ACMP0CR1
#define ACMP_CAL_FT0_POS						(1)
#define ACMP_CAL_FT0_BITS						C_REG_BITS1
#define ACMP_CAL_FT0_FAIL						(0x01<< ACMP_CAL_FT0_POS)
#define ACMP_CAL_FT0_SUCCESS					(0x00<< ACMP_CAL_FT0_POS)
#define ACMP_CAL_FT0_MASK						(ACMP_CAL_FT0_BITS<< ACMP_CAL_FT0_POS)
#define __ACMP_CAL_FT0_GET()					M_REG_GET(ACMP_CAL_FT0_REG, ACMP_CAL_FT0_POS, ACMP_CAL_FT0_BITS)
#define __ACMP_CAL_FT0_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_CAL_FT0_REG, ACMP_CAL_FT0_POS, ACMP_CAL_FT0_BITS)

//CALEN0
#define ACMP_CALEN0_REG							ACMP0CR1
#define ACMP_CALEN0_POS							(0)
#define ACMP_CALEN0_BITS						C_REG_BITS1
#define ACMP_CALEN0_FINISH						(0x00<< ACMP_CALEN0_POS)
#define ACMP_CALEN0_EN							(0x01<< ACMP_CALEN0_POS)
#define ACMP_CALEN0_MASK						(ACMP_CALEN0_BITS<< ACMP_CALEN0_POS)
#define __ACMP_CALEN0_GET()						M_REG_GET(ACMP_CALEN0_REG, ACMP_CALEN0_POS, ACMP_CALEN0_BITS)
#define __ACMP_CALEN0_SET(SET)					M_REG_SET(ACMP_CALEN0_REG, ACMP_CALEN0_POS, ACMP_CALEN0_BITS, SET)
#define __ACMP_CALEN0_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_CALEN0_REG, ACMP_CALEN0_POS, ACMP_CALEN0_BITS)
#define __ACMP_CALEN0_SET_SHIFT(POS_SET)		M_REG_SET_SHIFT(ACMP_CALEN0_REG, ACMP_CALEN0_POS, ACMP_CALEN0_BITS, POS_SET)
/**@}*/ /*** end of group acmp_reg_acmp0cr1 */

/** 
 * @addtogroup	acmp_reg_acmp0cr2	reg: ACMP0CR2 
 * @{
 */
//ACMP0CR2
//INSHTEN0[1:0]
#define ACMP_INSHTEN0_REG						ACMP0CR2
#define ACMP_INSHTEN0_POS						(6)
#define ACMP_INSHTEN0_BITS						C_REG_BITS2
#define ACMP_INSHTEN0_DIS						(0x00<< ACMP_INSHTEN0_POS)
#define ACMP_INSHTEN0_EN_MOD1					(0x01<< ACMP_INSHTEN0_POS)
#define ACMP_INSHTEN0_EN_MOD2					(0x02<< ACMP_INSHTEN0_POS)
#define ACMP_INSHTEN0_EN_MOD3					(0x03<< ACMP_INSHTEN0_POS)
#define ACMP_INSHTEN0_MASK						(ACMP_INSHTEN0_BITS<< ACMP_INSHTEN0_POS)
#define __ACMP_INSHTEN0_GET()					M_REG_GET(ACMP_INSHTEN0_REG, ACMP_INSHTEN0_POS, ACMP_INSHTEN0_BITS)
#define __ACMP_INSHTEN0_SET(EN)					M_REG_SET(ACMP_INSHTEN0_REG, ACMP_INSHTEN0_POS, ACMP_INSHTEN0_BITS, EN)
#define __ACMP_INSHTEN0_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_INSHTEN0_REG, ACMP_INSHTEN0_POS, ACMP_INSHTEN0_BITS)
#define __ACMP_INSHTEN0_SET_SHIFT(POS_EN)		M_REG_SET_SHIFT(ACMP_INSHTEN0_REG, ACMP_INSHTEN0_POS, ACMP_INSHTEN0_BITS, POS_EN)

//WEN0
#define ACMP_WEN0_REG							ACMP0CR2
#define ACMP_WEN0_POS							(5)
#define ACMP_WEN0_BITS							C_REG_BITS1
#define ACMP_WEN0_DIS							(0x00<< ACMP_WEN0_POS)
#define ACMP_WEN0_EN							(0x01<< ACMP_WEN0_POS)
#define ACMP_WEN0_MASK							(ACMP_WEN0_BITS<< ACMP_WEN0_POS)
#define __ACMP_WEN0_GET()						M_REG_GET(ACMP_WEN0_REG, ACMP_WEN0_POS, ACMP_WEN0_BITS)
#define __ACMP_WEN0_SET(SET)					M_REG_SET(ACMP_WEN0_REG, ACMP_WEN0_POS, ACMP_WEN0_BITS, SET)
#define __ACMP_WEN0_GET_SHIFT()					M_REG_GET_SHIFT(ACMP_WEN0_REG, ACMP_WEN0_POS, ACMP_WEN0_BITS)
#define __ACMP_WEN0_SET_SHIFT(POS_SET)			M_REG_SET_SHIFT(ACMP_WEN0_REG, ACMP_WEN0_POS, ACMP_WEN0_BITS, POS_SET)

//ACMP0OFT[4:0]
#define ACMP_ACMP0OFT_REG						ACMP0CR2
#define ACMP_ACMP0OFT_POS						(0)
#define ACMP_ACMP0OFT_BITS						C_REG_BITS5
#define ACMP_ACMP0OFT_DIS						(0x00<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_P0P5MV					(0x01<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_P1P0MV					(0x02<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_P1P5MV					(0x03<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_P2P0MV					(0x04<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_P2P5MV					(0x05<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_P3P0MV					(0x06<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_P3P5MV					(0x07<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_P4P0MV					(0x08<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_P4P5MV					(0x09<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_P5P0MV					(0x0A<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_P5P5MV					(0x0B<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_P6P0MV					(0x0C<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_P6P5MV					(0x0D<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_P7P0MV					(0x0E<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_P7P5MV					(0x0F<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_DIS_N						(0x10<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_N0P5MV					(0x11<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_N1P0MV					(0x12<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_N1P5MV					(0x13<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_N2P0MV					(0x14<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_N2P5MV					(0x15<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_N3P0MV					(0x16<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_N3P5MV					(0x17<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_N4P0MV					(0x18<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_N4P5MV					(0x19<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_N5P0MV					(0x1A<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_N5P5MV					(0x1B<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_N6P0MV					(0x1C<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_N6P5MV					(0x1D<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_N7P0MV					(0x1E<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_N7P5MV					(0x1F<< ACMP_ACMP0OFT_POS)
#define ACMP_ACMP0OFT_MASK						(ACMP_ACMP0OFT_BITS<< ACMP_ACMP0OFT_POS)
#define __ACMP_ACMP0OFT_GET()					M_REG_GET(ACMP_ACMP0OFT_REG, ACMP_ACMP0OFT_POS, ACMP_ACMP0OFT_BITS)
#define __ACMP_ACMP0OFT_SET(EN)					M_REG_SET(ACMP_ACMP0OFT_REG, ACMP_ACMP0OFT_POS, ACMP_ACMP0OFT_BITS, EN)
#define __ACMP_ACMP0OFT_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_ACMP0OFT_REG, ACMP_ACMP0OFT_POS, ACMP_ACMP0OFT_BITS)
#define __ACMP_ACMP0OFT_SET_SHIFT(POS_EN)		M_REG_SET_SHIFT(ACMP_ACMP0OFT_REG, ACMP_ACMP0OFT_POS, ACMP_ACMP0OFT_BITS, POS_EN)
/**@}*/ /*** end of group acmp_reg_acmp0cr2 */

/** 
 * @addtogroup	acmp_reg_acmp0cr3	reg: ACMP0CR3 
 * @{
 */

//ACMP0CR3
//ACMP0PS[3:0]
#define ACMP_ACMP0PS_REG						ACMP0CR3
#define ACMP_ACMP0PS_POS						(4)
#define ACMP_ACMP0PS_BITS						C_REG_BITS4
#define ACMP_ACMP0PS_CHL_DPA					(0x00<< ACMP_ACMP0PS_POS)
#define ACMP_ACMP0PS_CHL_DMA					(0x01<< ACMP_ACMP0PS_POS)
#define ACMP_ACMP0PS_CHL_DPB					(0x02<< ACMP_ACMP0PS_POS)
#define ACMP_ACMP0PS_CHL_DMB					(0x03<< ACMP_ACMP0PS_POS)
#define ACMP_ACMP0PS_CHL_INTVREF				(0x04<< ACMP_ACMP0PS_POS)
#define ACMP_ACMP0PS_CHL_CMP0VREF				(0x05<< ACMP_ACMP0PS_POS)
#define ACMP_ACMP0PS_CHL_GND					(0x06<< ACMP_ACMP0PS_POS)
#define ACMP_ACMP0PS_CHL_NC						(0x07<< ACMP_ACMP0PS_POS)
#define ACMP_ACMP0PS_CHL_DPC					(0x08<< ACMP_ACMP0PS_POS)
#define ACMP_ACMP0PS_CHL_DMC					(0x09<< ACMP_ACMP0PS_POS)
#define ACMP_ACMP0PS_CHL_DPD					(0x0A<< ACMP_ACMP0PS_POS)
#define ACMP_ACMP0PS_CHL_DMD					(0x0B<< ACMP_ACMP0PS_POS)
#define ACMP_ACMP0PS_MASK						(ACMP_ACMP0PS_BITS<< ACMP_ACMP0PS_POS)
#define __ACMP_ACMP0PS_GET()					M_REG_GET(ACMP_ACMP0PS_REG, ACMP_ACMP0PS_POS, ACMP_ACMP0PS_BITS)
#define __ACMP_ACMP0PS_SET(CHL)					M_REG_SET(ACMP_ACMP0PS_REG, ACMP_ACMP0PS_POS, ACMP_ACMP0PS_BITS, CHL)
#define __ACMP_ACMP0PS_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_ACMP0PS_REG, ACMP_ACMP0PS_POS, ACMP_ACMP0PS_BITS)
#define __ACMP_ACMP0PS_SET_SHIFT(POS_CHL)		M_REG_SET_SHIFT(ACMP_ACMP0PS_REG, ACMP_ACMP0PS_POS, ACMP_ACMP0PS_BITS, POS_CHL)

//ACMP0O
#define ACMP_ACMP0O_REG							ACMP0CR3
#define ACMP_ACMP0O_POS							(3)
#define ACMP_ACMP0O_BITS						C_REG_BITS1
#define ACMP_ACMP0O_RESET						(0x00<< ACMP_WEN0_POS)
#define ACMP_ACMP0O_SET							(0x01<< ACMP_WEN0_POS)
#define ACMP_ACMP0O_MASK						(ACMP_ACMP0O_BITS<< ACMP_WEN0_POS)
#define __ACMP_ACMP0O_GET()						M_REG_GET(ACMP_ACMP0O_REG, ACMP_WEN0_POS, ACMP_ACMP0O_BITS)
#define __ACMP_ACMP0O_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_ACMP0O_REG, ACMP_WEN0_POS, ACMP_ACMP0O_BITS)

//ACMP0NS[2:0]
#define ACMP_ACMP0NS_REG						ACMP0CR3
#define ACMP_ACMP0NS_POS						(0)
#define ACMP_ACMP0NS_BITS						C_REG_BITS3
#define ACMP_ACMP0NS_CHL_PT30					(0x00<< ACMP_ACMP0NS_POS)
#define ACMP_ACMP0NS_CHL_INTVREF				(0x04<< ACMP_ACMP0NS_POS)
#define ACMP_ACMP0NS_CHL_CMP0VREF				(0x05<< ACMP_ACMP0NS_POS)
#define ACMP_ACMP0NS_MASK						(ACMP_ACMP0NS_BITS<< ACMP_ACMP0NS_POS)
#define __ACMP_ACMP0NS_GET()					M_REG_GET(ACMP_ACMP0NS_REG, ACMP_ACMP0NS_POS, ACMP_ACMP0NS_BITS)
#define __ACMP_ACMP0NS_SET(CHL)					M_REG_SET(ACMP_ACMP0NS_REG, ACMP_ACMP0NS_POS, ACMP_ACMP0NS_BITS, CHL)
#define __ACMP_ACMP0NS_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_ACMP0NS_REG, ACMP_ACMP0NS_POS, ACMP_ACMP0NS_BITS)
#define __ACMP_ACMP0NS_SET_SHIFT(POS_CHL)		M_REG_SET_SHIFT(ACMP_ACMP0NS_REG, ACMP_ACMP0NS_POS, ACMP_ACMP0NS_BITS, POS_CHL)
/**@}*/ /*** end of group acmp_reg_acmp0cr3 */

/** 
 * @addtogroup	acmp_reg_acmp0cr4	reg: ACMP0CR4 
 * @{
 */
//ACMP0CR4
//ACMP0F
#define ACMP_ACMP0F_REG							ACMP0CR4
#define ACMP_ACMP0F_POS							(7)
#define ACMP_ACMP0F_BITS						C_REG_BITS1
#define ACMP_ACMP0F_RESET						(0x00<< ACMP_ACMP0F_POS)
#define ACMP_ACMP0F_SET							(0x01<< ACMP_ACMP0F_POS)
#define ACMP_ACMP0F_CLR							(0x01<< ACMP_ACMP0F_POS)
#define ACMP_ACMP0F_MASK						(ACMP_ACMP0F_BITS<< ACMP_ACMP0F_POS)
#define __ACMP_ACMP0F_GET()						M_REG_GET(ACMP_ACMP0F_REG, ACMP_ACMP0F_POS, ACMP_ACMP0F_BITS)
#define __ACMP_ACMP0F_SET(CLR)					M_REG_SET(ACMP_ACMP0F_REG, ACMP_ACMP0F_POS, ACMP_ACMP0F_BITS, CLR)
#define __ACMP_ACMP0F_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_ACMP0F_REG, ACMP_ACMP0F_POS, ACMP_ACMP0F_BITS)
#define __ACMP_ACMP0F_SET_SHIFT(POS_CLR)		M_REG_SET_SHIFT(ACMP_ACMP0F_REG, ACMP_ACMP0F_POS, ACMP_ACMP0F_BITS, POS_CLR)

//ACMP0OINV
#define ACMP_ACMP0OINV_REG						ACMP0CR4
#define ACMP_ACMP0OINV_POS						(6)
#define ACMP_ACMP0OINV_BITS						C_REG_BITS1
#define ACMP_ACMP0OINV_DIS						(0x00<< ACMP_ACMP0OINV_POS)
#define ACMP_ACMP0OINV_EN						(0x01<< ACMP_ACMP0OINV_POS)
#define ACMP_ACMP0OINV_MASK						(ACMP_ACMP0OINV_BITS<< ACMP_ACMP0OINV_POS)
#define __ACMP_ACMP0OINV_GET()					M_REG_GET(ACMP_ACMP0OINV_REG, ACMP_ACMP0OINV_POS, ACMP_ACMP0OINV_BITS)
#define __ACMP_ACMP0OINV_SET(EN)				M_REG_SET(ACMP_ACMP0OINV_REG, ACMP_ACMP0OINV_POS, ACMP_ACMP0OINV_BITS, EN)
#define __ACMP_ACMP0OINV_GET_SHIFT()			M_REG_GET_SHIFT(ACMP_ACMP0OINV_REG, ACMP_ACMP0OINV_POS, ACMP_ACMP0OINV_BITS)
#define __ACMP_ACMP0OINV_SET_SHIFT(POS_EN)		M_REG_SET_SHIFT(ACMP_ACMP0OINV_REG, ACMP_ACMP0OINV_POS, ACMP_ACMP0OINV_BITS, POS_EN)

//ACMP0OFLTS[2:0]
#define ACMP_ACMP0OFLTS_REG						ACMP0CR4
#define ACMP_ACMP0OFLTS_POS						(3)
#define ACMP_ACMP0OFLTS_BITS					C_REG_BITS3
#define ACMP_ACMP0OFLTS_DIS						(0x00<< ACMP_ACMP0OFLTS_POS)
#define ACMP_ACMP0OFLTS_4XCLK					(0x01<< ACMP_ACMP0OFLTS_POS)
#define ACMP_ACMP0OFLTS_8XCLK					(0x02<< ACMP_ACMP0OFLTS_POS)
#define ACMP_ACMP0OFLTS_16XCLK					(0x03<< ACMP_ACMP0OFLTS_POS)
#define ACMP_ACMP0OFLTS_32XCLK					(0x04<< ACMP_ACMP0OFLTS_POS)
#define ACMP_ACMP0OFLTS_64XCLK					(0x05<< ACMP_ACMP0OFLTS_POS)
#define ACMP_ACMP0OFLTS_128XCLK					(0x06<< ACMP_ACMP0OFLTS_POS)
#define ACMP_ACMP0OFLTS_256XCLK					(0x07<< ACMP_ACMP0OFLTS_POS)
#define ACMP_ACMP0OFLTS_MASK					(ACMP_ACMP0OFLTS_BITS<< ACMP_ACMP0OFLTS_POS)
#define __ACMP_ACMP0OFLTS_GET()					M_REG_GET(ACMP_ACMP0OFLTS_REG, ACMP_ACMP0OFLTS_POS, ACMP_ACMP0OFLTS_BITS)
#define __ACMP_ACMP0OFLTS_SET(SET)				M_REG_SET(ACMP_ACMP0OFLTS_REG, ACMP_ACMP0OFLTS_POS, ACMP_ACMP0OFLTS_BITS, SET)
#define __ACMP_ACMP0OFLTS_GET_SHIFT()			M_REG_GET_SHIFT(ACMP_ACMP0OFLTS_REG, ACMP_ACMP0OFLTS_POS, ACMP_ACMP0OFLTS_BITS)
#define __ACMP_ACMP0OFLTS_SET_SHIFT(POS_SET)	M_REG_SET_SHIFT(ACMP_ACMP0OFLTS_REG, ACMP_ACMP0OFLTS_POS, ACMP_ACMP0OFLTS_BITS, POS_SET)

//HYSEN0
#define ACMP_HYSEN0_REG							ACMP0CR4
#define ACMP_HYSEN0_POS							(2)
#define ACMP_HYSEN0_BITS						C_REG_BITS1
#define ACMP_HYSEN0_DIS							(0x00<< ACMP_HYSEN0_POS)
#define ACMP_HYSEN0_EN							(0x01<< ACMP_HYSEN0_POS)
#define ACMP_HYSEN0_MASK						(ACMP_HYSEN0_BITS<< ACMP_HYSEN0_POS)
#define __ACMP_HYSEN0_GET()						M_REG_GET(ACMP_HYSEN0_REG, ACMP_HYSEN0_POS, ACMP_HYSEN0_BITS)
#define __ACMP_HYSEN0_SET(EN)					M_REG_SET(ACMP_HYSEN0_REG, ACMP_HYSEN0_POS, ACMP_HYSEN0_BITS, EN)
#define __ACMP_HYSEN0_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_HYSEN0_REG, ACMP_HYSEN0_POS, ACMP_HYSEN0_BITS)
#define __ACMP_HYSEN0_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(ACMP_HYSEN0_REG, ACMP_HYSEN0_POS, ACMP_HYSEN0_BITS, POS_EN)

//ACMP0IE
#define ACMP_ACMP0IE_REG						ACMP0CR4
#define ACMP_ACMP0IE_POS						(1)
#define ACMP_ACMP0IE_BITS						C_REG_BITS1
#define ACMP_ACMP0IE_DIS						(0x00<< ACMP_ACMP0IE_POS)
#define ACMP_ACMP0IE_EN							(0x01<< ACMP_ACMP0IE_POS)
#define ACMP_ACMP0IE_MASK						(ACMP_ACMP0IE_BITS<< ACMP_ACMP0IE_POS)
#define __ACMP_ACMP0IE_GET()					M_REG_GET(ACMP_ACMP0IE_REG, ACMP_ACMP0IE_POS, ACMP_ACMP0IE_BITS)
#define __ACMP_ACMP0IE_SET(EN)					M_REG_SET(ACMP_ACMP0IE_REG, ACMP_ACMP0IE_POS, ACMP_ACMP0IE_BITS, EN)
#define __ACMP_ACMP0IE_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_ACMP0IE_REG, ACMP_ACMP0IE_POS, ACMP_ACMP0IE_BITS)
#define __ACMP_ACMP0IE_SET_SHIFT(POS_EN)		M_REG_SET_SHIFT(ACMP_ACMP0IE_REG, ACMP_ACMP0IE_POS, ACMP_ACMP0IE_BITS, POS_EN)


//ACMP0EN
#define ACMP_ACMP0EN_REG						ACMP0CR4
#define ACMP_ACMP0EN_POS						(0)
#define ACMP_ACMP0EN_BITS						C_REG_BITS1
#define ACMP_ACMP0EN_DIS						(0x00<< ACMP_ACMP0EN_POS)
#define ACMP_ACMP0EN_EN							(0x01<< ACMP_ACMP0EN_POS)
#define ACMP_ACMP0EN_MASK						(ACMP_ACMP0EN_BITS<< ACMP_ACMP0EN_POS)
#define __ACMP_ACMP0EN_GET()					M_REG_GET(ACMP_ACMP0EN_REG, ACMP_ACMP0EN_POS, ACMP_ACMP0EN_BITS)
#define __ACMP_ACMP0EN_SET(EN)					M_REG_SET(ACMP_ACMP0EN_REG, ACMP_ACMP0EN_POS, ACMP_ACMP0EN_BITS, EN)
#define __ACMP_ACMP0EN_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_ACMP0EN_REG, ACMP_ACMP0EN_POS, ACMP_ACMP0EN_BITS)
#define __ACMP_ACMP0EN_SET_SHIFT(POS_EN)		M_REG_SET_SHIFT(ACMP_ACMP0EN_REG, ACMP_ACMP0EN_POS, ACMP_ACMP0EN_BITS, POS_EN)
/**@}*/ /*** end of group acmp_reg_acmp0cr4 */

/** 
 * @addtogroup	acmp_reg_acmp1cr1	reg: ACMP1CR1 
 * @{
 */
//ACMP1CR1
//CAL_CNT1[5:0]
#define ACMP_CAL_CNT1_REG						ACMP1CR1
#define ACMP_CAL_CNT1_POS						(2)
#define ACMP_CAL_CNT1_BITS						C_REG_BITS5
#define ACMP_CAL_CNT1_VAL
#define ACMP_CAL_CNT1_MASK						(ACMP_CAL_CNT1_BITS<< ACMP_CAL_CNT1_POS)
#define __ACMP_CAL_CNT1_GET()					M_REG_GET(ACMP_CAL_CNT1_REG, ACMP_CAL_CNT1_POS, ACMP_CAL_CNT1_BITS)
#define __ACMP_CAL_CNT1_SET(SET)				M_REG_SET(ACMP_CAL_CNT1_REG, ACMP_CAL_CNT1_POS, ACMP_CAL_CNT1_BITS, SET)
#define __ACMP_CAL_CNT1_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_CAL_CNT1_REG, ACMP_CAL_CNT1_POS, ACMP_CAL_CNT1_BITS)
#define __ACMP_CAL_CNT1_SET_SHIFT(POS_SET)		M_REG_SET_SHIFT(ACMP_CAL_CNT1_REG, ACMP_CAL_CNT1_POS, ACMP_CAL_CNT1_BITS, POS_SET)

//CAL_FT1
#define ACMP_CAL_FT1_REG						ACMP1CR1
#define ACMP_CAL_FT1_POS						(1)
#define ACMP_CAL_FT1_BITS						C_REG_BITS1
#define ACMP_CAL_FT1_FAIL						(0x01<< ACMP_CAL_FT1_POS)
#define ACMP_CAL_FT1_SUCCESS					(0x00<< ACMP_CAL_FT1_POS)
#define ACMP_CAL_FT1_MASK						(ACMP_CAL_FT1_BITS<< ACMP_CAL_FT1_POS)
#define __ACMP_CAL_FT1_GET()					M_REG_GET(ACMP_CAL_FT1_REG, ACMP_CAL_FT1_POS, ACMP_CAL_FT1_BITS)
#define __ACMP_CAL_FT1_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_CAL_FT1_REG, ACMP_CAL_FT1_POS, ACMP_CAL_FT1_BITS)

//CALEN1
#define ACMP_CALEN1_REG							ACMP1CR1
#define ACMP_CALEN1_POS							(0)
#define ACMP_CALEN1_BITS						C_REG_BITS1
#define ACMP_CALEN1_FINISH						(0x00<< ACMP_CALEN1_POS)
#define ACMP_CALEN1_EN							(0x01<< ACMP_CALEN1_POS)
#define ACMP_CALEN1_MASK						(ACMP_CALEN1_BITS<< ACMP_CALEN1_POS)
#define __ACMP_CALEN1_GET()						M_REG_GET(ACMP_CALEN1_REG, ACMP_CALEN1_POS, ACMP_CALEN1_BITS)
#define __ACMP_CALEN1_SET(SET)					M_REG_SET(ACMP_CALEN1_REG, ACMP_CALEN1_POS, ACMP_CALEN1_BITS, SET)
#define __ACMP_CALEN1_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_CALEN1_REG, ACMP_CALEN1_POS, ACMP_CALEN1_BITS)
#define __ACMP_CALEN1_SET_SHIFT(POS_SET)		M_REG_SET_SHIFT(ACMP_CALEN1_REG, ACMP_CALEN1_POS, ACMP_CALEN1_BITS, POS_SET)
/**@}*/ /*** end of group acmp_reg_acmp1cr1 */

/** 
 * @addtogroup	acmp_reg_acmp1cr2	reg: ACMP1CR2 
 * @{
 */
//ACMP1CR2
//INSHTEN1[1:0]
#define ACMP_INSHTEN1_REG						ACMP1CR2
#define ACMP_INSHTEN1_POS						(6)
#define ACMP_INSHTEN1_BITS						C_REG_BITS2
#define ACMP_INSHTEN1_DIS						(0x00<< ACMP_INSHTEN1_POS)
#define ACMP_INSHTEN1_EN_MOD1					(0x01<< ACMP_INSHTEN1_POS)
#define ACMP_INSHTEN1_EN_MOD2					(0x02<< ACMP_INSHTEN1_POS)
#define ACMP_INSHTEN1_EN_MOD3					(0x03<< ACMP_INSHTEN1_POS)
#define ACMP_INSHTEN1_MASK						(ACMP_INSHTEN1_BITS<< ACMP_INSHTEN1_POS)
#define __ACMP_INSHTEN1_GET()					M_REG_GET(ACMP_INSHTEN1_REG, ACMP_INSHTEN1_POS, ACMP_INSHTEN1_BITS)
#define __ACMP_INSHTEN1_SET(EN)					M_REG_SET(ACMP_INSHTEN1_REG, ACMP_INSHTEN1_POS, ACMP_INSHTEN1_BITS, EN)
#define __ACMP_INSHTEN1_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_INSHTEN1_REG, ACMP_INSHTEN1_POS,ACMP_INSHTEN1_BITS)
#define __ACMP_INSHTEN1_SET_SHIFT(POS_EN)		M_REG_SET_SHIFT(ACMP_INSHTEN1_REG, ACMP_INSHTEN1_POS,ACMP_INSHTEN1_BITS, POS_EN)

//WEN1
#define ACMP_WEN1_REG							ACMP1CR2
#define ACMP_WEN1_POS							(5)
#define ACMP_WEN1_BITS							C_REG_BITS1
#define ACMP_WEN1_DIS							(0x00<< ACMP_WEN1_POS)
#define ACMP_WEN1_EN							(0x01<< ACMP_WEN1_POS)
#define ACMP_WEN1_MASK							(ACMP_WEN1_BITS<< ACMP_WEN1_POS)
#define __ACMP_WEN1_GET()						M_REG_GET(ACMP_WEN1_REG, ACMP_WEN1_POS, ACMP_WEN1_BITS)
#define __ACMP_WEN1_SET(SET)					M_REG_SET(ACMP_WEN1_REG, ACMP_WEN1_POS, ACMP_WEN1_BITS, SET)
#define __ACMP_WEN1_GET_SHIFT()					M_REG_GET_SHIFT(ACMP_WEN1_REG, ACMP_WEN1_POS, ACMP_WEN1_BITS)
#define __ACMP_WEN1_SET_SHIFT(POS_SET)			M_REG_SET_SHIFT(ACMP_WEN1_REG, ACMP_WEN1_POS, ACMP_WEN1_BITS, POS_SET)

//ACMP1OFT[4:0]
#define ACMP_ACMP1OFT_REG						ACMP1CR2
#define ACMP_ACMP1OFT_POS						(0)
#define ACMP_ACMP1OFT_BITS						C_REG_BITS5
#define ACMP_ACMP1OFT_DIS						(0x00<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_P0P5MV					(0x01<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_P1P0MV					(0x02<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_P1P5MV					(0x03<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_P2P0MV					(0x04<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_P2P5MV					(0x05<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_P3P0MV					(0x06<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_P3P5MV					(0x07<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_P4P0MV					(0x08<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_P4P5MV					(0x09<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_P5P0MV					(0x0A<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_P5P5MV					(0x0B<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_P6P0MV					(0x0C<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_P6P5MV					(0x0D<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_P7P0MV					(0x0E<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_P7P5MV					(0x0F<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_DIS_N						(0x10<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_N0P5MV					(0x11<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_N1P0MV					(0x12<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_N1P5MV					(0x13<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_N2P0MV					(0x14<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_N2P5MV					(0x15<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_N3P0MV					(0x16<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_N3P5MV					(0x17<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_N4P0MV					(0x18<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_N4P5MV					(0x19<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_N5P0MV					(0x1A<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_N5P5MV					(0x1B<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_N6P0MV					(0x1C<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_N6P5MV					(0x1D<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_N7P0MV					(0x1E<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_N7P5MV					(0x1F<< ACMP_ACMP1OFT_POS)
#define ACMP_ACMP1OFT_MASK						(ACMP_ACMP1OFT_BITS<< ACMP_ACMP1OFT_POS)
#define __ACMP_ACMP1OFT_GET()					M_REG_GET(ACMP_ACMP1OFT_REG, ACMP_ACMP1OFT_POS, ACMP_ACMP1OFT_BITS)
#define __ACMP_ACMP1OFT_SET(EN)					M_REG_SET(ACMP_ACMP1OFT_REG, ACMP_ACMP1OFT_POS, ACMP_ACMP1OFT_BITS, EN)
#define __ACMP_ACMP1OFT_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_ACMP1OFT_REG, ACMP_ACMP1OFT_POS, ACMP_ACMP1OFT_BITS)
#define __ACMP_ACMP1OFT_SET_SHIFT(POS_EN)		M_REG_SET_SHIFT(ACMP_ACMP1OFT_REG, ACMP_ACMP1OFT_POS, ACMP_ACMP1OFT_BITS, POS_EN)
/**@}*/ /*** end of group acmp_reg_acmp1cr2 */

/** 
 * @addtogroup	acmp_reg_acmp1cr3	reg: ACMP1CR3 
 * @{
 */
//ACMP1CR3
//ACMP1PS[3:0]
#define ACMP_ACMP1PS_REG						ACMP1CR3
#define ACMP_ACMP1PS_POS						(4)
#define ACMP_ACMP1PS_BITS						C_REG_BITS4
#define ACMP_ACMP1PS_CHL_PT30					(0x01<< ACMP_ACMP1PS_POS)
#define ACMP_ACMP1PS_CHL_LDO					(0x03<< ACMP_ACMP1PS_POS)
#define ACMP_ACMP1PS_CHL_1V0					(0x04<< ACMP_ACMP1PS_POS)
#define ACMP_ACMP1PS_CHL_CMP1VREF				(0x05<< ACMP_ACMP1PS_POS)
#define ACMP_ACMP1PS_CHL_GND					(0x06<< ACMP_ACMP1PS_POS)
#define ACMP_ACMP1PS_CHL_PT31					(0x08<< ACMP_ACMP1PS_POS)
#define ACMP_ACMP1PS_CHL_PT32					(0x0A<< ACMP_ACMP1PS_POS)
#define ACMP_ACMP1PS_CHL_CC1A					(0x0C<< ACMP_ACMP1PS_POS)
#define ACMP_ACMP1PS_CHL_CC2A					(0x0D<< ACMP_ACMP1PS_POS)
#define ACMP_ACMP1PS_CHL_CC1B					(0x0E<< ACMP_ACMP1PS_POS)
#define ACMP_ACMP1PS_CHL_CC2B					(0x0F<< ACMP_ACMP1PS_POS)
#define ACMP_ACMP1PS_MASK						(ACMP_ACMP1PS_BITS<< ACMP_ACMP1PS_POS)
#define __ACMP_ACMP1PS_GET()					M_REG_GET(ACMP_ACMP1PS_REG, ACMP_ACMP1PS_POS, ACMP_ACMP1PS_BITS)
#define __ACMP_ACMP1PS_SET(CHL)					M_REG_SET(ACMP_ACMP1PS_REG, ACMP_ACMP1PS_POS, ACMP_ACMP1PS_BITS, CHL)
#define __ACMP_ACMP1PS_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_ACMP1PS_REG, ACMP_ACMP1PS_POS, ACMP_ACMP1PS_BITS)
#define __ACMP_ACMP1PS_SET_SHIFT(POS_CHL)		M_REG_SET_SHIFT(ACMP_ACMP1PS_REG, ACMP_ACMP1PS_POS, ACMP_ACMP1PS_BITS, POS_CHL)

//ACMP1O
#define ACMP_ACMP1O_REG							ACMP1CR3
#define ACMP_ACMP1O_POS							(3)
#define ACMP_ACMP1O_BITS						C_REG_BITS1
#define ACMP_ACMP1O_RESET						(0x00<< ACMP_WEN0_POS)
#define ACMP_ACMP1O_SET							(0x01<< ACMP_WEN0_POS)
#define ACMP_ACMP1O_MASK						(ACMP_ACMP1O_BITS<< ACMP_WEN0_POS)
#define __ACMP_ACMP1O_GET()						M_REG_GET(ACMP_ACMP1O_REG, ACMP_WEN0_POS, ACMP_ACMP1O_BITS)
#define __ACMP_ACMP1O_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_ACMP1O_REG, ACMP_WEN0_POS, ACMP_ACMP1O_BITS)

//ACMP1NS[2:0]
#define ACMP_ACMP1NS_REG						ACMP1CR3
#define ACMP_ACMP1NS_POS						(0)
#define ACMP_ACMP1NS_BITS						C_REG_BITS3
#define ACMP_ACMP1NS_CHL_PT30					(0x00<< ACMP_ACMP1NS_POS)
#define ACMP_ACMP1NS_CHL_PT26					(0x01<< ACMP_ACMP1NS_POS)
#define ACMP_ACMP1NS_CHL_INTVREF				(0x04<< ACMP_ACMP1NS_POS)
#define ACMP_ACMP1NS_CHL_CMP1VREF				(0x05<< ACMP_ACMP1NS_POS)
#define ACMP_ACMP1NS_MASK						(ACMP_ACMP1NS_BITS<< ACMP_ACMP1NS_POS)
#define __ACMP_ACMP1NS_GET()					M_REG_GET(ACMP_ACMP1NS_REG, ACMP_ACMP1NS_POS, ACMP_ACMP1NS_BITS)
#define __ACMP_ACMP1NS_SET(CHL)					M_REG_SET(ACMP_ACMP1NS_REG, ACMP_ACMP1NS_POS, ACMP_ACMP1NS_BITS, CHL)
#define __ACMP_ACMP1NS_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_ACMP1NS_REG, ACMP_ACMP1NS_POS, ACMP_ACMP1NS_BITS)
#define __ACMP_ACMP1NS_SET_SHIFT(POS_CHL)		M_REG_SET_SHIFT(ACMP_ACMP1NS_REG, ACMP_ACMP1NS_POS, ACMP_ACMP1NS_BITS, POS_CHL)
/**@}*/ /*** end of group acmp_reg_acmp1cr3 */

/** 
 * @addtogroup	acmp_reg_acmp1cr4	reg: ACMP1CR4 
 * @{
 */
//ACMP1CR4
//ACMP1F
#define ACMP_ACMP1F_REG							ACMP1CR4
#define ACMP_ACMP1F_POS							(7)
#define ACMP_ACMP1F_BITS						C_REG_BITS1
#define ACMP_ACMP1F_RESET						(0x00<< ACMP_ACMP1F_POS)
#define ACMP_ACMP1F_SET							(0x01<< ACMP_ACMP1F_POS)
#define ACMP_ACMP1F_CLR							(0x01<< ACMP_ACMP1F_POS)
#define ACMP_ACMP1F_MASK						(ACMP_ACMP1F_BITS<< ACMP_ACMP1F_POS)
#define __ACMP_ACMP1F_GET()						M_REG_GET(ACMP_ACMP1F_REG, ACMP_ACMP1F_POS, ACMP_ACMP1F_BITS)
#define __ACMP_ACMP1F_SET(CLR)					M_REG_SET(ACMP_ACMP1F_REG, ACMP_ACMP1F_POS, ACMP_ACMP1F_BITS, CLR)
#define __ACMP_ACMP1F_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_ACMP1F_REG, ACMP_ACMP1F_POS, ACMP_ACMP1F_BITS)
#define __ACMP_ACMP1F_SET_SHIFT(POS_CLR)		M_REG_SET_SHIFT(ACMP_ACMP1F_REG, ACMP_ACMP1F_POS, ACMP_ACMP1F_BITS, POS_CLR)

//ACMP1OINV
#define ACMP_ACMP1OINV_REG						ACMP1CR4
#define ACMP_ACMP1OINV_POS						(6)
#define ACMP_ACMP1OINV_BITS						C_REG_BITS1
#define ACMP_ACMP1OINV_DIS						(0x00<< ACMP_ACMP1OINV_POS)
#define ACMP_ACMP1OINV_EN						(0x01<< ACMP_ACMP1OINV_POS)
#define ACMP_ACMP1OINV_MASK						(ACMP_ACMP1OINV_BITS<< ACMP_ACMP1OINV_POS)
#define __ACMP_ACMP1OINV_GET()					M_REG_GET(ACMP_ACMP1OINV_REG, ACMP_ACMP1OINV_POS, ACMP_ACMP1OINV_BITS)
#define __ACMP_ACMP1OINV_SET(EN)				M_REG_SET(ACMP_ACMP1OINV_REG, ACMP_ACMP1OINV_POS, ACMP_ACMP1OINV_BITS, EN)
#define __ACMP_ACMP1OINV_GET_SHIFT()			M_REG_GET_SHIFT(ACMP_ACMP1OINV_REG, ACMP_ACMP1OINV_POS, ACMP_ACMP1OINV_BITS)
#define __ACMP_ACMP1OINV_SET_SHIFT(POS_EN)		M_REG_SET_SHIFT(ACMP_ACMP1OINV_REG, ACMP_ACMP1OINV_POS, ACMP_ACMP1OINV_BITS, POS_EN)

//ACMP1OFLTS[2:0]
#define ACMP_ACMP1OFLTS_REG						ACMP1CR4
#define ACMP_ACMP1OFLTS_POS						(3)
#define ACMP_ACMP1OFLTS_BITS					C_REG_BITS3
#define ACMP_ACMP1OFLTS_DIS						(0x00<< ACMP_ACMP1OFLTS_POS)
#define ACMP_ACMP1OFLTS_4XCLK					(0x01<< ACMP_ACMP1OFLTS_POS)
#define ACMP_ACMP1OFLTS_8XCLK					(0x02<< ACMP_ACMP1OFLTS_POS)
#define ACMP_ACMP1OFLTS_16XCLK					(0x03<< ACMP_ACMP1OFLTS_POS)
#define ACMP_ACMP1OFLTS_32XCLK					(0x04<< ACMP_ACMP1OFLTS_POS)
#define ACMP_ACMP1OFLTS_64XCLK					(0x05<< ACMP_ACMP1OFLTS_POS)
#define ACMP_ACMP1OFLTS_128XCLK					(0x06<< ACMP_ACMP1OFLTS_POS)
#define ACMP_ACMP1OFLTS_256XCLK					(0x07<< ACMP_ACMP1OFLTS_POS)
#define ACMP_ACMP1OFLTS_MASK					(ACMP_ACMP1OFLTS_BITS<< ACMP_ACMP1OFLTS_POS)
#define __ACMP_ACMP1OFLTS_GET()					M_REG_GET(ACMP_ACMP1OFLTS_REG, ACMP_ACMP1OFLTS_POS, ACMP_ACMP1OFLTS_BITS)
#define __ACMP_ACMP1OFLTS_SET(SET)				M_REG_SET(ACMP_ACMP1OFLTS_REG, ACMP_ACMP1OFLTS_POS, ACMP_ACMP1OFLTS_BITS, SET)
#define __ACMP_ACMP1OFLTS_GET_SHIFT()			M_REG_GET_SHIFT(ACMP_ACMP1OFLTS_REG, ACMP_ACMP1OFLTS_POS, ACMP_ACMP1OFLTS_BITS)
#define __ACMP_ACMP1OFLTS_SET_SHIFT(POS_SET)	M_REG_SET_SHIFT(ACMP_ACMP1OFLTS_REG, ACMP_ACMP1OFLTS_POS, ACMP_ACMP1OFLTS_BITS, POS_SET)

//HYSEN1
#define ACMP_HYSEN1_REG							ACMP1CR4
#define ACMP_HYSEN1_POS							(2)
#define ACMP_HYSEN1_BITS						C_REG_BITS1
#define ACMP_HYSEN1_DIS							(0x00<< ACMP_HYSEN1_POS)
#define ACMP_HYSEN1_EN							(0x01<< ACMP_HYSEN1_POS)
#define ACMP_HYSEN1_MASK						(ACMP_HYSEN1_BITS<< ACMP_HYSEN1_POS)
#define __ACMP_HYSEN1_GET()						M_REG_GET(ACMP_HYSEN1_REG, ACMP_HYSEN1_POS, ACMP_HYSEN1_BITS)
#define __ACMP_HYSEN1_SET(EN)					M_REG_SET(ACMP_HYSEN1_REG, ACMP_HYSEN1_POS, ACMP_HYSEN1_BITS, EN)
#define __ACMP_HYSEN1_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_HYSEN1_REG, ACMP_HYSEN1_POS, ACMP_HYSEN1_BITS)
#define __ACMP_HYSEN1_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(ACMP_HYSEN1_REG, ACMP_HYSEN1_POS, ACMP_HYSEN1_BITS, POS_EN)

//ACMP1IE
#define ACMP_ACMP1IE_REG						ACMP1CR4
#define ACMP_ACMP1IE_POS						(1)
#define ACMP_ACMP1IE_BITS						C_REG_BITS1
#define ACMP_ACMP1IE_DIS						(0x00<< ACMP_ACMP1IE_POS)
#define ACMP_ACMP1IE_EN							(0x01<< ACMP_ACMP1IE_POS)
#define ACMP_ACMP1IE_MASK						(ACMP_ACMP1IE_BITS<< ACMP_ACMP1IE_POS)
#define __ACMP_ACMP1IE_GET()					M_REG_GET(ACMP_ACMP1IE_REG, ACMP_ACMP1IE_POS, ACMP_ACMP1IE_BITS)
#define __ACMP_ACMP1IE_SET(EN)					M_REG_SET(ACMP_ACMP1IE_REG, ACMP_ACMP1IE_POS, ACMP_ACMP1IE_BITS, EN)
#define __ACMP_ACMP1IE_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_ACMP1IE_REG, ACMP_ACMP1IE_POS, ACMP_ACMP1IE_BITS)
#define __ACMP_ACMP1IE_SET_SHIFT(POS_EN)		M_REG_SET_SHIFT(ACMP_ACMP1IE_REG, ACMP_ACMP1IE_POS, ACMP_ACMP1IE_BITS, POS_EN)


//ACMP1EN
#define ACMP_ACMP1EN_REG						ACMP1CR4
#define ACMP_ACMP1EN_POS						(0)
#define ACMP_ACMP1EN_BITS						C_REG_BITS1
#define ACMP_ACMP1EN_DIS						(0x00<< ACMP_ACMP1EN_POS)
#define ACMP_ACMP1EN_EN							(0x01<< ACMP_ACMP1EN_POS)
#define ACMP_ACMP1EN_MASK						(ACMP_ACMP1EN_BITS<< ACMP_ACMP1EN_POS)
#define __ACMP_ACMP1EN_GET()					M_REG_GET(ACMP_ACMP1EN_REG, ACMP_ACMP1EN_POS, ACMP_ACMP1EN_BITS)
#define __ACMP_ACMP1EN_SET(EN)					M_REG_SET(ACMP_ACMP1EN_REG, ACMP_ACMP1EN_POS, ACMP_ACMP1EN_BITS, EN)
#define __ACMP_ACMP1EN_GET_SHIFT()				M_REG_GET_SHIFT(ACMP_ACMP1EN_REG, ACMP_ACMP1EN_POS, ACMP_ACMP1EN_BITS)
#define __ACMP_ACMP1EN_SET_SHIFT(POS_EN)		M_REG_SET_SHIFT(ACMP_ACMP1EN_REG, ACMP_ACMP1EN_POS, ACMP_ACMP1EN_BITS, POS_EN)
/**@}*/ /*** end of group acmp_reg_acmp1cr4 */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup csu39fx10_sdk_chip_fwlib_acmp_cfg	acmp_config
 * @{
 */
/** 
 * @name acmp0 config
 * @{
 */
/**
 * @details <b>CFG_ACMP_CAL_CNT0</b>
 * - <b>Features: </b> comparator 0 offset voltage calibration time constant setting
 * @details <b>time= CAL_CNT0[5:0]× 4× Tcpuclk</b>
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | n		| >5uS,			|
 */
#define	CFG_ACMP_CAL_CNT0			(30)		///< {>5uS, }

/**
 * @details <b>CFG_ACMP_CALEN0</b>
 * - <b>Features: </b> comparator 0 offset voltage calibration enable control
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| disable,		|
 * | 1		| enable,		|
 */
#define	CFG_ACMP_CALEN0				(0)			///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_ACMP_INSHTEN0</b>
 * - <b>Features: </b> short enable control in comparator 0
 * - <b>Param: </b>
 * | config	| Descriptions												|
 * | :----:	| :----:													|
 * | 0*		| disable short,											|
 * | 1		| enable short, positive_port= negative_port= gnd,			|
 * | 2		| enable short, positive_port= negative_port= positive_in,	|
 * | 3		| enable short, positive_port= negative_port= negative_in,	|
 */
#define	CFG_ACMP_INSHTEN0			(0)			///< {0~ 3}

/**
 * @details <b>CFG_ACMP_WEN0</b>
 * - <b>Features: </b> comparator 0 acmpoft[4:0] write enable control
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| disable,		|
 * | 1		| enable,		|
 */
#define	CFG_ACMP_WEN0				(0)			///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_ACMP_ACMP0OFT_VOL</b>
 * - <b>Features: </b> comparator 0 offset voltage calibration control
 * @details <b>time= CAL_CNT0[5:0]× 4× Tcpuclk</b>
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0~ 75	| unit: 0.1mV,	|
 */
#define	CFG_ACMP_ACMP0OFT_VOL		(0)			///< {0~ 75 unit->0.1mV}

/**
 * @details <b>CFG_ACMP_ACMP0PS</b>
 * - <b>Features: </b> comparator 0 positive terminal input selection
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0x00*	| PT3.1(DP_A),	|
 * | 0x01	| PT3.2(DM_A),	|
 * | 0x02	| PT2.3(DP_B),	|
 * | 0x03	| PT2.4(DM_B),	|
 * | 0x04	| INTVREF,		|
 * | 0x05	| CMP0VREF,		|
 * | 0x06	| GND,			|
 * | 0x07	| NC,			|
 * | 0x08	| PT3.5(DP_C),	|
 * | 0x09	| PT3.6(DM_C),	|
 * | 0x0A	| PT3.3(DP_D),	|
 * | 0x0B	| PT3.4(DM_D),	|
 */
#define	CFG_ACMP_ACMP0PS			(0)			///< {0~ 15}

/**
 * @details <b>CFG_ACMP_ACMP0PS</b>
 * - <b>Features: </b> comparator 0 negative terminal input selection
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0x00*	| PT3.0,		|
 * | 0x01	| NC,			|
 * | 0x02	| NC,			|
 * | 0x03	| NC,			|
 * | 0x04	| INTVREF,		|
 * | 0x05	| CMP0VREF,		|
 * | 0x06	| NC,			|
 * | 0x07	| NC,			|
 */
#define	CFG_ACMP_ACMP0NS			(0)			///< {0~ 7}

/**
 * @details <b>CFG_ACMP_ACMP0OINV</b>
 * - <b>Features: </b> comparator 0 output inversion enable control
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| normal,		|
 * | 1		| flip,			|
 */
#define	CFG_ACMP_ACMP0OINV			(0)			///< 0-> normal, 1-> flip

/**
 * @details <b>CFG_ACMP_ACMP0OFLTS</b>
 * - <b>Features: </b> comparator 0 output filter time control
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0x00*	| disable,		|
 * | 0x01	| 4* Tcpuclk,	|
 * | 0x02	| 8* Tcpuclk,	|
 * | 0x03	| 16* Tcpuclk,	|
 * | 0x04	| 32* Tcpuclk,	|
 * | 0x05	| 64* Tcpuclk,	|
 * | 0x06	| 128* Tcpuclk,	|
 * | 0x07	| 256* Tcpuclk,	|
 */
#define	CFG_ACMP_ACMP0OFLTS			(0)			///< {0~ 7}

/**
 * @details <b>CFG_ACMP_HYSEN0</b>
 * - <b>Features: </b> comparator 0 hysteresis enable control
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| disable,		|
 * | 1		| enable,		|
 */
#define	CFG_ACMP_HYSEN0				(0)			///< 0-> disbale, 1-> enable

/**
 * @details <b>CFG_ACMP_ACMP0IE</b>
 * - <b>Features: </b> comparator 0 interrupt enable control
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| disable,		|
 * | 1		| enable,		|
 */
#define	CFG_ACMP_ACMP0IE			(0)			///< 0-> disbale, 1-> enable

/**
 * @details <b>CFG_ACMP_ACMP0EN</b>
 * - <b>Features: </b> comparator 0 enable control
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| disable,		|
 * | 1		| enable,		|
 */
#define	CFG_ACMP_ACMP0EN			(0)			///< 0-> disbale, 1-> enable
/**@}*/ /*** end of name acmp0 config */


/** 
 * @name acmp1 config
 * @{
 */
/**
 * @details <b>CFG_ACMP_CAL_CNT1</b>
 * - <b>Features: </b> comparator 1 offset voltage calibration time constant setting
 * @details <b>time= CAL_CNT1[5:0]× 4× Tcpuclk</b>
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | n		| >5uS,			|
 */
#define	CFG_ACMP_CAL_CNT1			(30)		///< {>5uS, }

/**
 * @details <b>CFG_ACMP_CALEN1</b>
 * - <b>Features: </b> comparator 1 offset voltage calibration enable control
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| disable,		|
 * | 1		| enable,		|
 */
#define	CFG_ACMP_CALEN1				(0)			///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_ACMP_INSHTEN1</b>
 * - <b>Features: </b> short enable control in comparator 1
 * - <b>Param: </b>
 * | config	| Descriptions												|
 * | :----:	| :----:													|
 * | 0*		| disable short,											|
 * | 1		| enable short, positive_port= negative_port= gnd,			|
 * | 2		| enable short, positive_port= negative_port= positive_in,	|
 * | 3		| enable short, positive_port= negative_port= negative_in,	|
 */
#define	CFG_ACMP_INSHTEN1			(0)			///< {0~ 3}

/**
 * @details <b>CFG_ACMP_WEN1</b>
 * - <b>Features: </b> comparator 1 acmpoft[4:0] write enable control
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| disable,		|
 * | 1		| enable,		|
 */
#define	CFG_ACMP_WEN1				(0)			///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_ACMP_ACMP1OFT_VOL</b>
 * - <b>Features: </b> comparator 1 offset voltage calibration control
 * @details <b>time= CAL_CNT0[5:0]× 4× Tcpuclk</b>
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0~ 75	| unit: 0.1mV,	|
 */
#define	CFG_ACMP_ACMP1OFT_VOL		(0)			///< {0~ 75 unit->0.1mV}

/**
 * @details <b>CFG_ACMP_ACMP1PS</b>
 * - <b>Features: </b> comparator 1 positive terminal input selection
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0x00*	| NC,			|
 * | 0x01	| PT3.0,		|
 * | 0x02	| NC,			|
 * | 0x03	| LDO,			|
 * | 0x04	| 1.0V,			|
 * | 0x05	| CMP1VREF,		|
 * | 0x06	| GND,			|
 * | 0x07	| NC,			|
 * | 0x08	| PT3.1,		|
 * | 0x09	| PT3.1,		|
 * | 0x0A	| PT3.2,		|
 * | 0x0B	| PT3.2,		|
 * | 0x0C	| CC1_A,		|
 * | 0x0D	| CC2_A,		|
 * | 0x0E	| PT3.3(CC1_B),	|
 * | 0x0F	| PT3.4(CC2_B),	|
 */
#define	CFG_ACMP_ACMP1PS			(0)			///< {0~ 15}

/**
 * @details <b>CFG_ACMP_ACMP1NS</b>
 * - <b>Features: </b> comparator 1 negative terminal input selection
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0x00*	| PT3.0,		|
 * | 0x01	| PT2.6,		|
 * | 0x02	| NC,			|
 * | 0x03	| NC,			|
 * | 0x04	| INTVREF,		|
 * | 0x05	| CMP0VREF,		|
 * | 0x06	| NC,			|
 * | 0x07	| NC,			|
 */
#define	CFG_ACMP_ACMP1NS			(0)			///< {0~ 7}

/**
 * @details <b>CFG_ACMP_ACMP1OINV</b>
 * - <b>Features: </b> comparator 1 output inversion enable control
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| normal,		|
 * | 1		| flip,			|
 */
#define	CFG_ACMP_ACMP1OINV			(0)			///< 0-> normal, 1-> flip

/**
 * @details <b>CFG_ACMP_ACMP1OFLTS</b>
 * - <b>Features: </b> comparator 1 output filter time control
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0x00*	| disable,		|
 * | 0x01	| 4* Tcpuclk,	|
 * | 0x02	| 8* Tcpuclk,	|
 * | 0x03	| 16* Tcpuclk,	|
 * | 0x04	| 32* Tcpuclk,	|
 * | 0x05	| 64* Tcpuclk,	|
 * | 0x06	| 128* Tcpuclk,	|
 * | 0x07	| 256* Tcpuclk,	|
 */
#define	CFG_ACMP_ACMP1OFLTS			(0)			///< {0~ 7}

/**
 * @details <b>CFG_ACMP_HYSEN1</b>
 * - <b>Features: </b> comparator 1 hysteresis enable control
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| disable,		|
 * | 1		| enable,		|
 */
#define	CFG_ACMP_HYSEN1				(0)			///< 0-> disbale, 1-> enable

/**
 * @details <b>CFG_ACMP_ACMP1IE</b>
 * - <b>Features: </b> comparator 1 interrupt enable control
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| disable,		|
 * | 1		| enable,		|
 */
#define	CFG_ACMP_ACMP1IE			(0)			///< 0-> disbale, 1-> enable

/**
 * @details <b>CFG_ACMP_ACMP1EN</b>
 * - <b>Features: </b> comparator 1 enable control
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| disable,		|
 * | 1		| enable,		|
 */
#define	CFG_ACMP_ACMP1EN			(0)			///< 0-> disbale, 1-> enable
/**@}*/ /*** end of name acmp1 config */
/**@}*/ /*** end of group csu39fx10_sdk_chip_fwlib_acmp_cfg */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup acmp_compile	attention: users do not need to care
 * @attention <b>users do not need to care</b>
 * @{
 */
/** 
 * @name acmp0_compile_reg_acmp0cr1
 * @{
 */
#define PRE_ACMP_CAL_CNT0				CFG_ACMP_CAL_CNT0

#if(CFG_ACMP_CALEN0!= 0)
	#define PRE_ACMP_CALEN0				1
#else
	#define PRE_ACMP_CALEN0				0
#endif
/**@}*/ /*** end of name acmp0_compile_reg_acmp0cr1 */

/** 
 * @name acmp0_compile_reg_acmp0cr2
 * @{
 */
#define PRE_ACMP_INSHTEN0				CFG_ACMP_INSHTEN0

#if(CFG_ACMP_WEN0!= 0)
	#define PRE_ACMP_WEN0				1
#else
	#define PRE_ACMP_WEN0				0
#endif

#define PRE_ACMP_ACMP0OFT				(unsigned char)(CFG_ACMP_ACMP0OFT_VOL/ 5)
/**@}*/ /*** end of name acmp0_compile_reg_acmp0cr2 */

/** 
 * @name acmp0_compile_reg_acmp0cr3
 * @{
 */
#define PRE_ACMP_ACMP0PS				(CFG_ACMP_ACMP0PS& 0x0F)
#define PRE_ACMP_ACMP0NS				(CFG_ACMP_ACMP0NS& 0x07)
/**@}*/ /*** end of name acmp0_compile_reg_acmp0cr3 */

/** 
 * @name acmp0_compile_reg_acmp0cr4
 * @{
 */
#if(CFG_ACMP_ACMP0OINV!= 0)
	#define PRE_ACMP_ACMP0OINV			1
#else
	#define PRE_ACMP_ACMP0OINV			0
#endif

#define PRE_ACMP_ACMP0OFLTS				CFG_ACMP_ACMP0OFLTS

#if(CFG_ACMP_HYSEN0!= 0)
	#define PRE_ACMP_HYSEN0				1
#else
	#define PRE_ACMP_HYSEN0				0
#endif

#if(CFG_ACMP_ACMP0IE!= 0)
	#define PRE_ACMP_ACMP0IE			1
#else
	#define PRE_ACMP_ACMP0IE			0
#endif

#if(CFG_ACMP_ACMP0EN!= 0)
	#define PRE_ACMP_ACMP0EN			1
#else
	#define PRE_ACMP_ACMP0EN			0
#endif
/**@}*/ /*** end of name acmp0_compile_reg_acmp0cr4 */
 
/** 
 * @name acmp0_compile_warning
 * @attention <b>compile warning message</b>
 * @{
 */
#if(CFG_ACMP_CALEN0)
	#if(((CFG_ACMP_CAL_CNT0* 4* 1000* 1000)/ C_CLK_CPUCLK)< 5)
		#warning "Warning: CFG_ACMP_CAL_CNT0 define error, will be redefined!"
	#endif
#endif

#if(CFG_ACMP_WEN0)
	#if((CFG_ACMP_ACMP0OFT_VOL< 0)|| (CFG_ACMP_ACMP0OFT_VOL> 75))
		#warning "Warning: CFG_ACMP_ACMP0OFT_VOL define error, will be redefined!"
	#endif
#endif
/**@}*/ /*** end of name acmp0_compile_warning */

/** 
 * @name acmp1_compile_reg_acmp1cr1
 * @{
 */
#define PRE_ACMP_CAL_CNT1				CFG_ACMP_CAL_CNT1

#if(CFG_ACMP_CALEN1!= 0)
	#define PRE_ACMP_CALEN1				1
#else
	#define PRE_ACMP_CALEN1				0
#endif
/**@}*/ /*** end of name acmp1_compile_reg_acmp1cr1 */

/** 
 * @name acmp1_compile_reg_acmp1cr2
 * @{
 */
#define PRE_ACMP_INSHTEN1				CFG_ACMP_INSHTEN1

#if(CFG_ACMP_WEN1!= 0)
	#define PRE_ACMP_WEN1				1
#else
	#define PRE_ACMP_WEN1				0
#endif

#define PRE_ACMP_ACMP1OFT				(unsigned char)((float)CFG_ACMP_ACMP1OFT_VOL/ 0.5)
/**@}*/ /*** end of name acmp1_compile_reg_acmp1cr2 */

/** 
 * @name acmp1_compile_reg_acmp1cr3
 * @{
 */
#define PRE_ACMP_ACMP1PS				CFG_ACMP_ACMP1PS
#define PRE_ACMP_ACMP1NS				CFG_ACMP_ACMP1NS
/**@}*/ /*** end of name acmp1_compile_reg_acmp1cr3 */

/** 
 * @name acmp1_compile_reg_acmp1cr4
 * @{
 */
#if(CFG_ACMP_ACMP1OINV!= 0)
	#define PRE_ACMP_ACMP1OINV			1
#else
	#define PRE_ACMP_ACMP1OINV			0
#endif

#define PRE_ACMP_ACMP1OFLTS				CFG_ACMP_ACMP1OFLTS

#if(CFG_ACMP_HYSEN1!= 0)
	#define PRE_ACMP_HYSEN1				1
#else
	#define PRE_ACMP_HYSEN1				0
#endif

#if(CFG_ACMP_ACMP1IE!= 0)
	#define PRE_ACMP_ACMP1IE			1
#else
	#define PRE_ACMP_ACMP1IE			0
#endif

#if(CFG_ACMP_ACMP1EN!= 0)
	#define PRE_ACMP_ACMP1EN			1
#else
	#define PRE_ACMP_ACMP1EN			0
#endif
/**@}*/ /*** end of name acmp1_compile_reg_acmp1cr4 */

/** 
 * @name acmp1_compile_warning
 * @attention <b>compile warning message</b>
 * @{
 */
#if(CFG_ACMP_CALEN1)
	#if(((CFG_ACMP_CAL_CNT1* 4* 1000* 1000)/ C_CLK_CPUCLK)< 5)
		#warning "Warning: CFG_ACMP_CAL_CNT1 define error, will be redefined!"
	#endif
#endif

#if(CFG_ACMP_WEN1)
	#if((CFG_ACMP_ACMP1OFT_VOL< 0)|| (CFG_ACMP_ACMP1OFT_VOL> 75))
		#warning "Warning: CFG_ACMP_ACMP1OFT_VOL define error, will be redefined!"
	#endif
#endif
/**@}*/ /*** end of name acmp1_compile_warning */
/**@}*/ /*** end of group acmp_compile */
/*******************************************************************************/




/******************************** dividing line ********************************/
/**
 * @addtogroup acmp_reg_default	reg_default_value
 * @{
 */
/** 
 * @name acmp0_reg_default
 * @par 示例
 * @code
 *		void test( void )
 *		{
 *			ACMP0CR1= PRE_ACMP0CR1_DEFAULT;
 *			ACMP0CR2= PRE_ACMP0CR2_DEFAULT;
 *			ACMP0CR3= PRE_ACMP0CR3_DEFAULT;
 *			ACMP0CR4= PRE_ACMP0CR4_DEFAULT;
 *		}
 * @endcode
 * @{
 */
#define PRE_ACMP0CR1_DEFAULT			(((PRE_ACMP_CAL_CNT0<< ACMP_CAL_CNT0_POS)& ACMP_CAL_CNT0_MASK)|				\
											((PRE_ACMP_CALEN0<< ACMP_CALEN0_POS)& ACMP_CALEN0_MASK))
#define PRE_ACMP0CR2_DEFAULT			(((PRE_ACMP_INSHTEN0<< ACMP_INSHTEN0_POS)& ACMP_INSHTEN0_MASK)|				\
											((PRE_ACMP_WEN0<< ACMP_WEN0_POS)& ACMP_WEN0_MASK)|						\
											((PRE_ACMP_ACMP0OFT<< ACMP_ACMP0OFT_POS)& ACMP_ACMP0OFT_MASK))
#define PRE_ACMP0CR3_DEFAULT			(((PRE_ACMP_ACMP0PS<< ACMP_ACMP0NS_POS)& ACMP_ACMP0NS_MASK)|				\
											((PRE_ACMP_ACMP0NS<< ACMP_ACMP0NS_POS)& ACMP_ACMP0NS_MASK))
#define PRE_ACMP0CR4_DEFAULT			(((PRE_ACMP_ACMP0OINV<< ACMP_ACMP0OINV_POS)& ACMP_ACMP0OINV_MASK)|			\
											((PRE_ACMP_ACMP0OFLTS<< ACMP_ACMP0OFLTS_POS)& ACMP_ACMP0OFLTS_MASK)|	\
											((PRE_ACMP_HYSEN0<< ACMP_HYSEN0_POS)& ACMP_HYSEN0_MASK)|				\
											((PRE_ACMP_ACMP0IE<< ACMP_ACMP0IE_POS)& ACMP_ACMP0IE_MASK)|				\
											((PRE_ACMP_ACMP0EN<< ACMP_ACMP0EN_POS)& ACMP_ACMP0EN_MASK))
/**@}*/ /*** end of name acmp0_reg_default */

/** 
 * @name acmp1_reg_default
 * @par 示例
 * @code
 *		void test( void )
 *		{
 *			ACMP1CR1= PRE_ACMP1CR1_DEFAULT;
 *			ACMP1CR2= PRE_ACMP1CR2_DEFAULT;
 *			ACMP1CR3= PRE_ACMP1CR3_DEFAULT;
 *			ACMP1CR4= PRE_ACMP1CR4_DEFAULT;
 *		}
 * @endcode
 * @{
 */
#define PRE_ACMP1CR1_DEFAULT			(((PRE_ACMP_CAL_CNT1<< ACMP_CAL_CNT1_POS)& ACMP_CAL_CNT1_MASK)|				\
											((PRE_ACMP_CALEN1<< ACMP_CALEN1_POS)& ACMP_CALEN1_MASK))
#define PRE_ACMP1CR2_DEFAULT			(((PRE_ACMP_INSHTEN1<< ACMP_INSHTEN1_POS)& ACMP_INSHTEN1_MASK)|				\
											((PRE_ACMP_WEN1<< ACMP_WEN1_POS)& ACMP_WEN1_MASK)|						\
											((PRE_ACMP_ACMP1OFT<< ACMP_ACMP1OFT_POS)& ACMP_ACMP1OFT_MASK))
#define PRE_ACMP1CR3_DEFAULT			(((PRE_ACMP_ACMP1PS<< ACMP_ACMP1NS_POS)& ACMP_ACMP1NS_MASK)|				\
											((PRE_ACMP_ACMP1NS<< ACMP_ACMP1NS_POS)& ACMP_ACMP1NS_MASK))
#define PRE_ACMP1CR4_DEFAULT			(((PRE_ACMP_ACMP1OINV<< ACMP_ACMP1OINV_POS)& ACMP_ACMP1OINV_MASK)|			\
											((PRE_ACMP_ACMP1OFLTS<< ACMP_ACMP1OFLTS_POS)& ACMP_ACMP1OFLTS_MASK)|	\
											((PRE_ACMP_HYSEN1<< ACMP_HYSEN1_POS)& ACMP_HYSEN1_MASK)|				\
											((PRE_ACMP_ACMP1IE<< ACMP_ACMP1IE_POS)& ACMP_ACMP1IE_MASK)|				\
											((PRE_ACMP_ACMP1EN<< ACMP_ACMP1EN_POS)& ACMP_ACMP1EN_MASK))
/**@}*/ /*** end of name acmp1_reg_default */
/**@}*/ /*** end of group acmp_reg_default */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup acmp_api	api
 * @{
 */
/** 
 * @name acmp0_api
 * @{
 */
/**
 * @brief 	<b>Description:</b> acmp 0 initialization.
 * @details <b>Function prototype:</b> void acmp0_init(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp0_init();
 *		}
 * @endcode
 */
void acmp0_init(void);

/**
 * @brief 	<b>Description:</b> acmp 0 disable.
 * @details <b>Function prototype:</b> void acmp0_disable(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp0_disable();
 *		}
 * @endcode
 */
void acmp0_disable(void);

/**
 * @brief 	<b>Description:</b> acmp 0 enable.
 * @details <b>Function prototype:</b> void acmp0_enable(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp0_enable();
 *		}
 * @endcode
 */
void acmp0_enable(void);

/**
 * @brief 	<b>Description:</b> acmp 0 interrupt disable.
 * @details <b>Function prototype:</b> void acmp0_interrupt_disable(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp0_interrupt_disable();
 *		}
 * @endcode
 */
void acmp0_interrupt_disable(void);

/**
 * @brief 	<b>Description:</b> acmp 0 interrupt enable.
 * @details <b>Function prototype:</b> void acmp0_interrupt_enable(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp0_interrupt_enable();
 *		}
 * @endcode
 */
void acmp0_interrupt_enable(void);

/**
 * @brief 	<b>Description:</b> get acmp 0 result.
 * @details <b>Function prototype:</b> bool acmp0_get_result(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			bool acmp0_output;
 * 			acmp0_output= acmp0_get_result();
 *		}
 * @endcode
 */
bool acmp0_get_result(void);

/**
 * @brief 	<b>Description:</b> get acmp 0 refresh.
 * @details <b>Function prototype:</b> bool acmp0_get_refresh(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			bool acmp0_refresh;
 * 			acmp0_refresh= acmp0_get_refresh();
 *		}
 * @endcode
 */
bool acmp0_get_refresh(void);

/**
 * @brief 	<b>Description:</b> clear acmp 0 refresh flag.
 * @details <b>Function prototype:</b> void acmp0_clear_refresh(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp0_clear_refresh();
 *		}
 * @endcode
 */
void acmp0_clear_refresh(void);
/**@}*/ /*** end of name acmp1_api */


/** 
 * @name acmp1_api
 * @{
 */
/**
 * @brief 	<b>Description:</b> acmp 1 initialization.
 * @details <b>Function prototype:</b> void acmp1_init(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp1_init();
 *		}
 * @endcode
 */
void acmp1_init(void);

/**
 * @brief 	<b>Description:</b> acmp 1 disable.
 * @details <b>Function prototype:</b> void acmp1_disable(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp1_disable();
 *		}
 * @endcode
 */
void acmp1_disable(void);

/**
 * @brief 	<b>Description:</b> acmp 1 enable.
 * @details <b>Function prototype:</b> void acmp1_enable(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp1_enable();
 *		}
 * @endcode
 */
void acmp1_enable(void);

/**
 * @brief 	<b>Description:</b> acmp 1 interrupt disable.
 * @details <b>Function prototype:</b> void acmp1_interrupt_disable(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp1_interrupt_disable();
 *		}
 * @endcode
 */
void acmp1_interrupt_disable(void);

/**
 * @brief 	<b>Description:</b> acmp 1 interrupt enable.
 * @details <b>Function prototype:</b> void acmp1_interrupt_enable(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp1_interrupt_enable();
 *		}
 * @endcode
 */
void acmp1_interrupt_enable(void);

/**
 * @brief 	<b>Description:</b> get acmp 1 result.
 * @details <b>Function prototype:</b> bool acmp1_get_result(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			bool acmp1_output;
 * 			acmp1_output= acmp1_get_result();
 *		}
 * @endcode
 */
bool acmp1_get_result(void);

/**
 * @brief 	<b>Description:</b> get acmp 1 refresh.
 * @details <b>Function prototype:</b> bool acmp1_get_refresh(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			bool acmp1_refresh;
 * 			acmp1_refresh= acmp1_get_refresh();
 *		}
 * @endcode
 */
bool acmp1_get_refresh(void);

/**
 * @brief 	<b>Description:</b> clear acmp 1 refresh flag.
 * @details <b>Function prototype:</b> void acmp1_clear_refresh(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp1_clear_refresh();
 *		}
 * @endcode
 */
void acmp1_clear_refresh(void);

/**@}*/ /*** end of name acmp1_api */
/**@}*/ /*** end of group acmp_api */
/**@}*/ /*** end of group csu39fx10_sdk_chip_fwlib_acmp */
/**@}*/ /*** end of group csu39fx10_sdk_chip_fwlib */
/**@}*/ /*** end of group csu39fx10_sdk_chip */
/*******************************************************************************/




#ifdef __cplusplus
}
#endif

#endif  //__CSU39FX10_ACMP_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/
