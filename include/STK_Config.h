/***********************************/
/* SWC: SYSTICK Driver             */
/* Author: Aya Hesham              */
/* Version: V1                     */
/* Date: 5 Jun 2023                */
/***********************************/ 

#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H

#define STK_AHB_CLK             0
#define STK_AHB_CLK_Div_By_8    1
#define STK_CLK_SRC             STK_AHB_CLK_Div_By_8

#define Int_Single_Flag       0
#define Int_Periodic_Flag     1



#endif