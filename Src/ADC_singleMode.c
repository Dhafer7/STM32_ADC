/*
 * ADC_singleMode.c
 *
 *  Created on: Sep 10, 2023
 *      Author: DHAFER ABBES
 */

#include <stdint.h>
#include "ADC_singleMode.h"


void init_adc3_CH11()
{
	//Activate Bus clock for GPIOC
	*AHB1_ENR |= (1U<<2);
	/*Activate APB2 clock signal for ADC3*/
	*APB2_ENR|=(1U<<10);
	/*Configure PC1as analog input*/
	*GPIOC_MODE_R|=(1U<<2);
	*GPIOC_MODE_R|=(1U<<3);

}

void Configure_adc3_CH11()
{
/*Conversion sequence length*/
	*ADC3_SQR1 = 0;
/*Conversion sequence start*/
	*ADC3_SQR3 |= 0xB;
/*Enable ADC3*/
	*ADC3_CR2 = (1U<<0);
}

uint16_t ADC3_CH11_conversion()
{
/*Start conversion*/
	*ADC3_CR2 |= (1U<<30);
/*Wait till conversion is completed*/
	while(!((*ADC3_STATUS & (1U<<1)))) {}

return ((uint16_t)(*ADC3_DR));

}


