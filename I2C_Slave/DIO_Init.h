/*
 * DIO_Init.h
 *
 *  Created on: Aug 28, 2022
 *      Author: mahmo
 */

#ifndef DIO_INIT_H_
#define DIO_INIT_H_



#endif /* DIO_INIT_H_ */

//HELPER MACROS
#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW 0

#define PORT_A (u8)0
#define PORT_B (u8)1
#define PORT_C (u8)2
#define PORT_D (u8)3

#define PIN_1 (u8)0
#define PIN_2 (u8)1
#define PIN_3 (u8)2
#define PIN_4 (u8)3
#define PIN_5 (u8)4
#define PIN_6 (u8)5
#define PIN_7 (u8)6
#define PIN_8 (u8)7




//Pin Functions Prototype
void DIO_SetPinValue(u8 DIO_Port_ID, u8 DIO_Pin_Num, u8 DIO_Pin_Value);
u8 DIO_GetPinValue(u8 DIO_Port_ID, u8 DIO_Pin_Num);
void DIO_SetPinDirection(u8 DIO_Port_ID, u8 DIO_Pin_Num, u8 DIO_Pin_Direction);
void DIO_SetInternalPullUp(u8 DIO_Port_ID, u8 DIO_Pin_Num);
//Port Functions Prototype
void DIO_SetPortValue(u8 DIO_Port_ID, u8 DIO_Port_Value);
u8 DIO_GetPortValue(u8 DIO_Port_ID);
void DIO_SetPortDirection(u8 DIO_Port_ID, u8 DIO_Port_Direction);
