/*
 * STP_Interface.h
 *
 *  Created on: Aug 22, 2023
 *      Author: eslam
 */

#ifndef STP_INTERFACE_H_
#define STP_INTERFACE_H_
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "SysTick_Interface.h"

#include "STP_Config.h"






void STP_vInit(void);
void STP_vDisplayData(uint8_t  Data);


#endif 
