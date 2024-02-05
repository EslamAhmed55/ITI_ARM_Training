/****************************************************************************/
/* Driver  : RCC Driver                                                     */
/* Author  : Eslam Ahmed                                                 */
/* Version : V 1.0                                                          */
/* Description :                                                            */
/****************************************************************************/

/*File Gaurd*/
#ifndef RCC_RCC_CONFIG_H
#define RCC_RCC_CONFIG_H


/*RCC_CLK_SRC*/
#define  RCC_CLK_SRC    HSI



#define HSI_ON			0

#define HSE_ON			16



/*PLL Configurations*/

/*
1-From RCC clock control register (RCC_CR)
	Bit 24 PLLON: Main PLL (PLL) enable
Set and cleared by software to enable PLL.
Cleared by hardware when entering Stop or Standby mode. This bit cannot be reset if PLL 
clock is used as the system clock.
0: PLL OFF
1: PLL ON
*/





#define SET_PLL			24










#define RCC_PLLCFGR_PLLM_Pos		0
#define RCC_PLLCFGR_PLLN_Pos		6
#define RCC_PLLCFGR_PLLP_Pos		16
#define RCC_PLLCFGR_PLLQ_Pos		24







/*
2-From  RCC PLL configuration register (RCC_PLLCFGR)
	Bit 22 PLLSRC: Main PLL(PLL) and audio PLL (PLLI2S) entry clock source
Set and cleared by software to select PLL and PLLI2S clock source. This bit can be written 
only when PLL and PLLI2S are disabled.
0: HSI clock selected as PLL and PLLI2S clock entry
1: HSE oscillator clock selected as PLL and PLLI2S clock entry


*/

#define PLL_Source_HSI			0
#define PLL_Source_HSE			1





/*
3-From  RCC PLL configuration register (RCC_PLLCFGR)
	
	This register is used to configure the PLL clock outputs according to the formulas:
	• f(VCO clock) = f(PLL clock input) × (PLLN / PLLM)
		
		Bits 5:0 PLLM: Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
		Set and cleared by software to divide the PLL and PLLI2S input clock before the VCO. 
		These bits can be written only when the PLL and PLLI2S are disabled.
		Caution: The software has to set these bits correctly to ensure that the VCO input frequency 
		ranges from 1 to 2 MHz. It is recommended to select a frequency of 2 MHz to limit 
		PLL jitter. 
		VCO input frequency = PLL input clock frequency / PLLM with 2 ≤ PLLM ≤ 63
		000000: PLLM = 0, wrong configuration
		000001: PLLM = 1, wrong configuration
		000010: PLLM = 2
		000011: PLLM = 3
		000100: PLLM = 4
...
		111110: PLLM = 62
		111111: PLLM = 63
*/

#define RCC_PLLCFGR_PLLM_DIV2		(uint32_t)0x2

#define RCC_PLLCFGR_PLLM_DIV3		(uint32_t)0x3
#define RCC_PLLCFGR_PLLM_DIV4		(uint32_t)0x4
#define RCC_PLLCFGR_PLLM_DIV5		(uint32_t)0x5
#define RCC_PLLCFGR_PLLM_DIV6		(uint32_t)0x6
#define RCC_PLLCFGR_PLLM_DIV7		(uint32_t)0x7

#define RCC_PLLCFGR_PLLM_DIV63		(uint32_t)0x3F




/*

4-From  RCC PLL configuration register (RCC_PLLCFGR)
Bits 14:6 PLLN: Main PLL (PLL) multiplication factor for VCO
Set and cleared by software to control the multiplication factor of the VCO. These bits can 
be written only when PLL is disabled. Only half-word and word accesses are allowed to 
write these bits.
Caution: The software has to set these bits correctly to ensure that the VCO output 
frequency is between 192 and 432 MHz. (check also Section 6.3.20: RCC PLLI2S 
configuration register (RCC_PLLI2SCFGR))
VCO output frequency = VCO input frequency × PLLN with 192 ≤ PLLN ≤ 432
000000000: PLLN = 0, wrong configuration
000000001: PLLN = 1, wrong configuration
...
...
110110000: PLLN = 432
110110001: PLLN = 433, wrong configuration
...
111111111: PLLN = 511, wrong configuration
*/

#define  RCC_PLLCFGR_PLLN_MUL192				(uint32_t)0xC0
#define  RCC_PLLCFGR_PLLN_MUL432				(uint32_t)0x1B0


/*
5-From  RCC PLL configuration register (RCC_PLLCFGR)

Bits 17:16 PLLP: Main PLL (PLL) division factor for main system clock
Set and cleared by software to control the frequency of the general PLL output clock. These 
bits can be written only if PLL is disabled.
Caution: The software has to set these bits correctly not to exceed 84 MHz on this domain.
PLL output clock frequency = VCO frequency / PLLP with PLLP = 2, 4, 6, or 8
00: PLLP = 2
01: PLLP = 4
10: PLLP = 6
11: PLLP = 8
*/

#define  RCC_PLLCFGR_PLLP2				(uint32_t)0x00
#define  RCC_PLLCFGR_PLLP4				(uint32_t)0x01
#define  RCC_PLLCFGR_PLLP6				(uint32_t)0x10
#define  RCC_PLLCFGR_PLLP8				(uint32_t)0x11


/*
6-From  RCC PLL configuration register (RCC_PLLCFGR)

Bits 27:24 PLLQ: Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator 
clocks
Set and cleared by software to control the frequency of USB OTG FS clock, the random 
number generator clock and the SDIO clock. These bits should be written only if PLL is 
disabled.
Caution: The USB OTG FS requires a 48 MHz clock to work correctly. The SDIO and the 
random number generator need a frequency lower than or equal to 48 MHz to work 
correctly.
USB OTG FS clock frequency = VCO frequency / PLLQ with 2 ≤PLLQ ≤15
0000: PLLQ = 0, wrong configuration
0001: PLLQ = 1, wrong configuration
0010: PLLQ = 2
0011: PLLQ = 3
0100: PLLQ = 4
...
1111: PLLQ = 15
*/


#define RCC_PLLCFGR_PLLQ2					0x2					
#define RCC_PLLCFGR_PLLQ3					0x3					
#define RCC_PLLCFGR_PLLQ4					0x4					
#define RCC_PLLCFGR_PLLQ5					0x5					
#define RCC_PLLCFGR_PLLQ6					0x6					
#define RCC_PLLCFGR_PLLQ7					0x7					
#define RCC_PLLCFGR_PLLQ8					0x8					
#define RCC_PLLCFGR_PLLQ9					0x9					
#define RCC_PLLCFGR_PLLQ10					0xA					
#define RCC_PLLCFGR_PLLQ11					0xB					
#define RCC_PLLCFGR_PLLQ12					0xC					
#define RCC_PLLCFGR_PLLQ13					0xD					
#define RCC_PLLCFGR_PLLQ14					0xE					
#define RCC_PLLCFGR_PLLQ15					0xF					




#endif



