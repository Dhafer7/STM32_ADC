/*
 * ADC.c
 *      Author: DHAFER
 */

#include <stdint.h>
#include "stm32f407_reg.h"
#include "ADC.h"

/*Constant*/
const adc_config ADC_configurations[]=
{       {ADC_CH1,SEQ_LEN,(0U<<24),0x0,ADC_ON,0}, /*ADC1*/
		{ADC_CH2,SEQ_LEN,(0U<<24),0x0,ADC_ON,0}, /*ADC2*/
		{ADC_CH3,SEQ_LEN,(01U<<24),(1U<<11),ADC_ON,ADC_EN_DMA_Mode}  /*ADC3*/};

void init_ADC(void)
{
/*clock enable for GPIOA */
RCC->AHB1EN_R |= GPIOA_EN;
/*Clock enable for ADC1, ADC2, ADC3*/
RCC->APB2EN_R |= ADC1_EN;
RCC->APB2EN_R |= ADC2_EN;
RCC->APB2EN_R |= ADC3_EN;
/*Configure ADCs Analog inputs*/
/*Pin PA1*/
GPIOA->MODE_R |= (1U<<2);
GPIOA->MODE_R |= (1U<<3);
/*Pin PA2*/
GPIOA->MODE_R |= (1U<<4);
GPIOA->MODE_R |= (1U<<5);
/*Pin PA3*/
GPIOA->MODE_R |= (1U<<6);
GPIOA->MODE_R |= (1U<<7);

}

void configure_ADC(ADC_registers* adcx, adc_config adc_configs)
{
	/*Configuring conversion sequence*/
	adcx->SQR3 |= adc_configs.Cfg_SQR_3;
	/*Sequences length */
	adcx->SQR1 = adc_configs.Cfg_SQR_1;
	/*Select resolution*/
	adcx->CR1 = adc_configs.Cfg_CR_1;
	/*Data alignment*/
	adcx->CR2 = adc_configs.Cfg_CR2_align;
	/*Enable ADC*/
	adcx->CR2 |= adc_configs.Cfg_CR_2;
	/*Enable ADC3 transmitter DMA*/  //stream1 ch2 dma2
	adcx->CR2 |= adc_configs.Cfg_CR_2_DMA;

}

uint32_t Get_ADC_Value(ADC_registers* v_adc)
{
	uint32_t v_result=0;

	/*START conversion*/
	v_adc->CR2 |= ADC_STRTCONV;
	/*Wait till conversion is completed and return the value*/
	while(!(v_adc->SR & ADC_EOC)){}
	v_result= (uint32_t) (v_adc->DR);
	//v_adc->SR &= ~ADC_EOC;
	return(v_result);

}
