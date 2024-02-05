/*
 * DMA_Private.h
 *
 *  Created on: Aug 31, 2023
 *      Author: eslam
 */

#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

typedef struct
{
	volatile u32 CR        ;
	volatile u32 NDTR      ;
	volatile u32 PAR       ;
	volatile u32 M0AR      ;
	volatile u32 M1AR      ;
	volatile u32 FCR       ;
	volatile u32 NDTR       ;

}DMACHANNEL_t;




typedef struct
{
	volatile u32 DMA_LISR                  ;
	volatile u32 DMA_HISR                  ;
	volatile u32 DMA_LIFCR                 ;
	volatile u32 DMA_HIFCR                 ;
	volatile DMACHANNEL_t DMACHANNEL[8]    ;
} DMA_T;

#define DMA_BASE_ADDRESS		0x40026000

#define DAM1			((volatile DMA_T*)DMA_BASE_ADDRESS)

#define DAM2			((volatile DMA_T*)0x40026400)

#endif /* DMA_PRIVATE_H_ */
