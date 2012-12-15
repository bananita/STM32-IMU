/*
 * complementary_filter.h
 *
 *  Created on: Dec 15, 2012
 *      Author: Michal Banasiak
 */

#ifndef COMPLEMENTARY_FILTER_H_
#define COMPLEMENTARY_FILTER_H_

#include "data_structures/vector.h"

#define PI_180 (57.2957795)

vector complementaryFilter(vector gyroscope, vector accelerometer);

void complementaryFilterSetFactor(float factor);
float complementaryFilterGetFactor();

#endif /* COMPLEMENTARY_FILTER_H_ */
