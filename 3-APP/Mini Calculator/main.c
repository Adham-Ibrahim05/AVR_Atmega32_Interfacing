#define  F_CPU 8000000UL
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KPD_interface.h"
#include <util/delay.h>
int main()
{
	LCD_voidInit();
	KPD_u8Init();
	
	u16 Key,operation=0;
	u16 num1=0,num2=0;
	u32 result=0;
	LCD_voidGoToXY(1,5);
	LCD_voidSendString("Calculator");
	_delay_ms(2000);
	LCD_voidSendCommand(1);

	while(1)
	{
		do
		{
			Key = KPD_u8GetPressedKey();
		} while (Key==0xff);
		
		if ((Key >= 0 && Key <= 9))
		{
			LCD_voidWriteNumber(Key);
			num1  = (num1*10) + Key;
		}
		
		else if (Key!='=' && !(Key >= 0 && Key <=9))
		{
			operation = Key;
			switch(operation)
			{
				case '+':LCD_voidSendData(operation);break;
				case '*':LCD_voidSendData(operation);break;
				case '-':LCD_voidSendData(operation);break;
				case '/':LCD_voidSendData(operation);break;
			}
			num2=num1;
			num1=0;
		}
		
		else if (Key=='=')
		{
			LCD_voidSendData(Key);
			switch(operation)
			{
				case '+':result = num1 + num2;break;
				case '*':result = num1 * num2;break;
				case '-':result = num2 - num1;break;
				case '/':result = num2 / num1;break;
			}
			LCD_voidWriteNumber(result);
			_delay_ms(2000);
			num2=num1=0;
			LCD_voidSendCommand(1);
		}
	}