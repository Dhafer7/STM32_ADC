/*@brief: 	ADC conversion
 *@Author: 	Dhafer Abbes
 *@Creation date: 10/09/2023
 * */



#include <stdint.h>
#include "ADC_singleMode.h"

#define LED_ORANGE			13
#define LED_GREEN			12
#define LED_RED				14
#define LED_BLUE			15
#define GPIOD_MODE_R		(uint32_t*)(0x40020C00U)
#define GPIOD_OD_R			(uint32_t*)(0x40020C14U)


int main(void)
{
	uint16_t	data=0;

	//Activate Bus clock for GPIOD
	*AHB1_ENR |= (1U<<3);
	//Configure GPIOD_12 as OUTPUT
	*GPIOD_MODE_R &= ~(1U<<25);
	*GPIOD_MODE_R |= (1U<<24);
	//Configure GPIOD_13 as OUTPUT
	*GPIOD_MODE_R &= ~(1U<<27);
	*GPIOD_MODE_R |= (1U<<26);
	//Configure GPIOD_14 as OUTPUT
	*GPIOD_MODE_R &= ~(1U<<29);
	*GPIOD_MODE_R |= (1U<<28);
	//Configure GPIOD_15 as OUTPUT
	*GPIOD_MODE_R &= ~(1U<<31);
	*GPIOD_MODE_R |= (1U<<30);


	init_adc3_CH11();
	Configure_adc3_CH11();

	while(1)
	{
		data=ADC3_CH11_conversion();
		if(data < 1023)
		{
			*GPIOD_OD_R |= (1U<<LED_ORANGE);
			*GPIOD_OD_R &= ~(1U<<LED_GREEN);
			*GPIOD_OD_R &= ~(1U<<LED_RED);
			*GPIOD_OD_R &= ~(1U<<LED_BLUE);
		} else if((data >= 1032)&&(data < 2046))
		{
			*GPIOD_OD_R |= (1U<<LED_ORANGE);
			*GPIOD_OD_R |= (1U<<LED_GREEN);
			*GPIOD_OD_R &= ~(1U<<LED_RED);
			*GPIOD_OD_R &= ~(1U<<LED_BLUE);
		}else if((data >= 2046)&&(data < 3078))
		{
			*GPIOD_OD_R |= (1U<<LED_ORANGE);
			*GPIOD_OD_R |= (1U<<LED_GREEN);
			*GPIOD_OD_R |= (1U<<LED_RED);
			*GPIOD_OD_R &= ~(1U<<LED_BLUE);
		}else if((data >= 3078)&&(data < 4095))
		{
			*GPIOD_OD_R |= (1U<<LED_ORANGE);
			*GPIOD_OD_R |= (1U<<LED_GREEN);
			*GPIOD_OD_R |= (1U<<LED_RED);
			*GPIOD_OD_R |= (1U<<LED_BLUE);
		}else
		{
			*GPIOD_OD_R &= ~(1U<<LED_ORANGE);
			*GPIOD_OD_R &= ~(1U<<LED_GREEN);
			*GPIOD_OD_R &= ~(1U<<LED_RED);
			*GPIOD_OD_R &= ~(1U<<LED_BLUE);
		}



	}
}



