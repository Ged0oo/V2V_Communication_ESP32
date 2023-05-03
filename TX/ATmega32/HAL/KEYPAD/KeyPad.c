/*
 * KeyPad.c
 *
 *  Created on: 18 Sept 2022
 *      Author: Mahmoud Abdelmoniem
 */

#include "KeyPad.h"
static const uint8 KP_Maparr[KEYPAD_ROWS][KEYPAD_COLUMNS] = {
                                                                        {'7', '8', '9', '/'},
                                                                        {'4', '5', '6', '*'},
                                                                        {'1', '2', '3', '-'},
                                                                        {'&', '0', '=', '+'}
                                                                     };

uint8 KP_GetPressed(){
	uint8 LRowConter=0;
	uint8 RowConter=0;
	uint8 LColumnConter=0;
	Dio_state_t state=LOW;
	uint8 Btn=0;
	for(LRowConter=0;LRowConter<KEYPAD_ROWS ;LRowConter++)
	{
		for(RowConter = KEYPAD_ROW_1 ;RowConter < KEYPAD_ROW_1 + KEYPAD_ROWS ;RowConter++){
			Dio_Write(RowConter, LOW);
		}
		Dio_Write(LRowConter + KEYPAD_ROW_1, HIGH);
		//_delay_ms(10);
		for(LColumnConter = KEYPAD_COLUMNS_1;LColumnConter < KEYPAD_COLUMNS_1 + KEYPAD_COLUMNS;LColumnConter++)
		{
			state = Dio_Read(LColumnConter);
			if(state == HIGH)
			{
				Btn = KP_Maparr[LRowConter][LColumnConter - KEYPAD_COLUMNS_1];
			}
		}
	}

	return Btn;

}
