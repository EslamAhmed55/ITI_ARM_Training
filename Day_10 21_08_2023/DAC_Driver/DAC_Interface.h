/*
 * DAC_Interface.h
 *
 *  Created on: Aug 21, 2023
 *      Author: eslam
 */

#ifndef DAC_INTERFACE_H_
#define DAC_INTERFACE_H_


// you  should call STK_Init() during implement this function
void DACvoidInit(void);
void DACvoidPlay(void);
void DACvoidRun(void);

void DAC_voidCallback(void);
#endif /* DAC_INTERFACE_H_ */
