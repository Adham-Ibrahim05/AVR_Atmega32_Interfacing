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
	
	u16 Key,operation=0,operation2=0;
	u8 flag1=0,flag2=0;
	u16 num1=0,num2=0,num3=0;
	u16 result=0,temp=0;
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
				num1  = (num1*10) + Key;
			}
			
			else if (Key!='=' && !(Key >= 0 && Key <=9))
			{
				if (flag1==0)			//first operation
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
					flag1=1;
				}
				
				else if (flag1==1)		//second operation
				{
					operation2 =Key;
					switch(operation2)
					{
						case '+':LCD_voidSendData(operation2);break;
						case '*':LCD_voidSendData(operation2);break;
						case '-':LCD_voidSendData(operation2);break;
						case '/':LCD_voidSendData(operation2);break;
					}
					num3=num1;
					num1=0;
					flag1=0;
					flag2=1;
				}			
			}

		else if (Key== '=')
		{
			/*IF Enter One Operation*/
			if (flag1==1 && flag2==0)
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
				flag1=flag2=0;
				LCD_voidSendCommand(1);
			}
			/*IF Enter Two Operation*/
			else if	(flag2==1 && flag1==0)
			{
				LCD_voidSendData(Key);
				switch(operation2)
				{
					case '+':
					if (operation=='+')
					{
						temp = num1 + num2 + num3;break;
					}
					else if (operation=='-')
					{
						temp = (num1 + num2) - num3 ;break;
					}
					else if (operation=='/')
					{
						temp = num1 + (num2/num3);break;
					}
					else if (operation=='*')
					{
						temp = num1 + (num2*num3);break;
					}
					
					case '*':
					if (operation=='+')
					{
						temp = (num3 * num1) + num2;break;
					}
					else if (operation=='-')
					{
						temp =num2 - (num1 * num3);break;
					}
					else if (operation=='/')
					{
						temp =num2 / (num1 * num3) ;break;
					}
					else if (operation=='*')
					{
						temp = num1 * num3 * num2;break;
					}
					
					case '-':
					if (operation=='+')
					{
						temp = (num3 + num2) - num1;break;
					}
					else if (operation=='-')
					{
						temp = num2 - num3 - num1 ;break;
					}
					else if (operation=='/')
					{
						temp = (num2 / num3) - num1;break;
					}
					else if (operation=='*')
					{
						temp = (num2*num3) - num1;break;
					}
					
					case '/':
					if (operation=='+')
					{
						temp = (num3 / num1) + num2;break;
					}
					/*else if (operation=='-')
					{
						temp = (num3 / num1) - num2 ;break;
					}*/
					else if (operation=='/')
					{
						temp = num2 / num1 / num3;break;
					}
					else if (operation=='*')
					{
						temp = (num2*num3) / num1;break;
					}
				}	
				
				LCD_voidWriteNumber(temp);
				_delay_ms(2000);
				num2=num1=num3=0;
				flag1=flag2=0;
				LCD_voidSendCommand(1);
			}
		}
	}	
}