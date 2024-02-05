/*
 * DMA_Interface.h
 *
 *  Created on: Aug 31, 2023
 *      Author: eslam
 */

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

#define DMA_PRIORTY_HIGH			0b10
#define DMA_PRIORTY_VERY_HIGH		0b11
#define DMA_PRIORTY_MEDIUM			0b01
#define DMA_PRIORTY_LOW				0b00






void DMA_voidInit(u8 Copy_StreamID,u8 priortyLevel,u8 TransferMode );
void DMA_voidSetAddress(u32 *PTRu32SrcAddress,u32 *PTRu32DesAddress, u32 Copyu32Length, u8 Copy8StreamID );

void DMA_voidClearFlagChannel0(void);

void DMA_voidStreamEnable(u8 Copy_StreamID);

#endif /* DMA_INTERFACE_H_ */
