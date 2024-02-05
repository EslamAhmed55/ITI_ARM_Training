#include "GPIO.Interface.h"
#include "FreeRTOS.h"
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "semphr.h"
#include "task.h"
#include  "RCC_Interface.h"
#include "NVIC_Interface.h"
#include  "EXTI_interface.h"


SemaphoreHandle_t  ST_Semaphore ;
TaskHandle_t TASK1;
BaseType_t semaphor_state ;
typedef  void (*PointerToFunction)(void);

void Init_GPIO(void)
{
	for (int var = 0; var < 5; ++var) {
		GPIO_u8SetPinMode(GPIO_u8PortA,var,GPIO_u8_PinModeOutput);
		GPIO_u8SetPinOutputType(GPIO_u8PortA,var,GPIO_u8_OP_PP);
		GPIO_u8SetPinOutputSpeed(GPIO_u8PortA,var,GPIO_u8_MODE_LS);
		GPIO_u8ChangePinOutMode(GPIO_u8PortA,var,GPIO_u8_OP_MODE_RESET);
	}

}

void clock_int(void)
{
		RCC_u8InitSysClk();
	RCC_u8EnablePeripheralClk(RCC_u8_AHB1_BUS,RCC_u8_AHB1ENR_GPIOA);
	RCC_u8EnablePeripheralClk(RCC_u8_AHB1_BUS,RCC_u8_AHB1ENR_GPIOB);
}

void TASk_1(void);
void TASk_2(void);
int main()
{
	
			Init_GPIO();
	
			clock_int();

	

	//create binary semaphor
		vSemaphoreCreateBinary(ST_Semaphore);

		//create tasks
		xTaskCreate(TASk_1 ,NULL ,50 ,NULL , 1 ,TASK1  );
		xTaskCreate(TASk_2 ,NULL ,50 ,NULL , 4 ,NULL  );
		// start os
		vTaskStartScheduler() ;

	while(1)
	{
	}

  return 0;
}




void TASk_1(void)
{
	 u8 counter=0;
	 u8 flag = 0 ;
	while(1)
	{
		counter++;
		semaphor_state = xSemaphoreTake( ST_Semaphore, 2100 ) ;
		if(semaphor_state == pdTRUE)
		{

			if(flag == 0)
			{
				GPIO_u8DirectSetPinOutMode(GPIO_u8PortA ,GPIO_Pin0 , 1 );
				flag = 1 ;
			}
			else
			{
				GPIO_u8DirectSetPinOutMode(GPIO_u8PortA ,GPIO_Pin0 , 0 );
				flag = 0 ;
			}
			vTaskDelay(2000);
			xSemaphoreGive(ST_Semaphore);


		}
	}

}

void TASK2(void)
{
	 u8 flag = 0 ;
		u8 counter=0;
	while(1)
	{
		counter++;
		semaphor_state = xSemaphoreTake(ST_Semaphore ,2100) ;
		if(semaphor_state == pdTRUE)
		{
			if(flag == 0)
			{
				GPIO_u8DirectSetPinOutMode(GPIO_u8PortA ,GPIO_Pin1 , 1 );
				flag = 1 ;
			}
			else
			{
				GPIO_u8DirectSetPinOutMode(GPIO_u8PortA ,GPIO_Pin1 , 0 );
				flag = 0 ;
			}
			vTaskDelay(2000);
			xSemaphoreGive(ST_Semaphore);
			if(counter>3){
				vTaskSuspend(TASK1);
			}
			vTaskDelay(1000);
		}
	}

}
