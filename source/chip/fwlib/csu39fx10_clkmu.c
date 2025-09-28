/**************************************************************************//**
 * @file     csu39fx10_clkmu.c
 * @version  V1.0.0
 * @author   0531
 * @date     2020-09-24 AM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 *****************************************************************************/

// Include header file.
#include "csu39fx10_clkmu.h"


/**@brief Clock configuration.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void SetSysClock(void)
{
    MCK= PRE_MCK_DEFAULT;
	TCTRIM= PRE_TCTRIM_DEFAULT;
	CLKSEL0= PRE_CLKSEL0_DEFAULT;
	CLKSEL1= PRE_CLKSEL1_DEFAULT;
	CLKSEL2= PRE_CLKSEL2_DEFAULT;
	CLKDIV0= PRE_CLKDIV0_DEFAULT;
	CLKDIV1= PRE_CLKDIV1_DEFAULT;
	CLKDIV2= PRE_CLKDIV2_DEFAULT;
	CLKDIV3= PRE_CLKSEL3_DEFAULT;
	CLKDIV4= PRE_CLKDIV4_DEFAULT;
}

