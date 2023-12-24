/*
 * ADC_singleMode.h
 *
 *  Created on: Sep 10, 2023
 *      Author: DHAFER ABBES
 */


#ifndef ADC_SINGLEMODE_H_
#define ADC_SINGLEMODE_H_

#define		APB2_ENR			(uint32_t*)(0x40023844U)
#define		AHB1_ENR			(uint32_t*)(0x40023830U)
#define		GPIOC_MODE_R		(uint32_t*)(0x40020800U)
#define		ADC3_CR1				(uint32_t*)(0x40012204U)
#define		ADC3_CR2				(uint32_t*)(0x40012208U)
#define		ADC3_STATUS			(uint32_t*)(0x40012200U)
#define		ADC3_DR				(uint32_t*)(0x4001224CU)
#define 	ADC3_SQR1			(uint32_t*)(0x4001222CU)
#define		ADC3_SQR3			(uint32_t*)(0x40012234U)

void init_adc3_CH11();
uint16_t ADC3_CH11_conversion();
void Configure_adc3_CH11();

#endif /* ADC_SINGLEMODE_H_ */
