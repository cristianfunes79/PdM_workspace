/*
 * API_uart.h
 *
 *  Created on: Oct 11, 2022
 *      Author: cfunes
 */

#ifndef API_INC_API_UART_H_
#define API_INC_API_UART_H_

#include <stdbool.h>
#include <stdint.h>

typedef bool bool_t;

bool_t uartInit(void);
void uartSendString(uint8_t* pstring);
void uartSendStringSize(uint8_t* pstring, uint16_t size);
void uartReceiveStringSize(uint8_t* pstring, uint16_t size);

#endif /* API_INC_API_UART_H_ */
