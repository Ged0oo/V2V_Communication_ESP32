/*
 * main.h
 *
 *  Created on: 11 Oct 2022
 *      Author: Mahmoud AbdelMoniem
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "MCAL/Dio/Dio.h"
#include "HAL/DC_motor/DC_motor.h"
#include "HAL/LCD/lcd.h"
#include "HAL/Servo_Motor/Servo.h"
#include "MCAL/Timer1/Timer1.h"
#include "HAL/ultrasonic/ultrasonic.h"
#include "MCAL/USART/USART.h"
#include "HAL/IR_Sensor/IR_Sensor.h"



#define STOP_DISTANCE     40

typedef enum{
	MAX_SPEED=100,
	HIGH_SPEED=90,
	HALF_SPEED =50,
	LOW_SPEED=30,
	MIN_SPEED=15
}Motor_Sped_t;


void Robot_Move_Forward();
void Robot_Move_Backward();
void Robot_Move_Right();
void Robot_Move_Left();
void Robot_turn_Right90();
void Robot_turn_Left90();
void Robot_Reverse();
void Robot_Move_Step();
void Robot_Stop();
void Robot_Speed(Motor_Sped_t speed);
void Robot_Localization();
void Robot_LineFollower();
void RC_Car();
void Obstcale();
#endif /* MAIN_H_ */
