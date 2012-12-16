/*
 * frame.c
 *
 *  Created on: Dec 15, 2012
 *      Author: Michal Banasiak
 */

#include "frame.h"

const char* frameBegin = "*";
const char* frameEnd = "*";

const char joinChar = ',';
const char frameEndChar = 10;

const double frameFactor = 1000000.0f;

void makeKalmanOrientationFrame(const char* buf, float x, float y, float z) {
	char dataFrame[200];

	sprintf(dataFrame, "%d%c%d%c%d", (int)(x*frameFactor), joinChar, (int)(y*frameFactor), joinChar, (int)(z*frameFactor));

	makeFrame(buf, dataFrame, "k",3);
}

void makeComplementaryOrientationFrame(const char* buf, float x, float y, float z) {
	char dataFrame[200];

	sprintf(dataFrame, "%d%c%d%c%d", (int)(x*frameFactor), joinChar, (int)(y*frameFactor), joinChar, (int)(z*frameFactor));

	makeFrame(buf, dataFrame, "c",3);
}

void makeFrame(const char* buf, const char* data, const char* identifier, uint32_t numberOfArguments) {
	sprintf(buf, "%s%c%s%c%d%c%s%c%s%c%c", frameBegin,
									 joinChar,
									 identifier,
									 joinChar,
									 (int)numberOfArguments,
									 joinChar,
									 data,
									 joinChar,
									 frameEnd,
									 joinChar,
									 frameEndChar);
}
