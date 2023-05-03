/*
 * Timer1.h
 *
 *  Created on: 27 Sept 2022
 *      Author: El-Wattaneya
 */

#ifndef MCAL_TIMER1_TIMER1_H_
#define MCAL_TIMER1_TIMER1_H_
#include "avr/io.h"
#include "avr/interrupt.h"
#include "Timer1_config.h"
#include "../../Bit_math.h"
#include "../../std_types.h"


typedef enum{
	TMR1_NORMAL_MODE=0,
	TMR1_PWM_PHASE_CORRECT_8BIT_MODE,
	TMR1_PWM_PHASE_CORRECT_9BIT_MODE,
	TMR1_PWM_PHASE_CORRECT_10BIT_MODE,
	TMR1_CTC_OCR1A_MODE,
	TMR1_PWM_FAST_MODE_8BIT,
	TMR1_PWM_FAST_MODE_9BIT,
	TMR1_PWM_FAST_MODE_10BIT,
	TMR1_PWM_PHASE_FRQ_ICR1_MODE,
	TMR1_PWM_PHASE_FRQ_OCR1A_MODE,
	TMR1_PWM_PHASE_CORRECT_ICR1_MODE,
	TMR1_PWM_PHASE_CORRECT_OCR1A_MODE,
	TMR1_CTC_ICR1_MODE,
	REVERSED,
	TMR1_PWM_FAST_MODE_ICR1,
	TMR1_PWM_FAST_MODE_OCR1A
}TMR1_mode;



typedef enum{
	OCRA1_DISCONNECTED=0,
	OCRA1_TOGGLE=0X40,
	OCRA1_NON_INVERTING=0X80,
	OCRA1_INVERTING=0XC0
}OCRA_Phase_fast_pwm;
typedef enum{
	OCRB1_DISCONNECTED=0,
	OCRB1_TOGGLE=0X10,
	OCRB1_NON_INVERTING=0X20,
	OCRB1_INVERTING=0X30
}OCRB_Phase_fast_pwm;

typedef enum{
	FALLING_EDGE,
	RISING_EDGE
}Edge_t;

#define TIMER1_OCR1A_CHAN_MODE(_MODE)        (TCCR1A = TCCR1A | (_MODE))
#define TIMER1_OCR1B_CHAN_MODE(_MODE)        (TCCR1B = TCCR1B | (_MODE))


#define TIMER1_SET_MODE(_MODE)             (TCCR1A = TCCR1A+( _MODE&0x03),\
										   TCCR1B = TCCR1B + ((_MODE &0x0c)<<1))


#define TIMER1_SET_PRESCALLER(_PRE)        (TCCR1B = TCCR1B + (_PRE))



void Timer1_Init(uint8 mode ,OCRA_Phase_fast_pwm outputa,OCRB_Phase_fast_pwm outputb);
void Timer1_Interrupt_Enable();
void Timer1_Interrupt_Disable();
void Timer1_SetCallBack(void (*tmr1_ptf)(void));
void TIMER1_SetOCR1A(uint16 Copy_u16Value);
void TIMER1_SetOCR1B(uint16 Copy_u16Value);
void TIMER1_SetICR1(uint16 Copy_u16Value);
void TIMER1_SetTCNT1(uint16 Copy_u16Value);
void PWM_FreQ_KHz(uint16 _ferq);
void PWM_FreQ_Hz(uint16 _ferq);
void PWM_SetDuty_Cycle_OCR1A(uint8 _duty);
void PWM_SetDuty_Cycle_OCR1B(uint8 _duty);
void TMR1_Interrupt_COMPA_enable();
void Timer1_SetCallBack_COMPA(void (*tmr1_ptf)(void));
void TMR1_Interrupt_COMPA_Disable();
void TMR1_Interrupt_CAPT_enable();
void Timer1_SetCallBack_COMPB(void (*tmr1_ptf)(void));
void TMR1_Interrupt_CAPT_Disable();
void Timer1_ICU_SetCallBack(void (*(TMR1_ICU)) (void));
void Timer1_InputCpetureEdge(Edge_t _edge);
void Timer1_ICU_InterruptEnable();
void Timer1_ICU_InterruptDisnable();
void PWM_measure(uint32 *pfeq,uint8 * pduty);
#endif /* MCAL_TIMER1_TIMER1_H_ */
