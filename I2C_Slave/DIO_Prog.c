/*
 * DIO_Prog.c
 *
 *  Created on: Aug 28, 2022
 *      Author: mahmo
 */
#include "DIO_Register.h"
#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO_Init.h"



//PIN FUNCTIONS
void DIO_SetPinValue(u8 DIO_Port_ID, u8 DIO_Pin_Num, u8 DIO_Pin_Value)
{
	switch(DIO_Port_ID)
	{
		case PORT_A:
			DIO_Pin_Value ? SET_BIT(PORTA,DIO_Pin_Num) : CLEAR_BIT(PORTA,DIO_Pin_Num);
			break;
		case PORT_B:
			DIO_Pin_Value ? SET_BIT(PORTB,DIO_Pin_Num) : CLEAR_BIT(PORTB,DIO_Pin_Num);
			break;
		case PORT_C:
			DIO_Pin_Value ? SET_BIT(PORTC,DIO_Pin_Num) : CLEAR_BIT(PORTC,DIO_Pin_Num);
			break;
		case PORT_D:
			DIO_Pin_Value ? SET_BIT(PORTD,DIO_Pin_Num) : CLEAR_BIT(PORTD,DIO_Pin_Num);
			break;
		default:
			break;
	}
}



void DIO_SetInternalPullUp(u8 DIO_Port_ID, u8 DIO_Pin_Num)
{
	//TODO check pin direction

	switch(DIO_Port_ID)
	{
		case PORT_A:
			SET_BIT(PORTA,DIO_Pin_Num);
			break;
		case PORT_B:
			SET_BIT(PORTB,DIO_Pin_Num);
			break;
		case PORT_C:
			SET_BIT(PORTC,DIO_Pin_Num);
			break;
		case PORT_D:
			SET_BIT(PORTD,DIO_Pin_Num);
			break;
		default:
			break;
	}

}

u8 DIO_GetPinValue(u8 DIO_Port_ID, u8 DIO_Pin_Num)
{

	switch(DIO_Port_ID)
	{
		case PORT_A:
			return GET_BIT(PINA,DIO_Pin_Num);
			break;
		case PORT_B:
			return GET_BIT(PINB,DIO_Pin_Num);
			break;
		case PORT_C:
			return GET_BIT(PINC,DIO_Pin_Num);
			break;
		case PORT_D:
			return GET_BIT(PIND,DIO_Pin_Num);
			break;
		default:
			break;
	}

}


void DIO_SetPinDirection(u8 DIO_Port_ID, u8 DIO_Pin_Num, u8 DIO_Pin_Direction)
{
	switch(DIO_Port_ID)
	{
		case PORT_A:
			DIO_Pin_Direction ? SET_BIT(DDRA,DIO_Pin_Num) : CLEAR_BIT(DDRA,DIO_Pin_Num);
			break;
		case PORT_B:
			DIO_Pin_Direction ? SET_BIT(DDRB,DIO_Pin_Num) : CLEAR_BIT(DDRB,DIO_Pin_Num);
			break;
		case PORT_C:
			DIO_Pin_Direction ? SET_BIT(DDRC,DIO_Pin_Num) : CLEAR_BIT(DDRC,DIO_Pin_Num);
			break;
		case PORT_D:
			DIO_Pin_Direction ? SET_BIT(DDRD,DIO_Pin_Num) : CLEAR_BIT(DDRD,DIO_Pin_Num);
			break;
		default:
			break;
	}
}

//PORT FUNCTIONS
void DIO_SetPortValue(u8 DIO_Port_ID, u8 DIO_Port_Value)
{
	switch(DIO_Port_ID)
	{
		case PORT_A:
			PORTA = DIO_Port_Value;
			break;
		case PORT_B:
			PORTB = DIO_Port_Value;
			break;
		case PORT_C:
			PORTC = DIO_Port_Value;
			break;
		case PORT_D:
			PORTD = DIO_Port_Value;
			break;
		default:
			break;
	}
}


u8 DIO_GetPortValue(u8 DIO_Port_ID)
{
	switch(DIO_Port_ID)
	{
		case PORT_A:
			return PORTA;
			break;
		case PORT_B:
			return PORTB;
			break;
		case PORT_C:
			return PORTC;
			break;
		case PORT_D:
			return PORTD;
			break;
		default:
			break;
	}
}


void DIO_SetPortDirection(u8 DIO_Port_ID, u8 DIO_Port_Direction)
{
	switch(DIO_Port_ID)
	{
		case PORT_A:
			DIO_Port_Direction ? (DDRA = 0xFF) : (DDRA = 0);
			break;
		case PORT_B:
			DIO_Port_Direction ? (DDRB = 0xFF) : (DDRB = 0);
			break;
		case PORT_C:
			DIO_Port_Direction ? (DDRC = 0xFF) : (DDRC = 0);
			break;
		case PORT_D:
			DIO_Port_Direction ? (DDRD = 0xFF) : (DDRD = 0);
			break;
		default:
			break;
	}
}

