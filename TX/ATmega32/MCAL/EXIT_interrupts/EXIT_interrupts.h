/*
 * EXI_interrupts.h
 *
 *  Created on: 18 Sept 2022
 *      Author: Mahmoud Abdelmoniem
 */

#ifndef MCAL_EXI_INTERRUPTS_EXIT_INTERRUPTS_H_
#define MCAL_EXI_INTERRUPTS_EXIT_INTERRUPTS_H_

#include "avr/io.h"
#include "avr/interrupt.h"
#include "stdio.h"
#include "../../Bit_math.h"
#include "../../std_types.h"

typedef enum{
	EXIT_INT0,
	EXIT_INT1,
	EXIT_INT2
}EXIT_interrupts_t;

typedef enum{
	EXIT_EDGE_LOW_LEVEL,
	EXIT_EDGE_BOTH_RAISING_FALLING,
	EXIT_EDGE_FALLING,
	EXIT_EDGE_RAISING
}EXIT_interrupts_edge_t;

void EXIT_Interrupts_Init(EXIT_interrupts_t source,EXIT_interrupts_edge_t edge);
void EXIT_Interrupts_Disable(EXIT_interrupts_t source);
void EXIT_Set_CallBack(EXIT_interrupts_t source,void (*INT_ptf)(void));

#endif /* MCAL_EXI_INTERRUPTS_EXIT_INTERRUPTS_H_ */
