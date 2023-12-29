/*
 * stm32f407_reg.h
 *      Author: DHAFER
 */

/******Includes******/
#include <stdint.h>


#ifndef STM32F407_REG_H_
#define STM32F407_REG_H_

/******Structures******/
typedef struct{
	uint32_t CR;
	uint32_t unused1[11];
	uint32_t AHB1EN_R;
	uint32_t AHB2EN_R;
	uint32_t AHB3EN_R;
	uint32_t unused2;
	uint32_t APB1EN_R;
	uint32_t APB2EN_R;
} RCC_Registers;

typedef struct{
	uint32_t MODE_R;
	uint32_t OTYPE_R;
	uint32_t OSPEED_R;
	uint32_t PUPD_R;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRS;
	uint32_t unuesed3;
	uint32_t AF_RL;
	uint32_t AF_RH;
} GPIO_registers;

typedef struct{
	uint32_t SR;
	uint32_t CR1;
	uint32_t CR2;
	uint32_t unused1[8];
	uint32_t SQR1;
	uint32_t SQR2;
	uint32_t SQR3;
	uint32_t unused2[5];
	uint32_t DR;
} ADC_registers;

typedef struct{
	uint32_t DMA_LISR;
	uint32_t DMA_HISR;
	uint32_t DMA_LIFCR;
	uint32_t DMA_HIFCR;
	uint32_t DMA_CR;
	uint32_t DMA_NDTR;
	uint32_t DMA_PAR;
	uint32_t DMA_M0AR;
	uint32_t DMA_M1AR;
	uint32_t DMA_FCR;
}DMA_registers_1STR;

typedef struct{
	DMA_registers_1STR Stream[8];
}DMA_registers_ALL_STR;

/******GV Definitions******/
#define  RCC 	 ((RCC_Registers*)(0x40023800U))
#define  GPIOA	 ((GPIO_registers*)(0x40020000U))
#define  GPIOB	 ((GPIO_registers*)(0x40020400U))
#define  GPIOC	 ((GPIO_registers*)(0x40020800U))
#define  GPIOD	 ((GPIO_registers*)(0x40020C00U))
#define  GPIOE	 ((GPIO_registers*)(0x40021000U))
#define  GPIOF	 ((GPIO_registers*)(0x40021400U))
#define  GPIOG	 ((GPIO_registers*)(0x40021800U))
#define  GPIOH	 ((GPIO_registers*)(0x40021C00U))
#define  GPIOI	 ((GPIO_registers*)(0x40022000U))
#define  DMA1	 ((DMA_registers_ALL_STR*)(0x40026000))
#define  DMA2	 ((DMA_registers_ALL_STR*)(0x40026400U))


#endif


