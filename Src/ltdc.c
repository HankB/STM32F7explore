/**
  ******************************************************************************
  * File Name          : LTDC.c
  * Description        : This file provides code for the configuration
  *                      of the LTDC instances.
  ******************************************************************************
  *
  * Copyright (c) 2017 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "ltdc.h"

#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

LTDC_HandleTypeDef hltdc;

/* LTDC init function */
void MX_LTDC_Init(void)
{
  LTDC_LayerCfgTypeDef pLayerCfg;
  LTDC_LayerCfgTypeDef pLayerCfg1;

  hltdc.Instance = LTDC;
  hltdc.Init.HSPolarity = LTDC_HSPOLARITY_AL;
  hltdc.Init.VSPolarity = LTDC_VSPOLARITY_AL;
  hltdc.Init.DEPolarity = LTDC_DEPOLARITY_AL;
  hltdc.Init.PCPolarity = LTDC_PCPOLARITY_IPC;
  hltdc.Init.HorizontalSync = 7;
  hltdc.Init.VerticalSync = 3;
  hltdc.Init.AccumulatedHBP = 14;
  hltdc.Init.AccumulatedVBP = 5;
  hltdc.Init.AccumulatedActiveW = 654;
  hltdc.Init.AccumulatedActiveH = 485;
  hltdc.Init.TotalWidth = 660;
  hltdc.Init.TotalHeigh = 487;
  hltdc.Init.Backcolor.Blue = 0;
  hltdc.Init.Backcolor.Green = 0;
  hltdc.Init.Backcolor.Red = 0;
  if (HAL_LTDC_Init(&hltdc) != HAL_OK)
  {
    Error_Handler();
  }

  pLayerCfg.WindowX0 = 0;
  pLayerCfg.WindowX1 = 0;
  pLayerCfg.WindowY0 = 0;
  pLayerCfg.WindowY1 = 0;
  pLayerCfg.PixelFormat = LTDC_PIXEL_FORMAT_ARGB8888;
  pLayerCfg.Alpha = 0;
  pLayerCfg.Alpha0 = 0;
  pLayerCfg.BlendingFactor1 = LTDC_BLENDING_FACTOR1_CA;
  pLayerCfg.BlendingFactor2 = LTDC_BLENDING_FACTOR2_CA;
  pLayerCfg.FBStartAdress = 0;
  pLayerCfg.ImageWidth = 0;
  pLayerCfg.ImageHeight = 0;
  pLayerCfg.Backcolor.Blue = 0;
  pLayerCfg.Backcolor.Green = 0;
  pLayerCfg.Backcolor.Red = 0;
  if (HAL_LTDC_ConfigLayer(&hltdc, &pLayerCfg, 0) != HAL_OK)
  {
    Error_Handler();
  }

  pLayerCfg1.WindowX0 = 0;
  pLayerCfg1.WindowX1 = 0;
  pLayerCfg1.WindowY0 = 0;
  pLayerCfg1.WindowY1 = 0;
  pLayerCfg1.PixelFormat = LTDC_PIXEL_FORMAT_ARGB8888;
  pLayerCfg1.Alpha = 0;
  pLayerCfg1.Alpha0 = 0;
  pLayerCfg1.BlendingFactor1 = LTDC_BLENDING_FACTOR1_CA;
  pLayerCfg1.BlendingFactor2 = LTDC_BLENDING_FACTOR2_CA;
  pLayerCfg1.FBStartAdress = 0;
  pLayerCfg1.ImageWidth = 0;
  pLayerCfg1.ImageHeight = 0;
  pLayerCfg1.Backcolor.Blue = 0;
  pLayerCfg1.Backcolor.Green = 0;
  pLayerCfg1.Backcolor.Red = 0;
  if (HAL_LTDC_ConfigLayer(&hltdc, &pLayerCfg1, 1) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_LTDC_MspInit(LTDC_HandleTypeDef* ltdcHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct;
  if(ltdcHandle->Instance==LTDC)
  {
  /* USER CODE BEGIN LTDC_MspInit 0 */

  /* USER CODE END LTDC_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_LTDC_CLK_ENABLE();
  
    /**LTDC GPIO Configuration    
    PE4     ------> LTDC_B0
    PJ13     ------> LTDC_B1
    PK7     ------> LTDC_DE
    PK6     ------> LTDC_B7
    PK5     ------> LTDC_B6
    PG12     ------> LTDC_B4
    PJ14     ------> LTDC_B2
    PI10     ------> LTDC_HSYNC
    PK4     ------> LTDC_B5
    PJ15     ------> LTDC_B3
    PI9     ------> LTDC_VSYNC
    PK1     ------> LTDC_G6
    PK2     ------> LTDC_G7
    PI15     ------> LTDC_R0
    PJ11     ------> LTDC_G4
    PK0     ------> LTDC_G5
    PI14     ------> LTDC_CLK
    PJ8     ------> LTDC_G1
    PJ10     ------> LTDC_G3
    PJ7     ------> LTDC_G0
    PJ9     ------> LTDC_G2
    PJ6     ------> LTDC_R7
    PJ4     ------> LTDC_R5
    PJ5     ------> LTDC_R6
    PJ3     ------> LTDC_R4
    PJ2     ------> LTDC_R3
    PJ0     ------> LTDC_R1
    PJ1     ------> LTDC_R2 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_4;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_11 
                          |GPIO_PIN_8|GPIO_PIN_10|GPIO_PIN_7|GPIO_PIN_9 
                          |GPIO_PIN_6|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_3 
                          |GPIO_PIN_2|GPIO_PIN_0|GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
    HAL_GPIO_Init(GPIOJ, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_6|GPIO_PIN_5|GPIO_PIN_4 
                          |GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
    HAL_GPIO_Init(GPIOK, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF9_LTDC;
    HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_9|GPIO_PIN_15|GPIO_PIN_14;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
    HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

  /* USER CODE BEGIN LTDC_MspInit 1 */

  /* USER CODE END LTDC_MspInit 1 */
  }
}

void HAL_LTDC_MspDeInit(LTDC_HandleTypeDef* ltdcHandle)
{

  if(ltdcHandle->Instance==LTDC)
  {
  /* USER CODE BEGIN LTDC_MspDeInit 0 */

  /* USER CODE END LTDC_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_LTDC_CLK_DISABLE();
  
    /**LTDC GPIO Configuration    
    PE4     ------> LTDC_B0
    PJ13     ------> LTDC_B1
    PK7     ------> LTDC_DE
    PK6     ------> LTDC_B7
    PK5     ------> LTDC_B6
    PG12     ------> LTDC_B4
    PJ14     ------> LTDC_B2
    PI10     ------> LTDC_HSYNC
    PK4     ------> LTDC_B5
    PJ15     ------> LTDC_B3
    PI9     ------> LTDC_VSYNC
    PK1     ------> LTDC_G6
    PK2     ------> LTDC_G7
    PI15     ------> LTDC_R0
    PJ11     ------> LTDC_G4
    PK0     ------> LTDC_G5
    PI14     ------> LTDC_CLK
    PJ8     ------> LTDC_G1
    PJ10     ------> LTDC_G3
    PJ7     ------> LTDC_G0
    PJ9     ------> LTDC_G2
    PJ6     ------> LTDC_R7
    PJ4     ------> LTDC_R5
    PJ5     ------> LTDC_R6
    PJ3     ------> LTDC_R4
    PJ2     ------> LTDC_R3
    PJ0     ------> LTDC_R1
    PJ1     ------> LTDC_R2 
    */
    HAL_GPIO_DeInit(GPIOE, GPIO_PIN_4);

    HAL_GPIO_DeInit(GPIOJ, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_11 
                          |GPIO_PIN_8|GPIO_PIN_10|GPIO_PIN_7|GPIO_PIN_9 
                          |GPIO_PIN_6|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_3 
                          |GPIO_PIN_2|GPIO_PIN_0|GPIO_PIN_1);

    HAL_GPIO_DeInit(GPIOK, GPIO_PIN_7|GPIO_PIN_6|GPIO_PIN_5|GPIO_PIN_4 
                          |GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_0);

    HAL_GPIO_DeInit(GPIOG, GPIO_PIN_12);

    HAL_GPIO_DeInit(GPIOI, GPIO_PIN_10|GPIO_PIN_9|GPIO_PIN_15|GPIO_PIN_14);

  }
  /* USER CODE BEGIN LTDC_MspDeInit 1 */

  /* USER CODE END LTDC_MspDeInit 1 */
} 

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
