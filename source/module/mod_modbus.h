#ifndef __MOD_MODBUS_H__
#define __MOD_MODBUS_H__


#include "drv_gpio.h"
#include "mod_dcdc.h "
#include "app_init.h"
#include "drv_uart.h"
#include "lib_prot_pd.h"
#include "lib_prot_typec.h"
#include "lib_prot_typec.h"
#include "lib_multi_protocol.h"
#include "mod_coulomb.h"
#include "mod_queue.h"
#include "mod_input_output.h"

#define SLAVE_ADDRESS 0x12// 从机地址
#define REG_COUNT 10
#define BUFFER_SIZE 16
#define MODBUS_TIMEOUT_MS 249 // 9600bps时约3.65ms		255
// #define MODBUS_TIMEOUT_MS 200 // 9600bps时约3.65ms		255 调试

typedef union
{
	struct
	{
		uint8_t uart_discharge_on_falg_bak	: 1;					
		uint8_t uart_charge_on_falg_bak	: 1;					
		uint8_t charge_vbus_undervol_flag	: 1;				
		uint8_t charge_bat_overvol_flag	: 1;					
		uint8_t user_flag5	: 1;					
		uint8_t user_flag6	: 1;				
		uint8_t user_flag7	: 1;					
		uint8_t plug_refresh	: 1;					
	}bit;
	uint8_t		byte;
}user_flag_t;


typedef struct {
    uint8_t data[BUFFER_SIZE];    // 数据存储数组
    volatile uint8_t length;      // 当前数据长度
    volatile uint8_t ready;       // 数据就绪标志
} Buffer;


extern bank2  uint8_t 	holdingRegisters[REG_COUNT];
extern bank2  Buffer    rxBuffers[2]; // 声明两个缓冲区的数组
extern bank2  uint8_t   activeBuffer; //
// extern bank2  uint8_t   processingBuffer; // 
extern bank2  uint8_t   lastRxTime;
extern bank2  Buffer *  buf; 
extern bank2  Buffer *  p_buffer;
extern bank2  user_flag_t user_flag;
extern bank2  uint8_t 	  now_power_number;



extern void check_frame_timeout(void);
extern void process_modbus_frame(void);
extern void init_buffers(void);
extern uint16_t modbus_crc16(uint8_t *data, uint8_t length);
extern void handle_read_registers( uint8_t *response, uint8_t *length); 
extern void handle_write_register( uint8_t *response, uint8_t *length);
extern void UART_Transmit(uint8_t *response, uint8_t responseLength);
extern void modus_event_proc(void);

#endif