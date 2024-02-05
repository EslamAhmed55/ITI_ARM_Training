/*
 * Flash_Interface.h
 *
 *  Created on: Sep 5, 2023
 *      Author: eslam
 */

#ifndef FLASH_INTERFACE_H_
#define FLASH_INTERFACE_H_

u8 Flash_Unlook();
u8 Flash_look();


u8 Flash_u8EraseSector(u8 Copy_u32Sector);

u8 Flash_u8Write(u32 Copy_u32Address, u32* ptr_u32Data, u32 Copy_u32Length);






#endif /* FLASH_INTERFACE_H_ */
