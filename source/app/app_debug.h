/***************************************************************************//**
 * @file     app_debug.h
 * @version  V1.0.0
 * @author   0531
 * @date     2021-01-15 PM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 ****************************************************************************
 * @attention
 *  硬件平台:  \n
 *  SDK版本： .0.0
 * 
 * @par 修改日志:
 * <table>
 * <tr><th>Date        <th>Version  <th>Author    <th>Description
 * <tr><td>2018/08/17  <td>1.0      <td>0531	  <td>创建初始版本
 * </table>
 *
 *****************************************************************************/

#ifndef __APP_DEBUG_H__
#define __APP_DEBUG_H__

// Include external header file.


#ifdef __cplusplus
extern "C" {
#endif


#define CFG_DEBUG_DISABLE			(1)

typedef enum
{
	VIRTUAL_OSCILLOSCOPE_HEAD1= 0xA5F5,
	VIRTUAL_OSCILLOSCOPE_HEAD2= 0xA55A,
	VIRTUAL_OSCILLOSCOPE_HEAD3= 0xFA5A,
	VIRTUAL_OSCILLOSCOPE_HEAD4= 0x5AA5,
}debug_print_frame_head_t;




void test_display(void);
void test_key(void);
void test_dcdc_print(void);
void test_adcconvert_print(void);


#ifdef __cplusplus
}
#endif

#endif  //__APP_DEBUG_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/
