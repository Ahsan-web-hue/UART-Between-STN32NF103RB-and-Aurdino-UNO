#ifndef INC_GPIO_HAL_H_
#define INC_GPIO_HAL_H_

#include "stm32f1xx_hal.h"

/*=========================================================
 * GPIO Object
 *========================================================*/
typedef struct
{
    GPIO_TypeDef *Port;
    uint16_t Pin;

} LEDS;

/*=========================================================
 * Function Prototypes
 *========================================================*/

/* Initialize GPIO Pin as Output */
void LED_Init(LEDS * const led);
/* LED Control */
void LED_On(LEDS * const led);
void LED_Off(LEDS * const led);
void LED_TogglePin(LEDS * const led);

/* Read Pin State */
GPIO_PinState Read_Pin(LEDS * const led);

#endif /* INC_GPIO_HAL_H_ */
