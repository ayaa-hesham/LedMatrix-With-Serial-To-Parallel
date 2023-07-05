/***********************************/
/* SWC: GPIO Driver                */
/* Author: Aya Hesham              */
/* Version: V1                     */
/* Date: 30 May 2023               */
/***********************************/

#include "Std_types.h"

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


void GPIO_voidSetPinMode(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Mode);

void GPIO_voidSetPinType(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Type);

void GPIO_voidSetPinSpeed(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Speed);

void GPIO_voidSetPinPUPDOption(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PuPdOption);

void GPIO_voidSetPortValue(u8 Copy_u8PortID, u32 Copy_u32Value);

void GPIO_voidSetPinValueDirectAccess(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Signal);

u8 GPIO_u8GetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID);


/*Interface Macros*/
#define GPIOA           0
#define GPIOB           1
#define GPIOC           2

#define Pin0            0 
#define Pin1            1 
#define Pin2            2 
#define Pin3            3 
#define Pin4            4 
#define Pin5            5 
#define Pin6            6 
#define Pin7            7 
#define Pin8            8 
#define Pin9            9 
#define Pin10           10
#define Pin11           11
#define Pin12           12
#define Pin13           13
#define Pin14           14
#define Pin15           15

#define INPUT           0
#define OUTPUT          1
#define AF              2
#define ANALOG          3

#define AF0             0b0000
#define AF1             0b0001
#define AF2             0b0010
#define AF3             0b0011
#define AF4             0b0100
#define AF5             0b0101
#define AF6             0b0110
#define AF7             0b0111
#define AF8             0b1000
#define AF9             0b1001
#define AF10            0b1010
#define AF11            0b1011
#define AF12            0b1100
#define AF13            0b1101
#define AF14            0b1110
#define AF15            0b1111


#define OUTPUT_PP       0
#define OUTPUT_OD       1

#define OUTPUT_LS       0
#define OUTPUT_MS       1
#define OUTPUT_HS       2

#define PIN_SET			0
#define PIN_RST			1

#define INPUT_FLOATING	0
#define INPUT_PU		1
#define INPUT_PD		2

#endif
