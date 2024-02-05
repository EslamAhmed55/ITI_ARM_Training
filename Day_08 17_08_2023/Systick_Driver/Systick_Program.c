#include "SysTick_Interface.h"
#include "SysTick_Config.h"
#include "SysTick_Private.h"

static volatile PoinTer_TO_Function  SysTick_CallBack = NULL;
static uint8_t SysTick_Mode = SysTick_Single_Interval_Mode;

void SysTick_Init(void)
{
	/* Disable SysTick */
	CLR_BIT(SysTick->STK_CTRL,0);   // bit 0 ENABLE  ERROR: Cant be solved
	/* Set Reload Register to SysTicks */
	SysTick->STK_LOAD = 20;   
	/*Reset the SysTick  */
	SysTick->STK_VAL = 0;
	/*Select Clock */
#if   STK_CLOCK_SOURCE  == CLOCK_AHB_DIV_1
	SET_BIT(SysTick->STK_CTRL,CLKSOURCE);
#elif   STK_CLOCK_SOURCE  == CLOCK_AHB_DIV_8
	CLR_BIT(SysTick->STK_CTRL,CLKSOURCE);
#endif

	/* Disable SysTickIRQ */
	CLR_BIT(SysTick->STK_CTRL,TICKINT);
}



void SysTick_Disable(void)
{
	/* Disable SysTick Conunter */
	CLR_BIT(SysTick-> STK_CTRL,0);   // bit 0 ENABLE  ERROR: Cant be Solved

	/* Reset Reload Register to SysTicks */
	SysTick->STK_LOAD = 0;

	/* Reset the SysTick Conter value */
	SysTick->STK_VAL = 0;

	/* Disable SysTickIRQ */
	CLR_BIT(SysTick->STK_CTRL,TICKINT);
}



void SysTick_Delay(u32 Delay)
{
	/* Set Reload Register to SysTick */
	SysTick->STK_LOAD = Delay;

	/* Enable SysTick Counter */
	SET_BIT(SysTick->STK_CTRL,0);

	/* Waint the COUNTFLAG Returns 1 */
	while(GET_BIT(SysTick->STK_CTRL , COUNTFLAG) == 0);

	/* Disable SysTick Counter  */
	CLR_BIT(SysTick->STK_CTRL,0);

	/* Reset the SysTick Reload Register */
	SysTick->STK_LOAD = 0;

	/* Reset The SysTick Counter Value*/
	SysTick-> STK_VAL = 0;
}

void SysTick_SingleInterval(u32 Ticks , T *CallBack)
{
	/* Validation Step */
	if(CallBack != NULL){
		/* Set Reload Register to SysTick */
		SysTick->STK_LOAD = Ticks;

		/*Copy of user Callback yo a local T*/
		SysTick_CallBack = CallBack;

		/*Set SysTick Timer to the Single Interval Mode */
		SysTick_Mode = SysTick_Single_Interval_Mode ;
		/*Enable SysTick Timer IRQ NVIC Line*/
		SET_BIT(SysTick->STK_CTRL,TICKINT);

		/*Set the SysTick Timer IRQ Priority Least urgent */

		/*Enable SysTick Timer to asserts the systick exception request */
		SET_BIT(SysTick->STK_CTRL,0);

	}else{
		/*Nothing*/
	}

}

void SysTick_PeriodicInterval(u32 Ticks , T *CallBack)
{
	/* Validation Step */
	if(CallBack != NULL){
		/* Set Reload Register to SysTick */
		SysTick->STK_LOAD = Ticks;

		/*Copy of user Callback a local T*/
		SysTick_CallBack = CallBack;

		/*Set SysTick Timer to the Single Interval Mode */
		SysTick_Mode = SysTick_Peruidic_Interval_Mode ;
		/*Enable SysTick Timer IRQ NVIC Line*/
		SET_BIT(SysTick->STK_CTRL,TICKINT);

		/*Set the SysTick Timer IRQ Priority Least urgent */

		/*Enable SysTick Timer to asserts the systick exception request */
		SET_BIT(SysTick->STK_CTRL,0);

	}
}

void SysTick_Handler(void)
{
	if(SysTick_Mode == SysTick_Single_Interval_Mode)
	{
		/* Disable SysTick Counter */
		CLR_BIT(SysTick-> STK_CTRL,0);   // bit 0 ENABLE  ERROR: Can't be Solved

		/* Reset Reload Register to SysTicks */
		SysTick->STK_LOAD = 0;

		/* Reset the SysTick Counter value */
		SysTick->STK_VAL = 0;

		/* Disable SysTickIRQ */
		CLR_BIT(SysTick->STK_CTRL,TICKINT);
	}


	if(SysTick_CallBack)
	{
		SysTick_CallBack();
	}
}

u32 SysTick_u32GET_Remain(void)
{
	/*Define a Loca Variable To Hold Data*/
	u32  Local_Var;
	/*Set data from STK_VAL reg into variable */
	Local_Var = SysTick-> STK_VAL;
	/* Return Local Variable */
	return (Local_Var);
}


u32 STK_uint32GET_Done(void)
{
	/*Define a Loca Variable To Hold Data*/
	u32  Local_Var;
	/*Set data from STK_LOAD - STK_VAL reg  into variable */
	Local_Var = (SysTick-> STK_LOAD)- (SysTick-> STK_VAL);
	/* Return Local Variable */
	return (Local_Var);
}