/*
 * lsm303dlhc_setup.h
 *
 *  Created on: Dec 12, 2012
 *      Author: Michal Banasiak
 */

#ifndef LSM303DLHC_SETUP_H_
#define LSM303DLHC_SETUP_H_

#include "stm32f3_discovery_lsm303dlhc.h"

void lsm303dlhc_setup();

void accelerometerSetup();
void magnetometerSetup();

#endif /* LSM303DLHC_SETUP_H_ */
