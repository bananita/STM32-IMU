/*
 * frame.c
 *
 *  Created on: Dec 15, 2012
 *      Author: Michal Banasiak
 */

#include "frame.h"

const char* frameBegin = "***";
const char* frameEnd = "**";

const char joinChar = ',';
const char frameEndChar = 10;

const char* orientationFrameIdentifier = "ORIENTATION";

void makeOrientationFrame(const char* buf, int32_t x, int32_t y, int32_t z) {
	char dataFrame[200];

	sprintf(dataFrame, "%d%c%d%c%d", (int)x, joinChar, (int)y, joinChar, (int)z);

	makeFrame(buf, dataFrame, orientationFrameIdentifier,3);
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
