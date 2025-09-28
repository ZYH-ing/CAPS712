/**************************************************************************//**
 * @file     cs_common.c
 * @version  V1.0.0
 * @author   0531
 * @date     2021-01-05 PM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 *****************************************************************************/

// Include header file.
#include "csu39fx10.h"
#include "cs_common.h"

//拷贝、设置、比较数据长度
unsigned char r_memcpy_len;
//数据比较返回结果
unsigned char r_memcmp_res;


//内存拷贝
void cs_memcpy(void)
{
	__asm__("L_memcpy_loop:					");
	__asm__("	movfw	_IND1				");
	__asm__("	movwf	_IND0				");
	__asm__("	addlfsr 0, 1				");
	__asm__("	addlfsr 1, 1				");
	__asm__("	decfsz	_r_memcpy_len, 1	");
	__asm__("	goto 	L_memcpy_loop		");
	__asm__("	clrf 	_FSR0H				");
	__asm__("	clrf 	_FSR0				");
	__asm__("	clrf 	_FSR1H				");
	__asm__("	clrf 	_FSR1				");
	__asm__("	clrf 	_BSR				");
}


//内存拷贝（从flash到内存）
void cs_memcpy_rom2ram(void)
{
	__asm__("	clrf	_CMD					");
	__asm__("L_memcpy_rom2ram:					");
	__asm__("	btfsc	ISPSR, 0				");
	__asm__("	goto	L_memcpy_rom2ram		");
	__asm__("L_memcpy_rom2ram_loop:				");
	__asm__("	movlw	1						");
	__asm__("	addwf	EADRL, 1				");
	__asm__("	clrf	WORK					");
	__asm__("	addwfc	EADRH, 1				");
	__asm__("	bsf		_ISPCR, 0				");
	__asm__("L_memcpy_rom2ram_wait:				");
	__asm__("	btfsc	ISPSR, 0				");
	__asm__("	goto	L_memcpy_rom2ram_wait	");
	__asm__("	movfw	EDATL					");
	__asm__("	movwf	_IND0					");
	__asm__("	addlfsr 0, 1					");
	__asm__("	decfsz	_r_memcpy_len, 1		");
	__asm__("	goto 	L_memcpy_rom2ram		");
	__asm__("	clrf 	_FSR0H					");
	__asm__("	clrf 	_FSR0					");
	__asm__("	clrf 	_EADRH					");
	__asm__("	clrf 	_EADRL					");
	__asm__("	clrf 	_BSR					");
}


//内存设置
void cs_memset(unsigned char _data)
{
	__asm__("L_memset_loop:					");
	WORK= _data;
	__asm__("	movwf	_IND0				");
	__asm__("	addlfsr 0, 1				");
	__asm__("	decfsz	_r_memcpy_len, 1	");
	__asm__("	goto 	L_memset_loop		");
	__asm__("	clrf 	_FSR0H				");
	__asm__("	clrf 	_FSR0				");
	__asm__("	clrf 	_BSR				");
	
}


//内存比较
bool cs_memcmp(void)
{
	r_memcmp_res= true;
	__asm__("L_memcmp_loop:					");
	__asm__("	movfw	_IND1				");
	__asm__("	xorwf	_IND0, 0			");
	__asm__("	btfss	_STATUS, 0			");
	__asm__("	clrf	_r_memcmp_res		");
	__asm__("	addlfsr 0, 1				");
	__asm__("	addlfsr 1, 1				");
	__asm__("	decfsz	_r_memcpy_len, 1	");
	__asm__("	goto 	L_memcmp_loop		");
	__asm__("	clrf 	_FSR0H				");
	__asm__("	clrf 	_FSR0				");
	__asm__("	clrf 	_FSR1H				");
	__asm__("	clrf 	_FSR1				");
	__asm__("	clrf 	_BSR				");
	
	r_memcmp_res^= 0x01;
	return r_memcmp_res;
}


/**
 * @brief 	<b>Description:</b> hex_greater_than_compare
 * @param[in]  uint16_t a	.
 * @param[in]  uint16_t b	.
 * @param[out] bool true-> (a> b), false-> (a<= b).
 * 
 * @return  null
 */
bool hex_greater_than_compare(uint16_t a, uint16_t b)
{
    if(a > b)
    {
        return true;
    }
    return false;
}

/**
 * @brief 	<b>Description:</b> hex_less_than_compare
 * @param[in]  uint16_t a	.
 * @param[in]  uint16_t b	.
 * @param[out] bool true-> (a< b), false-> (a>= b).
 * 
 * @return  null
 */
bool hex_less_than_compare(uint16_t a, uint16_t b)
{
    if(a == b || hex_greater_than_compare(a, b))
    {
        return false;
    }
    return true;
}

/**
 * @brief 	<b>Description:</b> isr_hex_greater_than_compare
 * @param[in]  uint16_t a	.
 * @param[in]  uint16_t b	.
 * @param[out] bool true-> (a> b), false-> (a<= b).
 * 
 * @return  null
 */
bool isr_hex_greater_than_compare(uint16_t a, uint16_t b)
{
    if(a > b)
    {
        return true;
    }
    return false;
}


/**
 * @brief 	<b>Description:</b> isr_hex_less_than_compare
 * @param[in]  uint16_t a	.
 * @param[in]  uint16_t b	.
 * @param[out] bool true-> (a< b), false-> (a>= b).
 * 
 * @return  null
 */
bool isr_hex_less_than_compare(uint16_t a, uint16_t b)
{
    if(a == b || isr_hex_greater_than_compare(a, b))
    {
        return false;
    }
    return true;
}











