#include "Stm32_F103C6_GPIO-Driver.h"
#include "Stm32_F103C6_EXTI-Driver.h"
#include "Stm32_F103x6.h"




void clock_int()
{
	// Enable clock GPIOA, GBIOB
		RCC_GPIOA_CLK_EN();
		RCC_GPIOB_CLK_EN();
}


void EXTI0_callBack(){

	if(MCAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0)==1)
	{
		MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);
		MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);

	}



}

void EXTI1_callBack()
{
	if(MCAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1)==1)
	{
		MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
		MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0);

	}
}

voidm main()
{
	clock_int();


	EXTI_PinConfig_t EXTI_CFG ;
	EXTI_CFG.EXTI_PIN = EXTI0PB0;
	EXTI_CFG.trigger_case = EXTI_Trigger_RISING;
	EXTI_CFG.P_IRQ_CallBack = EXTI0_CallBack;
	EXTI_CFG.IRQ_EN = EXTI_IRQ_Enable;
	MCAL_EXTI_GPIO_Init(&EXTI_CFG);
	
	EXTI_PinConfig_t EXTI_CFG2 ;
		EXTI_CFG2.EXTI_PIN = EXTI0PB1;
		EXTI_CFG2.trigger_case = EXTI_Trigger_RISING;
		EXTI_CFG2.P_IRQ_CallBack = EXTI1_CallBack;
		EXTI_CFG2.IRQ_EN = EXTI_IRQ_Enable;
		MCAL_EXTI_GPIO_Init(&EXTI_CFG2);

	


}
