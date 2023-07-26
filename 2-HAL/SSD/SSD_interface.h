/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	HAL				***************/
/***************	SWC: 	SSD			***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/
#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H
void SSD_Init();
/*void SSD_u8DisplayOn(u8 SSD_ID,u8 Number);*/
void SSD_voidDisplayOff(u8 SSD_ID);
void SSD_voidDisplayNumbers(u16 Number);

#endif