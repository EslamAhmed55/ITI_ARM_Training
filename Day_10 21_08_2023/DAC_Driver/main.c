/*
 ============================================================================
 Name        : DAC.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


#include  "RCC_Interface.h"
#include  "RCC_Private.h"
#include  "RCC_Config.h"
#include "song.h"
#include "DAC_Config.h"
#include "DAC_Interface.h"
#include "DAC_Private.h"
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "GPIO.Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Conf.h"
#include "SYSTICK_INTERFACE.h"
#include "SYSTICK_PRIVATE.h"
#include "SYSTICK_CONFIG.h"
int main(void) {

	// clock init
	RCC_u8InitSysClk();
	STK_void_Init();
	RCC_u8EnablePeripheralClk(RCC_u8_AHB1_BUS,RCC_u8_AHB1ENR_GPIOA);

	//DAC init

	DACvoidInit();

	DACvoidRun();

	while(1)
	{

	}




}
