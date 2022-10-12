/*
 * API_uart.c
 *
 *  Created on: Oct 11, 2022
 *      Author: cfunes
 */
#include "API_uart.h"
#include "main.h"

/* UART handler declaration */
static UART_HandleTypeDef UartHandle;

bool_t uartInit(void)
{
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

	return (HAL_UART_Init(&UartHandle) != HAL_OK) ? false : true;
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
