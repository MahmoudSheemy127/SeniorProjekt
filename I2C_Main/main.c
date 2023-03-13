/*
 * main.c
 *
 *  Created on: Mar 7, 2023
 *      Author: mahmo
 */
#define F_CPU 8000000UL
#include "STD_Types.h"
#include "LCD_Interface.h"
#include "USART.h"

#include "I2C_Init.h"
#include <avr/delay.h>
u8 half1[8][10], half2[8][10],mat2[16][10];
u8 buff_rec1[8][10],buff_rec2[8][10];
u8 x1[8][10],x2[][10];

u8 r[][10];



void divide( u8 array[][10], u16 numberOfElements )
{
    u8 mat1[numberOfElements/2][10];
    // mat2[numberOfElements/2][10];
//    u8 half1[numberOfElements/4][10], half2[numberOfElements/4][10];
    u16 k = 0, l = 0;
    for(u16 i = 0; i < numberOfElements; i++)
    {
        if(i < numberOfElements/2)
        {
            if(i < numberOfElements/4)
            {
                //memcpy(mat1[i], array[i], sizeof(array[i]));
                memcpy(half1[i], array[i], sizeof(array[i]));
            }
            else
            {
                //memcpy(mat1[i], array[i], sizeof(array[i]));
                memcpy(half2[k], array[i], sizeof(array[i]));
                k++;
            }
        }
        else
        {
            memcpy(mat2[l], array[i], sizeof(array[i]));
            l++;
        }
    }
}

void combine( u8 array1[][10], u8 array2[][10], u8 array3[][10], u8 numberOfElements )
{
    u16 j = 0;
    for(u16 i = 0; i < numberOfElements; i++)
    {
        if(i < numberOfElements/2)
//            memcpy(array3[i], array1[i], sizeof(array1[i]));
        		strcpy(array3[i], array1[i]);
        else
        {
//            memcpy(array3[i], array2[j], sizeof(array1[j]));
            strcpy(array3[i], array2[j]);
            j++;
        }
    }
}


void main(void)
{
	USART_initialize();
	LCD_Init();
	u8 m2[][10]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16"};
	divide(m2,32);

	//Master code
	I2C_Handle handle;
	handle.address = 0x06;
	handle.clock = I2C_CLOCK_200KHZ;

	//Send mat to slave 1
	for (u16 i =0; i < 16;i++)
	{

		handle.sendBuff = mat2[i];
		handle.sendBuffLen = 10;
		I2C_Init(&handle);
		I2C_Start(0x02);
		_delay_ms(10);
		I2C_Master_Write(&handle);
		I2C_End();

	}

	//Send first have to slave 1
	for (u16 i =0; i <8;i++)
	{

		handle.sendBuff = half1[i];
		handle.sendBuffLen = 10;
		I2C_Init(&handle);
		I2C_Start(0x02);
		_delay_ms(10);
		I2C_Master_Write(&handle);
		I2C_End();

	}

	//receive first have of mat_result frome slave 1
	for( u16 i = 0;i <8 ; i++)
	{

		handle.receiveBuff = buff_rec1[i];
		handle.receiveBuffLen = 20;
		handle.mode = I2C_SLAVE_RECEIVE_MODE;
		I2C_Init(&handle);
		I2C_Slave_Read(&handle);
		strcpy(x1[i],handle.receiveBuff);
//		LCD_WriteStr(x1[i]);
//		if(i==3)
//			LCD_SetCursor(0,1);

	}


	for(int i=0;i<8;i++)
	{

		LCD_WriteStr(x1[i]);
		if( i == 3){

			LCD_SetCursor(0,1);

		}
		LCD_WriteChar(',');
	}

	//sent mat to slave 2
	for (u16 i =0; i < 16;i++)
	{

		handle.sendBuff = mat2[i];
		handle.sendBuffLen = 10;
		I2C_Init(&handle);
		I2C_Start(0x04);
		_delay_ms(10);
		I2C_Master_Write(&handle);
		I2C_End();

	}

	//send second have to slave 2
	for (u16 i =0; i <8;i++)
	{

		handle.sendBuff = half2[i];
		handle.sendBuffLen = 10;
		I2C_Init(&handle);
		I2C_Start(0x04);
		_delay_ms(10);
		I2C_Master_Write(&handle);
		I2C_End();

	}

	//receive second half of mat_result from slave 2
	for( u16 i = 0;i <8 ; i++)
	{

		handle.receiveBuff = buff_rec2[i];
		handle.receiveBuffLen = 10;
		handle.mode = I2C_SLAVE_RECEIVE_MODE;
		I2C_Init(&handle);
		I2C_Slave_Read(&handle);
		strcpy(x2[i],handle.receiveBuff);


	}
		LCD_WriteCommand(LCD_DISPLAY_CLEAR);

	for(int i=0;i<8;i++)
	{

		LCD_WriteStr(x2[i]);
		if( i == 3){

			LCD_SetCursor(0,1);

		}
		LCD_WriteChar(',');
	}

//	_delay_ms(2000);
//	LCD_WriteCommand(LCD_DISPLAY_CLEAR);
//
//	for(int i=0;i<8;i++)
//	{
//
//		LCD_WriteStr(x1[i]);
//		if( i == 3){
//
//			LCD_SetCursor(0,1);
//
//		}
//		LCD_WriteChar(',');
//	}
//		LCD_WriteCommand(LCD_DISPLAY_CLEAR);
//		combine(x2,x1,r,16);
//		for(int i=0;i<16;i++)
//		{
//
//			LCD_WriteStr(r[i]);
//			if( i == 3){
//
//				LCD_SetCursor(0,1);
//
//			}
//			LCD_WriteChar('.');
//			if( i == 7){
//				_delay_ms(2000);
//				LCD_WriteCommand(LCD_DISPLAY_CLEAR);
//
//			}
//		}

	for( u16 i = 0 ; i<8;i++)
	{
		USART_send_string(x1[i]);
		USART_send_char(',');

	}
	USART_send_string("\n");
	for( u16 i = 0 ; i<8;i++)
		{
			USART_send_string(x2[i]);
			USART_send_char(',');

		}


}
