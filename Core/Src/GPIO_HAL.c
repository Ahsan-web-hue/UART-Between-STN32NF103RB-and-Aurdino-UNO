#include "GPIO_HAL.h"

/*----------------------------------------------------------
 * Initialize GPIO Output
 *---------------------------------------------------------*/
void LED_Init(LEDS * const led)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    if (led == NULL)
    {
        return;
    }

    /* Enable GPIO Clock */
//    if (led->Port == GPIOA)
//    {
//        __HAL_RCC_GPIOA_CLK_ENABLE();
//    }
//    else if (led->Port == GPIOB)
//    {
//        __HAL_RCC_GPIOB_CLK_ENABLE();
//    }
//    else if (led->Port == GPIOC)
//    {
//        __HAL_RCC_GPIOC_CLK_ENABLE();
//        __HAL_RCC_AFIO_CLK_ENABLE();
//    }
//    else
//    {
//        return;
//    }
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_AFIO_CLK_ENABLE();   // Required if using EXTI or AFIO remapping

    /* Configure PC13 as External Interrupt */
    if ((led->Port == GPIOC) && (led->Pin == GPIO_PIN_13))
    {
        GPIO_InitStruct.Pin  = led->Pin;
        GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
        GPIO_InitStruct.Pull = GPIO_PULLUP;

        HAL_GPIO_Init(led->Port, &GPIO_InitStruct);

        HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
    }
    else
    {
        /* Configure LED Output */
        GPIO_InitStruct.Pin   = led->Pin;
        GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull  = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

        HAL_GPIO_Init(led->Port, &GPIO_InitStruct);

        HAL_GPIO_WritePin(led->Port,
                          led->Pin,
                          GPIO_PIN_RESET);
    }
}

/*----------------------------------------------------------
 * LED ON
 *---------------------------------------------------------*/
void LED_On(LEDS * const led)
{
    if (led != NULL)
    {
        HAL_GPIO_WritePin(led->Port,
                          led->Pin,
                          GPIO_PIN_SET);
    }
}

/*----------------------------------------------------------
 * LED OFF
 *---------------------------------------------------------*/
void LED_Off(LEDS * const led)
{
    if (led != NULL)
    {
        HAL_GPIO_WritePin(led->Port,
                          led->Pin,
                          GPIO_PIN_RESET);
    }
}

/*----------------------------------------------------------
 * Toggle LED
 *---------------------------------------------------------*/
void LED_TogglePin(LEDS * const led)
{
    if (led != NULL)
    {
        HAL_GPIO_TogglePin(led->Port,
                           led->Pin);
    }
}

/*----------------------------------------------------------
 * Read Pin State
 *---------------------------------------------------------*/
GPIO_PinState Read_Pin(LEDS * const led)
{
    GPIO_PinState State = GPIO_PIN_RESET;

    if (led != NULL)
    {
        State = HAL_GPIO_ReadPin(led->Port,
                                 led->Pin);
    }

    return State;
}
