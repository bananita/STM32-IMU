/*
 * frame.h
 *
 *  Created on: Dec 15, 2012
 *      Author: Michal Banasiak
 */

#ifndef FRAME_H_
#define FRAME_H_

#include "stm32f30x.h"

void makeKalmanOrientationFrame(const char* buf, float x, float y, float z);
void makeComplementaryOrientationFrame(const char* buf, float x, float y, float z);

void makeFrame(const char* buf, const char* data, const char* identifier, uint32_t numberOfArguments);

#endif /* FRAME_H_ */
