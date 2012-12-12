/*
 * setup.c
 *
 *  Created on: Dec 12, 2012
 *      Author: Michal Banasiak
 */

#include "setup.h"

void setup() {
	SysTick_Config(72000);
	SystemCoreClockUpdate();
}
