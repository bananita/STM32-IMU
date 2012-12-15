/*
 * interrupts.h
 *
 *  Created on: Dec 14, 2012
 *      Author: Michal Banasiak
 */

#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "stm32f30x.h"

void SysTick_Handler(void);
void USART1_IRQHandler(void);

#endif /* INTERRUPTS_H_ */
