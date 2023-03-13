/*
 * LCD_Prog.c

 *
 *  Created on: Sep 3, 2022
 *      Author: Mahmoud Elsheemy
 */

#include "STD_Types.h"
#include "BIT_Math.h"
#include "LCD_Interface.h"
#include "LCD_Extra.h"
#include "DIO_Init.h"
#include <util/delay.h>
#include <string.h>

void LCD_WriteCommand(u8 LCD_Command)
{
	//CLEAR RS AND RW
	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS,LOW);
	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW,LOW);

	//SET PORT COMMAND
	DIO_SetPortValue(LCD_DATA_PORT,LCD_Command);

	//E1 FOR 1 MS
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_E,HIGH);
	_delay_ms(1);
	//RESET E1
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_E,LOW);

}

void LCD_WriteData(u8 LCD_Data)
{
	//SET RS AND RESET RW
	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS,HIGH);
	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW,LOW);

	//SET PORT DATA COMMAND
	DIO_SetPortValue(LCD_DATA_PORT,LCD_Data);

	//E1 FOR 1 MS
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_E,HIGH);
	_delay_ms(1);
	//RESET E1
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_E,LOW);
}


void LCD_Init()
{
	//INITIALIZE PORTS DIRECTION
	DIO_SetPortDirection(LCD_DATA_PORT,OUTPUT);
	DIO_SetPortDirection(LCD_CONTROL_PORT,OUTPUT);
	//DELAY FOR 40ms
	_delay_ms(40);
	//FUNCTION SET COMMAND
	LCD_WriteCommand(LCD_FUNCTION_SET);
	//DELAY FOR 40US
	_delay_us(40);
	//DISPLAY ON
	LCD_WriteCommand(LCD_DISPLAY_ON);
	//DELAY FOR 40US
	_delay_us(40);
	//DISPLAY CLEAR
	LCD_WriteCommand(LCD_DISPLAY_CLEAR);
	//WAIT FOR 2MS
	_delay_ms(2);
	//entry mode
	LCD_WriteCommand(LCD_ENTRY_MODE_INCREMENT_NOSHIFT);

}


void LCD_WriteNum(u32 Num, u8 dp)
{
	u16 Val = Num;
	u16 n = 0;
	while(Val > 0)
	{
		n++;
		Val = Val / 10;
	}
	u16 num_array[n];
	s16 i = 0;
	while(Num > 0)
	{
		num_array[i] = (Num%10) + 48;
		Num = Num / 10;
		i++;
	}
	for(i=(n-1);i>=0;i--)
	{
		LCD_WriteChar(num_array[i]);
		if(dp && dp == i)
		{
			LCD_WriteChar(0xA5);
		}
	}
}

void LCD_WriteStr(u8 str[])
{

	u16 i;
	for(i=0;i<strlen(str);i++)
	{
		LCD_WriteChar(str[i]);
	}

}

void LCD_SetCursor(u8 X,u8 Y)
{
	LCD_WriteCommand((X+LCD_START_POS)+(LCD_VERTICAL_INCREMENT*Y));
}


void LCD_CustomCharsInit()
{
	//set CG_RAM address to AC
//	LCD_WriteCommand(LCD_CGRAM_ADDRESS);
//	u16 i;
//	for(i=0;i<sizeof(LCD_ExtraChars);i++)
//	{
//		LCD_WriteChar(LCD_ExtraChars[i]);
//	}

}


void LCD_WriteStrSin(u8 LCD_STR[], u8 NumOfIterations)
{
	u8 i,j,cursor_x;
	u8 toggle = 0;
	for(i=0;i<NumOfIterations;i++)
	{
		LCD_WriteCommand(LCD_DISPLAY_CLEAR);
		cursor_x = i;
		for(j=0;j<strlen(LCD_STR);j++)
		{
			//character swap
//			if(j%2==toggle)
//			{
//				LCD_SetCursor(cursor_x,0);
//			}
//			else
//			{
//				LCD_SetCursor(cursor_x,1);
//			}

			//word swap
			if(LCD_STR[j] == ' ')
			{
				toggle=!toggle;
			}
			else
			{
				LCD_SetCursor(cursor_x,toggle);
				cursor_x++;
				LCD_WriteChar(LCD_STR[j]);
			}
		}
		_delay_ms(500);

	}
}

void LCD_WriteChar(u8 LCD_Data)
{
	//SET RS AND RESET RW
	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS,HIGH);
	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW,LOW);

	//SET PORT DATA COMMAND
	DIO_SetPortValue(LCD_DATA_PORT,LCD_Data);

	//E1 FOR 1 MS
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_E,HIGH);
	_delay_ms(1);
	//RESET E1
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_E,LOW);

}
