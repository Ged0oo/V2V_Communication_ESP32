/*
 * IR_Sensor.h
 *
 *  Created on: 2 Feb 2023
 *      Author: El-Wattaneya
 */

#ifndef HAL_IR_SENSOR_IR_SENSOR_H_
#define HAL_IR_SENSOR_IR_SENSOR_H_
#include "../../MCAL/Dio/Dio.h"

typedef channel_t IR_Sensor_Pin;


#define RIGHT   PORTC_0
#define LEFT    PORTC_2
#define MIDDL   PORTC_1
typedef enum{
	NON_BODY=0,
	BODY=1
}IR_Sensor_s;

IR_Sensor_s IR_Sensor_Status(IR_Sensor_Pin _pin);

#endif /* HAL_IR_SENSOR_IR_SENSOR_H_ */
