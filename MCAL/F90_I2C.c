
#include <avr/interrupt.h>
#include "../MCAL/F90_I2C.h"
#include "../MCAL/F90_DIO.h"
#define generic
//#define specific
#ifdef specific
void F90_void_I2C_init()
{
	TWBR = 0x47;
	TWSR = 0x00;
	TWCR = (1 << TWEN);
}
#endif

#ifdef generic

void F90_void_I2C_init(unsigned int bitrate,unsigned char prescaler)
{
	TWBR = bitrate;
	switch(prescaler)
	{
	case 1:

	CLEAR_BIT(TWSR,TWPS0);
	CLEAR_BIT(TWSR,TWPS1);
	break;
	case 4:

	SET_BIT(TWSR,TWPS0);
	CLEAR_BIT(TWSR,TWPS1);
	break;
	case 16:

	CLEAR_BIT(TWSR,TWPS0);
	SET_BIT(TWSR,TWPS1);
	break;
	case 64:

	SET_BIT(TWSR,TWPS0);
	SET_BIT(TWSR,TWPS1);
	break;

	}
	TWCR = (1 << TWEN);
}


#endif

void F90_void_I2C_Start()
{

	TWCR = (1 << TWINT) | (1 << TWSTA) | (1<<TWEN);

	while(!(TWCR & (1 << TWINT)));

}

void F90_void_I2C_Stop()
{
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1<<TWEN);
}


void F90_void_I2C_Write(char data)
{
	TWDR = data ;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1 << TWINT)));
}




char F90_char_I2C_Read(char ack)
{
	if(ack)
	{
		TWCR = (1<<TWINT) | (1<<TWEN) | (1 << TWEA);

	}
	else
	{
		TWCR = (1<<TWINT) | (1<<TWEN);

	}
	while(!(TWCR & (1 << TWINT)));
	return TWDR;
}
