/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
#define LA_Pin GPIO_PIN_0
#define LA_GPIO_Port GPIOA
#define LB_Pin GPIO_PIN_1
#define LB_GPIO_Port GPIOA
#define RA_Pin GPIO_PIN_6
#define RA_GPIO_Port GPIOA
#define RB_Pin GPIO_PIN_7
#define RB_GPIO_Port GPIOA
#define HYRUN_Pin GPIO_PIN_15
#define HYRUN_GPIO_Port GPIOB
#define PWMA_Pin GPIO_PIN_8
#define PWMA_GPIO_Port GPIOA
#define HYOUT_Pin GPIO_PIN_12
#define HYOUT_GPIO_Port GPIOA
#define BIN2_Pin GPIO_PIN_15
#define BIN2_GPIO_Port GPIOA
#define BIN1_Pin GPIO_PIN_3
#define BIN1_GPIO_Port GPIOB
#define AIN2_Pin GPIO_PIN_4
#define AIN2_GPIO_Port GPIOB
#define AIN1_Pin GPIO_PIN_5
#define AIN1_GPIO_Port GPIOB
#define L3_Pin GPIO_PIN_6
#define L3_GPIO_Port GPIOB
#define L2_Pin GPIO_PIN_7
#define L2_GPIO_Port GPIOB
#define PWMB_Pin GPIO_PIN_8
#define PWMB_GPIO_Port GPIOB
#define STBY_Pin GPIO_PIN_9
#define STBY_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
