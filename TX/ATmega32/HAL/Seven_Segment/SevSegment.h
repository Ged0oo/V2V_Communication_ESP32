/*
 * SevSegment.h
 *
 *  Created on: 14 Sept 2022
 *      Author: Mahmoud Abdelmoniem
 */

#ifndef HAL_SEVEN_SEGMENT_SEVSEGMENT_H_
#define HAL_SEVEN_SEGMENT_SEVSEGMENT_H_

#include "../../MCAL/Dio/Dio.h"
#include "SevSegment_config.h"


void SevSegment_Display_Number(uint8 number);

void SevSegment_Display_Counter(uint8 counterUP_DOWN,uint16 delay);

#endif /* HAL_SEVEN_SEGMENT_SEVSEGMENT_H_ */
