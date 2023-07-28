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
	
	u8 Key,operation=0,operation2=0;
	u8 flag=0;
	u8 Count=0;
	u16 num[20];
	u16 result=0;
	
	LCD_voidGoToXY(1,5);
	LCD_voidSendString("Calculator");
	_delay_ms(2000);
	LCD_voidSendCommand(1);
	
	while (1)
	{
		do
		{
			Key = KPD_u8GetPressedKey();
		} while (Key== 0xff);
		
		
		if ((Key >= 0 && Key <= 9))
		{
			LCD_voidWriteNumber(Key);
			num[Count]  = (num[Count]*10) + Key;
		}
		
		else if (Key=='+' || Key=='-' || Key=='*' || Key=='/')
		{
			/*first operation*/
			if (flag==0)			
			{
				operation = Key;
				switch(operation)
				{
					case '+':LCD_voidSendData(operation);break;
					case '*':LCD_voidSendData(operation);break;
					case '-':LCD_voidSendData(operation);break;
					case '/':LCD_voidSendData(operation);break;
				}
				Count++;
				flag=1;
			}
			
			/*second operation*/
			else if (flag==1)		
			{
				operation2 =Key;
				switch(operation2)
				{
					case '+':LCD_voidSendData(operation2);break;
					case '*':LCD_voidSendData(operation2);break;
					case '-':LCD_voidSendData(operation2);break;
					case '/':LCD_voidSendData(operation2);break;
				}
				Count++;
				flag=0;
			}
		}

		else if (Key== '=')
		{
			/*IF Enter One Operation*/
			if (flag==1)
			{
				LCD_voidSendData(Key);
				switch(operation)
				{
					case '+':result = num[0] + num[1];break;
					case '*':result = num[0] * num[1];break;
					case '-':result = num[0] - num[1];break;
					case '/':result = num[0] / num[1];break;
				}
				LCD_voidWriteNumber(result);
				_delay_ms(2000);
				
				flag=0;
				
				/*clear array of numbers & counter*/
				for (u8 i = 0; i < 20; i++) {
				num[i] = '\0';}
				Count=0;
				
				LCD_voidSendCommand(1);
			}
			
			/*IF Enter Two Operation*/
			else if	(flag==0)
			{
				LCD_voidSendData(Key);
				switch(operation2)
				{
					case '+':
					
					if (operation=='+')
					{
						result = num[0] + num[1] + num[2];break;
					}
					else if (operation=='-')
					{
						result = num[0] - (num[1] + num[2]) ;break;
					}
					else if (operation=='/')
					{
						result = (num[0] / num[1]) + num[2] ;break;
					}
					else if (operation=='*')
					{
						result =(num[0] * num[1]) + num[2] ;break;
					}

					case '*':
					
					if (operation=='+')
					{
						result = num[0] + (num[1] * num[2]) ;break;
					}
					else if (operation=='-')
					{
						result = num[0] - (num[1] * num[2]);break;
					}
					else if (operation=='/')
					{
						result = num[0] / (num[1] * num[2]) ;break;
					}
					else if (operation=='*')
					{
						result = num[0] * num[1] * num[2] ;break;
					}
					
					case '-':
					
					if (operation=='+')
					{
						result = (num[0] + num[1]) - num[2];break;
					}
					else if (operation=='-')
					{
						result = num[0] - num[1] - num[2] ;break;
					}
					else if (operation=='/')
					{
						result = (num[0] / num[1]) - num[2];break;
					}
					else if (operation=='*')
					{
						result = (num[0] * num[1]) - num[2];break;
					}
					
					case '/':
					
					if (operation=='+')
					{
						result = num[0] + (num[1] / num[2]);break;
					}
					else if (operation=='-')
					{
						result = num[0] - (num[1] / num[2]);break;
					}
					else if (operation=='/')
					{
						result =num[0] / num[1] / num[2];break;
					}
					else if (operation=='*')
					{
						result = (num[0] * num[1]) / num[2];break;
					}
				}
				
				LCD_voidWriteNumber(result);
				_delay_ms(2000);
				
				/*clear array of numbers & counter*/
				for (u8 i = 0; i < 20; i++) {
				num[i] = '\0';}
				Count=0;
				
				LCD_voidSendCommand(1);
			}
		}
		
		if (Key=='c')
		{
			LCD_voidSendCommand(1);
		}
	}
}