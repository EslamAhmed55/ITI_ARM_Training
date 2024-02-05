/*
 * NVIC_Program.c
 *
 *  Created on: Aug 15, 2023
 *      Author: eslam
 */

#include  "STD_TYPES.h"
#include  "BIT_MATHS.h"
#include "NVIC_Config.h"
#include "NVIC_Private.h"
#include "NVIC_Interface.h"

static u8 StaticGlobal_u8priorityConfig;

void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptNum)
{
	//Enable_ ISER
	NVIC->NVIC_ISER[Copy_u8InterruptNum];

	//SET
	SET_BIT(	NVIC->NVIC_ISER[Copy_u8InterruptNum/32],Copy_u8InterruptNum%32);


}
void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptNum)
{
	SET_BIT(NVIC->NVIC_ICER[Copy_u8InterruptNum/32],Copy_u8InterruptNum%32);


}
void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptNum)
{
	SET_BIT(	NVIC->NVIC_ISPR[Copy_u8InterruptNum/32],Copy_u8InterruptNum%32);


}
void NVIC_voidClearPending(u8 Copy_u8InterruptNum)
{
	SET_BIT(	NVIC->NVIC_ICPR[Copy_u8InterruptNum/32],Copy_u8InterruptNum%32);

}

void NVIC_u8GetInterruptState(u8 Copy_u8InterruptNum)
{
	u8 Local_u8Instate = 	SET_BIT(NVIC->NVIC_IABR[Copy_u8InterruptNum/32],Copy_u8InterruptNum%32);

	return Local_u8Instate;

}
void NVIC_voidSetInterruptPriorityConfig(u8 Copy_u8InterruptNum, u8 Copy_u8GroupId , u8 Copy_u8SubGroupId)
{
	switch(StaticGlobal_u8priorityConfig)
	{
	case NVIC_GROUP4BITS_SUB0BITS:
		NVIC->NVIC_IPR[Copy_u8InterruptNum]=(Copy_u8GroupId<<4);
		break;

	case NVIC_GROUP3BITS_SUB1BITS:
		NVIC->NVIC_IPR[Copy_u8InterruptNum]=(Copy_u8GroupId<<5)|(Copy_u8SubGroupId<<4);

			break;
	case NVIC_GROUP2BITS_SUB2BITS:
		NVIC->NVIC_IPR[Copy_u8InterruptNum]=(Copy_u8GroupId<<6)|(Copy_u8SubGroupId<<4);

			break;
	case NVIC_GROUP1BITS_SUB3BITS:
		NVIC->NVIC_IPR[Copy_u8InterruptNum]=(Copy_u8GroupId<<7)|(Copy_u8SubGroupId<<4);

			break;

	case NVIC_GROUP0BITS_SUB4BITS:
		NVIC->NVIC_IPR[Copy_u8InterruptNum]=(Copy_u8SubGroupId<<4);

				break;

	}




	/*
	u8 local_u8priorityConfig=(u8)((StaticGlobal_u8priorityConfig>>8)& 0b111);
	u8 Local_u8priority1=((Copy_u8GroupId)<<(local_u8priorityConfig-3))|Copy_u8SubGroupId;
	NVIC->NVIC_IPR[Copy_u8InterruptNum]=(Local_u8priority1 <<4);
*/
}

void NVIC_voidSetPriorityConfig(u8 Copy_u8Priority)
{

	u32	LocalTempRegValue=(VEC_KEY<<16)|(Copy_u8Priority<<8);

	SCB->SCB_AIRCR &= (VEC_KEY<<16)|(0x111<<8);
	SCB->SCB_AIRCR =SCB->SCB_AIRCR|LocalTempRegValue;
	StaticGlobal_u8priorityConfig=Copy_u8Priority;



}

/*
	u16 vectkey=0x5FA;

	StaticGlobal_u8priorityConfig=((vectkey)<<16)|((Copy_u8Priority)<<8);

	SCB->SCB_AIRCR=StaticGlobal_u8priorityConfig;

*/
