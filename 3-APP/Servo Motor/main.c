#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "ADC_interface.h"
#include "LCD_interface.h"
#include "Timer1_interface.h"
#include "util/delay.h"


s32 Map(s32 In_min, s32 In_max, s32 out_min, s32 out_max, s32 x);

int main(void)
{
	DIO_VoidInit();
	LCD_voidInit();
	Timer1_voidInit();
	Timer1_voidSetICRValue(20000);
	ADC_voidInit();
	ADC_voidEnable();
	u32 result;
	u16 read;
    while(1)
    {
		ADC_Channel();
		ADC_voidStartConversion();
		read = ADC_u16GetChannelReading();
		result = Map(0,1023,1000,2000,read); // Potentiometer , Servo Angel(0 pos to 180 pos) , ADC reading
		LCD_voidGoToXY(0,0);
		LCD_voidWriteNumber(read);
		Timer1_voidSetOCRValue(result);
		_delay_ms(10);
    }
}

s32 Map(s32 In_min, s32 In_max, s32 out_min, s32 out_max, s32 x)
{	
	return (((x - In_min)*(out_max - out_min)) / (In_max - In_min)) + out_min;
}