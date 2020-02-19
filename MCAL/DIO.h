/*
 * DIO.h
 *
 *  Created on: Feb 16, 2020
 *      Author: Tariq A.Diab
 */

#ifndef DIO_H_
#define DIO_H_
#include <avr/io.h>

#define SET_BIT(PORTNAME,PIN_NUMBER) (PORTNAME |=(1<<PIN_NUMBER))
#define CLEAR_BIT(PORTNAME,PIN_NUMBER) (PORTNAME &=~(1<<PIN_NUMBER))
#define TOGGLE_BIT(PORTNAME,PIN_NUMBER) (PORTNAME ^=(1<<PIN_NUMBER))
#define READ_BIT(PORTNAME,PIN_NUMBER) (PORTNAME & (1<<PIN_NUMBER))

void void_init_pin(char portname,char pinnumber , char dir);
void void_write_pin(char portname,char pinnumber , char state);
void void_init_port(char portname,char pins_dir);
void void_write_port(char portname,char pins_state);
char char_read_pin(char portname,char pinnumber);

#endif /* DIO_H_ */
