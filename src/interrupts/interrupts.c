/*
 * interrupts.c
 *
 *  Created on: Dec 14, 2012
 *      Author: Michal Banasiak
 */

#include "interrupts.h"

#include "peripherals/usart1.h"

void SysTick_Handler(void) {

}

void USART1_IRQHandler(void) {
	sendByteWithUSART1(USART_ReceiveData(USART1));

	USART_ClearITPendingBit(USART1,USART_IT_RXNE);
}

void I2C1_EV_IRQHandler(void){

}
void I2C1_ER_IRQHandler(void){

}
void I2C2_EV_IRQHandler(void){

}
void I2C2_ER_IRQHandler(void){

}
