/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	MCAL			***************/
/***************	SWC: 	ADC				***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/
#ifndef _ADC_INTERFACE_H
#define _ADC_INTERFACE_H


void ADC_voidInit (void);

void ADC_voidEnable();

void ADC_voidInterrputEnable();

void ADC_voidDisable();

u16 ADC_u16GetChannelReading();

void ADC_voidStartConversion();

void ADC_SelectChannel(u8 Channel);

//u8 ADC_u8ReadADC(pf addresscpy);

//void ADC_voidAutoTrigger();



#endif