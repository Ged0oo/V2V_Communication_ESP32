/* 
 * File:   IR.c
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on March 3, 2023, 8:41 PM
 */

#include "IR.h"

Std_ReturnType IR_Init(const ST_IR_t *ir_obj)
{
	Std_ReturnType ret = E_OK;
	if(ir_obj == NULL)
	{
		return;
	}
	else
	{
		ret = gpio_pin_init(&(ir_obj->IrPin));
	}
	return ret;
}

EN_IRStatus_t IR_Get_Status(const ST_IR_t *ir_obj)
{
	Std_ReturnType ret = E_OK;
	if(ir_obj == NULL)
	{
		return;
	}
	else
	{
		EN_logic_t IrState = White;
		ret  = gpio_read_logic(&(ir_obj->IrPin) , &IrState);
		if(GPIO_LOW == IrState)
		{
			return White;
		}
		else if(GPIO_HIGH == IrState)
		{
			return Black;
		}
	}
}