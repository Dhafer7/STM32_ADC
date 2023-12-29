#include "stm32f407_reg.h"
#include <stdint.h>
#include "ADC.h"
#include "DMA.h"


#define LED_ORANGE			13
#define LED_GREEN			12
#define LED_RED				14
#define LED_BLUE			15

int main()
{
	uint32_t ADC1_value=0;
	uint32_t ADC2_value=0;
	uint32_t ADC3_value=0;

	init_ADC();
	configure_ADC(ADC1,ADC_configurations[0]);
	configure_ADC(ADC2,ADC_configurations[1]);
	configure_ADC(ADC3,ADC_configurations[2]);
	DMA_init( (uint32_t)ADC3->DR, ADC3_value, sizeof(ADC3_value));



		//Activate Bus clock for GPIOD
    	RCC->AHB1EN_R |= (1U<<3);
		//Configure GPIOD_12 as OUTPUT
		GPIOD->MODE_R &= ~(1U<<25);
		GPIOD->MODE_R |= (1U<<24);
		//Configure GPIOD_13 as OUTPUT
		GPIOD->MODE_R &= ~(1U<<27);
		GPIOD->MODE_R |= (1U<<26);
		//Configure GPIOD_14 as OUTPUT
		GPIOD->MODE_R &= ~(1U<<29);
		GPIOD->MODE_R |= (1U<<28);
		//Configure GPIOD_15 as OUTPUT
		GPIOD->MODE_R &= ~(1U<<31);
		GPIOD->MODE_R |= (1U<<30);

		GPIOD->ODR |= (1U<<LED_ORANGE);
		GPIOD->ODR |= (1U<<LED_GREEN);
		GPIOD->ODR |= (1U<<LED_RED);
		GPIOD->ODR |= (1U<<LED_BLUE);

		int i=0;
		while(i<10000){i++;}

		GPIOD->ODR &= ~(1U<<LED_ORANGE);
		GPIOD->ODR &= ~(1U<<LED_GREEN);
		GPIOD->ODR &= ~(1U<<LED_RED);
		GPIOD->ODR &= ~(1U<<LED_BLUE);

		i=0;
		while(i<10000){i++;}

		while(1)
		{
			ADC1_value=Get_ADC_Value(ADC1);
			ADC2_value=Get_ADC_Value(ADC2);
			ADC3_value=Get_ADC_Value(ADC3);

			if(ADC1_value < 1000)
			{
				GPIOD->ODR |= (1U<<LED_ORANGE);

			}else
			{
				GPIOD->ODR &= ~(1U<<LED_ORANGE);
			}
			if(ADC2_value >= 1000)
			{
				GPIOD->ODR |= (1U<<LED_GREEN);
			}else
			{
				GPIOD->ODR &= ~(1U<<LED_GREEN);
			}
			if(ADC3_value >= 1000)
			{
				GPIOD->ODR |= (1U<<LED_RED);
			}else
			{
				GPIOD->ODR &= ~(1U<<LED_RED);
			}




		}

}

