/*
 * TEMP.c
 *
 *  Created on: Sep 15, 2018
 *      Author: Tariq A.Diab
 */
#include "../HAL/TEMP.h"
#include "../MCAL/F90_ADC.h"
adc_t adc={128,0,0,3,5};


float TEMP_READ()
{
	ADC_INIT(&adc);
	float temp=ADC_READ();
	return (temp*4.88)/10;




}
