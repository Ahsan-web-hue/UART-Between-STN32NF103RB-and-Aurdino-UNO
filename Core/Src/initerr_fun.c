#include "interr_fun.h"

void GPIO_EXTI_Init(LEDS * const led)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    if (led == NULL)
    {
        return;
    }

    /* Enable GPIO Clock */
    if (led->Port == GPIOA)
    {
        __HAL_RCC_GPIOA_CLK_ENABLE();
    }
    else if (led->Port == GPIOB)
    {
        __HAL_RCC_GPIOB_CLK_ENABLE();
    }
    else if (led->Port == GPIOC)
    {
        __HAL_RCC_GPIOC_CLK_ENABLE();
    }
    else
    {
        return;
    }

    GPIO_InitStruct.Pin  = led->Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
    GPIO_InitStruct.Pull = GPIO_PULLUP;

    HAL_GPIO_Init(led->Port, &GPIO_InitStruct);

    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0U, 0U);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}
