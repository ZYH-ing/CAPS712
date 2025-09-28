/**************************************************************************//**
 * @file     drv_adc.c
 * @version  V1.0.0
 * @author   0531
 * @date     2020-10-09 PM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 *****************************************************************************/

// Include header file.
#include "drv_adc.h"


/**@brief adc initialization.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void adc_init(void)
{
	SRADCON0= PRE_SRADCON0_DEFAULT;
	SRADCON1= PRE_SRADCON1_DEFAULT;
	SRADCON2= PRE_SRADCON2_DEFAULT;/////0x3C  0011 1100  1V  参考电压
	asm("nop");
}


/**@brief adc disable.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void adc_disable(void)
{
	__ADC_SRADEN_SET_SHIFT(ADC_SRADEN_DIS);
}


/**@brief adc enable.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void adc_enable(void)
{
	__ADC_SRADEN_SET_SHIFT(ADC_SRADEN_EN);
}


/**@brief adc stop.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void adc_stop(void)
{
	__ADC_SRADS_SET_SHIFT(ADC_SRADS_STOP);
}


/**@brief adc start.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void adc_start(void)
{
	__ADC_SRADS_SET_SHIFT(ADC_SRADS_START);
}


/**@brief adc interrupt disable.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void adc_interrupt_disable(void)
{
	__ADC_SRADIE_SET_SHIFT(ADC_SRADIE_DIS);
}


/**@brief adc interrupt enable.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  null
 */
void adc_interrupt_enable(void)
{
	__ADC_SRADIE_SET_SHIFT(ADC_SRADIE_EN);
}


/**@brief adc set channel.
 * 
 * @param[in]  adc_sing_chl_t _chl _chl  channel.
 * @param[out] null     .
 * 
 * @return  uint16_t sroft_data
 */
void adc_set_sing_channel(adc_sing_chl_t _chl)
{
	__ADC_CHS_SET(_chl);
}

/**@brief adc set channel.
 * 
 * @param[in]  adc_diff_chl_t _chl  channel.
 * @param[out] null     .
 * 
 * @return  uint16_t sroft_data
 */
void adc_set_diff_channel(adc_diff_chl_t _chl)
{
	__ADC_CHS_SET(_chl);
}


/**@brief adc set channel.
 * 
 * @param[in]  adc_vref_t _vrefs	vref.
 * @param[out] null     .
 * 
 * @return  uint16_t sroft_data
 */
void adc_set_vref(adc_vref_t _vrefs)
{
	__ADC_VREFS_SET(_vrefs);
}


/**@brief adc get.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  uint16_t srad_data
 */
uint16_t adc_get_srad(void)
{
	return (SRADH<< 8)| SRADL;
}


/**@brief adc get sroft.
 * 
 * @param[in]  null     .
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  uint16_t sroft_data
 */
uint16_t adc_get_sroft(void)
{
	return (SROFTH<< 8)| SROFTL;
}

