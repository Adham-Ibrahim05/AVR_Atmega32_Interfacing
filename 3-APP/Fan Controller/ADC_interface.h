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

void ADC_voidEnable(void);

void ADC_voidInterrputEnable(void);

void ADC_voidDisable(void);

u16 ADC_u16GetChannelReading(void);

void ADC_voidStartConversion(void);

void ADC_Channel(void);

//u8 ADC_u8ReadADC(pf addresscpy);

//void ADC_voidAutoTrigger();



#endif