/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	MCAL			***************/
/***************	SWC: 	WDT				***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "WDT_interface.h"
#include "WDT_register.h"
#include "WDT_config.h"
#include "WDT_private.h"

void WDT_voidON(void)
{
	/*WDT Time Out*/
	WDTCR &= TIME_OUT_MASK;
	WDTCR |= WDT_TIME_OUT;
	
	/*Enable WDT*/
	SET_BIT(WDTCR,WDTCR_WDE);
}

void WDT_voidOFF(void)
{
	WDTCR = 0XFF;
	CLR_BIT(WDTCR,WDTCR_WDE);
}

void WDT_voidRefresh(void)
{
	asm("WDR");
}