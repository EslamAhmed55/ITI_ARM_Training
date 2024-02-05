#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_



#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "SYSTICK_INTERFACE.h"
#include "SYSTICK_PRIVATE.h"
#include "SYSTICK_CONFIG.h"






void SysTick_vInit(void);
void SysTick_vDisable(void);
void SysTick_Delay_(u32 Delay);
void SysTick_SingleInterval(u32 Ticks , ptrFunction *CallBack);
void SysTick_PeriodicInterval(u32 Ticks , ptrFunction *CallBack);
u32 SysTick_u32GET_Remain(void);
u32 STK_uint32GET_Done(void);




#endif /* SYSTICK_INTERFACE_H_ */