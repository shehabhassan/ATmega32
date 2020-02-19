/*
 * LCD.c
 *
 *  Created on: Sep 15, 2018
 *      Author: Tariq A.Diab
 */

#include <avr/io.h>
#include<util/delay.h>
#include "../MCAL/F90_DIO.h"
#include "../HAL/LCD.h"

// user defined functions
void send_command(char c)
{
	//PORTA&=~rs; //command mode
	CLEAR_BIT(PORTA,rs);



	PORTB=(c>>4); //|(PORTB&0xf0);   // sending msb
	puls();
	PORTB=(c&0x0f); //|(PORTB&0xf0);
	puls();

}
void puls(void)
{
SET_BIT(PORTD,e);
_delay_ms(3);
CLEAR_BIT(PORTD,e);
_delay_ms(3);
}
void send_char(char l)
{
	PORTA|=rs;                   //command mode



	PORTB=(l>>4);//|(PORTB&0xf0);   // sending msb
	puls();
	PORTB=(l&0x0f);//|(PORTB&0xf0);
	puls();

}
void send_string(char *s)
{
	while(*s != '\0')
	{
	send_char(*s++);

	}

}
void lcd_init(void)
{
	_delay_ms(50);
	DDRB=0xff;            //apv
	DDRA|=(1<<3);
	DDRD|=(1<<6);
	PORTB=0;
	PORTD&=~(1<<6);
	PORTA&=~(1<<3);
	_delay_ms(3);

	send_command(0x28);
	send_command(0x0c);
	send_command(0x06);
	send_command(0x01);
	send_command(0x80);

	_delay_ms(3);
}




