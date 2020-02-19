/*
 * F90_I2C.h
 *
 *  Created on: Sep 12, 2018
 *      Author: root
 */

#ifndef F90_I2C_H_
#define F90_I2C_H_

void F90_void_I2C_Start();
void F90_void_I2C_Stop();
void F90_void_I2C_Write(char data);
char F90_char_I2C_Read(char ack);

#define generic
//#define specific
#ifdef generic

void F90_void_I2C_init(unsigned int bitrate,unsigned  char prescaler);

#endif
#ifdef specific

void F90_void_I2C_init();

#endif



#endif /* F90_I2C_H_ */
