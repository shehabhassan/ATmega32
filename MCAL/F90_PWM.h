/*
 * F90_PWM.h

 *
 *  Created on: Sep 15, 2018
 *      Author: Tariq A.Diab
 */

#ifndef F90_PWM_H_
#define F90_PWM_H_

typedef struct PWM pwm_t;
struct PWM
{
	unsigned char type;
	unsigned char inverse;
	unsigned int clock;


};
enum
{
	PhaseCorrect,
	phasecorrect,
	CTC,
	ctc,
	FastPwm,
	fastpwm,
	True,
	False,
	NO=0,
	falling_edge,
	rising_edge,




};

void PWM_SET( float dutysycle);
void PWM_INIT(pwm_t *pwm);
#endif /* F90_PWM_H_ */
