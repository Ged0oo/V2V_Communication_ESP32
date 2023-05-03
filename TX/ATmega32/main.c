
/*
 * main.c
 *  Created on: 9 Sept 2022
 *      Author: Mahmoud Abdelmoniem
 */


#include "main.h"

Motor_t motor1={
		.in_1=PORTB_1,
		.in_2=PORTB_2
};
Motor_t motor2={
		.in_1=PORTB_3,
		.in_2=PORTB_4
};

Ultrasonic_t ultra ;
uint8 dis;
uint8 dis_right=0;
uint8 dis_left=0;
int main()
{
	sei();
	Dio_init();
	Ultrasonic_init();
	UART_Init();
	uint8 dataRecived;
	while (1)
	    {

		UART_SendString("\nChoose your mode\n");
		UART_SendString("\nFor RC Mode\n");
		UART_SendString("\nV For V2V Mode\n");

	    dataRecived = UART_ReceiveByte();

	    if('R' == dataRecived) RC_Car();
	    else if('V' == dataRecived) Obstcale();

	    }

}

void Robot_Move_Forward()
{
	Motor_Move_Right(&motor1);
	Motor_Move_Right(&motor2);
}

void Robot_Move_Backward()
{
	Motor_Move_Left(&motor1);
	Motor_Move_Left(&motor2);
}

void Robot_Move_Right()
{
	Motor_Move_Right(&motor1);
	Motor_Stop(&motor2);
}

void Robot_Move_Left()
{
	Motor_Stop(&motor1);
	Motor_Move_Right(&motor2);
}

void Robot_turn_Right90()
{

	Robot_Move_Right();
	_delay_ms(1500);
	Robot_Stop();

}

void Robot_turn_Left90()
{

	Robot_Move_Left();
	_delay_ms(1500);
	Robot_Stop();

}

void Robot_Reverse()
{
	Robot_Speed(HIGH_SPEED);
	Robot_Move_Right();
	_delay_ms(3000);
}

void Robot_Move_Step()
{
	Robot_Speed(HIGH_SPEED);
	Robot_Move_Forward();
	_delay_ms(10);

}

void Robot_Stop()
{
	Motor_Stop(&motor1);
	Motor_Stop(&motor2);
	_delay_ms(600);
}

void Robot_Speed(Motor_Sped_t speed)
{
	PWM_SetDuty_Cycle_OCR1A(speed);
	PWM_SetDuty_Cycle_OCR1B(speed);
}
void RC_Car()
{
	UART_SendString("RC Mode");
	uint8 dataRecive=0;

	  while(1)
	  {
		UART_Receive_NoBlock(&dataRecive);

	    if('f' == dataRecive) Robot_Move_Forward();

	    else if('r' == dataRecive) Robot_Move_Right();
	    else if('l' == dataRecive) Robot_Move_Left();
	    else if('s' == dataRecive) Robot_Stop();
	    else if('t' == dataRecive) {Robot_Stop(); break;}
	    else /* Nothing */;
	  }
}
void Obstcale()
{
	UART_SendString("V2V Mode");
	uint8 dataRecive=0;
	while(1){
		UART_Receive_NoBlock(&dataRecive);
		_delay_ms(10);
			dis=UltrasonicReadDistance(&ultra);
			_delay_ms(10);
			if(dis > STOP_DISTANCE)
			{
				UART_SendByte('f');
				Robot_Move_Forward();
			}
			else if (dis<STOP_DISTANCE)
			{
				Robot_Stop();
				UART_SendByte('s');
				Servo_angle(0);
				_delay_ms(1000);
				dis_right=UltrasonicReadDistance(&ultra);
				_delay_ms(300);
				Servo_angle(180);
				_delay_ms(1000);
				dis_left=UltrasonicReadDistance(&ultra);
				_delay_ms(300);
				Servo_angle(90);
				if(dis_right>dis_left)
				{
					UART_SendByte('r');
					UART_SendByte('r');
					UART_SendByte('r');
					UART_SendByte('r');
					Robot_turn_Right90();

				}
				else if(dis_right<dis_left)
				{
					UART_SendByte('l');
					UART_SendByte('l');
					UART_SendByte('l');
					UART_SendByte('l');
					Robot_turn_Left90();
				}

			}
			if(dataRecive == 't'){Robot_Stop(); break;}

		}
}


