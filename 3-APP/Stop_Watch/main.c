#define F_CPU	8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"
#include "Timer1_interface.h"
#include "Timer1_register.h"
#include "Seven_Segment.h"


void INT0_ISR (void);	// For Reset
void INT1_ISR (void);	// For Pause
void INT2_ISR (void);	// For Resume
void Timer1_ISR (void);	// For Timer

u8 flag;
u8 Clock[6];

int main(void)
{
	DIO_VoidInit();
	GIE_voidEnable();
	
	/*RESET Interrupt*/
	EXTI_voidINT0Init();
	EXTINT0_VoidSetCallBack(INT0_ISR);
	EXTI_voidINT0Enable();
	
	/*PAUSE Interrupt*/
	EXTI_voidINT1Init();
	EXTINT1_VoidSetCallBack(INT1_ISR);
	EXTI_voidINT1Enable();
	
	/*RESUME Interrupt*/
	EXTI_voidINT2Init();
	EXTINT2_VoidSetCallBack(INT2_ISR);
	EXTI_voidINT2Enable();
	
	/*TIMER Interrupt*/
	Timer1_voidInit();
	Timer1_voidSetOCR1AValue(7813);	// for 1 sec at Freq=8MHZ, Prescaler=1024;
	Timer1_voidCompareSetCallBack(Timer1_ISR);
	
		
    while(1)
    {
		SevenSegment_voidDisplay();
       if(flag==1){
	       SevenSegment_voidUpdateDigits();
	       flag=0;
       }
    }
}


void INT0_ISR (void)
{
	//RESET Stop Watch
	for(int i=0;i<6;i++){
		Clock[i]=0;
	}
	TCNT1=0;	//Timer Start from 0
}

void INT1_ISR (void)
{
	//PAUSE Stop Watch,No Clock Source
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	CLR_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);
}
void INT2_ISR (void)
{
	//RESUME Stop Watch,Set PreScaler by 1024
	SET_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS12);
}

void Timer1_ISR (void)
{
	flag = 1;
}