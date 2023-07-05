
#include "Std_types.h"
#include "Bit_Math.h"

#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"

#include "SR2PRL_Interface.h"
#include "LM_SR2PRL_Interface.h"

u8 G_Name[] = { 0, 0, 124, 18, 18, 124, 0, 0
		,0, 0, 78, 72, 72, 126, 0,0
		,0, 0, 124, 18, 18, 124, 0, 0
};

void main(void)
{
	//init Sys CLK
	RCC_voidInitSysclk();

	//Enable GPIOA CLK
	RCC_voidEnablePeriphralCLK(AHB1,0);
	RCC_voidEnablePeriphralCLK(AHB1,1);

	//stk init
	STK_void_Init();

	//Serial to parallel init
	SR2PRL_voidInit();


	while(1)
	{

		LEDM_STPvoidDisplay_Name(G_Name,30);
	}

}
