/**************************************************************************//**
 * @file     drv_gpio.c
 * @version  V1.0.0
 * @author   0531
 * @date     2020-10-10 AM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 *****************************************************************************/

// Include header file.
#include "csu39fx10_syscfg.h"
#include "drv_gpio.h"

#define GPIO1		(gpio_type_t* )&GPIO_1
#define GPIO2		(gpio_type_t* )&GPIO_2
#define GPIO3		(gpio_type_t* )&GPIO_3
                                                                                                                                                                                                                                                                                                                                                                               
#define GPIO_BASES	{GPIO1, GPIO2, GPIO3}

static gpio_type_t *const GPIO_InstanceTable[] = GPIO_BASES;


/**@brief gpio port multiplexing configuration.
 * 
 * @param[in]  _gpio_config					gpio configuration structure.
 * @param[in]  _gpio_config->gpio_portx		gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  _gpio_config->gpio_pinx		gpio pin number{pin_0~ pin_7}.
 * @param[in]  _gpio_config->gpio_pinmux	gpio port multiplex number{pinmux_func0~ pinmux_func3}.
 * @param[out] null     .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *		 	gpio_config_t		gpio_cfg;
 *		 	gpio_cfg.gpio_portx= gpio_1;
 *		 	gpio_cfg.gpio_pinx= pin_0;
 *		 	gpio_cfg.gpio_pinmux= pinmux_func0;
 *		 	gpio_pinmux_config(&gpio_cfg);
 *		}
 * @endcode
 */
void gpio_pinmux_config(gpio_config_t *_gpio_config)
{
	uint8_t *p= (uint8_t *)&SYSCFG_PT10FUNC_REG;
	
	p+= (_gpio_config->gpio_portx<< 1)+ (_gpio_config->gpio_pinx>> 2);
	*p&= ~(0x03<< ((_gpio_config->gpio_pinx& 0x03)<< 1));
	*p|= _gpio_config->gpio_pinmux<< ((_gpio_config->gpio_pinx& 0x03)<< 1);
}


/**@brief gpio port input and output direction configuration.
 * 
 * @param[in]  _gpio_config					gpio configuration structure.
 * @param[in]  _gpio_config->gpio_portx		gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  _gpio_config->gpio_pinx		gpio pin number{pin_0~ pin_7}.
 * @param[in]  _gpio_config->gpio_dir		gpio port input and output direction{dir_input, dir_output}.
 * @param[out] null     .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *		 	gpio_config_t		gpio_cfg;
 *		 	gpio_cfg.gpio_portx= gpio_1;
 *		 	gpio_cfg.gpio_pinx= pin_0;
 *		 	gpio_cfg.gpio_dir= dir_input;
 *		 	gpio_direction_config(&gpio_cfg);
 *		}
 * @endcode
 */
void gpio_direction_config(gpio_config_t *_gpio_config)
{
	_gpio_config->gpio_dir? (GPIO_InstanceTable[_gpio_config->gpio_portx]->PTxEN|= (1<< _gpio_config->gpio_pinx)):		\
							(GPIO_InstanceTable[_gpio_config->gpio_portx]->PTxEN&= ~(1<< _gpio_config->gpio_pinx));
}


/**@brief gpio port input and output pull-up configuration.
 * 
 * @param[in]  _gpio_config					gpio configuration structure.
 * @param[in]  _gpio_config->gpio_portx		gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  _gpio_config->gpio_pinx		gpio pin number{pin_0~ pin_7}.
 * @param[in]  _gpio_config->gpio_pull		gpio port pull-up{no_pull, pull_up}.
 * @param[out] null     .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *		 	gpio_config_t		gpio_cfg;
 *		 	gpio_cfg.gpio_portx= gpio_1;
 *		 	gpio_cfg.gpio_pinx= pin_0;
 *		 	gpio_cfg.gpio_pull= pull_up;
 *		 	gpio_pull_config(&gpio_cfg);
 *		}
 * @endcode
 */
void gpio_pull_config(gpio_config_t *_gpio_config)
{
	_gpio_config->gpio_pull? (GPIO_InstanceTable[_gpio_config->gpio_portx]->PTxPU|= (1<< _gpio_config->gpio_pinx)):		\
							(GPIO_InstanceTable[_gpio_config->gpio_portx]->PTxPU&= ~(1<< _gpio_config->gpio_pinx));
}


/**@brief gpio port input and output mode configuration.
 * 
 * @param[in]  _gpio_config					gpio configuration structure.
 * @param[in]  _gpio_config->gpio_pin		gpio port_pin number{enum->port_t}.
 * @param[in]  _gpio_config->gpio_mode		gpio port input and output mode{enum->gpio_mode_t}.
 * @param[out] null     .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *		 	gpio_config_t		gpio_cfg;
 *		 	gpio_cfg.gpio_pin= pt10;
 *		 	gpio_cfg.gpio_mode= mode_pp;
 *		 	gpio_mode_config(&gpio_cfg);
 *		}
 * @endcode
 */
void gpio_mode_config(gpio_config_t *_gpio_config)
{
	switch(_gpio_config->gpio_mode)
	{
		case mode_pp:
			switch(_gpio_config->gpio_pin)
			{
				case pt20:
					__GPIO_PT2OTYPE_PT20_SET(GPIO_PT2OTYPE_PT20_PP);
					break;
				case pt21:
					__GPIO_PT2OTYPE_PT20_SET(GPIO_PT2OTYPE_PT20_PP);
					break;
				default:
					break;
			}
			break;
		case mode_od:
			switch(_gpio_config->gpio_pin)
			{
				case pt20:
					__GPIO_PT2OTYPE_PT20_SET(GPIO_PT2OTYPE_PT20_OD);
					break;
				case pt21:
					__GPIO_PT2OTYPE_PT20_SET(GPIO_PT2OTYPE_PT20_OD);
					break;
				default:
					break;
			}
			break;
		case mode_digital_in_open:
			switch(_gpio_config->gpio_pin)
			{
				case pt24:
					__GPIO_PT2OFFDIN_PT24_SET_SHIFT(GPIO_PT2OFFDIN_PT24_OPEN);
					break;
				case pt23:
					__GPIO_PT2OFFDIN_PT23_SET_SHIFT(GPIO_PT2OFFDIN_PT23_OPEN);
					break;
				case pt36:
					__GPIO_PT3OFFDIN_PT36_SET_SHIFT(GPIO_PT3OFFDIN_PT36_OPEN);
					break;
				case pt35:
					__GPIO_PT3OFFDIN_PT35_SET_SHIFT(GPIO_PT3OFFDIN_PT35_OPEN);
					break;
				case pt34:
					__GPIO_PT3OFFDIN_PT34_SET_SHIFT(GPIO_PT3OFFDIN_PT34_OPEN);
					break;
				case pt33:
					__GPIO_PT3OFFDIN_PT33_SET_SHIFT(GPIO_PT3OFFDIN_PT33_OPEN);
					break;
				case pt32:
					__GPIO_PT3OFFDIN_PT32_SET_SHIFT(GPIO_PT3OFFDIN_PT32_OPEN);
					break;
				case pt31:
					__GPIO_PT3OFFDIN_PT31_SET_SHIFT(GPIO_PT3OFFDIN_PT31_OPEN);
					break;
				default:
					break;
			}
			break;
		case mode_digital_in_close:
			switch(_gpio_config->gpio_pin)
			{
				case pt24:
					__GPIO_PT2OFFDIN_PT24_SET_SHIFT(GPIO_PT2OFFDIN_PT24_CLOSE);
					break;
				case pt23:
					__GPIO_PT2OFFDIN_PT23_SET_SHIFT(GPIO_PT2OFFDIN_PT23_CLOSE);
					break;
				case pt36:
					__GPIO_PT3OFFDIN_PT36_SET_SHIFT(GPIO_PT3OFFDIN_PT36_CLOSE);
					break;
				case pt35:
					__GPIO_PT3OFFDIN_PT35_SET_SHIFT(GPIO_PT3OFFDIN_PT35_CLOSE);
					break;
				case pt34:
					__GPIO_PT3OFFDIN_PT34_SET_SHIFT(GPIO_PT3OFFDIN_PT34_CLOSE);
					break;
				case pt33:
					__GPIO_PT3OFFDIN_PT33_SET_SHIFT(GPIO_PT3OFFDIN_PT33_CLOSE);
					break;
				case pt32:
					__GPIO_PT3OFFDIN_PT32_SET_SHIFT(GPIO_PT3OFFDIN_PT32_CLOSE);
					break;
				case pt31:
					__GPIO_PT3OFFDIN_PT31_SET_SHIFT(GPIO_PT3OFFDIN_PT31_CLOSE);
					break;
				default:
					break;
			}
			break;
		case mode_bypass_close:
			switch(_gpio_config->gpio_pin)
			{
				case pt20_23:
					__GPIO_SHORT_2023_SET_SHIFT(GPIO_SHORT_2023_CLOSE);
					break;
				case pt21_24:
					__GPIO_SHORT_2124_SET_SHIFT(GPIO_SHORT_2124_CLOSE);
					break;
				case pt22_25:
					__GPIO_SHORT_2225_SET_SHIFT(GPIO_SHORT_2225_CLOSE);
					break;
				case pt37_30:
					__GPIO_SHORT_3730_SET_SHIFT(GPIO_SHORT_3730_CLOSE);
					break;
				default:
					break;
			}
			break;
		case mode_bypass_open:
			switch(_gpio_config->gpio_pin)
			{
				case pt20_23:
					__GPIO_SHORT_2023_SET_SHIFT(GPIO_SHORT_2023_OPEN);
					break;
				case pt21_24:
					__GPIO_SHORT_2124_SET_SHIFT(GPIO_SHORT_2124_OPEN);
					break;
				case pt22_25:
					__GPIO_SHORT_2225_SET_SHIFT(GPIO_SHORT_2225_OPEN);
					break;
				case pt37_30:
					__GPIO_SHORT_3730_SET_SHIFT(GPIO_SHORT_3730_OPEN);
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
}


/**@brief gpio initialization.
 * 
 * @param[in]  _gpio_config					gpio configuration structure.
 * @param[in]  _gpio_config->gpio_pin		gpio port_pin number{enum->port_t}.
 * @param[in]  _gpio_config->gpio_portx		gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  _gpio_config->gpio_pinx		gpio pin number{pin_0~ pin_7}.
 * @param[in]  _gpio_config->gpio_pinmux	gpio port multiplex number{pinmux_func0~ pinmux_func3}.
 * @param[in]  _gpio_config->gpio_dir		gpio port input and output direction{dir_input, dir_output}.
 * @param[in]  _gpio_config->gpio_pull		gpio port pull-up{no_pull, pull_up}.
 * @param[in]  _gpio_config->gpio_mode		gpio port input and output mode{gpio_mode_t}.
 * @param[out] null     .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 *		 	gpio_config_t		gpio_cfg;
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
void gpio_init(gpio_config_t *_gpio_config)
{
	gpio_mode_config(_gpio_config);
	gpio_direction_config(_gpio_config);
	gpio_pull_config(_gpio_config);
	gpio_pinmux_config(_gpio_config);
}




/**@brief gpio dir bit.
 * 
 * @param[in]  port_gpio_t _port		gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  port_pin_t _pin			gpio pin number{pin_0~ pin_7}.
 * @param[in]  gpio_direction_t _dir	gpio input and output direction{dir_input, dir_output}.
 * @param[out] null .
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
void gpio_dir_bit(port_gpio_t _port, port_pin_t _pin, gpio_direction_t _dir)
{
	// _dir? (GPIO_InstanceTable[_port]->PTxEN|= (1<< _pin)):			\
			// ({														\
				// GPIO_InstanceTable[_port]->PTxEN&= (~(1<< _pin));	\
				// GPIO_InstanceTable[_port]->PTxEN&= (~(1<< _pin));	\
			// });
	_dir? (GPIO_InstanceTable[_port]->PTxEN|= 1<< _pin):		\
			(GPIO_InstanceTable[_port]->PTxEN&= ~(1<< _pin));
}


/**@brief gpio pull-up bit.
 * 
 * @param[in]  port_gpio_t _port		gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  port_pin_t _pin			gpio pin number{pin_0~ pin_7}.
 * @param[in]  gpio_pull_t _pull		gpio pull-up{no_pull, pull_up}.
 * @param[out] null .
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
void gpio_pull_bit(port_gpio_t _port, port_pin_t _pin, gpio_pull_t _pull)
{
	_pull? (GPIO_InstanceTable[_port]->PTxPU|= 1<< _pin):		\
			(GPIO_InstanceTable[_port]->PTxPU&= ~(1<< _pin));
}


/**@brief gpio reset bit.
 * 
 * @param[in]  port_gpio_t _port	gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  port_pin_t _pin		gpio pin number{pin_0~ pin_7}.
 * @param[out] null     .
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
void gpio_reset_bit(port_gpio_t _port, port_pin_t _pin)
{
	GPIO_InstanceTable[_port]->PTx&= ~(1<< _pin);
}


/**@brief gpio set bit.
 * 
 * @param[in]  port_gpio_t _port	gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  port_pin_t _pin		gpio pin number{pin_0~ pin_7}.
 * @param[out] null     .
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
void gpio_set_bit(port_gpio_t _port, port_pin_t _pin)
{
	GPIO_InstanceTable[_port]->PTx|= 1<< _pin;
}


/**@brief gpio toggle bit.
 * 
 * @param[in]  port_gpio_t _port	gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  port_pin_t _pin		gpio pin number{pin_0~ pin_7}.
 * @param[out] null     .
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
void gpio_toggle_bit(port_gpio_t _port, port_pin_t _pin)
{
	GPIO_InstanceTable[_port]->PTx^= 1<< _pin;
}


/**@brief gpio write bit.
 * 
 * @param[in]  port_gpio_t _port	gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  port_pin_t _pin		gpio pin number{pin_0~ pin_7}.
 * @param[in]  bool _set			gpio pin set{true, false}.
 * @param[out] null     .
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
void gpio_write_bit(port_gpio_t _port, port_pin_t _pin, bool _set)
{
	_set? (GPIO_InstanceTable[_port]->PTx|= 1<< _pin):		\
			(GPIO_InstanceTable[_port]->PTx&= ~(1<< _pin));
}


/**@brief gpio read bit.
 * 
 * @param[in]  port_gpio_t _port	gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  port_pin_t _pin		gpio pin number{pin_0~ pin_7}.
 * @param[out] null     .
 * 
 * @return  bool value
 * @par Example
 * @code
 *		void test( void )
 *		{
 *		 	bool 	gpio1_1_value;
 *		 	gpio1_1_value= gpio_read_bit(gpio_1, pin_0);
 *		}
 * @endcode
 */
bool gpio_read_bit(port_gpio_t _port, port_pin_t _pin)
{
	return (GPIO_InstanceTable[_port]->PTx>> _pin)& 0x01;
}


/**@brief gpio write port.
 * 
 * @param[in]  port_gpio_t _port	gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[in]  uint8_t _data		gpio pin data.
 * @param[out] null     .
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
void gpio_write_port(uint8_t _port, uint8_t _data)
{
	switch(_port)
	{
		case gpio_1:
			PT1= _data;
			break;
		case gpio_2:
			PT2= _data;
			break;
		case gpio_3:
			PT3= _data;
			break;
		default:
			break;
	}
	// GPIO_InstanceTable[_port]->PTx= _data;
}


/**@brief gpio read port.
 * 
 * @param[in]  port_gpio_t _port	gpio port number{gpio_1, gpio_2, gpio_3}.
 * @param[out] null     .
 * 
 * @return  uint8_t value
 * @par Example
 * @code
 *		void test( void )
 *		{
 *		 	uint8_t		gpio1_value;
 *		 	gpio1_value= gpio_read_port(gpio_1);
 *		}
 * @endcode
 */
uint8_t gpio_read_port(port_gpio_t _port)
{
	return GPIO_InstanceTable[_port]->PTx;
}



