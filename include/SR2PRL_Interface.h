/***********************************/
/* SWC: Serial To Parallel Driver  */
/* Author: Aya Hesham              */
/* Version: V1                     */
/* Date: 18 June 2023              */
/***********************************/

#ifndef SR2PRL_INTERFACE_H_
#define SR2PRL_INTERFACE_H_

void SR2PRL_voidInit();
void SR2PRL_voidSendSynch(u8 Copy_u8Data);

void SR2PRL_voidSendStoreClk();
void SR2PRL_voidSendShiftClk();



#endif
