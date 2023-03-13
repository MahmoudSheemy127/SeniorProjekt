#include "USART.h"
#include "BIT_Math.h"

void USART_initialize(void){
	UCSRC = 0x86;
	//SET_BIT(UCSRC, 7);
	// asynchronous
	//CLR_BIT(UCSRC, 6);

	// set baud rate
	UBRRL = 51;

	// enable Tx & Rx
	SET_BIT(UCSRB, 3);
	SET_BIT(UCSRB, 4);

	// set format, 8 data bits
	//SET_BIT(UCSRC, 1);
	//SET_BIT(UCSRC, 2);
	CLEAR_BIT(UCSRB, 2);

	// set format, 1 stop bit1
	//CLR_BIT(UCSRC, 3);
}

void USART_send_char(u8 val){
	// wait until register is empty
	while(GET_BIT(UCSRA, 5) == 0);
	// put byte in the UDR register
	UDR = val;
}

u8 USART_recieve_char(void){
	//u8 res;
	// wait until a byte is received
	while(GET_BIT(UCSRA, 7) == 0);
	//res = UDR;
	// return value
	//SET_BIT(UCSRA,7);
	return UDR;
}

void USART_send_string(u8* string){
	while(*string != '\0'){
		USART_send_char(*string);
		string++;
	}
}
