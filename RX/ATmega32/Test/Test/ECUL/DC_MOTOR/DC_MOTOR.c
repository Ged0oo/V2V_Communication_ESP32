/* 
 * File:   DC_MOTOR.c
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on February 23, 2023, 8:41 PM
 */


#include "DC_MOTOR.h"

Std_ReturnType DC_Motor_Init(const ST_dcMotor_t* _motor)
{
	Std_ReturnType ret = E_OK;
	if(_motor == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ret = gpio_pin_dirction_init(&(_motor->pin[0]));
		ret = gpio_write_logic(&(_motor->pin[0]),GPIO_LOW);
		ret = gpio_pin_dirction_init(&(_motor->pin[1]));
		ret = gpio_write_logic(&(_motor->pin[1]),GPIO_LOW);
	}
	return ret;
}


Std_ReturnType DC_Motor_Move_Right(const ST_dcMotor_t* _motor)
{
	Std_ReturnType ret =E_OK;
	if(_motor == NULL){
		ret = E_NOT_OK;
	}
	else{
		ret = gpio_write_logic(&(_motor->pin[0]),GPIO_LOW);
		ret = gpio_write_logic(&(_motor->pin[1]),GPIO_HIGH);
	}
	return ret;
}


Std_ReturnType DC_Motor_Move_Lift(const ST_dcMotor_t* _motor)
{
	Std_ReturnType ret =E_OK;
	if(_motor == NULL){
		ret = E_NOT_OK;
	}
	else{
		ret = gpio_write_logic(&(_motor->pin[0]),GPIO_HIGH);
		ret = gpio_write_logic(&(_motor->pin[1]),GPIO_LOW);
	}
	return ret;
}


Std_ReturnType DC_Stop_Motor(const ST_dcMotor_t* _motor)
{
	Std_ReturnType ret =E_OK;
	if(_motor == NULL){
		ret = E_NOT_OK;
	}
	else{
		ret = gpio_write_logic(&(_motor->pin[0]),GPIO_LOW);
		ret = gpio_write_logic(&(_motor->pin[1]),GPIO_LOW);
	}
	return ret;
}