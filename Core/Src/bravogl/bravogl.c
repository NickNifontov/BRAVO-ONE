/*
 * bravogl.c
 *
 *  Created on: Mar 25, 2020
 *      Author: Nick Nifontov
 */

#include "bravogl.h"

// *** GLOBAL - BEGIN ***//
volatile enum BRAVO_STATE stateBRAVO=NOAC;
// *** GLOBAL - END ***//



// *** INIT - BEGIN *** //
void BRAVO_Init(void) {
	//HAL_TIM_Base_Start_IT(&htim6); // start LED Timer
}
// *** INIT - END *** //


// *** TIMER - UPDATE CALLBACK *** //
/*void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance==TIM6) {
		LED_SD_Callback();
	}
}*/

// *** LED TIM6 1 Sec - BEGIN *** //
void LED_SD_Callback(void) {
		switch (stateBRAVO) {
				case NOAC:
					LL_GPIO_ResetOutputPin(GPIOC, LED_SD_Pin);
					break;
				case AC:
					LL_GPIO_SetOutputPin(GPIOC, LED_SD_Pin);
					break;
				case SD:
					LL_GPIO_TogglePin(GPIOC, LED_SD_Pin);
					break;
			}
}
// *** LED TIM6 1 Sec - END *** //
