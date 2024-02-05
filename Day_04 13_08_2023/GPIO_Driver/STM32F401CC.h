/*
 * STM32F401CC.h
 *
 *  Created on: Aug 12, 2023
 *      Author: eslam
 */

#ifndef STM32F401CC_H_
#define STM32F401CC_H_

//______________________________________________________________________________-
//Inclides
//______________________________________________________________________________

#include "stdlib.h"
#include "stdint.h"





//______________________________________________________________________________-
//Base addresses for memories
//______________________________________________________________________________

#define 	SRAM						0x20000000UL
#define 	FLASH						0x08000000UL








//______________________________________________________________________________-
//  Base addresses for AHB1 Peripherals
//______________________________________________________________________________

#define		RCC_BASE					       0x40023800UL

#define		GPIOA_BASE					       0x40020000UL
#define		GPIOB_BASE					       0x40020400UL
#define		GPIOC_BASE					       0x40020800UL
#define		GPIOD_BASE					       0x40020C00UL
#define		GPIOE_BASE					       0x40021000UL
#define		GPIOH_BASE					       0x40021C00UL




//______________________________________________________________________________-
//  Base addresses for APB1 Peripherals
//______________________________________________________________________________



//______________________________________________________________________________-
//  Base addresses for APB1 Peripherals
//______________________________________________________________________________



/*********************************************************************************************************************************************/



//______________________________________________________________________________________________
// Peripheral Registers  RCC
//______________________________________________________________________________________________


typedef struct
{
	volatile uint32_t 	CR;
	volatile uint32_t 	PLLCFGR;
	volatile uint32_t 	CFGR;
	volatile uint32_t 	CIR;
	volatile uint32_t 	AHB1RSTR;
	volatile uint32_t 	AHB2RSTR;
	volatile uint32_t 	Reserved1;
	volatile uint32_t 	Reserved2;
	volatile uint32_t 	APB1RSTR;
	volatile uint32_t 	APB2RSTR;
	volatile uint32_t 	Reserved3;
	volatile uint32_t 	Reserved4;
	volatile uint32_t 	AHB1ENR;
	volatile uint32_t 	AHB2ENR;
	volatile uint32_t 	Reserved5;
	volatile uint32_t 	Reserved6;
	volatile uint32_t 	APB1ENR;
	volatile uint32_t 	APB2ENR;
	volatile uint32_t 	Reserved7;
	volatile uint32_t 	Reserved8;
	volatile uint32_t 	AHB1LPENR;
	volatile uint32_t 	AHB2LPENR;
	volatile uint32_t 	Reserved9;
	volatile uint32_t 	Reserved10;
	volatile uint32_t 	APB1LPENR;
	volatile uint32_t 	APB2LPENR;
	volatile uint32_t 	Reserved11;
	volatile uint32_t 	Reserved12;
	volatile uint32_t 	BDCR;
	volatile uint32_t 	CSR;
	volatile uint32_t 	Reserved13;
	volatile uint32_t 	Reserved14;
	volatile uint32_t 	SSCGR;
	volatile uint32_t 	PLLI2S_CFGR;
	volatile uint32_t 	Reserved15;
	volatile uint32_t 	DCKCF_GR;



}RCC_t;





typedef struct
{

	 uint32_t MODER      ;
	 uint32_t OTYPER     ;
	 uint32_t OSPEEDR    ;
	 uint32_t PUPDR      ;
	 uint32_t IDR        ;
	 uint32_t ODR        ;
	 uint32_t BSRR       ;
	 uint32_t LCKR       ;
	 uint32_t AFRL       ;
	 uint32_t AFRH       ;


}GPIO_t;





//______________________________________________________________________________________________
// Peripheral Instants
//______________________________________________________________________________________________

//RCC
#define RCC										((RCC_t *)RCC_BASE)

//GPIOs
#define GPIOA 									((GPIO_t *)GPIOA_BASE)
#define GPIOB 									((GPIO_t *)GPIOB_BASE)
#define GPIOC 									((GPIO_t *)GPIOC_BASE)
#define GPIOD 									((GPIO_t *)GPIOD_BASE)
#define GPIOE 									((GPIO_t *)GPIOE_BASE)
#define GPIOH 									((GPIO_t *)GPIOH_BASE)



//___________________________________________________________________________________________________________
//RCC macros Enable clock
//__________________________________________________________________________________________________________


#define RCC_GPIOA_CLK_ENABLE()		(RCC->APB1ENR |=1<<0)
#define RCC_GPIOB_CLK_ENABLE()		(RCC->APB1ENR |=1<<1)
#define RCC_GPIOC_CLK_ENABLE()		(RCC->APB1ENR |=1<<2)
#define RCC_GPIOD_CLK_ENABLE()		(RCC->APB1ENR |=1<<3)
#define RCC_GPIOE_CLK_ENABLE()		(RCC->APB1ENR |=1<<4)
#define RCC_GPIOH_CLK_ENABLE()		(RCC->APB1ENR |=1<<7)




//___________________________________________________________________________________________________________
//RCC macros Disable clock
//__________________________________________________________________________________________________________



#define RCC_GPIOA_CLK_DISABLE()		(RCC->APB1ENR &= ~ (0<<0))
#define RCC_GPIOB_CLK_DISABLE()		(RCC->APB1ENR &= ~ (0<<1))
#define RCC_GPIOC_CLK_DISABLE()		(RCC->APB1ENR &= ~ (0<<2))
#define RCC_GPIOD_CLK_DISABLE()		(RCC->APB1ENR &= ~ (0<<3))
#define RCC_GPIOE_CLK_DISABLE()		(RCC->APB1ENR &= ~ (0<<4))
#define RCC_GPIOH_CLK_DISABLE()		(RCC->APB1ENR &= ~ (0<<7))











#endif /* STM32F401CC_H_ */
