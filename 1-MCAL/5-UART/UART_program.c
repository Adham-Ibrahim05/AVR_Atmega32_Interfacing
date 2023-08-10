/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	MCAL			***************/
/***************	SWC: 	UART			***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h" 
#include "UART_register.h"

 u8* G_Data;
void(*INT_pf)(u8) = NULL;

void UART_Init( )
{
	/*Choose UCSRC Register*/
	SET_BIT(UCSRC,UCSRC_URSEL);
	
	/*Asynchronous Mood*/
	CLR_BIT(UCSRC,UCSRC_UMSEL);
	
	/*NO Parity*/
	CLR_BIT(UCSRC,UCSRC_UPM0);
	CLR_BIT(UCSRC,UCSRC_UPM1);
	
	/*Set Baud Rate =9600*/
	u16 Local_BaudRate = 51;//for 8MHZ
	UBRRH = (u8)(Local_BaudRate>>8);
	UBRRL = (u8)Local_BaudRate;
	
	/*Enable Transmitter*/
	SET_BIT(UCSRB,UCSRB_TXEN);
	
	/*Enable Receiver*/
	SET_BIT(UCSRB,UCSRB_RXEN);
	
	/*Data Frame 8bits*/
	SET_BIT(UCSRC,UCSRC_UCSZ0);
	SET_BIT(UCSRC,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
	
	/*1bit Stop*/
	CLR_BIT(UCSRC,UCSRC_USBS);
}


void UART_SynchTransmit( u8 data )
{
	/*Wait Until TX REG Is Empty*/
	while(GET_BIT(UCSRA,UCSRA_UDRE) == NULL);
	/*Send Data Byte*/
	UDR = data;
}


u8 UART_SynchReceive( )
{
	u8 Receive_Data;
	/*Wait Until The Data Is Received*/
	while(GET_BIT(UCSRA,UCSRA_RXC) == NULL);
	/*Read Data*/
	 Receive_Data = UDR;
	 return Receive_Data;
}

void UART_voidASynchSendString( u8* Data)
{
	G_Data = Data;
	/*Enable Tx Interrupt*/
	SET_BIT(UCSRB,UCSRB_TXCIE);
	/*Send First Character*/
	UDR = G_Data[0];
}

u8 UART_voidASynchRecieve(void (*ptr)(u8))
{
	INT_pf = ptr;
	/*Enable RX Interrupt*/
	SET_BIT(UCSRB,UCSRB_RXCIE);
}

/*For Transmit*/
void __vector_15(void) __attribute__((signal));
void __vector_15(void)
{
	static u8 counter=1;
	if(G_Data[counter]!='\0')
	{
		UDR = G_Data[counter];
		counter++;
	}
	else
	{
		UDR ='\0';
	}	
		
}

void UART_VoidSetCallBack(void (*Copy_pf) (u8))
{
	INT_pf = Copy_pf;
}

/*For Receive*/
void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	INT_pf(UDR);
	
}