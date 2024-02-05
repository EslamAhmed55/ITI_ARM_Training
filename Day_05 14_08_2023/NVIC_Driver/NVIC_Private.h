/*
 * NVIC_Private.h
 *
 *  Created on: Aug 15, 2023
 *      Author: eslam
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#define  NVIC_BASE_ADDRESS			0xE000E100

#define  SCB_BASE_ADDRESS			0xE000E008


typedef struct
{

	volatile u32 NVIC_ISER[8+24] ;
	volatile u32 NVIC_ICER[8+24] ;
	volatile u32 NVIC_ISPR[8+24] ;
	volatile u32 NVIC_ICPR[8+24] ;
	volatile u32 NVIC_IABR[8+56] ;
	volatile u32 NVIC_IPR[4*64] ;


}NVIC_t;


typedef struct
{

		  volatile u8  SCB_ACTLR [415]    ;
		  volatile u8  SCB_CPUID     ;
		  volatile u8  SCB_VTOR     ;
		  volatile u8  SCB_AIRCR;
		  volatile u8  SCB_SCR			;
		  volatile u8  SCB_CCR          ;
		  volatile u8  SCB_SHPR1        ;
		  volatile u8  SCB_SHPR2        ;
		  volatile u8  SCB_SHPR3        ;
		  volatile u8  SCB_SHCSR        ;
		  volatile u8  SCB_CFSR         ;
		  volatile u8  SCB_HFSR[2]      ;
		  volatile u8  SCB_MMAR         ;
		  volatile u8  SCB_BFAR         ;
		  volatile u8  SCB_AFSR         ;


}SCB_t;

#define SCB				((SCB_t *)SCB_BASE_ADDRESS)
#define NVIC				((NVIC_t *)NVIC_BASE_ADDRESS)

#define VEC_KEY			0xFA05

#define	NVIC_ISER0		(volatile u32*)(NVIC_BASE_ADDRESS+0x0)
#define	NVIC_ISER01     (volatile u32*)(NVIC_BASE_ADDRESS+0x4)
#define	NVIC_ISER2      (volatile u32*)(NVIC_BASE_ADDRESS+0x8)


#endif /* NVIC_PRIVATE_H_ */
