/*
 * Test.c
 *
 * Created: 4/16/2023 1:42:45 AM
 * Author : Mohamed Nagy
 */ 


#include "MCAL/DIO/DIO.h"
#include "MCAL/UART/UART.h"
#include "ECUL/DC_MOTOR/DC_MOTOR.h"
#include "ECUL/LED/LED.h"
#include "ECUL/IR_SENSOR/IR.h"
#include "MCAL/TIMER1/Timer1.h"


void RcCarMode(void);
void V2VCarMode(void);
void LineFollowerMood(void);
void Robot_Speed(uint8 speed);
void CarMoveBackward(void);
void CarTurnRight(void);
void CarTurnLeft(void);
void CarStop(void);


#define  F_CPU 8000000UL
Std_ReturnType ret = E_NOT_OK;
uint8 dataRecived = '0';



ST_dcMotor_t motor_1 =
{
	.pin[0].pin = GPIO_PIN0,
	.pin[0].port = PORTA_INDEX,
	.pin[0].pin_direction = GPIO_DIRECTION_OUTPUT,
	.pin[0].pin_logic = GPIO_LOW,
	
	.pin[1].pin = GPIO_PIN1,
	.pin[1].port = PORTA_INDEX,
	.pin[1].pin_direction = GPIO_DIRECTION_OUTPUT,
	.pin[1].pin_logic = GPIO_LOW
};


ST_dcMotor_t motor_2 =
{
	.pin[0].pin = GPIO_PIN2,
	.pin[0].port = PORTA_INDEX,
	.pin[0].pin_direction = GPIO_DIRECTION_OUTPUT,
	.pin[0].pin_logic = GPIO_LOW,
	
	.pin[1].pin = GPIO_PIN3,
	.pin[1].port = PORTA_INDEX,
	.pin[1].pin_direction = GPIO_DIRECTION_OUTPUT,
	.pin[1].pin_logic = GPIO_LOW
};


int main(void)
{
	ret = DC_Motor_Init(&motor_1);
	ret = DC_Motor_Init(&motor_2);
	
	Timer1_Init(TMR1_PWM_FAST_MODE_ICR1 , OCRA1_NON_INVERTING , OCRB1_NON_INVERTING);
	PWM_FreQ_KHz(50);
	Robot_Speed(88);

	UART_Init();
	
    while (1) 
    {		
		dataRecived = '0';
		UART_Receive_NoBlock(&dataRecived);
		
		if('f' == dataRecived) CarMoveForward();
		else if('b' == dataRecived) CarMoveBackward();
		else if('r' == dataRecived) CarTurnRight();
		else if('l' == dataRecived) CarTurnLeft();
		else if('s' == dataRecived) CarStop();
		else if('t' == dataRecived) {CarStop(); break;}
		else /* Nothing */;
		
		_delay_ms(150);
    }
	
}


/*
void LineFollowerMood(void)
{
	Timer1_Init(TMR1_PWM_FAST_MODE_ICR1 , OCRA1_NON_INVERTING , OCRB1_NON_INVERTING);
	PWM_FreQ_KHz(50);
	Robot_Speed(90);
	
	EN_IRStatus_t Right_IR_State = White;
	EN_IRStatus_t Left_IR_State  = White;

	while(1)
	{
		Right_IR_State = IR_Get_Status(&Right_IR);
		Left_IR_State  = IR_Get_Status(&Left_IR);
		
		if(     (Left_IR_State == White) && (Right_IR_State == Black))
		{
			CarTurnRight();
		}
		else if((Left_IR_State == Black) && (Right_IR_State == White))
		{
			CarTurnLeft();
		}
		else if((Left_IR_State == White) && (Right_IR_State == White))
		{
			CarMoveForward();
		}
	}
}
*/


void Robot_Speed(uint8 speed)
{
	PWM_SetDuty_Cycle_OCR1A(speed);
	PWM_SetDuty_Cycle_OCR1B(speed);
}

void CarMoveForward(void)
{
	ret = DC_Motor_Move_Right(&motor_1);
	ret = DC_Motor_Move_Right(&motor_2);
}

void CarMoveBackward(void)
{
	ret = DC_Motor_Move_Lift(&motor_1);
	ret = DC_Motor_Move_Lift(&motor_2);
}

void CarTurnRight(void)
{
	ret = DC_Motor_Move_Right(&motor_1);
	ret = DC_Stop_Motor(&motor_2);
}

void CarTurnLeft(void)
{
	ret = DC_Stop_Motor(&motor_1);
	ret = DC_Motor_Move_Right(&motor_2);
}

void CarStop(void)
{
	ret = DC_Stop_Motor(&motor_1);
	ret = DC_Stop_Motor(&motor_2);
}
