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


float dt = 0.01;

void SysTick_Handler(void) {
	vector gyro = vectorMultiply(velocityInDegreesPerSecond(), vectorCreate(1.0f, -1.0f, 0.0f));
	vector accelerometer = acceleration();

//	vector dOrientation = vectorMultiplyScalar(gyro, dt);
//	dOrientation = vectorMultiply(dOrientation, vectorCreate(1,-1,1));
//	vector newOrientation = vectorAdd(orientationGetVector(), dOrientation);
//
//	vector filteredOrientation = complementaryFilter(newOrientation, accelerometer);

	vector filteredOrientation = kalmanFilter(gyro, accelerometer);

	orientationSetVector(filteredOrientation);



		int32_t xr = (int32_t) (filteredOrientation.x*1000000.0);
		int32_t yr = (int32_t) (filteredOrientation.y*1000000.0);
		int32_t zr = (int32_t) (filteredOrientation.z*1000000.0);

		char str[200];

		makeOrientationFrame(str, xr, yr, zr);

		sendStringWithUSART1(str);
}

void USART1_IRQHandler(void) {
	sendByteWithUSART1(USART_ReceiveData(USART1));

	USART_ClearITPendingBit(USART1,USART_IT_RXNE);
}
