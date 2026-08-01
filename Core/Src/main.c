
#include "main.h"
#include "usart.h"
#include "gpio.h"
#include"GPIO_HAL.h"
//#include"interr_fun.h"
#include"UART_HAL.h"
#include <stdio.h>
void SystemClock_Config(void);
UART_HAL DebugUART =
{
    USART1
};

char Rx;
LEDS LED1 =
{
    GPIOA,
    GPIO_PIN_5
};

LEDS LED2 =
{
    GPIOA,
    GPIO_PIN_6
};

LEDS LED3 =
{
    GPIOA,
    GPIO_PIN_7
};

LEDS LED4 =
{
    GPIOC,
    GPIO_PIN_4
};
LEDS LED5 =
{
    GPIOB,
    GPIO_PIN_14
};
LEDS LED6 =
{
    GPIOB,
    GPIO_PIN_15
};

//LEDS Button =
//{
//    GPIOC,
//    GPIO_PIN_13
//};


int main(void)
{

  HAL_Init();


  SystemClock_Config();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();

     LED_Init(&LED1);
     LED_Init(&LED2);
     LED_Init(&LED3);
     LED_Init(&LED4);
     LED_Init(&LED5);
     LED_Init(&LED6);

     //LED_Init(&Button);

     UART_Init(&DebugUART);
     UART_SendString(&DebugUART,
                        "UART Driver Ready\r\n");
  while (1)
  {
//	  LED_TogglePin(&LED1);
//	  LED_TogglePin(&LED2);
//	  LED_TogglePin(&LED3);
//	  LED_TogglePin(&LED4);
//	  LED_TogglePin(&LED5);
//	  LED_TogglePin(&LED6);
//	  HAL_Delay(1000);

//	  if (UART_ReadChar(&DebugUART, &Rx) == HAL_OK)
//	          {
//	              UART_SendChar(&DebugUART, Rx);
//	          }
	  if (UART_SendString(&DebugUART, "UART Driver Ready\r\n") == HAL_OK)
	  {
	      LED_TogglePin(&LED4);
	      HAL_Delay(1000);
	  }


  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
