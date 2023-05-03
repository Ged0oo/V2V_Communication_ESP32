/*
 * USART.h
 *
 *  Created on: 26 Sept 2022
 *      Author: Mahmoud Abdelmoniem
 */

#ifndef MCAL_USART_USART_H_
#define MCAL_USART_USART_H_

#include "avr/io.h"
#include "avr/interrupt.h"
#include "USART_config.h"
#include "../../Bit_math.h"
#include "../../std_types.h"




void UART_Init(void);

void UART_SendByte(uint8 data);
void UART_SendString(uint8* str);
uint8 UART_ReceiveByte(void);
uint8* UART_ReceiveString(void);
uint8 UART_Receive_NoBlock(uint8*pdata);





void UART_RX_InterruptEnable(void);
void UART_RX_InterruptDisable(void);

void UART_TX_InterruptEnable(void);
void UART_TX_InterruptDisable(void);

void UART_RX_SetCallBack(void (*LocalFptr)(void));
void UART_TX_SetCallBack(void (*LocalFptr)(void));


void UART_SendByteNoBlock(uint8 data);
uint8 UART_ReceiveByteNoBlock(void);





#endif /* MCAL_USART_USART_H_ */
