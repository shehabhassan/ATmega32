/*
 * LCD.h
 *
 *  Created on: Sep 15, 2018
 *      Author: Tariq A.Diab
 */

#ifndef LCD_H_
#define LCD_H_
#define rs 3
#define e 6

void send_command(char c);
void puls (void);
void send_char(char l);
void send_string(char *s);
void lcd_init(void);

#endif /* LCD_H_ */
