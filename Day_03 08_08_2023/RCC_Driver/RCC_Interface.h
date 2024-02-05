/****************************************************************************/
/* Driver  : RCC Driver                                                     */
/* Author  : Eslam Ahmed                                                 */
/* Version : V 1.0                                                          */
/* Description :                                                            */
/****************************************************************************/
/*File Gaurd*/
#ifndef RCC_RCC_INTERFACE_H
#define RCC_RCC_INTERFACE_H


void RCC_voidInitSysClc(void);
void RCC_voidEnablePerpheralClk (u8 Copy_u8BusId ,u8 Copy_u8PeripheralId);
void RCC_voidDisablePerpheralClk(u8 Copy_u8BusId ,u8 Copy_u8PeripheralId);
void configure_PLL(uint32_t pllm, uint32_t plln, uint32_t pllp, uint32_t pllq);





/*Interface Macros*/
#define AHB1         0
#define AHB2         1
#define APB1         2
#define APB1         3

#endif


