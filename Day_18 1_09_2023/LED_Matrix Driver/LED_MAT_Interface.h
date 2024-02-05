/*
 * LED_MAT_Interface.h
 *
 *  Created on: Sep 1, 2023
 *      Author: eslam
 */

#ifndef LED_MAT_INTERFACE_H_
#define LED_MAT_INTERFACE_H_

void LED_MAT_voidInit();
void LED_MAT_voidClearDispaly(void);
void LED_MAT_voidClearColumns(void);
void LED_MAT_voidClearROWS(void);
void LED_MAT_voidSETRow(u8 Copy_RowValue);
void LED_MAT_Display(u8 *Copy_Frame);

#endif /* LED_MAT_INTERFACE_H_ */
