/*
 * EXI_interrupts.c
 *
 *  Created on: 18 Sept 2022
 *      Author: Mahmoud Abdelmoniem
 */

#include "EXIT_interrupts.h"
static void (*INT0_fptr) (void) = NULL;
static void (*INT1_fptr) (void) = NULL;
static void (*INT2_fptr) (void) = NULL;

void EXIT_Interrupts_Init(EXIT_interrupts_t source,EXIT_interrupts_edge_t edge){

	switch(source)
	{
		case EXIT_INT0:
			SET_BIT(GICR,INT0);
			switch(edge){
				case EXIT_EDGE_LOW_LEVEL:
					CLEAR_BIT(MCUCR,ISC00);
					CLEAR_BIT(MCUCR,ISC01);
					break;
				case EXIT_EDGE_BOTH_RAISING_FALLING:
					SET_BIT(MCUCR,ISC00);
					CLEAR_BIT(MCUCR,ISC01);
					break;
				case EXIT_EDGE_FALLING:
					CLEAR_BIT(MCUCR,ISC00);
					SET_BIT(MCUCR,ISC01);
					break;
				case EXIT_EDGE_RAISING:
					SET_BIT(MCUCR,ISC00);
					SET_BIT(MCUCR,ISC01);
					break;
			}
			break;




		case EXIT_INT1:
			SET_BIT(GICR,INT1);

			switch(edge){
				case EXIT_EDGE_LOW_LEVEL:
					CLEAR_BIT(MCUCR,ISC10);
					CLEAR_BIT(MCUCR,ISC11);
					break;
				case EXIT_EDGE_BOTH_RAISING_FALLING:
					SET_BIT(MCUCR,ISC10);
					CLEAR_BIT(MCUCR,ISC11);
					break;
				case EXIT_EDGE_FALLING:
					CLEAR_BIT(MCUCR,ISC10);
					SET_BIT(MCUCR,ISC11);
					break;
				case EXIT_EDGE_RAISING:
					SET_BIT(MCUCR,ISC10);
					SET_BIT(MCUCR,ISC11);
					break;
			}
			break;




		case EXIT_INT2:
			SET_BIT(GICR,INT2);
			switch(edge)
			{
				case EXIT_EDGE_FALLING:
					SET_BIT(MCUCSR,ISC2);
					break;
				case EXIT_EDGE_RAISING:
					CLEAR_BIT(MCUCSR,ISC2);
					break;
				default:;
			}
			break;
	}


}
void EXIT_Interrupts_Disable(EXIT_interrupts_t source){
	switch(source)
	{
		case EXIT_INT0: CLEAR_BIT(GICR,INT0);break;
		case EXIT_INT1:	CLEAR_BIT(GICR,INT1);break;
		case EXIT_INT2:	CLEAR_BIT(GICR,INT2);break;
	}
}
void EXIT_Set_CallBack(EXIT_interrupts_t source,void (*INT_ptf)(void)){

	switch(source)
	{
		case EXIT_INT0: INT0_fptr = INT_ptf;break;
		case EXIT_INT1:	INT1_fptr = INT_ptf;break;
		case EXIT_INT2:	INT2_fptr = INT_ptf;break;
	}
}
ISR(INT0_vect)
{
	if(INT0_fptr)
		INT0_fptr();

}
ISR(INT1_vect)
{
	if(INT2_fptr)
		INT2_fptr();

}
ISR(INT2_vect)
{
	if(INT2_fptr)
		INT2_fptr();

}

