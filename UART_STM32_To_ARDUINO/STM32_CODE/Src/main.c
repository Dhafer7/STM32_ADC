/*@brief: 	UART communication between Arduino UNO and STM32F409, sending from STM32
 * and UART blinks LED when message is received
 *@Author: 	Dhafer Abbes
 *@Creation date: 04/09/2023
 * */


#include "STM32F407_reg.h"
#include <stdint.h>
#include "UART_Tx.h"



int i=0;
char* str;
char ch;




int main(void)
{

	uart2_tx_init();


	while(1)
	{
		uart_print("My name is Dhafer B ");
		for(int w=0;w<1000000;w++){}
	}
}





static void uart_callback(void)
{
		ch=(*(str+i) & 0xFFU);
		if (*(str+i) != '\0') {i++;}
		else {i=0;}

	/*write to transmit data register*/
	UART2->USART_DR = ch ;
}
void USART2_IRQHandler(void)
{
	/*Check if TXNE is set*/
	if(UART2->USART_SR &  SR_TXE)
	{
		/*do something*/
		uart_callback();
	}
}
