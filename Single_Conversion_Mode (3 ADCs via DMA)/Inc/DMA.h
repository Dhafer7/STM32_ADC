/*
 * DMA.h
 *
 *  Created on: Dec 26, 2023
 *      Author: DHAFER
 */

#include <stdint.h>
#include "stm32f407_reg.h"

#ifndef DMA_H_
#define DMA_H_

#define DMA2_EN 			(1U<<22)
#define DMA_STR_EN			(1U<<0)
#define DMA_STR1_CLF		(111101U<<6)
#define DMA_CH2				(1U<<26)
#define DMA_MEM_INC			(1U<<10)
#define DMA_DIRECT			(11U<<6)
#define DMA_NO_FIFO			(1U<<2)

#endif /* DMA_H_ */
