/*
 * F90_PWM.c
 *
 *  Created on: Sep 15, 2018
 *      Author: Tariq A.Diab
 */

#include "../MCAL/F90_PWM.h"
#include "../MCAL/F90_DIO.h"
#include <avr/io.h>

void PWM_INIT (pwm_t *pwm)
{
	SET_BIT(DDRB,PB3);
	switch (pwm->type)
	{
	case PhaseCorrect:
	case phasecorrect:
		SET_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		break;
	case CTC:
	case ctc:
		CLEAR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
	case FastPwm:
	case fastpwm:
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
	}
	switch (pwm->inverse)
	{
	case True:
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
	case False:
		CLEAR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
	}
	switch (pwm->clock)
	{
	case NO:
	SET_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
	break;
	case 8:
	CLEAR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
	break;
	case 64:
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
	break;
	case 256:
	CLEAR_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	break;
	case 1024:
	SET_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	break;
	case falling_edge:
	CLEAR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	break;
	case rising_edge:
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	break;

	}


}

void PWM_SET( float dutysycle)
{
	unsigned int PulseWidth=(dutysycle*255);
	OCR0=PulseWidth;




}



