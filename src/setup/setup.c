/*
 * setup.c
 *
 *  Created on: Dec 12, 2012
 *      Author: Michal Banasiak
 */

#include "setup.h"

#include "stm32f3_discovery.h"

#include "sensors/l3gd20.h"
#include "sensors/lsm303dlhc.h"
#include "usart1_setup.h"

#include "main/programState.h"
#include "algorithms/complementary_filter.h"
#include "algorithms/kalman_filter.h"
#include "utilities/leds.h"

void setup() {
	SysTick_Config(720000);

	l3gd20Setup();
	lsm303dlhcSetup();
	setupUSART1();

	orientationReset();
	complementaryFilterSetFactor(0.975);
	kalmanFilterInit();

	ledsSetup();
}


