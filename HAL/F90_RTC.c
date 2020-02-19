/*
 * F90_RTC.c
 *
 *  Created on: Sep 13, 2018
 *      Author: root
 */
#include "../MCAL/F90_I2C.h"
#include "F90_RTC.h"

static unsigned char F90_DecToBcdConvert(unsigned char  val)
{
	return val + 6 * (val / 10);
}

static unsigned char F90_BcdToDecConvert(unsigned char  val)
{
	return val - 6 * (val >> 4);
}

void F90_void_RTC_init()
{
	//F90_void_I2C_init();

	 F90_void_I2C_init(0x47,1);

}

void F90_void_RTC_Settime(unsigned char HH ,unsigned char MM ,unsigned char SS  )
{
	F90_void_I2C_Start();
	F90_void_I2C_Write(ADDR_WITH_WRITE);
	F90_void_I2C_Write(CONTROL_REG);
	F90_void_I2C_Write(0x00);
	F90_void_I2C_Stop();

	unsigned char Hours = F90_DecToBcdConvert(HH);
	unsigned char Minute = F90_DecToBcdConvert(MM);
	unsigned char Second = F90_DecToBcdConvert(SS);


	F90_void_I2C_Start();
	F90_void_I2C_Write(ADDR_WITH_WRITE);
	F90_void_I2C_Write(SECOND_REG);
	F90_void_I2C_Write(Second);
	F90_void_I2C_Write(Minute);
	F90_void_I2C_Write(Hours);
	F90_void_I2C_Stop();
}

void F90_void_RTC_Gettime(unsigned char *HH ,unsigned char *MM ,unsigned char *SS  )
{
	unsigned char Hours = 0;
	unsigned char Minute = 0;
	unsigned char Second = 0;

	F90_void_I2C_Start();
	F90_void_I2C_Write(ADDR_WITH_WRITE);
	F90_void_I2C_Write(SECOND_REG);
	F90_void_I2C_Stop();
	F90_void_I2C_Start();
	F90_void_I2C_Write(ADDR_WITH_READ);
	Second = F90_char_I2C_Read(1);
	Minute = F90_char_I2C_Read(1);
	Hours = F90_char_I2C_Read(0);
	F90_void_I2C_Stop();


	*HH = F90_BcdToDecConvert(Hours);
	*MM = F90_BcdToDecConvert(Minute);
	*SS = F90_BcdToDecConvert(Second);


}

