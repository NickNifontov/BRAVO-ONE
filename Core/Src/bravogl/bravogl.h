/*
 * bravogl.h
 *
 *  Created on: Mar 25, 2020
 *      Author: Nick Nifontov
 */

#ifndef SRC_BRAVOGL_BRAVOGL_H_
#define SRC_BRAVOGL_BRAVOGL_H_

#include "bravogl_def.h"

#include "main.h"
#include "adc.h"
#include "comp.h"
#include "dac.h"
#include "dma.h"
#include "hrtim.h"
#include "iwdg.h"
#include "tim.h"
#include "gpio.h"

// *** GLOBAL ***//
extern volatile enum BRAVO_STATE stateBRAVO;

// *** INIT *** //
void BRAVO_Init(void);

// *** LED *** //
void LED_SD_Callback(void);

#endif /* SRC_BRAVOGL_BRAVOGL_H_ */
