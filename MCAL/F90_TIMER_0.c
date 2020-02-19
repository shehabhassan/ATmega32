/*
 * F90_TIMER_0.c
 *
 *  Created on: Sep 7, 2018
 *      Author: Tariq A.Diab
 */
#include "F90_TIMER_0.h"
#include "avr/io.h"
#include "avr/interrupt.h"

volatile unsigned long Timer0_counter=0; // as this variable is operated on only using hardware we prevent optomization on it
char reg ;

void F90_Void_Timer0_init(unsigned int clk,unsigned char overflowOrCompare )
{
	switch(clk)
	{
	case '0':
	case 'no':

		CLEAR_BIT(reg,CS01);
		CLEAR_BIT(reg,CS00);
		CLEAR_BIT(reg,CS02);
		TIMER0_COMTROL_REG=reg;
		reg=0;
		break;
	case '1':
		CLEAR_BIT(reg,CS01);
		SET_BIT(reg,CS00);
		CLEAR_BIT(reg,CS02);
		TIMER0_COMTROL_REG=reg;
		reg=0;
		break;
	case '8':
		SET_BIT(reg,CS01);
		CLEAR_BIT(reg,CS00);
		CLEAR_BIT(reg,CS02);
		TIMER0_COMTROL_REG=reg;
		reg=0;
		break;
	case 64:
		SET_BIT(reg,CS01);
		SET_BIT(reg,CS00);
		CLEAR_BIT(reg,CS02);
		TIMER0_COMTROL_REG=reg;
		reg=0;
		break;
	case 265:
		CLEAR_BIT(reg,CS01);
		CLEAR_BIT(reg,CS00);
		SET_BIT(reg,CS02);
		TIMER0_COMTROL_REG=reg;
		reg=0;
		break;
	case 1024:
		CLEAR_BIT(reg,CS01);
		CLEAR_BIT(reg,CS00);
		CLEAR_BIT(reg,CS02);
		TIMER0_COMTROL_REG=reg;
		reg=0;
		break;
	case 'E_F':
		SET_BIT(reg,CS01);
		CLEAR_BIT(reg,CS00);
		SET_BIT(reg,CS02);
		TIMER0_COMTROL_REG=reg;
		reg=0;
		break;
	case 'E_R':
		SET_BIT(reg,CS01);
		SET_BIT(reg,CS00);
		SET_BIT(reg,CS02);
		TIMER0_COMTROL_REG=reg;
		reg=0;
		break;
	}
	if (overflowOrCompare)
	{
	SET_BIT(TIMER0_INT_REG     ,  TOIE0);
	CLEAR_BIT(TIMER0_INT_REG     ,  OCIE0);
	}
	else
	SET_BIT(TIMER0_INT_REG     ,  OCIE0);
	CLEAR_BIT(TIMER0_INT_REG     ,  TOIE0);

	sei();                                    //enable global service interrupt


}


void F90_Void_Timer0_init_normal(unsigned char com01 ,unsigned char com00)
{
	CLEAR_BIT(TIMER0_COMTROL_REG,WGM00) ;
	CLEAR_BIT(TIMER0_COMTROL_REG,WGM01) ;
if ((com01=0)&&(com00=0))
{
	CLEAR_BIT(TIMER0_COMTROL_REG,COM00) ;
	CLEAR_BIT(TIMER0_COMTROL_REG,COM01) ;

}
else if ((com01=0)&&(com00=1))
{
	SET_BIT(TIMER0_COMTROL_REG,COM00) ;
	CLEAR_BIT(TIMER0_COMTROL_REG,COM01) ;
}

else if ((com01=1)&&(com00=0))
{
	CLEAR_BIT(TIMER0_COMTROL_REG,COM00) ;
	SET_BIT(TIMER0_COMTROL_REG,COM01) ;
}
else
{
	SET_BIT(TIMER0_COMTROL_REG,COM00) ;
	SET_BIT(TIMER0_COMTROL_REG,COM01) ;
}

}

void F90_Void_Timer0_init_pwm(unsigned char com01 ,unsigned char com00)
{

	SET_BIT(TIMER0_COMTROL_REG , WGM00); //MAKING 64 PRESCALLER
	CLEAR_BIT(TIMER0_INT_REG     ,  WGM01);

	if ((com01=0)&&(com00=0))
	{
		CLEAR_BIT(TIMER0_COMTROL_REG,COM00) ;
		CLEAR_BIT(TIMER0_COMTROL_REG,COM01) ;

	}
	else if ((com01=0)&&(com00=1))
	{
		SET_BIT(TIMER0_COMTROL_REG,COM00) ;
		CLEAR_BIT(TIMER0_COMTROL_REG,COM01) ;
	}

	else if ((com01=1)&&(com00=0))
	{
		CLEAR_BIT(TIMER0_COMTROL_REG,COM00) ;
		SET_BIT(TIMER0_COMTROL_REG,COM01) ;
	}
	else
	{
		SET_BIT(TIMER0_COMTROL_REG,COM00) ;
		SET_BIT(TIMER0_COMTROL_REG,COM01) ;
	}

}
void F90_Void_Timer0_init_FastPwm(unsigned char com01 ,unsigned char com00)
{

	SET_BIT(TIMER0_COMTROL_REG , WGM00); //MAKING 64 PRESCALLER
	SET_BIT(TIMER0_INT_REG     ,  WGM01);
	if ((com01=0)&&(com00=0))
	{
		CLEAR_BIT(TIMER0_COMTROL_REG,COM00) ;
		CLEAR_BIT(TIMER0_COMTROL_REG,COM01) ;

	}
	else if ((com01=0)&&(com00=1))
	{
		SET_BIT(TIMER0_COMTROL_REG,COM00) ;
		CLEAR_BIT(TIMER0_COMTROL_REG,COM01) ;
	}

	else if ((com01=1)&&(com00=0))
	{
		CLEAR_BIT(TIMER0_COMTROL_REG,COM00) ;
		SET_BIT(TIMER0_COMTROL_REG,COM01) ;
	}
	else
	{
		SET_BIT(TIMER0_COMTROL_REG,COM00) ;
		SET_BIT(TIMER0_COMTROL_REG,COM01) ;
	}


}


void F90_Void_Timer0_init_ctc()
{

	CLEAR_BIT(TIMER0_COMTROL_REG , WGM00); //MAKING 64 PRESCALLER
	SET_BIT(TIMER0_INT_REG     ,  WGM01);


}




