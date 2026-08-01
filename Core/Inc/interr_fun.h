#ifndef INC_INTERR_FUN_H_
#define INC_INTERR_FUN_H_

#include "GPIO_HAL.h"
#include "stm32f1xx_hal.h"

void GPIO_EXTI_Init(LEDS * const led);
//void GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#endif /* INC_INTERR_FUN_H_ */
