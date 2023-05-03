/*
 * eeprom.h
 *
 *  Created on: 25 Sept 2022
 *      Author: El-Wattaneya
 */

#ifndef MCAL_INT_EEPROM_EEPROM_H_
#define MCAL_INT_EEPROM_EEPROM_H_





#include "avr/io.h"
#include "avr/interrupt.h"
#include "../../std_types.h"
#include "../../Bit_math.h"


void EEPROM_Read_Byte(uint8 address,uint8 *_value);


void EEPROM_Write_Byte(uint8 address,uint8 _value);

void EEPROM_Interupt_Enable(void);
void EEPROM_Interupt_Disable(void);
void EEPROM_Set_CallBack(void(*Local_ptr)(void));



#endif /* MCAL_INT_EEPROM_EEPROM_H_ */
