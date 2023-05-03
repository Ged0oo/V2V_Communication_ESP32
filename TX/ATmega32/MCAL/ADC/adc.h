/*
 * adc.h
 *
 *  Created on: 20 Sept 2022
 *      Author: Mahmoud Abdelmoniem
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_
#include "avr/io.h"
#include "../../Bit_math.h"
#include "../../std_types.h"
#include "stdio.h"
#include "adc_config.h"
#include "avr/interrupt.h"


void ADC_Init();
uint16 ADC_Read(ADC_chanel ch);
void ADC_Intrrupt_Enable();
void ADC_Intrrupt_Disable();
void ADC_SetCallBack(void (*ptfHandler)(void));

#endif /* MCAL_ADC_ADC_H_ */
