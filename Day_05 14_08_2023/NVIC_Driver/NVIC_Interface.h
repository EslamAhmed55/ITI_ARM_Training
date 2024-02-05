/*
 * NVIC_Interface.h
 *
 *  Created on: Aug 15, 2023
 *      Author: eslam
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

/*  Enable interrupt */

void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptNum);
void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptNum);
void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptNum);
void NVIC_voidClearPending(u8 Copy_u8InterruptNum);
void NVIC_u8GetInterruptState(u8 Copy_u8InterruptNum);
void NVIC_voidSetInterruptPriorityConfig(u8 Copy_u8InterruptNum, u8 Copy_u8GroupId , u8 Copy_u8SubGroupId);

void NVIC_voidSetPriorityConfig(u8 Copy_u8Priority);

#define NVIC_GROUP4BITS_SUB0BITS		0b011
#define NVIC_GROUP3BITS_SUB1BITS		0b100
#define NVIC_GROUP2BITS_SUB2BITS		0b101
#define NVIC_GROUP1BITS_SUB3BITS		0b110
#define NVIC_GROUP0BITS_SUB4BITS		0b111



#endif /* NVIC_INTERFACE_H_ */
