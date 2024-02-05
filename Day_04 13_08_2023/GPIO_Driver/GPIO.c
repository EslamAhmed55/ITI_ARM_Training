/*
 * GPIO.c
 *
 *  Created on: Aug 12, 2023
 *      Author: eslam
 */


/*		Gerneric Varibles*/



/*********************************************************************************/
/* Api Name       :                                      			                */
/* Parameters in  :     														   */
/* Parameters out :                                                              */
/* Description    : 																*/
/*********************************************************************************/





#include "GPIO.h"

uint8_t Get_PIN_Position(uint16_t PinNumber)
{
	switch (PinNumber)
	{
	case GPIO_PIN_0:
		return 0 ;
		break ;
	case GPIO_PIN_1:
		return 1 ;
		break ;
	case GPIO_PIN_2:
		return 2 ;
		break ;
	case GPIO_PIN_3:
		return 3 ;
		break ;

	case GPIO_PIN_4:
		return 4 ;
		break ;


	case GPIO_PIN_5:
		return 5 ;
		break ;

	case GPIO_PIN_6:
		return 6 ;
		break ;

	case GPIO_PIN_7:
		return  7;
		break ;


	case GPIO_PIN_8:
		return 8 ;
		break ;
	case GPIO_PIN_9:
		return 9 ;
		break ;

	case GPIO_PIN_10:
		return 10 ;
		break ;

	case GPIO_PIN_11:
		return 11 ;
		break ;

	case GPIO_PIN_12:
		return 12 ;
		break ;


	case GPIO_PIN_13:
		return 13 ;
		break ;

	case GPIO_PIN_14:
		return 14 ;
		break ;

	case GPIO_PIN_15:
		return 15 ;
		break ;



	}

	return 0 ;
}






uint8_t Get_AFRLH_SET(uint16_t PinNumber)
{
	switch (PinNumber)
	{
	case AFIO0:
		return 0x0 ;
		break ;
	case AFIO1:
		return 0x1 ;
		break ;
	case AFIO2:
		return 0x2 ;
		break ;
	case AFIO3:
		return 0x3 ;
		break ;

	case AFIO4:
		return 0x4 ;
		break ;


	case AFIO5:
		return 0x5 ;
		break ;

	case AFIO6:
		return 0x6 ;
		break ;

	case AFIO7:
		return  0x7;
		break ;


	case AFIO8:
		return 0x8 ;
		break ;
	case AFIO9:
		return 0x9 ;
		break ;

	case AFIO10:
		return 0xA ;
		break ;

	case AFIO11:
		return 0xB ;
		break ;

	case AFIO12:
		return 0xC ;
		break ;


	case AFIO13:
		return 0xD ;
		break ;

	case AFIO14:
		return 0xE ;
		break ;

	case AFIO15:
		return 0xF ;
		break ;



	}

	return 0 ;
}


void MCAL_GPIO_SetSpeed (GPIO_t *GPIOx ,GPIO_PinConfig *PinConfig)
{
	if(PinConfig->GPIO_OSPEEDR ==GPIO_Low_speed)
	{
		GPIOx->OSPEEDR &= ~((1 << Get_PIN_Position(PinConfig->GPIO_PinNumber)) | (1 <<(Get_PIN_Position(PinConfig->GPIO_PinNumber)+1)));

	}

	else if(PinConfig->GPIO_OSPEEDR == GPIO_Medium_speed)
	{
		GPIOx->OSPEEDR &= ~((1 << Get_PIN_Position(PinConfig->GPIO_PinNumber)) | (1 <<(Get_PIN_Position(PinConfig->GPIO_PinNumber)+1)));
		GPIOx->OSPEEDR |= 1<<(Get_PIN_Position(PinConfig->GPIO_PinNumber)*2);
	}

	else if(PinConfig->GPIO_OSPEEDR == GPIO_High_speed)
	{
		GPIOx->OSPEEDR &= ~((1 << Get_PIN_Position(PinConfig->GPIO_PinNumber)) | (1 <<(Get_PIN_Position(PinConfig->GPIO_PinNumber)+1)));
		GPIOx->OSPEEDR |= 2<<(Get_PIN_Position(PinConfig->GPIO_PinNumber)*2);
	}

	else if(PinConfig->GPIO_OSPEEDR == GPIO_VeryHigh_speed)
	{
		GPIOx->OSPEEDR &= ~((1 << Get_PIN_Position(PinConfig->GPIO_PinNumber)) | (1 <<(Get_PIN_Position(PinConfig->GPIO_PinNumber)+1)));
		GPIOx->OSPEEDR |= 3<<(Get_PIN_Position(PinConfig->GPIO_PinNumber)*2);
	}
}




/*********************************************************************************/
/* Api Name       :  MCAL_GPIO_Init                                                    */
/* Parameters in  :  GPIOX where x can be (A,B,C,D,E)  to select the gpio pripher 	  */
/* Parameters in  :  pinconfig is apointer to the GPIO_pinconfig_t struture that contains  all 	  */
/* Parameters out :  non                                                            	*/
/* Description    : initialize the GPIO pin  to a specified parameters					*/
/*********************************************************************************/



void MCAL_GPIO_Init(GPIO_t *GPIOx, GPIO_PinConfig *PinConfig)
{

	//GPIO alternate function low register (GPIOx_AFRL) Configure PINS from 0 >>> 7
	//GPIO alternate function low register (GPIOx_AFRH) Configure PINS from 8 >>> 15
	volatile uint32_t* configregister = NULL ;
	configregister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8 )?  &GPIOx->AFRL : &GPIOx->AFRH ;

	/* input pin*/
	if(PinConfig->GPIO_MODER== GPIO_Input)
	{
		GPIOx->MODER &= ~((1 << (Get_PIN_Position(PinConfig->GPIO_PinNumber)*2)) | (1 <<((Get_PIN_Position(PinConfig->GPIO_PinNumber)*2)+1)));


		if(PinConfig->GPIO_PUPDR==GPIO_Pull_Up)
		{
			//clear
			GPIOx->PUPDR &= ~((1 << Get_PIN_Position(PinConfig->GPIO_PinNumber)) | (1 <<(Get_PIN_Position(PinConfig->GPIO_PinNumber)+1)));
			//set
			GPIOx->PUPDR |= 1>>Get_PIN_Position(PinConfig->GPIO_PinNumber);

		}
		else
		{
			//clear
			GPIOx->PUPDR &= ~((1 << Get_PIN_Position(PinConfig->GPIO_PinNumber)) | (1 <<(Get_PIN_Position(PinConfig->GPIO_PinNumber)+1)));
			//set
			GPIOx->PUPDR |= 2>>Get_PIN_Position(PinConfig->GPIO_PinNumber);
		}


	}

	/* AFIO PIN*/
	else if(PinConfig->GPIO_MODER== AFIO)
	{
		//clear
		GPIOx->MODER &= ~((1 << (Get_PIN_Position(PinConfig->GPIO_PinNumber)*2)) | (1 <<((Get_PIN_Position(PinConfig->GPIO_PinNumber)*2)+1)));

		//set
		GPIOx->MODER |= 2<<( Get_PIN_Position(PinConfig->GPIO_PinNumber)*2);
		if(PinConfig->GPIO_PUPDR==GPIO_Pull_Up)
		{
			//clear
			GPIOx->PUPDR &= ~((1 << Get_PIN_Position(PinConfig->GPIO_PinNumber)) | (1 <<(Get_PIN_Position(PinConfig->GPIO_PinNumber)+1)));
			//set
			GPIOx->PUPDR |= 1>>Get_PIN_Position(PinConfig->GPIO_PinNumber);
			//SELECT AFIO
			*(configregister) |= Get_AFRLH_SET(PinConfig->GPIO_AFIO)<<(Get_PIN_Position(PinConfig->GPIO_PinNumber)*4);

		}
		else if(PinConfig->GPIO_PUPDR==GPIO_Pull_Down)
		{
			//clear
			GPIOx->PUPDR &= ~((1 << Get_PIN_Position(PinConfig->GPIO_PinNumber)) | (1 <<(Get_PIN_Position(PinConfig->GPIO_PinNumber)+1)));
			//set
			GPIOx->PUPDR |= 2>>Get_PIN_Position(PinConfig->GPIO_PinNumber);
			//SELECT AFIO
			*(configregister) |= Get_AFRLH_SET(PinConfig->GPIO_AFIO)<<(Get_PIN_Position(PinConfig->GPIO_PinNumber)*4);

		}


		else if(PinConfig->GPIO_OTYPER==GPIO_Output_Push_Pull)
		{
			//clear
			GPIOx->OTYPER &= ~(1<<Get_PIN_Position(PinConfig->GPIO_PinNumber));
			//set
			//SELECT AFIO
			*(configregister) |= Get_AFRLH_SET(PinConfig->GPIO_AFIO)<<(Get_PIN_Position(PinConfig->GPIO_PinNumber)*4);

		}
		else if (PinConfig->GPIO_OTYPER==GPIO_Output_Open_Drain)
		{

			//set
			GPIOx->OTYPER |= 1>>Get_PIN_Position(PinConfig->GPIO_PinNumber);
			//SELECT AFIO
			*(configregister) |= Get_AFRLH_SET(PinConfig->GPIO_AFIO)<<(Get_PIN_Position(PinConfig->GPIO_PinNumber)*4);

		}
	}

	/* OUTPUT PIN*/
	else if(PinConfig->GPIO_MODER== GPIO_output_mode)
	{
		//clear
		GPIOx->MODER &= ~((1 << (Get_PIN_Position(PinConfig->GPIO_PinNumber)*2)) | (1 <<((Get_PIN_Position(PinConfig->GPIO_PinNumber)*2)+1)));

		//set
		GPIOx->MODER |= 1<<( Get_PIN_Position(PinConfig->GPIO_PinNumber)*2);

		if(PinConfig->GPIO_OTYPER==GPIO_Output_Push_Pull)
		{
			//clear
			GPIOx->OTYPER &= ~(1<<Get_PIN_Position(PinConfig->GPIO_PinNumber));
			//set

		}
		else if (PinConfig->GPIO_OTYPER==GPIO_Output_Open_Drain)
		{

			//set
			GPIOx->OTYPER |= 1>>Get_PIN_Position(PinConfig->GPIO_PinNumber);
		}

	}
	// Analog PIN
	else if(PinConfig->GPIO_MODER== GPIO_output_mode)
	{
		//clear
		GPIOx->MODER &= ~((1 << (Get_PIN_Position(PinConfig->GPIO_PinNumber)*2)) | (1 <<((Get_PIN_Position(PinConfig->GPIO_PinNumber)*2)+1)));

		//set
		GPIOx->MODER |= 3<<( Get_PIN_Position(PinConfig->GPIO_PinNumber)*2);
	}

	MCAL_GPIO_SetSpeed(GPIOx, PinConfig);
	MCAL_GPIO_AFIO(GPIOx, PinConfig, configregister);
}


/*********************************************************************************/
/* Api Name       :    MCAL_GPIO_DeInit                                  			                */
/* Parameters in  :     GPIOx														   */
/* Parameters out :  none                                                          */
/* Description    : 	Reset all GPIO Registers															*/
/*********************************************************************************/
void MCAL_GPIO_DeInit(GPIO_t *GPIOx)
{

	//can be reset manual .
	/*
GPIOx->BRR = 0x00000000 ;
	GPIOx->BSRR =0x00000000 ;
GPIOx->CRH = 0x44444444 ;
	GPIOx->CRL =  0x44444444 ;
	GPIOx->IDR = ;  (READ Only)
	GPIOx->LCKR =  0x00000000 ;
	GPIOx->ODR = 0x00000000;
	 */
	//or you can use the reset Controller
	//APB2 peripheral reset register (RCC_APB2RSTR)
	//Set and cleared by software.
	if (GPIOx == GPIOA)
	{
		RCC_GPIOA_CLK_DISABLE();

	}else if (GPIOx == GPIOB)
	{
		RCC_GPIOB_CLK_DISABLE();


	}else if (GPIOx == GPIOC)
	{
		RCC_GPIOC_CLK_DISABLE();


	}else if (GPIOx == GPIOD)
	{
		RCC_GPIOD_CLK_DISABLE();


	}else if (GPIOx == GPIOE)
	{
		RCC_GPIOE_CLK_DISABLE();


	}
	else if (GPIOx == GPIOH)
	{
		RCC_GPIOH_CLK_DISABLE();


	}



}
uint8_t MCAL_GPIO_ReadPin (GPIO_t *GPIOx , uint16_t PinNumber)
{

	uint8_t bitstatus ;
	if (((GPIOx->IDR) & PinNumber ) !=  (uint32_t)GPIO_PIN_RESET )
	{
		bitstatus = GPIO_PIN_SET ;
	}else
	{
		bitstatus = GPIO_PIN_RESET ;
	}
	return  bitstatus ;

}
uint16_t MCAL_GPIO_ReadPort (GPIO_t *GPIOx)
{
	uint16_t port_value ;
	port_value  =   (uint16_t)(GPIOx->IDR);
	return port_value ;
}
uint8_t MCAL_GPIO_WritePin (GPIO_t *GPIOx , uint16_t PinNumber , uint8_t Value)
{

	if ( Value !=  GPIO_PIN_RESET )
	{
		//		GPIOx->ODR |= PinNumber ;
		//		or
		//		Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
		//		These bits are write-only and can be accessed in Word mode only.
		//		0: No action on the corresponding ODRx bit
		//		1: Set the corresponding ODRx bit
		GPIOx->BSRR = (uint32_t)PinNumber ;

	}else
	{
		//		Bits 31:16 BRy: Port x Reset bit y (y= 0 .. 15)
		//		These bits are write-only and can be accessed in Word mode only.
		//		0: No action on the corresponding ODRx bit
		//		1: Reset the corresponding ODRx bit
		GPIOx->BSRR = (uint32_t)PinNumber ;
	}



}
uint16_t MCAL_GPIO_WritePort (GPIO_t *GPIOx , uint16_t Value )
{
	GPIOx->ODR = (uint32_t)Value ;

}
uint8_t MCAL_GPIO_TogglePin (GPIO_t *GPIOx , uint16_t PinNumber)
{
	GPIOx->ODR ^= (PinNumber) ;

}
uint8_t MCAL_GPIO_LockPin (GPIO_t *GPIOx , uint16_t PinNumber)
{
	/*
	 * Bit 16 LCKK[16]: Lock key
This bit can be read any time. It can only be modified using the lock key write sequence.
0: Port configuration lock key not active
1: Port configuration lock key active. The GPIOx_LCKR register is locked until an MCU reset
or a peripheral reset occurs.
LOCK key write sequence:
WR LCKR[16] = ‘1’ + LCKR[15:0]
WR LCKR[16] = ‘0’ + LCKR[15:0]
WR LCKR[16] = ‘1’ + LCKR[15:0]
RD LCKR
RD LCKR[16] = ‘1’ (this read operation is optional but it confirms that the lock is active)
Note: During the LOCK key write sequence, the value of LCK[15:0] must not change.
Any error in the lock sequence aborts the lock.
After the first lock sequence on any bit of the port, any read access on the LCKK bit will
return ‘1’ until the next CPU reset.
	 */

	//Set LCKK[16]
	volatile uint32_t tmp = 1<<16 ;
	//Set the LCKy
	tmp |= PinNumber ;

	//	Write 1
	GPIOx->LCKR = tmp ;// in this step we write 1 in bit 16 according the mechanism in Specs
	//	Write 0
	GPIOx->LCKR = PinNumber ;// in this step we write 0 in bit 16 according the mechanism in Specs
	//	Write 1
	GPIOx->LCKR = tmp ;// in this step we write 1 in bit 16 according the mechanism in Specs

	//	Read 0
	tmp = GPIOx->LCKR  ;
	//	Read 1 (this read is optional but confirms that the lock is active)
	if ( (uint32_t) (GPIOx->LCKR  & 1<<16 ))
	{
		return GPIO_RETURN_LOCK_Enable ;
	}else
	{
		return GPIO_RETURN_LOCK_ERROR ;

	}

}
