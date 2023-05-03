#ifndef DIOCONFIG_H_
#define DIOCONFIG_H_



typedef enum{
	PORTA_0,
	PORTA_1,
	PORTA_2,
	PORTA_3,
	PORTA_4,
	PORTA_5,
	PORTA_6,
	PORTA_7,
	PORTB_0,
	PORTB_1,
	PORTB_2,
	PORTB_3,
	PORTB_4,
	PORTB_5,
	PORTB_6,
	PORTB_7,
	PORTC_0,
	PORTC_1,
	PORTC_2,
	PORTC_3,
	PORTC_4,
	PORTC_5,
	PORTC_6,
	PORTC_7,
	PORTD_0,
	PORTD_1,
	PORTD_2,
	PORTD_3,
	PORTD_4,
	PORTD_5,
	PORTD_6,
	PORTD_7,

}channel_t;


typedef enum{
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7

}Dio_pin_t;

typedef enum{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
}Dio_port_t;


typedef enum{
	LOW,
	HIGH
}Dio_state_t;


typedef enum{
	INPUT,
	OUTPUT
}Dio_dir_t;
#endif
