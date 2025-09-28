/**************************************************************************//**
 * @file     drv_timer.c
 * @version  V1.0.0
 * @author   
 * @date     2020-09-24 PM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 *****************************************************************************/

// Include header file.
#include "drv_timer.h"
#include "drv_gpio.h"


/**@brief timer 0 initialization.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void timer0_init(void)
{
	TM0CON= PRE_TM0CON_DEFAULT;
	TM0IN= PRE_TM0IN_DEFAULT;
	TM0CNT= PRE_TM0CNT_DEFAULT;
#if(PRE_TIMER0_TM0IE)
	GIE= true;
#endif
}


/**@brief timer 0 enable.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void timer0_enable(void)
{
	__T0_T0EN_SET_SHIFT(T0_T0EN_EN);
}


/**@brief timer 0 disable.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void timer0_disable(void)
{
	__T0_T0EN_SET_SHIFT(T0_T0EN_DIS);
}


/**@brief timer 2 initialization.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void timer2_init(void)
{
//#if(PRE_TIMER2_PWM2EN)
//	/** gpio cfg**/
//	gpio_config_t		gpio_cfg;
//	gpio_cfg.gpio_portx= P_TIMER2_PWM2_PORT;
//	gpio_cfg.gpio_pinx= P_TIMER2_PWM2_PIN;
//	gpio_cfg.gpio_pinmux= pinmux_func3;
//	gpio_cfg.gpio_dir= dir_output;
//	gpio_cfg.gpio_mode= mode_pp;
//	gpio_cfg.gpio_pull= no_pull;
//	gpio_init(&gpio_cfg);
//	/****************/
//#endif
//	
//	TM2CON= PRE_TM2CON_DEFAULT;
//	TM2IN= PRE_TM2IN_DEFAULT;
//	TM2CNT= PRE_TM2CNT_DEFAULT;
//	TM2R= PRE_TM2R_DEFAULT;
//	
//#if(PRE_TIMER2_TM2IE)
//	GIE= true;
//#endif

//#if(PRE_TIMER2_PWM2EN)
//	/** gpio cfg**/
//	gpio_config_t		gpio_cfg;
//	gpio_cfg.gpio_portx= P_TIMER2_PWM2_PORT;
//	gpio_cfg.gpio_pinx= P_TIMER2_PWM2_PIN;
//	gpio_cfg.gpio_pinmux= pinmux_func3;
//	gpio_cfg.gpio_dir= dir_output;
//	gpio_cfg.gpio_mode= mode_pp;
//	gpio_cfg.gpio_pull= no_pull;
//	gpio_init(&gpio_cfg);
//	/****************/
//#endif
	CLKSEL0=CLKSEL0|0x30;//// 5：4 --11-10kHZ 时钟
	CLKDIV1=CLKDIV1|0x07;///// 128 分频 
//    CLKDIV1=CLKDIV1|0x06;///// 64 分频 
//    CLKDIV1=CLKDIV1|0x05;///// 32 分频 
//    CLKDIV1=CLKDIV1|0x04;///// 16 分频 
//    CLKDIV1=CLKDIV1|0x03;///// 8 分频 
//    CLKDIV1=CLKDIV1|0x02;///// 4 分频 
//    CLKDIV1=CLKDIV1|0x01;///// 2 分频 
//    CLKDIV1=CLKDIV1|0x00;///// 0 分频 
    
	TM2CON= PRE_TM2CON_DEFAULT;
    TM2IN= 30;//// 10K 频率 128分频 --周期400ms
//  TM2IN= 10;//// 10K 频率 128分频 --周期400ms
//	TM2CNT= PRE_TM2CNT_DEFAULT;
//	TM2R= PRE_TM2R_DEFAULT;
	
	TM2IF=0;
#if(PRE_TIMER2_TM2IE)
	GIE= true;
#endif

}


/**@brief timer 2 enable.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void timer2_enable(void)
{
	__T2_T2EN_SET_SHIFT(T2_T2EN_EN);
}


/**@brief timer 2 disable.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void timer2_disable(void)
{
	__T2_T2EN_SET_SHIFT(T2_T2EN_DIS);
}




/**@brief timer 3 initialization.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void timer3_init(void)
{
#if(PRE_TIMER3_PWM3EN)
	/** gpio cfg**/
	gpio_config_t		gpio_cfg;
	gpio_cfg.gpio_portx= P_TIMER3_PWM3_PORT;
	gpio_cfg.gpio_pinx= P_TIMER3_PWM3_PIN;
	gpio_cfg.gpio_pinmux= pinmux_func3;
	gpio_cfg.gpio_dir= dir_output;
	gpio_cfg.gpio_mode= mode_pp;
	gpio_cfg.gpio_pull= no_pull;
	gpio_init(&gpio_cfg);
	/****************/
#endif
	
	TM3CON= PRE_TM3CON_DEFAULT;
	TM3IN= PRE_TM3IN_DEFAULT;
	TM3INH= PRE_TM3INH_DEFAULT;
	TM3CNT= PRE_TM3CNT_DEFAULT;
	TM3CNTH= PRE_TM3CNTH_DEFAULT;
	TM3R= PRE_TM3R_DEFAULT;
	TM3RH= PRE_TM3RH_DEFAULT;
	TM3CON2= PRE_TM3CON2_DEFAULT;

#if(PRE_TIMER3_TM3IE)
	GIE= true;
#endif
}


/**@brief timer 3 enable.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void timer3_enable(void)
{
	__T3_T3EN_SET_SHIFT(T3_T3EN_EN);
}


/**@brief timer 3 disable.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void timer3_disable(void)
{
	__T3_T3EN_SET_SHIFT(T3_T3EN_DIS);
}




/**@brief timer 4 initialization.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void timer4_init(void)
{
#if(PRE_TIMER4_PWM4EN)
	/** gpio cfg**/
	gpio_config_t		gpio_cfg;
	gpio_cfg.gpio_portx= P_TIMER4_PWM4_PORT;
	gpio_cfg.gpio_pinx= P_TIMER4_PWM4_PIN;
	gpio_cfg.gpio_pinmux= pinmux_func2;
	gpio_cfg.gpio_dir= dir_output;
	gpio_cfg.gpio_mode= mode_pp;
	gpio_cfg.gpio_pull= no_pull;
	gpio_init(&gpio_cfg);
	/****************/
#endif
	
	TM4CON= PRE_TM4CON_DEFAULT;
	TM4IN= PRE_TM4IN_DEFAULT;
	TM4INH= PRE_TM4INH_DEFAULT;
	TM4CNT= PRE_TM4CNT_DEFAULT;
	TM4CNTH= PRE_TM4CNTH_DEFAULT;
	TM4R= PRE_TM4R_DEFAULT;
	TM4RH= PRE_TM4RH_DEFAULT;

#if(PRE_TIMER4_TM4IE)
	GIE= true;
#endif
}


/**@brief timer 4 enable.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void timer4_enable(void)
{
	__T4_T4EN_SET_SHIFT(T4_T4EN_EN);
}


/**@brief timer 4 disable.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void timer4_disable(void)
{
	__T4_T4EN_SET_SHIFT(T4_T4EN_DIS);
}

