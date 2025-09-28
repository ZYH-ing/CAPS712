/**************************************************************************//**
 * @file     drv_iic.c
 * @version  V1.0.0
 * @author   0531
 * @date     2020-10-19 PM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 *****************************************************************************/

// Include header file.
#include "drv_iic.h"


static void iic_start(void);
static void iic_stop(void);
static bool iic_write_byte(uint8_t u8value);
static uint8_t iic_read_byte(uint8_t ack);


/**@brief soft iic initialization.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void iic_init(void)
{
//	/** gpio init**/
//	
//#if CFG_SIMP_GPIO
	/** PT14 init**/
	PT1EN4= 1;
	PT1PU4= 0;
	/** PT15 init**/
	PT1EN5= 1;
	PT1PU5= 0;
//#else
//	gpio_config_t		gpio_cfg;
//	gpio_cfg.gpio_portx= PRE_PORT_SDA;
//	gpio_cfg.gpio_pinx= PRE_PIN_SDA;
//	gpio_cfg.gpio_pinmux= pinmux_func0;
//	gpio_cfg.gpio_dir= dir_output;
//	gpio_cfg.gpio_mode= mode_pp;
//	gpio_cfg.gpio_pull= pull_up;
//	gpio_init(&gpio_cfg);
//
//	gpio_cfg.gpio_portx= PRE_PORT_SCL;
//	gpio_cfg.gpio_pinx= PRE_PIN_SCL;
//	gpio_cfg.gpio_pinmux= pinmux_func0;
//	gpio_cfg.gpio_dir= dir_output;
//	gpio_cfg.gpio_mode= mode_pp;
//	gpio_cfg.gpio_pull= pull_up;
//	gpio_init(&gpio_cfg);
//#endif
//
	__IIC_SDA_H();
	__IIC_SCL_H();
//	/************************/
}


void iic_disable(void)
{
	/** gpio init**/
	// gpio_config_t		gpio_cfg;
	// gpio_cfg.gpio_portx= PRE_PORT_SDA;
	// gpio_cfg.gpio_pinx= PRE_PIN_SDA;
	// gpio_cfg.gpio_pinmux= pinmux_func0;
	// gpio_cfg.gpio_dir= dir_output;
	// gpio_cfg.gpio_mode= mode_pp;
	// gpio_cfg.gpio_pull= no_pull;
	// gpio_init(&gpio_cfg);

	// gpio_cfg.gpio_portx= PRE_PORT_SCL;
	// gpio_cfg.gpio_pinx= PRE_PIN_SCL;
	// gpio_cfg.gpio_pinmux= pinmux_func0;
	// gpio_cfg.gpio_dir= dir_output;
	// gpio_cfg.gpio_mode= mode_pp;
	// gpio_cfg.gpio_pull= no_pull;
	// gpio_init(&gpio_cfg);
	/************************/
	
//	__IIC_SDA_H();
//	__IIC_SCL_H();
}


/**@brief (subfunction)soft iic start.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
static void iic_start(void)
{
//	__IIC_SDA_H();
//	__IIC_SCL_H();
//	__IIC_DELAY();
//	__IIC_DELAY();
//	__IIC_SDA_L();
//	__IIC_DELAY();
//	__IIC_DELAY();
//	__IIC_SCL_L();
	__IIC_SDA_H();
	__IIC_SCL_H();
	__IIC_DELAY();
	__IIC_DELAY();
	__IIC_SDA_L();
	__IIC_DELAY();
	__IIC_DELAY();
	__IIC_SCL_L();
}


/**@brief (subfunction)soft iic stop.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
static void iic_stop(void)
{
	__IIC_SDA_L();
	__IIC_SCL_L();
	__IIC_DELAY();
	__IIC_SCL_H();
	__IIC_DELAY();
	__IIC_DELAY();
	__IIC_SDA_H();
}


/**@brief (subfunction)soft iic send on byte data.
 * 
 * @param[in]  uint8_t u8value		send data.
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  bool ack	slave answer bit.
 */
static bool iic_write_byte(uint8_t u8value)
{
	bool ack= true;
	for(uint8_t i= 0; i< 8; i++)
	{
		__IIC_SCL_L();
		if(u8value& 0x80)
		{
			__IIC_SDA_H();
		}else
		{
			__IIC_SDA_L();
		}
		__IIC_DELAY();
		__IIC_SCL_H();
		__IIC_DELAY();
		u8value<<= 1;
	}
	
	//read ack
	__IIC_SCL_L();
	__IIC_DELAY();
	__IIC_DELAY();
	__IIC_SDA_DIR_IN();
	ack^= __IIC_SDA_IN();
	__IIC_SCL_H();
	__IIC_DELAY();
	__IIC_DELAY();
	__IIC_SCL_L();
	__IIC_SDA_H();
	__IIC_SDA_DIR_OUT();
	__IIC_DELAY();
	
	return ack;
}


/**@brief (subfunction)soft iic receive on byte data.
 * 
 * @param[in]  uint8_t ack	iic ack.
 * @param[out] null     .
 * 
 * @return  uint8_t u8value		receive data
 */
static uint8_t iic_read_byte(uint8_t ack)
{
	uint8_t u8value;

	__IIC_SDA_DIR_IN();
	for(uint8_t i= 0; i< 8; i++)
	{
		u8value<<= 1;
		__IIC_SCL_H();
		__IIC_DELAY();
		if(__IIC_SDA_IN())
		{
			u8value += 1;
		}
		__IIC_SCL_L();
		__IIC_DELAY();
	}

	if(ack== true)
	{
		__IIC_SDA_L();
	}else
	{
		__IIC_SDA_H();
	}
	__IIC_SDA_DIR_OUT();
	__IIC_SCL_H();
	__IIC_DELAY();
	__IIC_DELAY();
	__IIC_SCL_L();
	__IIC_DELAY();
	return u8value;
}


/**@brief soft iic write one byte data.
 * 
 * @param[in]  uint8_t address	iic slave-reg address.
 * @param[in]  uint8_t data		write data.
 * @param[out] null     .
 * 
 * @return  null
 */
void iic_transmit_byte(uint8_t address, BANK_IIC uint8_t data) //  单个字节写入
{
	iic_start();
	iic_write_byte(CFG_SLAVE_ADDR<< 1);
	iic_write_byte(address);
	iic_write_byte(data);
	iic_stop();
}

void iic_transmit_24C02_byte(uint8_t address, BANK_IIC uint8_t data) //  单个字节写入
{
	iic_start();
	iic_write_byte(CFG_SLAVE_24C02_ADDR<< 1);
	iic_write_byte(address);
	iic_write_byte(data);
	iic_stop();
}

/**@brief soft iic write data.
 * 
 * @param[in]  uint8_t address			iic slave-reg address.
 * @param[in]  uint8_t * data_array		write data buffer.
 * @param[in]  uint8_t length			write data length.
 * @param[out] null     .
 * 
 * @return  null
 */
void iic_transmit_bytes(uint8_t address, BANK_IIC uint8_t *data_array, uint8_t length)
{
	iic_start();
	iic_write_byte(CFG_SLAVE_ADDR<< 1);
	iic_write_byte(address);
	for(uint8_t i= 0; i< length; i++)
	{
		iic_write_byte(data_array[i]);
	}
	iic_stop();
}


/**@brief soft iic read one byte data.
 * 
 * @param[in]  uint8_t address	iic slave-reg address.
 * @param[out] null     .
 * 
 * @return  uint8_t u8value		read data
 */
uint8_t iic_receive_byte(uint8_t address)////  单个字节读取
{
	uint8_t u8value;

	iic_start();
	iic_write_byte(CFG_SLAVE_ADDR<< 1);
	iic_write_byte(address);

	iic_start();
	iic_write_byte((CFG_SLAVE_ADDR<< 1)| 1);
	
	u8value= iic_read_byte(false);
	iic_stop();
	return u8value;
}

uint8_t iic_receive_24C02_byte(uint8_t address)////  单个字节读取
{
	uint8_t u8value;

	iic_start();
	iic_write_byte(CFG_SLAVE_24C02_ADDR<< 1);
	iic_write_byte(address);

	iic_start();
	iic_write_byte((CFG_SLAVE_24C02_ADDR<< 1)| 1);
	
	u8value= iic_read_byte(false);
	iic_stop();
	return u8value;
}
/**@brief soft iic read data.
 * 
 * @param[in]  uint8_t address			iic slave-reg address.
 * @param[in]  uint8_t * data_array		read data buffer.
 * @param[in]  uint8_t length			read data length.
 * @param[out] null     .
 * 
 * @return  null
 */
BANK_IIC uint8_t *p_data_array;
 
void iic_receive_bytes(uint8_t address, BANK_IIC uint8_t *data_array, uint8_t length)
{
	iic_start();
	iic_write_byte(CFG_SLAVE_ADDR<< 1);
	iic_write_byte(address);

	iic_start();
	iic_write_byte((CFG_SLAVE_ADDR<< 1)| 1);
	
	for(uint8_t i= 0; i< (uint8_t)(length- 1); i++)
	{
		// *p_data_array= iic_read_byte(true);
		// p_data_array++;
		data_array[i]= iic_read_byte(true);
	}
	data_array[i]= iic_read_byte(false);
	iic_stop();
}



