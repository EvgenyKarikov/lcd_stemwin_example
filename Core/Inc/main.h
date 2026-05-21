/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
#ifndef DEBUG_BUF_SIZE
  #define DEBUG_BUF_SIZE 512
#endif
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
#define WK_UP_Pin GPIO_PIN_13
#define WK_UP_GPIO_Port GPIOC
#define SD_CS_Pin GPIO_PIN_3
#define SD_CS_GPIO_Port GPIOC
#define MOTOR_B_Pin GPIO_PIN_0
#define MOTOR_B_GPIO_Port GPIOA
#define MOTOR_A_Pin GPIO_PIN_1
#define MOTOR_A_GPIO_Port GPIOA
#define WIFI_INT_Pin GPIO_PIN_5
#define WIFI_INT_GPIO_Port GPIOC
#define BEEP_Pin GPIO_PIN_2
#define BEEP_GPIO_Port GPIOB
#define LED_RED_Pin GPIO_PIN_7
#define LED_RED_GPIO_Port GPIOE
#define LED_GREEN_Pin GPIO_PIN_8
#define LED_GREEN_GPIO_Port GPIOE
#define LED_BLUE_Pin GPIO_PIN_9
#define LED_BLUE_GPIO_Port GPIOE
#define NRF_CLK_Pin GPIO_PIN_13
#define NRF_CLK_GPIO_Port GPIOB
#define NRF_MISO_Pin GPIO_PIN_14
#define NRF_MISO_GPIO_Port GPIOB
#define KEY2_Pin GPIO_PIN_8
#define KEY2_GPIO_Port GPIOD
#define KEY1_Pin GPIO_PIN_9
#define KEY1_GPIO_Port GPIOD
#define KEY0_Pin GPIO_PIN_10
#define KEY0_GPIO_Port GPIOD
#define AUDIO_PWR_Pin GPIO_PIN_15
#define AUDIO_PWR_GPIO_Port GPIOA
#define ICM_INT_Pin GPIO_PIN_0
#define ICM_INT_GPIO_Port GPIOD
#define WIFI_REG_ON_Pin GPIO_PIN_1
#define WIFI_REG_ON_GPIO_Port GPIOD
#define NRF_IRQ_Pin GPIO_PIN_3
#define NRF_IRQ_GPIO_Port GPIOD
#define NRF_CE_Pin GPIO_PIN_4
#define NRF_CE_GPIO_Port GPIOD
#define NRF_CS_Pin GPIO_PIN_5
#define NRF_CS_GPIO_Port GPIOD
#define AHT10_IIC_CLK_Pin GPIO_PIN_6
#define AHT10_IIC_CLK_GPIO_Port GPIOD
#define LCD_CS_Pin GPIO_PIN_7
#define LCD_CS_GPIO_Port GPIOD
#define LCD_CLK_Pin GPIO_PIN_3
#define LCD_CLK_GPIO_Port GPIOB
#define LCD_WR_Pin GPIO_PIN_4
#define LCD_WR_GPIO_Port GPIOB
#define LCD_SDA_Pin GPIO_PIN_5
#define LCD_SDA_GPIO_Port GPIOB
#define LCD_RST_Pin GPIO_PIN_6
#define LCD_RST_GPIO_Port GPIOB
#define LCD_PWR_Pin GPIO_PIN_7
#define LCD_PWR_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
#define GET_PIN(PORT,PIN)               ((PORT->IDR & PIN) != (uint32_t)GPIO_PIN_RESET)
#define SET_PIN(PORT,PIN)               (PORT->BSRR = PIN)
#define RESET_PIN(PORT,PIN)             (PORT->BSRR = ((uint32_t)PIN << 16U))

#define LCD_DC_Pin              LCD_WR_Pin
#define LCD_DC_GPIO_Port        LCD_WR_GPIO_Port
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
