/***************************************************************************
 * @file     drv_iic.h
 * @version  V1.0.0
 * @author   0531
 * @date     2020-10-19 PM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 ****************************************************************************
 * @par 头文件
 *       drv_gpio.h
 * @note <b>software simulation iic host</b>
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

#ifndef __DRV_IIC_H__
#define __DRV_IIC_H__

// Include external header file.
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
 * @addtogroup csu39fx10_sdk_chip_driver_iic	iic 
 * @{
 */

/** 
 * @addtogroup csu39fx10_sdk_chip_driver_iic_cfg	iic_config
 * @{
 */
/** 
 * @name iic config
 * @{
 */
/**
 * @details <b>CFG_SLAVE_ADDR</b>
 * - <b>Features: </b> iic slave address configuration
 * - <b>Param: </b>
 * | config	| Descriptions	|
 * | :----:	| :----:		|
 * | 0~ 127	| slave address	|
 */
//#define CFG_SLAVE_ADDR				(0x74)		///< {0~ 127}-SC8815
//#define CFG_SLAVE_ADDR				(0x6b)		///< {0~ 127}---SC8886
#define CFG_SLAVE_ADDR				(0x3C)		///< {0~ 127}---SW7203--7201

#define CFG_SLAVE_24C02_ADDR	  	(0x50)		///24C02 地址
/**
 * @details <b>CFG_PORT_SDA</b>
 * - <b>Features: </b> iic gpio port configuration
 * - <b>Param: </b>
 * | config		| Descriptions	|
 * | :----:		| :----:		|
 * | GPIO_PT10	| pt10			|
 * | ....		| ....			|
 * | GPIO_PT37	| pt37			|
 */
//#define CFG_PORT_SDA				GPIO_PT14
#define CFG_PORT_SDA				GPIO_PT16
/**
 * @details <b>CFG_PORT_SCL</b>
 * - <b>Features: </b> iic gpio port configuration
 * - <b>Param: </b>
 * | config		| Descriptions	|
 * | :----:		| :----:		|
 * | GPIO_PT10	| pt10			|
 * | ....		| ....			|
 * | GPIO_PT37	| pt37			|
 */
//#define CFG_PORT_SCL				GPIO_PT15
#define CFG_PORT_SCL				GPIO_PT17

#define BANK_IIC					 bank4
#define BANK_IIC_NUM				 BANK3
/**@}*/ /*** end of name iic config */
/**@}*/ /*** end of group csu39fx10_sdk_chip_driver_wdt_cfg */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup iic_compile	attention: users do not need to care
 * @attention <b>users do not need to care</b>
 * @{
 */
/** 
 * @name iic_compile_port
 * @{
 */
#define PRE_PORT_SDA				(CFG_PORT_SDA/ 8)
#define PRE_PIN_SDA					(CFG_PORT_SDA% 8)
#define PRE_PORT_SCL				(CFG_PORT_SCL/ 8)
#define PRE_PIN_SCL					(CFG_PORT_SCL% 8)

#if(PRE_PORT_SDA== 0)
	#define P_PORT_SDA				PT1
	#define P_PORTEN_SDA			PT1EN
	#define P_PIN_SDA				PRE_PIN_SDA
#elif(PRE_PORT_SDA== 1)
	#define P_PORT_SDA				PT2
	#define P_PORTEN_SDA			PT2EN
	#define P_PIN_SDA				PRE_PIN_SDA
#elif(PRE_PORT_SDA== 2)
	#define P_PORT_SDA				PT3
	#define P_PORTEN_SDA			PT3EN
	#define P_PIN_SDA				PRE_PIN_SDA
#endif

#if(PRE_PORT_SCL== 0)
	#define P_PORT_SCL				PT1
	#define P_PIN_SCL				PRE_PIN_SCL
#elif(PRE_PORT_SCL== 1)
	#define P_PORT_SCL				PT2
	#define P_PIN_SCL				PRE_PIN_SCL
#elif(PRE_PORT_SCL== 2)
	#define P_PORT_SCL				PT3
	#define P_PIN_SCL				PRE_PIN_SCL
#endif
/**@}*/ /*** end of name iic_compile_port */
/**@}*/ /*** end of group iic_compile */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup iic_macro_function	macro_function
 * @attention <b>functions used inside iic</b>
 * @{
 */
#define __IIC_SCL_H()						PTXOUT(P_PORT_SCL, P_PIN_SCL, 1)
#define __IIC_SCL_L()						PTXOUT(P_PORT_SCL, P_PIN_SCL, 0)

#define __IIC_SDA_H()						PTXOUT(P_PORT_SDA, P_PIN_SDA, 1)
#define __IIC_SDA_L()                       PTXOUT(P_PORT_SDA, P_PIN_SDA, 0)

#define __IIC_SDA_IN()                      PTXIN(P_PORT_SDA, P_PIN_SDA)

#define __IIC_SDA_DIR_IN()					PTX_DIR_IN(P_PORTEN_SDA, P_PIN_SDA)
#define __IIC_SDA_DIR_OUT()					PTX_DIR_OUT(P_PORTEN_SDA, P_PIN_SDA)


#define __IIC_DELAY()						do				\
											{				\
												asm("NOP");	\
												asm("NOP");	\
												asm("NOP");	\
											}while(0)	/** 400KHz**/
// #define __IIC_DELAY()						do				\
											// {				\
												// asm("NOP");	\
												// asm("NOP");	\
												// asm("NOP");	\
												// asm("NOP");	\
												// asm("NOP");	\
												// asm("NOP");	\
												// asm("NOP");	\
												// asm("NOP");	\
												// asm("NOP");	\
												// asm("NOP");	\
												// asm("NOP"); \
											// }while(0)	/** 270KHz**/

/**@}*/ /*** end of group iic_macro_function */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup iic_api	api
 * @{
 */
/** 
 * @name iic_api
 * @{
 */
/**
 * @brief 	<b>Description:</b> iic initialization.
 * @details <b>Function prototype:</b> void iic_init(void);
 * @param[in]  null	.
 * @param[out] null.
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			iic_init();
 *		}
 * @endcode
 */
void iic_init(void);
void iic_disable(void);

/**
 * @brief 	<b>Description:</b> iic write one byte data.
 * @details <b>Function prototype:</b> void iic_transmit_byte(uint8_t address, uint8_t data);
 * @param[in]  uint8_t address	reg address.
 * @param[in]  uint8_t data		data.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			iic_transmit_byte(0x01, 0xAA);
 *		}
 * @endcode
 */
void iic_transmit_byte(uint8_t address, BANK_IIC uint8_t data);

/**
 * @brief 	<b>Description:</b> iic write data.
 * @details <b>Function prototype:</b> void iic_transmit_bytes(uint8_t address, uint8_t * data_array, uint8_t length);
 * @param[in]  uint8_t address		reg address.
 * @param[in]  uint8_t *data_array	data_buffer.
 * @param[in]  uint8_t length		data_length.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			uint8_t data_array[8];
 *			data_array[0]= 0xA5;
 *			data_array[7]= 0x5A;
 * 			iic_transmit_bytes(0x01, data_array, 0x08);
 *		}
 * @endcode
 */
void iic_transmit_bytes(uint8_t address, BANK_IIC uint8_t *data_array, uint8_t length);
void iic_transmit_24C02_byte(uint8_t address, BANK_IIC uint8_t data);
/**
 * @brief 	<b>Description:</b> iic read one byte data.
 * @details <b>Function prototype:</b> uint8_t iic_receive_byte(uint8_t address);
 * @param[in]  uint8_t address	reg address.
 * @param[out] null .
 * 
 * @return  uint8_t u8value		read data.
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			uint8_t re_data;
 * 			re_data= iic_receive_byte(0x01);
 *		}
 * @endcode
 */
uint8_t iic_receive_byte(uint8_t address);
uint8_t iic_receive_24C02_byte(uint8_t address);
/**
 * @brief 	<b>Description:</b> iic read data.
 * @details <b>Function prototype:</b> void iic_receive_bytes(uint8_t address, uint8_t * data_array, uint8_t length);
 * @param[in]  uint8_t address		reg address.
 * @param[in]  uint8_t *data_array	data_buffer.
 * @param[in]  uint8_t length		data_length.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			uint8_t data_array[8];
 * 			iic_receive_bytes(0x01, data_array, 0x08);
 *		}
 * @endcode
 */
void iic_receive_bytes(uint8_t address, BANK_IIC uint8_t *data_array, uint8_t length);

/**@}*/ /*** end of name iic_api */
/**@}*/ /*** end of group iic_api */
/**@}*/ /*** end of group csu39fx10_sdk_chip_driver_iic */
/**@}*/ /*** end of group csu39fx10_sdk_chip_driver */
/**@}*/ /*** end of group csu39fx10_sdk_chip */
/*******************************************************************************/




#ifdef __cplusplus
}
#endif

#endif  //__DRV_IIC_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/

