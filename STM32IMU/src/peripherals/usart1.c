/*
 * usart1.c
 *
 *  Created on: Dec 14, 2012
 *      Author: Michal Banasiak
 */

#include "usart1.h"

void sendByteWithUSART1(uint8_t data) {
	while ( !USART_GetFlagStatus(USART1, USART_FLAG_TXE));
	USART_SendData(USART1, data);
}

void sendStringWithUSART1(const char* ptr) {
	do {
		sendByteWithUSART1(*ptr);
		ptr++;
	}
	while (*ptr);
}

uint8_t receiveByteFromUSART1() {
	return USART_ReceiveData(USART1);
}
