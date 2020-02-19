#include <avr/io.h>
#include "F90_DIO.h"

void F91_void_Initpin(char port ,int number , int Dir)
{

	switch(port)
	{
	case 'A':
	case 'a':
		if(Dir)
		{
			F91_SETBIT(DDRA , number);
		}else
		{
			F91_CLEARBIT(DDRA , number);
		}
		break;
	case 'B':
	case 'b':
		if(Dir)
		{
			F91_SETBIT(DDRB , number);
		}else
		{
			F91_CLEARBIT(DDRB , number);
		}
		break;
	case 'D':
	case 'd':
		if(Dir)
		{
			F91_SETBIT(DDRD , number);
		}else
		{
			F91_CLEARBIT(DDRD , number);
		}
		break;
	case 'C':
	case 'c':
		if(Dir)
		{
			F91_SETBIT(DDRC , number);
		}else
		{
			F91_CLEARBIT(DDRC , number);
		}
		break;

	}
}

void F91_void_Writpin(char port ,int number , int Dir)
{

	switch(port)
	{
	case 'A':
	case 'a':
		if(Dir)
		{
			F91_SETBIT(PORTA , number);
		}else
		{
			F91_CLEARBIT(PORTA , number);
		}
		break;
	case 'B':
	case 'b':
		if(Dir)
		{
			F91_SETBIT(PORTB , number);
		}else
		{
			F91_CLEARBIT(PORTB , number);
		}
		break;
	case 'D':
	case 'd':
		if(Dir)
		{
			F91_SETBIT(PORTD , number);
		}else
		{
			F91_CLEARBIT(PORTD , number);
		}
		break;
	case 'C':
	case 'c':
		if(Dir)
		{
			F91_SETBIT(PORTC , number);
		}else
		{
			F91_CLEARBIT(PORTC , number);
		}
		break;

	}
}


void F91_void_InitPort(unsigned char port , char value)
{

	switch(port)
	{
	case 'A':
	case 'a':
		DDRA = value;
		break;
	case 'B':
	case 'b':
		DDRB = value;
		break;
	case 'D':
	case 'd':
		DDRD = value;

		break;
	case 'C':
	case 'c':
		DDRC = value;

		break;

	}
}
void F91_void_WritePort(unsigned char port , char value)
{

	switch(port)
	{
	case 'A':
	case 'a':
		PORTA = value;
		break;
	case 'B':
	case 'b':
		PORTB = value;
		break;
	case 'D':
	case 'd':
		PORTD = value;

		break;
	case 'C':
	case 'c':
		PORTC = value;

		break;

	}
}

char F91_char_Readpin(char port , char number)
{
	switch(port)
	{
	case 'A':
	case 'a':
		return F91_READBIT(PINA , number);
		break;
	case 'B':
	case 'b':
		return F91_READBIT(PINB , number);
		break;
	case 'D':
	case 'd':
		return F91_READBIT(PIND , number);
		break;
	case 'C':
	case 'c':
		return F91_READBIT(PINC , number);
		break;

	}
	return 0;
}


