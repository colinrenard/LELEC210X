/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usart.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "retarget.h""retarget.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int blue_button = 0;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_LPUART1_UART_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */
  RetargetInit(&hlpuart1);
  printf("Hello world!\r\n");

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 0bc45eb (hands on 2 code)
=======
>>>>>>> b4bd9b6 (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> 7387a6f (hands on 2 code)
=======
>>>>>>> dffbce0 (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> 3e45de6 (hands on 2 code)
=======
>>>>>>> b44abd4 (hands on 2 code)
=======
>>>>>>> dad352b (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> 9976e44 (hands on 2 code)
=======
>>>>>>> a1342b2 (hands on 2 code)
=======
>>>>>>> 4ce6c36 (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> 114bca7 (hands on 2 code)
=======
=======
=======
>>>>>>> 23f59fe0db3345a3c0d515744d902b87d726b5a9
>>>>>>> b66da5a3d91a15c5bdbb66ca5b1d08815b7e0e55
>>>>>>> e9d869fc335fa1630213bb1270206efea7efbfa6
	  //HAL_Delay(1);
	  //__WFI();
=======
=======
>>>>>>> bf0f14f (hands on 2 code)
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> e9d869fc335fa1630213bb1270206efea7efbfa6
=======
>>>>>>> f8a72b7 (hands on 2 code)
=======
>>>>>>> 023d92b (hands on 2 code)
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> e9d869fc335fa1630213bb1270206efea7efbfa6
=======
>>>>>>> 4657125 (hands on 2 code)
=======
>>>>>>> 7322888 (hands on 2 code)
=======
>>>>>>> e3ac280 (hands on 2 code)
=======
>>>>>>> c2432af (hands on 2 code)
<<<<<<< HEAD
=======
>>>>>>> bf0f14f (hands on 2 code)
=======
>>>>>>> f8a72b7 (hands on 2 code)
=======
>>>>>>> 023d92b (hands on 2 code)
=======
>>>>>>> 4657125 (hands on 2 code)
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 7322888 (hands on 2 code)
=======
>>>>>>> e3ac280 (hands on 2 code)
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> c2432af (hands on 2 code)
=======
>>>>>>> ca2e54d (hands on 2 code)
=======
>>>>>>> 631f73f (hands on 2 code)
=======
>>>>>>> 8a80c09 (hands on 2 code)
=======
>>>>>>> 5c43933 (hands on 2 code)
=======
	  //HAL_Delay(1);
	  //__WFI();
=======
>>>>>>> 4ea202f (hands on 2 code)
=======
>>>>>>> 0bc45eb (hands on 2 code)
=======
=======
>>>>>>> f8a72b7 (hands on 2 code)
>>>>>>> 7387a6f (hands on 2 code)
=======
>>>>>>> 3e45de6 (hands on 2 code)
=======
>>>>>>> b44abd4 (hands on 2 code)
=======
=======
>>>>>>> 7322888 (hands on 2 code)
>>>>>>> 9976e44 (hands on 2 code)
=======
>>>>>>> a1342b2 (hands on 2 code)
=======
=======
>>>>>>> c2432af (hands on 2 code)
>>>>>>> 114bca7 (hands on 2 code)
=======
<<<<<<< HEAD
>>>>>>> e9d869fc335fa1630213bb1270206efea7efbfa6
=======
>>>>>>> bf0f14f (hands on 2 code)
=======
>>>>>>> f8a72b7 (hands on 2 code)
=======
>>>>>>> 023d92b (hands on 2 code)
=======
>>>>>>> 4657125 (hands on 2 code)
=======
>>>>>>> 7322888 (hands on 2 code)
=======
>>>>>>> e3ac280 (hands on 2 code)
=======
>>>>>>> c2432af (hands on 2 code)
<<<<<<< HEAD
=======
=======
>>>>>>> b66da5a3d91a15c5bdbb66ca5b1d08815b7e0e55
>>>>>>> e9d869fc335fa1630213bb1270206efea7efbfa6
//	  if (blue_button == 1) {
//		  HAL_TIM_OC_Start(&htim4, TIM_CHANNEL_2);
//	  } else {
//		  HAL_TIM_OC_Stop(&htim4, TIM_CHANNEL_2);
//	  }

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 7387a6f (hands on 2 code)
=======
>>>>>>> 9976e44 (hands on 2 code)
=======
>>>>>>> a1342b2 (hands on 2 code)
=======
>>>>>>> 114bca7 (hands on 2 code)
=======
=======
>>>>>>> b66da5a3d91a15c5bdbb66ca5b1d08815b7e0e55
>>>>>>> e9d869fc335fa1630213bb1270206efea7efbfa6
>>>>>>> c2432af (hands on 2 code)
=======
>>>>>>> bf0f14f (hands on 2 code)
=======
	  //HAL_Delay(1);
	  //__WFI();
>>>>>>> 4857028 (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> f8a72b7 (hands on 2 code)
=======
	  //HAL_Delay(1);
	  //__WFI();
>>>>>>> d79862a (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> 023d92b (hands on 2 code)
=======
>>>>>>> 4657125 (hands on 2 code)
=======
	  //HAL_Delay(1);
	  //__WFI();
>>>>>>> 813067d (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> 7322888 (hands on 2 code)
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> e3ac280 (hands on 2 code)
=======
	  //HAL_Delay(1);
	  //__WFI();
>>>>>>> 6f5b50f (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 3e45de6 (hands on 2 code)
=======
>>>>>>> b44abd4 (hands on 2 code)
>>>>>>> c2432af (hands on 2 code)
=======
>>>>>>> bf0f14f (hands on 2 code)
=======
	  //HAL_Delay(1);
	  //__WFI();
>>>>>>> 4857028 (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> f8a72b7 (hands on 2 code)
=======
	  //HAL_Delay(1);
	  //__WFI();
>>>>>>> d79862a (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 023d92b (hands on 2 code)
=======
>>>>>>> 4657125 (hands on 2 code)
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> dad352b (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
	  //HAL_Delay(1);
	  //__WFI();
>>>>>>> 813067d (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
<<<<<<< HEAD
=======
>>>>>>> 7322888 (hands on 2 code)
=======
>>>>>>> e3ac280 (hands on 2 code)
=======
	  //HAL_Delay(1);
	  //__WFI();
>>>>>>> 6f5b50f (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> c2432af (hands on 2 code)
=======
>>>>>>> ca2e54d (hands on 2 code)
=======
	  //HAL_Delay(1);
	  //__WFI();
>>>>>>> cde3d85 (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> 631f73f (hands on 2 code)
=======
	  //HAL_Delay(1);
	  //__WFI();
>>>>>>> 307f066 (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> 8a80c09 (hands on 2 code)
=======
	  //HAL_Delay(1);
	  //__WFI();
>>>>>>> 907c331 (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> 5c43933 (hands on 2 code)
=======
	  //HAL_Delay(1);
	  //__WFI();
>>>>>>> 6337d93 (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> c2432af (hands on 2 code)
>>>>>>> 4ea202f (hands on 2 code)
=======
>>>>>>> c2432af (hands on 2 code)
=======
>>>>>>> bf0f14f (hands on 2 code)
>>>>>>> 0bc45eb (hands on 2 code)
=======
>>>>>>> b4bd9b6 (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
=======
>>>>>>> f8a72b7 (hands on 2 code)
>>>>>>> 7387a6f (hands on 2 code)
=======
>>>>>>> dffbce0 (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
=======
>>>>>>> 023d92b (hands on 2 code)
>>>>>>> 3e45de6 (hands on 2 code)
=======
>>>>>>> b44abd4 (hands on 2 code)
=======
>>>>>>> dad352b (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> 9976e44 (hands on 2 code)
=======
=======
>>>>>>> e3ac280 (hands on 2 code)
>>>>>>> a1342b2 (hands on 2 code)
=======
>>>>>>> 4ce6c36 (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
=======
>>>>>>> c2432af (hands on 2 code)
>>>>>>> 114bca7 (hands on 2 code)
=======
>>>>>>> bf0f14f (hands on 2 code)
=======
	  //HAL_Delay(1);
	  //__WFI();
>>>>>>> 4857028 (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> e9d869fc335fa1630213bb1270206efea7efbfa6
=======
>>>>>>> f8a72b7 (hands on 2 code)
=======
	  //HAL_Delay(1);
	  //__WFI();
>>>>>>> d79862a (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> 023d92b (hands on 2 code)
=======
>>>>>>> 4657125 (hands on 2 code)
=======
	  //HAL_Delay(1);
	  //__WFI();
>>>>>>> 813067d (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> 7322888 (hands on 2 code)
=======
>>>>>>> e3ac280 (hands on 2 code)
=======
	  //HAL_Delay(1);
	  //__WFI();
>>>>>>> 6f5b50f (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> c2432af (hands on 2 code)
<<<<<<< HEAD
=======
=======
<<<<<<< HEAD
>>>>>>> bf0f14f (hands on 2 code)
=======
	  //HAL_Delay(1);
	  //__WFI();
>>>>>>> 4857028 (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> f8a72b7 (hands on 2 code)
=======
	  //HAL_Delay(1);
	  //__WFI();
>>>>>>> d79862a (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> 023d92b (hands on 2 code)
=======
>>>>>>> 4657125 (hands on 2 code)
=======
	  //HAL_Delay(1);
	  //__WFI();
>>>>>>> 813067d (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> 7322888 (hands on 2 code)
=======
>>>>>>> e3ac280 (hands on 2 code)
=======
	  //HAL_Delay(1);
	  //__WFI();
>>>>>>> 6f5b50f (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> c2432af (hands on 2 code)
=======
	  //HAL_Delay(1);
	  //__WFI();
>>>>>>> 6bfb654aea6d168430009f7c99f49364789daa63
>>>>>>> b66da5a3d91a15c5bdbb66ca5b1d08815b7e0e55
>>>>>>> e9d869fc335fa1630213bb1270206efea7efbfa6
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_10;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == B1_Pin) {
	// Insert code to be executed in the interrupt
		if(blue_button == 0) {
			blue_button = 1;
		} else {
			blue_button = 0;
		}
	    if (blue_button == 1) {
		    HAL_TIM_OC_Start(&htim4, TIM_CHANNEL_2);
	    } else {
		    HAL_TIM_OC_Stop(&htim4, TIM_CHANNEL_2);
	  }
	}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> b4bd9b6 (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> b44abd4 (hands on 2 code)
=======
>>>>>>> 114bca7 (hands on 2 code)
=======
>>>>>>> e9d869fc335fa1630213bb1270206efea7efbfa6
=======

>>>>>>> bf0f14f (hands on 2 code)
=======
>>>>>>> 4857028 (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> e9d869fc335fa1630213bb1270206efea7efbfa6
=======

>>>>>>> 4657125 (hands on 2 code)
=======
>>>>>>> 813067d (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======

>>>>>>> e3ac280 (hands on 2 code)
=======
>>>>>>> 6f5b50f (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======

>>>>>>> c2432af (hands on 2 code)
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> dad352b (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> a1342b2 (hands on 2 code)
=======
>>>>>>> 4ce6c36 (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======

>>>>>>> bf0f14f (hands on 2 code)
=======
>>>>>>> 4857028 (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======

>>>>>>> 4657125 (hands on 2 code)
=======
>>>>>>> 813067d (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> e3ac280 (hands on 2 code)
=======
>>>>>>> 6f5b50f (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
<<<<<<< HEAD
=======

>>>>>>> c2432af (hands on 2 code)
=======

>>>>>>> ca2e54d (hands on 2 code)
=======
>>>>>>> cde3d85 (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
=======

>>>>>>> bf0f14f (hands on 2 code)
>>>>>>> 0bc45eb (hands on 2 code)
=======
>>>>>>> b4bd9b6 (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
=======

>>>>>>> 4657125 (hands on 2 code)
>>>>>>> b44abd4 (hands on 2 code)
=======
>>>>>>> dad352b (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
=======

>>>>>>> e3ac280 (hands on 2 code)
>>>>>>> a1342b2 (hands on 2 code)
=======
>>>>>>> 4ce6c36 (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======
>>>>>>> 114bca7 (hands on 2 code)
=======
=======
>>>>>>> b66da5a3d91a15c5bdbb66ca5b1d08815b7e0e55
>>>>>>> e9d869fc335fa1630213bb1270206efea7efbfa6
=======

>>>>>>> bf0f14f (hands on 2 code)
=======
>>>>>>> 4857028 (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======

>>>>>>> 4657125 (hands on 2 code)
=======
>>>>>>> 813067d (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======

>>>>>>> e3ac280 (hands on 2 code)
=======
>>>>>>> 6f5b50f (Hands on 2a modified code and a smiley for Mathieu 👨‍❤️‍💋‍👨)
=======

>>>>>>> c2432af (hands on 2 code)
}

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

#ifdef  USE_FULL_ASSERT
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
