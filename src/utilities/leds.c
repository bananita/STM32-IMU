/*
 * leds.c
 *
 *  Created on: Dec 16, 2012
 *      Author: Michal Banasiak
 */

#include "leds.h"

void ledsSetup() {
	STM_EVAL_LEDInit(LED3);
	STM_EVAL_LEDInit(LED4);
	STM_EVAL_LEDInit(LED5);
	STM_EVAL_LEDInit(LED6);
	STM_EVAL_LEDInit(LED7);
	STM_EVAL_LEDInit(LED8);
	STM_EVAL_LEDInit(LED9);
	STM_EVAL_LEDInit(LED10);
}

void turnOnAllLeds() {
	STM_EVAL_LEDOn(LED3);
	STM_EVAL_LEDOn(LED4);
	STM_EVAL_LEDOn(LED5);
	STM_EVAL_LEDOn(LED6);
	STM_EVAL_LEDOn(LED7);
	STM_EVAL_LEDOn(LED8);
	STM_EVAL_LEDOn(LED9);
	STM_EVAL_LEDOn(LED10);
}

void turnOffAllLeds() {
	STM_EVAL_LEDOff(LED3);
	STM_EVAL_LEDOff(LED4);
	STM_EVAL_LEDOff(LED5);
	STM_EVAL_LEDOff(LED6);
	STM_EVAL_LEDOff(LED7);
	STM_EVAL_LEDOff(LED8);
	STM_EVAL_LEDOff(LED9);
	STM_EVAL_LEDOff(LED10);
}

void showOrientation(vector orientation) {
	turnOffAllLeds();

	if (sqrt(orientation.x*orientation.x + orientation.y*orientation.y) > 20.0f) {
		if (orientation.x > 1.0f && (orientation.y > 1.0f)) {
			STM_EVAL_LEDOn(LED7);
			STM_EVAL_LEDOn(LED10);
			STM_EVAL_LEDOn(LED6);
		}
		else if (orientation.x > 1.0f && (orientation.y < 1.0f)) {
			STM_EVAL_LEDOn(LED8);
			STM_EVAL_LEDOn(LED10);
			STM_EVAL_LEDOn(LED9);
		}
		else if (orientation.x < 1.0f && (orientation.y > 1.0f)) {
			STM_EVAL_LEDOn(LED3);
			STM_EVAL_LEDOn(LED4);
			STM_EVAL_LEDOn(LED6);
		}
		else if (orientation.x < 1.0f && (orientation.y < 1.0f)) {
			STM_EVAL_LEDOn(LED5);
			STM_EVAL_LEDOn(LED4);
			STM_EVAL_LEDOn(LED9);
		}
	}
	else {
		if (orientation.x > 1.0f)
			STM_EVAL_LEDOn(LED10);
		if (orientation.x < -1.0f)
			STM_EVAL_LEDOn(LED4);
		if (orientation.y > 1.0f)
			STM_EVAL_LEDOn(LED6);
		if (orientation.y < -1.0f)
			STM_EVAL_LEDOn(LED9);
	}
}
