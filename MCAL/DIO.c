#include <avr/io.h>
#include "DIO.h"



void void_init_pin(char portname,char pinnumber , char dir)
{
	switch (portname)
	{
	case 'A':
	case 'a':
		if (dir)
			SET_BIT(DDRA,pinnumber);
		else
			CLEAR_BIT(DDRA,pinnumber);
		break ;
	case 'B':
	case 'b':
		if (dir)
			SET_BIT(DDRB,pinnumber);
		else
			CLEAR_BIT(DDRB,pinnumber);
		break ;
	case 'C':
	case 'c':
		if (dir)
			SET_BIT(DDRC,pinnumber);
		else
			CLEAR_BIT(DDRC,pinnumber);
		break ;
	case 'D':
	case 'd':
		if (dir)
			SET_BIT(DDRD,pinnumber);
		else
			CLEAR_BIT(DDRD,pinnumber);
		break ;


	}

}
void void_write_pin(char portname,char pinnumber , char state)
{


	switch (portname)
	{
	case 'A':
	case 'a':
		if (state)
			SET_BIT(PORTA,pinnumber);
		else
			CLEAR_BIT(PORTA,pinnumber);
		break ;
	case 'B':
	case 'b':
		if (state)
			SET_BIT(PORTB,pinnumber);
		else
			CLEAR_BIT(PORTB,pinnumber);
		break ;
	case 'C':
	case 'c':
		if (state)
			SET_BIT(PORTC,pinnumber);
		else
			CLEAR_BIT(PORTC,pinnumber);
		break ;
	case 'D':
	case 'd':
		if (state)
			SET_BIT(PORTD,pinnumber);
		else
			CLEAR_BIT(PORTD,pinnumber);
		break ;


	}

}
void void_init_port(char portname,char pins_dir)
{

	switch (portname)
	{
	case 'A':
	case 'a':
		DDRA=pins_dir;
		break;

	case 'B':
	case 'b':
		DDRB=pins_dir;
		break ;
	case 'C':
	case 'c':
		DDRC =pins_dir;
		break ;
	case 'D':
	case 'd':
		DDRD=pins_dir;
		break;
	}

}
void void_write_port(char portname,char pins_dir)
{

	switch (portname)
	{
	case 'A':
	case 'a':
		PORTA=pins_dir;
		break;

	case 'B':
	case 'b':
		PORTB=pins_dir;
		break ;
	case 'C':
	case 'c':
		PORTC =pins_dir;
		break ;
	case 'D':
	case 'd':
		PORTD=pins_dir;
		break;
	}

}
char char_read_pin(char portname,char pinnumber)
{
	switch(portname)
	{
	case 'A':
	case 'a':
		return READ_BIT(PINA,pinnumber);
	case 'B':
	case 'b':
		return READ_BIT(PINB,pinnumber);
	case 'C':
	case 'c':
		return READ_BIT(PINC,pinnumber);
	case 'D':
	case 'd':
		return READ_BIT(PIND,pinnumber);



	}
	return 'N';

}
