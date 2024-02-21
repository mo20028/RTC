/*
 * main.c
 *
 *  Created on: Feb 4, 2024
 *      Author: MS
 */
#include "STD_types.h"
#include "BIT_math.h"

#include "PORT_interface.h"
#include "DIO_interface.h"
#include "TWI_interface.h"

#include "CLCD_interface.h"
#include "DS1307_interface.h"

#include <util/delay.h>

u8 *days[7]={"Sat","Sun","Mon","Tue","Wen","Thu","Fri"};


void main(void)
{
	PORT_voidInti();
	CLCD_voidInit();
	TWI_voidMasterInt(0);
	DS1307_t curren_time;

	//DS_SetClock(0x55,0x59,0x12,0);


	while(1)
	{
		DS_ReadTime(&curren_time);
		CLCD_ClearScreen();
		CLCD_voidNumber(curren_time.hour%12);
		CLCD_voidSendData(':');
		CLCD_voidNumber(curren_time.min);
		CLCD_voidSendData(':');
		CLCD_voidNumber(curren_time.second);
		if(curren_time.APM)
		{
			CLCD_voidSendString(" PM");
		}
		else
		{
			CLCD_voidSendString(" AM");
		}
		CLCD_voidGOTOXY(1,0);
		CLCD_voidNumber(curren_time.day);
		CLCD_voidSendData('/');
		CLCD_voidNumber(curren_time.month);
		CLCD_voidSendString("/20");
		CLCD_voidNumber(curren_time.year);
		CLCD_voidSendData(' ');
		CLCD_voidSendString((char *) days[curren_time.week_day-1]);

		_delay_ms(1000);

	}
}

