/*@brief: 	UART communication between Arduino UNO and STM32F409, sending from STM32
 * and UART blinks LED when message is received
 *@Author: 	Dhafer Abbes
 *@Creation date: 04/09/2023
 * */


#include "STM32F407_reg.h"
#include <stdint.h>
#include "spi.h"


#define GPIOB_EN			(1U<<1)


int main(void)
{
	uint32_t * received_data;
	uint32_t spi_data_adress;

	/*Initialize SPI1*/
	 init_SPI1();
	 config_SPI();


	//Activate Bus clock for GPIOD
	RCC->AHB1EN_R |= (1U<<3);
	//Configure GPIOD_12 as OUTPUT
	GPIOD->MODE_R &= ~(1U<<27);
	GPIOD->MODE_R |= (1U<<26);

	//Initialize receiver pointer
	received_data= &spi_data_adress;


while(1)
{
	SPI1_receive(received_data,1);

	if(*received_data == (uint32_t)('B'))
	{
		GPIOD->ODR |= (1U<<13);
		for(int i=0;i<10000;i++){}
		GPIOD->ODR &= ~(1U<<13);
	}
}


}







