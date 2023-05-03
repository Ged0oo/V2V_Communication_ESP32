/*
 * H_Bridge.h
 *
 *  Created on: 10/10/2022
 *      Author: Mohamed Samir
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_H_
#define HAL_DC_MOTOR_DC_MOTOR_H_

#include "../../MCAL/Dio/Dio.h"
#include "DC_motor_Cfg.h"

typedef struct {
	channel_t in_1;
	channel_t in_2;
}Motor_t;
void Motor_Move_Right(Motor_t *_motor);
void Motor_Move_Left(Motor_t *_motor);
void Motor_Stop(Motor_t *_motor);

#endif /* HAL_DC_MOTOR_DC_MOTOR_H_ */
