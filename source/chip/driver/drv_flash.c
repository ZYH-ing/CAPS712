/**************************************************************************//**
 * @file     drv_flash.c
 * @version  V1.0.0
 * @author   0531
 * @date     2020-10-10 AM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 *****************************************************************************/

// Include header file.
#include "drv_flash.h"


/**@brief flash erase one sector(512Byte).
 * 
 * @param[in]  uint16_t _address	flash address(sector alignment).
 * @param[in]  null     .
 * @param[out] null     .
 * 
 * @return  bool error:	true, false
 */
bool flash_erase(uint16_t _address)
{
	bool error= true;
	uint16_t sector_addr;
	sector_addr= _address>> C_FLASH_SECTOR_SIZE_SHIFT;
	sector_addr<<= C_FLASH_SECTOR_SIZE_SHIFT;
	
	/** 0. backup GIE, turn off GIE**/
	bool backup_gie;
	backup_gie= GIE;
	GIE= 0;

	/** 1. Read the BUSY bit of the ISPSR register to 	
	confirm that the last programming operation has ended;**/
	do
	{
		
	}while(__FLASH_BSY_GET_SHIFT());
	
	/** 2. Write ISPEN=1 to enable erasing the Flash; 
	write CMD=0A to enable the Flash sector erasing function;**/
	__FLASH_ISPEN_SET_SHIFT(FLASH_ISPEN_EN);
	__FLASH_CMD_SET(0x0A);
	
	/** 3. Write the sector address to be erased 
	into the EADRH and EADRL registers;**/
	__FLASH_EADRH_SET((sector_addr>> 8)& 0xFF);
	__FLASH_EADRL_SET(sector_addr& 0xFF);
	
	/** 4. Write 96H, 69H, 5AH to the WRPRT register continuously, 
	and read the UNLOCK register to confirm that it has been unlocked successfully;**/
	__FLASH_WRPRT_SET(0x96);
	__FLASH_WRPRT_SET(0x69);
	__FLASH_WRPRT_SET(0x5A);
	
	if(__FLASH_UNLOCK_GET_SHIFT()== FLASH_UNLOCK_UNLOCK)
	{
		__FLASH_START_SET_SHIFT(FLASH_START_EN);
		do
		{
			
		}while(__FLASH_BSY_GET_SHIFT());
	}else
	{
		error|= false;
	}
	
	/** 5. restore GIE**/
	if(backup_gie)
	{
		GIE= 1;
	}else
	{
		GIE= 0;
	}

	return error;
}


/**@brief flash read data.
 * 
 * @param[in]  uint16_t _address	flash address.
 * @param[in]  uint16_t *_data		read data buffer.
 * @param[in]  uint8_t _length		read data length.
 * @param[out] null     .
 * 
 * @return  bool error:	true, false
 */
bool flash_read(uint16_t _address, uint16_t *_data, uint8_t _length)
{
	bool error= true;
	uint8_t i;
	uint16_t flash_addr;
	uint16_t *p_data= _data;
	uint16_t timeout_cnt= 0;
	
	/** 1. Read the BUSY bit of the ISPSR register to 	
	confirm that the last programming operation has ended;**/
	do
	{
		
	}while(__FLASH_BSY_GET_SHIFT());
	
	/** 2. Write CMD=00 to turn on the Flash writing function;**/
	__FLASH_CMD_SET(0x00);
	
	/** 3. Write the address to be operated 
	into the EADRH and EADRL registers;**/
	for(i= 0; i< _length; i++)
	{
		flash_addr= _address+ i;
		__FLASH_EADRH_SET((flash_addr>> 8)& 0xFF);
		__FLASH_EADRL_SET(flash_addr& 0xFF);
		__FLASH_START_SET_SHIFT(FLASH_START_EN);
		do
		{
			timeout_cnt++;
		}while((__FLASH_BSY_GET_SHIFT()!= FLASH_BSY_RESET)&& (timeout_cnt< 65000));	
		if(timeout_cnt>= 65000)
		{
			error|= false;
			break;
		}
		*p_data= __FLASH_EDATL_GET();
		*p_data|= (__FLASH_EDATH_GET()<< 8)& 0xFF00;
		p_data++;
	}
	
	return error;
}


/**@brief flash write data.
 * 
 * @param[in]  uint16_t _address	flash address.
 * @param[in]  uint16_t *_data		write data buffer.
 * @param[in]  uint8_t _length		write data length.
 * @param[out] null     .
 * 
 * @return  bool error:	true, false
 */
bool flash_write(uint16_t _address, uint16_t *_data, uint8_t _length)
{
	bool error= true;
	uint8_t i;
	_flash_t	flash_t;
	uint16_t flash_addr;
	uint16_t *p_data= _data;
	uint16_t timeout_cnt= 0;
	uint16_t sector_addr;
	uint8_t offset_addr;
	sector_addr= _address>> C_FLASH_SECTOR_SIZE_SHIFT;
	sector_addr<<= C_FLASH_SECTOR_SIZE_SHIFT;
	offset_addr= _address& C_FLASH_SECTOR_SIZE;
	
	/** 0. backup GIE, turn off GIE**/
	bool backup_gie;
	backup_gie= GIE;
	GIE= 0;
	
	/** 1. Read sector data**/
	error|= flash_read(sector_addr, flash_t.cache, C_FLASH_SECTOR_SIZE);

	/** 2. Rewrite data**/
	for(i= 0; i< _length; i++)
	{
		flash_t.cache[offset_addr+ i]= *p_data;
		p_data++;
	}
	
	/** 3. Erase sector**/
	error|= flash_erase(_address);

	/** 4. Write data**/
	/*** 4.1. Read the BUSY bit of the ISPSR register to 	
	confirm that the last programming operation has ended;***/
	do
	{
		
	}while(__FLASH_BSY_GET_SHIFT());
	
	/*** 4.2. Write CMD=05, turn on the write Flash function;***/
	__FLASH_CMD_SET(0x05);

	/*** 4.3. Write the address to be operated 
	into the EADRH and EADRL registers;***/
	p_data= flash_t.cache;
	for(i= 0; i< C_FLASH_SECTOR_SIZE; i++)
	{
		flash_addr= sector_addr+ i;
		__FLASH_EADRH_SET((flash_addr>> 8)& 0xFF);
		__FLASH_EADRL_SET(flash_addr);
		timeout_cnt= 0;
		do
		{
			timeout_cnt++;
		}while((__FLASH_BSY_GET_SHIFT()!= FLASH_BSY_RESET)&& (timeout_cnt< 65000));	
		if(timeout_cnt>= 65000)
		{
			error|= false;
		}else
		{
			/*** 4.4. Write the data to be written 
			into the EDATH and EDATL registers;***/
			__FLASH_EDATL_SET(*p_data& 0xFF);
			__FLASH_EDATH_SET((*p_data>> 8)& 0xFF);
			p_data++;

			/*** 4.5. Write 96H, 69H, 5AH to the WRPRT register continuously, 
			and read the UNLOCK register to confirm that it has been unlocked successfully;***/
			__FLASH_WRPRT_SET(0x96);
			__FLASH_WRPRT_SET(0x69);
			__FLASH_WRPRT_SET(0x5A);
			
			if(__FLASH_UNLOCK_GET_SHIFT()== FLASH_UNLOCK_UNLOCK)
			{
				__FLASH_START_SET_SHIFT(FLASH_START_EN);
				do
				{
					
				}while(__FLASH_BSY_GET_SHIFT());
			}else
			{
				error|= false;
				break;
			}
		}
	}
	
	/** 5. restore GIE**/
	if(backup_gie)
	{
		GIE= 1;
	}else
	{
		GIE= 0;
	}

	return error;
}

