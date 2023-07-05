/***********************************/
/* SWC: SYSTICK Driver             */
/* Author: Aya Hesham              */
/* Version: V1                     */
/* Date: 5 Jun 2023                */
/***********************************/ 

#include <stdio.h>

#include "Std_types.h"
#include "Bit_Math.h"

#include "STK_Interface.h"
#include "STK_Private.h"
#include "STK_Config.h"

static u8 STK_HandlerSingleSrc = 0;

void (*STK_pfNotification) (void)= NULL;

void STK_void_Init()   
{
    //disable STK timer
    Clear_Bit(STK_CTRL,0);

    //disable STK Int 
    Clear_Bit(STK_CTRL,1);

    //configure CLK SRC(AHB, AHB/8)
    #if STK_CLK_SRC == STK_AHB_CLK
        Set_Bit(STK_CTR,2);
    #elif STK_CLK_SRC == STK_AHB_CLK_Div_By_8
        Clear_Bit(STK_CTRL,2);
    #else
        #warning "Invalid Config"
    #endif
}  

//delay func using polling
void STK_voidSetBusyWait (u32 Copy_u32NumOfCounts)    
{
    //load user defined counts to load reg
    STK_LOAD = Copy_u32NumOfCounts;

    //start timer
    Set_Bit(STK_CTRL,0);

    //polling on flag
    while(Get_Bit(STK_CTRL,16) == 0);

    //disable timer
    Private_voidDisableSTK();

    //diable intrrupt
    Clear_Bit(STK_CTRL ,1);
}

//Asynch jumb once on ISR  tech
void STK_voidSetIntervalSingle(u32 Copy_u32NumOfCounts, void (*LpF) (void))
{ 
    //save call back
    STK_pfNotification = LpF;
    
    //load user defined counts to load reg
    STK_LOAD = Copy_u32NumOfCounts;

    //start timer
    Set_Bit(STK_CTRL,0);

    //set flag 1
    STK_HandlerSingleSrc = 1;

    //enable STK Int
    Set_Bit(STK_CTRL,1);
}

void STK_voidSetIntervalPeriodic(u32 Copy_u32NumOfCounts, void (*LpF)(void))
{
     //save call back
    STK_pfNotification = LpF;
    
    //load user defined counts to load reg
    STK_LOAD = Copy_u32NumOfCounts;

    //start timer
    Set_Bit(STK_CTRL,0);

    //enable STK Int
    Set_Bit(STK_CTRL,1);
}


void STK_voidGetElapsedTime(u32* ElapsedTime)
{
    *ElapsedTime = (STK_LOAD - STK_VAL);
}

void STK_voidGetRemainingTime(u32* RemainingTime)
{
    *RemainingTime = STK_VAL;
}

void Private_voidDisableSTK(void)
{
    Clear_Bit(STK_CTRL,0);
    STK_LOAD = 0;
    STK_VAL = 0;
}


void SysTick_Handler(void)
{
    if(STK_HandlerSingleSrc == 1)
    {
        Private_voidDisableSTK();
    }

    if(STK_pfNotification!= NULL)
    {
        STK_pfNotification();
    }
    //clear intrrupt flag
    u8 Local_u8TempValue = Get_Bit(STK_CTRL,16);
}



