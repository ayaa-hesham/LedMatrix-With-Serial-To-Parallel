/***********************************/
/* SWC: Serial To Parallel Driver  */
/* Author: Aya Hesham              */
/* Version: V1                     */
/* Date: 18 June 2023              */
/***********************************/

#include "Std_types.h"
#include "Bit_Math.h"

#include "GPIO_Interface.h"
#include "STK_Interface.h"


#include "SR2PRL_Interface.h"
#include "SRL2PRL_Config.h"
#include "SRL2PRL_Private.h"

u8 NumberOfArrElem = 8;

void SR2PRL_voidInit()
{
	//config pins A0 ,A1 ,A2 as output PP LS
	//SR2PRL_Serial_Pin
	GPIO_voidSetPinMode(SR2PRL_Serial_Pin,OUTPUT);
	GPIO_voidSetPinSpeed(SR2PRL_Serial_Pin, OUTPUT_LS);
	GPIO_voidSetPinType(SR2PRL_Serial_Pin, OUTPUT_PP);

	//ST_Pin
	GPIO_voidSetPinMode(SR2PRL_Store_CLK_Pin ,OUTPUT);
	GPIO_voidSetPinSpeed(SR2PRL_Store_CLK_Pin , OUTPUT_LS);
	GPIO_voidSetPinType(SR2PRL_Store_CLK_Pin , OUTPUT_PP);

	//SH_Pin
	GPIO_voidSetPinMode(SR2PRL_Shift_CLK_Pin,OUTPUT);
	GPIO_voidSetPinSpeed(SR2PRL_Shift_CLK_Pin, OUTPUT_LS);
	GPIO_voidSetPinType(SR2PRL_Shift_CLK_Pin, OUTPUT_PP);
}

void SR2PRL_voidSendSynch(u8 Copy_u8Data)
{
	//Copy_u8Data ===> 8bits
	s8 Local_s8Counter;
	u8 Local_u88Bit;

	for (Local_s8Counter=0 ; Local_s8Counter <= 7 ;Local_s8Counter++)
	{
		Local_u88Bit = Get_Bit(Copy_u8Data , Local_s8Counter);
		//send data bit by bit
		GPIO_voidSetPinValue(SR2PRL_Serial_Pin,Local_u88Bit );
		//send pulse on SR2PRLShiftCLK_Pin
		SR2PRL_voidSendShiftClk();
	}

	//send pulse on SR2PRL_StoreCLK_Pin
	SR2PRL_voidSendStoreClk();
}


void SR2PRL_voidSendShiftClk()
{
	// clk
	GPIO_voidSetPinValue(SR2PRL_Shift_CLK_Pin,PIN_SET);
	STK_voidSetBusyWait(5);
	GPIO_voidSetPinValue(SR2PRL_Shift_CLK_Pin,PIN_RST);
	STK_voidSetBusyWait(5);
}

void SR2PRL_voidSendStoreClk()
{
	GPIO_voidSetPinValue(SR2PRL_Store_CLK_Pin,PIN_SET);
	STK_voidSetBusyWait(5);
	GPIO_voidSetPinValue(SR2PRL_Store_CLK_Pin,PIN_RST);
	STK_voidSetBusyWait(5);
}



