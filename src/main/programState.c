/*
 * programState.c
 *
 *  Created on: Dec 15, 2012
 *      Author: Michal Banasiak
 */

#include "programState.h"

vector ___currentOrientation;

void orientationReset() {
	___currentOrientation.x = 0.0f;
	___currentOrientation.y = 0.0f;
	___currentOrientation.z = 0.0f;
}

void orientationSetVector(vector orientation) {
	___currentOrientation = orientation;
}

vector orientationGetVector() {
	return ___currentOrientation;
}
