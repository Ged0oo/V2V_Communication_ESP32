/*
 * timer0_config.h
 *
 *  Created on: 24 Sept 2022
 *      Author: El-Wattaneya
 */

#ifndef MCAL_TIMER0_TIMER0_CONFIG_H_
#define MCAL_TIMER0_TIMER0_CONFIG_H_


#define TIMER0_PRESCALLER     TIMER0_8_PRESCALER


#define TIMER0_DISABLE               0X00
#define TIMER0_1_PRESCALER           0X01
#define TIMER0_8_PRESCALER           0X02
#define TIMER0_64_PRESCALER          0X03
#define TIMER0_256_PRESCALER         0X04
#define TIMER0_1024_PRESCALER        0X05
#define TIMER0_EXITRNAL_FALLING      0X06
#define TIMER0_EXITRNAL_RISING       0X07
#endif /* MCAL_TIMER0_TIMER0_CONFIG_H_ */
