/**************************************************************************//**
 * @file     mod_queue.c
 * @version  V1.0.0
 * @author   0531
 * @date     2020-11-24 PM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 *****************************************************************************/

// Include header file.
#include "mod_queue.h"

#define PLUG_QUEUE_LENGTH					10


BANK_QUEUE static uint8_t quque_event_stack[PLUG_QUEUE_LENGTH];
BANK_QUEUE static uint8_t head;
BANK_QUEUE static uint8_t tail;

void mod_queue_create(void)
{
	head= 0;
	tail= 0;
}

uint8_t mod_queue_send(uint8_t data)//// 系统有动作先 执行 mod_queue_send 储存动作  再执行 mod_queue_receive 执行动作
{
	if(head== (tail+ 1)% PLUG_QUEUE_LENGTH)
	{
		return RESET;
	}else
	{
		quque_event_stack[tail]= data;
		tail= (tail+ 1)% PLUG_QUEUE_LENGTH;
		return SET;
	}
}

uint8_t mod_queue_receive(void)
{
	uint8_t u8value;
	
	if(head== tail)
	{
		return NULL;
	}else
	{
		u8value= quque_event_stack[head];
		head= (head+ 1)% PLUG_QUEUE_LENGTH;
		return u8value;
	}
}
