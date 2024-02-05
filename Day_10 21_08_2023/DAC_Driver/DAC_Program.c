/*
 * DAC_Program.c
 *
 *  Created on: Aug 21, 2023
 *      Author: eslam
 */

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

static u32 DAC_Counter=0;
void DACvoidInit(void)
{
	//PIN0
	GPIO_u8SetPinMode( DAC_PIN0, GPIO_u8_PinModeOutput);
	GPIO_u8SetPinOutputType(DAC_PIN0,GPIO_u8_OP_PP);
	GPIO_u8ChangePinOutMode(DAC_PIN0,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputSpeed(DAC_PIN0,GPIO_u8_MODE_HS);

	//PIN1
	GPIO_u8SetPinMode( DAC_PIN1, GPIO_u8_PinModeOutput);
	GPIO_u8SetPinOutputType(DAC_PIN1,GPIO_u8_OP_PP);
	GPIO_u8ChangePinOutMode(DAC_PIN1,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputSpeed(DAC_PIN1,GPIO_u8_MODE_HS);

	//PIN2
	GPIO_u8SetPinMode( DAC_PIN2, GPIO_u8_PinModeOutput);
	GPIO_u8SetPinOutputType(DAC_PIN2,GPIO_u8_OP_PP);
	GPIO_u8ChangePinOutMode(DAC_PIN2,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputSpeed(DAC_PIN2,GPIO_u8_MODE_HS);

	//PIN3
	GPIO_u8SetPinMode( DAC_PIN3, GPIO_u8_PinModeOutput);
	GPIO_u8SetPinOutputType(DAC_PIN3,GPIO_u8_OP_PP);
	GPIO_u8ChangePinOutMode(DAC_PIN3,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputSpeed(DAC_PIN3,GPIO_u8_MODE_HS);

	//PIN4
	GPIO_u8SetPinMode( DAC_PIN4, GPIO_u8_PinModeOutput);
	GPIO_u8SetPinOutputType(DAC_PIN4,GPIO_u8_OP_PP);
	GPIO_u8ChangePinOutMode(DAC_PIN4,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputSpeed(DAC_PIN4,GPIO_u8_MODE_HS);

	//PIN5
	GPIO_u8SetPinMode( DAC_PIN5, GPIO_u8_PinModeOutput);
	GPIO_u8SetPinOutputType(DAC_PIN5,GPIO_u8_OP_PP);
	GPIO_u8ChangePinOutMode(DAC_PIN5,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputSpeed(DAC_PIN5,GPIO_u8_MODE_HS);

	//PIN6
	GPIO_u8SetPinMode( DAC_PIN6, GPIO_u8_PinModeOutput);
	GPIO_u8SetPinOutputType(DAC_PIN6,GPIO_u8_OP_PP);
	GPIO_u8ChangePinOutMode(DAC_PIN6,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputSpeed(DAC_PIN6,GPIO_u8_MODE_HS);

	//PIN7
	GPIO_u8SetPinMode( DAC_PIN7, GPIO_u8_PinModeOutput);
	GPIO_u8SetPinOutputType(DAC_PIN7,GPIO_u8_OP_PP);
	GPIO_u8ChangePinOutMode(DAC_PIN7,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputSpeed(DAC_PIN7,GPIO_u8_MODE_HS);

	STK_void_Init();


}




void DACvoidRun(void)
{
	STK_voidSetIntervalPeriodic(250,DAC_voidCallback); //250 Tick = 125 micro second
}

void DAC_voidCallback(void)
{
	GPIO_u8ChangePinOutMode(DAC_PIN0,GET_BIT(song_raw[DAC_Counter],0));
	GPIO_u8ChangePinOutMode(DAC_PIN1,GET_BIT(song_raw[DAC_Counter],1));
	GPIO_u8ChangePinOutMode(DAC_PIN2,GET_BIT(song_raw[DAC_Counter],2));
	GPIO_u8ChangePinOutMode(DAC_PIN3,GET_BIT(song_raw[DAC_Counter],3));
	GPIO_u8ChangePinOutMode(DAC_PIN4,GET_BIT(song_raw[DAC_Counter],4));
	GPIO_u8ChangePinOutMode(DAC_PIN5,GET_BIT(song_raw[DAC_Counter],5));
	GPIO_u8ChangePinOutMode(DAC_PIN6,GET_BIT(song_raw[DAC_Counter],6));
	GPIO_u8ChangePinOutMode(DAC_PIN7,GET_BIT(song_raw[DAC_Counter],7));
	DAC_Counter++;

	if(DAC_Counter>=song_len)
	{
		DAC_Counter=0;
	}

}



