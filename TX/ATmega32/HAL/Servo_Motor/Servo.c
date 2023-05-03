/*
 * Servo.c
 *
 *  Created on: 10 Oct 2022
 *      Author: El-Wattaneya
 */
#include "Servo.h"
#include "../../MCAL/Dio/Dio.h"
#include "../../MCAL/Timer0/timer0.h"


volatile uint8 counter=0;

void Servo_angle(uint8 angle){

	if(angle==0)
	{
		OCR1B=1000;
	}
	else if(angle==180)
	{
		OCR1B=2000;
	}
	else if(angle==90)
	{
		OCR1B = 1500;
	}
	else
	{
		OCR1B = 0;
	}
}


