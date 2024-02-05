void wait_ms (uint32_t time )
{
	uint32_t i,j;
	for(i =0 ;i<time ; i++)
		for(j=0 ; j<255 ; j++);
}
void RCC_init()
{
	RCC_GPIOA_CLK();
	RCC_GPIOB_CLK();

}
void GPIO_int()
{

	GPIO_PinConfig Pincfg;

	/*************************PORTA**********************************/
	//PIN0
	Pincfg.GPIO_PinNumber=GPIO_PIN_0;
	Pincfg.GPIO_MOOD=GPIO_MOOD_OUTPUT_PP;
	Pincfg.GPIO_Output_speed=GPIO_SPEED_10M;

	MCAL_GPIO_Init(GPIOA, & Pincfg);

	//PIN1
	Pincfg.GPIO_PinNumber=GPIO_PIN_1;
	Pincfg.GPIO_MOOD=GPIO_MOOD_OUTPUT_PP;
	Pincfg.GPIO_Output_speed=GPIO_SPEED_10M;

	MCAL_GPIO_Init(GPIOA, & Pincfg);

	//PIN2
	Pincfg.GPIO_PinNumber=GPIO_PIN_2;
	Pincfg.GPIO_MOOD=GPIO_MOOD_OUTPUT_PP;
	Pincfg.GPIO_Output_speed=GPIO_SPEED_10M;

	MCAL_GPIO_Init(GPIOA, & Pincfg);
	//PIN3
	Pincfg.GPIO_PinNumber=GPIO_PIN_3;
	Pincfg.GPIO_MOOD=GPIO_MOOD_OUTPUT_PP;
	Pincfg.GPIO_Output_speed=GPIO_SPEED_10M;

	MCAL_GPIO_Init(GPIOA, & Pincfg);
	//PIN4
	Pincfg.GPIO_PinNumber=GPIO_PIN_4;
	Pincfg.GPIO_MOOD=GPIO_MOOD_OUTPUT_PP;
	Pincfg.GPIO_Output_speed=GPIO_SPEED_10M;

	MCAL_GPIO_Init(GPIOA, & Pincfg);
	//PIN5
	Pincfg.GPIO_PinNumber=GPIO_PIN_5;
	Pincfg.GPIO_MOOD=GPIO_MOOD_OUTPUT_PP;
	Pincfg.GPIO_Output_speed=GPIO_SPEED_10M;

	MCAL_GPIO_Init(GPIOA, & Pincfg);
	//PIN6
	Pincfg.GPIO_PinNumber=GPIO_PIN_6;
	Pincfg.GPIO_MOOD=GPIO_MOOD_OUTPUT_PP;
	Pincfg.GPIO_Output_speed=GPIO_SPEED_10M;

	MCAL_GPIO_Init(GPIOA, & Pincfg);
	//PIN7
	Pincfg.GPIO_PinNumber=GPIO_PIN_7;
	Pincfg.GPIO_MOOD=GPIO_MOOD_OUTPUT_PP;
	Pincfg.GPIO_Output_speed=GPIO_SPEED_10M;

	MCAL_GPIO_Init(GPIOA, & Pincfg);

	/****************************PORTB***********************/


	//PIN0

	Pincfg.GPIO_PinNumber=GPIO_PIN_0;
	Pincfg.GPIO_MOOD=GPIO_MOOD_INPUT_PD;
	MCAL_GPIO_Init(GPIOB, & Pincfg);
	//PIN1

	Pincfg.GPIO_PinNumber=GPIO_PIN_1;
	Pincfg.GPIO_MOOD=GPIO_MOOD_INPUT_PD;
	MCAL_GPIO_Init(GPIOB, & Pincfg);
	//PIN2

	Pincfg.GPIO_PinNumber=GPIO_PIN_2;
	Pincfg.GPIO_MOOD=GPIO_MOOD_INPUT_PD;
	MCAL_GPIO_Init(GPIOB, & Pincfg);
	//PIN3

	Pincfg.GPIO_PinNumber=GPIO_PIN_3;
	Pincfg.GPIO_MOOD=GPIO_MOOD_INPUT_PD;
	MCAL_GPIO_Init(GPIOB, & Pincfg);
	//PIN4

	Pincfg.GPIO_PinNumber=GPIO_PIN_4;
	Pincfg.GPIO_MOOD=GPIO_MOOD_INPUT_PD;
	MCAL_GPIO_Init(GPIOB, & Pincfg);
	//PIN5

	Pincfg.GPIO_PinNumber=GPIO_PIN_5;
	Pincfg.GPIO_MOOD=GPIO_MOOD_INPUT_PD;
	MCAL_GPIO_Init(GPIOB, & Pincfg);
	//PIN6

	Pincfg.GPIO_PinNumber=GPIO_PIN_6;
	Pincfg.GPIO_MOOD=GPIO_MOOD_INPUT_PD;
	MCAL_GPIO_Init(GPIOB, & Pincfg);
	//PIN7

	Pincfg.GPIO_PinNumber=GPIO_PIN_7;
	Pincfg.GPIO_MOOD=GPIO_MOOD_INPUT_PD;
	MCAL_GPIO_Init(GPIOB, & Pincfg);






}

void main()
{
	RCC_init();
	GPIO_int();

	while(1)
	{

		if(MCAL_GPIO_ReadPin( GPIOB, GPIO_PIN_0)==1)
		{
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);
						MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
						MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);
						MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);
						MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
						MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
						MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
						MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);


		}

		else if(MCAL_GPIO_ReadPin( GPIOB, GPIO_PIN_1)==1)
		{
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0);
						MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
						MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);
						MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);
						MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
						MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
						MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
						MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
		}
		else if(MCAL_GPIO_ReadPin( GPIOB, GPIO_PIN_2)==1)
		{
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);
						MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
						MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);
						MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);
						MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
						MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
						MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
						MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
		}

		else if(MCAL_GPIO_ReadPin( GPIOB, GPIO_PIN_3)==1)
		{
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0);
					MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
					MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
					MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);
					MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
					MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
					MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
					MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);

		}
		else if(MCAL_GPIO_ReadPin( GPIOB, GPIO_PIN_4)==1)
		{
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
		}
		else if(MCAL_GPIO_ReadPin( GPIOB, GPIO_PIN_5)==1)
		{
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
		}
		else if(MCAL_GPIO_ReadPin( GPIOB, GPIO_PIN_6)==1)
		{
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
		}
		else if(MCAL_GPIO_ReadPin( GPIOB, GPIO_PIN_7)==1)
		{
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
		}

		else{
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
			MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);

		}
	}
}
