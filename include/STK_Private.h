/***********************************/
/* SWC: SYSTICK Driver             */
/* Author: Aya Hesham              */
/* Version: V1                     */
/* Date: 5 Jun 2023                */
/***********************************/ 

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

//Base Add  0xE000E010
#define STK_CTRL    *((volatile u32*)0xE000E010)
#define STK_LOAD    *((volatile u32*)0xE000E014)
#define STK_VAL     *((volatile u32*)0xE000E018)
#define STK_CALIB   *((volatile u32*)0xE000E01C)


void Private_voidDisableSTK(void);

#endif