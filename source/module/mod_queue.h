/***************************************************************************//**
 * @file     mod_queue.h
 * @version  V1.0.0
 * @author   0531
 * @date     2020-11-24 PM
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

#ifndef __MOD_QUEUE_H__
#define __MOD_QUEUE_H__

// Include external header file.
#include "csu39fx10.h"
#include "cs_common.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BANK_QUEUE		bank4


void mod_queue_create(void);
uint8_t mod_queue_send(uint8_t data);
uint8_t mod_queue_receive(void);


#ifdef __cplusplus
}
#endif

#endif  //__MOD_QUEUE_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/

