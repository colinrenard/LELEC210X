/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    adc.c
  * @brief   This file provides code for the configuration
  *          of the ADC instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "adc.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

/* ADC1 init function */
void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_MultiModeTypeDef multimode = {0};
  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc1.Init.LowPowerAutoWait = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_EXTERNALTRIG_T3_TRGO;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_RISING;
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
  hadc1.Init.DMAContinuousRequests = ENABLE;
=======
  hadc1.Init.DMAContinuousRequests = DISABLE;
>>>>>>> 9f4839f (Hands On 2b and a smiley for Mathieu 🤣)
=======
  hadc1.Init.DMAContinuousRequests = ENABLE;
>>>>>>> a568686 (avancement sans colin 🚀)
=======
  hadc1.Init.DMAContinuousRequests = DISABLE;
>>>>>>> 2479e37 (Hands On 2b and a smiley for Mathieu 🤣)
=======
  hadc1.Init.DMAContinuousRequests = ENABLE;
>>>>>>> 74d9a91 (avancement sans colin 🚀)
=======
  hadc1.Init.DMAContinuousRequests = DISABLE;
>>>>>>> 55443d7 (Hands On 2b and a smiley for Mathieu 🤣)
=======
  hadc1.Init.DMAContinuousRequests = ENABLE;
>>>>>>> 704a8bb (avancement sans colin 🚀)
=======
  hadc1.Init.DMAContinuousRequests = DISABLE;
>>>>>>> 197be3e (Hands On 2b and a smiley for Mathieu 🤣)
=======
  hadc1.Init.DMAContinuousRequests = ENABLE;
>>>>>>> e65878e (avancement sans colin 🚀)
=======
  hadc1.Init.DMAContinuousRequests = DISABLE;
>>>>>>> b69df25 (Hands On 2b and a smiley for Mathieu 🤣)
=======
  hadc1.Init.DMAContinuousRequests = ENABLE;
>>>>>>> 1e441ad (avancement sans colin 🚀)
=======
  hadc1.Init.DMAContinuousRequests = DISABLE;
>>>>>>> 4677dcc (Hands On 2b and a smiley for Mathieu 🤣)
=======
  hadc1.Init.DMAContinuousRequests = ENABLE;
>>>>>>> 556d07c (avancement sans colin 🚀)
=======
  hadc1.Init.DMAContinuousRequests = ENABLE;
>>>>>>> e9d869fc335fa1630213bb1270206efea7efbfa6
=======
  hadc1.Init.DMAContinuousRequests = DISABLE;
>>>>>>> 795cdad (Hands On 2b and a smiley for Mathieu 🤣)
=======
  hadc1.Init.DMAContinuousRequests = ENABLE;
>>>>>>> ae514d0 (avancement sans colin 🚀)
  hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  hadc1.Init.OversamplingMode = DISABLE;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure the ADC multi-mode
  */
  multimode.Mode = ADC_MODE_INDEPENDENT;
  if (HAL_ADCEx_MultiModeConfigChannel(&hadc1, &multimode) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_5;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_2CYCLES_5;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

void HAL_ADC_MspInit(ADC_HandleTypeDef* adcHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(adcHandle->Instance==ADC1)
  {
  /* USER CODE BEGIN ADC1_MspInit 0 */

  /* USER CODE END ADC1_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
    PeriphClkInit.AdcClockSelection = RCC_ADCCLKSOURCE_SYSCLK;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* ADC1 clock enable */
    __HAL_RCC_ADC_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**ADC1 GPIO Configuration
    PA0     ------> ADC1_IN5
    */
    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* ADC1 DMA Init */
    /* ADC1 Init */
    hdma_adc1.Instance = DMA1_Channel1;
    hdma_adc1.Init.Request = DMA_REQUEST_0;
    hdma_adc1.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_adc1.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_adc1.Init.MemInc = DMA_MINC_ENABLE;
    hdma_adc1.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
    hdma_adc1.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
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
    hdma_adc1.Init.Mode = DMA_CIRCULAR;
=======
    hdma_adc1.Init.Mode = DMA_NORMAL;
>>>>>>> 9f4839f (Hands On 2b and a smiley for Mathieu 🤣)
=======
    hdma_adc1.Init.Mode = DMA_CIRCULAR;
>>>>>>> a568686 (avancement sans colin 🚀)
=======
    hdma_adc1.Init.Mode = DMA_NORMAL;
>>>>>>> 2479e37 (Hands On 2b and a smiley for Mathieu 🤣)
=======
    hdma_adc1.Init.Mode = DMA_CIRCULAR;
>>>>>>> 74d9a91 (avancement sans colin 🚀)
=======
    hdma_adc1.Init.Mode = DMA_NORMAL;
>>>>>>> 55443d7 (Hands On 2b and a smiley for Mathieu 🤣)
=======
    hdma_adc1.Init.Mode = DMA_CIRCULAR;
>>>>>>> 704a8bb (avancement sans colin 🚀)
=======
    hdma_adc1.Init.Mode = DMA_NORMAL;
>>>>>>> 197be3e (Hands On 2b and a smiley for Mathieu 🤣)
=======
    hdma_adc1.Init.Mode = DMA_CIRCULAR;
>>>>>>> e65878e (avancement sans colin 🚀)
=======
    hdma_adc1.Init.Mode = DMA_NORMAL;
>>>>>>> b69df25 (Hands On 2b and a smiley for Mathieu 🤣)
=======
    hdma_adc1.Init.Mode = DMA_CIRCULAR;
>>>>>>> 1e441ad (avancement sans colin 🚀)
=======
    hdma_adc1.Init.Mode = DMA_NORMAL;
>>>>>>> 4677dcc (Hands On 2b and a smiley for Mathieu 🤣)
=======
    hdma_adc1.Init.Mode = DMA_CIRCULAR;
>>>>>>> 556d07c (avancement sans colin 🚀)
=======
    hdma_adc1.Init.Mode = DMA_CIRCULAR;
>>>>>>> e9d869fc335fa1630213bb1270206efea7efbfa6
=======
    hdma_adc1.Init.Mode = DMA_NORMAL;
>>>>>>> 795cdad (Hands On 2b and a smiley for Mathieu 🤣)
=======
    hdma_adc1.Init.Mode = DMA_CIRCULAR;
>>>>>>> ae514d0 (avancement sans colin 🚀)
    hdma_adc1.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_adc1) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(adcHandle,DMA_Handle,hdma_adc1);

  /* USER CODE BEGIN ADC1_MspInit 1 */

  /* USER CODE END ADC1_MspInit 1 */
  }
}

void HAL_ADC_MspDeInit(ADC_HandleTypeDef* adcHandle)
{

  if(adcHandle->Instance==ADC1)
  {
  /* USER CODE BEGIN ADC1_MspDeInit 0 */

  /* USER CODE END ADC1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_ADC_CLK_DISABLE();

    /**ADC1 GPIO Configuration
    PA0     ------> ADC1_IN5
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_0);

    /* ADC1 DMA DeInit */
    HAL_DMA_DeInit(adcHandle->DMA_Handle);
  /* USER CODE BEGIN ADC1_MspDeInit 1 */

  /* USER CODE END ADC1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
