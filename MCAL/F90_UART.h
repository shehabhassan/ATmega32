/*
 * F90_UART.h
 *
 *  Created on: Sep 8, 2018
 *      Author: Tariq A.Diab
 */

#ifndef F90_UART_H_
#define F90_UART_H_
#define SET_BIT(REG,BIT)   (REG|=(1<<BIT) )
#define CLEAR_BIT(REG,BIT) (REG &= ~(1<<BIT) )
#define READ_BIT(REG,BIT)  (REG&(1<<BIT))
void F90_VOID_INIT(unsigned long baud);
void F90_VOID_WRITE(unsigned char c);
void F90_VOID_WRITE_string( char *string);

#endif /* F90_UART_H_ */
