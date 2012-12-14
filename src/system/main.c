/*
 * main.c
 *
 *  Created on: Dec 12, 2012
 *      Author: Michal Banasiak
 */

#include "setup/setup.h"
#include "main/loop.h"
#include "peripherals/usart1.h"

void SysTick_Handler(void) {

}

void USART1_IRQHandler(void)
{
	sendByteWithUSART1(USART_ReceiveData(USART1));

	USART_ClearITPendingBit(USART1,USART_IT_RXNE);
}

int main(void) {


	setup();

	while(1) {
		loop();
	}

	return 0;
}
