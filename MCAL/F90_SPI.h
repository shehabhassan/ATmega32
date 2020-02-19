/*
 * F90_SPI.h
 *
 *  Created on: Sep 14, 2018
 *      Author: Tariq A.Diab
 */

#ifndef F90_SPI_H_
#define F90_SPI_H_


enum
{
	MASTER,
	SLAVE
};

enum
{
	RISING,
	FALLING
};
void SPI_INIT(unsigned char Interrupt ,unsigned char M_S,unsigned char plo,unsigned char plo2,char frq);
void SPI_TARNSIT(char data,char num);
char SPI_receive(void);

#endif /* F90_SPI_H_ */
