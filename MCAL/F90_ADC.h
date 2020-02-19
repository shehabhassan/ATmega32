/*
 * F90_ADC.h
 *
 *  Created on: Sep 14, 2018
 *      Author: Tariq A.Diab
 */

#ifndef F90_ADC_H_
#define F90_ADC_H_

typedef struct adc adc_t;
struct adc
{
	unsigned int prescaler;
	unsigned char interrupt_en;
	unsigned char data_mode;
	unsigned char ref;
	unsigned char channel_mux;
};


int ADC_READ();
void ADC_START_CONVERSION();
void ADC_INIT(adc_t *adc);

#define CLEAR_BIT(REG,BIT) (REG &= ~(1<<BIT) )
#define READ_BIT(REG,BIT)  (REG&(1<<BIT))



#endif /* F90_ADC_H_ */
