/*
 * I2C_Register.h
 *
 *  Created on: Mar 7, 2023
 *      Author: mahmo
 */

#ifndef I2C_REGISTER_H_
#define I2C_REGISTER_H_

#define TWDR *((volatile u8*) 0x23)
#define TWAR *((volatile u8*) 0x22)
#define TWSR *((volatile u8*) 0x21)
#define TWBR *((volatile u8*) 0x20)
#define TWCR *((volatile u8*) 0x56)


#endif /* I2C_REGISTER_H_ */
