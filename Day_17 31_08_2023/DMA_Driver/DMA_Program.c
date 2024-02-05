/*
 * DMA_Program.c
 *
 *  Created on: Aug 31, 2023
 *      Author: eslam
 */


#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "DMA_Private.h"
#include "DMA_Interface.h"

void(*DMA_pToFunction)(void);

void DMA_voidInit(u8 Copy_StreamID ,u8 priortyLevel , u8 TransferMode)
{
	/* disable DMA before congig*/
	CLEAR_BIT((DMA2->DMACHANNEL[Copy_StreamID].CR),0);



	//select SW priority
	SET_BIT((DMA2->DMACHANNEL[Copy_StreamID].CR),16);
	SET_BIT((DMA2->DMACHANNEL[Copy_StreamID].CR),17);

	//set direction (MTM or P2M or M2P)
	SET_BIT((DMA2->DMACHANNEL[Copy_StreamID].CR),7);
	CLEAR_BIT((DMA2->DMACHANNEL[Copy_StreamID].CR),6);

	/*select  circular mode*/
	SET_BIT((DMA2->DMACHANNEL[Copy_StreamID].CR),8);

	//SRC and DIS increament
	SET_BIT((DMA2->DMACHANNEL[Copy_StreamID].CR),9);
	SET_BIT((DMA2->DMACHANNEL[Copy_StreamID].CR),10);


	//set size and destnation
	CLEAR_BIT((DMA2->DMACHANNEL[Copy_StreamID].CR),13);
	SET_BIT((DMA2->DMACHANNEL[Copy_StreamID].CR),14);

	CLEAR_BIT((DMA2->DMACHANNEL[Copy_StreamID].CR),11);
	SET_BIT((DMA2->DMACHANNEL[Copy_StreamID].CR),12);

	//disable direct mode
	SET_BIT((DMA2->DMACHANNEL[Copy_StreamID].FCR),2);


	//use fully buffer in circular mode
	SET_BIT((DMA2->DMACHANNEL[Copy_StreamID].FCR),0);
	SET_BIT((DMA2->DMACHANNEL[Copy_StreamID].FCR),1);


	//enable interrupt
	DMA2->DMACHANNEL[Copy_StreamID].CR=(1<<4);


}
void DMA_voidSetAddress(u32 *PTRu32SrcAddress,u32 *PTRu32DesAddress, u32 Copyu32Length, u8 Copy8StreamID )
{
	DMA2->DMACHANNEL[Copy8StreamID].PAR=(u32)PTRu32SrcAddress;

	DMA2->DMACHANNEL[Copy8StreamID].M0AR=(u32)PTRu32DesAddress;
	DMA2->DMACHANNEL[Copy8StreamID].NDTR=(u32)Copyu32Length;


}

void DMA_voidClearFlagChannel0(void)
{
	DMA2->DMA_LIFCR|=((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5));
}

void DMA_voidStreamEnable(u8 Copy_StreamID)
{
	DMA_DMA_voidClearFlagChannel0();
	SET_BIT((DMA2->DMACHANNEL[Copy_StreamID].CR),0);

}

void DMA_void_CallBack(void(*FPTR)(void))
{
	DMA_pToFunction=FPTR;
}

void DMA2_Stream0_IRQHandler(void)
{
	DMA_voidClearFlagChannel0();
	if(DMA_pToFunction!=NULL)
	{
	DMA_pToFunction();
	}

}
