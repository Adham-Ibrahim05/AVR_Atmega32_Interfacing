/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	MCAL			***************/
/***************	SWC: 	UART			***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_Init( );

void UART_SynchTransmit( u8 data );

u8 UART_SynchReceive( );

void UART_voidASynchSendString(u8* Data);

u8 UART_voidASynchRecieve(void (*ptr)(u8));

void UART_VoidSetCallBack(void (*Copy_pf) (u8));

#endif	