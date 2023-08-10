/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	MCAL			***************/
/***************	SWC: 	SPI				***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/
#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_register.h"

void (*SPI_Read)(void) = NULL;

u8* SPI_buffer;
u8  SPI_Buffer_size;
u8  SPI_Index = 0;
u8  busy_flag = 0;


u8 SPI_u8SendAsynchData(u8* Copy_Data,u8 buffer_size)
{
	if(busy_flag ==1)
	{
		return 1;
	}
	else
	{	
		busy_flag = 1;
		SPI_buffer = Copy_Data;
		/*Enable SPI Interrupt*/
		SET_BIT(SPCR,SPCR_SPIE);
	}
	SPDR = SPI_buffer[SPI_Index];// for send
	return 0;
}

u8 SPI_u8ReadAsynchData(u8* data,u8 buffer_size,void (*pf)(void)) 
{
	if(busy_flag ==1)
	{
		return 1; // return error
	}
	
	else
	{
		busy_flag = 1;
		SPI_buffer = data;
		SPI_Buffer_size = buffer_size;
		SPI_Read = pf;
		/*Enable SPI Interrupt*/
		SET_BIT(SPCR,SPCR_SPIE);
	}
	return 0; //return no Error
}


void __vector_12(void) __attribute__((signal , used));
void __vector_12(void)
{
	//SPI_buffer[SPI_Index] = SPDR;// read Data From Master
	SPI_Index++;
	if(SPI_Index == SPI_Buffer_size )
	{
		//SPI_Read();
		SPI_Buffer_size =0;
		SPI_Index = 0;
		busy_flag=0;
	}
	
	else
	{
		SPDR = SPI_buffer[SPI_Index]; 
	}
}

u8 SPI_u8Transmit_RecieveSynch(u8 Copy_Data)
{
	/* Start transmission */
	SPDR = Copy_Data;
	
	/* Wait for transmission complete */
	while(GET_BIT(SPSR,SPSR_SPIF)==0);
	
	/*Get the Exchanged Data*/
	return SPDR;
}


void SPI_voidMasterInit(void)
{	
	/*Enable Master*/
	SET_BIT(SPCR,SPCR_MSTR);
	
	/*Data Order*/
	#if DATA_ORDER == LSB
	SET_BIT(SPCR,SPCR_DORD);
	
	#elif DATA_ORDER == MSB
	CLR_BIT(SPCR,SPCR_DORD);
	#endif
	
	/*Clock Polarity*/
	#if CLOCK_POLARITY == CLKPOL_RISING_FALLING
	CLR_BIT(SPCR,SPCR_CPOL);
	
	#elif CLOCK_POLARITY == CLKPOL_FALLING_RISING
	SET_BIT(SPCR,SPCR_CPOL);	
	#endif
	
	/*Clock Phase*/
	#if CLOCK_PHASE == CLKPH_SAMPLE_SETUP
	CLR_BIT(SPCR,SPCR_CPHA);
	
	#elif CLOCK_PHASE == CLKPH_SETUP_SAMPLE
	SET_BIT(SPCR,SPCR_CPHA);
	#endif
	
	/*Set Clock Rate*/
	#if SPI_FREQUENCY == DIV_BY_4
	CLR_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
	
	#elif SPI_FREQUENCY == DIV_BY_16 
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);

	#elif SPI_FREQUENCY == DIV_BY_64
	CLR_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);	
	
	#elif SPI_FREQUENCY == DIV_BY_128
	SET_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);	
	
	#elif SPI_FREQUENCY == DIV_BY_2
	CLR_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);

	#elif SPI_FREQUENCY == DIV_BY_8
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);
	
	#elif SPI_FREQUENCY == DIV_BY_32
	CLR_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);	
	#endif
	
	/*Enable SPI*/
	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_voidSlaveInit(void)
{	
	/*Enable Slave*/
	CLR_BIT(SPCR,SPCR_MSTR);
	
	/*Data Order*/
	#if DATA_ORDER == LSB
	SET_BIT(SPCR,SPCR_DORD);
	
	#elif DATA_ORDER == MSB
	CLR_BIT(SPCR,SPCR_DORD);
	#endif
	
	/*Clock Polarity*/
	#if CLOCK_POLARITY == CLKPOL_RISING_FALLING
	CLR_BIT(SPCR,SPCR_CPOL);
	
	#elif CLOCK_POLARITY == CLKPOL_FALLING_RISING
	SET_BIT(SPCR,SPCR_CPOL);
	#endif
	
	/*Clock Phase*/
	#if CLOCK_PHASE == CLKPH_SAMPLE_SETUP
	CLR_BIT(SPCR,SPCR_CPHA);
	
	#elif CLOCK_PHASE == CLKPH_SETUP_SAMPLE
	SET_BIT(SPCR,SPCR_CPHA);
	#endif
	
	/*Enable SPI*/
	SET_BIT(SPCR,SPCR_SPE);
}