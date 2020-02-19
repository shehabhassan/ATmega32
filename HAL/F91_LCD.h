/*
 * F91_LCD.h
 *
 *  Created on: Sep 4, 2018
 *      Author: root
 */

#ifndef F91_LCD_H_
#define F91_LCD_H_

#define WRITE_MOST(command)   ((command &0xf0) >> 4)
#define WRITE_LEST(command)   (command & 0x0f)

enum
{
	LCD_DATA_PIN1,
	LCD_DATA_PIN2,
	LCD_DATA_PIN3,
	LCD_DATA_PIN4,
	LCD_RS_PIN = 3,
	LCD_EN_PIN = 6,
	_4BITS = 4

};

enum
{
	LCD_DATA_PORT 	= 'B',
	LCD_EN_PORT 	= 'D',
	LCD_RS_PORT		= 'A'

};

void F91_void_initLCD();
void F91_void_LCD_Clear_Screen(void);
void F91_void_LCD_print( char *string);
void F91_void_LCD_Send_Data(unsigned char data);
void F91_void_LCD_goto(char y, char x);




#endif /* F91_LCD_H_ */
