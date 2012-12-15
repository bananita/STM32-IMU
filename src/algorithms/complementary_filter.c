/*
 * complementary_filter.c
 *
 *  Created on: Dec 15, 2012
 *      Author: Michal Banasiak
 */

#include "complementary_filter.h"

float ___complementaryFilterFactor;

vector complementaryFilter(vector gyroscope, vector accelerometer) {
	vector filteredData;

	float gyroscopeFactor = ___complementaryFilterFactor;
	float accelerometerFactor = 1.0f - ___complementaryFilterFactor;

	float accelerometerXZ = atan2(-accelerometer.x,sqrt(accelerometer.y*accelerometer.y+accelerometer.z*accelerometer.z))*PI_180;
	float accelerometerYZ = atan2(accelerometer.y,sqrt(accelerometer.x*accelerometer.x+accelerometer.z*accelerometer.z))*PI_180;

	filteredData.x = gyroscopeFactor*gyroscope.x + accelerometerFactor*accelerometerXZ;
	filteredData.y = gyroscopeFactor*gyroscope.y + accelerometerFactor*accelerometerYZ;
	filteredData.z = gyroscopeFactor*gyroscope.z;

	return filteredData;
}

void complementaryFilterSetFactor(float factor) {
	___complementaryFilterFactor = factor;
}

float complementaryFilterGetFactor() {
	return ___complementaryFilterFactor;
}


