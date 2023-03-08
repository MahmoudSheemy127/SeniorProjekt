/*
 * main.c
 *
 *  Created on: Mar 7, 2023
 *      Author: mahmo
 */
#define F_CPU 8000000UL
#include "STD_Types.h"
#include "I2C_Init.h"
#include <avr/delay.h>

void main(void)
{
	//Master code
	u8 buffer[] = "Hello";
	I2C_Handle handle;
	handle.address = 0x01;
	handle.clock = I2C_CLOCK_200KHZ;
	handle.sendBuff = buffer;
	handle.sendBuffLen = 5;
	I2C_Init(&handle);
	I2C_Start(0x02);
	_delay_ms(10);
	I2C_Master_Write(&handle);
	I2C_End();

//Slave code
//	I2C_Handle handle;
//	handle.address = 0x02;
//	handle.clock = I2C_CLOCK_200KHZ;
//	handle.receiveBuff = buff_rec;
//	handle.receiveBuffLen = 5;
//	handle.mode = I2C_SLAVE_RECEIVE_MODE;
//	I2C_Init(&handle);
//	I2C_Slave_Read(&handle);
//	LCD_WriteCommand(LCD_DISPLAY_CLEAR);
//	LCD_WriteStr(handle.receiveBuff);

}
