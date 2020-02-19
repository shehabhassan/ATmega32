/*
 * F90_UART2.c
 *
 *  Created on: Sep 8, 2018
 *      Author: Tariq A.Diab
 */


/*
 * F90_UART.c
 *
 *  Created on: Sep 8, 2018
 *      Author: Tariq A.Diab
 */


#include "../MCAL/F90_UART.h"
#include <avr/io.h>
unsigned char i;
unsigned char reg;
void F90_VOID_INIT(unsigned long baud)
{

	unsigned long baudrate =(F_CPU/(16*baud) )-1;
	UCSRC&=~(1<<URSEL);
	UBRRL=(unsigned char)baudrate;
	UBRRH=(unsigned char)(baudrate>>8);

	reg=0;
	SET_BIT(reg,TXEN);
	SET_BIT(reg,RXEN);
	UCSRB=reg;

	reg=0;
	SET_BIT(reg,URSEL);
	SET_BIT(reg,UCSZ1);
	SET_BIT(reg,UCSZ0);

	UCSRC=reg;
	//CHOSING THE STATUS REG C
	// SETTING 8BIT MODE
	//	CLEAR_BIT(UCSRC,URSEL);



}

void F90_VOID_WRITE(unsigned char c)
{
	while(!(READ_BIT(UCSRA,UDRE)));//TRUE WHEN UDRE==0
	//CONTINUEE WHEN UDRE==1



	UDR=c;




}
void F90_VOID_WRITE_string( char *string)
{
	//while(READ_BIT(UCSRB,UDRIE));
	i=0;
	while (!(*(string+i) ==0))
	{
	//i=0;

	//UDR=*string;
	F90_VOID_WRITE (string[i]);
	i++;



	}

}
char F90_VOID_READ()
{
	while(!(READ_BIT(UCSRA,RXC)));


	return UDR;




}
