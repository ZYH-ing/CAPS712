/**************************************************************************//**
 * @file     csu39fx10_acmp.c
 * @version  V1.0.0
 * @author   0531
 * @date     2020-10-09 PM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 *****************************************************************************/

// Include header file.
#include "csu39fx10_acmp.h"

/**
 * @brief 	<b>Description:</b> acmp 0 initialization.
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp0_init();
 *		}
 * @endcode
 */
void acmp0_init(void)
{
	ACMP0CR1= PRE_ACMP0CR1_DEFAULT;
	ACMP0CR2= PRE_ACMP0CR2_DEFAULT;
	ACMP0CR3= PRE_ACMP0CR3_DEFAULT;
	ACMP0CR4= PRE_ACMP0CR4_DEFAULT;
}


/**
 * @brief 	<b>Description:</b> acmp 0 disable.
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp0_disable();
 *		}
 * @endcode
 */
void acmp0_disable(void)
{
	__ACMP_ACMP0EN_SET_SHIFT(ACMP_ACMP0EN_DIS);
}


/**
 * @brief 	<b>Description:</b> acmp 0 enable.
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp0_enable();
 *		}
 * @endcode
 */
void acmp0_enable(void)
{
	__ACMP_ACMP0EN_SET_SHIFT(ACMP_ACMP0EN_EN);
}


/**
 * @brief 	<b>Description:</b> acmp 0 interrupt disable.
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp0_interrupt_disable();
 *		}
 * @endcode
 */
void acmp0_interrupt_disable(void)
{
	__ACMP_ACMP0IE_SET_SHIFT(ACMP_ACMP0IE_DIS);
}


/**
 * @brief 	<b>Description:</b> acmp 0 interrupt enable.
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp0_interrupt_enable();
 *		}
 * @endcode
 */
void acmp0_interrupt_enable(void)
{
	__ACMP_ACMP0IE_SET_SHIFT(ACMP_ACMP0IE_EN);
}


/**
 * @brief 	<b>Description:</b> get acmp 0 result.
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			bool acmp0_output;
 * 			acmp0_output= acmp0_get_result();
 *		}
 * @endcode
 */
bool acmp0_get_result(void)
{
	return __ACMP_ACMP0O_GET();
}


/**
 * @brief 	<b>Description:</b> get acmp 0 refresh.
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			bool acmp0_refresh;
 * 			acmp0_refresh= acmp0_get_refresh();
 *		}
 * @endcode
 */
bool acmp0_get_refresh(void)
{
	return __ACMP_ACMP0F_GET();
}


/**
 * @brief 	<b>Description:</b> clear acmp 0 refresh flag.
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp0_clear_refresh();
 *		}
 * @endcode
 */
void acmp0_clear_refresh(void)
{
	__ACMP_ACMP0F_SET_SHIFT(ACMP_ACMP0F_CLR);
}




/**
 * @brief 	<b>Description:</b> acmp 1 initialization.
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp1_init();
 *		}
 * @endcode
 */
void acmp1_init(void)
{
	ACMP1CR1= PRE_ACMP1CR1_DEFAULT;
	ACMP1CR2= PRE_ACMP1CR2_DEFAULT;
	ACMP1CR3= PRE_ACMP1CR3_DEFAULT;
	ACMP1CR4= PRE_ACMP1CR4_DEFAULT;
}


/**
 * @brief 	<b>Description:</b> acmp 1 disable.
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp1_disable();
 *		}
 * @endcode
 */
void acmp1_disable(void)
{
	__ACMP_ACMP1EN_SET_SHIFT(ACMP_ACMP1EN_DIS);
}


/**
 * @brief 	<b>Description:</b> acmp 1 enable.
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp1_enable();
 *		}
 * @endcode
 */
void acmp1_enable(void)
{
	__ACMP_ACMP1EN_SET_SHIFT(ACMP_ACMP1EN_EN);
}


/**
 * @brief 	<b>Description:</b> acmp 1 interrupt disable.
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp1_interrupt_disable();
 *		}
 * @endcode
 */
void acmp1_interrupt_disable(void)
{
	__ACMP_ACMP1IE_SET_SHIFT(ACMP_ACMP1IE_DIS);
}


/**
 * @brief 	<b>Description:</b> acmp 1 interrupt enable.
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp1_interrupt_enable();
 *		}
 * @endcode
 */
void acmp1_interrupt_enable(void)
{
	__ACMP_ACMP1IE_SET_SHIFT(ACMP_ACMP1IE_EN);
}


/**
 * @brief 	<b>Description:</b> get acmp 1 result.
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			bool acmp1_output;
 * 			acmp1_output= acmp1_get_result();
 *		}
 * @endcode
 */
bool acmp1_get_result(void)
{
	return __ACMP_ACMP1O_GET();
}


/**
 * @brief 	<b>Description:</b> get acmp 1 refresh.
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			bool acmp1_refresh;
 * 			acmp1_refresh= acmp1_get_refresh();
 *		}
 * @endcode
 */
bool acmp1_get_refresh(void)
{
	return __ACMP_ACMP1F_GET();
}


/**
 * @brief 	<b>Description:</b> clear acmp 1 refresh flag.
 * @param[in]  null	.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			acmp1_clear_refresh();
 *		}
 * @endcode
 */
void acmp1_clear_refresh(void)
{
	__ACMP_ACMP1F_SET_SHIFT(ACMP_ACMP1F_CLR);
}











