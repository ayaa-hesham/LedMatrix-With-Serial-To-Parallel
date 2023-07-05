/**************************************/
/* SWC: Led Matrix with SR2PRL Driver */
/* Author: Aya Hesham                 */
/* Version: V1                        */
/* Date: 25 Jun 2023                  */
/**************************************/  

//MCAL
#include "GPIO_Interface.h"
#include "STK_Interface.h"
//Libraries
#include "Std_types.h"
#include "Bit_Math.h"
//HAL
#include "SRL2PRL_Config.h"
#include "SR2PRL_Interface.h"




void LEDM_SR2PRL_ResetColumns()
{
	// disable all columns
	s8 Local_s8Counter;
		for(Local_s8Counter=7 ; Local_s8Counter>=0 ; Local_s8Counter--)
		{
			GPIO_voidSetPinValue(SR2PRL_Serial_Pin,PIN_RST);
			SR2PRL_voidSendShiftClk();
		}
}

void LEDM_SR2PRL_SetRows()
{
	// set all rows
	s8 Local_s8Counter;
	for(Local_s8Counter=7 ; Local_s8Counter>=0 ; Local_s8Counter--)
	{
		GPIO_voidSetPinValue(SR2PRL_Serial_Pin,PIN_SET);
		SR2PRL_voidSendShiftClk();
	}
}

void LEDM_SR2PRL_voidDisplay(u8* FrameData)
{
    LEDM_SR2PRL_ResetColumns();
    LEDM_SR2PRL_SetRows();
    SR2PRL_voidSendStoreClk();

    u8 Local_u8Counter;
    for(Local_u8Counter=0 ; Local_u8Counter<8 ; Local_u8Counter++)
    {
    	LEDM_SR2PRLSendData(FrameData[Local_u8Counter] ,Local_u8Counter);
		STK_voidSetBusyWait(150);
		SR2PRL_voidSendStoreClk();
		LEDM_SR2PRL_ResetColumns();
		LEDM_SR2PRL_SetRows();
		SR2PRL_voidSendStoreClk();
    }

}

void LEDM_STPSetColumns()
{
	s8 Local_s8Counter;
		for(Local_s8Counter=7 ; Local_s8Counter>=0 ; Local_s8Counter++)
		{
			GPIO_voidSetPinValue(SR2PRL_Serial_Pin,PIN_SET);
			SR2PRL_voidSendShiftClk();
		}
}

void LEDM_SR2PRL_SetOneCol(u8 Copy_U8ColNum)
{
	s8 Local_s8Counter;
		for(Local_s8Counter=7 ; Local_s8Counter>=0 ; Local_s8Counter--)
		{
			if(Local_s8Counter == Copy_U8ColNum)
			{
				GPIO_voidSetPinValue(SR2PRL_Serial_Pin,PIN_SET);
			}
			else
			{
				GPIO_voidSetPinValue(SR2PRL_Serial_Pin,PIN_RST);
			}

			SR2PRL_voidSendShiftClk();
		}
}

void LEDM_SR2PRLSendData(u8 Copy_u8RowData ,u8 Copy_u8ColNum)
{
	s8 Local_s8Counter;
	// enable column
	LEDM_SR2PRL_SetOneCol(Copy_u8ColNum) ;
	//out data on row
	for(Local_s8Counter=7 ; Local_s8Counter>=0 ; Local_s8Counter-- )
	{
		GPIO_voidSetPinValue(SR2PRL_Serial_Pin , Get_Bit(Copy_u8RowData,Local_s8Counter));
		SR2PRL_voidSendShiftClk();
	}
}

void LEDM_STPvoidDisplay_Name(u8* Display_frame_data,u8 copy_u8size)
{
	static u8 LetterCount=0;
	for(LetterCount=0 ; LetterCount<(copy_u8size-8) ; )
	{
		static u8 Frame=0;
		LEDM_SR2PRL_voidDisplay(Display_frame_data + LetterCount);
		Frame++;
		if(Frame==15)
		{
			LetterCount++;
			Frame=0;
		}
	}
}
