/*
 * DMA.c
 *
 *  Created on: Dec 26, 2023
 *      Author: DHAFER
 */

#include <stdint.h>
#include "stm32f407_reg.h"
#include "DMA.h"

void DMA_init(uint32_t src, uint32_t dst, uint32_t len)
{
/*Enable clock access to DMA2*/
RCC->AHB1EN_R |= DMA2_EN;
/*Disable DMA2 STREAM1*/
DMA2->Stream[1].DMA_CR &= ~DMA_STR_EN;
/*Clear all interrupt flags of STREAMy*/
DMA2->Stream[1].DMA_LIFCR |= DMA_STR1_CLF;
/*Set source buffer*/
DMA2->Stream[1].DMA_PAR = src;
/*Set destinaion buffer*/
DMA2->Stream[1].DMA_M0AR = dst;
/*Set length*/
DMA2->Stream[1].DMA_NDTR = len;
/*Select STREAM1 CH2*/
DMA2->Stream[1].DMA_CR |= DMA_CH2;
/*Enable memory incrementation*/
DMA2->Stream[1].DMA_CR |= DMA_MEM_INC;
/*Configure transfer direction*/
DMA2->Stream[1].DMA_CR &= ~DMA_DIRECT;
/*Enable direct mode and disable FIFO*/
DMA2->Stream[1].DMA_FCR &= ~DMA_NO_FIFO;
/*Enable DMAx STREAMy*/
DMA2->Stream[1].DMA_CR |= DMA_STR_EN;
}
