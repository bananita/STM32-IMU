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

float x = 0;
float y = 0;
float z = 0;;
float dt = 0.01;

void SysTick_Handler(void) {
	float data[3];

	x += dt * data[0];
	x =  x*0.98 + angleInDegreesFromXZ()*0.02;
	y -= dt * data[1];
	y = y* 0.98 + angleInDegreesFromYZ()*0.02;
	z += dt * data[2];

		Gyro_ReadData(data);

		char xr[8];
		char yr[8];
		char zr[8];


		ftoa(x,xr);
		ftoa(y,yr);
		ftoa(z,zr);

		char str[200];

		sprintf(str, "x rate: %s, y rate: %s, z rate: %s %c", xr, yr, zr, 10);

		sendStringWithUSART1(str);
}

void USART1_IRQHandler(void) {
	sendByteWithUSART1(USART_ReceiveData(USART1));

	USART_ClearITPendingBit(USART1,USART_IT_RXNE);
}
