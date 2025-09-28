/***************************************************************************
 * @file     drv_adc.c
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

#ifndef __DRV_ADC_H__
#define __DRV_ADC_H__

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
 * @addtogroup csu39fx10_sdk_chip_driver_adc	adc 
 * @{
 */

/** 
 * @addtogroup	adc_reg_sradcon0	reg: SRADCON0 
 * @{
 */
//SRADCON0
//SRADACKS[1:0]
#define ADC_SRADACKS_REG						SRADCON0
#define ADC_SRADACKS_POS						(4)
#define ADC_SRADACKS_BITS						C_REG_BITS2
#define ADC_SRADACKS_16							(0x00<< ADC_SRADACKS_POS)
#define ADC_SRADACKS_8							(0x01<< ADC_SRADACKS_POS)
#define ADC_SRADACKS_4							(0x02<< ADC_SRADACKS_POS)
#define ADC_SRADACKS_2							(0x03<< ADC_SRADACKS_POS)
#define ADC_SRADACKS_MASK						(ADC_SRADACKS_BITS<< ADC_SRADACKS_POS)
#define __ADC_SRADACKS_GET()					M_REG_GET(ADC_SRADACKS_REG, ADC_SRADACKS_POS, ADC_SRADACKS_BITS)
#define __ADC_SRADACKS_SET(SET)					M_REG_SET(ADC_SRADACKS_REG, ADC_SRADACKS_POS, ADC_SRADACKS_BITS, SET)
#define __ADC_SRADACKS_GET_SHIFT()				M_REG_GET_SHIFT(ADC_SRADACKS_REG, ADC_SRADACKS_POS, ADC_SRADACKS_BITS)
#define __ADC_SRADACKS_SET_SHIFT(POS_SET)		M_REG_SET_SHIFT(ADC_SRADACKS_REG, ADC_SRADACKS_POS, ADC_SRADACKS_BITS, POS_SET)

//SRADIF
#define ADC_SRADIF_REG							SRADCON0
#define ADC_SRADIF_POS							(3)
#define ADC_SRADIF_BITS							C_REG_BITS1
#define ADC_SRADIF_CLR							(0x00<< ADC_SRADIF_POS)
#define ADC_SRADIF_UNINT						(0x00<< ADC_SRADIF_POS)
#define ADC_SRADIF_INT							(0x01<< ADC_SRADIF_POS)
#define ADC_SRADIF_MASK							(ADC_SRADIF_BITS<< ADC_SRADIF_POS)
#define __ADC_SRADIF_GET()						M_REG_GET(ADC_SRADIF_REG, ADC_SRADIF_POS, ADC_SRADIF_BITS)
#define __ADC_SRADIF_SET(CLR)					M_REG_SET(ADC_SRADIF_REG, ADC_SRADIF_POS, ADC_SRADIF_BITS, CLR)
#define __ADC_SRADIF_GET_SHIFT()				M_REG_GET_SHIFT(ADC_SRADIF_REG, ADC_SRADIF_POS, ADC_SRADIF_BITS)
#define __ADC_SRADIF_SET_SHIFT(POS_CLR)			M_REG_SET_SHIFT(ADC_SRADIF_REG, ADC_SRADIF_POS, ADC_SRADIF_BITS, POS_CLR)

//SRADIE
#define ADC_SRADIE_REG							SRADCON0
#define ADC_SRADIE_POS							(2)
#define ADC_SRADIE_BITS							C_REG_BITS1
#define ADC_SRADIE_DIS							(0x00<< ADC_SRADIE_POS)
#define ADC_SRADIE_EN							(0x01<< ADC_SRADIE_POS)
#define ADC_SRADIE_MASK							(ADC_SRADIE_BITS<< ADC_SRADIE_POS)
#define __ADC_SRADIE_GET()						M_REG_GET(ADC_SRADIE_REG, ADC_SRADIE_POS, ADC_SRADIE_BITS)
#define __ADC_SRADIE_SET(EN)					M_REG_SET(ADC_SRADIE_REG, ADC_SRADIE_POS, ADC_SRADIE_BITS, EN)
#define __ADC_SRADIE_GET_SHIFT()				M_REG_GET_SHIFT(ADC_SRADIE_REG, ADC_SRADIE_POS, ADC_SRADIE_BITS)
#define __ADC_SRADIE_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(ADC_SRADIE_REG, ADC_SRADIE_POS, ADC_SRADIE_BITS, POS_EN)

//SAR_DIFFEN
#define ADC_SAR_DIFFEN_REG						SRADCON0
#define ADC_SAR_DIFFEN_POS						(0)
#define ADC_SAR_DIFFEN_BITS						C_REG_BITS1
#define ADC_SAR_DIFFEN_SIN						(0x00<< ADC_SAR_DIFFEN_POS)
#define ADC_SAR_DIFFEN_DIF						(0x01<< ADC_SAR_DIFFEN_POS)
#define ADC_SAR_DIFFEN_MASK						(ADC_SAR_DIFFEN_BITS<< ADC_SAR_DIFFEN_POS)
#define __ADC_SAR_DIFFEN_GET()					M_REG_GET(ADC_SAR_DIFFEN_REG, ADC_SAR_DIFFEN_POS, ADC_SAR_DIFFEN_BITS)
#define __ADC_SAR_DIFFEN_SET(EN)				M_REG_SET(ADC_SAR_DIFFEN_REG, ADC_SAR_DIFFEN_POS, ADC_SAR_DIFFEN_BITS, EN)
#define __ADC_SAR_DIFFEN_GET_SHIFT()			M_REG_GET_SHIFT(ADC_SAR_DIFFEN_REG, ADC_SAR_DIFFEN_POS, ADC_SAR_DIFFEN_BITS)
#define __ADC_SAR_DIFFEN_SET_SHIFT(POS_EN)		M_REG_SET_SHIFT(ADC_SAR_DIFFEN_REG, ADC_SAR_DIFFEN_POS, ADC_SAR_DIFFEN_BITS, POS_EN)
/**@}*/ /*** end of group adc_reg_sradcon0 */

/** 
 * @addtogroup	adc_reg_sradcon1	reg: SRADCON1 
 * @{
 */
//SRADCON1
//SRADEN
#define ADC_SRADEN_REG							SRADCON1
#define ADC_SRADEN_POS							(7)
#define ADC_SRADEN_BITS							C_REG_BITS1
#define ADC_SRADEN_DIS							(0x00<< ADC_SRADEN_POS)
#define ADC_SRADEN_EN							(0x01<< ADC_SRADEN_POS)
#define ADC_SRADEN_MASK							(ADC_SRADEN_BITS<< ADC_SRADEN_POS)
#define __ADC_SRADEN_GET()						M_REG_GET(ADC_SRADEN_REG, ADC_SRADEN_POS, ADC_SRADEN_BITS)
#define __ADC_SRADEN_SET(EN)					M_REG_SET(ADC_SRADEN_REG, ADC_SRADEN_POS, ADC_SRADEN_BITS, EN)
#define __ADC_SRADEN_GET_SHIFT()				M_REG_GET_SHIFT(ADC_SRADEN_REG, ADC_SRADEN_POS, ADC_SRADEN_BITS)
#define __ADC_SRADEN_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(ADC_SRADEN_REG, ADC_SRADEN_POS, ADC_SRADEN_BITS, POS_EN)

//SRADS
#define ADC_SRADS_REG							SRADCON1
#define ADC_SRADS_POS							(6)
#define ADC_SRADS_BITS							C_REG_BITS1
#define ADC_SRADS_STOP							(0x00<< ADC_SRADS_POS)
#define ADC_SRADS_START							(0x01<< ADC_SRADS_POS)
#define ADC_SRADS_MASK							(ADC_SRADS_BITS<< ADC_SRADS_POS)
#define __ADC_SRADS_GET()						M_REG_GET(ADC_SRADS_REG, ADC_SRADS_POS, ADC_SRADS_BITS)
#define __ADC_SRADS_SET(SET)					M_REG_SET(ADC_SRADS_REG, ADC_SRADS_POS, ADC_SRADS_BITS, SET)
#define __ADC_SRADS_GET_SHIFT()					M_REG_GET_SHIFT(ADC_SRADS_REG, ADC_SRADS_POS, ADC_SRADS_BITS)
#define __ADC_SRADS_SET_SHIFT(POS_SET)			M_REG_SET_SHIFT(ADC_SRADS_REG, ADC_SRADS_POS, ADC_SRADS_BITS, POS_SET)

//OFTEN
#define ADC_OFTEN_REG							SRADCON1
#define ADC_OFTEN_POS							(5)
#define ADC_OFTEN_BITS							C_REG_BITS1
#define ADC_OFTEN_SRAD							(0x00<< ADC_OFTEN_POS)
#define ADC_OFTEN_SROFT							(0x01<< ADC_OFTEN_POS)
#define ADC_OFTEN_MASK							(ADC_OFTEN_BITS<< ADC_OFTEN_POS)
#define __ADC_OFTEN_GET()						M_REG_GET(ADC_OFTEN_REG, ADC_OFTEN_POS, ADC_OFTEN_BITS)
#define __ADC_OFTEN_SET(SET)					M_REG_SET(ADC_OFTEN_REG, ADC_OFTEN_POS, ADC_OFTEN_BITS, SET)
#define __ADC_OFTEN_GET_SHIFT()					M_REG_GET_SHIFT(ADC_OFTEN_REG, ADC_OFTEN_POS, ADC_OFTEN_BITS)
#define __ADC_OFTEN_SET_SHIFT(POS_SET)			M_REG_SET_SHIFT(ADC_OFTEN_REG, ADC_OFTEN_POS, ADC_OFTEN_BITS, POS_SET)

//CALIF
#define ADC_CALIF_REG							SRADCON1
#define ADC_CALIF_POS							(4)
#define ADC_CALIF_BITS							C_REG_BITS1
#define ADC_CALIF_DIS							(0x00<< ADC_CALIF_POS)
#define ADC_CALIF_EN							(0x01<< ADC_CALIF_POS)
#define ADC_CALIF_MASK							(ADC_CALIF_BITS<< ADC_CALIF_POS)
#define __ADC_CALIF_GET()						M_REG_GET(ADC_CALIF_REG, ADC_CALIF_POS, ADC_CALIF_BITS)
#define __ADC_CALIF_SET(EN)						M_REG_SET(ADC_CALIF_REG, ADC_CALIF_POS, ADC_CALIF_BITS, EN)
#define __ADC_CALIF_GET_SHIFT()					M_REG_GET_SHIFT(ADC_CALIF_REG, ADC_CALIF_POS, ADC_CALIF_BITS)
#define __ADC_CALIF_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(ADC_CALIF_REG, ADC_CALIF_POS, ADC_CALIF_BITS, POS_EN)

//ENOV
#define ADC_ENOV_REG							SRADCON1
#define ADC_ENOV_POS							(3)
#define ADC_ENOV_BITS							C_REG_BITS1
#define ADC_ENOV_DIS							(0x00<< ADC_ENOV_POS)
#define ADC_ENOV_EN								(0x01<< ADC_ENOV_POS)
#define ADC_ENOV_MASK							(ADC_ENOV_BITS<< ADC_ENOV_POS)
#define __ADC_ENOV_GET()						M_REG_GET(ADC_ENOV_REG, ADC_ENOV_POS, ADC_ENOV_BITS)
#define __ADC_ENOV_SET(EN)						M_REG_SET(ADC_ENOV_REG, ADC_ENOV_POS, ADC_ENOV_BITS, EN)
#define __ADC_ENOV_GET_SHIFT()					M_REG_GET_SHIFT(ADC_ENOV_REG, ADC_ENOV_POS, ADC_ENOV_BITS)
#define __ADC_ENOV_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(ADC_ENOV_REG, ADC_ENOV_POS, ADC_ENOV_BITS, POS_EN)

//OFFEX
#define ADC_OFFEX_REG							SRADCON1
#define ADC_OFFEX_POS							(0)
#define ADC_OFFEX_BITS							C_REG_BITS1
#define ADC_OFFEX_DIS							(0x00<< ADC_OFFEX_POS)
#define ADC_OFFEX_EN							(0x01<< ADC_OFFEX_POS)
#define ADC_OFFEX_MASK							(ADC_OFFEX_BITS<< ADC_OFFEX_POS)
#define __ADC_OFFEX_GET()						M_REG_GET(ADC_OFFEX_REG, ADC_OFFEX_POS, ADC_OFFEX_BITS)
#define __ADC_OFFEX_SET(EN)						M_REG_SET(ADC_OFFEX_REG, ADC_OFFEX_POS, ADC_OFFEX_BITS, EN)
#define __ADC_OFFEX_GET_SHIFT()					M_REG_GET_SHIFT(ADC_OFFEX_REG, ADC_OFFEX_POS, ADC_OFFEX_BITS)
#define __ADC_OFFEX_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(ADC_OFFEX_REG, ADC_OFFEX_POS, ADC_OFFEX_BITS, POS_EN)
/**@}*/ /*** end of group adc_reg_sradcon1 */

/** 
 * @addtogroup	adc_reg_sradcon2	reg: SRADCON2 
 * @{
 */
//SRADCON2
//CHS
#define ADC_CHS_REG								SRADCON2
#define ADC_CHS_POS								(3)
#define ADC_CHS_BITS							C_REG_BITS5
#define ADC_CHS_AIN11_AIN12						(0x00<< ADC_CHS_POS)
#define ADC_CHS_AIN13_AIN14						(0x01<< ADC_CHS_POS)
#define ADC_CHS_AIN15_AIN16						(0x02<< ADC_CHS_POS)
#define ADC_CHS_AIN0_VSSA						(0x03<< ADC_CHS_POS)
#define ADC_CHS_AIN1_VSSA						(0x04<< ADC_CHS_POS)
#define ADC_CHS_AIN2_VSSA						(0x05<< ADC_CHS_POS)
#define ADC_CHS_AIN3_VSSA						(0x06<< ADC_CHS_POS)
#define ADC_CHS_AIN4_VSSA						(0x07<< ADC_CHS_POS)
#define ADC_CHS_AIN5_VSSA						(0x08<< ADC_CHS_POS)
#define ADC_CHS_AIN6_VSSA						(0x09<< ADC_CHS_POS)
#define ADC_CHS_AIN7_VSSA						(0x0A<< ADC_CHS_POS)
#define ADC_CHS_AIN8_VSSA						(0x0B<< ADC_CHS_POS)
#define ADC_CHS_AIN9_VSSA						(0x0C<< ADC_CHS_POS)
#define ADC_CHS_AIN10_VSSA						(0x0D<< ADC_CHS_POS)
#define ADC_CHS_AIN11_VSSA						(0x0E<< ADC_CHS_POS)
#define ADC_CHS_AIN12_VSSA						(0x0F<< ADC_CHS_POS)
#define ADC_CHS_AIN13_VSSA						(0x10<< ADC_CHS_POS)
#define ADC_CHS_AIN14_VSSA						(0x11<< ADC_CHS_POS)
#define ADC_CHS_AIN15_VSSA						(0x12<< ADC_CHS_POS)
#define ADC_CHS_AIN16_VSSA						(0x13<< ADC_CHS_POS)
#define ADC_CHS_VDD_VSSA						(0x14<< ADC_CHS_POS)
#define ADC_CHS_VREF_VSSA						(0x18<< ADC_CHS_POS)
#define ADC_CHS_GND_VSSA						(0x1C<< ADC_CHS_POS)
#define ADC_CHS_AIN0							(0x00<< ADC_CHS_POS)
#define ADC_CHS_AIN1							(0x01<< ADC_CHS_POS)
#define ADC_CHS_AIN2							(0x02<< ADC_CHS_POS)
#define ADC_CHS_AIN3							(0x03<< ADC_CHS_POS)
#define ADC_CHS_AIN4							(0x04<< ADC_CHS_POS)
#define ADC_CHS_AIN5							(0x05<< ADC_CHS_POS)
#define ADC_CHS_AIN6							(0x06<< ADC_CHS_POS)
#define ADC_CHS_AIN7							(0x07<< ADC_CHS_POS)
#define ADC_CHS_AIN8							(0x08<< ADC_CHS_POS)
#define ADC_CHS_AIN9							(0x09<< ADC_CHS_POS)
#define ADC_CHS_AIN10							(0x0A<< ADC_CHS_POS)
#define ADC_CHS_AIN11							(0x0B<< ADC_CHS_POS)
#define ADC_CHS_AIN12							(0x0C<< ADC_CHS_POS)
#define ADC_CHS_AIN13							(0x0D<< ADC_CHS_POS)
#define ADC_CHS_AIN14							(0x0E<< ADC_CHS_POS)
#define ADC_CHS_AIN15							(0x0F<< ADC_CHS_POS)
#define ADC_CHS_AIN16							(0x10<< ADC_CHS_POS)
#define ADC_CHS_VDD_DIV8						(0x14<< ADC_CHS_POS)
#define ADC_CHS_VREF							(0x18<< ADC_CHS_POS)
#define ADC_CHS_AGND							(0x1C<< ADC_CHS_POS)
#define ADC_CHS_MASK							(ADC_CHS_BITS<< ADC_CHS_POS)
#define __ADC_CHS_GET()							M_REG_GET(ADC_CHS_REG, ADC_CHS_POS, ADC_CHS_BITS)
#define __ADC_CHS_SET(CHL)						M_REG_SET(ADC_CHS_REG, ADC_CHS_POS, ADC_CHS_BITS, CHL)
#define __ADC_CHS_GET_SHIFT()					M_REG_GET_SHIFT(ADC_CHS_REG, ADC_CHS_POS, ADC_CHS_BITS)
#define __ADC_CHS_SET_SHIFT(POS_CHL)			M_REG_SET_SHIFT(ADC_CHS_REG, ADC_CHS_POS, ADC_CHS_BITS, POS_CHL)

//VREFS[2:0]
#define ADC_VREFS_REG							SRADCON2
#define ADC_VREFS_POS							(0)
#define ADC_VREFS_BITS							C_REG_BITS3
#define ADC_VREFS_VDD							(0x00<< ADC_VREFS_POS)
#define ADC_VREFS_PT30IN						(0x02<< ADC_VREFS_POS)
#define ADC_VREFS_1V0							(0x04<< ADC_VREFS_POS)
#define ADC_VREFS_2V5							(0x05<< ADC_VREFS_POS)
#define ADC_VREFS_1V0_PT30OUT					(0x06<< ADC_VREFS_POS)
#define ADC_VREFS_2V5_PT30OUT					(0x07<< ADC_VREFS_POS)
#define ADC_VREFS_MASK							(ADC_VREFS_BITS<< ADC_VREFS_POS)
#define __ADC_VREFS_GET()						M_REG_GET(ADC_VREFS_REG, ADC_VREFS_POS, ADC_VREFS_BITS)
#define __ADC_VREFS_SET(SET)					M_REG_SET(ADC_VREFS_REG, ADC_VREFS_POS, ADC_VREFS_BITS, SET)
#define __ADC_VREFS_GET_SHIFT()					M_REG_GET_SHIFT(ADC_VREFS_REG, ADC_VREFS_POS, ADC_VREFS_BITS)
#define __ADC_VREFS_SET_SHIFT(POS_SET)			M_REG_SET_SHIFT(ADC_VREFS_REG, ADC_VREFS_POS, ADC_VREFS_BITS, POS_SET)
/**@}*/ /*** end of group adc_reg_sradcon2 */

/** 
 * @addtogroup	adc_reg_sradl	reg: SRADL 
 * @attention <b>READ-ONLY</b>
 * @{
 */
//SRADL, READ-ONLY
//SRAD[7:0]
#define ADC_SRADL_REG							SRADL
#define ADC_SRADL_POS							(0)
#define ADC_SRADL_VAL
#define ADC_SRADL_MASK							(0xFF<< SRAD_SRADL_POS)
#define __ADC_SRADL_GET()						M_REG_GETBYTE(SRAD_SRADL_REG, SRAD_SRADL_POS)
#define __ADC_SRADL_GET_SHIFT()					M_REG_GETBYTE_SHIFT(SRAD_SRADL_REG, SRAD_SRADL_POS)
/**@}*/ /*** end of group adc_reg_sradl */

/** 
 * @addtogroup	adc_reg_sradh	reg: SRADH 
 * @attention <b>READ-ONLY</b>
 * @{
 */
//SRADH, READ-ONLY
//SRAD[11:8]
#define ADC_SRADH_REG							SRADH
#define ADC_SRADH_POS							(0)
#define ADC_SRADH_VAL
#define ADC_SRADH_MASK							(0x0F<< SRAD_SRADH_POS)
#define __ADC_SRADH_GET()						M_REG_GETBYTE(SRAD_SRADH_REG, SRAD_SRADH_POS)
#define __ADC_SRADH_GET_SHIFT()					M_REG_GETBYTE_SHIFT(SRAD_SRADH_REG, SRAD_SRADH_POS)
/**@}*/ /*** end of group adc_reg_sradh */

/** 
 * @addtogroup	adc_reg_sroftl	reg: SROFTL 
 * @{
 */
//SROFTL
//SROFT[7:0]
#define ADC_SROFTL_REG							SROFTL
#define ADC_SROFTL_POS							(0)
#define ADC_SROFTL_VAL
#define ADC_SROFTL_MASK							(0xFF<< ADC_SROFTL_POS)
#define __ADC_SROFTL_GET()						M_REG_GETBYTE(ADC_SROFTL_REG, ADC_SROFTL_POS)
#define __ADC_SROFTL_SET(SET)					M_REG_GETBYTE(ADC_SROFTL_REG, ADC_SROFTL_POS, SET)
#define __ADC_SROFTL_GET_SHIFT()				M_REG_GETBYTE_SHIFT(ADC_SROFTL_REG, ADC_SROFTL_POS)
#define __ADC_SROFTL_SET_SHIFT(POS_SET)			M_REG_GETBYTE_SHIFT(ADC_SROFTL_REG, ADC_SROFTL_POS, POS_SET)
/**@}*/ /*** end of group adc_reg_sroftl */

/** 
 * @addtogroup	adc_reg_sroftl	reg: SROFTL 
 * @{
 */
//SROFTL
//SROFT[11:8]
#define ADC_SROFTH_REG							SROFTH
#define ADC_SROFTH_POS							(0)
#define ADC_SROFTH_VAL
#define ADC_SROFTH_MASK							(0x0F<< ADC_SROFTH_POS)
#define __ADC_SROFTH_GET()						M_REG_GETBYTE(ADC_SROFTH_REG, ADC_SROFTH_POS)
#define __ADC_SROFTH_SET(SET)					M_REG_GETBYTE(ADC_SROFTH_REG, ADC_SROFTH_POS, SET)
#define __ADC_SROFTH_GET_SHIFT()				M_REG_GETBYTE_SHIFT(ADC_SROFTH_REG, ADC_SROFTH_POS)
#define __ADC_SROFTH_SET_SHIFT(POS_SET)			M_REG_GETBYTE_SHIFT(ADC_SROFTH_REG, ADC_SROFTH_POS, POS_SET)
/**@}*/ /*** end of group adc_reg_sroftl */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup csu39fx10_sdk_chip_driver_adc_cfg	adc_config
 * @{
 */
/** 
 * @name input_channel_list
 * @{
 */
#define C_ADC_CHL_LIST									///< input_channel_list
#define C_ADC_CHL_AIN11_AIN12			(0x00)			
#define C_ADC_CHL_AIN13_AIN14	        (0x01)
#define C_ADC_CHL_AIN15_AIN16	        (0x02)
#define C_ADC_CHL_AIN0_VSSA	            (0x03)
#define C_ADC_CHL_AIN1_VSSA	            (0x04)
#define C_ADC_CHL_AIN2_VSSA	            (0x05)
#define C_ADC_CHL_AIN3_VSSA	            (0x06)
#define C_ADC_CHL_AIN4_VSSA	            (0x07)
#define C_ADC_CHL_AIN5_VSSA	            (0x08)
#define C_ADC_CHL_AIN6_VSSA	            (0x09)
#define C_ADC_CHL_AIN7_VSSA	            (0x0A)
#define C_ADC_CHL_AIN8_VSSA	            (0x0B)
#define C_ADC_CHL_AIN9_VSSA	            (0x0C)
#define C_ADC_CHL_AIN10_VSSA	        (0x0D)
#define C_ADC_CHL_AIN11_VSSA	        (0x0E)
#define C_ADC_CHL_AIN12_VSSA	        (0x0F)
#define C_ADC_CHL_AIN13_VSSA	        (0x10)
#define C_ADC_CHL_AIN14_VSSA	        (0x11)
#define C_ADC_CHL_AIN15_VSSA	        (0x12)
#define C_ADC_CHL_AIN16_VSSA	        (0x13)
#define C_ADC_CHL_VDD_DIV8_VSSA			(0x14)
#define C_ADC_CHL_VREF_VSSA	            (0x18)
#define C_ADC_CHL_GND_VSSA	            (0x1C)
#define C_ADC_CHL_AIN0					(0x00)
#define C_ADC_CHL_AIN1		            (0x01)
#define C_ADC_CHL_AIN2		            (0x02)
#define C_ADC_CHL_AIN3		            (0x03)
#define C_ADC_CHL_AIN4		            (0x04)
#define C_ADC_CHL_AIN5		            (0x05)
#define C_ADC_CHL_AIN6		            (0x06)
#define C_ADC_CHL_AIN7		            (0x07)
#define C_ADC_CHL_AIN8		            (0x08)
#define C_ADC_CHL_AIN9		            (0x09)
#define C_ADC_CHL_AIN10		            (0x0A)
#define C_ADC_CHL_AIN11		            (0x0B)
#define C_ADC_CHL_AIN12		            (0x0C)
#define C_ADC_CHL_AIN13		            (0x0D)
#define C_ADC_CHL_AIN14		            (0x0E)
#define C_ADC_CHL_AIN15		            (0x0F)
#define C_ADC_CHL_AIN16		            (0x10)
#define C_ADC_CHL_VDD_DIV8	            (0x14)
#define C_ADC_CHL_VREF		            (0x18)
#define C_ADC_CHL_AGND		            (0x1C)
/**@}*/ /*** end of name input_channel_list */


/** 
 * @name vref_list
 * @{
 */
#define C_ADC_VREF_VREFS_LIST							///< vref_list	
#define C_ADC_VREF_VREFS_VDD			(0x00)
#define C_ADC_VREF_VREFS_PT30IN			(0x02)
#define C_ADC_VREF_VREFS_1V0			(0x04)
#define C_ADC_VREF_VREFS_2V5			(0x05)
#define C_ADC_VREF_VREFS_1V0_PT30OUT	(0x06)
#define C_ADC_VREF_VREFS_2V5_PT30OUT	(0x07)
/**@}*/ /*** end of name vref_list */


/** 
 * @name adc_cfg
 * @{
 */
/**
 * @details <b>CFG_ADC_SRADACKS</b>
 * - <b>Features: </b> adc input signal sampling clock number selection signal
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| 16XADC_CLK	|
 * | 1		| 8XADC_CLK		|
 * | 2		| 4XADC_CLK		|
 * | 3		| 2XADC_CLK		|
 */
#define	CFG_ADC_SRADACKS				(0)		///< {0~ 3}

/**
 * @details <b>CFG_ADC_SRADIE</b>
 * - <b>Features: </b> adc interrupt enable configuration
 * - <b>Param: </b>
 * | config	| Descriptions			|
 * | :----:	| :----:				|
 * | 0*		| disable adc interrupt	|
 * | 1		| enable adc interrupt	|
 */
#define	CFG_ADC_SRADIE					(1)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_ADC_SAR_DIFFEN</b>
 * - <b>Features: </b> adc differential input configuration
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| single-ended	|
 * | 1		| differences	|
 */
#define	CFG_ADC_SAR_DIFFEN				(0)		///< 0-> single-ended, 1-> differences

/**
 * @details <b>CFG_ADC_SRADEN</b>
 * - <b>Features: </b> adc enable configuration
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| enable adc 	|
 * | 1		| disable adc 	|
 */
#define	CFG_ADC_SRADEN					(1)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_ADC_OFTEN</b>
 * - <b>Features: </b> adc conversion result storage location configuration
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| SRAD			|
 * | 1		| SROFT 		|
 */
#define	CFG_ADC_OFTEN					(0)		///< 0-> SRAD, 1-> SROFT

/**
 * @details <b>CFG_ADC_CALIF</b>
 * - <b>Features: </b> adc correction configuration, effective when CFG_ADC_OFTEN is 0
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| enable  		|
 * | 1		| disable  		|
 */
#define	CFG_ADC_CALIF					(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_ADC_ENOV</b>
 * - <b>Features: </b> adc enable comparator overflow mode configuration, effective when CFG_ADC_CALIF is 1
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| enable  		|
 * | 1		| disable  		|
 */
#define	CFG_ADC_ENOV					(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_ADC_OFFEX</b>
 * - <b>Features: </b> differential ADC positive and negative terminals are internally interchanged, effective when CFG_ADC_SAR_DIFFEN is 1
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0*		| enable  		|
 * | 1		| disable  		|
 */
#define	CFG_ADC_OFFEX					(0)		///< 0-> disable, 1-> enable

/**
 * @details <b>CFG_ADC_OFFEX</b>
 * - <b>Features: </b> adc input channel configuration
 * - <b>Param: </b> parameter list
 * | config	| Descriptions				| Remarks		|
 * | :----:	| :----:					| :----:		|
 * | (0x00)	| C_ADC_CHL_AIN11_AIN12		| differences	|
 * | (0x01)	| C_ADC_CHL_AIN13_AIN14		| differences	|
 * | (0x02)	| C_ADC_CHL_AIN15_AIN16		| differences	|
 * | (0x03)	| C_ADC_CHL_AIN0_VSSA		| differences	|
 * | (0x04)	| C_ADC_CHL_AIN1_VSSA		| differences	|
 * | (0x05)	| C_ADC_CHL_AIN2_VSSA		| differences	|
 * | (0x06)	| C_ADC_CHL_AIN3_VSSA		| differences	|
 * | (0x07)	| C_ADC_CHL_AIN4_VSSA		| differences	|
 * | (0x08)	| C_ADC_CHL_AIN5_VSSA		| differences	|
 * | (0x09)	| C_ADC_CHL_AIN6_VSSA		| differences	|
 * | (0x0A)	| C_ADC_CHL_AIN7_VSSA		| differences	|
 * | (0x0B)	| C_ADC_CHL_AIN8_VSSA		| differences	|
 * | (0x0C)	| C_ADC_CHL_AIN9_VSSA		| differences	|
 * | (0x0D)	| C_ADC_CHL_AIN10_VSSA		| differences	|
 * | (0x0E)	| C_ADC_CHL_AIN11_VSSA		| differences	|
 * | (0x0F)	| C_ADC_CHL_AIN12_VSSA		| differences	|
 * | (0x10)	| C_ADC_CHL_AIN13_VSSA		| differences	|
 * | (0x11)	| C_ADC_CHL_AIN14_VSSA		| differences	|
 * | (0x12)	| C_ADC_CHL_AIN15_VSSA		| differences	|
 * | (0x13)	| C_ADC_CHL_AIN16_VSSA		| differences	|
 * | (0x14)	| C_ADC_CHL_VDD_DIV8_VSSA	| differences	|
 * | (0x18)	| C_ADC_CHL_VREF_VSSA		| differences	|
 * | (0x1C)	| C_ADC_CHL_GND_VSSA		| differences	|
 * | --		| --						| --			|
 * | (0x00)	| C_ADC_CHL_AIN0			| single-ended	|
 * | (0x01)	| C_ADC_CHL_AIN1			| single-ended	|
 * | (0x02)	| C_ADC_CHL_AIN2			| single-ended	|
 * | (0x03)	| C_ADC_CHL_AIN3			| single-ended	|
 * | (0x04)	| C_ADC_CHL_AIN4			| single-ended	|
 * | (0x05)	| C_ADC_CHL_AIN5			| single-ended	|
 * | (0x06)	| C_ADC_CHL_AIN6			| single-ended	|
 * | (0x07)	| C_ADC_CHL_AIN7			| single-ended	|
 * | (0x08)	| C_ADC_CHL_AIN8			| single-ended	|
 * | (0x09)	| C_ADC_CHL_AIN9			| single-ended	|
 * | (0x0A)	| C_ADC_CHL_AIN10			| single-ended	|
 * | (0x0B)	| C_ADC_CHL_AIN11			| single-ended	|
 * | (0x0C)	| C_ADC_CHL_AIN12			| single-ended	|
 * | (0x0D)	| C_ADC_CHL_AIN13			| single-ended	|
 * | (0x0E)	| C_ADC_CHL_AIN14			| single-ended	|
 * | (0x0F)	| C_ADC_CHL_AIN15			| single-ended	|
 * | (0x10)	| C_ADC_CHL_AIN16			| single-ended	|
 * | (0x14)	| C_ADC_CHL_VDD_DIV8		| single-ended	|
 * | (0x18)	| C_ADC_CHL_VREF			| single-ended	|
 * | (0x1C)	| C_ADC_CHL_AGND			| single-ended	|
 */
#define	CFG_ADC_CHS						(C_ADC_CHL_AIN7)		///< {param: @ref C_ADC_CHL_LIST, @ref CFG_ADC_SAR_DIFFEN}

/**
 * @details <b>CFG_ADC_OFFEX</b>
 * - <b>Features: </b> adc input channel configuration
 * - <b>Param: </b> parameter list
 * | config	| Descriptions					| Remarks			|
 * | :----:	| :----:						| :----:			|
 * | 0x00	| C_ADC_VREF_VREFS_VDD  		| vdd				|
 * | 0x02	| C_ADC_VREF_VREFS_PT30IN		| input-pt30		|
 * | 0x04	| C_ADC_VREF_VREFS_1V0			| 1.0V				|
 * | 0x05	| C_ADC_VREF_VREFS_2V5			| 2.5V				|
 * | 0x06	| C_ADC_VREF_VREFS_1V0_PT30OUT	| 1.0_output-pt30	|
 * | 0x07	| C_ADC_VREF_VREFS_2V5_PT30OUT	| 2.5_output-pt30	|
 */
#define	CFG_ADC_VREFS					(C_ADC_VREF_VREFS_1V0)		///< {param: @ref C_ADC_VREF_VREFS_LIST}
/**@}*/ /*** end of name adc_cfg */
/**@}*/ /*** end of group csu39fx10_sdk_chip_driver_adc_cfg */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup adc_compile	attention: users do not need to care
 * @attention <b>users do not need to care</b>
 * @{
 */
/** 
 * @name adc_compile_reg_sradcon0
 * @{
 */
//#if(CFG_ADC_SRADACKS!= 0)
//	#define PRE_ADC_SRADACKS			1
//#else
//	#define PRE_ADC_SRADACKS			0
//#endif

#define PRE_ADC_SRADACKS			3



#if(CFG_ADC_SRADIE!= 0)
	#define PRE_ADC_SRADIE				1
#else
	#define PRE_ADC_SRADIE				0
#endif

#if(CFGCFG_ADC_SAR_DIFFEN!= 0)
	#define PRE_ADC_SAR_DIFFEN			1
#else
	#define PRE_ADC_SAR_DIFFEN			0
#endif
/**@}*/ /*** end of name adc_compile_reg_sradcon0 */

/** 
 * @name adc_compile_reg_sradcon1
 * @{
 */
#if(CFG_ADC_SRADEN!= 0)
	#define PRE_ADC_SRADEN				1
#else
	#define PRE_ADC_SRADEN				0
#endif

#if(CFG_ADC_OFTEN!= 0)
	#define PRE_ADC_OFTEN				1
#else
	#define PRE_ADC_OFTEN				0
#endif

#if(CFG_ADC_CALIF!= 0)
	#define PRE_ADC_CALIF				1
#else
	#define PRE_ADC_CALIF				0
#endif

#if(CFG_ADC_ENOV!= 0)
	#define PRE_ADC_ENOV				1
#else
	#define PRE_ADC_ENOV				0
#endif

#if(CFG_ADC_OFFEX!= 0)
	#define PRE_ADC_OFFEX				1
#else
	#define PRE_ADC_OFFEX				0
#endif	
/**@}*/ /*** end of name adc_compile_reg_sradcon1 */

/** 
 * @name adc_compile_reg_sradcon2
 * @{
 */
#define PRE_ADC_CHS						CFG_ADC_CHS
#define PRE_ADC_VREFS					CFG_ADC_VREFS
/**@}*/ /*** end of name adc_compile_reg_sradcon2 */

/** 
 * @name adc_compile_warning
 * @attention <b>compile warning message</b>
 * @{
 */
#if(((CFG_SYS_CLK_ADC_DIV== 0)&& (CFG_ADC_SRADACKS== 1))||		\
	((CFG_SYS_CLK_ADC_DIV== 0)&& (CFG_ADC_SRADACKS== 2))||		\
	((CFG_SYS_CLK_ADC_DIV== 0)&& (CFG_ADC_SRADACKS== 3))||		\
	((CFG_SYS_CLK_ADC_DIV== 1)&& (CFG_ADC_SRADACKS== 2))||		\
	((CFG_SYS_CLK_ADC_DIV== 1)&& (CFG_ADC_SRADACKS== 3))||		\
	((CFG_SYS_CLK_ADC_DIV== 10)&& (CFG_ADC_SRADACKS== 3)))
	#warning "Warning: CFG_SYS_CLK_ADC_DIV or CFG_ADC_SRADACKS define error, will be redefined!"
#endif
/**@}*/ /*** end of name adc_compile_warning */
/**@}*/ /*** end of group adc_compile */
/*******************************************************************************/




/******************************** dividing line ********************************/
/**
 * @addtogroup adc_reg_default	reg_default_value
 * @{
 */
/** 
 * @name adc_reg
 * @par 示例
 * @code
 *		void test( void )
 *		{
 *			SRADCON0= PRE_SRADCON0_DEFAULT;
 *			SRADCON1= PRE_SRADCON1_DEFAULT;
 *			SRADCON2= PRE_SRADCON2_DEFAULT;
 *		}
 * @endcode
 * @{
 */
#define PRE_SRADCON0_DEFAULT			(((PRE_ADC_SRADACKS<< ADC_SRADACKS_POS)& ADC_SRADACKS_MASK)|			\
											((PRE_ADC_SRADIE<< ADC_SRADIE_POS)& ADC_SRADIE_MASK)|				\
											((PRE_ADC_SAR_DIFFEN<< ADC_SAR_DIFFEN_POS)& ADC_SAR_DIFFEN_MASK))
#define PRE_SRADCON1_DEFAULT			(((PRE_ADC_SRADEN<< ADC_SRADEN_POS)& ADC_SRADEN_MASK)|					\
											((PRE_ADC_OFTEN<< ADC_OFTEN_POS)& ADC_OFTEN_MASK)|					\
											((PRE_ADC_CALIF<< ADC_CALIF_POS)& ADC_CALIF_MASK)|					\
											((PRE_ADC_ENOV<< ADC_ENOV_POS)& ADC_ENOV_MASK)|						\
											((PRE_ADC_OFFEX<< ADC_OFFEX_POS)& ADC_OFFEX_MASK))
#define PRE_SRADCON2_DEFAULT			(((PRE_ADC_CHS<< ADC_CHS_POS)& ADC_CHS_MASK)|							\
											((PRE_ADC_VREFS<< ADC_VREFS_POS)& ADC_VREFS_MASK))
/**@}*/ /*** end of name adc_reg */
/**@}*/ /*** end of group adc_reg_default */
/*******************************************************************************/

typedef enum
{
	CHL_ADC_CHL_AIN0			=(uint8_t)0x00,
	CHL_ADC_CHL_AIN1			=(uint8_t)0x01,
	CHL_ADC_CHL_AIN2			=(uint8_t)0x02,
	CHL_ADC_CHL_AIN3			=(uint8_t)0x03,
	CHL_ADC_CHL_AIN4			=(uint8_t)0x04,
	CHL_ADC_CHL_AIN5			=(uint8_t)0x05,
	CHL_ADC_CHL_AIN6			=(uint8_t)0x06,
	CHL_ADC_CHL_AIN7			=(uint8_t)0x07,
	CHL_ADC_CHL_AIN8			=(uint8_t)0x08,
	CHL_ADC_CHL_AIN9			=(uint8_t)0x09,
	CHL_ADC_CHL_AIN10			=(uint8_t)0x0A,
	CHL_ADC_CHL_AIN11			=(uint8_t)0x0B,
	CHL_ADC_CHL_AIN12			=(uint8_t)0x0C,
	CHL_ADC_CHL_AIN13			=(uint8_t)0x0D,
	CHL_ADC_CHL_AIN14			=(uint8_t)0x0E,
	CHL_ADC_CHL_AIN15			=(uint8_t)0x0F,
	CHL_ADC_CHL_AIN16			=(uint8_t)0x10,
	CHL_ADC_CHL_VDD_DIV8		=(uint8_t)0x14,
	CHL_ADC_CHL_VREF			=(uint8_t)0x18,
	CHL_ADC_CHL_AGND			=(uint8_t)0x1C,
}adc_sing_chl_t;

typedef enum
{
	CHL_ADC_CHL_AIN11_AIN12		=(uint8_t)0x00,
	CHL_ADC_CHL_AIN13_AIN14		=(uint8_t)0x01,
	CHL_ADC_CHL_AIN15_AIN16		=(uint8_t)0x02,
	CHL_ADC_CHL_AIN0_VSSA		=(uint8_t)0x03,
	CHL_ADC_CHL_AIN1_VSSA		=(uint8_t)0x04,
	CHL_ADC_CHL_AIN2_VSSA		=(uint8_t)0x05,
	CHL_ADC_CHL_AIN3_VSSA		=(uint8_t)0x06,
	CHL_ADC_CHL_AIN4_VSSA		=(uint8_t)0x07,
	CHL_ADC_CHL_AIN5_VSSA		=(uint8_t)0x08,
	CHL_ADC_CHL_AIN6_VSSA		=(uint8_t)0x09,
	CHL_ADC_CHL_AIN7_VSSA		=(uint8_t)0x0A,
	CHL_ADC_CHL_AIN8_VSSA		=(uint8_t)0x0B,
	CHL_ADC_CHL_AIN9_VSSA		=(uint8_t)0x0C,
	CHL_ADC_CHL_AIN10_VSSA		=(uint8_t)0x0D,
	CHL_ADC_CHL_AIN11_VSSA		=(uint8_t)0x0E,
	CHL_ADC_CHL_AIN12_VSSA		=(uint8_t)0x0F,
	CHL_ADC_CHL_AIN13_VSSA		=(uint8_t)0x10,
	CHL_ADC_CHL_AIN14_VSSA		=(uint8_t)0x11,
	CHL_ADC_CHL_AIN15_VSSA		=(uint8_t)0x12,
	CHL_ADC_CHL_AIN16_VSSA		=(uint8_t)0x13,
	CHL_ADC_CHL_VDD_DIV8_VSSA	=(uint8_t)0x14,
	CHL_ADC_CHL_VREF_VSSA		=(uint8_t)0x18,
	CHL_ADC_CHL_GND_VSSA		=(uint8_t)0x1C,
}adc_diff_chl_t;
	 

typedef enum
{
	VREFS_VDD  					=(uint8_t)0x00,
	VREFS_PT30IN				=(uint8_t)0x02,
	VREFS_1V0					=(uint8_t)0x04,
	VREFS_2V5					=(uint8_t)0x05,
	VREFS_1V0_PT30OUT			=(uint8_t)0x06,
	VREFS_2V5_PT30OUT			=(uint8_t)0x07,
}adc_vref_t;
	 



/******************************** dividing line ********************************/
/** 
 * @addtogroup adc_api	api
 * @{
 */
/** 
 * @name adc_api
 * @{
 */
/**
 * @brief 	<b>Description:</b> adc initialization.
 * @details <b>Function prototype:</b> void adc_init(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			adc_init();
 *		}
 * @endcode
 */
void adc_init(void);

/**
 * @brief 	<b>Description:</b> adc disable.
 * @details <b>Function prototype:</b> void adc_disable(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			adc_disable();
 *		}
 * @endcode
 */
void adc_disable(void);

/**
 * @brief 	<b>Description:</b> adc enable.
 * @details <b>Function prototype:</b> void adc_enable(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			adc_enable();
 *		}
 * @endcode
 */
void adc_enable(void);

/**
 * @brief 	<b>Description:</b> adc stop.
 * @details <b>Function prototype:</b> void adc_stop(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			adc_stop();
 *		}
 * @endcode
 */
void adc_stop(void);

/**
 * @brief 	<b>Description:</b> adc start.
 * @details <b>Function prototype:</b> void adc_start(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			adc_start();
 *		}
 * @endcode
 */
void adc_start(void);

/**
 * @brief 	<b>Description:</b> adc interrupt disable.
 * @details <b>Function prototype:</b> void adc_interrupt_disable(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			adc_interrupt_disable();
 *		}
 * @endcode
 */
void adc_interrupt_disable(void);

/**
 * @brief 	<b>Description:</b> adc interrupt enable.
 * @details <b>Function prototype:</b> void adc_interrupt_enable(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			adc_interrupt_enable();
 *		}
 * @endcode
 */
void adc_interrupt_enable(void);


void adc_set_sing_channel(adc_sing_chl_t _chl);
void adc_set_diff_channel(adc_diff_chl_t _chl);
void adc_set_vref(adc_vref_t _vrefs);



/**
 * @brief 	<b>Description:</b> adc get.
 * @details <b>Function prototype:</b> uint16_t adc_get_srad(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  uint16_t srad_data
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			uint16_t adc_code;
 * 			adc_code= adc_get_srad();
 *		}
 * @endcode
 */
uint16_t adc_get_srad(void);

/**
 * @brief 	<b>Description:</b> adc get sroft.
 * @details <b>Function prototype:</b> uint16_t adc_get_sroft(void);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  uint16_t srad_data
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			uint16_t adc_sroft;
 * 			adc_sroft= adc_get_sroft();
 *		}
 * @endcode
 */
uint16_t adc_get_sroft(void);

/**@}*/ /*** end of name adc_api */
/**@}*/ /*** end of group adc_api */
/**@}*/ /*** end of group csu39fx10_sdk_chip_driver_adc */
/**@}*/ /*** end of group csu39fx10_sdk_chip_driver */
/**@}*/ /*** end of group csu39fx10_sdk_chip */
/*******************************************************************************/




#ifdef __cplusplus
}
#endif

#endif  //__DRV_ADC_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/
