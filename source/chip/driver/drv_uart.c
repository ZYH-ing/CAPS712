/**************************************************************************//**
 * @file     drv_uart.c
 * @version  V1.0.0
 * @author   0531
 * @date     2020-09-24 AM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 *****************************************************************************/

// Include header file.
#include "drv_uart.h"
#include "drv_gpio.h"


/**@brief uart initialization.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void uart_init(void)
{
	/** gpio cfg**/
	gpio_config_t		gpio_cfg;
	gpio_cfg.gpio_portx= PORT_UR0_RX_PORTX;
	gpio_cfg.gpio_pinx= PORT_UR0_RX_PINX;
	gpio_cfg.gpio_pinmux= pinmux_func2;
	gpio_cfg.gpio_dir= dir_output;
	gpio_cfg.gpio_mode= mode_pp;
	gpio_cfg.gpio_pull= no_pull;
	gpio_init(&gpio_cfg);
	
	gpio_cfg.gpio_portx= PORT_UR0_TX_PORTX;
	gpio_cfg.gpio_pinx= PORT_UR0_TX_PINX;
	gpio_cfg.gpio_pinmux= pinmux_func2;
	gpio_cfg.gpio_dir= dir_output;
	gpio_cfg.gpio_mode= mode_pp;
	gpio_cfg.gpio_pull= no_pull;
	gpio_init(&gpio_cfg);
	/****************/

	UR0_CR1= PRE_UR0_CR1_DEFAULT;
	UR0_BRR0= PRE_UR0_BRR0_DEFAULT;
	UR0_BRR1= PRE_UR0_BRR1_DEFAULT;
	UR0_ST= PRE_UR0_ST_DEFAULT;
	UR0_INTE= PRE_UR0_INTE_DEFAULT;
	UR0_INTF= PRE_UR0_INTF_DEFAULT;
	UR0_TX_REG= 0x00;
	
#if(PRE_UR0_INTE_DEFAULT!= 0)
	GIE= true;
#endif
}


void uart_disable(void)
{
	/** gpio cfg**/
	gpio_config_t		gpio_cfg;
//	gpio_cfg.gpio_portx= PORT_UR0_RX_PORTX;
//	gpio_cfg.gpio_pinx= PORT_UR0_RX_PINX;
//	gpio_cfg.gpio_pinmux= pinmux_func0;
//	gpio_cfg.gpio_dir= dir_output;
//	gpio_cfg.gpio_mode= mode_pp;
//	gpio_cfg.gpio_pull= no_pull;
//	gpio_init(&gpio_cfg);
	
	gpio_cfg.gpio_portx= PORT_UR0_TX_PORTX;
	gpio_cfg.gpio_pinx= PORT_UR0_TX_PINX;
	gpio_cfg.gpio_pinmux= pinmux_func0;
	gpio_cfg.gpio_dir= dir_output;
	gpio_cfg.gpio_mode= mode_pp;
	gpio_cfg.gpio_pull= no_pull;
	gpio_init(&gpio_cfg);
	/****************/

	__UR0_UART0_EN_SET_SHIFT(UR0_UART0_EN_DIS);
}


/**@brief uart send one byte.
 * 
 * @param[in]  uint8_t data     uart send data.
 * @param[out] null     .
 * 
 * @return  null
 */
void uart_putchar(uint8_t data)
{
	do
	{
		for(uint8_t i= 0; i< 2; i++){}
	}while(__UR0_TX_BUSY_GET_SHIFT()== UR0_TX_BUSY_BUSY);
	UR0_TX_REG= data;
}	


/**@brief uart receive one byte.
 * 
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  uint8_t data     uart receive data.
 */
uint8_t uart_getchar(void)
{
	return UR0_RX_REG;
}	

