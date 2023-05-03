/*
 * Timer1_config.h
 *
 *  Created on: 27 Sept 2022
 *      Author: El-Wattaneya
 */

#ifndef MCAL_TIMER1_TIMER1_CONFIG_H_
#define MCAL_TIMER1_TIMER1_CONFIG_H_

#define TIMER1_PRESCALLER     TIMER1_8_PRESCALER


#define TIMER1_DISABLE               0X00
#define TIMER1_1_PRESCALER           0X01
#define TIMER1_8_PRESCALER           0X02
#define TIMER1_64_PRESCALER          0X03
#define TIMER1_256_PRESCALER         0X04
#define TIMER1_1024_PRESCALER        0X05
#define TIMER1_EXITRNAL_FALLING      0X06
#define TIMER1_EXITRNAL_RISING       0X07

#endif /* MCAL_TIMER1_TIMER1_CONFIG_H_ */
