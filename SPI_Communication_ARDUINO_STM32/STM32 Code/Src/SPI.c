/*
 * SPI.c
 *
 *  Created on: Jan 8, 2024
 *      Author: DHAFER
 */
#include "spi.h"
#include "stm32f407_reg.h"
#include <stdint.h>

void init_SPI1()
{
	/*Clock access for GPIOA*/
	RCC->AHB1EN_R |= GPIOA_EN;
	/*Set GPIOA mode to Alternate Function*/
	//GPIOA_Pin 4 Mode
		GPIOA->MODE_R &= ~(1U<<8);
		GPIOA->MODE_R |= (1U<<9);
	//GPIOA_Pin 5 Mode
		GPIOA->MODE_R &= ~(1U<<10);
		GPIOA->MODE_R |= (1U<<11);
	//GPIOA_Pin 6 Mode
		GPIOA->MODE_R &= ~(1U<<12);
		GPIOA->MODE_R |= (1U<<13);
	//GPIOA_Pin 7 Mode
		GPIOA->MODE_R &= ~(1U<<14);
		GPIOA->MODE_R |= (1U<<15);
	/*Set GPIOA to AF5*/
	//Pin 4
		GPIOA->AF_RL |= (1<<16);
		GPIOA->AF_RL &= ~(1<<17);
		GPIOA->AF_RL |= (1<<18);
		GPIOA->AF_RL &= ~(1<<19);
	//Pin 5
		GPIOA->AF_RL |= (1<<20);
		GPIOA->AF_RL &= ~(1<<21);
		GPIOA->AF_RL |= (1<<22);
		GPIOA->AF_RL &= ~(1<<23);
	//Pin 6
		GPIOA->AF_RL |= (1<<24);
		GPIOA->AF_RL &= ~(1<<25);
		GPIOA->AF_RL |= (1<<26);
		GPIOA->AF_RL &= ~(1<<27);
	//Pin 7
		GPIOA->AF_RL |= (1<<28);
		GPIOA->AF_RL &= ~(1<<29);
		GPIOA->AF_RL |= (1<<30);
		GPIOA->AF_RL &= ~(1<<31);
}

void config_SPI()
{
	/*Clock access for SPI1*/
	RCC->APB2EN_R |= SPI1_EN;
	/*Disabled SPI1 */
	SPI1->SPI_CR1 &= ~SPI_ACTIVATE;
	/*Configure Baud rate to 16MHZ/256 */
	SPI1->SPI_CR1 |= (1U<<3);
	SPI1->SPI_CR1 |= (1U<<4);
	SPI1->SPI_CR1 |= (1U<<5);
	/*Configure Clock phase*/
	SPI1->SPI_CR1 |= SPI_CLK_PHASE;
	/*Configure Clock polarity*/
	SPI1->SPI_CR1 |= SPI_CLK_POL;
	/*Configure Receive only mode*/
	SPI1->SPI_CR1 |= SPI_REC_ONLY;
	/*Configure MSB first*/
	SPI1->SPI_CR1 &= SPI1_MSB_FIRST;
	/*Select 8 bit data mode*/
	SPI1->SPI_CR1 &= SPI1_DATA_FRAME_F;
	/*Select software slave management  */
	//SPI1->SPI_CR1 |= SPI1_SOFTW_SLAVE;
	//SPI1->SPI_CR1 |= SPI1_INTERNAL_SLAVE;
	/*Select slave mode*/
	SPI1->SPI_CR1 &= SPI1_SLAVE_SELECT;
	/*Enable SPI1*/
	SPI1->SPI_CR1 |= SPI_ACTIVATE;
}



void SPI1_receive(uint32_t* data, uint32_t size)
{
	uint32_t v_local;
	while(size)
	{
		/*send dummy data for synchronization */
		SPI1->SPI_DR = 0;

		/*Wait for RXNE flag to be set*/
		while(!(SPI1->SPI_SR & SPI1_SR_RXNE)){}

		/*read data from data register*/
		v_local=SPI1->SPI_DR;
		*data++=v_local;

		size--;
	}
}


