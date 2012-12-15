/*
 * frame.h
 *
 *  Created on: Dec 15, 2012
 *      Author: Michal Banasiak
 */

#ifndef FRAME_H_
#define FRAME_H_

#include "stm32f30x.h"

void makeOrientationFrame(const char* buf, int32_t x, int32_t y, int32_t z);

void makeFrame(const char* buf, const char* data, const char* identifier, uint32_t numberOfArguments);

#endif /* FRAME_H_ */
