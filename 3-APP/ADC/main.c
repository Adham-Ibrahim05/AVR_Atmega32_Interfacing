#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "LCD_interface.h"

s32 Map(s32 In_min, s32 In_max, s32 out_min, s32 out_max, s32 In_val);

void main(void)
{
	u16 result=0,mv=0,Digital=0,Digi=0;
	u8 temp=0;
	
	DIO_voidSetPinDirection(DIO_PORTD,PIN0,PIN_OUTPUT);//PIN D0 output
	DIO_voidSetPinDirection(DIO_PORTD,PIN1,PIN_OUTPUT);//PIN D1 output
	DIO_voidSetPinDirection(DIO_PORTD,PIN2,PIN_OUTPUT);//PIN D2 output
	DIO_voidSetPinDirection(DIO_PORTC,PIN0,PIN_OUTPUT);//PIN C0 output
	DIO_voidSetPinDirection(DIO_PORTA,PIN0,PIN_INPUT);//ADC0 pin input
	DIO_voidSetPinDirection(DIO_PORTA,PIN1,PIN_INPUT);//ADC1 pin input
	
	LCD_voidInit();
	ADC_voidInit ();
	ADC_voidEnable();
	
    while(1)
    {  
		/*Potentiometer*/
		ADC_SelectChannel(ADC0);
		ADC_voidStartConversion();
        result = ADC_u16GetChannelReading();
		LCD_voidGoToXY(0,0);
        LCD_voidWriteNumber(result);
				
		/*Temperature Sensor*/
		ADC_SelectChannel(ADC1);
		ADC_voidStartConversion();
		Digital = ADC_u16GetChannelReading(); //Digital Reading 
		mv = ((u32) Digital*5000UL)/1024UL; // Analog m.volt type casted to u32 to avoid overflow, UL for unsigned long
		temp = mv/10;		
		if(temp==30)
		DIO_voidSetPinValue(DIO_PORTC,PIN0,PIN_HIGH);
		else 
		DIO_voidSetPinValue(DIO_PORTC,PIN0,PIN_LOW);
		
		
		/*LDR Sensor*/
		ADC_SelectChannel(ADC5);
		ADC_voidStartConversion();
		Digi = ADC_u16GetChannelReading();
		u32 out = Map(0,1023,0,4,Digi); 
		
		if (out==0)
		{
			DIO_voidSetPinValue(DIO_PORTD,PIN0,PIN_LOW);
			DIO_voidSetPinValue(DIO_PORTD,PIN1,PIN_LOW);
			DIO_voidSetPinValue(DIO_PORTD,PIN2,PIN_LOW);
		}
		else if (out==1)
		{
			DIO_voidSetPinValue(DIO_PORTD,PIN0,PIN_HIGH);
			DIO_voidSetPinValue(DIO_PORTD,PIN1,PIN_LOW);
			DIO_voidSetPinValue(DIO_PORTD,PIN2,PIN_LOW);
		}
		else if (out==2)
		{
			DIO_voidSetPinValue(DIO_PORTD,PIN0,PIN_HIGH);
			DIO_voidSetPinValue(DIO_PORTD,PIN1,PIN_HIGH);
			DIO_voidSetPinValue(DIO_PORTD,PIN2,PIN_LOW);
		}
		else if (out==3)
		{
			DIO_voidSetPinValue(DIO_PORTD,PIN0,PIN_HIGH);
			DIO_voidSetPinValue(DIO_PORTD,PIN1,PIN_HIGH);
			DIO_voidSetPinValue(DIO_PORTD,PIN2,PIN_HIGH);
		}
	}
}

s32 Map(s32 In_min, s32 In_max, s32 out_min, s32 out_max, s32 x) //(ADC range(0 to 1023),Led range(0 to 8), Digital reading)
{
	s32 y=0;
	
	y = (((x - In_min)*(out_max - out_min)) / (In_max - In_min)) + out_min;
	 
	return y;
}