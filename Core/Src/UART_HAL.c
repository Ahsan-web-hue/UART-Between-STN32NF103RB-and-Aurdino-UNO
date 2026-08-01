/******************************************************************************
 * @file    UART_HAL.c
 * @brief   UART HAL Driver
 *
 * @details Implements UART initialization and blocking
 *          transmit/receive APIs.
 *
 * @author  Ahsan Basharat
 * @date    31-Jul-2026
 ******************************************************************************/

#include "UART_HAL.h"
#include <string.h>

#define UART_TIMEOUT    (1000U)

/******************************************************************************
 * @brief Initialize UART peripheral.
 *
 * @param uart Pointer to UART object.
 *
 * @note Configures USART1 with:
 *       BaudRate   : 115200
 *       WordLength : 8 Bits
 *       StopBits   : 1
 *       Parity     : None
 *       Mode       : TX/RX
 ******************************************************************************/
void UART_Init(UART_HAL * const uart)
{
    if (uart == NULL)
    {
        return;
    }

    /* Enable peripheral clock */
    if (uart->Instance == USART1)
    {
        __HAL_RCC_USART1_CLK_ENABLE();
    }

    uart->Handle.Instance = uart->Instance;

    /* UART Configuration */
    uart->Handle.Init.BaudRate = 115200U;
    uart->Handle.Init.WordLength = UART_WORDLENGTH_8B;
    uart->Handle.Init.StopBits = UART_STOPBITS_1;
    uart->Handle.Init.Parity = UART_PARITY_NONE;
    uart->Handle.Init.Mode = UART_MODE_TX_RX;
    uart->Handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    uart->Handle.Init.OverSampling = UART_OVERSAMPLING_16;

    (void)HAL_UART_Init(&uart->Handle);
}

/******************************************************************************
 * @brief Transmit one character.
 ******************************************************************************/
HAL_StatusTypeDef UART_SendChar(UART_HAL * const uart,
                                char ch)
{
    return HAL_UART_Transmit(&uart->Handle,(uint8_t *)&ch,1U,UART_TIMEOUT);
}

/******************************************************************************
 * @brief Transmit string.
 ******************************************************************************/
HAL_StatusTypeDef UART_SendString(UART_HAL * const uart,
                                  const char *str)
{
    return HAL_UART_Transmit(&uart->Handle,(uint8_t *)str,(uint16_t)strlen(str),UART_TIMEOUT);
}

/******************************************************************************
 * @brief Receive one character.
 ******************************************************************************/
HAL_StatusTypeDef UART_ReadChar(UART_HAL * const uart,
                                char *ch)
{
    return HAL_UART_Receive(&uart->Handle,(uint8_t *)ch,1U,HAL_MAX_DELAY);
}
