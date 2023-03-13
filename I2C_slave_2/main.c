/*
 * main.c
 *
 *  Created on: Mar 3, 2023
 *      Author: mahmo
 */
#define F_CPU 8000000UL
#include "STD_Types.h"
#include "LCD_Interface.h"
#include "I2C_Init.h"
#include <avr/delay.h>
#include <string.h>


u8 buff_rec[][10];
u8 buff_rec2[][10];
u8 x1 [8][10];
u8 x2 [16][10];
int r[8];
void Slave_calc(u8 m1[][10] , u8 m2 [][10]){

	for ( u16 i = 0 ; i < 2 ; i++ ){
		for ( u16 j = 0 ; j < 4 ; j++){
			int sum = 0;
			for( u16 k = 0; k < 4 ; k++){
				sum += atoi(m1[ k + i * 4 ] ) * atoi(m2[ j + k * 4 ] );
			}
			r[ j +i * 4] = sum;
		}
	}

}
void main()
{
	LCD_Init();
	I2C_Handle handle;
	handle.address = 0x04;
	handle.clock = I2C_CLOCK_200KHZ;
	for( u16 i = 0;i <16 ; i++){
	handle.receiveBuff = buff_rec[i];
	handle.receiveBuffLen = 10;
	handle.mode = I2C_SLAVE_RECEIVE_MODE;
	I2C_Init(&handle);
	I2C_Slave_Read(&handle);
	strcpy(x2[i],handle.receiveBuff);
//	LCD_WriteStr(handle.receiveBuff);
//	if(i == 11){
//		LCD_SetCursor(0,1);
//	}
	}
	for( u16 i = 0;i <8 ; i++){
		handle.receiveBuff = buff_rec2[i];
		handle.receiveBuffLen = 10;
		handle.mode = I2C_SLAVE_RECEIVE_MODE;
		I2C_Init(&handle);
		I2C_Slave_Read(&handle);
		strcpy(x1[i],handle.receiveBuff);
//		LCD_WriteStr(x1);
//		LCD_WriteStr(",");
		}
	Slave_calc(x1,x2);
	for (int i=0;i<8;i++){
//				LCD_WriteStr(x2[i]);
//				LCD_WriteStr(",");
		LCD_WriteNum(r[i],0);
			LCD_WriteStr(".");
				if(i == 3){
					LCD_SetCursor(0,1);
				}
	}
	u8 temp[8][10];
	for(u16 i = 0;i<8;i++){
		sprintf(temp[i], "%d", r[i]);

	}

	for (u16 i =0; i <8;i++){
		handle.sendBuff = temp[i];
		handle.sendBuffLen = 10;
		I2C_Init(&handle);
		I2C_Start(0x06);
		_delay_ms(10);
		I2C_Master_Write(&handle);
		I2C_End();

	}



}
