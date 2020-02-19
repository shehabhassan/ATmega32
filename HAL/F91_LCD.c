//#include <avr/io.h>
//#include <util/delay.h>
//
//
//void F91_void_LCD_Send_data(char data )
//{
//	PORTA |= (1 << PA3) ;
//	PORTB = (data >> 4);
//	PORTD |= (1 << PD6);
//	_delay_ms(2);
//	PORTD &= ~(1 << PD6);
//	_delay_ms(2);
//
//	PORTB = (data);
//	PORTD |= (1 << PD6);
//	_delay_ms(2);
//	PORTD &= ~(1 << PD6);
//	_delay_ms(2);
//}
//
//void F91_void_LCD_Send_command(char command )
//{
//	PORTA &= ~(1 << PA3) ;
//	PORTB = (command >> 4);
//	PORTD |= (1 << PD6);
//	_delay_ms(2);
//	PORTD &= ~(1 << PD6);
//	_delay_ms(2);
//
//	PORTB = (command);
//	PORTD |= (1 << PD6);
//	_delay_ms(2);
//	PORTD &= ~(1 << PD6);
//	_delay_ms(2);
//}





#include "../MCAL/F90_DIO.h"
#include "F91_LCD.h"
#include "util/delay.h"
#include "../Services_layers/Services_layers.h"

void F91_void_LCD_Send_Data(unsigned char data)
{
	F91_void_Writpin(LCD_RS_PORT , LCD_RS_PIN , HIGH);


	F91_void_WritePort(LCD_DATA_PORT, WRITE_MOST(data));
	F91_void_Writpin(LCD_EN_PORT , LCD_EN_PIN , HIGH);
	_delay_ms(1);
	F91_void_Writpin(LCD_EN_PORT , LCD_EN_PIN , LOW);
	_delay_ms(1);

	F91_void_WritePort(LCD_DATA_PORT, WRITE_LEST(data));
	F91_void_Writpin(LCD_EN_PORT , LCD_EN_PIN , HIGH);
	_delay_ms(1);
	F91_void_Writpin(LCD_EN_PORT , LCD_EN_PIN , LOW);
	_delay_ms(1);
}

void F91_void_LCD_Send_Command(unsigned char command)
{
	F91_void_Writpin(LCD_RS_PORT , LCD_RS_PIN , LOW);

	F91_void_WritePort(LCD_DATA_PORT, WRITE_MOST(command));
	F91_void_Writpin(LCD_EN_PORT , LCD_EN_PIN , HIGH);
	_delay_ms(1);
	F91_void_Writpin(LCD_EN_PORT , LCD_EN_PIN , LOW);
	_delay_ms(1);

	F91_void_WritePort(LCD_DATA_PORT, WRITE_LEST(command));
	F91_void_Writpin(LCD_EN_PORT , LCD_EN_PIN , HIGH);
	_delay_ms(1);
	F91_void_Writpin(LCD_EN_PORT , LCD_EN_PIN , LOW);
	_delay_ms(1);
}

void F91_void_LCD_init_Command(unsigned char command)
{
	F91_void_Writpin(LCD_RS_PORT , LCD_RS_PIN , LOW);


	F91_void_WritePort(LCD_DATA_PORT, WRITE_MOST(command));
	F91_void_Writpin(LCD_EN_PORT , LCD_EN_PIN , HIGH);
	_delay_ms(1);
	F91_void_Writpin(LCD_EN_PORT , LCD_EN_PIN , LOW);
	_delay_ms(1);

}

void F91_void_initLCD()
{

	F91_void_InitPort(LCD_DATA_PORT , 0x0F);
	F91_void_Initpin(LCD_EN_PORT , LCD_EN_PIN , OUTPUT);
	F91_void_Initpin(LCD_RS_PORT , LCD_RS_PIN , OUTPUT);
	/* after power up , delay 10ms should be existed */
	F91_void_LCD_init_Command(0x30);
	_delay_ms(10);
	F91_void_LCD_init_Command(0x30);
	_delay_ms(10);
	F91_void_LCD_init_Command(0x30);
	_delay_ms(10);
	F91_void_LCD_init_Command(0x20);
	_delay_ms(10);
	_delay_ms(10);
	F91_void_LCD_Send_Command(0x28);            /* Command ..0x28---> 4-bit mode - 2 line - 5x7 font */
	F91_void_LCD_Send_Command(0x0C);            /* Command ..0x0C---> Display no cursor - no blink */
	F91_void_LCD_Send_Command(0x06);            /* Command ..0x06---> Automatic Increment - No Display shift */
	F91_void_LCD_Send_Command(0x80);            /* Command ..0x80---> Address DDRAM with 0 offset 80h */
	_delay_ms(20);
}


void F91_void_LCD_Clear_Screen(void)
{
	F91_void_LCD_Send_Command(0x01);
	_delay_ms(10);
}

void F91_void_LCD_print( char *string)
{
	int i = 0;

	while( string[i]  != 0)
	{
		F91_void_LCD_Send_Data(string[i]);
		i++;
	}
}


void F91_void_LCD_goto(char y, char x)
{
	char firstAddress[] = {0x80,0xC0,0x94,0xD4};

	F91_void_LCD_Send_Command(firstAddress[y-1] + x-1);
	_delay_ms(20);
}




