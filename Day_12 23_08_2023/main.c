#include <stdio.h>
#include <stdlib.h>

//includes

#include "BIT_MATHS.h"
#include"STD_TYPES.h"
#include "RCC_Private.h"
#include "RCC_Interface.h"
#include "RCC_Config.h"
#include "GPIO_Private.h"
#include "GPIO_Interface.h"
#include "GPIO_Config.h"
#include "USART_Private.h"
#include "USART_Confih.h"
#include "USART_Interface.h"

void clock_int()
{
	RCC_u8InitSysClk();
	RCC_u8EnablePeripheralClk(RCC_u8_AHB1_BUS,RCC_u8_AHB1ENR_GPIOA);

}



int main(void) {
	char password[]="ESLAM";
	 char ReceiveBuffer[6];
	 u8 BufferIndex=0;
	RCC_u8InitSysClk();
	RCC_u8EnablePeripheralClk(RCC_u8_AHB1_BUS,RCC_u8_AHB1ENR_GPIOA);
	RCC_u8EnablePeripheralClk(RCC_u8_AHB1_BUS,RCC_u8_AHB1ENR_GPIOB);

	RCC_u8EnablePeripheralClk(RCC_u8_AHB2_BUS,0);
	RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS,RCC_u8_APB2ENR_USART1EN);

	STK_void_Init();

	GPIO_u8SetPinMode(GPIOA,GPIO_Pin10,GPIO_u8_PinModeAF);
	GPIO_u8SetPinMode(GPIOA,GPIO_Pin9,GPIO_u8_PinModeAF);

	GPIO_u8SetAlterFunc(GPIO_u8PortA,GPIO_Pin10,AF7);
	GPIO_u8SetAlterFunc(GPIO_u8PortA,GPIO_Pin9,AF7);
	USART_voidInit();

	u8 Valid_Pass="Password is Valid \n";
	u8 InValid_Pass="Password is InValid \n";

	while(1)
	{
		u8 receivedchar;

		USART_voidReceive(&receivedchar);
		USART_voidSend(&receivedchar,1);
		if(receivedchar=='\r'||receivedchar=='\n')
		{
			ReceiveBuffer[6]='\0';

		if(strcmp(ReceiveBuffer,password)==0)
		{
			USART_voidSend(Valid_Pass,21);
			USART_voidSend('\n',1);
		}
		else
		{
			USART_voidSend(InValid_Pass,23);
		}
		BufferIndex=0;
		}
		else
		{
			if(BufferIndex<5)
			{
				ReceiveBuffer[BufferIndex++]=receivedchar;
			}
		}

	}

	return 0;
}
