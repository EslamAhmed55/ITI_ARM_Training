/*
 * Flash_Private.h
 *
 *  Created on: Sep 5, 2023
 *      Author: eslam
 */

#ifndef FLASH_PRIVATE_H_
#define FLASH_PRIVATE_H_




typedef struct
{

	  volatile u32 FLASH_ACR   ;
	  volatile u32 FLASH_KEYR    ;
	  volatile u32 FLASH_OPTKEYR    ;
	  volatile u32 FLASH_SR    ;
	  volatile u32 FLASH_CR    ;
	  volatile u32 FLASH_OPTCR    ;
}FLASH_t;


#define FLASH_BASE_ADDRESS			0x40023C00
#define FLASH				((FLASH_t *)FLASH_BASE_ADDRESS)

#define FLASH_KEY1			0x45670123U
#define FLASH_KEY2			0xCDEF89ABU

#define  FLASH_CR_SNB_MASK			0x00000078

#endif /* FLASH_PRIVATE_H_ */
