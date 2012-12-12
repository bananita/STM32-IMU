/*
 * main.c
 *
 *  Created on: Dec 12, 2012
 *      Author: Michal Banasiak
 */

#include "setup/setup.h"
#include "program/loop.h"

int main(void) {
	SystemCoreClockUpdate();

	setup();

	while(1)
		loop();

	return 0;
}
