/**
  ******************************************************************************
  * File Name          : DAC.c
  * Description        : This file provides code for the configuration
  *                      of the DAC instances.
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

/* Includes ------------------------------------------------------------------*/
#include "dac.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* DAC1 init function */
void MX_DAC1_Init(void)
{
  LL_DAC_InitTypeDef DAC_InitStruct = {0};

  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* Peripheral clock enable */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_DAC1);
  
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
  /**DAC1 GPIO Configuration  
  PA4   ------> DAC1_OUT1 
  */
  GPIO_InitStruct.Pin = DAC_V_Pin;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(DAC_V_GPIO_Port, &GPIO_InitStruct);

  /* DAC1 DMA Init */
  
  /* DAC1_CH1 Init */
  LL_DMA_SetDataTransferDirection(DMA1, LL_DMA_CHANNEL_3, LL_DMA_DIRECTION_MEMORY_TO_PERIPH);

  LL_DMA_SetChannelPriorityLevel(DMA1, LL_DMA_CHANNEL_3, LL_DMA_PRIORITY_VERYHIGH);

  LL_DMA_SetMode(DMA1, LL_DMA_CHANNEL_3, LL_DMA_MODE_CIRCULAR);

  LL_DMA_SetPeriphIncMode(DMA1, LL_DMA_CHANNEL_3, LL_DMA_PERIPH_NOINCREMENT);

  LL_DMA_SetMemoryIncMode(DMA1, LL_DMA_CHANNEL_3, LL_DMA_MEMORY_INCREMENT);

  LL_DMA_SetPeriphSize(DMA1, LL_DMA_CHANNEL_3, LL_DMA_PDATAALIGN_HALFWORD);

  LL_DMA_SetMemorySize(DMA1, LL_DMA_CHANNEL_3, LL_DMA_MDATAALIGN_HALFWORD);

  LL_SYSCFG_SetRemapDMA_DAC(LL_SYSCFG_DAC1_CH1_RMP_DMA1_CH3);

  /* DAC1 interrupt Init */
  NVIC_SetPriority(TIM6_DAC1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),3, 0));
  NVIC_EnableIRQ(TIM6_DAC1_IRQn);

  /** DAC channel OUT1 config 
  */
  DAC_InitStruct.TriggerSource = LL_DAC_TRIGGER_HRTIM1_DACTRG1;
  DAC_InitStruct.WaveAutoGeneration = LL_DAC_WAVE_AUTO_GENERATION_TRIANGLE;
  DAC_InitStruct.WaveAutoGenerationConfig = LL_DAC_TRIANGLE_AMPLITUDE_4095;
  DAC_InitStruct.OutputBuffer = LL_DAC_OUTPUT_BUFFER_ENABLE;
  LL_DAC_Init(DAC1, LL_DAC_CHANNEL_1, &DAC_InitStruct);
  LL_SYSCFG_SetRemapTrigger_DAC(LL_SYSCFG_DAC1_TRIG3_RMP_HRTIM1_DAC1_TRIG1);
  LL_DAC_EnableTrigger(DAC1, LL_DAC_CHANNEL_1);

}
/* DAC2 init function */
void MX_DAC2_Init(void)
{
  LL_DAC_InitTypeDef DAC_InitStruct = {0};

  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* Peripheral clock enable */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_DAC2);
  
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
  /**DAC2 GPIO Configuration  
  PA6   ------> DAC2_OUT1 
  */
  GPIO_InitStruct.Pin = DAC_I_Pin;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(DAC_I_GPIO_Port, &GPIO_InitStruct);

  /* DAC2 DMA Init */
  
  /* DAC2_CH1 Init */
  LL_DMA_SetDataTransferDirection(DMA1, LL_DMA_CHANNEL_5, LL_DMA_DIRECTION_MEMORY_TO_PERIPH);

  LL_DMA_SetChannelPriorityLevel(DMA1, LL_DMA_CHANNEL_5, LL_DMA_PRIORITY_HIGH);

  LL_DMA_SetMode(DMA1, LL_DMA_CHANNEL_5, LL_DMA_MODE_CIRCULAR);

  LL_DMA_SetPeriphIncMode(DMA1, LL_DMA_CHANNEL_5, LL_DMA_PERIPH_NOINCREMENT);

  LL_DMA_SetMemoryIncMode(DMA1, LL_DMA_CHANNEL_5, LL_DMA_MEMORY_INCREMENT);

  LL_DMA_SetPeriphSize(DMA1, LL_DMA_CHANNEL_5, LL_DMA_PDATAALIGN_HALFWORD);

  LL_DMA_SetMemorySize(DMA1, LL_DMA_CHANNEL_5, LL_DMA_MDATAALIGN_HALFWORD);

  LL_SYSCFG_SetRemapDMA_DAC(LL_SYSCFG_DAC2_CH1_RMP_DMA1_CH5);

  /* DAC2 interrupt Init */
  NVIC_SetPriority(TIM7_DAC2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),3, 0));
  NVIC_EnableIRQ(TIM7_DAC2_IRQn);

  /** DAC channel OUT1 config 
  */
  DAC_InitStruct.TriggerSource = LL_DAC_TRIGGER_HRTIM1_DACTRG3;
  DAC_InitStruct.WaveAutoGeneration = LL_DAC_WAVE_AUTO_GENERATION_NONE;
  DAC_InitStruct.OutputBuffer = LL_DAC_OUTPUT_SWITCH_ENABLE;
  LL_DAC_Init(DAC2, LL_DAC_CHANNEL_1, &DAC_InitStruct);
  LL_DAC_EnableTrigger(DAC2, LL_DAC_CHANNEL_1);

}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
