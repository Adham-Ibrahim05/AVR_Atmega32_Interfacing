#define F_CPU	8000000UL
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KPD_interface.h"
#include <util/delay.h>
int main(void)
{
	KPD_u8Init();
	u8 Local_u8Key;
	LCD_voidInit();
	_delay_ms(200);
	LCD_voidSendCommand(1);
	_delay_ms(200);
	LCD_voidSendCommand(0X80);//DDRAM
	_delay_ms(200);
	while(1)
	{
		do
		{
			Local_u8Key = KPD_u8GetPressedKey();
		} while (Local_u8Key==0xff);
		LCD_voidSendData(Local_u8Key);
	}
}
