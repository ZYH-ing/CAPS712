/***************************************************************************
 * @file     mod_display.h
 * @version  V1.0.0
 * @author   0531
 * @date     2020-11-02 AM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 ****************************************************************************
 * @par 头文件
 *       drv_gpio.h
 * @attention
 *  硬件平台:	\n
 *  SDK版本		.0.0
 * 
 * @par 修改日志:
 * <table>
 * <tr><th>Date        <th>Version  <th>Author    <th>Description
 * <tr><td>2018/08/17  <td>1.0      <td>0531	  <td>创建初始版本
 * </table>
 *
 *****************************************************************************/

#ifndef __MOD_DISPLAY_H__
#define __MOD_DISPLAY_H__

// Include external header file.
#include "drv_gpio.h"


#ifdef __cplusplus
extern "C" {
#endif


#define BANK_DISP	bank4


/**
 * @addtogroup csu39fx10_sdk_module	csu39fx10_sdk_module
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_module_display	display 
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_module_display_cfg	display_config
 * @{
 */
/**
 * @name	led_port
 * @{
 */
/***
 * @brief  display - schematic.
 *
 *		__pt17(LED4)________________________________________________________________
 *																		|			|
 *		__pt16(LED3)_________________________________________			|			|
 *						|			|			|			|			|			|	
 *					  __|__		  __|__       __|__		  __|__		  __|__			|	
 *					  \ | / 	   /|\        \ | / 	   /|\		  \ | /			 \	
 *					  _\|/_		  /_|_\       _\|/_		  /_|_\		  _\|/_			  \
 *						|			|      	 	|			|			|			|	
 *				   led_2|	   led_1|	   led_4|	   led_3|	   led_0|	   key_0| 	
 *						|			|			|			|			|			|	
 *		__pt10(LED1)____|___________|			|			|			|			|	
 *						|			|			|			|			|			|	
 *					  __|__		  __|__ 		|			|			|			|	
 *					  \ | / 	   /|\  		|			|			|			|	
 *					  _\|/_		  /_|_\ 		|			|			|			|	
 *						|			|   		|			|			|			|	
 *				   led_5|	   led_6|			|			|			|			|	
 *						|			|			|			|			|			|	
 *		__pt11(LED2)____|___________|___________|___________|___________|			|_____gnd____		
 */
/**
 * @details <b>CFG_DISP_PORT_LED0</b>
 * - <b>Features: </b> display led port configuration
 * - <b>Param: </b>
 * | config		| Descriptions	|
 * | :----:		| :----:		|
 * | GPIO_PT10	| pt10			|
 * | ....		| ....			|
 * | GPIO_PT37	| pt37			|
 */
#define CFG_DISP_PORT_LED0		GPIO_PT17
/**@}*/ /*** end of name led_port */

/**
 * @details <b>CFG_DISP_PORT_LED1</b>
 * - <b>Features: </b> display led port configuration
 * - <b>Param: </b>
 * | config		| Descriptions	|
 * | :----:		| :----:		|
 * | GPIO_PT10	| pt10			|
 * | ....		| ....			|
 * | GPIO_PT37	| pt37			|
 */
#define CFG_DISP_PORT_LED1		GPIO_PT10

/**
 * @details <b>CFG_DISP_PORT_LED2</b>
 * - <b>Features: </b> display led port configuration
 * - <b>Param: </b>
 * | config		| Descriptions	|
 * | :----:		| :----:		|
 * | GPIO_PT10	| pt10			|
 * | ....		| ....			|
 * | GPIO_PT37	| pt37			|
 */
#define CFG_DISP_PORT_LED2		GPIO_PT11

/**
 * @details <b>CFG_DISP_PORT_LED3</b>
 * - <b>Features: </b> display led port configuration
 * - <b>Param: </b>
 * | config		| Descriptions	|
 * | :----:		| :----:		|
 * | GPIO_PT10	| pt10			|
 * | ....		| ....			|
 * | GPIO_PT37	| pt37			|
 */
#define CFG_DISP_PORT_LED3		GPIO_PT16

/**
 * @name	key_port
 * @{
 */
/**
 * @details <b>CFG_DISP_PORT_KEY0</b>
 * - <b>Features: </b> key port configuration
 * - <b>Param: </b>
 * | config		| Descriptions	|
 * | :----:		| :----:		|
 * | GPIO_PT10	| pt10			|
 * | ....		| ....			|
 * | GPIO_PT37	| pt37			|
 */
#define CFG_DISP_PORT_KEY0		CFG_DISP_PORT_LED3
 
/**@}*/ /*** end of name key_port */
/**@}*/ /*** end of group csu39fx10_sdk_chip_module_display_cfg */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup display_compile	attention: users do not need to care
 * @attention <b>users do not need to care</b>
 * @{
 */
/** 
 * @name display_compile_port
 * @{
 */
#define PRE_PORT_LED_1_P			(CFG_DISP_PORT_LED1/ 8)
#define PRE_PIN_LED_1_P				(CFG_DISP_PORT_LED1% 8)
#define PRE_PORT_LED_1_N			(CFG_DISP_PORT_LED3/ 8)
#define PRE_PIN_LED_1_N				(CFG_DISP_PORT_LED3% 8)

#define PRE_PORT_LED_2_P			(CFG_DISP_PORT_LED3/ 8)
#define PRE_PIN_LED_2_P				(CFG_DISP_PORT_LED3% 8)
#define PRE_PORT_LED_2_N			(CFG_DISP_PORT_LED1/ 8)
#define PRE_PIN_LED_2_N				(CFG_DISP_PORT_LED1% 8)

#define PRE_PORT_LED_3_P			(CFG_DISP_PORT_LED2/ 8)
#define PRE_PIN_LED_3_P				(CFG_DISP_PORT_LED2% 8)
#define PRE_PORT_LED_3_N			(CFG_DISP_PORT_LED3/ 8)
#define PRE_PIN_LED_3_N				(CFG_DISP_PORT_LED3% 8)

#define PRE_PORT_LED_4_P			(CFG_DISP_PORT_LED3/ 8)
#define PRE_PIN_LED_4_P				(CFG_DISP_PORT_LED3% 8)
#define PRE_PORT_LED_4_N			(CFG_DISP_PORT_LED2/ 8)
#define PRE_PIN_LED_4_N				(CFG_DISP_PORT_LED2% 8)

#define PRE_PORT_LED_5_P			(CFG_DISP_PORT_LED1/ 8)
#define PRE_PIN_LED_5_P				(CFG_DISP_PORT_LED1% 8)
#define PRE_PORT_LED_5_N			(CFG_DISP_PORT_LED2/ 8)
#define PRE_PIN_LED_5_N				(CFG_DISP_PORT_LED2% 8)

#define PRE_PORT_LED_6_P			(CFG_DISP_PORT_LED2/ 8)
#define PRE_PIN_LED_6_P				(CFG_DISP_PORT_LED2% 8)
#define PRE_PORT_LED_6_N			(CFG_DISP_PORT_LED1/ 8)
#define PRE_PIN_LED_6_N				(CFG_DISP_PORT_LED1% 8)

#define PRE_PORT_LED_0				(CFG_DISP_PORT_LED0/ 8)
#define PRE_PIN_LED_0				(CFG_DISP_PORT_LED0% 8)

#define PRE_PORT_KEY_0				(CFG_DISP_PORT_KEY0/ 8)
#define PRE_PIN_KEY_0				(CFG_DISP_PORT_KEY0% 8)


#define P_LED_1_P					PRE_PORT_LED_1_P, PRE_PIN_LED_1_P
#define P_LED_1_N					PRE_PORT_LED_1_N, PRE_PIN_LED_1_N
#define P_LED_2_P					PRE_PORT_LED_2_P, PRE_PIN_LED_2_P
#define P_LED_2_N					PRE_PORT_LED_2_N, PRE_PIN_LED_2_N
		
#define P_LED_3_P					PRE_PORT_LED_3_P, PRE_PIN_LED_3_P
#define P_LED_3_N					PRE_PORT_LED_3_N, PRE_PIN_LED_3_N
#define P_LED_4_P					PRE_PORT_LED_4_P, PRE_PIN_LED_4_P
#define P_LED_4_N					PRE_PORT_LED_4_N, PRE_PIN_LED_4_N
		
#define P_LED_5_P					PRE_PORT_LED_5_P, PRE_PIN_LED_5_P
#define P_LED_5_N					PRE_PORT_LED_5_N, PRE_PIN_LED_5_N
#define P_LED_6_P					PRE_PORT_LED_6_P, PRE_PIN_LED_6_P
#define P_LED_6_N					PRE_PORT_LED_6_N, PRE_PIN_LED_6_N
		
#define P_LED_0						PRE_PORT_LED_0, PRE_PIN_LED_0
#define P_KEY_0						PRE_PORT_KEY_0, PRE_PIN_KEY_0

//#define KEY1  PT25
//#define KEY1_inti {PT2EN5=0;PT2PU5=1;}

#define KEY1  PT13
#define KEY1_inti {PT1EN3=0;PT1PU3=1;}

//#define KEY2  PT12
//#define KEY2_inti {PT1EN2=0;PT1PU2=1;}

//#define LED2_PIN     PT22   ///// 单独白灯//// 单机
//#define LED2_PIN_EN  PT2EN2
//#define LED2_PIN_ON  {LED2_PIN_EN=1;LED2_PIN=1;}
//#define LED2_PIN_OFF {LED2_PIN_EN=1;LED2_PIN=0;} 

#define WHITE_PIN     PT33  ////灯板白灯 长按
#define WHITE_PIN_EN  PT3EN3
#define WHITE_PIN_ON  {WHITE_PIN_EN=1; WHITE_PIN=1;}// 
#define WHITE_PIN_OFF {WHITE_PIN_EN=1; WHITE_PIN=0;}// 

//#define LED3_PIN     PT25 /// 灯板红灯 双击
//#define LED3_PIN_EN  PT2EN5
//#define LED3_PIN_ON  {LED3_PIN_EN=1;LED3_PIN=1;}
//#define LED3_PIN_OFF {LED3_PIN_EN=1;LED3_PIN=0;} 

#define C_VDD     PT25
#define C_VDD_EN  PT2EN5
#define C_VDD_ON  {C_VDD_EN=1;C_VDD=1;}
#define C_VDD_OFF {C_VDD_EN=1;C_VDD=0;} 
 
//#define LED6_PIN     PT12
//#define LED6_PIN_EN  PT1EN2
//#define LED6_PIN_ON  {LED6_PIN_EN=1;LED6_PIN=1;}
//#define LED6_PIN_OFF {LED6_PIN_EN=1;LED6_PIN=0;}  
 
//#define LED_TX_PIN     PT35
//#define LED_TX_PIN_EN  PT3EN5
//#define LED_TX_ON  {LED_TX_PIN_EN=1;LED_TX_PIN=1;}
//#define LED_TX_OFF {LED_TX_PIN_EN=1;LED_TX_PIN=0;} 


//#define MCU_TX_PIN     PT35
//#define MCU_TX_PIN_EN  PT3EN5
//#define MCU_TX_PIN_UP  PT3PU5
//
//#define MCU_TX_PIN_OUT {MCU_TX_PIN_EN=1;}
//#define MCU_TX_PIN_IN  {MCU_TX_PIN_EN=0;}
//#define MCU_TX_PIN_H   {MCU_TX_PIN_EN=1;MCU_TX_PIN=1;}
//#define MCU_TX_PIN_L   {MCU_TX_PIN_EN=1;MCU_TX_PIN=0;}


//#define LED1_PIN    PT35
//#define LED1_PIN_EN PT3EN5
//
//#define LED2_PIN    PT12
//#define LED2_PIN_EN PT1EN2
//
//#define LED3_PIN    PT20
//#define LED3_PIN_EN PT2EN0
//
//#define LED4_PIN    PT22
//#define LED4_PIN_EN PT2EN2

/**@}*/ /*** end of name display_compile_port */
/**@}*/ /*** end of group display_compile */
/*******************************************************************************/

/******************************** dividing line ********************************/
/** 
 * @addtogroup display_enum	enum
 * @{
 */
/**
 * @brief  display - led number.
 */
typedef enum
{
	p_led_0	= (uint8_t)0x00,			/*!< display led 0 */
	p_led_1	= (uint8_t)0x01,			/*!< display led 1 */
	p_led_2	= (uint8_t)0x02,			/*!< display led 2 */
	p_led_3	= (uint8_t)0x03,			/*!< display led 3 */
	p_led_4	= (uint8_t)0x04,			/*!< display led 4 */
	p_led_5	= (uint8_t)0x05,			/*!< display led 5 */
	p_led_6	= (uint8_t)0x06,			/*!< display led 6 */
}disp_led_t;

typedef union
{
	struct
	{
		uint8_t led_0: 1;				/*!< led_0 display data */
		uint8_t led_1: 1;				/*!< led_1 display data */
		uint8_t led_2: 1;				/*!< led_2 display data */
		uint8_t led_3: 1;				/*!< led_3 display data */
		uint8_t led_4: 1;				/*!< led_4 display data */
		uint8_t led_5: 1;				/*!< led_5 display data */
		uint8_t led_6: 1;				/*!< led_6 display data */
	}bit;
	uint8_t byte;
}disp_data_t;

/**@}*/ /*** end of group display_enum */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup display_struct	struct
 * @{
 */
/**
 * @brief  display_struct.
 */
typedef struct
{
	disp_data_t		disp_data;

	struct
	{
#if CFG_SIMP_BITFIELD
		uint8_t key_0;						/*!< key_0 data */
#else
		uint8_t key_0: 1;					/*!< key_0 data */
#endif
	}key_data;
	uint8_t	disp_refresh_status;
}display_t;

extern uint8_t Err_diply;
extern uint8_t Err_diply_check_time_cnt;
extern BANK_DISP uint8_t Car_lighting_bright;
extern BANK_DISP uint8_t Key_up_flage;
/**@}*/ /*** end of group display_struct */
/*******************************************************************************/

/******************************** dividing line ********************************/
/** 
 * @addtogroup display_api	api
 * @{
 */
/**
 * @name display_api
 * @{
 */
/**
 * @brief 	<b>Description:</b> display initialization.
 * @details <b>Function prototype:</b> void mod_display_init(void);
 * @param[in]  null .
 * @param[out] null .
 * 
 * @return  null .
 * @par Example
 * @code
 *		void test( void )
 *		{
 *			mod_display_init();
 *		}
 * @endcode
 */
void mod_display_init(void);
void mod_display_disable(void);

/**
 * @brief 	<b>Description:</b> led display.
 * @details <b>Function prototype:</b> void mod_display_led(disp_led_t _led, bool _on);
 * @param[in]  disp_led_t _led 	led number{disp_led_t}.
 * @param[in]  bool _on			true-> on, false-> false.
 * @param[out] null .
 * 
 * @return  null .
 * @par Example
 * @code
 *		void test( void )
 *		{
 *			mod_display_led(led_1, true);
 *			mod_display_led(led_2, false);
 *		}
 * @endcode
 */
void mod_display_led(disp_led_t _led, bool _on);

/**
 * @brief 	<b>Description:</b> led toggle.
 * @details <b>Function prototype:</b> void mod_display_led_toggle(disp_led_t _led);
 * @param[in]  disp_led_t _led 	led number{disp_led_t}.
 * @param[out] null .
 * 
 * @return  null .
 * @par Example
 * @code
 *		void test( void )
 *		{
 *			mod_display_led_toggle(p_led_1);
 *		}
 * @endcode
 */
void mod_display_led_toggle(disp_led_t _led);

/**
 * @brief 	<b>Description:</b> led and key refresh.
 * @attention <b>Called in 1ms system interrupt</b>
 * @details <b>Function prototype:</b> void mod_display_led_key_refresh(void);
 * @param[in]  null .
 * @param[out] null .
 * 
 * @return  null .
 * @par Example
 * @code
 *		void test( void )
 *		{
 *			mod_display_led_key_refresh();
 *		}
 * @endcode
 */
void mod_display_led_key_refresh(void);

/**
 * @brief 	<b>Description:</b> get key data.
 * @details <b>Function prototype:</b> bool mod_key_get_data(void);
 * @param[in]  null .
 * @param[out] null .
 * 
 * @return  null .
 * @par Example
 * @code
 *		void test( void )
 *		{
 *			bool key_data;
 *			key_data= mod_key_get_data();
 *		}
 * @endcode
 */
bool mod_key_get_data(void);


void mod_display_batt_level(uint8_t _batt_energy);


/**@}*/ /*** end of group display_api */
/**@}*/ /*** end of group csu39fx10_sdk_chip_module_display */
/**@}*/ /*** end of group csu39fx10_sdk_module */
/*******************************************************************************/




#ifdef __cplusplus
}
#endif

#endif  //__MOD_DISPLAY_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/
