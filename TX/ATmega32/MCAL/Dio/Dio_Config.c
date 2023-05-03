/*
 * Dio_Config.c
 *
 *  Created on: 14 Sept 2022
 *      Author: Mahmoud Abdelmoniem
 */
#include "Dio_Config.h"


/******************************************************************************/
/**
          --------------
 	 B0	 |              |
 	 B1	 |		        |
 	 B2	 |				|
 	 B3	 |				|
 	 B4	 |				|
 	 B5	 |				|
 	 B6	 |				|
 	 B7	 |				|
 	 	 |				|
 	 	 |				|
 	 	 |				|
 	 	 |				|
 	 	 |				|
 	 	 |				|
 	 	 |				|
 	 	 |				|
 	 	 |				|
 	 	 |				|
 	 	 |				|
 	 	 |				|
 	 	 |				|
 	 	 ---------------

 **/

Dio_pin_config pin[PIN_COUNT]={
		//DC_motors_Pins
		{PORT_B,PIN_0,OUTPUT},
		{PORT_B,PIN_1,OUTPUT},
		{PORT_B,PIN_2,OUTPUT},
		{PORT_B,PIN_3,OUTPUT},
		{PORT_B,PIN_4,OUTPUT},

/*		{PORT_A,PIN_7,OUTPUT},
		{PORT_A,PIN_4,OUTPUT},
		{PORT_A,PIN_5,OUTPUT},
		{PORT_A,PIN_6,OUTPUT},*/

		{PORT_C,PIN_2,INPUT},
		{PORT_C,PIN_0,INPUT},
		{PORT_D,PIN_6,INPUT},
		{PORT_D,PIN_4,OUTPUT},




};

