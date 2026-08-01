/******************************************************************************
 * @file    UART_HAL.h
 * @brief   UART Hardware Abstraction Layer.
 *
 * @details Provides a simple UART driver using the STM32 HAL library.
 *          Supports blocking transmit and receive operations.
 *
 * @author  Ahsan Basharat
 * @date    31-Jul-2026
 ******************************************************************************/

#ifndef UART_HAL_H
#define UART_HAL_H

#include "stm32f1xx_hal.h"
#include <stdint.h>

typedef struct
{
    USART_TypeDef *Instance;      /* UART peripheral instance */
    UART_HandleTypeDef Handle;    /* HAL UART handle */

} UART_HAL;

/*----------------------------------------------------------------------------
 * Function Prototypes
 *---------------------------------------------------------------------------*/

/**
 * @brief Initialize UART peripheral.
 *
 * @param uart Pointer to UART object.
 */
void UART_Init(UART_HAL * const uart);

/**
 * @brief Transmit one character.
 *
 * @param uart Pointer to UART object.
 * @param ch Character to transmit.
 *
 * @return HAL status.
 */
HAL_StatusTypeDef UART_SendChar(UART_HAL * const uart,char ch);

/**
 * @brief Transmit a null-terminated string.
 *
 * @param uart Pointer to UART object.
 * @param str Pointer to string.
 *
 * @return HAL status.
 */
HAL_StatusTypeDef UART_SendString(UART_HAL * const uart,  const char *str);


/**
 * @brief Receive one character.
 *
 * @param uart Pointer to UART object.
 * @param ch Pointer to received character.
 *
 * @return HAL status.
 */
HAL_StatusTypeDef UART_ReadChar(UART_HAL * const uart,char *ch);


#endif
