/***********************************/
/* SWC: RCC Driver                 */
/* Author: Aya Hesham              */
/* Version: V1                     */
/* Date: 30 May 2023               */
/***********************************/

#include <stdio.h>

#include "Std_types.h"
#include "Bit_Math.h"

#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"


void RCC_voidInitSysclk(void)
{
    //HSI on
    Set_Bit(RCC_CR , 0);
    //HSE on
    Set_Bit(RCC_CR , 16);

    #if RCC_SYS_CLK_SRC == HSE_CRYSTAL
        /*
         //Enable HSE
        Set_Bit(RCC_CR, 16);
        */

        /*Disable Bybass*/
        Clear_Bit(RCC_CR, 18);

        /*
        //Sys Clk Source ==> HSE
        Set_Bit(RCC_CFGR, 0);
        Clear_Bit(RCC_CFGR, 1);
        */

    #elif RCC_SYS_CLK_SRC == HSE_RC
        /*
        //Enable HSE
        Set_Bit(RCC_CR, 16);
         */

        /*Enable Bybass*/
        Set_Bit(RCC_CR, 18);
	#endif

        /*PLL is ON*/
        Set_Bit(RCC_CR, 24);

        /*Sys Clk Source ==> HSE*/
        /*Select Clock Source*/
    #if RCC_SYS_CLK_SRC == HSE
        Set_Bit(RCC_CFGR, 0);
        Clear_Bit(RCC_CFGR, 1);
    #elif RCC_SYS_CLK_SRC == HSI
        /*Enable HSI*/
        Set_Bit(RCC_CR, 0);
        /*Sys Clk Source ==> HSI*/
        Clear_Bit(RCC_CFGR, 0);
        Clear_Bit(RCC_CFGR, 1);
    #elif RCC_SYS_CLK_SRC == PLL
        Clear_Bit(RCC_CFGR, 0);
        Set_Bit(RCC_CFGR, 1);

     #else
		#error "Invalid Configurations!"
    #endif

     //select AHB clock
      Set_Bit(RCC_CFGR,7);
}


/*Copy_u8BusID: AHB1, AHB2, APB1, APB2*/
/*Copy_u8PeripheralID: 0 --> 31*/
void RCC_voidEnablePeriphralCLK(u8 Copy_u8BusID , u8 Copy_u8PeripheralID)
{
    /*Input Validation*/
    if((Copy_u8BusID > APB2) ||Copy_u8PeripheralID > 31)
    {
        /*Nothing to be done*/
    }
    else
    {
        switch(Copy_u8BusID)
        {
            case AHB1:   
            {
                Set_Bit(RCC_AHB1ENR, Copy_u8PeripheralID);    
                break;
            }
            case AHB2:  
            {
                Set_Bit(RCC_AHB2ENR, Copy_u8PeripheralID);    
                break;
            }
            case APB1:  
            {
                Set_Bit(RCC_APB1ENR, Copy_u8PeripheralID);    
                break;
            }

            case APB2:   
            {
                Set_Bit(RCC_APB2ENR, Copy_u8PeripheralID);    
                break;
            }
            default  :                                                 
            {
                break;
            }
        }
    }
}


/*Copy_u8BusID: AHB1, AHB2, APB1, APB2*/
/*Copy_u8PeripheralID: 0 --> 31*/
void RCC_voidDisablePeriphralCLK(u8 Copy_u8BusID ,u8 Copy_u8PeripheralID)
{
    /*Input Validation*/
    if(Copy_u8PeripheralID > 31 || (Copy_u8BusID > APB2))
    {
        /*Nothing to be done*/
    }
    else
    {
        switch(Copy_u8BusID)
        {
            case AHB1:   
            {
                Clear_Bit(RCC_AHB1ENR, Copy_u8PeripheralID);    
                break;
            }
            case AHB2:  
            {
                Clear_Bit(RCC_AHB2ENR, Copy_u8PeripheralID);    
                break;
            }
            case APB1:  
            {
                Clear_Bit(RCC_APB1ENR, Copy_u8PeripheralID);    
                break;
            }

            case APB2:   
            {
                Clear_Bit(RCC_APB2ENR, Copy_u8PeripheralID);    
                break;
            }
            default  :                                                 
            {
                break;
            }
        }
    }
}

//PLL Config
