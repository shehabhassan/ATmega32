/*
 * main.c
 *
 *  Created on: Sep 29, 2018
 *      Author: Tariq A.Diab
 */
/*innclude os header files */



#include "../MCAL/DIO.h"
#include <util/delay.h>
#include "../HAL/keypad.h"
#include "../HAL/F91_LCD.h"
#include <stdio.h>


int x,y;
char toscreen[50];
int * ptr;
key k;
int main()
{
	char start[]="nothing pressed";

	void_init_keypad();
	F91_void_initLCD();
	F91_void_LCD_print( start);
	_delay_ms(1000);
	F91_void_LCD_Clear_Screen();
	sprintf(toscreen,"button %d ,%d",x,y);

	while (1)
	{
		k= key_read_keypad();
		x=k.x;
		y=k.y;
		if (y==5 )
		{
			F91_void_LCD_print( "waiting .... ");
			_delay_ms(100);
		}
		else
		{
			sprintf(toscreen,"button %d, %d ",x,y);
			F91_void_LCD_print(toscreen);
			_delay_ms(1000);
		}
			F91_void_LCD_Clear_Screen();


	}



}























/*

int main()
{

void_init_led(1);
void_init_led(2);
void_turn(1,0);
void_turn(2,0);
void_init_pin('d',2,0)	;
void_write_pin('d',2,1);
void_init_pin('a',0,0)	;
void_write_pin('a',0,1);
while(1)
{
if (! char_read_pin('d',2))
{	_delay_ms(50);
	void_turn(1,0);
	_delay_ms(1000);
	void_turn(1,1);
}
if (! char_read_pin('a',0))
{	_delay_ms(50);
	void_turn(2,0);
	_delay_ms(1000);
	void_turn(2,1);
}

}

}




*/






















//#define DIO_testing
#ifdef DIO_testing

#include "../MCAL/DIO.h"
#include "../HAL/LED.h"
#include <avr/delay.h>
int main ()
{
	void_init_pin('a',1,1);  //0b00000110;
	void_init_pin('a',2,1);
	void_write_pin('a',1,0);
	void_write_pin('a',2,0);
	while (1)
	{
		_delay_ms(500);
		void_write_pin('a',1,1);
		void_write_pin('a',2,0);

		_delay_ms(500);
		void_write_pin('a',1,0);
		void_write_pin('a',2,1);


	}


}

#endif




















/*
#include "../MCAL/F90_DIO.h"
#include <avr/io.h>
#include <util/delay.h>

#include "../MCAL/F90_UART.h"
#include "../HAL/F91_LCD.h"
#include "../HAL/TEMP.h"
#include "../HAL/F90_RTC.h"


//#define settime

int main()
{

unsigned char test [50] ;
unsigned char temp [50] ;
unsigned int x =0;


F91_void_initLCD();
F90_void_RTC_init();
int h,m,s;
#ifdef settime
F90_void_RTC_Settime(2 ,17 ,00  );
#endif
while (1){

	F90_void_RTC_Gettime(&h,&m,&s );
	x=TEMP_READ();
	sprintf(test ,"time is %d:%d:%d" , h, m,s);
	F91_void_LCD_print( test);
	F91_void_LCD_goto(2,1);

	sprintf(temp ,"temp: %d " ,x);
	F91_void_LCD_print( temp);
	_delay_ms(1000);
	F91_void_LCD_Clear_Screen();

}
	return 0;

}


*/
