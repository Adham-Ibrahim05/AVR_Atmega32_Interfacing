#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "Timer1_register.h"
#include "Seven_Segment.h"
#include "util/delay.h"

u8 Clock[6];

void SevenSegment_voidUpdateDigits(void)
{
	Clock[0]++;	//every timer interrupt (every second) increase seconds
	/*For Seconds*/
	if (Clock[0]==10)
	{
		Clock[0]=0;
		Clock[1]++;
		if (Clock[1]==6 && Clock[0]==0)
		{
			Clock[1]=0;
			Clock[2]++;
		}
	}
	/*For Minuets*/
	if (Clock[2]==10)
	{
		Clock[2]=0;
		Clock[3]++;
		if (Clock[3]==6 && Clock[2]==0)
		{
			Clock[3]=0;
			Clock[4]++;
		}
	}
	/*For Hours*/
	if (Clock[4]==10)
	{
		Clock[4]=0;
		Clock[5]++;
		if (Clock[5]==10 && Clock[4]==0)
		{
			/*Reaches the max limit so reset the timer & Stop Watch*/
			for(int i=0;i<6;i++){
				Clock[i]=0;
			}
			TCNT1=0;	
		}
	}
}

void SevenSegment_voidDisplay(void)
{
	/*looping on each digit*/
	 for(int i=0;i<6;i++)
	 { 
		PORTA=1<<i;
		PORTC=Clock[i];
		 _delay_ms(5);	
	 }
}
