
#ifndef EXTI_Config_H_
#define EXTI_Config_H_


//****************************************************
// Interrupt Vector Table
//************************************************8****
#define				EXTI0_IRQ		6
#define				EXTI1_IRQ		7
#define				EXTI2_IRQ		8
#define				EXTI3_IRQ		9
#define				EXTI4_IRQ		10
#define				EXTI5_IRQ		23
#define				EXTI6_IRQ		23
#define				EXTI7_IRQ		23
#define				EXTI8_IRQ		23
#define				EXTI9_IRQ		23
#define				EXTI10_IRQ		40
#define				EXTI11_IRQ		40
#define				EXTI12_IRQ		40
#define				EXTI13_IRQ		40
#define				EXTI14_IRQ		40
#define				EXTI15_IRQ		40

#define				USART1_IRQ		37
#define				USART2_IRQ		38
#define				USART3_IRQ		39

#define				SPI1_IRQ		35
#define				SPI2_IRQ		36

#define				I2C1_EV_IRQ		31
#define				I2C1_ER_IRQ		32
#define				I2C2_EV_IRQ		33
#define				I2C2_ER_IRQ		34


// Mapping GPIO PIN Number with EXTI Line Number
typedef struct
{

	uint16_t EXTI_InputLineNumber;
	GPIO_Typedef *GPIO_Port;
	uint16_t GPIO_PIN;
	uint8_t IVT_IRQ_Number;


}EXTI_GPIO_Mapping_t;


typedef struct
{
	EXTI_GPIO_Mapping_t 	EXTI_PIN; //Specifies the External interrupt GPIO Mapping
	                                  //this parameter must be based on reference EXTI_define
	uint8_t             	Trigger_Case;//Specifies RISING or FALLING or BOTH Trigger
										//this parameter must be based on reference EXTI_Trigger_define
	uint8_t					 IRQ_EN ; //Enable or Disable The EXTI IRQ (that will Enable The IRQ MASK in EXTI and also on NVIC Interrupt
									//this parameter must be based on reference EXTI_IRQ_define
	void (*P_IRQ_CallBack)(void);   //Set the C Function() Which Will be called once the IRQ Happen
}EXTI_PinConfig_t;




#define EXTI0              0
#define EXTI1              1
#define EXTI2              2
#define EXTI3              3
#define EXTI4              4
#define EXTI5              5
#define EXTI6              6
#define EXTI7              7
#define EXTI8              8
#define EXTI9              9
#define EXTI10             10
#define EXTI11             11
#define EXTI12             12
#define EXTI13             13
#define EXTI14             14
#define EXTI15             15


/*
 * =================================================================
 *
 *               		Reference Macros
 *
 * =================================================================
 *
 */
//reference EXTI_define
//EXTI0
#define EXTI0PA0                        (EXTI_GPIO_Mapping_t){EXTI0 , GPIOA , GPIO_PIN_0 , EXTI0_IRQ}
#define EXTI0PB0                        (EXTI_GPIO_Mapping_t){EXTI0 , GPIOA , GPIO_PIN_0 , EXTI0_IRQ}
#define EXTI0PC0                        (EXTI_GPIO_Mapping_t){EXTI0 , GPIOA , GPIO_PIN_0 , EXTI0_IRQ}
#define EXTI0PD0                        (EXTI_GPIO_Mapping_t){EXTI0 , GPIOA , GPIO_PIN_0 , EXTI0_IRQ}


//EXTI1
#define EXTI1PA1                        (EXTI_GPIO_Mapping_t){EXTI1 , GPIOA , GPIO_PIN_1 , EXTI1_IRQ}
#define EXTI1PB1                        (EXTI_GPIO_Mapping_t){EXTI1 , GPIOA , GPIO_PIN_1 , EXTI1_IRQ}
#define EXTI1PC1                        (EXTI_GPIO_Mapping_t){EXTI1 , GPIOA , GPIO_PIN_1 , EXTI1_IRQ}
#define EXTI1PD1                        (EXTI_GPIO_Mapping_t){EXTI1 , GPIOA , GPIO_PIN_1 , EXTI1_IRQ}


//EXTI2
#define EXTI2PA2                        (EXTI_GPIO_Mapping_t){EXTI2 , GPIOA , GPIO_PIN_2 , EXTI2_IRQ}
#define EXTI2PB2                        (EXTI_GPIO_Mapping_t){EXTI2 , GPIOA , GPIO_PIN_2 , EXTI2_IRQ}
#define EXTI2PC2                        (EXTI_GPIO_Mapping_t){EXTI2 , GPIOA , GPIO_PIN_2 , EXTI2_IRQ}
#define EXTI2PD2                        (EXTI_GPIO_Mapping_t){EXTI2 , GPIOA , GPIO_PIN_2 , EXTI2_IRQ}


//EXTI3
#define EXTI3PA3                        (EXTI_GPIO_Mapping_t){EXTI3 , GPIOA , GPIO_PIN_3 , EXTI3_IRQ}
#define EXTI3PB3                        (EXTI_GPIO_Mapping_t){EXTI3 , GPIOA , GPIO_PIN_3 , EXTI3_IRQ}
#define EXTI3PC3                        (EXTI_GPIO_Mapping_t){EXTI3 , GPIOA , GPIO_PIN_3 , EXTI3_IRQ}
#define EXTI3PD3                        (EXTI_GPIO_Mapping_t){EXTI3 , GPIOA , GPIO_PIN_3 , EXTI3_IRQ}


//EXTI4
#define EXTI4PA4                        (EXTI_GPIO_Mapping_t){EXTI4 , GPIOA , GPIO_PIN_4 , EXTI4_IRQ}
#define EXTI4PB4                        (EXTI_GPIO_Mapping_t){EXTI4 , GPIOA , GPIO_PIN_4 , EXTI4_IRQ}
#define EXTI4PC4                        (EXTI_GPIO_Mapping_t){EXTI4 , GPIOA , GPIO_PIN_4 , EXTI4_IRQ}
#define EXTI4PD4                        (EXTI_GPIO_Mapping_t){EXTI4 , GPIOA , GPIO_PIN_4 , EXTI4_IRQ}


//EXTI5
#define EXTI5PA5                        (EXTI_GPIO_Mapping_t){EXTI5 , GPIOA , GPIO_PIN_5 , EXTI5_IRQ}
#define EXTI5PB5                        (EXTI_GPIO_Mapping_t){EXTI5 , GPIOA , GPIO_PIN_5 , EXTI5_IRQ}
#define EXTI5PC5                        (EXTI_GPIO_Mapping_t){EXTI5 , GPIOA , GPIO_PIN_5 , EXTI5_IRQ}
#define EXTI5PD5                        (EXTI_GPIO_Mapping_t){EXTI5 , GPIOA , GPIO_PIN_5 , EXTI5_IRQ}




//EXTI10
#define EXTI10PA10                      (EXTI_GPIO_Mapping_t){EXTI10 , GPIOA , GPIO_PIN_10 , EXTI10_IRQ}
#define EXTI10PB10                      (EXTI_GPIO_Mapping_t){EXTI10 , GPIOA , GPIO_PIN_10 , EXTI10_IRQ}
#define EXTI10PC10                      (EXTI_GPIO_Mapping_t){EXTI10 , GPIOA , GPIO_PIN_10 , EXTI10_IRQ}
#define EXTI10PD10                      (EXTI_GPIO_Mapping_t){EXTI10 , GPIOA , GPIO_PIN_10 , EXTI10_IRQ}


//EXTI11
#define EXTI11PA11                      (EXTI_GPIO_Mapping_t){EXTI11 , GPIOA , GPIO_PIN_11 , EXTI11_IRQ}
#define EXTI11PB11                      (EXTI_GPIO_Mapping_t){EXTI11 , GPIOA , GPIO_PIN_11 , EXTI11_IRQ}
#define EXTI11PC11                      (EXTI_GPIO_Mapping_t){EXTI11 , GPIOA , GPIO_PIN_11 , EXTI11_IRQ}
#define EXTI11PD11                      (EXTI_GPIO_Mapping_t){EXTI11 , GPIOA , GPIO_PIN_11 , EXTI11_IRQ}


//EXTI12
#define EXTI12PA12                      (EXTI_GPIO_Mapping_t){EXTI12 , GPIOA , GPIO_PIN_12 , EXTI12_IRQ}
#define EXTI12PB12                      (EXTI_GPIO_Mapping_t){EXTI12 , GPIOA , GPIO_PIN_12 , EXTI12_IRQ}
#define EXTI12PC12                      (EXTI_GPIO_Mapping_t){EXTI12 , GPIOA , GPIO_PIN_12 , EXTI12_IRQ}
#define EXTI12PD12                      (EXTI_GPIO_Mapping_t){EXTI12 , GPIOA , GPIO_PIN_12 , EXTI12_IRQ}


//EXTI13
#define EXTI13PA13                      (EXTI_GPIO_Mapping_t){EXTI13 , GPIOA , GPIO_PIN_13 , EXTI13_IRQ}
#define EXTI13PB13                      (EXTI_GPIO_Mapping_t){EXTI13 , GPIOA , GPIO_PIN_13 , EXTI13_IRQ}
#define EXTI13PC13                      (EXTI_GPIO_Mapping_t){EXTI13 , GPIOA , GPIO_PIN_13 , EXTI13_IRQ}
#define EXTI13PD13                      (EXTI_GPIO_Mapping_t){EXTI13 , GPIOA , GPIO_PIN_13 , EXTI13_IRQ}


//EXTI14
#define EXTI14PA14                      (EXTI_GPIO_Mapping_t){EXTI14 , GPIOA , GPIO_PIN_14 , EXTI14_IRQ}
#define EXTI14PB14                      (EXTI_GPIO_Mapping_t){EXTI14 , GPIOA , GPIO_PIN_14 , EXTI14_IRQ}
#define EXTI14PC14                      (EXTI_GPIO_Mapping_t){EXTI14 , GPIOA , GPIO_PIN_14 , EXTI14_IRQ}
#define EXTI14PD14                      (EXTI_GPIO_Mapping_t){EXTI14 , GPIOA , GPIO_PIN_14 , EXTI14_IRQ}


//EXTI15
#define EXTI15PA15                      (EXTI_GPIO_Mapping_t){EXTI15 , GPIOA , GPIO_PIN_15 , EXTI15_IRQ}
#define EXTI15PB15                      (EXTI_GPIO_Mapping_t){EXTI15 , GPIOA , GPIO_PIN_15 , EXTI15_IRQ}
#define EXTI15PC15                      (EXTI_GPIO_Mapping_t){EXTI15 , GPIOA , GPIO_PIN_15 , EXTI15_IRQ}
#define EXTI15PD15                      (EXTI_GPIO_Mapping_t){EXTI15 , GPIOA , GPIO_PIN_15 , EXTI15_IRQ}

//========================================================================
//Reference EXTI_Trigger_define

#define EXTI_Trigger_RISING							0
#define EXTI_Trigger_FALLING						1
#define EXTI_Trigger_RisingAndFalling				2


//Reference EXTI_IRQ_define

#define EXTI_IRQ_Enable				1
#define EXTI_IRQ_Enable				0





#endif