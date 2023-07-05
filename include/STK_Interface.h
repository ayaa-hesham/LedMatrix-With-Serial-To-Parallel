/***********************************/
/* SWC: SYSTICK Driver             */
/* Author: Aya Hesham              */
/* Version: V1                     */
/* Date: 5 Jun 2023                */
/***********************************/ 


#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


void STK_void_Init();   //disable STK , disable STK Int , CLK SRC( AHB, AHB/8)
void STK_voidSetBusyWait(u32 Copy_u32NumOfCounts);     //delay func using polling

void STK_voidSetIntervalSingle(u32 Copy_u32NumOfCounts, void (*LpF) (void));   //Asynch jumb once on ISR  tech
void STK_voidSetIntervalPeriodic(u32 Copy_u32NumOfCounts, void (*LpF)(void)); //Asynch repeating

void STK_voidGetElapsedTime(u32* ElapsedTime);
void STK_voidGetRemainingTime(u32* RemainingTime);



#endif
