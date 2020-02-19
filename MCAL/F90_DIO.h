/*
 * F91_DIO.h
 *
 *  Created on: Aug 28, 2018
 *      Author: root
 */

#ifndef F91_DIO_H_
#define F91_DIO_H_

#define F91_SETBIT(portname , pinnumber) (portname |= (1 << pinnumber))
#define F91_CLEARBIT(portname , pinnumber) (portname &= ~(1 << pinnumber))
#define F91_TOGGLEBIT(portname , pinnumber) (portname ^= (1 << pinnumber))
#define F91_READBIT(portname , pinnumber) (portname & (1 << pinnumber))

#define SET_BIT(REG,BIT)   (REG|=(1<<BIT) )
#define CLEAR_BIT(REG,BIT) (REG &= ~(1<<BIT) )
#define READ_BIT(REG,BIT)  (REG&(1<<BIT))


void F91_void_Initpin(char port ,int number , int Dir);
void F91_void_Writpin(char port ,int number , int Dir);
void F91_void_InitPort(unsigned char port , char value);
void F91_void_WritePort(unsigned char port , char value);
char F91_char_Readpin(char port , char number);

#endif /* F91_DIO_H_ */
