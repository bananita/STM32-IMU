/*
 * leds.h
 *
 *  Created on: Dec 16, 2012
 *      Author: Michal Banasiak
 */

#ifndef LEDS_H_
#define LEDS_H_

#include "stm32f3_discovery.h"
#include "stm32f30x.h"
#include "data_structures/vector.h"

void ledsSetup();
void turnOnAllLeds();
void turnOffAllLeds();

void showOrientation(vector orientation);

#endif /* LEDS_H_ */
