/*
 * UART_Tx.h
 *
 *  Created on: Dec 29, 2023
 *      Author: DHAFER
 */

#ifndef UART_RX_H_
#define UART_RX_H_

/*Constant definition*/
#define UART_EN 		(1U<<17)
#define GPIOA_EN		(1U<<0)
/*
 * #define SYS_FREQ		    168000000
   #define APB1_SYSCLK		16000000
*/
#define UART_BAUDRT		0x683u //115200
#define CR1_RE			(1U<<2)
#define CR1_UE			(1U<<13)
#define SR_RXNE			(1U<<5)
#define CR1_RXNEIE		(1U<<5)




/*Function declaration*/
void uart2_rx_init(void);
char uart2_receive_oneByte(void);
void uart_read_Words(char* message_received, char One_byte);
#endif /* UART_RX_H_ */
