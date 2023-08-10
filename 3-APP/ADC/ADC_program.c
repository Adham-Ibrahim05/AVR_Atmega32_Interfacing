/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	MCAL			***************/
/***************	SWC: 	ADC				***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_register.h"

void ADC_voidInit (void)
{
	/*Select Voltage reference*/
	#if VOLTAGE_REFERENCE == AVCC
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	
	#elif VOLTAGE_REFERENCE == AREF
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	
	#elif VOLTAGE_REFERENCE == INTERNAL
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
	#endif
	
	/*Select Adjustment*/
	#if ADJUSTMENT == LEFT_ADJUSTMENT
	SET_BIT(ADMUX,ADMUX_ADLAR);
	
	#elif ADJUSTMENT == RIGHT_ADJUSTMENT
	CLR_BIT(ADMUX,ADMUX_ADLAR);
	
	#endif
	
	/*Select ADC PreScaler*/
	//Clear Prescaller bits in ADMUX Register//
	ADMUX &= ADC_PRESCALER_MASK;
	//Set required Prescaller in Prescaller bits//
	ADMUX |= ADC_PRESCALLER;
		
	/*Disable ADC Enable*/
	CLR_BIT(ADCSRA,ADCSRA_ADEN);
	
	/*Disable ADC Auto Trigger*/
	CLR_BIT(ADCSRA,ADCSRA_ADATE);
	
	/*Disable ADC Interrupt Flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);
	
	/*Disable ADC Interrupt Enable*/
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
	
}

void ADC_voidEnable()
{
	/*Enable ADC Enable*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

void ADC_voidDisable()
{
	CLR_BIT(ADCSRA,ADCSRA_ADEN);
}

void ADC_voidInterrputEnable()
{
	SET_BIT(ADCSRA,ADCSRA_ADIE);
}

u16 ADC_u16GetChannelReading()
{

	u16 value=0;
	ADC_voidStartConversion();
	/*Polling until the conversion is complete ,flag is set*/
	while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0);
	 
	value = ADC_Data;
	/*Clear ADC Interrupt Flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);
	
	return value;
}

void ADC_voidStartConversion()
{
	SET_BIT(ADCSRA,ADCSRA_ADSC);
}

void ADC_SelectChannel(u8 Channel)
{
	//Clear MUX bits in ADMUX Register//
	ADMUX &= ADC_CHANNEL_MASK;
	//Set required Channel in MUX bits//
	ADMUX |= Channel;
}