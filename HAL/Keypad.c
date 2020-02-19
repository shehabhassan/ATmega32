/*
 * Keypad.c
 *
 *  Created on: Feb 18, 2020
 *      Author: Tariq A.Diab
 */

#include "keypad.h"
#ifndef c4
char n =3;
char rows[3]={r1,r2,r3};
char columns[3]= {c1,c2,c3};
#endif


#ifdef c4
char n =4;
char rows[4]={r1,r2,r3,r4};
char columns[4]= {c1,c2,c3,c4};
#endif


void void_init_keypad()
{

	//for 3X3 keypad
#ifndef c4
	// intializing rows
void_init_pin(r_port,r1,1);
void_init_pin(r_port,r2,1);
void_init_pin(r_port,r3,1);
	// intializing rows
void_init_pin(c_port,c1,0);
void_init_pin(c_port,c2,0);
void_init_pin(c_port,c3,0);
#endif




	//for 4X4 keypad
#ifdef c4
	// intializing rows
void_init_pin(r_port,r1,1);
void_init_pin(r_port,r2,1);
void_init_pin(r_port,r3,1);
void_init_pin(r_port,r4,1);
	// intializing rows
void_init_pin(c_port,c1,0);
void_init_pin(c_port,c2,0);
void_init_pin(c_port,c3,0);
void_init_pin(c_port,c4,0);

#endif

//turning all pins off
for (int x=0 ; x<n;x++)
{
	void_write_pin(r_port,rows[x],1);
}

//intializing the pullup resisrors
for (int x=0 ; x<n;x++)
{
	void_write_pin(c_port,columns[x],1);
}

}







key key_read_keypad()
{
key k;
int x,y;

for ( x=0 ; x<n;x++)
{
	void_write_pin(r_port,rows[x],0);
	for ( y=0 ;y<n;y++)
		{
		if (!char_read_pin(c_port,columns[y]))
		{
			_delay_ms(5);
			k.x=x;
			k.y=y;
			return k;
		}




		}
	void_write_pin(r_port,rows[x],1);

}
k.x=5;
k.y=5;
return k;



}

























