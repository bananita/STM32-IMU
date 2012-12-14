/*
 * usart1.c
 *
 *  Created on: Dec 14, 2012
 *      Author: Michal Banasiak
 */

#include "usart1.h"

void sendByUSART1(uint8_t data) {
	while ( !USART_GetFlagStatus(USART1, USART_FLAG_TXE));
	USART_SendData(USART1, data);
}

void sendStringByUSART1(const char* ptr) {
	do {
		sendByUSART1(*ptr);
		ptr++;
	}
	while (*ptr);
}
