/***************************************************************************//**
 * @file     cs_common.h
 * @version  V1.0.0
 * @author   
 * @date     2020-09-23 AM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 ****************************************************************************
 * @par 头文件
 * @attention
 *  硬件平台:	\n
 *  SDK版本：	.0.0
 * 
 * @par 修改日志:
 * <table>
 * <tr><th>Date        <th>Version  <th>Author    <th>Description
 * <tr><td>2018/08/17  <td>1.0      <td>	      <td>创建初始版本
 * </table>
 *
 *****************************************************************************/

#ifndef __CS_COMMON_H__
#define __CS_COMMON_H__

// Include external header file.


#ifdef __cplusplus
extern "C" {
#endif


#define CFG_SIMP_BITFIELD		(1)
#define CFG_SIMP_MEMCPY_QC		(1)
#define CFG_SIMP_GPIO			(1)
#define CFG_SIMP_MEMCPY			(1)

typedef unsigned char						_Bool;
typedef unsigned char						uint8_t;
typedef unsigned int						uint16_t;
typedef unsigned long						uint32_t;
typedef long								int32_t;


/**
 * @addtogroup csu39fx10_sdk_chip	csu39fx10_sdk_chip
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_misc	misc 
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_misc_common	common 
 * @{
 */

/** 
 * @name bank number defination
 * @brief Used for functions such as MEMCPY
 * @{
 */
typedef enum
{
	BANK0	= (unsigned char)0x00,
	BANK1,
	BANK2,
	BANK3,
	BANK4,
	BANK5,
	BANK6,
	BANK7,
	BANK8,
	BANK9,
	BANK10,
}bank_num_t;
/**@}*/ /*** end of name bank number defination */


/** 
 * @name bool defination
 * @brief for compatibility with c++ bool
 * @{
 */
#ifndef bool
	#define bool	_Bool
	#define true	1
	#define false	0
#endif

#ifndef NULL
	#define NULL	0
#endif

typedef enum
{
//	NULL = 0,
	RESET = 0,		SET = !RESET,
	DISABLE = 0,	ENABLE = !DISABLE,
	ERROR = 0,		SUCCESS = !ERROR,
	INPUT = 0,		OUTPUT = !INPUT,
}status_t;
/**@}*/ /*** end of name bool defination */




/** 
 * @name reg_bit defination
 * @brief register bit
 * @{
 */
#define	C_REG_BITS1         0x01
#define	C_REG_BITS2         0x03
#define	C_REG_BITS3         0x07
#define	C_REG_BITS4         0x0F
#define	C_REG_BITS5         0x1F
#define	C_REG_BITS6         0x3F
#define	C_REG_BITS7         0x7F
#define	C_REG_BITS8         0xFF
/**@}*/ /*** end of name reg_bit defination */




/** 
 * @name global variables
 * @brief Memory copy related global variables
 * @{
 */
extern unsigned char r_memcpy_len;
extern unsigned char r_memcmp_res;
/**@}*/ /*** end of name global variables */




/** 
 * @name macro function
 * @brief register operation macro function
 * @{
 */
/**
  * @brief Register bit manipulation macro function
  * @param[in] REG, Operating register
  * @param[in] POS, Bit offset of operation{bit3-> 3, bit7-> 7}
  * @param[in] SHIFT_POS, Bit offset of operation{bit3-> 0x04, bit7-> 0x80}
  * @param[in] BITS, Number of bits operated
  * @param[in] VAL, Operation register bit value
  * @return  Register bit value
  */
#define M_REG_GET(REG, POS, BITS)					(unsigned char)((REG>> POS)& BITS)

/**
  * @brief Register bit manipulation macro function
  * @param[in] REG, Operating register
  * @param[in] POS, Bit offset of operation{bit3-> 3, bit7-> 7}
  * @param[in] SHIFT_POS, Bit offset of operation{bit3-> 0x04, bit7-> 0x80}
  * @param[in] BITS, Number of bits operated
  * @param[in] VAL, Operation register bit value
  * @return  Register bit value
  */
#define M_REG_GET_SHIFT(REG, POS, BITS)				(unsigned char)(REG& (BITS<< POS))

/**
  * @brief Register bit manipulation macro function
  * @param[in] REG, Operating register
  * @param[in] POS, Bit offset of operation{bit3-> 3, bit7-> 7}
  * @param[in] SHIFT_POS, Bit offset of operation{bit3-> 0x04, bit7-> 0x80}
  * @param[in] BITS, Number of bits operated
  * @param[in] VAL, Operation register bit value
  * @return  null
  */
#define M_REG_SET(REG, POS, BITS, VAL)				REG&= ~(BITS<< POS);		\
													REG|= (VAL<< POS)

/**
  * @brief Register bit manipulation macro function
  * @param[in] REG, Operating register
  * @param[in] POS, Bit offset of operation{bit3-> 3, bit7-> 7}
  * @param[in] SHIFT_POS, Bit offset of operation{bit3-> 0x04, bit7-> 0x80}
  * @param[in] BITS, Number of bits operated
  * @param[in] VAL, Operation register bit value
  * @return  null
  */
#define M_REG_SET_SHIFT(REG, POS, BITS, VAL)		REG&= (~(BITS << POS));		\
													REG|= VAL
													
/**
  * @brief Register bit manipulation macro function
  * @param[in] REG, Operating register
  * @param[in] POS, Bit offset of operation{bit3-> 3, bit7-> 7}
  * @param[in] SHIFT_POS, Bit offset of operation{bit3-> 0x04, bit7-> 0x80}
  * @param[in] BITS, Number of bits operated
  * @param[in] VAL, Operation register bit value
  * @return  null
  */
#define M_REG_TOGGLEBIT(REG, POS)					REG^= (1<< POS)

/**
  * @brief Register bit manipulation macro function
  * @param[in] REG, Operating register
  * @param[in] POS, Bit offset of operation{bit3-> 3, bit7-> 7}
  * @param[in] SHIFT_POS, Bit offset of operation{bit3-> 0x04, bit7-> 0x80}
  * @param[in] BITS, Number of bits operated
  * @param[in] VAL, Operation register bit value
  * @return  null
  */
#define M_REG_TOGGLEBIT_SHIFT(REG, SHIFT_POS)		REG^= SHIFT_POS
													
/**
  * @brief Register bit manipulation macro function
  * @param[in] REG, Operating register
  * @param[in] POS, Bit offset of operation{bit3-> 3, bit7-> 7}
  * @param[in] SHIFT_POS, Bit offset of operation{bit3-> 0x04, bit7-> 0x80}
  * @param[in] BITS, Number of bits operated
  * @param[in] VAL, Operation register bit value
  * @return  null
  */
#define M_REG_SETBIT(REG, POS, VAL)					(VAL? (REG|= (1<< POS)): (REG&= ~(1<< POS)))
/**
  * @brief Register bit manipulation macro function
  * @param[in] REG, Operating register
  * @param[in] POS, Bit offset of operation{bit3-> 3, bit7-> 7}
  * @param[in] SHIFT_POS, Bit offset of operation{bit3-> 0x04, bit7-> 0x80}
  * @param[in] BITS, Number of bits operated
  * @param[in] VAL, Operation register bit value
  * @return  null
  */
#define M_REG_CLRBIT(REG, POS, VAL)					(VAL? (REG&= ~(1<< POS)): (REG|= (1<< POS)))

/**
  * @brief Register bit manipulation macro function
  * @param[in] REG, Operating register
  * @param[in] POS, Bit offset of operation{bit3-> 3, bit7-> 7}
  * @param[in] SHIFT_POS, Bit offset of operation{bit3-> 0x04, bit7-> 0x80}
  * @param[in] BITS, Number of bits operated
  * @param[in] VAL, Operation register bit value
  * @return  null
  */
#define M_REG_GETBYTE(REG, BIT)						(unsigned char)(REG)

/**
  * @brief Register bit manipulation macro function
  * @param[in] REG, Operating register
  * @param[in] POS, Bit offset of operation{bit3-> 3, bit7-> 7}
  * @param[in] SHIFT_POS, Bit offset of operation{bit3-> 0x04, bit7-> 0x80}
  * @param[in] BITS, Number of bits operated
  * @param[in] VAL, Operation register bit value
  * @return  null
  */
#define M_REG_GETBYTE_SHIFT(REG, BIT)				(unsigned char)(REG)

/**
  * @brief Register bit manipulation macro function
  * @param[in] REG, Operating register
  * @param[in] POS, Bit offset of operation{bit3-> 3, bit7-> 7}
  * @param[in] SHIFT_POS, Bit offset of operation{bit3-> 0x04, bit7-> 0x80}
  * @param[in] BITS, Number of bits operated
  * @param[in] VAL, Operation register bit value
  * @return  null
  */
#define M_REG_SETBYTE(REG, BIT, SET)				(REG= SET)

/**
  * @brief Register bit manipulation macro function
  * @param[in] REG, Operating register
  * @param[in] POS, Bit offset of operation{bit3-> 3, bit7-> 7}
  * @param[in] SHIFT_POS, Bit offset of operation{bit3-> 0x04, bit7-> 0x80}
  * @param[in] BITS, Number of bits operated
  * @param[in] VAL, Operation register bit value
  * @return  null
  */
#define M_REG_SETBYTE_SHIFT(REG, BIT, POS_SET)		(REG= SET)


/**
  * @brief memory copy macro function
  * @param[in] c_str1_addr_h, Target address bank number{@ bank_num_t}
  * @param[in] r_str1_addr_l, Target address
  * @param[in] c_str2_addr_h, Original address bank number{@ bank_num_t}
  * @param[in] r_str2_addr_l, Original address
  * @param[in] _len, Data length (in bytes)
  * @return  null
  */
#define M_MEMCPY(c_str1_addr_h, r_str1_addr_l, c_str2_addr_h, r_str2_addr_l, _len)	\
do{															\
	FSR0H= (volatile uint8_t)c_str1_addr_h;					\
	FSR0= (volatile uint8_t)r_str1_addr_l;					\
	FSR1H= (volatile uint8_t)c_str2_addr_h;					\
	FSR1= (volatile uint8_t)r_str2_addr_l;					\
	r_memcpy_len= _len;										\
	cs_memcpy();											\
}while(0)

/**
  * @brief memory copy macro function(From flash to ram)
  * @param[in] c_str1_addr_h, Target address bank number{@ bank_num_t}
  * @param[in] r_str1_addr_l, Target address
  * @param[in] rom_str2_addr, Flash address
  * @param[in] _len, Data length (in bytes)
  * @return  null
  */
#define M_MEMCPY_ROM2RAM(c_str1_addr_h, r_str1_addr_l, rom_str2_addr, _len)	\
do{															\
	FSR0H= (volatile uint8_t)c_str1_addr_h;					\
	FSR0= (volatile uint8_t)r_str1_addr_l;					\
	EADRH= ((volatile uint16_t)rom_str2_addr>> 8)& 0xff;	\
	EADRL= (volatile uint16_t)rom_str2_addr& 0xff;			\
	r_memcpy_len= _len;										\
	cs_memcpy_rom2ram();									\
}while(0)

/**
  * @brief memory set macro function
  * @param[in] c_str1_addr_h, Target address bank number{@ bank_num_t}
  * @param[in] r_str1_addr_l, Target address
  * @param[in] _len, Data length (in bytes)
  * @param[in] _data, Set value
  * @return  null
  */
#define M_MEMSET(c_str1_addr_h, r_str1_addr_l, _len, _data)		\
do{															\
	FSR0H= (volatile uint8_t)c_str1_addr_h;					\
	FSR0= (volatile uint8_t)r_str1_addr_l;					\
	r_memcpy_len= _len;										\
	cs_memset(_data);										\
}while(0)

/**
  * @brief memory compare macro function
  * @param[in] c_str1_addr_h, RAM_1 address bank number{@ bank_num_t}
  * @param[in] r_str1_addr_l, RAM_1 address
  * @param[in] c_str2_addr_h, RAM_2 address bank number{@ bank_num_t}
  * @param[in] r_str2_addr_l, RAM_2 address
  * @param[in] _len, Data length (in bytes)
  * @return  r_memcmp_res, 0-> the same, 1-> different
  */
#define M_MEMCMP(c_str1_addr_h, r_str1_addr_l, c_str2_addr_h, r_str2_addr_l, _len)	\
do{															\
	FSR0H= (volatile uint8_t)c_str1_addr_h;					\
	FSR0= (volatile uint8_t)r_str1_addr_l;					\
	FSR1H= (volatile uint8_t)c_str2_addr_h;					\
	FSR1= (volatile uint8_t)r_str2_addr_l;					\
	r_memcpy_len= _len;										\
	cs_memcmp();											\
}while(0)
/**@}*/ /*** end of name macro function */
/*******************************************************************************/




/** 
 * @name common api
 * @brief common api
 * @{
 */
/**
 * @brief 	<b>Description:</b> data compare(>).
 * @details <b>Function prototype:</b> bool hex_greater_than_compare(uint16_t a, uint16_t b);
 * @param[in]  uint16_t a .
 * @param[in]  uint16_t b .
 * @param[out] null .
 * 
 * @return  bool true-> (a> b), false-> (a<= b) .
 * @par Example
 * @code
 *		void test( void )
 *		{
 *			uint16_t temp_a;
 *			uint16_t temp_b;
 *			uint16_t temp_c;
 *			temp_a= 1000;
 *			temp_b= 1002;
 *			if(hex_greater_than_compare(uint16_t a, uint16_t b))
 *			{
 *				temp_c= 10;
 *			}else
 *			{
 *				temp_c= 20;
 *			}
 *		}
 * @endcode
 */
bool hex_greater_than_compare(uint16_t a, uint16_t b);
bool isr_hex_greater_than_compare(uint16_t a, uint16_t b);

/**
 * @brief 	<b>Description:</b> data compare(>=).
 * @details <b>Function prototype:</b> bool hex_less_than_compare(uint16_t a, uint16_t b);
 * @param[in]  uint16_t a .
 * @param[in]  uint16_t b .
 * @param[out] null .
 * 
 * @return  bool true-> (a< b), false-> (a>= b).
 * @par Example
 * @code
 *		void test( void )
 *		{
 *			uint16_t temp_a;
 *			uint16_t temp_b;
 *			uint16_t temp_c;
 *			temp_a= 1000;
 *			temp_b= 1002;
 *			if(hex_less_than_compare(uint16_t a, uint16_t b))
 *			{
 *				temp_c= 20;
 *			}else
 *			{
 *				temp_c= 10;
 *			}
 *		}
 * @endcode
 */
bool hex_less_than_compare(uint16_t a, uint16_t b);
bool isr_hex_less_than_compare(uint16_t a, uint16_t b);


/**
 * @brief 	<b>Description:</b> Memory copy related functions.
 * @details <b>Function prototype:</b> void cs_memcpy(void);
 * @param[in]  null.
 * @param[out] null .
 * 
 * @return  null.
 */
void cs_memcpy(void);
void cs_memcpy_rom2ram(void);
void cs_memset(unsigned char _data);
bool cs_memcmp(void);

/**@}*/ /*** end of name common api */
/**@}*/ /*** end of group csu39fx10_sdk_chip_misc_common */
/**@}*/ /*** end of group csu39fx10_sdk_chip_misc */
/**@}*/ /*** end of group csu39fx10_sdk_chip */
/*******************************************************************************/


#ifdef __cplusplus
}
#endif

#endif  //__CS_COMMON_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/
