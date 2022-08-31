/**
  ******************************************************************************
  * @file    Practica_2/Ejercicio_1/Inc/main.h
  * @author  Cristian Funes
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdbool.h>
#include "stm32f4xx_hal.h"  		/* <- HAL include */
#include "stm32f4xx_nucleo_144.h" 	/* <- BSP include */



/* Exported types ------------------------------------------------------------*/
typedef uint32_t tick_t;
typedef bool bool_t;

typedef struct
{
	tick_t startTime;
	tick_t duration;
	bool_t running;
} delay_t;
/* Exported constants --------------------------------------------------------*/
/* User can use this section to tailor USARTx/UARTx instance used and associated
   resources */
/* Definition for USARTx clock resources */
#define USARTx                           USART3
#define USARTx_CLK_ENABLE()              __HAL_RCC_USART3_CLK_ENABLE();
#define USARTx_RX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOD_CLK_ENABLE()
#define USARTx_TX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOD_CLK_ENABLE()

#define USARTx_FORCE_RESET()             __HAL_RCC_USART3_FORCE_RESET()
#define USARTx_RELEASE_RESET()           __HAL_RCC_USART3_RELEASE_RESET()

/* Definition for USARTx Pins */
#define USARTx_TX_PIN                    GPIO_PIN_8
#define USARTx_TX_GPIO_PORT              GPIOD
#define USARTx_TX_AF                     GPIO_AF7_USART3
#define USARTx_RX_PIN                    GPIO_PIN_9
#define USARTx_RX_GPIO_PORT              GPIOD
#define USARTx_RX_AF                     GPIO_AF7_USART3

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/*
 * @brief 	Inicializa la duracion del retardo especificado y setea la flag running en flase
 * @param 	delay: estructura que contiene el retardo
 * @param	duration: duracion del retardo en ms
 * @retval 	None
 */
void delayInit(delay_t* delay, tick_t duration);

/*
 * @brief 	Verifica si se cumplio el retardo.
 * @param 	delay: estructura que contiene el retardo en ms
 * @retval 	true si se cumplio el retardo. false si no se cumplio el retardo.
 *
 */
bool_t delayRead(delay_t* delay);

/*
 * @brief Setea la duracion de un retardo existente.
 * @param 	delay: estructura que contiene el retardo
 * @param	duration: duracion del retardo en ms
 * @retval	None
 */
void delayWrite(delay_t* delay, tick_t duration);

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
