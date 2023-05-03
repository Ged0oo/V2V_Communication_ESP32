/*
 * ultrasonic.c
 *
 *  Created on: 28 Feb 2023
 *      Author: El-Wattaneya
 */

#include "ultrasonic.h"
static volatile uint16 ut1 ,ut2,uflag,c;
static void Func_ICU();
static void TMR_OVR();
void Ultrasonic_init()
{
	Timer1_Init(TMR1_PWM_FAST_MODE_OCR1A,OCRA1_DISCONNECTED,OCRB1_NON_INVERTING);
	OCR1A=20000;
	Timer1_ICU_SetCallBack(Func_ICU);
	Timer1_SetCallBack_COMPA(TMR_OVR);
	TMR1_Interrupt_COMPA_enable();
}
uint8 UltrasonicReadDistance(Ultrasonic_t* sonic)
{
	uint8 distance=0;
	uint16 time=0;
	c=0;
	uflag=0;
	TCNT1=0;
	Dio_Write(PORTB_0,HIGH);
	_delay_us(10);
	Dio_Write(PORTB_0,LOW);
	Timer1_InputCpetureEdge(RISING_EDGE);
	Timer1_ICU_InterruptEnable();
	while(uflag<2);
	time=ut2-ut1 + ((uint32) 65535*c);
	distance=time/58;
	Timer1_ICU_InterruptDisnable();
	return distance;
}
static void Func_ICU()
{
	if(uflag==0)
	{
		c=0;
		ut1=ICR1;
		uflag=1;
		Timer1_InputCpetureEdge(FALLING_EDGE);

	}
	else if(uflag == 1)
	{
		ut2=ICR1;
		uflag=2;
		Timer1_InputCpetureEdge(RISING_EDGE);
		Timer1_ICU_InterruptDisnable();
		TMR1_Interrupt_COMPA_Disable();

	}
}
static void TMR_OVR()
{
	c++;
}
