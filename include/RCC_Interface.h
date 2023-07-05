/***********************************/
/* SWC: RCC Driver                 */
/* Author: Aya Hesham              */
/* Version: V1                     */
/* Date: 30 May 2023               */
/***********************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*Functions Prototypes*/
void RCC_voidInitSysclk(void);   //Select System Clk

/*AHB1, AHB2, APB1, APB2*/
void RCC_voidEnablePeriphralCLK(u8 Copy_u8BusID ,u8 Copy_u8PeripheralID);
void RCC_voidDisablePeriphralCLK(u8 Copy_u8BusID ,u8 Copy_u8PeripheralID);


#define RCC_HSE_RC              0
#define RCC_HSE_Crystal         1

#define HSI                     0
#define HSE                     1
#define PLL                     2

#define AHB1                     0
#define AHB2                     1
#define APB1                     2
#define APB2                     3

#endif
