/*
 * loop.c
 *
 *  Created on: Dec 12, 2012
 *      Author: Michal Banasiak
 */

#include "loop.h"

#include "peripherals/usart1.h"
#include "sensors/lsm303dlhc.h"

inline void loop() {
	sendByteWithUSART1(accelerometerData());
}
