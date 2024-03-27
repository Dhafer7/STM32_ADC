/*
 * UART_Tx.c
 *
 *  Created on: Dec 29, 2023
 *      Author: DHAFER
 */

#include "STM32F407_reg.h"
#include "UART_Rx.h"


void uart2_rx_init(void)
{
	/*****************Configure UART GPIO pin**********************/
	/*Enable clock access to GPIOA*/
	RCC->AHB1EN_R |=  GPIOA_EN;
	/*set PA3 to AF mode*/
	GPIOA->MODE_R &= ~(1U<<6);
	GPIOA->MODE_R |= (1U<<7);
	/*Set PA3 to AF type to UART_RX(AF07) */
	GPIOA->AF_RL|= (1U<<12);
	GPIOA->AF_RL |= (1U<<13);
	GPIOA->AF_RL |= (1U<<14);
	GPIOA->AF_RL &= ~(1U<<15);

	/*****************Configure UART module**********************/
	/*Enable clock access to uart2*/
	RCC->APB1EN_R |= UART_EN;
	/*configure UART Baudrate*/
	UART2->USART_BRR = UART_BAUDRT;
	/*Configure the transfer direction*/
	UART2->USART_CR1 = CR1_RE;

	/*Enable UART module*/
	UART2->USART_CR1 |= CR1_UE;
}

char uart2_receive_oneByte(void)
{
	/*make sure transmit data register is not empty*/
	while(!(UART2->USART_SR &  SR_RXNE)) {}
	/*read from transmit data register*/
	return(UART2->USART_DR) ;
}


