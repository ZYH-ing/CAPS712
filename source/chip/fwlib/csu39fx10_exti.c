/**************************************************************************//**
 * @file     csu39fx10_exti.c
 * @version  V1.0.0
 * @author   0531
 * @date     2020-10-09 PM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 *****************************************************************************/

// Include header file.
#include "csu39fx10_exti.h"


/**@brief external interrupt initialization.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void exi_init(void)
{
	EXICON= PRE_EXICON_DEFAULT;
	EXIIE= PRE_EXIIE_DEFAULT;
	EXIIF= PRE_EXIIF_DEFAULT;
	INTCFG1= PRE_INTCFG1_DEFAULT;
	INTCFG2= PRE_INTCFG2_DEFAULT;
	INTCFG3= PRE_INTCFG3_DEFAULT;

#if(PRE_EXIIE_DEFAULT!= 0)
	/** enable global interrupt**/
	GIE= 1;
	/********************/
#endif
}


/**@brief external interrupt func.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
// __weak void exi_int0_irq(void)
// {
	// if(__EXI_E0IE_GET_SHIFT()== EXI_E0IE_EN)
	// {
		
	// }
// }

// __weak void exi_int1_irq(void)
// {
	// if(__EXI_E1IE_GET_SHIFT()== EXI_E1IE_EN)
	// {
		
	// }
// }

// __weak void exi_int2_irq(void)
// {
	// if(__EXI_E2IE_GET_SHIFT()== EXI_E2IE_EN)
	// {
		
	// }
// }



