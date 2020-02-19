/*
 * F90_ADC.c

 *
 *  Created on: Sep 14, 2018
 *      Author: Tariq A.Diab
 */
#include <avr/io.h>
#include "../MCAL/F90_DIO.h"
#include "../MCAL/F90_ADC.h"



//#define mine
#define inlecture
#ifdef mine
void ADC_INIT(unsigned char prescaler,unsigned char ADCIE,unsigned char data_adj,unsigned char V_R_S ,unsigned char *analog_gain_selection)
{

	SET_BIT(ADCSRA,ADEN); //enabling adc
	//ADC Interrupt Enable
	if (ADCIE==1)
		SET_BIT(ADCSRA,ADIE);
	else
		SET_BIT(ADCSRA,ADIE);

	if (data_adj==1)//left adjust
		SET_BIT(ADMUX,ADLAR);00
	else //right adjust
		SET_BIT(ADMUX,ADLAR);


	//ADC Prescaler Select Bits
	switch(prescaler)
		{

	case 2:
		CLEAR_BIT(ADCSRA,ADPS0);
		CLEAR_BIT(ADCSRA,ADPS1);
		CLEAR_BIT(ADCSRA,ADPS2);

		break;
	case 4:
		CLEAR_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		CLEAR_BIT(ADCSRA,ADPS2);

		break;
	case 8:
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		CLEAR_BIT(ADCSRA,ADPS2);

		break;
	case 16:
		CLEAR_BIT(ADCSRA,ADPS0);
		CLEAR_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);

		break;
	case 32:
		SET_BIT(ADCSRA,ADPS0);
		CLEAR_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);

		break;

	case 64:
		CLEAR_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);

		break;
	case 128:
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);

		break;

		}
	switch(V_R_S)
		{
	//Voltage Reference Selection
		case 0:

			CLEAR_BIT(ADMUX,REFS0);
			CLEAR_BIT(ADMUX,REFS1);
			break;
		case 1:

			SET_BIT(ADMUX,REFS0);
			CLEAR_BIT(ADMUX,REFS1);
			break;
		case 3:

			SET_BIT(ADMUX,REFS0);
			CLEAR_BIT(ADMUX,REFS1);
			break;
		}
	if ((unsigned char *)analog_gain_selection[3]==0)
		CLEAR_BIT(ADMUX,MUX3);
	else
		SET_BIT(ADMUX,MUX3);
	if ((unsigned char *)analog_gain_selection[2]==0)
		CLEAR_BIT(ADMUX,MUX2);
	else
		SET_BIT(ADMUX,MUX2);
	if ((unsigned char *)analog_gain_selection[1]==0)
		CLEAR_BIT(ADMUX,MUX1);
	else
		SET_BIT(ADMUX,MUX1);
	if ((unsigned char *)analog_gain_selection[0]==0)
		CLEAR_BIT(ADMUX,MUX0);
	else
		SET_BIT(ADMUX,MUX0);


}
void ADC_START_CONVERSION()
{
	SET_BIT(ADCSRA,ADSC);
}
unsigned int ADC_READ()
	{int data=0;

	data=ADCH;
	data = (data<<8);
	data = (data|ADCL);
	return data;

	}


#endif
#ifdef inlecture

void ADC_INIT(adc_t *adc)
{

	SET_BIT(ADCSRA,ADEN); //enabling adc
	//ADC Interrupt Enable
	if (adc->interrupt_en==1)
		SET_BIT(ADCSRA,ADIE);
	else
		SET_BIT(ADCSRA,ADIE);
	//ADC Prescaler Select Bits
	if (adc->data_mode==1)//left adjust
		SET_BIT(ADMUX,ADLAR);
	else //right adjust
		CLEAR_BIT(ADMUX,ADLAR);

	switch(adc->prescaler)
		{

	case 2:
		CLEAR_BIT(ADCSRA,ADPS0);
		CLEAR_BIT(ADCSRA,ADPS1);
		CLEAR_BIT(ADCSRA,ADPS2);

		break;
	case 4:
		CLEAR_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		CLEAR_BIT(ADCSRA,ADPS2);

		break;
	case 8:
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		CLEAR_BIT(ADCSRA,ADPS2);

		break;
	case 16:
		CLEAR_BIT(ADCSRA,ADPS0);
		CLEAR_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);

		break;
	case 32:
		SET_BIT(ADCSRA,ADPS0);
		CLEAR_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);

		break;

	case 64:
		CLEAR_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);

		break;
	case 128:
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);

		break;

		}
	switch(adc->ref)
		{
	//Voltage Reference Selection
		case 0:

			CLEAR_BIT(ADMUX,REFS0);
			CLEAR_BIT(ADMUX,REFS1);
			break;
		case 1:

			SET_BIT(ADMUX,REFS0);
			CLEAR_BIT(ADMUX,REFS1);
			break;
		case 3:

			SET_BIT(ADMUX,REFS0);
			CLEAR_BIT(ADMUX,REFS1);
			break;
		}
	ADMUX|=adc->channel_mux;




}
int ADC_READ()
{
ADCSRA|=(1<<ADSC);
while(!(READ_BIT(ADCSRA,ADIF)));
	return ADC;
}

#endif
