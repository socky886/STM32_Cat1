/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define B1_EXTI_IRQn EXTI15_10_IRQn
#define OLED_SCL_Pin GPIO_PIN_0
#define OLED_SCL_GPIO_Port GPIOC
#define OLED_SDA_Pin GPIO_PIN_1
#define OLED_SDA_GPIO_Port GPIOC
#define IN1_Pin GPIO_PIN_0
#define IN1_GPIO_Port GPIOA
#define IN2_Pin GPIO_PIN_1
#define IN2_GPIO_Port GPIOA
#define CAT_RX_Pin GPIO_PIN_2
#define CAT_RX_GPIO_Port GPIOA
#define CAT_TX_Pin GPIO_PIN_3
#define CAT_TX_GPIO_Port GPIOA
#define IN3_Pin GPIO_PIN_4
#define IN3_GPIO_Port GPIOA
#define RIGHT_KEY_Pin GPIO_PIN_10
#define RIGHT_KEY_GPIO_Port GPIOB
#define RIGHT_KEY_EXTI_IRQn EXTI15_10_IRQn
#define SPI1_CS_Pin GPIO_PIN_8
#define SPI1_CS_GPIO_Port GPIOA
#define DUT_TX_Pin GPIO_PIN_9
#define DUT_TX_GPIO_Port GPIOA
#define DUT_RX_Pin GPIO_PIN_10
#define DUT_RX_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define OK_KEY_Pin GPIO_PIN_3
#define OK_KEY_GPIO_Port GPIOB
#define OK_KEY_EXTI_IRQn EXTI3_IRQn
#define UP_KEY_Pin GPIO_PIN_4
#define UP_KEY_GPIO_Port GPIOB
#define UP_KEY_EXTI_IRQn EXTI4_IRQn
#define DOWN_KEY_Pin GPIO_PIN_5
#define DOWN_KEY_GPIO_Port GPIOB
#define DOWN_KEY_EXTI_IRQn EXTI9_5_IRQn
#define LEFT_KEY_Pin GPIO_PIN_6
#define LEFT_KEY_GPIO_Port GPIOB
#define LEFT_KEY_EXTI_IRQn EXTI9_5_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
