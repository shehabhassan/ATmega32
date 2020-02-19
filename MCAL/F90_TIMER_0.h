/*
 * F90_TIMER_0.h
 *
 *  Created on: Sep 7, 2018
 *      Author: Tariq A.Diab
 */

#ifndef F90_TIMER_0_H_
#define F90_TIMER_0_H_
void F90_Void_Timer0_init(unsigned int clk,unsigned char overflowOrCompare );
void F90_Void_Timer0_init_FastPwm(unsigned char com01, unsigned char com00);
void F90_Void_Timer0_init_pwm(unsigned char com01 ,unsigned char com00);
void F90_Void_Timer0_init_normal(unsigned char com01 ,unsigned char com00);
void F90_Void_Timer0_init_ctc();

#define TIMER0_COMTROL_REG 		TCCR0
#define TIMER0_INT_REG     		TIMSK
#define SET_BIT(REG,BIT) (REG|=(1<<BIT) )
#define CLEAR_BIT(REG,BIT) (REG &= ~(1<<BIT) )
extern volatile unsigned long Timer0_counter;

#endif /* F90_TIMER_0_H_ */
