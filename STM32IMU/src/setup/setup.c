/*
 * setup.c
 *
 *  Created on: Dec 12, 2012
 *      Author: Michal Banasiak
 */

#include "setup.h"

#include "l3gd20_setup.h"
#include "lsm303dlhc_setup.h"
#include "usart1_setup.h"

#include "main/programState.h"
#include "algorithms/complementary_filter.h"
#include "algorithms/kalman_filter.h"
void setup() {
	SysTick_Config(720000);

	l3gd20_setup();
	lsm303dlhc_setup();
	setupUSART1();

	orientationReset();
	complementaryFilterSetFactor(0.975);
	kalmanFilterInit();
}