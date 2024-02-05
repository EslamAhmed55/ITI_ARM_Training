/****************************************************************************/
/* Driver  : RCC Driver                                                     */
/* Author  : Eslam Ahmed                                                 */
/* Version : V 1.0                                                          */
/* Description :                                                            */
/****************************************************************************/
/*File Gaurd*/
#ifndef RCC_RCC_PRIVATE_H
#define RCC_RCC_PRIVATE_H

/*Base address of RCC is 0x40023800*/
#define RCC_BASE								0x40023800UL



volatile uint32_t 	Reserved;

typedef struct
{
	volatile uint32_t 	CR;
	volatile uint32_t 	PLLCFGR;
	volatile uint32_t 	CFGR;
	volatile uint32_t 	CIR;
	volatile uint32_t 	AHB1RSTR;
	volatile uint32_t 	AHB2RSTR;
	volatile uint32_t 	Reserved;
	volatile uint32_t 	Reserved;
	volatile uint32_t 	APB1RSTR;
	volatile uint32_t 	APB2RSTR;
	volatile uint32_t 	Reserved;
	volatile uint32_t 	Reserved;
	volatile uint32_t 	AHB1ENR;
	volatile uint32_t 	AHB2ENR;
	volatile uint32_t 	Reserved;
	volatile uint32_t 	Reserved;
	volatile uint32_t 	APB1ENR;
	volatile uint32_t 	APB2ENR;
	volatile uint32_t 	Reserved;
	volatile uint32_t 	Reserved;
	volatile uint32_t 	AHB1LPENR;
	volatile uint32_t 	AHB2LPENR;
	volatile uint32_t 	Reserved;
	volatile uint32_t 	Reserved;
	volatile uint32_t 	APB1LPENR;
	volatile uint32_t 	APB2LPENR;
	volatile uint32_t 	Reserved;
	volatile uint32_t 	Reserved;
	volatile uint32_t 	BDCR;
	volatile uint32_t 	CSR;
	volatile uint32_t 	Reserved;
	volatile uint32_t 	Reserved;
	volatile uint32_t 	SSCGR;
	volatile uint32_t 	PLLI2S_CFGR;
	volatile uint32_t 	Reserved;
	volatile uint32_t 	DCKCF_GR;
	
	
	
}RCC;

#define RCC										((RCC_Typedef *)RCC_BASE)





/*Private Macros*/
#define HSI    0
#define HSE    1
#define PLL    2

#endif




