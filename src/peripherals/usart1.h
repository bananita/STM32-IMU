/*
 * usart1.h
 *
 *  Created on: Dec 14, 2012
 *      Author: Michal Banasiak
 */

#ifndef USART1_H_
#define USART1_H_

#include "stm32f30x.h"

void USART_Send(uint8_t data);
void USART_SendString(const char* ptr);

#endif /* USART1_H_ */
