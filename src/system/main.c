/*
 * main.c
 *
 *  Created on: Dec 12, 2012
 *      Author: Michal Banasiak
 */

#include "setup/setup.h"
#include "main/loop.h"

void SysTick_Handler(void) {

}

int main(void) {


	setup();

	while(1) {
		loop();
	}

	return 0;
}
