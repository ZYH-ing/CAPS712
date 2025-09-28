#include "lib_prot_pd.h"

#include "mod_input_output.h"
#include "mod_display.h"
#include "mod_queue.h"

#include "app_typec_deal.h"
#include "app_init.h"
#include "lib_multi_protocol.h"
#include "app_state_machine.h"
uint8_t typeca_ufp= 0;
uint8_t Type_ca_charge_in= 0;
uint8_t Type_cb_charge_in= 0;
uint8_t MiroB_charge_in= 0;

//void typeca_hard_reset_cb(void)
//{
//	static uint8_t b_typec_hard_reset_lock= RESET;
//
//	if(h_pd.output.b_source_read_hard||		\
//		h_pd.output.b_sink_read_hard)
//	{
//		if(b_typec_hard_reset_lock== RESET)
//		{
//			b_typec_hard_reset_lock= SET;
//			
//			mod_queue_send(PLUG_CA_RST_P);
//		}
//	}
//	else
//	{
//		if(b_typec_hard_reset_lock)
//		{
//			b_typec_hard_reset_lock= RESET;
//			
//			mod_queue_send(PLUG_CA_RST_N);
//		}
//	}
//}

void typecx_hard_reset_cb(bank1 typec_handle_t * p_h_typec)
{
	if((h_pd.output.hardrst_instance == TYPECA)&&(p_h_typec->input.instance == TYPECA))
	{
		if(	h_pd.output.b_source_read_hard ||		\
			h_pd.output.b_sink_read_hard)
		{
			if(p_h_typec->private.b_typec_hard_reset_lock== RESET)
			{
				p_h_typec->private.b_typec_hard_reset_lock= SET;
				mod_queue_send(PLUG_CA_RST_P);
			}
		}else
		{
			if(p_h_typec->private.b_typec_hard_reset_lock)
			{
				p_h_typec->private.b_typec_hard_reset_lock= RESET;
				mod_queue_send(PLUG_CA_RST_N);
			}
		}
	}
	else if((h_pd.output.hardrst_instance == TYPECB)&&(p_h_typec->input.instance == TYPECB))
	{
		if(	h_pd.output.b_source_read_hard ||		\
			h_pd.output.b_sink_read_hard)
		{
			if(p_h_typec->private.b_typec_hard_reset_lock== RESET)
			{
				p_h_typec->private.b_typec_hard_reset_lock= SET;
				mod_queue_send(PLUG_CB_RST_P);
			}
		}else
		{
			if(p_h_typec->private.b_typec_hard_reset_lock)
			{
				p_h_typec->private.b_typec_hard_reset_lock= RESET;
				mod_queue_send(PLUG_CB_RST_N);
			}
		}
	}

}




void typecb_hard_reset_cb(void)
{
//	static uint8_t b_typec_hard_reset_lock= RESET;

//	if(h_pd.output.b_source_read_hard||		\
//		h_pd.output.b_sink_read_hard)
//	{
//		if(b_typec_hard_reset_lock== RESET)
//		{
//			b_typec_hard_reset_lock= SET;
//			
//			mod_queue_send(PLUG_CB_RST_P);
//		}
//	}else
//	{
//		if(b_typec_hard_reset_lock)
//		{
//			b_typec_hard_reset_lock= RESET;
//			
//			mod_queue_send(PLUG_CB_RST_N);
//		}
//	}
}

void typeca_pr_swap_cb(void)
{
	static uint8_t b_pd_power_role_swap_lock;

	if(h_pd.output.b_pr_swap_en)
	{
		if(h_pd.output.b_source_read_pr_swap)
		{
			b_pd_power_role_swap_lock= SET;
			/*用户代码*/
			//关 VBus
		}
		else if(h_pd.output.b_sink_read_pr_swap)
		{
			/*用户代码*/
			//DC-DC 进入放电状态,升压,打开 VBus
		}
	}else
	{
		b_pd_power_role_swap_lock= RESET;
	}
}


void typecb_pr_swap_cb(void)
{
	static uint8_t b_pd_power_role_swap_lock;

	if(h_pd.output.b_pr_swap_en)
	{
		if(h_pd.output.b_source_read_pr_swap)
		{
			b_pd_power_role_swap_lock= SET;
			/*用户代码*/
			//关 VBus
		}else if(h_pd.output.b_sink_read_pr_swap)
		{
			/*用户代码*/
			//DC-DC 进入放电状态,升压,打开 VBus
		}
	}else
	{
		b_pd_power_role_swap_lock= RESET;
	}
}

bool typeca_vbus_exist_cb(void)
{
	//判断一下0.8V VBus电压
	return mod_io_typeca_acin();
}

bool typecb_vbus_exist_cb(void)
{
	//判断一下0.8V VBus电压
	return mod_io_typecb_acin();
}

void typeca_attached_src_cb(void)
{
	/**
	 * !!!
	 * 兼容性测试需要
	 */
//	mod_io_a1d_out();
//     if(Out_Protest_Flage)///// 如果限制输出了 笔记本不能输出//// 取消
//	{
//	  if(!Bat_low_sleep_flage)
//	  {
//		  typec_break(&h_typeca);
//		  peripheral_typec_UFP_init(&h_typeca);
//	//	  typec_break(&h_typeca);
//		  Bat_low_sleep_flage=1;
//	  }
//	  return;
//	}
//	
//	if(Bat_low_sleep_flage)
//	  return;
	  
    if((!MiroB_charge_in)&&(!f_car_jump))//// B口充电 或者夹子插入 不能输出/////	
    {
//        if((Bat_low_Cnt>=30)||(!Temp.DischargeTemp_OK))
//        {
//		    Bat_low_sleep_flage=1;
//        }
//        else
//        {
            mod_queue_send(PLUG_CAD_IN);
//        }
    }
}

void typecb_attached_src_cb(void)
{
//	mod_io_a1d_out();
//	mod_queue_send(PLUG_CBD_IN);
}

void typeca_attached_snk_cb(void)
{
//     if(USBA_IN_DIS)
//	{
////	 mod_io_a1d_out();
//	}
	mod_queue_send(PLUG_CAC_IN);
	typeca_ufp = 1;
	Type_ca_charge_in=1;
}

void typecb_attached_snk_cb(void)
{
//	mod_queue_send(PLUG_CBC_IN);
//	typeca_ufp = 1;
//	Type_cb_charge_in=1;
}

void typeca_unattached_cb(void)
{
	mod_queue_send(PLUG_CAX_OUT);
	typeca_ufp = 0;
	
// 		  #if __IF_DEBUG__
// 		Sub_sim_tx(0xAC);
// 		Sub_sim_tx(0x02);
// //		Sub_sim_tx(0xEE);
// //		Sub_sim_tx(plug_state_context.state.byte& 0x3f);
// 	  #endif
	
//	Type_ca_charge_in=0;
}

void typecb_unattached_cb(void)
{
//	mod_queue_send(PLUG_CBX_OUT);
//	typeca_ufp = 0;/// 新添加
//	Type_cb_charge_in=0;
}


