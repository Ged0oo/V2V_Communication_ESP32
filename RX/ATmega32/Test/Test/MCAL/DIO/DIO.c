/* 
 * File:   DIO.c
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on February 23, 2023, 8:41 PM
 */

#include "DIO.h"

volatile uint8 *ddr_regster[]  = {&DDRA,&DDRB,&DDRC,&DDRD};
volatile uint8 *port_regster[] = {&PORTA,&PORTB,&PORTC,&PORTD};
volatile uint8 *pin_regster[]  = {&PINA,&PINB,&PINC,&PIND};


Std_ReturnType gpio_pin_dirction_init(const ST_pinCofig_t* pinObject)
{
	Std_ReturnType ret = E_OK;	
	if(pinObject == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		switch(pinObject->pin_direction)
		{
			case GPIO_DIRECTION_OUTPUT :
			SET_BIT(*(ddr_regster[pinObject->port]), pinObject->pin);
			break;
			
			case GPIO_DIRECTION_INPUT :
			CLEAR_BIT(*(ddr_regster[pinObject->port]), pinObject->pin);
			break;
			
			default:
			ret = E_NOT_OK;
		}
	}
	return ret;
}


Std_ReturnType gpio_get_pin_direction(const ST_pinCofig_t* pinObject, EN_pinDirection_t* dirction)
{
	Std_ReturnType ret = E_OK;
	if(pinObject == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		*dirction = READ_BIT(*pin_regster[pinObject->port], pinObject->pin);
	}
	return ret;
}


Std_ReturnType gpio_write_logic(const ST_pinCofig_t* pinObject, EN_logic_t logic)
{
	Std_ReturnType ret = E_OK;
	if(pinObject == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		switch(logic)
		{
			case GPIO_HIGH :
				SET_BIT(*(port_regster[pinObject->port]), pinObject->pin);
				break;
				
			case GPIO_LOW :
				CLEAR_BIT(*(port_regster[pinObject->port]), pinObject->pin);
				break;
				
			default :
				ret = E_NOT_OK;
		}
	}
	return ret;
}


Std_ReturnType gpio_read_logic(const ST_pinCofig_t* pinObject, EN_logic_t* logic)
{
	Std_ReturnType ret = E_OK;
	if(pinObject == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		*logic = READ_BIT(*pin_regster[pinObject->port], pinObject->pin);
	}
	return ret;
}


Std_ReturnType gpio_pin_toggle(const ST_pinCofig_t* pinObject)
{
	Std_ReturnType ret = E_OK;
	if(pinObject == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		TOGGLE_BIT(*port_regster[pinObject->port], pinObject->pin);		
	}
	return ret;
}


Std_ReturnType gpio_pin_init(const ST_pinCofig_t* pinObject)
{
	Std_ReturnType ret = E_OK;
	if(pinObject == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ret = gpio_pin_dirction_init(pinObject);
		ret = gpio_write_logic(pinObject, pinObject->pin_logic);	
	}
	return ret;
}
