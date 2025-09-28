/**************************************************************************//**
 * @file     drv_wdt.c
 * @version  V1.0.0
 * @author   0531
 * @date     2020-09-24 PM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 *****************************************************************************/

// Include header file.
#include "drv_wdt.h"


/**@brief watchdog initialization.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void wdt_init(void)
{
	WDTCON= PRE_WDTCON_DEFAULT;
	WDTIN= PRE_WDTIN_DEFAULT;
}


void wdt_disable(void)
{
	__WDT_WDTEN_SET_SHIFT(WDT_WDTEN_DIS);
}


/**@brief watchdog feed dog.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void wdt_feeddog(void)
{
	asm("CLRWDT");
	asm("nop");
}




/**@brief windows-watchdog initialization.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void wwdt_init(void)
{
	WWDTWR= PRE_WWDTWR_DEFAULT;
	WWDTCR= PRE_WWDTCR_DEFAULT;
}


void wwdt_disable(void)
{
	__WWDT_WWDTEN_SET_SHIFT(WWT_WWDTEN_DIS);
}


/**@brief windows-watchdog feed dog.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void wwdt_feeddog(void)
{
	uint8_t a, b;
	a= __WWDT_TR_GET();
	b= PRE_WWDTWR_DEFAULT;
	
	if(__WWDT_TR_GET()< PRE_WWDTWR_DEFAULT)
	{
		// __WWDT_TR_SET(0x7F);			!!!
		WWDTCR= PRE_WWDTCR_DEFAULT;
		WWDTWR= PRE_WWDTWR_DEFAULT;
	}
}

