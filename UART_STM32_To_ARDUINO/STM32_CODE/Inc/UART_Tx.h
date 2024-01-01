/*
 * UART_Tx.h
 *
 *  Created on: Dec 29, 2023
 *      Author: DHAFER
 */

#ifndef UART_TX_H_
#define UART_TX_H_

/*Constant definition*/
#define UART_EN 		(1U<<17)
#define GPIOA_EN		(1U<<0)
/*
 * #define SYS_FREQ		    168000000
   #define APB1_SYSCLK		16000000
*/
#define UART_BAUDRT		0x683u //115200
#define CR1_TE			(1U<<3)
#define CR1_UE			(1U<<13)
#define SR_TXE			(1U<<7)
#define CR1_TXEIE		(1U<<7)


/*Function declaration*/
void uart2_tx_init(void);
void uart2_write(int ch);
void uart_print(char* str);

#endif /* UART_TX_H_ */
