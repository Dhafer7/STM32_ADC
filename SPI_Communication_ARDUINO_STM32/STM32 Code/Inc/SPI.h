/*
 * SPI.h
 *
 *  Created on: Jan 8, 2024
 *      Author: DHAFER
 */
#include <stdint.h>

#ifndef SPI_H_
#define SPI_H_

void init_SPI1(void);
void config_SPI(void);
void SPI1_receive(uint32_t *data, uint32_t size);
void cs_enable(void);
void cs_disable(void);

#define GPIOA_EN			(1U<<0)
#define SPI1_EN				(1U<<12)
#define SPI_ACTIVATE		(1U<<6)
#define SPI_CLK_PHASE		(1U<<0)
#define SPI_CLK_POL			(1U<<1)
#define SPI_REC_ONLY		(1U<<10)
#define SPI1_MSB_FIRST		~(1U<<7)
#define SPI1_DATA_FRAME_F	~(1U<<11)
#define SPI1_SOFTW_SLAVE	(1U<<9)
#define SPI1_INTERNAL_SLAVE	(1U<<8)
#define SPI1_SLAVE_SELECT	~(1U<<2)
#define SPI1_SR_TXE			(1U<<1)
#define SPI1_SR_BSY			(1U<<7)
#define SPI1_SR_RXNE		(1U<<0)


#endif /* SPI_H_ */
