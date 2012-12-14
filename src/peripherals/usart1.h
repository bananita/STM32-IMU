/*
 * usart1.h
 *
 *  Created on: Dec 14, 2012
 *      Author: Michal Banasiak
 */

#ifndef USART1_H_
#define USART1_H_

#include "stm32f30x.h"

void sendByteWithUSART1(uint8_t data);
void sendStringWithUSART1(const char* ptr);

uint8_t receiveByteFromUSART1();

#endif /* USART1_H_ */
