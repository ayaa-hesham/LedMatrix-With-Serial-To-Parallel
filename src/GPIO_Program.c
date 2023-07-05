/***********************************/
/* SWC: GPIO Driver                */
/* Author: Aya Hesham              */
/* Version: V1                     */
/* Date: 30 May 2023               */
/***********************************/

#include "Std_types.h"
#include "Bit_Math.h"

#include "GPIO_Config.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"


/*Copy_u8Mode:  INPUT, OUTPUT, AF, ANALOG*/
void GPIO_voidSetPinMode(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Mode)
{
    /*Input Validation*/
    if((Copy_u8PortID > GPIOC) || (Copy_u8PinID > Pin15) || (Copy_u8Mode > ANALOG))
    {
        /*Do Nothing*/
    }
    else
    {
        switch(Copy_u8Mode)
        {
            case INPUT:
            {
                switch(Copy_u8PortID)
                    {
                        case GPIOA:
                        {
                            Clear_Bit(GPIOA_MODER, (Copy_u8PinID*2));
                            Clear_Bit(GPIOA_MODER, ((Copy_u8PinID*2)+1));
                            break;
                        }
                        case GPIOB:
                        {
                            Clear_Bit(GPIOB_MODER, (Copy_u8PinID*2));
                            Clear_Bit(GPIOB_MODER, ((Copy_u8PinID*2)+1));
                            break;
                        }
                        case GPIOC:
                        {
                            Clear_Bit(GPIOC_MODER, (Copy_u8PinID*2));
                            Clear_Bit(GPIOC_MODER, ((Copy_u8PinID*2)+1));
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    }
                break;
            }
            case OUTPUT:
            {
                switch(Copy_u8PortID)
                {
                    case GPIOA:
                    {
                        Set_Bit(GPIOA_MODER, (Copy_u8PinID*2));
                        Clear_Bit(GPIOA_MODER, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    case GPIOB:
                    {
                        Set_Bit(GPIOB_MODER, (Copy_u8PinID*2));
                        Clear_Bit(GPIOB_MODER, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    case GPIOC:
                    {
                        Set_Bit(GPIOC_MODER, (Copy_u8PinID*2));
                        Clear_Bit(GPIOC_MODER, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
            case AF:
            {
                switch(Copy_u8PortID)
                {
                    case GPIOA:
                    {
                        Clear_Bit(GPIOA_MODER, (Copy_u8PinID*2));
                        Set_Bit(GPIOA_MODER, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    case GPIOB:
                    {
                        Clear_Bit(GPIOB_MODER, (Copy_u8PinID*2));
                        Set_Bit(GPIOB_MODER, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    case GPIOC:
                    {
                        Clear_Bit(GPIOC_MODER, (Copy_u8PinID*2));
                        Set_Bit(GPIOC_MODER, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
            case ANALOG:
            {
                switch(Copy_u8PortID)
                {
                    case GPIOA:
                    {
                        Set_Bit(GPIOA_MODER, (Copy_u8PinID*2));
                        Set_Bit(GPIOA_MODER, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    case GPIOB:
                    {
                        Set_Bit(GPIOB_MODER, (Copy_u8PinID*2));
                        Set_Bit(GPIOB_MODER, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    case GPIOC:
                    {
                        Set_Bit(GPIOC_MODER, (Copy_u8PinID*2));
                        Set_Bit(GPIOC_MODER, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
            default:
            {
                break;
            }
        }
    }
}



/*Copy_u8Type: OUTPUT_PP, OUTPUT_OD*/
void GPIO_voidSetPinType(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Type)
{
    /*Input Validation*/
    if((Copy_u8PortID > GPIOC) || (Copy_u8PinID > Pin15) || (Copy_u8Type > OUTPUT_OD))
    {
        /*Do Nothing*/
    }
    else
    {
        switch(Copy_u8Type)
        {
            case OUTPUT_PP:
            {
                switch(Copy_u8PortID)
                {
                    case GPIOA:
                    {
                        Clear_Bit(GPIOA_TYPER, Copy_u8PinID);
                        break;
                    }
                    case GPIOB:
                    {
                        Clear_Bit(GPIOB_TYPER, Copy_u8PinID);
                        break;
                    }
                    case GPIOC:
                    {
                        Clear_Bit(GPIOB_TYPER, Copy_u8PinID);
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
            case OUTPUT_OD:
            {
                switch(Copy_u8PortID)
                {
                    case GPIOA:
                    {
                        Set_Bit(GPIOA_TYPER, Copy_u8PinID);
                        break;
                    }
                    case GPIOB:
                    {
                        Set_Bit(GPIOB_TYPER, Copy_u8PinID);
                        break;
                    }
                    case GPIOC:
                    {
                        Set_Bit(GPIOB_TYPER, Copy_u8PinID);
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }

            default:
            {
                break;
            }
        }
    }
}



/*Copy_u8Speed: OUTPUT_LS, OUTPUT_MS, OUTPUT_HS*/
void GPIO_voidSetPinSpeed(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Speed)
{
    /*Input Validation*/
    if((Copy_u8PortID > GPIOC) || (Copy_u8PinID > Pin15) || (Copy_u8Speed > OUTPUT_HS))
    {
        /*Do Nothing*/
    }
    else
    {
        switch(Copy_u8Speed)
        {
            case OUTPUT_LS:
            {
                switch(Copy_u8PortID)
                {
                    case GPIOA:
                    {
                        Clear_Bit(GPIOA_SPEEDR, (Copy_u8PinID*2));
                        Clear_Bit(GPIOA_SPEEDR, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    case GPIOB:
                    {
                        Clear_Bit(GPIOB_SPEEDR, (Copy_u8PinID*2));
                        Clear_Bit(GPIOB_SPEEDR, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    case GPIOC:
                    {
                        Clear_Bit(GPIOC_SPEEDR, (Copy_u8PinID*2));
                        Clear_Bit(GPIOC_SPEEDR, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    default:
                    {
                        break;
                        }
                }
                break;
            }
            case OUTPUT_MS:
            {
                switch(Copy_u8PortID)
                {
                    case GPIOA:
                    {
                        Set_Bit(GPIOA_SPEEDR, (Copy_u8PinID*2));
                        Clear_Bit(GPIOA_SPEEDR, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    case GPIOB:
                    {
                        Set_Bit(GPIOB_SPEEDR, (Copy_u8PinID*2));
                        Clear_Bit(GPIOB_SPEEDR, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    case GPIOC:
                    {
                        Set_Bit(GPIOC_SPEEDR, (Copy_u8PinID*2));
                        Clear_Bit(GPIOC_SPEEDR, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
            case OUTPUT_HS:
            {
                switch(Copy_u8PortID)
                {
                    case GPIOA:
                    {
                        Clear_Bit(GPIOA_SPEEDR, (Copy_u8PinID*2));
                        Set_Bit(GPIOA_SPEEDR, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    case GPIOB:
                    {
                        Clear_Bit(GPIOB_SPEEDR, (Copy_u8PinID*2));
                        Set_Bit(GPIOB_SPEEDR, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    case GPIOC:
                    {
                        Clear_Bit(GPIOC_SPEEDR, (Copy_u8PinID*2));
                        Set_Bit(GPIOC_SPEEDR, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
            default:
            {
                break;
            }
        }
    }
}



/*Copy_u8PuPdOption: INPUT_FLOATING, INPUT_PU, INPUT_PD*/
void GPIO_voidSetPinPUPDOption(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PuPdOption)
{
    if((Copy_u8PortID > GPIOC) || (Copy_u8PinID > Pin15) || (Copy_u8PuPdOption > INPUT_PD))
    {

    }
    else
    {
    	switch(Copy_u8PuPdOption)
    	{
            case INPUT_FLOATING:
            {
                switch(Copy_u8PortID)
                {
                    case GPIOA:
                    {
                        Clear_Bit(GPIOA_PUPDR, (Copy_u8PinID*2));
                        Clear_Bit(GPIOA_PUPDR, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    case GPIOB:
                    {
                        Clear_Bit(GPIOB_PUPDR, (Copy_u8PinID*2));
                        Clear_Bit(GPIOB_PUPDR, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    case GPIOC:
                    {
                        Clear_Bit(GPIOC_PUPDR, (Copy_u8PinID*2));
                        Clear_Bit(GPIOC_PUPDR, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
            case INPUT_PU:
            {
                switch(Copy_u8PortID)
                {
                    case GPIOA:
                    {
                        Set_Bit(GPIOA_PUPDR, (Copy_u8PinID*2));
                        Clear_Bit(GPIOA_PUPDR, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    case GPIOB:
                    {
                        Set_Bit(GPIOB_PUPDR, (Copy_u8PinID*2));
                        Clear_Bit(GPIOB_PUPDR, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    case GPIOC:
                    {
                        Set_Bit(GPIOC_PUPDR, (Copy_u8PinID*2));
                        Clear_Bit(GPIOC_PUPDR, ((Copy_u8PinID*2)+1));
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
            case INPUT_PD:switch(Copy_u8PortID)
            {
                case GPIOA:
                {
                    Clear_Bit(GPIOA_PUPDR, (Copy_u8PinID*2));
                    Set_Bit(GPIOA_PUPDR, ((Copy_u8PinID*2)+1));
                    break;
                }
                case GPIOB:
                {
                    Clear_Bit(GPIOB_PUPDR, (Copy_u8PinID*2));
                    Set_Bit(GPIOB_PUPDR, ((Copy_u8PinID*2)+1));
                    break;
                }
                case GPIOC:
                {
                    Clear_Bit(GPIOC_PUPDR, (Copy_u8PinID*2));
                    Set_Bit(GPIOC_PUPDR, ((Copy_u8PinID*2)+1));
                    break;
                }
                default:
                {
                    break;
                }
            }
                break;

            default:
            {
                break;
            }
        }
    }
}



void GPIO_voidSetPortValue(u8 Copy_u8PortID, u32 Copy_u32Value)
{
	/*Input Validation*/
	if((Copy_u8PortID > GPIOC))
	{

	}
	else
	{
		switch(Copy_u8PortID)
		{
			case GPIOA:
            {
                GPIOA_ODR = Copy_u32Value;
				break;
            }
			case GPIOB:
            {
                GPIOB_ODR = Copy_u32Value;
				break;
            }
			case GPIOC:
            {
                GPIOC_ODR = Copy_u32Value;
				break;
            }
			default:
            {
                break;
            }
		}
	}
}



/*Copy_u8Signal: PIN_SET, PIN_RST*/
void GPIO_voidSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Signal)
{
    if((Copy_u8PortID > GPIOC) || (Copy_u8PinID > Pin15) || (Copy_u8Signal > PIN_RST))
    {

    }
    else
    {
    	switch(Copy_u8Signal)
    	{
    		case PIN_SET:
            {
                switch(Copy_u8PortID)
                {
                    case GPIOA:
                    {
                        GPIOA_BSRR = (1 << Copy_u8PinID);
                        break;
                    }
                    case GPIOB:
                    {
                        GPIOB_BSRR = (1 << Copy_u8PinID);
                        break;
                    }
                    case GPIOC:
                    {
                        GPIOC_BSRR = (1 << Copy_u8PinID);
                        break;
                    }
                }
                break;
            }
    		case PIN_RST:
            {
                switch(Copy_u8PortID)
                {
                    case GPIOA:
                    {
                        GPIOA_BSRR = (1 << (Copy_u8PinID+16));
                        break;
                    }
                    case GPIOB:
                    {
                        GPIOB_BSRR = (1 << (Copy_u8PinID+16));
                        break;
                    }
                    case GPIOC:
                    {
                        GPIOC_BSRR = (1 << (Copy_u8PinID+16));
                        break;
                    }
                }
                break;
            }
    	}
    }
}


u8   GPIO_u8GetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
	u8 Local_u8PinValue = 0;
	if((Copy_u8PortID > GPIOC) || (Copy_u8PinID > Pin15))
	{

	}
	else
	{
		switch(Copy_u8PortID)
		{
			case GPIOA:
            {
                Local_u8PinValue = Get_Bit(GPIOA_IDR,Copy_u8PinID);
				break;
            }
			case GPIOB:
            {
                Local_u8PinValue = Get_Bit(GPIOB_IDR,Copy_u8PinID);
						break;
            }
			case GPIOC:
            {
                Local_u8PinValue = Get_Bit(GPIOC_IDR,Copy_u8PinID);
				break;
            }
		}
	}
	return Local_u8PinValue;
}



void GPIO_voidSetAlterFuncConfig(u8 Copy_u8PortID, u8 Copy_u8PinID ,u8 Copy_u8ALterFunc)
{
    if((Copy_u8PortID > GPIOC) || (Copy_u8PinID > Pin15) || (Copy_u8ALterFunc > AF15 ))
	{
        //do nothing
	}
    else
    {
        if(Copy_u8PinID <= 7)
        {
            switch (Copy_u8PortID)
            {
                case GPIOA:
                {
                    GPIOA_AFRL |= Copy_u8ALterFunc << (Copy_u8PinID *4);
                    break;
                }
                case GPIOB:
                {
                    GPIOB_AFRL |= Copy_u8ALterFunc << (Copy_u8PinID *4);
                    break;
                }
                case GPIOC:
                {
                    GPIOC_AFRL |= Copy_u8ALterFunc << (Copy_u8PinID *4);
                    break;
                }
            }
        }
        else if (Copy_u8PinID <= 15)
        {
            switch (Copy_u8PortID)
            {
                case GPIOA:
                {
                    GPIOA_AFRH |= Copy_u8ALterFunc << ((Copy_u8PinID % 8)*4);
                    break;
                }
                case GPIOB:
                {
                    GPIOB_AFRH |= Copy_u8ALterFunc << ((Copy_u8PinID % 8)*4);
                    break;
                }
                case GPIOC:
                {
                    GPIOC_AFRH |= Copy_u8ALterFunc << ((Copy_u8PinID % 8)*4);
                    break;
                }
            }
        }
    }


}
