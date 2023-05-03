/*
 * SevSegment.c
 *
 *  Created on: 14 Sept 2022
 *      Author: Mahmoud Abdelmoniem
 *
 */

#include "SevSegment.h"
void SevSegment_Display_Number(uint8 number){

#if SEGMENT_TYPE == COMMON_CATHODE
	Dio_Write(SEV_PIN1, READ_BIT(number,0));
	Dio_Write(SEV_PIN2, READ_BIT(number,1));
	Dio_Write(SEV_PIN3, READ_BIT(number,2));
	Dio_Write(SEV_PIN4, READ_BIT(number,3));
#elif SEGMENT_TYPE == COMMON_ANODE
	Dio_Write(SEV_PIN1, (READ_BIT(number,0))^1);
	Dio_Write(SEV_PIN2, (READ_BIT(number,1))^1);
	Dio_Write(SEV_PIN3, (READ_BIT(number,2))^1);
	Dio_Write(SEV_PIN4, (READ_BIT(number,3))^1);
#endif
}

void SevSegment_Display_Counter(uint8 counterUP_DOWN,uint16 delay)
{
	if(COUNTER_UP == counterUP_DOWN)
	{
		for(uint8 counter =0;counter<10;counter++)
		{
			SevSegment_Display_Number(counter);
			_delay_ms(delay);
		}
	}
	else if(COUNTER_DOWN == counterUP_DOWN)
	{
		for(uint8 counter =9;counter>=0;counter--)
		{
			SevSegment_Display_Number(counter);
			_delay_ms(delay);
		}
	}
}
