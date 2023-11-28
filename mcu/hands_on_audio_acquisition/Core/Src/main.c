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
#include "adc.h"
#include "dma.h"
#include "usart.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "retarget.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define ADC_BUF_SIZE 30000 // before : 256
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#define ADC_BUF_SIZE_SEQ 10000 // rapport
#define THRESHOLD 50000
=======
>>>>>>> a568686 (avancement sans colin 🚀)
=======
#define ADC_BUF_SIZE_SEQ 10000 // rapport
#define THRESHOLD 50000
>>>>>>> ae4cc29 (fin h2b 🏄)
=======
>>>>>>> e65878e (avancement sans colin 🚀)
=======
#define ADC_BUF_SIZE_SEQ 10000 // rapport
#define THRESHOLD 50000
>>>>>>> f377759 (fin h2b 🏄)
=======
>>>>>>> 1e441ad (avancement sans colin 🚀)
=======
#define ADC_BUF_SIZE_SEQ 10000 // rapport
#define THRESHOLD 50000
>>>>>>> 754b14e (fin h2b 🏄)
=======
>>>>>>> 556d07c (avancement sans colin 🚀)
=======
#define ADC_BUF_SIZE_SEQ 10000 // rapport
#define THRESHOLD 50000
>>>>>>> 7bcd62f (fin h2b 🏄)
=======
#define ADC_BUF_SIZE_SEQ 10000 // rapport
#define THRESHOLD 50000
>>>>>>> e9d869fc335fa1630213bb1270206efea7efbfa6
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
volatile int state;
volatile uint16_t ADCBuffer[2*ADC_BUF_SIZE]; /* ADC group regular conversion data (array of data) */
volatile uint16_t ADCBuffer_SEQ[ADC_BUF_SIZE_SEQ]; // rapport
volatile uint16_t* ADCData1;
volatile uint16_t* ADCData2;

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
>>>>>>> e9d869fc335fa1630213bb1270206efea7efbfa6
volatile uint8_t active_buffer = 0; // 0 -> Data1 ; 1-> Data2
volatile uint8_t last_sample = 0;	// 1 quand power passe >=50 -> dernier sample

char hex_encoded_buffer[4*ADC_BUF_SIZE+1]; // ADC_BUF_SIZE > ADC_BUF_SIZE_SEQ
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
volatile uint8_t active_buffer = 0; // 0 -> Data1 ; 1-> Data2
volatile uint8_t last_sample = 0;	// 1 quand power passe >=50 -> dernier sample

>>>>>>> a568686 (avancement sans colin 🚀)
=======
volatile uint8_t active_buffer = 0; // 0 -> Data1 ; 1-> Data2
volatile uint8_t last_sample = 0;	// 1 quand power passe >=50 -> dernier sample

>>>>>>> 74d9a91 (avancement sans colin 🚀)
=======
volatile uint8_t active_buffer = 0; // 0 -> Data1 ; 1-> Data2
volatile uint8_t last_sample = 0;	// 1 quand power passe >=50 -> dernier sample

>>>>>>> 704a8bb (avancement sans colin 🚀)
=======
volatile uint8_t active_buffer = 0; // 0 -> Data1 ; 1-> Data2
volatile uint8_t last_sample = 0;	// 1 quand power passe >=50 -> dernier sample

>>>>>>> e65878e (avancement sans colin 🚀)
=======
volatile uint8_t active_buffer = 0; // 0 -> Data1 ; 1-> Data2
volatile uint8_t last_sample = 0;	// 1 quand power passe >=50 -> dernier sample

>>>>>>> 1e441ad (avancement sans colin 🚀)
=======
volatile uint8_t active_buffer = 0; // 0 -> Data1 ; 1-> Data2
volatile uint8_t last_sample = 0;	// 1 quand power passe >=50 -> dernier sample

>>>>>>> 556d07c (avancement sans colin 🚀)
=======
volatile uint8_t active_buffer = 0; // 0 -> Data1 ; 1-> Data2
volatile uint8_t last_sample = 0;	// 1 quand power passe >=50 -> dernier sample

>>>>>>> ae514d0 (avancement sans colin 🚀)
char hex_encoded_buffer[4*ADC_BUF_SIZE+1];
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 9f4839f (Hands On 2b and a smiley for Mathieu 🤣)
=======
>>>>>>> ae4cc29 (fin h2b 🏄)
=======
char hex_encoded_buffer[4*ADC_BUF_SIZE+1];
>>>>>>> 2479e37 (Hands On 2b and a smiley for Mathieu 🤣)
=======
>>>>>>> 5f2cd98 (fin h2b 🏄)
=======
char hex_encoded_buffer[4*ADC_BUF_SIZE+1];
>>>>>>> 55443d7 (Hands On 2b and a smiley for Mathieu 🤣)
=======
>>>>>>> 1d7321c (fin h2b 🏄)
=======
char hex_encoded_buffer[4*ADC_BUF_SIZE+1];
>>>>>>> 197be3e (Hands On 2b and a smiley for Mathieu 🤣)
=======
>>>>>>> f377759 (fin h2b 🏄)
=======
>>>>>>> b69df25 (Hands On 2b and a smiley for Mathieu 🤣)
=======
>>>>>>> 754b14e (fin h2b 🏄)
=======
>>>>>>> 4677dcc (Hands On 2b and a smiley for Mathieu 🤣)
=======
>>>>>>> 7bcd62f (fin h2b 🏄)
=======
>>>>>>> e9d869fc335fa1630213bb1270206efea7efbfa6
=======
char hex_encoded_buffer[4*ADC_BUF_SIZE+1];
>>>>>>> 795cdad (Hands On 2b and a smiley for Mathieu 🤣)

uint32_t ADC_data = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void hex_encode(char* s, const uint8_t* buf, size_t len);
void print_buffer(uint16_t *buffer);
uint32_t get_signal_power(uint16_t *buffer, size_t len);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {
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


	/*
	// [SEQUENCE H2B]

	uint32_t power;
	if(active_buffer==0){
		if (last_sample==1){
			print_buffer(ADCData2); // pour dans le bon ordre
			print_buffer(ADCData1);
			HAL_TIM_Base_Stop(&htim3);
			HAL_ADC_Stop_DMA(&hadc1);
		} else {
			active_buffer = 1; // remplir l'autre buffer
			power = get_signal_power(ADCData1,ADC_BUF_SIZE);
			printf("Power (1) : %ld\n",power);
			if(power>=THRESHOLD){last_sample = 1;}
		}
	} else {
		if (last_sample == 1){
			print_buffer(ADCBuffer); // 1 puis 2
			HAL_TIM_Base_Stop(&htim3);
			HAL_ADC_Stop_DMA(&hadc1);
		}
		else{
			active_buffer = 0;
			power = get_signal_power(ADCData2,ADC_BUF_SIZE);
			printf("Power (2): %ld\n",power);
			if(power>=THRESHOLD){last_sample = 1;}
		}
=======
	print_buffer(ADCBuffer);
=======
=======
	print_buffer(ADCBuffer);
=======
=======
	print_buffer(ADCBuffer);
=======
=======
	print_buffer(ADCBuffer);
=======


	/*
	// [SEQUENCE H2B]

	uint32_t power;
	if(active_buffer==0){
		if (last_sample==1){
			print_buffer(ADCData2); // pour dans le bon ordre
			print_buffer(ADCData1);
			HAL_TIM_Base_Stop(&htim3);
			HAL_ADC_Stop_DMA(&hadc1);
		} else {
			active_buffer = 1; // remplir l'autre buffer
			power = get_signal_power(ADCData1,ADC_BUF_SIZE);
			printf("Power (1) : %ld\n",power);
			if(power>=THRESHOLD){last_sample = 1;}
		}
	} else {
		if (last_sample == 1){
			print_buffer(ADCBuffer); // 1 puis 2
			HAL_TIM_Base_Stop(&htim3);
			HAL_ADC_Stop_DMA(&hadc1);
		}
		else{
			active_buffer = 0;
			power = get_signal_power(ADCData2,ADC_BUF_SIZE);
			printf("Power (2): %ld\n",power);
			if(power>=THRESHOLD){last_sample = 1;}
		}
=======
	print_buffer(ADCBuffer);
=======


	/*
	// [SEQUENCE H2B]

	uint32_t power;
	if(active_buffer==0){
		if (last_sample==1){
			print_buffer(ADCData2); // pour dans le bon ordre
			print_buffer(ADCData1);
			HAL_TIM_Base_Stop(&htim3);
			HAL_ADC_Stop_DMA(&hadc1);
		} else {
			active_buffer = 1; // remplir l'autre buffer
			power = get_signal_power(ADCData1,ADC_BUF_SIZE);
			printf("Power (1) : %ld\n",power);
			if(power>=THRESHOLD){last_sample = 1;}
		}
	} else {
		if (last_sample == 1){
			print_buffer(ADCBuffer); // 1 puis 2
			HAL_TIM_Base_Stop(&htim3);
			HAL_ADC_Stop_DMA(&hadc1);
		}
		else{
			active_buffer = 0;
			power = get_signal_power(ADCData2,ADC_BUF_SIZE);
			printf("Power (2): %ld\n",power);
			if(power>=THRESHOLD){last_sample = 1;}
		}
=======
	print_buffer(ADCBuffer);
=======
=======
>>>>>>> e9d869fc335fa1630213bb1270206efea7efbfa6
=======
	print_buffer(ADCBuffer);
=======

	// [Q] Normal de devoir appeler les fonctions HAL_ADC_Start ici ? (pour dernier sample)
	// [Q] Pourquoi refaire un sample et pas juste print celui en cours si power >=50 ?

	uint32_t power;
	if(active_buffer==0){
		power = get_signal_power(ADCData1,ADC_BUF_SIZE);
		printf("Power (1) : %ld\n",power);
		if (power >= 50 && last_sample==0){
			last_sample = 1;
			HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCData1, ADC_BUF_SIZE);
		}
		if (last_sample == 1){
			print_buffer(ADCData1);
			active_buffer = 1;
			last_sample = 0;
		}


	} else {
		print_buffer(ADCData2);
		active_buffer = 0;
		power = get_signal_power(ADCData2,ADC_BUF_SIZE);
		printf("Power (2): %ld\n",power);
		if (power >= 50 && last_sample==0){
					last_sample = 1;
					HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCData2, ADC_BUF_SIZE);
		}
		if (last_sample == 1){
			print_buffer(ADCData2);
			active_buffer = 0;
			last_sample = 0;
		}
	}

>>>>>>> ae514d0 (avancement sans colin 🚀)
	HAL_TIM_Base_Stop(&htim3);
	HAL_ADC_Stop_DMA(&hadc1);
}
>>>>>>> 795cdad (Hands On 2b and a smiley for Mathieu 🤣)

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	//printf("Test\n");
	if (GPIO_Pin == B1_Pin) {
//		HAL_ADC_Start(&hadc1);
//		if (HAL_ADC_PollForConversion(&hadc1,0xFFFF) == HAL_OK) {
//			ADC_data = HAL_ADC_GetValue(&hadc1);
//			printf("%d \n", ADC_data);
//		}
//		HAL_ADC_Stop(&hadc1);

		HAL_TIM_Base_Start(&htim3);
		//HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCBuffer, 2*ADC_BUF_SIZE);
		if(active_buffer == 0){
			HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCData1, ADC_BUF_SIZE);
		} else{
			HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCData2, ADC_BUF_SIZE);
		}

	}
	*/

<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 556d07c (avancement sans colin 🚀)
=======



	// [SEQUENCE RAPPORT]

	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET); // LED s'allume
	print_buffer(ADCBuffer_SEQ);
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET); // LED s'arrête
>>>>>>> 7bcd62f (fin h2b 🏄)
	HAL_TIM_Base_Stop(&htim3);
	HAL_ADC_Stop_DMA(&hadc1);


}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	//printf("Test\n");
	// [DEMO!]
	/*
	// [CONSTANT INPUT]
	if (GPIO_Pin == B1_Pin) {
//		HAL_ADC_Start(&hadc1);
//		if (HAL_ADC_PollForConversion(&hadc1,0xFFFF) == HAL_OK) {
//			ADC_data = HAL_ADC_GetValue(&hadc1);
//			printf("%d \n", ADC_data);
//		}
//		HAL_ADC_Stop(&hadc1);

		*/

	/*
	// [SINGLE BUFFER + DOUBLE]
	if (GPIO_Pin == B1_Pin) {
		HAL_TIM_Base_Start(&htim3);
<<<<<<< HEAD
<<<<<<< HEAD
		HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCBuffer, ADC_BUF_SIZE);
>>>>>>> 4677dcc (Hands On 2b and a smiley for Mathieu 🤣)
=======
		//HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCBuffer, 2*ADC_BUF_SIZE);
		if(active_buffer == 0){
			HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCData1, ADC_BUF_SIZE);
		} else{
			HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCData2, ADC_BUF_SIZE);
		}

>>>>>>> 556d07c (avancement sans colin 🚀)
	}
	*/

<<<<<<< HEAD
>>>>>>> 1e441ad (avancement sans colin 🚀)
=======



	// [SEQUENCE RAPPORT]

	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET); // LED s'allume
	print_buffer(ADCBuffer_SEQ);
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET); // LED s'arrête
>>>>>>> 754b14e (fin h2b 🏄)
	HAL_TIM_Base_Stop(&htim3);
	HAL_ADC_Stop_DMA(&hadc1);


}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	//printf("Test\n");
	// [DEMO!]
	/*
	// [CONSTANT INPUT]
	if (GPIO_Pin == B1_Pin) {
//		HAL_ADC_Start(&hadc1);
//		if (HAL_ADC_PollForConversion(&hadc1,0xFFFF) == HAL_OK) {
//			ADC_data = HAL_ADC_GetValue(&hadc1);
//			printf("%d \n", ADC_data);
//		}
//		HAL_ADC_Stop(&hadc1);

		*/

	/*
	// [SINGLE BUFFER + DOUBLE]
	if (GPIO_Pin == B1_Pin) {
		HAL_TIM_Base_Start(&htim3);
<<<<<<< HEAD
<<<<<<< HEAD
		HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCBuffer, ADC_BUF_SIZE);
>>>>>>> b69df25 (Hands On 2b and a smiley for Mathieu 🤣)
=======
		//HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCBuffer, 2*ADC_BUF_SIZE);
		if(active_buffer == 0){
			HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCData1, ADC_BUF_SIZE);
		} else{
			HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCData2, ADC_BUF_SIZE);
		}

>>>>>>> 1e441ad (avancement sans colin 🚀)
	}
<<<<<<< HEAD

>>>>>>> e65878e (avancement sans colin 🚀)
	HAL_TIM_Base_Stop(&htim3);
	HAL_ADC_Stop_DMA(&hadc1);
}
>>>>>>> 197be3e (Hands On 2b and a smiley for Mathieu 🤣)

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	//printf("Test\n");
	if (GPIO_Pin == B1_Pin) {
//		HAL_ADC_Start(&hadc1);
//		if (HAL_ADC_PollForConversion(&hadc1,0xFFFF) == HAL_OK) {
//			ADC_data = HAL_ADC_GetValue(&hadc1);
//			printf("%d \n", ADC_data);
//		}
//		HAL_ADC_Stop(&hadc1);

		HAL_TIM_Base_Start(&htim3);
		//HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCBuffer, 2*ADC_BUF_SIZE);
=======
		// HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCBuffer, 2*ADC_BUF_SIZE); // Single
>>>>>>> 754b14e (fin h2b 🏄)
		if(active_buffer == 0){
			HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCData1, ADC_BUF_SIZE);
		} else{
			HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCData2, ADC_BUF_SIZE);
		}

	}
<<<<<<< HEAD
<<<<<<< HEAD

>>>>>>> 704a8bb (avancement sans colin 🚀)
	HAL_TIM_Base_Stop(&htim3);
	HAL_ADC_Stop_DMA(&hadc1);
}
>>>>>>> 55443d7 (Hands On 2b and a smiley for Mathieu 🤣)

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	//printf("Test\n");
	if (GPIO_Pin == B1_Pin) {
//		HAL_ADC_Start(&hadc1);
//		if (HAL_ADC_PollForConversion(&hadc1,0xFFFF) == HAL_OK) {
//			ADC_data = HAL_ADC_GetValue(&hadc1);
//			printf("%d \n", ADC_data);
//		}
//		HAL_ADC_Stop(&hadc1);

		HAL_TIM_Base_Start(&htim3);
		//HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCBuffer, 2*ADC_BUF_SIZE);
=======
		// HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCBuffer, 2*ADC_BUF_SIZE); // Single
>>>>>>> 7bcd62f (fin h2b 🏄)
		if(active_buffer == 0){
			HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCData1, ADC_BUF_SIZE);
		} else{
			HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCData2, ADC_BUF_SIZE);
		}

	}
<<<<<<< HEAD
<<<<<<< HEAD

>>>>>>> 74d9a91 (avancement sans colin 🚀)
	HAL_TIM_Base_Stop(&htim3);
	HAL_ADC_Stop_DMA(&hadc1);
}
>>>>>>> 2479e37 (Hands On 2b and a smiley for Mathieu 🤣)

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	//printf("Test\n");
	if (GPIO_Pin == B1_Pin) {
//		HAL_ADC_Start(&hadc1);
//		if (HAL_ADC_PollForConversion(&hadc1,0xFFFF) == HAL_OK) {
//			ADC_data = HAL_ADC_GetValue(&hadc1);
//			printf("%d \n", ADC_data);
//		}
//		HAL_ADC_Stop(&hadc1);

		HAL_TIM_Base_Start(&htim3);
		//HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCBuffer, 2*ADC_BUF_SIZE);
		if(active_buffer == 0){
			HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCData1, ADC_BUF_SIZE);
		} else{
			HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCData2, ADC_BUF_SIZE);
		}

	}
=======
>>>>>>> 5f2cd98 (fin h2b 🏄)
	*/

<<<<<<< HEAD
>>>>>>> a568686 (avancement sans colin 🚀)
=======



	// [SEQUENCE RAPPORT]

	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET); // LED s'allume
	print_buffer(ADCBuffer_SEQ);
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET); // LED s'arrête
>>>>>>> ae4cc29 (fin h2b 🏄)
	HAL_TIM_Base_Stop(&htim3);
	HAL_ADC_Stop_DMA(&hadc1);


}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	//printf("Test\n");
	// [DEMO!]
	/*
	// [CONSTANT INPUT]
	if (GPIO_Pin == B1_Pin) {
//		HAL_ADC_Start(&hadc1);
//		if (HAL_ADC_PollForConversion(&hadc1,0xFFFF) == HAL_OK) {
//			ADC_data = HAL_ADC_GetValue(&hadc1);
//			printf("%d \n", ADC_data);
//		}
//		HAL_ADC_Stop(&hadc1);

		*/

	/*
	// [SINGLE BUFFER + DOUBLE]
	if (GPIO_Pin == B1_Pin) {
		HAL_TIM_Base_Start(&htim3);
<<<<<<< HEAD
<<<<<<< HEAD
		HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCBuffer, ADC_BUF_SIZE);
>>>>>>> 9f4839f (Hands On 2b and a smiley for Mathieu 🤣)
=======
		//HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCBuffer, 2*ADC_BUF_SIZE);
=======
		// HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCBuffer, 2*ADC_BUF_SIZE); // Single
>>>>>>> ae4cc29 (fin h2b 🏄)
		if(active_buffer == 0){
			HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCData1, ADC_BUF_SIZE);
		} else{
			HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCData2, ADC_BUF_SIZE);
		}

>>>>>>> a568686 (avancement sans colin 🚀)
	}
=======
>>>>>>> 1d7321c (fin h2b 🏄)
=======
>>>>>>> f377759 (fin h2b 🏄)
	*/


<<<<<<< HEAD
=======

>>>>>>> e9d869fc335fa1630213bb1270206efea7efbfa6


	// [SEQUENCE RAPPORT]

	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET); // LED s'allume
	print_buffer(ADCBuffer_SEQ);
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET); // LED s'arrête
	HAL_TIM_Base_Stop(&htim3);
	HAL_ADC_Stop_DMA(&hadc1);


}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	//printf("Test\n");
	// [DEMO!]
	/*
	// [CONSTANT INPUT]
	if (GPIO_Pin == B1_Pin) {
//		HAL_ADC_Start(&hadc1);
//		if (HAL_ADC_PollForConversion(&hadc1,0xFFFF) == HAL_OK) {
//			ADC_data = HAL_ADC_GetValue(&hadc1);
//			printf("%d \n", ADC_data);
//		}
//		HAL_ADC_Stop(&hadc1);

		*/

	/*
	// [SINGLE BUFFER + DOUBLE]
	if (GPIO_Pin == B1_Pin) {
		HAL_TIM_Base_Start(&htim3);
		// HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCBuffer, 2*ADC_BUF_SIZE); // Single
		if(active_buffer == 0){
			HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCData1, ADC_BUF_SIZE);
		} else{
			HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCData2, ADC_BUF_SIZE);
		}

	}
	*/


<<<<<<< HEAD
=======
>>>>>>> ae4cc29 (fin h2b 🏄)
=======
	*/


>>>>>>> 754b14e (fin h2b 🏄)
=======
	*/


>>>>>>> 7bcd62f (fin h2b 🏄)
=======
>>>>>>> e9d869fc335fa1630213bb1270206efea7efbfa6
	// [SEQUENCE RAPPORT]
	if (GPIO_Pin == B1_Pin) {
		HAL_TIM_Base_Start(&htim3);
		HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCBuffer_SEQ, ADC_BUF_SIZE_SEQ);
	}




}

void hex_encode(char* s, const uint8_t* buf, size_t len) {
    s[2*len] = '\0'; // A string terminated by a zero char.
    for (size_t i=0; i<len; i++) {
        s[i*2] = "0123456789abcdef"[buf[i] >> 4];
        s[i*2+1] = "0123456789abcdef"[buf[i] & 0xF];
    }
}

void print_buffer(uint16_t *buffer) {
	/*
	// [SEQUENCE H2B]
	hex_encode(hex_encoded_buffer, (uint8_t*)buffer, 2*ADC_BUF_SIZE);
	printf("SND:HEX:%s\r\n", hex_encoded_buffer);
	*/

	// [SEQUENCE RAPPORT]
	hex_encode(hex_encoded_buffer, (uint8_t*)buffer, 2*ADC_BUF_SIZE_SEQ);
	printf("SND:HEX:%s\r\n", hex_encoded_buffer);

}

uint32_t get_signal_power(uint16_t *buffer, size_t len){
	uint64_t sum = 0;
	uint64_t sum2 = 0;
	for (size_t i=0; i<len; i++) {
		sum += (uint64_t) buffer[i];
		sum2 += (uint64_t) buffer[i]*(uint64_t) buffer[i];
	}
	return (uint32_t)(sum2/len - sum*sum/len/len);
}
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
  MX_DMA_Init();
  MX_LPUART1_UART_Init();
  MX_ADC1_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
  RetargetInit(&hlpuart1);
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
  printf("Hello from group H :) !\r\n");
=======
  printf("Hello from group H :)))!\r\n");
>>>>>>> a568686 (avancement sans colin 🚀)
=======
  printf("Hello from group H :) !\r\n");
>>>>>>> ae4cc29 (fin h2b 🏄)
=======
  printf("Hello from group H :)))!\r\n");
>>>>>>> 74d9a91 (avancement sans colin 🚀)
=======
  printf("Hello from group H :) !\r\n");
>>>>>>> 5f2cd98 (fin h2b 🏄)
=======
  printf("Hello from group H :)))!\r\n");
>>>>>>> 704a8bb (avancement sans colin 🚀)
=======
  printf("Hello from group H :) !\r\n");
>>>>>>> 1d7321c (fin h2b 🏄)
=======
  printf("Hello from group H :)))!\r\n");
>>>>>>> e65878e (avancement sans colin 🚀)
=======
  printf("Hello from group H :) !\r\n");
>>>>>>> f377759 (fin h2b 🏄)
=======
  printf("Hello from group H :)))!\r\n");
>>>>>>> 1e441ad (avancement sans colin 🚀)
=======
  printf("Hello from group H :) !\r\n");
>>>>>>> 754b14e (fin h2b 🏄)
=======
  printf("Hello from group H :)))!\r\n");
>>>>>>> 556d07c (avancement sans colin 🚀)
=======
  printf("Hello from group H :) !\r\n");
>>>>>>> 7bcd62f (fin h2b 🏄)
=======
  printf("Hello from group H :) !\r\n");
>>>>>>> e9d869fc335fa1630213bb1270206efea7efbfa6
=======
  printf("Hello from group H :)))!\r\n");
>>>>>>> ae514d0 (avancement sans colin 🚀)
  state=0;
  ADCData1 = &ADCBuffer[0];
  ADCData2 = &ADCBuffer[ADC_BUF_SIZE];
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	/*
	// [CLIGNOTEMENT LED]
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	HAL_Delay(500);
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
	HAL_Delay(500);
	*/

	__WFI(); // Séquence Rapport

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
