
/* 
 * File:   DIO.h
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on February 23, 2023, 8:41 PM
 */

#ifndef DIO_H_
#define DIO_H_


/*					section includes					*/


#include "../StdTypes.h"
#include "../MemoryMap.h"
#define F_CPU 8000000UL
#include <util/delay.h>


/*					section: data type declaration					*/
#define MASK_PIN			1

#define			SET_BIT(_REG,PIN)			(_REG = _REG | (MASK_PIN<<PIN))
#define			CLEAR_BIT(_REG,PIN)			(_REG = _REG & (~(MASK_PIN<<PIN)))
#define			TOGGLE_BIT(_REG,PIN)		(_REG = _REG ^ (MASK_PIN<<PIN))
#define			READ_BIT(_REG,PIN)			((_REG>>PIN)  & MASK_PIN)





typedef enum
{
	GPIO_LOW = 0,
	GPIO_HIGH
}EN_logic_t;

typedef enum
{
	PORTA_INDEX = 0,
	PORTB_INDEX,
	PORTC_INDEX,
	PORTD_INDEX,
	PORTE_INDEX
}EN_portIndex_t;

typedef enum
{
	GPIO_PIN0 = 0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
	GPIO_PIN4,
	GPIO_PIN5,
	GPIO_PIN6,
	GPIO_PIN7	
}EN_pinNumber_t;

typedef enum
{
	GPIO_DIRECTION_OUTPUT = 0,
	GPIO_DIRECTION_INPUT
}EN_pinDirection_t;


typedef struct
{
	EN_portIndex_t port;
	EN_pinNumber_t pin;
	EN_pinDirection_t pin_direction;
	EN_logic_t pin_logic;	
}ST_pinCofig_t;



/*					section:function declaration					*/
Std_ReturnType gpio_pin_dirction_init(const ST_pinCofig_t* pinObject);
Std_ReturnType gpio_get_pin_direction(const ST_pinCofig_t*pinObject, EN_pinDirection_t* dirction);
Std_ReturnType gpio_write_logic(const ST_pinCofig_t* pinObject, EN_logic_t logic);
Std_ReturnType gpio_read_logic(const ST_pinCofig_t* pinObject, EN_logic_t* logic);
Std_ReturnType gpio_pin_toggle(const ST_pinCofig_t* pinObject);
Std_ReturnType gpio_pin_init(const ST_pinCofig_t* pinObject);



#endif /* DIO_H_ */