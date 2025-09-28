/**************************************************************************//**
 * @file     csu39fx10_syscfg.c
 * @version  V1.0.0
 * @author   0531
 * @date     2020-10-09 PM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 *****************************************************************************/

// Include header file.
#include "csu39fx10_syscfg.h"


/**@brief syscfg(Port multiplexing, etc.) initialization.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void syscfg_init(void)
{
	CFGR1= PRE_CFGR1_DEFAULT;
	CFGR2= PRE_CFGR2_DEFAULT;
	CFGR3= PRE_CFGR3_DEFAULT;
	CFGR4= PRE_CFGR4_DEFAULT;
//	CFGR5= PRE_CFGR5_DEFAULT;
#if(SDWDO_EN)
	CFGR5= PRE_CFGR5_DEFAULT;
	CFGR5 |= (0x03<<2);//复用ICD
#else
	CFGR5= PRE_CFGR5_DEFAULT;/**<0x10>{复用功能 IO:PT2.5;	AIN:PT2.6,PT2.4,}**/
#endif
//	CFGR6= PRE_CFGR6_DEFAULT;
//#if(K_Temp_Protect)
	CFGR6= PRE_CFGR6_DEFAULT;
//#else
//	CFGR6= PRE_CFGR6_NTC_IO;
//#endif
	CFGR7= PRE_CFGR7_DEFAULT;
	CFGR8= PRE_CFGR8_DEFAULT;////  比较器配置 不用改
}

