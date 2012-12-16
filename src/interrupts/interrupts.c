/*
 * interrupts.c
 *
 *  Created on: Dec 14, 2012
 *      Author: Michal Banasiak
 */

#include "interrupts.h"

#include "peripherals/usart1.h"
#include "sensors/l3gd20.h"
#include "sensors/lsm303dlhc.h"
#include "utilities/printf_extensions.h"
#include "communication/frame.h"
#include "data_structures/vector.h"
#include "main/programState.h"
#include "algorithms/complementary_filter.h"
#include "algorithms/kalman_filter.h"
#include "utilities/leds.h"


float dt = 0.01;

uint32_t sendCounter = 5;

void SysTick_Handler(void) {
	vector gyro = vectorMultiply(velocityInDegreesPerSecond(), vectorCreate(1.0f, -1.0f, 0.0f));
	vector accelerometer = acceleration();

	vector dOrientation = vectorMultiplyScalar(gyro, dt);
	vector newOrientation = vectorAdd(orientationGetVector(), dOrientation);

	vector filteredOrientation = complementaryFilter(newOrientation, accelerometer);

	vector kalmanOrientation = kalmanFilter(gyro, accelerometer);

	orientationSetVector(filteredOrientation);

	showOrientation(kalmanOrientation);

	if (!(sendCounter--)) {
	char str[200];
	makeKalmanOrientationFrame(str, kalmanOrientation.x, kalmanOrientation.y, kalmanOrientation.z);
	sendStringWithUSART1(str);

	makeComplementaryOrientationFrame(str, filteredOrientation.x, filteredOrientation.y, filteredOrientation.z);
	sendStringWithUSART1(str);
	sendCounter = 5;
	}
}

void USART1_IRQHandler(void) {
	sendByteWithUSART1(USART_ReceiveData(USART1));

	USART_ClearITPendingBit(USART1,USART_IT_RXNE);
}
