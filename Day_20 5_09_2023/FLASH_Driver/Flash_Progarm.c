/*
 * Flash_Progarm.c
 *
 *  Created on: Sep 5, 2023
 *      Author: eslam
 */


#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "Flash_Private.h"
#include "Flash_Interface.h"
#include "Flash_Config.h"




u8 Flash_Unlook()
{
	u8 flag=STD_TYPES_OK;
	FLASH->FLASH_KEYR=FLASH_KEY1;
	FLASH->FLASH_KEYR=FLASH_KEY2;

	if(GET_BIT(FLASH->FLASH_CR,31)!=0)
	{
		flag=STD_TYPES_NOK;
	}


	return flag;
}

u8 Flash_look()
{
	u8 flag=STD_TYPES_OK;

	SET_BIT(FLASH->FLASH_CR,31);
	if(GET_BIT(FLASH->FLASH_CR,31)==0)
	{
		flag=STD_TYPES_NOK;
	}
	return flag;

}



u8 Flash_u8EraseSector(u8 Copy_u8Sector)
{
	u8 status=STD_TYPES_OK;

	if(Copy_u8Sector<5)
	{
		/*unlook */
		Flash_Unlook();

		while(GET_BIT(FLASH->FLASH_SR,16)==1);

		/* Disable Mode*/
		CLEAR_BIT(FLASH->FLASH_CR,0);
		/* Enable*/
		SET_BIT(FLASH->FLASH_CR,1);

		/* Disable */
		CLEAR_BIT(FLASH->FLASH_CR,2);

		/* To config sector_num*/

		MODIFY_REG(FLASH->FLASH_CR,Copy_u8Sector,FLASH_CR_SNB_MASK);


		/*clear flags*/
		FLASH->FLASH_SR=(0b11111<<4);
		/*start operation*/

		SET_BIT(FLASH->FLASH_CR,16);

		/*Look flash*/
		Flash_look();
	}
	else
	{
		status=STD_TYPES_NOK
	}

	return status;
}

u8 Flash_u8Write(u32 Copy_u32Address, u32* ptr_u32Data, u32 Copy_u32Length)
{
	u8 status=STD_TYPES_OK;

	if(ptr_u32Data!=NULL)

	{

		Flash_Unlook();
		while(GET_BIT(FLASH->FLASH_SR,16)==1);




		/* Disable Mode*/
		SET_BIT(FLASH->FLASH_CR,0);
		/* Enable*/
		CLEAR_BIT(FLASH->FLASH_CR,1);

		/* Disable */
		CLEAR_BIT(FLASH->FLASH_CR,2);


		/*configure size (32bit) */
		SET_BIT(FLASH->FLASH_CR,8);

		CLEAR_BIT(FLASH->FLASH_CR,9);
		/*clear flags*/

		FLASH->FLASH_SR=(0b11111<<4);

		for(u32 i=0;i<Copy_u32Length;++i)
		{
			*((u32*)Copy_u32Address+i*4)=ptr_u32Data[i];

			/* wait to set*/
			while(GET_BIT(FLASH->FLASH_SR,16)==1);
		}

		/* Disable Mode*/
		CLEAR_BIT(FLASH->FLASH_CR,0);

		/* look again*/
		Flash_look();

	}

	return status;
}
