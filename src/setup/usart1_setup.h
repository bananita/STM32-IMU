/*
 * usart1_setup.h
 *
 *  Created on: Dec 14, 2012
 *      Author: Michal Banasiak
 */

#ifndef USART1_SETUP_H_
#define USART1_SETUP_H_

#include "stm32f30x.h"

void setupUSART1();

void USART1_RCC_Initialization(void);
void USART1_GPIO_Initialization(void);
void USART1_NVIC_Initialization(void);
void USART1_Initialization(void);

#endif /* USART1_SETUP_H_ */
