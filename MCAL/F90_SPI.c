/*
 * F90_SPI.c
 *
 *  Created on: Sep 14, 2018
 *      Author: Tariq A.Diab
 */
#include "../MCAL/F90_DIO.h"
#include "../MCAL/F90_SPI.h"
#include <avr/io.h>
/*
struct polarity {
	char bit0 : 1;
	char bit1 : 1;
	char bit2 : 1;
	char bit3 : 1;

};
 */
void SPI_INIT(unsigned char Interrupt ,unsigned char M_S,unsigned char plo,unsigned char plo2,char frq)
{
	if (Interrupt)
		SET_BIT(SPCR,SPIE);
	else
		CLEAR_BIT(SPCR,SPIE);

	SET_BIT(SPCR,SPE);

	switch(M_S)
	{
	case MASTER:
		SET_BIT(DDRB,PB4);
		SET_BIT(DDRB,PB3);

		SET_BIT(DDRB,PB5);
		SET_BIT(DDRB,PB7);
		CLEAR_BIT(DDRB,PB6);
		SET_BIT(SPCR,MSTR);
		switch(plo)
		{
		case RISING:
			SET_BIT(SPCR,CPOL);
			break;
		case FALLING :
			CLEAR_BIT(SPCR,CPOL);
			break;
		}
		switch(plo2)
		{
		case 1:
			SET_BIT(SPCR,CPHA);
			break;
		case 0 :
			CLEAR_BIT(SPCR,CPHA);
			break;
		}

		switch (frq)
		{
		case 4:
			CLEAR_BIT(SPCR,SPR0);
			CLEAR_BIT(SPCR,SPR1);
			break;
		case 16:
			SET_BIT(SPCR,SPR0);
			CLEAR_BIT(SPCR,SPR1);
			break;
		case 64:
			CLEAR_BIT(SPCR,SPR0);
			SET_BIT(SPCR,SPR1);
			break;
		case 128:
			SET_BIT(SPCR,SPR0);
			SET_BIT(SPCR,SPR1);
			break;

		}
		break;
	case SLAVE :
		CLEAR_BIT(DDRB,PB4);
		CLEAR_BIT(DDRB,PB3);
		CLEAR_BIT(DDRB,PB5);
		CLEAR_BIT(DDRB,PB7);
		SET_BIT(DDRB,PB6);
		CLEAR_BIT(SPCR,MSTR);
		break;
	}

}


void SPI_TARNSIT(char data,char num)
{
	if (num==1)
	{
		SET_BIT(PORTB,PB3);
		CLEAR_BIT(PORTB,PB4);
	}
	if (num==2)
	{
		SET_BIT(PORTB,PB4);
		CLEAR_BIT(PORTB,PB3);

	}
	SPDR=data;
	while(! READ_BIT(SPSR,SPIF));
}

char SPI_receive(void)
{

	while(! READ_BIT(SPSR,SPIF));
	return SPDR;
}


