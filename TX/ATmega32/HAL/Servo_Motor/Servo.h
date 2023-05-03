/*
 * Servo.h
 *
 *  Created on: 10 Oct 2022
 *      Author: El-Wattaneya
 */

#ifndef HAL_SERVO_MOTOR_SERVO_H_
#define HAL_SERVO_MOTOR_SERVO_H_

#include "../../MCAL/Timer1/Timer1.h"


void Servo_angle(uint8 angle);
void Servo_MotorInit_TMR0();
#endif /* HAL_SERVO_MOTOR_SERVO_H_ */
