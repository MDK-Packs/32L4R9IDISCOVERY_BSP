/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file         stm32l4xx_hal_msp.c
  * @brief        This file provides code for the MSP Initialization
  *               and de-Initialization codes.
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
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN Define */

/* USER CODE END Define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* External functions --------------------------------------------------------*/
/* USER CODE BEGIN ExternalFunctions */

/* USER CODE END ExternalFunctions */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{
  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  __HAL_RCC_SYSCFG_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();

  /* System interrupt init*/

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

/**
* @brief DMA2D MSP Initialization
* This function configures the hardware resources used in this example
* @param hdma2d: DMA2D handle pointer
* @retval None
*/
void HAL_DMA2D_MspInit(DMA2D_HandleTypeDef* hdma2d)
{
  if(hdma2d->Instance==DMA2D)
  {
  /* USER CODE BEGIN DMA2D_MspInit 0 */

  /* USER CODE END DMA2D_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_DMA2D_CLK_ENABLE();
  /* USER CODE BEGIN DMA2D_MspInit 1 */

  /* USER CODE END DMA2D_MspInit 1 */
  }

}

/**
* @brief DMA2D MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hdma2d: DMA2D handle pointer
* @retval None
*/
void HAL_DMA2D_MspDeInit(DMA2D_HandleTypeDef* hdma2d)
{
  if(hdma2d->Instance==DMA2D)
  {
  /* USER CODE BEGIN DMA2D_MspDeInit 0 */

  /* USER CODE END DMA2D_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_DMA2D_CLK_DISABLE();
  /* USER CODE BEGIN DMA2D_MspDeInit 1 */

  /* USER CODE END DMA2D_MspDeInit 1 */
  }

}

/**
* @brief DSI MSP Initialization
* This function configures the hardware resources used in this example
* @param hdsi: DSI handle pointer
* @retval None
*/
void HAL_DSI_MspInit(DSI_HandleTypeDef* hdsi)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(hdsi->Instance==DSI)
  {
  /* USER CODE BEGIN DSI_MspInit 0 */

  /* USER CODE END DSI_MspInit 0 */
  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_DSI;
    PeriphClkInit.DsiClockSelection = RCC_DSICLKSOURCE_DSIPHY;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* Peripheral clock enable */
    __HAL_RCC_DSI_CLK_ENABLE();
  /* USER CODE BEGIN DSI_MspInit 1 */

  /* USER CODE END DSI_MspInit 1 */
  }

}

/**
* @brief DSI MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hdsi: DSI handle pointer
* @retval None
*/
void HAL_DSI_MspDeInit(DSI_HandleTypeDef* hdsi)
{
  if(hdsi->Instance==DSI)
  {
  /* USER CODE BEGIN DSI_MspDeInit 0 */

  /* USER CODE END DSI_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_DSI_CLK_DISABLE();
  /* USER CODE BEGIN DSI_MspDeInit 1 */

  /* USER CODE END DSI_MspDeInit 1 */
  }

}

/**
* @brief GFXMMU MSP Initialization
* This function configures the hardware resources used in this example
* @param hgfxmmu: GFXMMU handle pointer
* @retval None
*/
void HAL_GFXMMU_MspInit(GFXMMU_HandleTypeDef* hgfxmmu)
{
  if(hgfxmmu->Instance==GFXMMU)
  {
  /* USER CODE BEGIN GFXMMU_MspInit 0 */

  /* USER CODE END GFXMMU_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_GFXMMU_CLK_ENABLE();
  /* USER CODE BEGIN GFXMMU_MspInit 1 */

  /* USER CODE END GFXMMU_MspInit 1 */
  }

}

/**
* @brief GFXMMU MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hgfxmmu: GFXMMU handle pointer
* @retval None
*/
void HAL_GFXMMU_MspDeInit(GFXMMU_HandleTypeDef* hgfxmmu)
{
  if(hgfxmmu->Instance==GFXMMU)
  {
  /* USER CODE BEGIN GFXMMU_MspDeInit 0 */

  /* USER CODE END GFXMMU_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_GFXMMU_CLK_DISABLE();
  /* USER CODE BEGIN GFXMMU_MspDeInit 1 */

  /* USER CODE END GFXMMU_MspDeInit 1 */
  }

}

/**
* @brief LTDC MSP Initialization
* This function configures the hardware resources used in this example
* @param hltdc: LTDC handle pointer
* @retval None
*/
void HAL_LTDC_MspInit(LTDC_HandleTypeDef* hltdc)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(hltdc->Instance==LTDC)
  {
  /* USER CODE BEGIN LTDC_MspInit 0 */

  /* USER CODE END LTDC_MspInit 0 */
  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_LTDC;
    PeriphClkInit.LtdcClockSelection = RCC_LTDCCLKSOURCE_PLLSAI2_DIV2;
    PeriphClkInit.PLLSAI2.PLLSAI2Source = RCC_PLLSOURCE_HSE;
    PeriphClkInit.PLLSAI2.PLLSAI2M = 2;
    PeriphClkInit.PLLSAI2.PLLSAI2N = 8;
    PeriphClkInit.PLLSAI2.PLLSAI2P = RCC_PLLP_DIV2;
    PeriphClkInit.PLLSAI2.PLLSAI2R = RCC_PLLR_DIV2;
    PeriphClkInit.PLLSAI2.PLLSAI2Q = RCC_PLLQ_DIV2;
    PeriphClkInit.PLLSAI2.PLLSAI2ClockOut = RCC_PLLSAI2_LTDCCLK;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* Peripheral clock enable */
    __HAL_RCC_LTDC_CLK_ENABLE();
  /* USER CODE BEGIN LTDC_MspInit 1 */

  /* USER CODE END LTDC_MspInit 1 */
  }

}

/**
* @brief LTDC MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hltdc: LTDC handle pointer
* @retval None
*/
void HAL_LTDC_MspDeInit(LTDC_HandleTypeDef* hltdc)
{
  if(hltdc->Instance==LTDC)
  {
  /* USER CODE BEGIN LTDC_MspDeInit 0 */

  /* USER CODE END LTDC_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_LTDC_CLK_DISABLE();
  /* USER CODE BEGIN LTDC_MspDeInit 1 */

  /* USER CODE END LTDC_MspDeInit 1 */
  }

}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
