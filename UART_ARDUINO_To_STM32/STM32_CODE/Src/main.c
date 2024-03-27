/*@brief: 	UART communication between Arduino UNO and STM32F409, sending from STM32
 * and UART blinks LED when message is received
 *@Author: 	Dhafer Abbes
 *@Creation date: 04/09/2023
 * */


#include "STM32F407_reg.h"
#include <stdint.h>
#include "UART_Rx.h"

#define LED_ORANGE			13

char message;





int main(void)
{
	//Activate Bus clock for GPIOD
	RCC->AHB1EN_R |= (1U<<3);
	//Configure GPIOD_12 as OUTPUT
	GPIOD->MODE_R &= ~(1U<<27);
	GPIOD->MODE_R |= (1U<<26);

	//Initialize UART2
	uart2_rx_init();

	while(1)
	{
		message = uart2_receive_oneByte();

		if(message == '1')
			{
				GPIOD->ODR |= (1U<<LED_ORANGE);
			}
		else {
			GPIOD->ODR &= ~(1U<<LED_ORANGE);
		}
	}
}




