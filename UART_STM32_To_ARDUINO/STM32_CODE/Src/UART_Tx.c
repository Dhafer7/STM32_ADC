/*
 * UART_Tx.c
 *
 *  Created on: Dec 29, 2023
 *      Author: DHAFER
 */

#include "STM32F407_reg.h"
#include "UART_Tx.h"


void uart2_tx_init(void)
{
	/*****************Configure UART GPIO pin**********************/
	/*Enable clock access to GPIOD*/
	RCC->AHB1EN_R |=  GPIOA_EN;
	/*set PA2 to AF mode*/
	GPIOA->MODE_R &= ~(1U<<4);
	GPIOA->MODE_R |= (1U<<5);
	/*Set PA2 to AF type to UART_TX(AF07) */
	GPIOA->AF_RL|= (1U<<8);
	GPIOA->AF_RL |= (1U<<9);
	GPIOA->AF_RL |= (1U<<10);
	GPIOA->AF_RL &= ~(1U<<11);

	/*****************Configure UART module**********************/
	/*Enable clock access to uart2*/
	RCC->APB1EN_R |= UART_EN;
	/*configure UART Baudrate*/
	UART2->USART_BRR = UART_BAUDRT;
	/*Configure the transfer direction*/
	UART2->USART_CR1 = CR1_TE;

	/*Enable TXNE interrupt*/
	UART2->USART_CR1 |= CR1_TXEIE;
	/*Enable USART2 interrupt in NVIC (using pm0214 document)*/
	*NVIC_ISER1 = (1U<<6);
	/*Enable UART module*/
	UART2->USART_CR1 |= CR1_UE;
}

void uart2_write(int ch)
{
	/*make sure transmit data register is empty*/
	while(!(UART2->USART_SR &  SR_TXE)) {}
	/*write to transmit data register*/
	UART2->USART_DR = ch ;
}

void uart_print(char* str)
{
	int i=0;
	while (*(str+i) != '\0')
	{
	uart2_write(*(str+i) & 0xFFU);
	i++;

	}
}
