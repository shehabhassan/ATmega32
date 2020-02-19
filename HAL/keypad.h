/*
 * keypad.h
 *
 *  Created on: Feb 18, 2020
 *      Author: Tariq A.Diab
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "../MCAL/DIO.h"
#include <util/delay.h>
typedef struct  {
	char x ;
	char y ;
}key;

// rows of keypad
#define r_port 'a'			//the port of the rows
#define r1 2
#define r2 1
#define r3 0
//#define r4                // define for the 4th row of a 4x4 keypad

// columns of keypad
#define c_port 'c'			//the port of the columns
#define c1 5
#define c2 6
#define c3 7
//#define c4				// define for the 4th column of a 4x4 keypad

void void_init_keypad();

key key_read_keypad();






#endif /* KEYPAD_H_ */
