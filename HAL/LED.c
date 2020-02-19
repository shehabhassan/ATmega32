/*
 * LEDS.c
 *
 *  Created on: Feb 16, 2020
 *      Author: Tariq A.Diab
 */
#include "LED.h"







void void_init_leds(void)
{
/*
 * this function is used to intialize all four pins
 * that are connected to port A and PORT c in the kit
 *
 *
 *
 * */

	void_init_pin('a',1,1);
	void_init_pin('a',2,1);
	void_init_pin('c',6,1);
	void_init_pin('c',7,1);

}



void void_init_led(char LED)
{
	switch(LED)
	{
	case 1:
		void_init_pin('a',1,1);
		break;
	case 2 :
		void_init_pin('a',2,1);
		break ;
	case 3:
		void_init_pin('c',7,1);
		break;
	case 4:
		void_init_pin('c',6,1);
		break;
	}

}




void void_turn(char LED,char state)
{
	switch(LED)
	{
	case 1:
		if (state)
			void_write_pin('a',1,1);
		else
			void_write_pin('a',1,0);
		break;
	case 2 :
		if (state)
			void_write_pin('a',2,1);
		else
			void_write_pin('a',2,0);
		break;
	case 3:
		if (state)
			void_write_pin('c',7,1);
		else
			void_write_pin('c',7,0);
		break;
	case 4:
		if (state)
			void_write_pin('c',6,1);
		else
			void_write_pin('c',6,0);
		break;
	}


}


void void_toggle(char LED)
{
	switch(LED)
	{
	case 1:
		TOGGLE_BIT(PORTA,1);
		break;
	case 2 :
		TOGGLE_BIT(PORTA,2);
		break ;
	case 3:
		TOGGLE_BIT(PORTA,7);
		break;
	case 4:
		TOGGLE_BIT(PORTA,6);
		break;
	}


}
