#include "mod_modbus.h"

// #include "app_main.h"
// #include "app_init.h"
//

// #define SLAVE_ADDRESS 0x12
// #define REG_COUNT 16
// #define BUFFER_SIZE 32
// #define MODBUS_TIMEOUT_MS 4 // 9600bps鏃剁害3.65ms

// typedef struct {
//     uint8_t data[BUFFER_SIZE];
//     volatile uint16_t length;
//     volatile uint8_t ready;
// } Buffer;

bank2 uint8_t holdingRegisters[REG_COUNT];// 寄存器对应数据
bank2 Buffer rxBuffers[2];
bank2 uint8_t activeBuffer;
// bank2 uint8_t processingBuffer;
bank2 uint8_t lastRxTime;
bank2 Buffer *buf;
bank2 Buffer *p_buffer;
bank2 user_flag_t user_flag;
bank2 uint8_t now_power_number;



// CRC检验
uint16_t modbus_crc16(uint8_t *data, uint8_t length)
{
	uint16_t crc = 0xFFFF;

	for (uint8_t i = 0; i < length; i++)
	{
		crc ^= data[i];

		for (uint8_t j = 0; j < 8; j++)
		{
			if (crc & 0x0001)
			{
				crc = (crc >> 1) ^ 0xA001;
			}
			else
			{
				crc = crc >> 1;
			}
		}
	}
	return crc;
}

// 初始化缓冲区
void init_buffers(void)
{
	for (int i = 0; i < 2; i++)
	{
		rxBuffers[i].length = 0;// 长度清零
		rxBuffers[i].ready = 0;	// 就绪标志清零
	}
	activeBuffer = 0;			// 从缓冲区0开始使用
	// processingBuffer = 0;
}

// 检查帧超时
void check_frame_timeout(void)
{
	buf = &rxBuffers[activeBuffer];
	// 缓冲区中有数据 且 距离上次接收已超时
	if (buf->length > 0 && (MODBUS_TIMEOUT_MS > lastRxTime))
	{
		buf->ready = 1;// 标记当前缓冲区数据就绪
		activeBuffer = (activeBuffer + 1) % 2;// 切换到另一个缓冲区

		// 初始化新激活的缓冲区
		rxBuffers[activeBuffer].length = 0;
		rxBuffers[activeBuffer].ready = 0;
	}
}

// 处理ModBus帧：判断主机发来的帧是否合法，并根据功能码执行对应的处理
void process_modbus_frame(void)
{
	uint8_t response[BUFFER_SIZE];// 从机组包好返回给主机的数据
	uint8_t responseLength = 0;


/////////////////////////////////////////////////////////////////////////////////
	// uart_putchar(0xAA);  // 开始标记
    // uart_putchar(activeBuffer);  // 缓冲区索引
    // uart_putchar(p_buffer->length);  // 数据长度
    
    // for (uint8_t i = 0; i < p_buffer->length; i++) {
    //     uart_putchar(p_buffer->data[i]);  // 打印所有数据
    // }
    // uart_putchar(0xBB);  // 结束标记
//////////////////////////////////////////////////////////////////////////////////

	// 帧长度至少需要4字节（地址+功能码+长度+CRC） 或 地址不对
	if ((p_buffer->length < 4) || (p_buffer->data[0] != SLAVE_ADDRESS))
	{
		p_buffer->ready = 0;
		p_buffer->length = 0;
		//        uart_putchar(0x01);
		return;
	}

	// 取CRC值进行校验（低位在前）
	uint16_t crcReceived = (p_buffer->data[p_buffer->length - 1] << 8) |
						   p_buffer->data[p_buffer->length - 2];
	uint16_t crcCalculated = modbus_crc16((uint8_t *)(uint32_t)p_buffer->data, p_buffer->length - 2);

	if (crcReceived != crcCalculated)
	{
		p_buffer->ready = 0;
		// uart_putchar(0x03);
		return;
	}

	switch (p_buffer->data[1])
	{
		case 0x03:// 读保持寄存器
			handle_read_registers(response, &responseLength);
			// UART_Transmit(p_buffer->data[0],5);
			break;

		case 0x06:// 写单个寄存器
			handle_write_register(response, &responseLength);
			// UART_Transmit(p_buffer->data[0],5);
			break;

		default:// 不支持的功能码
			response[0] = p_buffer->data[0];
			response[1] = p_buffer->data[1] | 0x80;
			response[2] = 0x01;
			uint16_t crc = modbus_crc16(response, 3);
			response[3] = crc & 0xFF;
			response[4] = crc >> 8;
			responseLength = 5;
			// UART_Transmit(p_buffer->data[0],5);
			break;
	}
	//   uart_putchar(0x04);

	if (responseLength > 0)
	{
		UART_Transmit(response, responseLength);// 通过UART发送响应
		//       uart_putchar(0xAA);
	}
	p_buffer->ready = 0;// 处理完成，清除就绪标志
	
}

// 处理读寄存器请求：根据主机要读的寄存器地址与读取长度，组包返回给主机的数据
void handle_read_registers(uint8_t *response, uint8_t *length)
{
	// 若读取寄存器地址高位不为0 或 读取寄存器长度高位不为0 或 读取长度大于10 或 读取寄存器低地址+读取长度大于10
	if ((p_buffer->data[2] != 0) || (p_buffer->data[4] != 0) || (p_buffer->data[5] > REG_COUNT) || ((p_buffer->data[3] + p_buffer->data[5]) > REG_COUNT))
	{
		response[0] = p_buffer->data[0];
		response[1] = p_buffer->data[1] | 0x80;
		response[2] = 0x02;
		uint16_t crc = modbus_crc16(response, 3);
		response[3] = crc & 0xFF;
		response[4] = crc >> 8;
		*length = 5;
		return;
	}

	// 参数正常时，组包返回数据
	response[0] = p_buffer->data[0];
	response[1] = 0x03;
	response[2] = p_buffer->data[5];

	for (uint8_t i = 0; i < p_buffer->data[5]; i++)// p_buffer->data[5]读取长度低位
	{
		response[3 + i] = holdingRegisters[p_buffer->data[3] + i];// p_buffer->data[3]读取寄存器地址低位
	}

	*length = 3 + p_buffer->data[5];
	uint16_t crc = modbus_crc16(response, *length);
	response[*length] = crc & 0xFF;
	response[*length + 1] = crc >> 8;
	*length += 2;

	//     uint8_t regCount = (p_buffer->data[5] - p_buffer->data[3]);

	//    if((p_buffer->data[2] != 0) || (p_buffer->data[4] != 0) || (regCount > REG_COUNT))
	//    {
	//         response[0] = p_buffer->data[0];
	//         response[1] = p_buffer->data[1] | 0x80;
	//         response[2] = 0x02;
	//         uint16_t crc = modbus_crc16(response, 3);
	//         response[3] = crc & 0xFF;
	//         response[4] = crc >> 8;
	//         *length = 5;
	//         return;
	//    }

	//     response[0] = p_buffer->data[0];
	//     response[1] = 0x03;
	//     response[2] = regCount * 2;

	//     for(uint8_t i = 0; i < regCount; i++)
	//     {
	//         response[3+(2*i)] = (holdingRegisters[p_buffer->data[3] + i]) >> 8;
	//         response[4+(2*i)] = (holdingRegisters[p_buffer->data[3] + i]) & 0xFF;
	//     }

	//     *length = 3 + regCount * 2;
	//     uint16_t crc = modbus_crc16(response, *length);
	//     response[*length] = crc & 0xFF;
	//     response[*length + 1] = crc >> 8;
	//     *length += 2;
}

// 处理写寄存器请求
void handle_write_register(uint8_t *response, uint8_t *length)
{
	//   uint8_t regValue = (p_buffer->data[4] << 8) | p_buffer->data[5];
	// 若主机要写入除0x00或0x05以外的寄存器
	if ((p_buffer->data[3] != 0x00) && (p_buffer->data[3] != 0x05))
	{
		response[0] = p_buffer->data[0];
		response[1] = p_buffer->data[1] | 0x80;
		response[2] = 0x02;
		uint16_t crc = modbus_crc16(response, 3);
		response[3] = crc & 0xFF;
		response[4] = crc >> 8;
		*length = 5;
		return;
	}

	// 将数据写入对应寄存器
	if (!(p_buffer->data[3]))// 要写入的寄存器地址为0x00
	{
		holdingRegisters[0] &= 0x0F;
		holdingRegisters[0] |= ((p_buffer->data[4]) & 0xF0);// p_buffer->data[4]写入的数据
	}
	else
	{
		holdingRegisters[p_buffer->data[3]] = p_buffer->data[4];// p_buffer->data[3]写入寄存器地址低位，p_buffer->data[4]写入的数据
	}

	for (int i = 0; i < 5; i++)
	{
		response[i] = p_buffer->data[i];
	}

	uint16_t crc = modbus_crc16(response, 6);
	response[5] = crc & 0xFF;
	response[6] = crc >> 8;
	*length = 7;
}

void UART_Transmit(uint8_t *response, uint8_t responseLength)
{
	if (responseLength >= BUFFER_SIZE)
	{
		return;
	}
	for (uint8_t i = 0; i < responseLength; i++)
	{
		uart_putchar(response[i]);
	}
}

// 处理ModBus事件
void modus_event_proc(void)
{
	switch (R_SysMode_OK)
	{
	// 不充不放
	case 0:
		holdingRegisters[0] &= ~(0x01 << 0); // 充电状态
		holdingRegisters[0] &= ~(0x01 << 1); // 涓流状态
		holdingRegisters[0] &= ~(0x01 << 3); // 放电电状态
		break;

	// 充电
	case 1:
		holdingRegisters[0] |= (0x01 << 0);
		break;

	// 放电
	case 2:
		holdingRegisters[0] |= (0x01 << 3);
		break;

	default:
		break;
	}

	// 若充满电
	if (coulomb_data.output.b_batt_full)
	{
		holdingRegisters[0] |= (0x01 << 2);
	}
	else
	{
		holdingRegisters[0] &= ~(0x01 << 2);
	}

	holdingRegisters[1] = (multi_protocol.input.vbus_vol) >> 8; // 电压高八位
	holdingRegisters[2] = (multi_protocol.input.vbus_vol);		// 电压低八位
	//			holdingRegisters[3] = (multi_protocol.input.ibus_cur)>>8;
	//			holdingRegisters[4] = (multi_protocol.input.ibus_cur);

	holdingRegisters[3] = CIbus_16_date >> 8; // 电流高八位
	holdingRegisters[4] = CIbus_16_date;	  // 电流低八位

	if (holdingRegisters[0] & (0x01 << 5))
	{
		// 停止充电
		if (R_SysMode_OK == COULOMB_CHARGE)
		{
			mod_queue_send(PLUG_CAX_OUT);
		}
		user_flag.bit.uart_charge_on_falg_bak = 0;
	}
	if (!(holdingRegisters[0] & (0x01 << 5)) && !(user_flag.bit.uart_charge_on_falg_bak))
	{
		user_flag.bit.uart_charge_on_falg_bak = 1;
		typec_break(&h_typeca);
	}
	if (holdingRegisters[0] & (0x01 << 4))
	{
		// 停止放电
		if (R_SysMode_OK == COULOMB_DISCHARGE)
		{
			mod_queue_send(PLUG_CAX_OUT);
		}
		user_flag.bit.uart_discharge_on_falg_bak = 0;
	}
	if (!(holdingRegisters[0] & (0x01 << 4)) && !(user_flag.bit.uart_discharge_on_falg_bak))
	{
		user_flag.bit.uart_discharge_on_falg_bak = 1;
		typec_break(&h_typeca);
	}

	// 放电功率设置
	switch (holdingRegisters[5] & 0x0F)
	{
	case 0:
		if ((now_power_number & 0x0F) != 0)
		{
			now_power_number &= 0XF0;
			app_power_capabilities_switch_h();
		}
		break;

	case 1:
		if ((now_power_number & 0x0F) != 1)
		{
			now_power_number &= 0XF0;
			now_power_number |= 0X01;
			app_power_capabilities_switch_h_1();
		}
		break;

	case 2:
		if ((now_power_number & 0x0F) != 2)
		{
			now_power_number &= 0XF0;
			now_power_number |= 0X02;
			app_power_capabilities_switch_h_2();
		}
		break;

	case 3:
		if ((now_power_number & 0x0F) != 3)
		{
			now_power_number &= 0XF0;
			now_power_number |= 0X03;
			app_power_capabilities_switch_l();
		}
		break;

	default:
		break;
	}

	// 充电功率设置
	vbus_ibus_cheak();
	if (multi_protocol.input.vbus_vol > 650)
		volt_flag = VBUS_VOL_20V;
	else if (multi_protocol.input.vbus_vol > 520)
		volt_flag = VBUS_VOL_15V;
	else if (multi_protocol.input.vbus_vol > 400)
		volt_flag = VBUS_VOL_12V;
	else if (multi_protocol.input.vbus_vol > 320)
		volt_flag = VBUS_VOL_9V;
	else
		volt_flag = VBUS_VOL_5V;

	switch (holdingRegisters[5] & 0xF0)
	{
	case 0X00:
		if ((now_power_number & 0xF0) != 0)
		{
			now_power_number &= 0X0F;
		}
		break;

	case 0X10:
		if ((now_power_number & 0xF0) != 1)
		{
			now_power_number &= 0X0F;
			now_power_number |= 0X10;
		}
		break;

	case 0X20:
		if ((now_power_number & 0xF0) != 2)
		{
			now_power_number &= 0X0F;
			now_power_number |= 0X20;
		}
		break;

	case 0X30:
		if ((now_power_number & 0xF0) != 3)
		{
			now_power_number &= 0X0F;
			now_power_number |= 0X30;
		}
		break;

	default:
		break;
	}
	app_power_adjust(now_power_number);

	// 温度
	//

	// 故障码
	if (Temp.ChargeTemp_OK)
	{
		holdingRegisters[7] &= ~(0x01 << 6);
	}
	else
	{
		holdingRegisters[7] |= (0x01 << 6);
	}

	// 输入电压
	if (R_SysMode_OK == COULOMB_CHARGE)
	{
		// 充电过压
		if (V_NO_Cha_flage && !(user_flag.bit.charge_vbus_undervol_flag))
		{
			holdingRegisters[7] |= (0x01 << 4);
		}
		else
		{
			holdingRegisters[7] &= ~(0x01 << 4);
		}

		// 充电欠压
		if (user_flag.bit.charge_vbus_undervol_flag)
		{
			holdingRegisters[7] |= (0x0001 << 3);
		}
		else
		{
			holdingRegisters[7] &= ~(0x0001 << 3);
		}

		////充电过流
		if (Charge_OCP_Flage)
		{
			holdingRegisters[8] |= (0x01 << 6);
		}
		else
		{
			holdingRegisters[8] &= ~(0x01 << 6);
		}
	}

	// 电池过压
	if (V_NO_BAT_Charge)
	{
		holdingRegisters[7] |= (0x01 << 2);
	}
	else
	{
		holdingRegisters[7] &= ~(0x01 << 2);
	}

	// 电池欠压
	if (hex_greater_than_compare(VBAT_7201_Vaule, 1333))
	{
		holdingRegisters[7] &= ~(0x0001 << 1);
	}
	else
	{
		holdingRegisters[7] |= (0x0001 << 1);
	}

	// //放电过流
	// if (Charge_OCP_Flage)
	// {
	// 	holdingRegisters[7] |= (0x0001<<1);
	// }
	// else
	// {
	// 	holdingRegisters[7] &= ~(0x0001<<1);
	// }

	// 复位pd
}
