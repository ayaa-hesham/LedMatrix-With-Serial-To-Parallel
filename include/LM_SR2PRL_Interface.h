/**************************************/
/* SWC: Led Matrix with SR2PRL Driver */
/* Author: Aya Hesham                 */
/* Version: V1                        */
/* Date: 25 Jun 2023                  */
/**************************************/  

#ifndef LEDMATRIX_INTERFACE_H
#define LEDMATRIX_INTERFACE_H

void LEDM_SR2PRL_SetRows();
void LEDM_SR2PRL_ResetColumns();
void LEDM_SR2PRL_voidDisplay(u8* FrameData);
void LEDM_SR2PRL_SetOneCol(u8 Copy_U8ColNum);
void LEDM_STPvoidDisplay_Name(u8* Display_frame_data,u8 copy_u8size);
void LEDM_SR2PRLSendData(u8 Copy_u8RowData ,u8 Copy_u8ColNum);

#endif
