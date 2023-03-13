/*
 * LCD_Interface.h
 *
 *  Created on: Sep 3, 2022
 *      Author: mahmo
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_



#endif /* LCD_INTERFACE_H_ */


//define macros

//LCD INSTRUCTIONS
#define LCD_DISPLAY_CLEAR 0x01
#define LCD_RETURN_HOME 0x02
#define LCD_ENTRY_MODE_DECREMENT_NOSHIFT 0x04
#define LCD_ENTRY_MODE_INCREMENT_NOSHIFT 0x06
#define LCD_ENTRY_MODE_INCREMENT_SHIFT 0x07
#define LCD_DISPLAY_ON 0X0C
#define LCD_FUNCTION_SET 0x3C
#define LCD_DISPLAY_SHIFT_RIGHT 0x1C
#define LCD_DISPLAY_SHIFT_LEFT 0x18
#define LCD_CURSOR_RIGHT_SHIFT 0x14
#define LCD_CURSOR_LEFT_SHIFT 0x10
#define LCD_CGRAM_ADDRESS 0x40

//LCD PORTS AND PINS
#define LCD_DATA_PORT PORT_A
#define LCD_CONTROL_PORT PORT_B
#define LCD_RW PIN_2
#define LCD_RS PIN_3
#define LCD_E PIN_1


//LCD Cursor
#define LCD_START_POS 0x80
#define LCD_VERTICAL_INCREMENT 0x40

//LCD FUNCTIONS
void LCD_WriteCommand(u8 LCD_Command);
void LCD_Init();
void LCD_WriteData(u8 LCD_Char);
void LCD_SetCursor(u8 X,u8 Y);
void LCD_WriteStr(u8 LCD_STR[]);
void LCD_WriteNum(u32 Num, u8 dp);
void LCD_WriteChar(u8 LCD_Data);
void LCD_WriteChar_2d(u8 LCD_Data[]);

void LCD_WriteStrSin(u8 LCD_STR[], u8 NumOfIterations);
void LCD_CustomCharsInit();
