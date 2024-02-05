/*
 * GPIO.h
 *
 *  Created on: Aug 12, 2023
 *      Author: eslam
 */

#include "STM32F401CC.h"



//configure structure (informations of Pins )

typedef struct
{
	uint16_t GPIO_PinNumber; // specifies the GPIO pins to be configured
	//this parameter must be set based on  @reference GPOI_PINS _define

	uint8_t GPIO_MODER;  // specifies GPIO_MODE for the selected pin
	//this parameter must be set based on @reference GPOI_MODER _define

	uint8_t GPIO_OTYPER	;// specifies GPIO_OUTPUT_Type for the selected pin
	//this parameter must be set based on @reference GPIO_OUTPUT_Type

	uint8_t GPIO_OSPEEDR ;// specifies Speed for the selected pin
	//this parameter must be set based on  @reference GPOI_Speed _define

	uint8_t GPIO_PUPDR;// specifies configure the I/O pull-up or pull-down for the selected pin
	//this parameter must be set based on  @reference GPOI_GPIO_PUPDR_define

	uint8_t GPIO_AFIO; // specifies configure the I/O AFIO for the selected pin
	//this parameter must be set based on  @reference GPIO_AFIO_define

}GPIO_PinConfig;






//@reference GPOI_PINS _define
#define GPIO_PIN_0					((uint16_t)0x0001) /*Pin 0 selected */
#define GPIO_PIN_1					((uint16_t)0x0002) /*Pin 1 selected ((With HEXA ) 10) */
#define GPIO_PIN_2					((uint16_t)0x0004) /*Pin 2 selected  ((With HEXA ) 100) */
#define GPIO_PIN_3					((uint16_t)0x0008) /*Pin 3 selected  ((With HEXA ) 1000) */
#define GPIO_PIN_4					((uint16_t)0x0010) /*Pin 4 selected */
#define GPIO_PIN_5					((uint16_t)0x0020) /*Pin 5 selected */
#define GPIO_PIN_6					((uint16_t)0x0040) /*Pin 6 selected */
#define GPIO_PIN_7					((uint16_t)0x0080) /*Pin 7 selected */
#define GPIO_PIN_8					((uint16_t)0x0100) /*Pin 8 selected */
#define GPIO_PIN_9					((uint16_t)0x0200) /*Pin 9 selected */
#define GPIO_PIN_10					((uint16_t)0x0400) /*Pin 10 selected */
#define GPIO_PIN_11					((uint16_t)0x0800) /*Pin 11 selected */
#define GPIO_PIN_12					((uint16_t)0x1000) /*Pin 12 selected */
#define GPIO_PIN_13				    ((uint16_t)0x2000) /*Pin 13 selected */
#define GPIO_PIN_14				    ((uint16_t)0x4000) /*Pin 14 selected */
#define GPIO_PIN_15					((uint16_t)0x8000) /*Pin 15 selected */
#define GPIO_PIN_ALL				((uint16_t)0xFFFF) /*Pin ALL selected */




//GPIO_Pin_State
#define GPIO_PIN_SET		1
#define GPIO_PIN_RESET		0




//@ @reference GPOI_MODER _define


/*
 *  MODERy[1:0]: Port x configuration bits (y = 0..15)
These bits are written by software to configure the I/O direction mode.
00: Input (reset state)
01: General purpose output mode
10: Alternate function mode
11: Analog mode
 *
 */

#define		 GPIO_Input									0b00
#define		 GPIO_output_mode							0b01
#define		 AFIO										0b10
#define		 Analog_mode								0b11





//@reference GPOI_Speed _define
/*
00: Low speed
01: Medium speed
10: High speed
11: Very high speed
 */

#define GPIO_Low_speed								0b00
#define GPIO_Medium_speed							0b01
#define GPIO_High_speed								0b10
#define GPIO_VeryHigh_speed							0b11


//@reference GPIO_OUTPUT_Type

/*
 * Bits 15:0 OTy: Port x configuration bits (y = 0..15)
These bits are written by software to configure the output type of the I/O port.
0: Output push-pull (reset state)
1: Output open-drain
 */

#define	GPIO_Output_Push_Pull				0
#define	GPIO_Output_Open_Drain				1




//@reference GPOI_GPIO_PUPDR_define

/*
 *  PUPDRy[1:0]: Port x configuration bits (y = 0..15)
These bits are written by software to configure the I/O pull-up or pull-down
00: No pull-up, pull-down
01: Pull-up
10: Pull-down
11: Reserved
 */

#define GPIO_NoPull_Up_NoPull_down			0b00
#define GPIO_Pull_Up						0b01
#define GPIO_Pull_Down						0b10
#define GPIO_Reserved						0b11





//GPIO_RETURN_LOCK

/*
 * Bit 16 LCKK[16]: Lock key
This bit can be read any time. It can only be modified using the lock key write sequence.
0: Port configuration lock key not active
1: Port configuration lock key active. The GPIOx_LCKR register is locked until an MCU reset
or a peripheral reset occurs.
LOCK key write sequence:
WR LCKR[16] = ‘1’ + LCKR[15:0]
WR LCKR[16] = ‘0’ + LCKR[15:0]
WR LCKR[16] = ‘1’ + LCKR[15:0]
RD LCKR
RD LCKR[16] = ‘1’ (this read operation is optional but it confirms that the lock is active)
Note: During the LOCK key write sequence, the value of LCK[15:0] must not change.
Any error in the lock sequence aborts the lock.
After the first lock sequence on any bit of the port, any read access on the LCKK bit will
return ‘1’ until the next CPU reset.
Bits 15:0 LCKy: Port x lock bit y (y= 0..15)
These bits are read/write but can only be written when the LCKK bit is ‘0.
0: Port configuration not locked
1: Port configuration locked
 */
#define GPIO_RETURN_LOCK_Enable		1
#define GPIO_RETURN_LOCK_ERROR		0



//@reference GPIO_AFIO_define

#define AFIO0				0x0
#define AFIO1				0x1
#define AFIO2				0x2
#define AFIO3				0x3
#define AFIO4				0x4
#define AFIO5				0x5
#define AFIO6				0x6
#define AFIO7				0x7
#define AFIO8				0x8
#define AFIO9				0x9
#define AFIO10				0xA
#define AFIO11				0xB
#define AFIO12				0xC
#define AFIO13				0xD
#define AFIO14				0xE
#define AFIO15				0xF






//==========================================================================
//____________________________________________________________
//                APIS Supported by " MCAL GPIO DRIVER"
//____________________________________________________________
void MCAL_GPIO_Init(GPIO_t *GPIOx, GPIO_PinConfig *PinConfig);
void MCAL_GPIO_DeInit(GPIO_t *GPIOx);
uint8_t MCAL_GPIO_ReadPin (GPIO_t *GPIOx , uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort (GPIO_t *GPIOx);
uint8_t MCAL_GPIO_WritePin (GPIO_t *GPIOx , uint16_t PinNumber , uint8_t Value);
uint16_t MCAL_GPIO_WritePort (GPIO_t *GPIOx , uint16_t Value );
uint8_t MCAL_GPIO_TogglePin (GPIO_t *GPIOx , uint16_t PinNumber);
uint8_t MCAL_GPIO_LockPin (GPIO_t *GPIOx , uint16_t PinNumber);
void MCAL_GPIO_AFIO(GPIO_t *GPIOx,GPIO_PinConfig *PinConfig,uint32_t* configregister);
void MCAL_GPIO_SetSpeed (GPIO_t *GPIOx,GPIO_PinConfig *PinConfig);
