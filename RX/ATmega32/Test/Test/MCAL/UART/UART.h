#ifndef UART_H_
#define UART_H_



/*					section includes					*/

#include "../DIO/DIO.h"

/*					section: macro declaration					*/

#define  SPEED_MODE					NORMAL_SPEED
#define  CPU_F						_8_MHZ
#define  BUAD_RATE					BAUD_9600
#define  SYNCH_MODE					ASYNCH
#define  PARITY_MODE				NO_PARITY
#define  N_DATA_BITS				_8_DATA_BITS
#define  N_STOP_BITS				ONE_STOP_BIT

#define NORMAL_SPEED				0
#define DOUBLE_SPEED				1
#define TOTAL_SPEED_MODE			2

#define   _4_MHZ					0
#define   _8_MHZ					1
#define  _16_MHZ					2
#define  TOTAL_CPU_F				3

#define  BAUD_2400					0
#define  BAUD_4800					1
#define  BAUD_9600					2
#define  BAUD_14400					3
#define  BAUD_19200					4
#define  BAUD_28800					5
#define  TOTAL_BAUD_RATE			6

#define NO_PARITY					0
#define EVEN_PARITY					1
#define ODD_PARITY					2

#define  _5_DATA_BITS				5
#define  _6_DATA_BITS				6
#define  _7_DATA_BITS				7
#define  _8_DATA_BITS				8
#define  _9_DATA_BITS				9


#define  SYNCH						0
#define  ASYNCH						1

#define  ONE_STOP_BIT				1
#define  TWO_STOP_BIT				2


/*					section: macro function declaration					*/




/*					section: data type declaration					*/



/*					section:function declaration					*/

void UART_Init(void);

void  UART_SendByte(uint8 data);
uint8 UART_ReceiveByte(void);
void UART_Receive_NoBlock(uint8*pdata);

void UART_RX_InterruptEnable(void);
void UART_RX_InterruptDisable(void);

void UART_TX_InterruptEnable(void);
void UART_TX_InterruptDisable(void);

void UART_RX_SetCallBack(void (*LocalFptr)(void));
void UART_TX_SetCallBack(void (*LocalFptr)(void));

void UART_SendByteNoBlock(uint8 data);
uint8 UART_ReceiveByteNoBlock(void);

void UART_voidSendString(uint8  *Copy_pu8String);


#endif /* UART_H_ */