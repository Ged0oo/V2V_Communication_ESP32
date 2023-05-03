/*
 * H_Bridge.c
 *
 *  Created on: 10/10/2022
 *      Author: Mohamed Samir
 */

#include "DC_motor.h"

void Motor_Move_Right(Motor_t* _motor)
{
	Dio_Write(_motor->in_1,HIGH);
	Dio_Write(_motor->in_2,LOW);

}
void Motor_Move_Left(Motor_t* _motor)
{
	Dio_Write(_motor->in_1,LOW);
	Dio_Write(_motor->in_2,HIGH);
}
void Motor_Stop(Motor_t *_motor)
{
	Dio_Write(_motor->in_1,LOW);
	Dio_Write(_motor->in_2,LOW);
}

