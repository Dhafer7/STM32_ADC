/*
 * ADC.h
 *      Author: DHAFER
 */
#include <stdint.h>
#include "stm32f407_reg.h"


#ifndef ADC_H_
#define ADC_H_

/*Global Definitions*/
#define ADC1_EN  		 (1U<<8)
#define ADC2_EN  		 (1U<<9)
#define ADC3_EN  		 (1U<<10)
#define GPIOC_EN 		 (1U<<2)
#define GPIOA_EN 		 (1U<<0)
#define ADC_CH1   	     (0x1U)
#define ADC_CH2    		 (0x2U)
#define ADC_CH3  	     (0x3U)
#define SEQ_LEN			 (0x0U) /*1*/
#define ADC_ON	 		 (1U<<0)
#define ADC_EOC			 (1U<<1)
#define ADC_STRTCONV	 (1U<<30)
#define ADC_EN_DMA_Mode	 (11U<<8)
#define	ADC1			 ((ADC_registers*)(0x40012000U))
#define	ADC2			 ((ADC_registers*)(0x40012100U))
#define	ADC3			 ((ADC_registers*)(0x40012200U))
#define	ADC123			 ((ADC_registers*)(0x40012300U))

/*Type definitions*/
typedef struct config{

		uint32_t Cfg_SQR_3;       /*Configuring conversion sequence*/
		uint32_t Cfg_SQR_1;    	  /*Configuring sequences length*/
		uint32_t Cfg_CR_1;        /*Configuring resolution*/
		uint32_t Cfg_CR2_align;   /*Configuring alignement (default 0/ right)*/
		uint32_t Cfg_CR_2;        /*Configuring ADC Enable*/
		uint32_t Cfg_CR_2_DMA;	  /*Configuing DMA Enable*/
}adc_config;

/*Constants*/
extern const adc_config ADC_configurations[];

/*Function prototypes*/
void init_ADC(void);
void configure_ADC(ADC_registers* adcx, adc_config adc_configs);
uint32_t Get_ADC_Value(ADC_registers* v_adc);

#endif
