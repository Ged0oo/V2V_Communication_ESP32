/*
 * SevSegment_config.h
 *
 *  Created on: 14 Sept 2022
 *      Author: Mahmoud Abdelmoniem
 */

#ifndef HAL_SEVEN_SEGMENT_SEVSEGMENT_CONFIG_H_
#define HAL_SEVEN_SEGMENT_SEVSEGMENT_CONFIG_H_


#define SEV_PIN1   PORTC_0
#define SEV_PIN2   PORTC_1
#define SEV_PIN3   PORTC_2
#define SEV_PIN4   PORTC_3


#define COMMOM_CATHODE  0
#define COMMON_ANODE    1

#define SEGMENT_TYPE    COMMOM_CATHODE

#define COUNTER_UP    1
#define COUNTER_DOWN  0



#endif /* HAL_SEVEN_SEGMENT_SEVSEGMENT_CONFIG_H_ */
