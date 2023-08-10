/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	MCAL			***************/
/***************	SWC: 	SPI				***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_voidMasterInit(void);

void SPI_voidSlaveInit(void);

u8 SPI_u8Transmit_RecieveSynch(u8 Copy_Data);

u8 SPI_u8ReadAsynchData(u8* data,u8 buffer_size,void (*pf)(void));

u8 SPI_u8SendAsynchData(u8* Copy_Data,u8 buffer_size);

#endif