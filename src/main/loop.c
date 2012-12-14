/*
 * loop.c
 *
 *  Created on: Dec 12, 2012
 *      Author: Michal Banasiak
 */

#include "loop.h"

#include "peripherals/usart1.h"

void loop() {
	sendStringByUSART1("TEST USART1     ");
}
