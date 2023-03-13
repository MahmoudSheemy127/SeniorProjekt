#ifndef USART_H_
#define USART_H_

#include "STD_Types.h"

#define UDR 	*((volatile u8* ) (0x2C))
#define UCSRA	*((volatile u8* ) (0x2B))
#define UCSRB	*((volatile u8* ) (0x2A))
#define UCSRC	*((volatile u8* ) (0x40))
#define UBRRL	*((volatile u8* ) (0x29))
#define UBRRH	*((volatile u8* ) (0x40))


void USART_initialize(void);
void USART_send_char(u8 val);
u8 USART_recieve_char(void);
void USART_send_string(u8* string);

#endif
