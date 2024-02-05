/*
 * LED_MAT_Program.c
 *
 *  Created on: Sep 1, 2023
 *      Author: eslam
 */

#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "LED_MAT_Config.h"
#include "LED_MAT_Interface.h"
#include "GPIO_Interface.h"

#include "GPIO_Interface.h"
#include "SYSTICK_INTERFACE.h"

#define Delay		7000


void LED_MAT_voidInit()
{
	/* PINS OUTPUT*/
	GPIO_u8SetPinMode(LED_MAT_COL1 ,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LED_MAT_COL2 ,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LED_MAT_COL3 ,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LED_MAT_COL4 ,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LED_MAT_COL5 ,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LED_MAT_COL6 ,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LED_MAT_COL7 ,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LED_MAT_COL8 ,GPIO_u8_PinModeOutput);


	GPIO_u8SetPinMode(LED_MAT_ROW1,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LED_MAT_ROW2,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LED_MAT_ROW3,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LED_MAT_ROW4,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LED_MAT_ROW5,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LED_MAT_ROW6,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LED_MAT_ROW7,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LED_MAT_ROW8,GPIO_u8_PinModeOutput);

	/* PINS OUTPUT PUSHPULL*/

	GPIO_u8SetPinOutputType(LED_MAT_COL1 ,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LED_MAT_COL2 ,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LED_MAT_COL3 ,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LED_MAT_COL4 ,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LED_MAT_COL5 ,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LED_MAT_COL6 ,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LED_MAT_COL7 ,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LED_MAT_COL8 ,GPIO_u8_OP_PP);


	GPIO_u8SetPinOutputType(LED_MAT_ROW1,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LED_MAT_ROW2,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LED_MAT_ROW3,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LED_MAT_ROW4,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LED_MAT_ROW5,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LED_MAT_ROW6,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LED_MAT_ROW7,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LED_MAT_ROW8,GPIO_u8_OP_PP);

	/* PINS OUTPUT SPEED*/

	GPIO_u8SetPinOutputSpeed(LED_MAT_COL1 ,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LED_MAT_COL2 ,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LED_MAT_COL3 ,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LED_MAT_COL4 ,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LED_MAT_COL5 ,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LED_MAT_COL6 ,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LED_MAT_COL7 ,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LED_MAT_COL8 ,GPIO_u8_MODE_MS);

	GPIO_u8SetPinOutputSpeed(LED_MAT_ROW1,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LED_MAT_ROW2,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LED_MAT_ROW3,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LED_MAT_ROW4,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LED_MAT_ROW5,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LED_MAT_ROW6,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LED_MAT_ROW7,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LED_MAT_ROW8,GPIO_u8_MODE_MS);



}


void LED_MAT_voidClearDispaly(void)
{
	LED_MAT_voidClearColumns();
	LED_MAT_voidClearROWS();
}


void LED_MAT_voidClearColumns(void)
{

	GPIO_u8ChangePinOutMode(LED_MAT_COL1 ,GPIO_u8_OP_MODE_SET);
	GPIO_u8ChangePinOutMode(LED_MAT_COL2 ,GPIO_u8_OP_MODE_SET);
	GPIO_u8ChangePinOutMode(LED_MAT_COL3 ,GPIO_u8_OP_MODE_SET);
	GPIO_u8ChangePinOutMode(LED_MAT_COL4 ,GPIO_u8_OP_MODE_SET);
	GPIO_u8ChangePinOutMode(LED_MAT_COL5 ,GPIO_u8_OP_MODE_SET);
	GPIO_u8ChangePinOutMode(LED_MAT_COL6 ,GPIO_u8_OP_MODE_SET);
	GPIO_u8ChangePinOutMode(LED_MAT_COL7 ,GPIO_u8_OP_MODE_SET);
	GPIO_u8ChangePinOutMode(LED_MAT_COL8 ,GPIO_u8_OP_MODE_SET);




}

void LED_MAT_voidClearROWS(void)
{
	GPIO_u8ChangePinOutMode(LED_MAT_ROW1,GPIO_u8_OP_MODE_RESET);
	GPIO_u8ChangePinOutMode(LED_MAT_ROW2,GPIO_u8_OP_MODE_RESET);
	GPIO_u8ChangePinOutMode(LED_MAT_ROW3,GPIO_u8_OP_MODE_RESET);
	GPIO_u8ChangePinOutMode(LED_MAT_ROW4,GPIO_u8_OP_MODE_RESET);
	GPIO_u8ChangePinOutMode(LED_MAT_ROW5,GPIO_u8_OP_MODE_RESET);
	GPIO_u8ChangePinOutMode(LED_MAT_ROW6,GPIO_u8_OP_MODE_RESET);
	GPIO_u8ChangePinOutMode(LED_MAT_ROW7,GPIO_u8_OP_MODE_RESET);
	GPIO_u8ChangePinOutMode(LED_MAT_ROW8,GPIO_u8_OP_MODE_RESET);
}


void LED_MAT_Display(u8 *Copy_Frame)

{


	LED_MAT_voidClearDispaly();

	GPIO_u8ChangePinOutMode(LED_MAT_COL1 ,GPIO_u8_OP_MODE_RESET);
	LED_MAT_voidSETRow(Copy_Frame[0]);
	STK_voidSetBusyWait(Delay);

	LED_MAT_voidClearColumns();
	GPIO_u8ChangePinOutMode(LED_MAT_COL2 ,GPIO_u8_OP_MODE_RESET);
	LED_MAT_voidSETRow(Copy_Frame[1]);
	STK_voidSetBusyWait(Delay);

	LED_MAT_voidClearColumns();
	GPIO_u8ChangePinOutMode(LED_MAT_COL3 ,GPIO_u8_OP_MODE_RESET);
	LED_MAT_voidSETRow(Copy_Frame[2]);
	STK_voidSetBusyWait(Delay);

	LED_MAT_voidClearColumns();
	GPIO_u8ChangePinOutMode(LED_MAT_COL4 ,GPIO_u8_OP_MODE_RESET);
	LED_MAT_voidSETRow(Copy_Frame[3]);
	STK_voidSetBusyWait(Delay);

	LED_MAT_voidClearColumns();
	GPIO_u8ChangePinOutMode(LED_MAT_COL5 ,GPIO_u8_OP_MODE_RESET);
	LED_MAT_voidSETRow(Copy_Frame[4]);
	STK_voidSetBusyWait(Delay);

	LED_MAT_voidClearColumns();
	GPIO_u8ChangePinOutMode(LED_MAT_COL6 ,GPIO_u8_OP_MODE_RESET);
	LED_MAT_voidSETRow(Copy_Frame[5]);
	STK_voidSetBusyWait(Delay);

	LED_MAT_voidClearColumns();
	GPIO_u8ChangePinOutMode(LED_MAT_COL7 ,GPIO_u8_OP_MODE_RESET);
	LED_MAT_voidSETRow(Copy_Frame[6]);
	STK_voidSetBusyWait(Delay);

	LED_MAT_voidClearColumns();
	GPIO_u8ChangePinOutMode(LED_MAT_COL8 ,GPIO_u8_OP_MODE_RESET);
	LED_MAT_voidSETRow(Copy_Frame[7]);
	STK_voidSetBusyWait(Delay);

}

void LED_MAT_voidSETRow(u8 Copy_RowValue)
{
	GPIO_u8ChangePinOutMode(LED_MAT_ROW1,GET_BIT(Copy_RowValue,0));
	GPIO_u8ChangePinOutMode(LED_MAT_ROW2,GET_BIT(Copy_RowValue,1));
	GPIO_u8ChangePinOutMode(LED_MAT_ROW3,GET_BIT(Copy_RowValue,2));
	GPIO_u8ChangePinOutMode(LED_MAT_ROW4,GET_BIT(Copy_RowValue,3));
	GPIO_u8ChangePinOutMode(LED_MAT_ROW5,GET_BIT(Copy_RowValue,4));
	GPIO_u8ChangePinOutMode(LED_MAT_ROW6,GET_BIT(Copy_RowValue,5));
	GPIO_u8ChangePinOutMode(LED_MAT_ROW7,GET_BIT(Copy_RowValue,6));
	GPIO_u8ChangePinOutMode(LED_MAT_ROW8,GET_BIT(Copy_RowValue,7));


}

