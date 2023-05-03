/*
 * timer0.h
 *
 *  Created on: 24 Sept 2022
 *      Author: El-Wattaneya
 */

#ifndef MCAL_TIMER0_TIMER0_H_
#define MCAL_TIMER0_TIMER0_H_

#include "avr/io.h"
#include "avr/interrupt.h"
#include "timer0_config.h"
#include "../../Bit_math.h"
#include "../../std_types.h"



#define TIMER0_NORMAL_MODE       0
#define TIMER0_PHASSCORRECT_MODE 1
#define TIMER0_CTC_MODE          2
#define TIMER0_FASTPWM_MODE      3

#define	OC0_DISCONNECTED    0
#define	OC0_TOGGLE          1
#define	OC0_NON_INVERTING   2
#define	OC0_INVERTING       3


void Timer0_Init(uint8 mode,uint8 outputpin);
void Timer0_Set_OCR0(uint8 value);
void Timer0_Interrupt_Enable();
void Timer0_Interrupt_Disable();
void Timer0_SetCallBack(void (*tmr0_ptf)(void));




#endif /* MCAL_TIMER0_TIMER0_H_ */
