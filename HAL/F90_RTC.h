/*
 * F90_RTC.h
 *
 *  Created on: Sep 13, 2018
 *      Author: root
 */

#ifndef F90_RTC_H_
#define F90_RTC_H_

enum
{
	ADDR_WITH_WRITE = 0xD0,
	ADDR_WITH_READ = 0xD1,
	SECOND_REG = 0x00,
	CONTROL_REG = 0x07

};

void F90_void_RTC_init();

void F90_void_RTC_Settime(unsigned char HH ,unsigned char MM ,unsigned char SS  );
void F90_void_RTC_Gettime(unsigned char *HH ,unsigned char *MM ,unsigned char *SS  );

#endif /* F90_RTC_H_ */
