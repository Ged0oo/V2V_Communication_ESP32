/*
 * Dio_Config.h
 *
 *  Created on: 14 Sept 2022
 *      Author: Mahmoud Abdelmoniem
 */

#ifndef MCAL_DIO_DIO_CONFIG_H_
#define MCAL_DIO_DIO_CONFIG_H_
#include "Dio_types.h"

#define PIN_COUNT 20

typedef struct{
	Dio_port_t port;
	Dio_pin_t pin;
	Dio_dir_t direction;
}Dio_pin_config;

#endif /* MCAL_DIO_DIO_CONFIG_H_ */
