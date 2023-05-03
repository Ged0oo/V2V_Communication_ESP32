/* 
 * File:   LED.h
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on February 23, 2023, 8:41 PM
 */
#include "LED.h"


Std_ReturnType Led_Init(const ST_led_t* led)
{
	Std_ReturnType ret = E_OK;
	if(led == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ST_pinCofig_t led_1 =
		{
			.port = led->port,
			.pin = led->pin,
			.pin_logic = led->status,
			.pin_direction = GPIO_DIRECTION_OUTPUT
		};
		ret = gpio_pin_dirction_init(&led_1);
		ret = gpio_write_logic(&led_1, GPIO_LOW);
	}
	return ret;
}


Std_ReturnType Led_Turn_On(const ST_led_t* led)
{
	Std_ReturnType ret = E_OK;
	if(led == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ST_pinCofig_t led_1 =
		{
			.port = led->port,
			.pin = led->pin,
			.pin_logic = led->status,
			.pin_direction = GPIO_DIRECTION_OUTPUT
		};
		ret = gpio_write_logic(&led_1, GPIO_HIGH);
	}
	return ret;
}


Std_ReturnType Led_Turn_Off(const ST_led_t* led)
{
	Std_ReturnType ret = E_OK;
	if(led == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ST_pinCofig_t led_1 =
		{
			.port = led->port,
			.pin = led->pin,
			.pin_logic = led->status,
			.pin_direction = GPIO_DIRECTION_OUTPUT
		};
		ret = gpio_write_logic(&led_1, GPIO_LOW);
	}
	return ret;
}


Std_ReturnType Led_Toggle(const ST_led_t* led)
{
	Std_ReturnType ret = E_OK;
	if(led == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ST_pinCofig_t led_1 =
		{
			.port = led->port,
			.pin = led->pin,
			.pin_logic = led->status,
			.pin_direction = GPIO_DIRECTION_OUTPUT
		};
		ret = gpio_pin_toggle(&led_1);
	}
	return ret;
}

