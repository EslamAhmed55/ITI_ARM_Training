#ifndef EXTI_Interface_H_
#define EXTI_Interface_H_





void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t *EXTI_Config);
void MCAL_EXTI_GPIO_DeInit(void);
void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t *EXTI_Config);
#endif