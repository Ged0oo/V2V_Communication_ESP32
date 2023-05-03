/*
 * IR_Sensor.c
 *
 *  Created on: 2 Feb 2023
 *      Author: El-Wattaneya
 */

#include "IR_Sensor.h"
IR_Sensor_s IR_Sensor_Status(IR_Sensor_Pin _pin)
{
	Dio_state_t Pin_State = Dio_Read(_pin);
	IR_Sensor_s IR_Sensor_s = NON_BODY;
	if(Pin_State == LOW)
	{
		IR_Sensor_s = BODY;
	}
	else if(Pin_State == HIGH)
	{
		IR_Sensor_s = NON_BODY;
	}
	return IR_Sensor_s;
}
