/**************************************************************************//**
 * @file     csu39fx10_rstmu.c
 * @version  V1.0.0
 * @author   
 * @date     2020-10-09 PM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 *****************************************************************************/

// Include header file.
#include "csu39fx10_rstmu.h"


/**
 * @brief 	low voltage detection module enable.
 * @param[in]  bool _enable  true-> enable, false-> disable.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			rstmu_lvd_enable(true);
 *		}
 * @endcode
 */
void rstmu_lvd_enable(bool _enable)
{
	if(_enable)
	{
		__RSTMU_LVDEN_SET_SHIFT(RSTMU_LVDEN_EN);
	}else
	{
		__RSTMU_LVDEN_SET_SHIFT(RSTMU_LVDEN_DIS);
	}
}

bool rstmu_get_lvd(void)
{
	return	__RSTMU_LVDF_GET();
}

bool rstmu_get_emcreset(void)
{
	return	__RSTMU_EMCF_GET();
}

bool rstmu_get_ilopreset(void)
{
	return	__RSTMU_ILOPF_GET();
}

bool rstmu_get_wwdtreset(void)
{
	return	__RSTMU_WWDTF_GET();
}



