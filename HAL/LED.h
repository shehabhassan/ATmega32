/*
 * LED.h
 *
 *  Created on: Feb 16, 2020
 *      Author: Tariq A.Diab
 */

#ifndef LED_H_
#define LED_H_
#include "../MCAL/DIO.h"



void void_init_led(char LED);
void void_init_leds(void);
void void_turn(char LED,char state);
void void_toggle(char LED);


#endif /* LED_H_ */
