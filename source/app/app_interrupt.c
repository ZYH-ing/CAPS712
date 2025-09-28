/**************************************************************************//**
 * @file     app_interrupt.c
 * @version  V1.0.0
 * @author   0531
 * @date     2020-11-21 PM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 *****************************************************************************/

// Include header file.
#include "cs_common.h"
#include "system_csu39fx10.h"

//driver
#include "csu39fx10_exti.h"
#include "drv_timer.h"
#include "drv_uart.h"
#include "drv_adc.h"
#include "mod_coulomb.h"

//module
#include "mod_display.h"
#include "mod_adc_convert.h"
#include "mod_input_output.h"
#include "mod_modbus.h"

//protocol
#include "lib_prot_pd.h"
#include "lib_multi_protocol.h"

//app
#include "app_init.h"
#include "app_main.h"
#include "app_interrupt.h"
#include "app_state_machine.h"
//#include "drv_wdt.h"
#include "mod_key.h"
void exi_int0_irq(void);
void exi_int1_irq(void);
void exi_int2_irq(void);
void timer0_irq(void);
void timer2_irq(void);
void timer3_irq(void);
void timer4_irq(void);
void adc_irq(void);
void typec_irq(void);
void pd_irq(void);

//============================================
// interrupt function
//============================================
void INT_FUNCTION(void) interrupt
{
	if(__EXI_E0IF_GET_SHIFT()!= 0)////外部中断0处理
	{
		__EXI_E0IF_SET_SHIFT(EXI_E0IF_CLR);
		exi_int0_irq();
		Bat_low_sleep_flage=0;////  强制休眠按键唤醒请求强制唤醒标志////
	}
	if(__EXI_E1IF_GET_SHIFT()!= 0)//外部中断1处理
	{
		__EXI_E1IF_SET_SHIFT(EXI_E1IF_CLR);
		exi_int1_irq();
	}
	if(__EXI_E2IF_GET_SHIFT()!= 0)//外部中断2处理
	{
		__EXI_E2IF_SET_SHIFT(EXI_E2IF_CLR);
		exi_int2_irq();
	}

   	/////// 定时器2中断处理////
    if(__T2_TM2IF_GET_SHIFT()!= 0)/// 400ms 一次中断
	 {
		 __T2_TM2IF_SET_SHIFT(T2_TM2IF_CLR);
		 timer2_irq();
//		asm("CLRWDT");
//     	asm("nop");
       Time_2_Flage_do=1;
//       Foece_Sleep_Time_S++;
//       if(Foece_Sleep_Time_S>=150)////1分钟计数
//		 {
//			 Foece_Sleep_Time_S=0;
//			 Foece_Sleep_Time_Min++;
////			 if(Foece_Sleep_Time_Min>=43200)/////30x24x60----43200分钟---30天///
//             if(Foece_Sleep_Time_Min>=28800)/////20x24x60----28800---20天///
////             if(Foece_Sleep_Time_Min>=14400)/////10x24x60----14400---10天///
//			 {
//			   Foece_Sleep_Time_Min=0;
//			   Foece_Sleep_Time_Mon=1;
//			 }
//			 
//		 }
	 }
	 
	if(__T0_TM0IF_GET_SHIFT()!= 0)// 定时器0中断（1ms）
	{
		__T0_TM0IF_SET_SHIFT(T0_TM0IF_CLR);

		  Time_1ms_cnt++;
		  lastRxTime--;// 每1ms递减超时计数器
		if(Time_1ms_cnt>=10)
		{
	//   PT15=~PT15;
			Time_1ms_cnt=0;
			timer0_irq();
		}
	   
	}

	
	
//	 if(INTFL & INTF_UART_MASK)
//	{
//		if(UR0_RNIF)
//		{
//			UR0_RNIF = 0;
//			
//		    #if K_UARTX_RX_Upgrade
//			uart_read_temp = UR0_RX_REG;
//			iap_signal_detect(uart_read_temp);			//用户只需在接收到数据后调用此函数即可
//			#endif
//		}
//	}
	typec_irq();/// TYPE_C 中断连接处理
	pd_irq();///PD 接收中断处理
	
	//multi protocol
	multi_protocol_isr_process();//// 多协议中断处理

	// if(__T2_TM2IF_GET_SHIFT()!= 0)
	// {
		// __T2_TM2IF_SET_SHIFT(T2_TM2IF_CLR);
		// timer2_irq();
	// }
	// if(__T3_TM3IF_GET_SHIFT()!= 0)
	// {
		// __T3_TM3IF_SET_SHIFT(T3_TM3IF_CLR);
		// timer3_irq();
	// }
	// if(__T4_TM4IF_GET_SHIFT()!= 0)
	// {
		// __T4_TM4IF_SET_SHIFT(T4_TM4IF_CLR);
		// timer4_irq();
	// }
	
	if(__ADC_SRADIF_GET_SHIFT()!= 0)/// ADC 采样中断处理////
	{
		__ADC_SRADIF_SET_SHIFT(ADC_SRADIF_CLR);
		adc_irq();
	}
	
	if(__UR0_UR0_RNIF_GET_SHIFT()!= 0)  // 串口接收中断
	{
		Flag=1;
		buf = &rxBuffers[activeBuffer];  // 指针指向当前活动缓冲区
		
		do{
			if(buf->length < BUFFER_SIZE)// 该缓冲区未满
			{
				buf->data[buf->length] = UR0_RX_REG;  // 存储接收到的字节
				buf->length++;  // 增加数据长度
			}
			else
			{
				buf->length = 0;  // 缓冲区溢出，重新开始
			}
		}while(UR0_RNIF);  // 处理所有待接收数据
		
		lastRxTime = 255;  // 重置超时计时器
	}
	// else
	// {
	// 	Flag=2;
	// }
}

void exi_int0_irq(void)
{
	if(__EXI_E0IE_GET_SHIFT()== EXI_E0IE_EN)
	{
		if((PT12== 0)&&(__EXI_PT1INT_PT12_GET_SHIFT()))
		{
			
		}
	}
}

void exi_int1_irq(void)
{
	if(__EXI_E1IE_GET_SHIFT()== EXI_E1IE_EN)
	{
		// gpio_toggle_bit(gpio_3, pin_0);
	}
}

void exi_int2_irq(void)
{
	if(__EXI_E2IE_GET_SHIFT()== EXI_E2IE_EN)
	{
		// gpio_toggle_bit(gpio_3, pin_0);
	}
}

void timer0_irq(void)
{
	if(__T0_TM0IE_GET_SHIFT()!= 0)
	{
	/////////////////
//	   adc_branch_cnt++;
//	   if(adc_branch_cnt>=20)////20ms 没有ADC检测中断 则复位检测
//	   {
//	       adc_branch_cnt=0;
//	       adc_branch=0;
//	   }
	/////////////////////////// 1ms 动作
	
		if(!sys_flag.timer_1ms)
		{
			sys_flag.timer_1ms= true;
		}else
		{
			// while(1)
			{
				__asm__("nop");
			}
		}
		sys_timer.time_ruler++;
		multi_protocol_timebase_callback();
		mod_io_vbus_switch_timer();
		/** display scan**/
		if(!SYS_in_Sleep_F)
		{
//  	      mod_display_led_key_refresh();//// 灯显示刷新/////
		}
	}
}

void timer2_irq(void)
{
	if(__T2_TM2IE_GET_SHIFT()!= 0)
	{
	
	}
}

void timer3_irq(void)
{
	if(__T3_TM3IE_GET_SHIFT()!= 0)
	{
	}
}

void timer4_irq(void)
{
	if(__T4_TM4IE_GET_SHIFT()!= 0)
	{
	}
}

void typec_irq(void)
{
	//TypeC
	if(fwlib_typec_get_scnaif())
	{
		fwlib_typec_clear_scnaif();
	}else if(fwlib_typec_get_scnbif())
	{
		fwlib_typec_clear_scnbif();		
	}
}
	

//void pd_irq(void)
//{
////	if(fwlib_pd_get_tmoutif())
////	{
////		fwlib_pd_clear_tmoutif();
////		h_pd.private.b_pd_timeout_if= SET;
////	}else if(fwlib_pd_get_rxif())
////	{
////		fwlib_pd_clear_rxif();
////		h_pd.private.b_pd_receive_if= SET;
////	}else if(fwlib_pd_get_txif())
////	{
////		fwlib_pd_clear_txif();
////		h_pd.private.b_pd_trans_if= SET;
////	}
//}

volatile unsigned char bank4 APP_FIFOCTL1                @((0X50)+0x10);
volatile unsigned char bank4 APP_PDSOP					 @((0X50)+0x0F);
void pd_irq(void)
{
	if(fwlib_pd_get_tmoutif())
	{
		fwlib_pd_clear_tmoutif();
		h_pd.private.b_pd_timeout_if= SET;
		h_pd_of.private.n_derailment_cnt= 0;
	}else if(fwlib_pd_get_rxif())
	{
		fwlib_pd_clear_rxif();
		h_pd_of.private.n_derailment_cnt= 0;
		
		h_pd.output.rcv_sop = (unsigned char)((APP_PDSOP>> 3)& 0x07);
		if(((h_pd.output.rcv_sop == PD_SOP1)
		||(h_pd.output.rcv_sop == PD_SOP2))
		&&((h_typeca.output.state == ATTACHED_SNK)
		||(h_typecb.output.state == ATTACHED_SNK)))
		{
			APP_FIFOCTL1|= (1<< 7);
		}else
		{
			h_pd.private.b_pd_receive_if= SET;
		}
	}else if(fwlib_pd_get_txif())
	{
		fwlib_pd_clear_txif();
		h_pd.private.b_pd_trans_if= SET;
		h_pd_of.private.n_derailment_cnt= 0;
	}
}



void pd_interrupt_polling(void)
{
//	if(h_pd.private.b_pd_timeout_if)
//	{
//		h_pd.private.b_pd_timeout_if= false;
//		pd_time_out_handler();
//	}else if(h_pd.private.b_pd_receive_if)
//	{
//		h_pd.private.b_pd_receive_if= false;
//		pd_read();
//	}else if(h_pd.private.b_pd_trans_if)
//	{
//		h_pd.private.b_pd_trans_if= false;
//		pd_trans_complete_handler();
//	}
	//////////////////////////////
		if(h_pd.private.b_pd_timeout_if)////////////  4-9 修改/////
	{
		h_pd.private.b_pd_timeout_if= false;
		pd_time_out_handler();
	}else if(h_pd.private.b_pd_receive_if)
	{
		h_pd.private.b_pd_receive_if= false;
		pd_read();
		if((h_pd.output.rcv_sop != PD_SOP1)&&(h_pd.output.rcv_sop != PD_SOP2))
		{
			plug_state_context.pd_work = true;
		}
	}else if(h_pd.private.b_pd_trans_if)
	{
		h_pd.private.b_pd_trans_if= false;
		pd_trans_complete_handler();
	}
	
	
}


