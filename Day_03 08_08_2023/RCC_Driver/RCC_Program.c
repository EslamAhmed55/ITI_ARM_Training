/****************************************************************************/
/* Driver  : RCC Driver                                                     */
/* Author  : Eslam Ahmed                                                 */
/* Version : V 1.0                                                          */
/* Description :                                                            */
/****************************************************************************/

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"


#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"



/*********************************************************************************/
/* Api Name       :  configure_PLL                                                    */
/* Parameters in  :     uint32_t pllm, uint32_t plln, uint32_t pllp, uint32_t pllq   */
/* Parameters out :  non                                                            */
/* Description    : Function to configure the RCC_PLLCFGR register					*/
/*********************************************************************************/

void configure_PLL(uint32_t pllm, uint32_t plln, uint32_t pllp, uint32_t pllq)
{
   // Configure the PLL source and division factors
    RCC->PLLCFGR = (pllm << RCC_PLLCFGR_PLLM_Pos) |
                   (plln << RCC_PLLCFGR_PLLN_Pos) |
                   ( pllp<< RCC_PLLCFGR_PLLP_Pos) |
                   (pllq << RCC_PLLCFGR_PLLQ_Pos);
}



void RCC_voidInitSysClc(void)
{
	#if RCC_CLK_SRC == HSI
		/*
		Bit 0 HSION: Internal high-speed clock enable
			Set and cleared by software.
			Set by hardware to force the HSI oscillator ON when leaving the Stop or Standby mode or in 
			case of a failure of the HSE oscillator used directly or indirectly as the system clock. This bit 
			cannot be cleared if the HSI is used directly or indirectly as the system clock.
			0: HSI oscillator OFF
			1: HSI oscillator ON
		
		*/
		SET_BIT(RCC->CR , HSI_ON);
		
		/*
		
		Bits 1:0 SW: System clock switch
Set and cleared by software to select the system clock source.
Set by hardware to force the HSI selection when leaving the Stop or Standby mode or in 
case of failure of the HSE oscillator used directly or indirectly as the system clock.
00: HSI oscillator selected as system clock
01: HSE oscillator selected as system clock
10: PLL selected as system clock
11: not allowed
*/
		CLR_BIT(RCC->CFGR , 0);
		CLR_BIT(RCC->CFGR ,1);
	
	#elif RCC_CLK_SRC == HSE
	
	/*
	Bit 16 HSEON: HSE clock enable
Set and cleared by software.
Cleared by hardware to stop the HSE oscillator when entering Stop or Standby mode. This 
bit cannot be reset if the HSE oscillator is used directly or indirectly as the system clock.
0: HSE oscillator OFF
1: HSE oscillator ON
*/
		SET_BIT(RCC->CR , HSE_ON);
		/*
		Bits 1:0 SW: System clock switch
Set and cleared by software to select the system clock source.
Set by hardware to force the HSI selection when leaving the Stop or Standby mode or in 
case of failure of the HSE oscillator used directly or indirectly as the system clock.
00: HSI oscillator selected as system clock
01: HSE oscillator selected as system clock
10: PLL selected as system clock
11: not allowed
		*/
		SET_BIT(RCC->CFGR , 0);
		CLR_BIT(RCC->CFGR ,1);

	
	#elif RCC_CLK_SRC == PLL
	
	SET_BIT(RCC->CR , SET_PLL);
	SET(RCC->PLLCFGR,PLL_Source_HSI);
	void configure_PLL(RCC_PLLCFGR_PLLM_DIV2,RCC_PLLCFGR_PLLN_MUL192,RCC_PLLCFGR_PLLP2,RCC_PLLCFGR_PLLQ2);
	
	#else
		#error "Configuration parameters is not supported"
	
}



/*********************************************************************************/
/* Api Name       :                                                              */
/* Parameters in  :                                                              */
/* Parameters out :                                                              */
/* Description    :                                                              */
/*********************************************************************************/
void RCC_voidEnablePerpheralClk (u8 Copy_u8BusId ,u8 Copy_u8PeripheralId)
{
	if((Copy_u8BusId >APB2) || (Copy_u8PeripheralId > 31))
	{
		/*Do Nothing*/
	}
	
	
	else
	{
		switch(Copy_u8BusId)
		{
			case AHB1:
				SET_BIT(RCC->AHB1ENR ,Copy_u8PeripheralId);
			break;
			
			case AHB2:
				if(Copy_u8PeripheralId != 7)
				{
					#error "Configuration parameters is not supported"
				}
			break;
			
			case APB1: 
				SET_BIT(RCC->APB1ENR ,Copy_u8PeripheralId);
			break;
			
			case APB2:
				SET_BIT(RCC0->APB2ENR ,Copy_u8PeripheralId);
			break;
			
			case AHB1RSTR:
				SET_BIT(RCC->AHB1RSTR ,Copy_u8PeripheralId);
			break;
			case AHB2RSTR:
				SET_BIT(RCC->AHB2RSTR ,Copy_u8PeripheralId);
			break;
			
			case APB1RSTR:
				SET_BIT(RCC->APB1RSTR ,Copy_u8PeripheralId);
			break;
			
			case APB2RSTR:
				SET_BIT(RCC->APB2RSTR ,Copy_u8PeripheralId);
			break;
			
			default;
			break;
			
		}
	}
}




/*********************************************************************************/
/* Api Name       :                                                              */
/* Parameters in  :                                                              */
/* Parameters out :                                                              */
/* Description    :                                                              */
/*********************************************************************************/


void RCC_voidDisablePerpheralClk (u8 Copy_u8BusId ,u8 Copy_u8PeripheralId)
{
	if((Copy_u8BusId >APB2) || (Copy_u8PeripheralId > 31))
	{
		/*Do Nothing*/
	}
	
	
	else
	{
		switch(Copy_u8BusId)
		{
			case AHB1:
				CLR_BIT(RCC->AHB1ENR ,Copy_u8PeripheralId);
			break;
			
			case AHB2:
				if(Copy_u8PeripheralId != 7)
				{
					#error "Configuration parameters is not supported"
				}
			break;
			
			case APB1: 
				CLR_BIT(RCC->APB1ENR ,Copy_u8PeripheralId);
			break;
			
			case APB2:
				CLR_BIT(RCC0->APB2ENR ,Copy_u8PeripheralId);
			break;
			
			case AHB1RSTR:
				CLR_BIT(RCC->AHB1RSTR ,Copy_u8PeripheralId);
			break;
			case AHB2RSTR:
				CLR_BIT(RCC->AHB2RSTR ,Copy_u8PeripheralId);
			break;
			
			case APB1RSTR:
				CLR_BIT(RCC->APB1RSTR ,Copy_u8PeripheralId);
			break;
			
			case APB2RSTR:
				CLR_BIT (RCC->APB2RSTR ,Copy_u8PeripheralId);
			break;
			
			default;
			break;
			
		}
	}
}











