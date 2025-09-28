/***************************************************************************
 * @file     drv_flash.h
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

#ifndef __DRV_FLASH_H__
#define __DRV_FLASH_H__

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
 * @addtogroup csu39fx10_sdk_chip_driver_flash	flash 
 * @{
 */

/** 
 * @addtogroup	flash_reg_eadrh	reg: EADRH 
 * @{
 */
//EADRH
//EADR[15:8]
#define FLASH_EADRH_REG							EADRH
#define FLASH_EADRH_POS							(0)
#define FLASH_EADRH_VAL
#define FLASH_EADRH_MASK						(0xFF<< FLASH_EADRH_POS)
#define __FLASH_EADRH_GET()						M_REG_GETBYTE(FLASH_EADRH_REG, FLASH_EADRH_POS)
#define __FLASH_EADRH_SET(SET)					M_REG_SETBYTE(FLASH_EADRH_REG, FLASH_EADRH_POS, SET)
#define __FLASH_EADRH_GET_SHIFT()				M_REG_GETBYTE_SHIFT(FLASH_EADRH_REG, FLASH_EADRH_POS)
#define __FLASH_EADRH_SET_SHIFT(POS_SET)		M_REG_SETBYTE_SHIFT(FLASH_EADRH_REG, FLASH_EADRH_POS, POS_SET)
/**@}*/ /*** end of group flash_reg_eadrh */

/** 
 * @addtogroup	flash_reg_eadrl	reg: EADRL 
 * @{
 */
//EADRL
//EADR[7:0]
#define FLASH_EADRL_REG							EADRL
#define FLASH_EADRL_POS							(0)
#define FLASH_EADRL_VAL
#define FLASH_EADRL_MASK						(0xFF<< FLASH_EADRL_POS)
#define __FLASH_EADRL_GET()						M_REG_GETBYTE(FLASH_EADRL_REG, FLASH_EADRL_POS)
#define __FLASH_EADRL_SET(SET)					M_REG_SETBYTE(FLASH_EADRL_REG, FLASH_EADRL_POS, SET)
#define __FLASH_EADRL_GET_SHIFT()				M_REG_GETBYTE_SHIFT(FLASH_EADRL_REG, FLASH_EADRL_POS)
#define __FLASH_EADRL_SET_SHIFT(POS_SET)		M_REG_SETBYTE_SHIFT(FLASH_EADRL_REG, FLASH_EADRL_POS, POS_SET)
/**@}*/ /*** end of group flash_reg_eadrl */

/** 
 * @addtogroup	flash_reg_edath	reg: EDATH 
 * @{
 */
//EDATH
//EDAT[15:8]
#define FLASH_EDATH_REG							EDATH
#define FLASH_EDATH_POS							(0)
#define FLASH_EDATH_VAL
#define FLASH_EDATH_MASK						(0xFF<< FLASH_EDATH_POS)
#define __FLASH_EDATH_GET()						M_REG_GETBYTE(FLASH_EDATH_REG, FLASH_EDATH_POS)
#define __FLASH_EDATH_SET(SET)					M_REG_SETBYTE(FLASH_EDATH_REG, FLASH_EDATH_POS, SET)
#define __FLASH_EDATH_GET_SHIFT()				M_REG_GETBYTE_SHIFT(FLASH_EDATH_REG, FLASH_EDATH_POS)
#define __FLASH_EDATH_SET_SHIFT(POS_SET)		M_REG_SETBYTE_SHIFT(FLASH_EDATH_REG, FLASH_EDATH_POS, POS_SET)
/**@}*/ /*** end of group flash_reg_edath */

/** 
 * @addtogroup	flash_reg_edatl	reg: EDATL 
 * @{
 */
//EDATL
//EDAT[7:0]
#define FLASH_EDATL_REG							EDATL
#define FLASH_EDATL_POS							(0)
#define FLASH_EDATL_VAL
#define FLASH_EDATL_MASK						(0xFF<< FLASH_EDATL_POS)
#define __FLASH_EDATL_GET()						M_REG_GETBYTE(FLASH_EDATL_REG, FLASH_EDATL_POS)
#define __FLASH_EDATL_SET(SET)					M_REG_SETBYTE(FLASH_EDATL_REG, FLASH_EDATL_POS, SET)
#define __FLASH_EDATL_GET_SHIFT()				M_REG_GETBYTE_SHIFT(FLASH_EDATL_REG, FLASH_EDATL_POS)
#define __FLASH_EDATL_SET_SHIFT(POS_SET)		M_REG_SETBYTE_SHIFT(FLASH_EDATL_REG, FLASH_EDATL_POS, POS_SET)
/**@}*/ /*** end of group flash_reg_edatl */

/** 
 * @addtogroup	flash_reg_ispcr	reg: ISPCR 
 * @{
 */
//ISPCR
//READM1
#define FLASH_READM1_REG						ISPCR
#define FLASH_READM1_POS						(7)
#define FLASH_READM1_BITS						C_REG_BITS1
#define FLASH_READM1_DIS						(0x00<< FLASH_READM1_POS)
#define FLASH_READM1_EN							(0x01<< FLASH_READM1_POS)
#define FLASH_READM1_MASK						(FLASH_READM1_BITS<< FLASH_READM1_POS)
#define __FLASH_READM1_GET()					M_REG_GET(FLASH_READM1_REG, FLASH_READM1_POS, FLASH_READM1_BITS)
#define __FLASH_READM1_SET(EN)					M_REG_SET(FLASH_READM1_REG, FLASH_READM1_POS, FLASH_READM1_BITS, EN)
#define __FLASH_READM1_GET_SHIFT()				M_REG_GET_SHIFT(FLASH_READM1_REG, FLASH_READM1_POS, FLASH_READM1_BITS)
#define __FLASH_READM1_SET_SHIFT(POS_EN)		M_REG_SET_SHIFT(FLASH_READM1_REG, FLASH_READM1_POS, FLASH_READM1_BITS, POS_EN)

//READM0
#define FLASH_READM0_REG						ISPCR
#define FLASH_READM0_POS						(6)
#define FLASH_READM0_BITS						C_REG_BITS1
#define FLASH_READM0_DIS						(0x00<< FLASH_READM0_POS)
#define FLASH_READM0_EN							(0x01<< FLASH_READM0_POS)
#define FLASH_READM0_MASK						(FLASH_READM0_BITS<< FLASH_READM0_POS)
#define __FLASH_READM0_GET()					M_REG_GET(FLASH_READM0_REG, FLASH_READM0_POS, FLASH_READM0_BITS)
#define __FLASH_READM0_SET(EN)					M_REG_SET(FLASH_READM0_REG, FLASH_READM0_POS, FLASH_READM0_BITS, EN)
#define __FLASH_READM0_GET_SHIFT()				M_REG_GET_SHIFT(FLASH_READM0_REG, FLASH_READM0_POS, FLASH_READM0_BITS)
#define __FLASH_READM0_SET_SHIFT(POS_EN)		M_REG_SET_SHIFT(FLASH_READM0_REG, FLASH_READM0_POS, FLASH_READM0_BITS, POS_EN)

//ISPEN
#define FLASH_ISPEN_REG							ISPCR
#define FLASH_ISPEN_POS							(5)
#define FLASH_ISPEN_BITS						C_REG_BITS1
#define FLASH_ISPEN_DIS							(0x00<< FLASH_ISPEN_POS)
#define FLASH_ISPEN_EN							(0x01<< FLASH_ISPEN_POS)
#define FLASH_ISPEN_MASK						(FLASH_ISPEN_BITS<< FLASH_ISPEN_POS)
#define __FLASH_ISPEN_GET()						M_REG_GET(FLASH_ISPEN_REG, FLASH_ISPEN_POS, FLASH_ISPEN_BITSS)
#define __FLASH_ISPEN_SET(EN)					M_REG_SET(FLASH_ISPEN_REG, FLASH_ISPEN_POS, FLASH_ISPEN_BITSS, EN)
#define __FLASH_ISPEN_GET_SHIFT()				M_REG_GET_SHIFT(FLASH_ISPEN_REG, FLASH_ISPEN_POS, FLASH_ISPEN_BITS)
#define __FLASH_ISPEN_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(FLASH_ISPEN_REG, FLASH_ISPEN_POS, FLASH_ISPEN_BITS, POS_EN)

//START
#define FLASH_START_REG							ISPCR
#define FLASH_START_POS							(0)
#define FLASH_START_BITS						C_REG_BITS1
#define FLASH_START_DIS							(0x00<< FLASH_START_POS)
#define FLASH_START_EN							(0x01<< FLASH_START_POS)
#define FLASH_START_MASK						(FLASH_START_BITS<< FLASH_START_POS)
#define __FLASH_START_GET()						M_REG_GET(FLASH_START_REG, FLASH_START_POS, FLASH_START_BITS)
#define __FLASH_START_SET(EN)					M_REG_SET(FLASH_START_REG, FLASH_START_POS, FLASH_START_BITS, EN)
#define __FLASH_START_GET_SHIFT()				M_REG_GET_SHIFT(FLASH_START_REG, FLASH_START_POS, FLASH_START_BITS)
#define __FLASH_START_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(FLASH_START_REG, FLASH_START_POS, FLASH_START_BITS, POS_EN)
/**@}*/ /*** end of group flash_reg_ispcr */

/** 
 * @addtogroup	flash_reg_cmd	reg: CMD 
 * @{
 */
//CMD
//CMD[7:0]
#define FLASH_CMD_REG							CMD
#define FLASH_CMD_POS							(0)
#define FLASH_CMD_RD							(0x00<< FLASH_CMD_POS)
#define FLASH_CMD_WR							(0x05<< FLASH_CMD_POS)
#define FLASH_CMD_ERA_SECTOR					(0x0A<< FLASH_CMD_POS)
#define FLASH_CMD_ERA_CHIP						(0xA0<< FLASH_CMD_POS)
#define FLASH_CMD_MARGIN_READ					(0x50<< FLASH_CMD_POS)
#define FLASH_CMD_MASK							(0xFF<< FLASH_CMD_POS)
#define __FLASH_CMD_GET()						M_REG_GETBYTE(FLASH_CMD_REG, FLASH_CMD_POS)
#define __FLASH_CMD_SET(SET)					M_REG_SETBYTE(FLASH_CMD_REG, FLASH_CMD_POS, SET)
#define __FLASH_CMD_GET_SHIFT()					M_REG_GETBYTE_SHIFT(FLASH_CMD_REG, FLASH_CMD_POS)
#define __FLASH_CMD_SET_SHIFT(POS_SET)			M_REG_SETBYTE_SHIFT(FLASH_CMD_REG, FLASH_CMD_POS, POS_SET)
/**@}*/ /*** end of group flash_reg_cmd */

/** 
 * @addtogroup	flash_reg_ispsr	reg: ISPSR 
 * @{
 */
//ISPSR
//UNLOCK
#define FLASH_UNLOCK_REG						ISPSR
#define FLASH_UNLOCK_POS						(3)
#define FLASH_UNLOCK_BITS						C_REG_BITS1
#define FLASH_UNLOCK_LOCK						(0x00<< FLASH_UNLOCK_POS)
#define FLASH_UNLOCK_UNLOCK						(0x01<< FLASH_UNLOCK_POS)
#define FLASH_UNLOCK_MASK						(FLASH_UNLOCK_BITS<< FLASH_UNLOCK_POS)
#define __FLASH_UNLOCK_GET()					M_REG_GET(FLASH_UNLOCK_REG, FLASH_UNLOCK_POS, FLASH_UNLOCK_BITS)
#define __FLASH_UNLOCK_GET_SHIFT()				M_REG_GET_SHIFT(FLASH_UNLOCK_REG, FLASH_UNLOCK_POS, FLASH_UNLOCK_BITS)

//PGERR
#define FLASH_PGERR_REG							ISPSR
#define FLASH_PGERR_POS							(2)
#define FLASH_PGERR_BITS						C_REG_BITS1
#define FLASH_PGERR_CLR							(0x00<< FLASH_PGERR_POS)
#define FLASH_PGERR_IS							(0x01<< FLASH_PGERR_POS)
#define FLASH_PGERR_MASK						(FLASH_PGERR_BITS<< FLASH_PGERR_POS)
#define __FLASH_PGERR_GET()						M_REG_GET(FLASH_PGERR_REG, FLASH_PGERR_POS, FLASH_PGERR_BITS)
#define __FLASH_PGERR_SET(CLR)					M_REG_SET(FLASH_PGERR_REG, FLASH_PGERR_POS, FLASH_PGERR_BITS, CLR)
#define __FLASH_PGERR_GET_SHIFT()				M_REG_GET_SHIFT(FLASH_PGERR_REG, FLASH_PGERR_POS, FLASH_PGERR_BITS)
#define __FLASH_PGERR_SET_SHIFT(POS_CLR)		M_REG_SET_SHIFT(FLASH_PGERR_REG, FLASH_PGERR_POS, FLASH_PGERR_BITS, POS_CLR)

//ISPOF
#define FLASH_ISPOF_REG							ISPSR
#define FLASH_ISPOF_POS							(1)
#define FLASH_ISPOF_BITS						C_REG_BITS1
#define FLASH_ISPOF_CLR							(0x00<< FLASH_ISPOF_POS)
#define FLASH_ISPOF_SUCCESS						(0x00<< FLASH_ISPOF_POS)
#define FLASH_ISPOF_FAIL						(0x01<< FLASH_ISPOF_POS)
#define FLASH_ISPOF_MASK						(FLASH_ISPOF_BITS<< FLASH_ISPOF_POS)
#define __FLASH_ISPOF_GET()						M_REG_GET(FLASH_ISPOF_REG, FLASH_ISPOF_POS, FLASH_ISPOF_BITS)
#define __FLASH_ISPOF_SET(CLR)					M_REG_SET(FLASH_ISPOF_REG, FLASH_ISPOF_POS, FLASH_ISPOF_BITS, CLR)
#define __FLASH_ISPOF_GET_SHIFT()				M_REG_GET_SHIFT(FLASH_ISPOF_REG, FLASH_ISPOF_POS, FLASH_ISPOF_BITS)
#define __FLASH_ISPOF_SET_SHIFT(POS_CLR)		M_REG_SET_SHIFT(FLASH_ISPOF_REG, FLASH_ISPOF_POS, FLASH_ISPOF_BITS, POS_CLR)

//BSY
#define FLASH_BSY_REG							ISPSR
#define FLASH_BSY_POS							(0)
#define FLASH_BSY_BITS							C_REG_BITS1
#define FLASH_BSY_RESET							(0x00<< FLASH_BSY_POS)
#define FLASH_BSY_SET							(0x01<< FLASH_BSY_POS)
#define FLASH_BSY_MASK							(FLASH_BSY_BITS<< FLASH_BSY_POS)
#define __FLASH_BSY_GET()						M_REG_GET(FLASH_BSY_REG, FLASH_BSY_POS, FLASH_BSY_BITS)
#define __FLASH_BSY_GET_SHIFT()					M_REG_GET_SHIFT(FLASH_BSY_REG, FLASH_BSY_POS, FLASH_BSY_BITS)
/**@}*/ /*** end of group flash_reg_ispsr */

/** 
 * @addtogroup	flash_reg_wrprt	reg: WRPRT 
 * @{
 */
//WRPRT
//WRPRT[7:0]
#define FLASH_WRPRT_REG							WRPRT
#define FLASH_WRPRT_POS							(0)
#define FLASH_WRPRT_VAL
#define FLASH_WRPRT_MASK						(0xFF<< FLASH_WRPRT_POS)
#define __FLASH_WRPRT_GET()						M_REG_GETBYTE(FLASH_WRPRT_REG, FLASH_WRPRT_POS)
#define __FLASH_WRPRT_SET(SET)					M_REG_SETBYTE(FLASH_WRPRT_REG, FLASH_WRPRT_POS, SET)
#define __FLASH_WRPRT_GET_SHIFT()				M_REG_GETBYTE_SHIFT(FLASH_WRPRT_REG, FLASH_WRPRT_POS)
#define __FLASH_WRPRT_SET_SHIFT(POS_SET)		M_REG_SETBYTE_SHIFT(FLASH_WRPRT_REG, FLASH_WRPRT_POS, POS_SET)
/**@}*/ /*** end of group flash_reg_wrprt */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup csu39fx10_sdk_chip_driver_flash_cfg	flash_config
 * @{
 */
/** 
 * @name flash config
 * @{
 */
/**
 * @details <b>C_FLASH_SECTOR_SIZE</b>
 * - <b>Features: </b> flash sector size configuration
 * @attention <b> </b> The physical sector size is 256 words, and the sram size limits the operable sector size to be less than 256.
 * - <b>Param: </b>
 * | config	| Descriptions		|
 * | :----:	| :----:			|
 * | 0~ 64	| sector size		|
 */
#define C_FLASH_SECTOR_SIZE					64
#define C_FLASH_SECTOR_SIZE_SHIFT			6
/**@}*/ /*** end of name flash config */
/**@}*/ /*** end of group csu39fx10_sdk_chip_driver_flash_cfg */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup flash_struct	struct
 * @{
 */
/**
 * @brief flash - register layout typedef
 */
typedef struct
{
	uint16_t cache[C_FLASH_SECTOR_SIZE];		//!< data buffer,	offset: 0x02
}_flash_t;

/**@}*/ /*** end of group flash_struct */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup flash_api	api
 * @details flash map
 * | Address partition	| EADR[15:0]	| flash address	|
 * | :----:				| :----:		| :----:		|
 * | Main program		| 0000h			| 0000h			|
 * |					| 0001h			| 0000h			|
 * |					| 0002h			| 0001h			|
 * |					| 0003h			| 0001h			|
 * | ....				| .... 			| ....			|
 * |					| 7ffeh			| 3fffh			|
 * | Main program		| 7fffh			| 3fffh			|
 * | NVR sector0		| f000h			| 0000h			|
 * |					| f001h			| 0000h			|
 * | ....				| .... 			| ....			|
 * |					| f0feh			| 007fh			|
 * | NVR sector0		| f0ffh			| 007fh			|
 * | NVR sector1		| f800h			| 0080h			|
 * |					| f801h			| 007fh			|
 * | ....				| .... 			| ....			|
 * |					| f8feh			| 00ffh			|
 * | NVR sector1		| f8ffh			| 00ffh			|
 * | NVR sector2		| fa00h			| 0100h			|
 * |					| fa01h			| 0100h			|
 * | ....				| .... 			| ....			|
 * |					| fafeh			| 017fh			|
 * | NVR sector2		| faffh			| 017fh			|
 * | NVR sector3		| fc00h			| 0180h			|
 * |					| fc01h			| 0180h			|
 * | ....				| .... 			| ....			|
 * |					| fcfeh			| 01ffh			|
 * | NVR sector3		| fcffh			| 01ffh			|
 * @{
 */
/** 
 * @name flash_api
 * @{
 */
/**
 * @brief 	<b>Description:</b> flash erase one sector(512Byte).
 * @details <b>Function prototype:</b> bool flash_erase(uint16_t _address);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  bool error:	true, false.
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			bool error;
 * 			error= flash_erase(0x7F00);
 *		}
 * @endcode
 */
bool flash_erase(uint16_t _address);

/**
 * @brief 	<b>Description:</b> flash read data.
 * @details <b>Function prototype:</b> bool flash_read(uint16_t _address, uint16_t *_data, uint8_t _length);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  bool error:	true, false.
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			bool error;
 * 			uint16_t data_buff[32];
 * 			error= flash_erase(0x7F00, (uint16_t *)data_buff, 32);
 *		}
 * @endcode
 */
bool flash_read(uint16_t _address, uint16_t *_data, uint8_t _length);

/**
 * @brief 	<b>Description:</b> flash write data.
 * @details <b>Function prototype:</b> bool flash_write(uint16_t _address, uint16_t *_data, uint8_t _length);
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  bool error:	true, false.
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			bool error;
 * 			uint16_t data;
 *			data= 0x55;
 * 			error= flash_erase(0x7F00, (uint16_t *)&data, 1);
 *		}
 * @endcode
 */
bool flash_write(uint16_t _address, uint16_t *_data, uint8_t _length);
/**@}*/ /*** end of name flash_api */
/**@}*/ /*** end of group flash_api */
/**@}*/ /*** end of group csu39fx10_sdk_chip_driver_flash */
/**@}*/ /*** end of group csu39fx10_sdk_chip_driver */
/**@}*/ /*** end of group csu39fx10_sdk_chip */
/*******************************************************************************/




/**
 * FLASH MAP
 *			 ___________________________________________________
 *			| Address partition	| EADR[15:0]	| flash address	|
 *			|___________________|_______________|_______________|
 *			| Main program		| 0000h			| 0000h			|
 *			|					|_0001h_________|_______________|
 *			|					| 0002h			| 0001h			|
 *			|					|_0003h_________|_______________|
 *			|					| .... 			| ....			|
 *			|					|_______________|_______________|
 *			|					| 7ffeh			| 3fffh			|
 *			|___________________|_7fffh_________|_______________|
 *			| NVR sector0		| f000h			| 0000h			|
 *			|					|_f001h_________|_______________|
 *			|					| .... 			| ....			|
 *			|					|_______________|_______________|
 *			|					| f0feh			| 007fh			|
 *			|___________________|_f0ffh_________|_______________|
 *			| NVR sector1		| f800h			| 0080h			|
 *			|					|_f801h_________|_______________|
 *			|					| .... 			| ....			|
 *			|					|_______________|_______________|
 *			|					| f8feh			| 00ffh			|
 *			|___________________|_f8ffh_________|_______________|
 *			| NVR sector2		| fa00h			| 0100h			|
 *			|					|_fa01h_________|_______________|
 *			|					| .... 			| ....			|
 *			|					|_______________|_______________|
 *			|					| fafeh			| 017fh			|
 *			|___________________|_faffh_________|_______________|
 *			| NVR sector3		| fc00h			| 0180h			|
 *			|					|_fc01h_________|_______________|
 *			|					| .... 			| ....			|
 *			|					|_______________|_______________|
 *			|					| fcfeh			| 01ffh			|
 *			|					| fcffh			|				|
 *			|___________________|_______________|_______________|
 *
**/


#ifdef __cplusplus
}
#endif

#endif  //__DRV_FLASH_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/
