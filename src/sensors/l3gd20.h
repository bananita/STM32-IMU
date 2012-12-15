/*
 * l3gd20.h
 *
 *  Created on: Dec 15, 2012
 *      Author: Michal Banasiak
 */

#ifndef L3GD20_H_
#define L3GD20_H_

#include "stm32f3_discovery_l3gd20.h"
#include "data_structures/vector.h"

vector velocityInDegreesPerSecond();



void Gyro_ReadData(float* pfData);
uint32_t L3GD20_TIMEOUT_UserCallback(void);

#endif /* L3GD20_H_ */
