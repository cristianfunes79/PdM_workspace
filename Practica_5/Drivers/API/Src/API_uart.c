/*
 * API_uart.c
 *
 *  Created on: Oct 11, 2022
 *      Author: cfunes
 */
#include <stdlib.h>

#include "API_uart.h"
#include "main.h"

#define MAX_BUFFER 128

/* UART handler declaration */
static UART_HandleTypeDef UartHandle;

bool_t uartInit(void)
{
	char buffer[MAX_BUFFER];
	/*##-1- Configure the UART peripheral ######################################*/
	/* Put the USART peripheral in the Asynchronous mode (UART Mode) */
	/* UART configured as follows:
	  - Word Length = 8 Bits (7 data bit + 1 parity bit) :
					  BE CAREFUL : Program 7 data bits + 1 parity bit in PC HyperTerminal
	  - Stop Bit    = One Stop bit
	  - Parity      = ODD parity
	  - BaudRate    = 9600 baud
	  - Hardware flow control disabled (RTS and CTS signals) */
	UartHandle.Instance        = USARTx;

	UartHandle.Init.BaudRate   = 9600;
	UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits   = UART_STOPBITS_1;
	UartHandle.Init.Parity     = UART_PARITY_ODD;
	UartHandle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode       = UART_MODE_TX_RX;
	UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;

	if (HAL_UART_Init(&UartHandle) != HAL_OK) return false;

	uartSendString((uint8_t*)"-------------------------------------------\r\n");
	uartSendString((uint8_t*)"UART Configuration\r\n");
	uartSendString((uint8_t*)"BaudRate: ");
	uartSendString((uint8_t*)itoa(UartHandle.Init.BaudRate, buffer, 10));
	uartSendString((uint8_t*)"\r\nWordLength: ");
	uartSendString((uint8_t*)itoa(UartHandle.Init.WordLength, buffer, 10));
	uartSendString((uint8_t*)"\r\nStopBits: ");
	uartSendString((uint8_t*)itoa(UartHandle.Init.StopBits, buffer, 10));
	uartSendString((uint8_t*)"\r\nParity: ");
	uartSendString((uint8_t*)itoa(UartHandle.Init.Parity, buffer, 10));
	uartSendString((uint8_t*)"\r\nHwFlowCtl: ");
	uartSendString((uint8_t*)itoa(UartHandle.Init.HwFlowCtl, buffer, 10));
	uartSendString((uint8_t*)"\r\nMode: ");
	uartSendString((uint8_t*)itoa(UartHandle.Init.Mode, buffer, 10));
	uartSendString((uint8_t*)"\r\nOverSampling: ");
	uartSendString((uint8_t*)itoa(UartHandle.Init.OverSampling, buffer, 10));
	uartSendString((uint8_t*)"\r\n");
	uartSendString((uint8_t*)"-------------------------------------------\r\n");

	return true;
}

void uartSendString(uint8_t* pstring)
{
	while(*pstring != '\0')
	{
		HAL_UART_Transmit(&UartHandle, pstring, 1, 1);
		pstring++;
	}

}

void uartSendStringSize(uint8_t* pstring, uint16_t size)
{
	HAL_UART_Transmit(&UartHandle, pstring, size, size);
}

void uartReceiveStringSize(uint8_t* pstring, uint16_t size)
{
	HAL_UART_Receive(&UartHandle, pstring, size, size);
}
