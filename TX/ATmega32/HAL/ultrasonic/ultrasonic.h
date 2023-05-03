/*
 * ultrasonic.h
 *
 *  Created on: 28 Feb 2023
 *      Author: El-Wattaneya
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_H_
#define HAL_ULTRASONIC_ULTRASONIC_H_

#include "../../MCAL/Dio/Dio.h"
#include "../../MCAL/Timer1/Timer1.h"



typedef struct{
	channel_t Trigger;
}Ultrasonic_t;

void Ultrasonic_init();
uint8 UltrasonicReadDistance(Ultrasonic_t *sonic);


#endif /* HAL_ULTRASONIC_ULTRASONIC_H_ */
