/*
 * STP_Program.c
 *
 *  Created on: Aug 22, 2023
 *      Author: eslam
 */





#include "STP_Interface.h"

PIN_CFG PIN0,PIN1,PIN2,PIN3;

void STP_vInit(void)
{
    /* Enable RCC */
	RCC_vInitSysClk();
	RCC_vEnablePeripheral(AHB1,GPIOAEN);

	/* Enable GPIO */
	PIN0.Pin = STP_DATA_PIN;
	PIN0.Port = STP_PORT;
	PIN0.PinMode = OUTPUT_M;
	GPIO_PinConfig(&PIN0);

	PIN1.Pin = STP_SHIFT_CLK_PIN;
	PIN1.Port = STP_PORT;
	PIN1.PinMode = OUTPUT_M;
	GPIO_PinConfig(&PIN1);

	PIN2.Pin = STP_LATCH_CLK_PIN;
	PIN2.Port = STP_PORT;
	PIN2.PinMode = OUTPUT_M;
	GPIO_PinConfig(&PIN2);

	PIN3.Pin = STP_OUTEN_PIN;
	PIN3.Port = STP_PORT;
	PIN3.PinMode = OUTPUT_M;
	PIN3.Level = PIN_HIGH;
	GPIO_PinConfig(&PIN3);

    /* Init SysTick */
	STK_vInit();

}

static void Send_Pulse(uint32_t Pulse_Width)
{
	PIN0.Level = PIN_HIGH;
	GPIO_PinConfig(&PIN0);
	STK_vDelay_(Pulse_Width);   // Pluse Width
	PIN0.Level = PIN_LOW;
	GPIO_PinConfig(&PIN0);

}
void STP_vDisplayData(uint8_t  Data)
{
	uint8_t i;
	for(i=0;i<8;i++)
	{
		/* Send Data on Data Series Pin*/
		PIN1.Level = GET_BIT(Data,i);
		GPIO_PinConfig(&PIN1);

		/*Send Pules*/
		Send_Pulse(100000);

	}

	/*Send High on Latch Clock*/
	PIN2.Level = PIN_HIGH;
	GPIO_PinConfig(&PIN2);
	STK_vDelay_(100000);
	/*Send Low to OutPut Enable */
	PIN3.Level = PIN_LOW;
	GPIO_PinConfig(&PIN3);
	STK_vDelay_(100000);


}

