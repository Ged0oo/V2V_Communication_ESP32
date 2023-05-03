/* 
 * File:   IR.h
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on March 3, 2023, 8:41 PM
 */


#ifndef IR_H_
#define IR_H_

#include "../../MCAL/DIO/DIO.h"


typedef enum
{
	Black = 0,
	White  = 1
}EN_IRStatus_t;


typedef struct
{
	ST_pinCofig_t IrPin;
}ST_IR_t;



Std_ReturnType IR_Init(const ST_IR_t *ir_obj);
EN_IRStatus_t IR_Get_Status(const ST_IR_t *ir_obj);


#endif /* IR_H_ */