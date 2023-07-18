/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : NVIC_driver.h 			                             */
/* Date          : Jun 20, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef INC_NVIC_DRIVER_H_
#define INC_NVIC_DRIVER_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include "STM32F103x8.h"

//----------------------------------------------
// Section: User type definitions
//----------------------------------------------



//----------------------------------------------
// Section: Macros Configuration References
//----------------------------------------------

#define SCB_VECTKEY					0x05FA0000UL
#define SCB_VECTKEY_MASK			0xFFFF0000UL
#define NVIC_PRIGROUP_SET_MASK		0x700UL
#define NVIC_PRIGROUP_CLEAR_MASK	0xFFFFF8FFUL

// @ref interrupt_status_define
#define NVIC_INTERRUPT_ACTIVE		1UL
#define NVIC_INTERRUPT_INACTIVE		0UL

// @ref priority_groups_define
#define NVIC_PRIO_16GRP_0SUBGRP		0x300U
#define NVIC_PRIO_8GRP_2SUBGRP		0x400U
#define NVIC_PRIO_4GRP_4SUBGRP		0x500U
#define NVIC_PRIO_2GRP_8SUBGRP		0x600U
#define NVIC_PRIO_0GRP_8SUBGRP		0x700U

// @ref Interrupt_Priorities_define
#define NVIC_PRIO_0000              0x00U
#define NVIC_PRIO_0001              0x10U
#define NVIC_PRIO_0010              0x20U
#define NVIC_PRIO_0011              0x30U
#define NVIC_PRIO_0100              0x40U
#define NVIC_PRIO_0101              0x50U
#define NVIC_PRIO_0110              0x60U
#define NVIC_PRIO_0111              0x70U
#define NVIC_PRIO_1000              0x80U
#define NVIC_PRIO_1001              0x90U
#define NVIC_PRIO_1010              0xA0U
#define NVIC_PRIO_1011              0xB0U
#define NVIC_PRIO_1100              0xC0U
#define NVIC_PRIO_1101              0xD0U
#define NVIC_PRIO_1110              0xE0U
#define NVIC_PRIO_1111              0xF0U

// @ref Interrupt_Requests_Numbers_define
#define EXTI0_IRQ	6
#define EXTI1_IRQ	7
#define EXTI2_IRQ	8
#define EXTI3_IRQ	9
#define EXTI4_IRQ	10
#define EXTI5_IRQ	23
#define EXTI6_IRQ	23
#define EXTI7_IRQ	23
#define EXTI8_IRQ	23
#define EXTI9_IRQ	23
#define EXTI10_IRQ	40
#define EXTI11_IRQ	40
#define EXTI12_IRQ	40
#define EXTI13_IRQ	40
#define EXTI14_IRQ	40
#define EXTI15_IRQ	40

#define USART1_IRQ	37
#define USART2_IRQ	38
#define USART3_IRQ	39

#define SPI1_IRQ	35
#define SPI2_IRQ	36

/*
 * =============================================
 * APIs Supported by "NVIC"
 * =============================================
 */

/**=============================================
  * @Fn				- MCAL_NVIC_SetPriorityGrouping
  * @brief 			- Set the priority grouping
  * @param [in] 	- priority_grouping: Configuration of priority grouping @ref priority_groups_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_NVIC_SetPriorityGrouping(uint32 priority_grouping);

/**=============================================
  * @Fn				- MCAL_NVIC_GetPriorityGrouping
  * @brief 			- Set the priority grouping
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- Configuration of priority grouping @ref priority_groups_define
  * Note			- None
  */
uint32 MCAL_NVIC_GetPriorityGrouping(void);

/**=============================================
  * @Fn				- MCAL_NVIC_EnableIRQ
  * @brief 			- Enable IRQn
  * @param [in] 	- IRQn: Number of interrupt request as defined in vector table or in @ref Interrupt_Requests_Numbers_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_NVIC_EnableIRQ(uint8 IRQn);

/**=============================================
  * @Fn				- MCAL_NVIC_DisableIRQ
  * @brief 			- Disable IRQn
  * @param [in] 	- IRQn: Number of interrupt request as defined in vector table or in @ref Interrupt_Requests_Numbers_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_NVIC_DisableIRQ(uint8 IRQn);

/**=============================================
  * @Fn				- MCAL_NVIC_GetPendingIRQ
  * @brief 			- Return true (IRQ-Number) if IRQn is pending
  * @param [in] 	- IRQn: Number of interrupt request as defined in vector table or in @ref Interrupt_Requests_Numbers_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
uint8 MCAL_NVIC_GetPendingIRQ(uint8 IRQn);

/**=============================================
  * @Fn				- MCAL_NVIC_SetPendingIRQ
  * @brief 			- Set IRQn pending
  * @param [in] 	- IRQn: Number of interrupt request as defined in vector table or in @ref Interrupt_Requests_Numbers_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_NVIC_SetPendingIRQ(uint8 IRQn);

/**=============================================
  * @Fn				- MCAL_NVIC_ClearPendingIRQ
  * @brief 			- Clear IRQn pending status
  * @param [in] 	- IRQn: Number of interrupt request as defined in vector table or in @ref Interrupt_Requests_Numbers_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_NVIC_ClearPendingIRQ(uint8 IRQn);

/**=============================================
  * @Fn				- MCAL_NVIC_GetActive
  * @brief 			- Return the IRQ number of the active interrupt
  * @param [in] 	- IRQn: Number of interrupt request as defined in vector table or in @ref Interrupt_Requests_Numbers_define
  * @param [out] 	- None
  * @retval 		- returns 1 or 0 based on @ref interrupt_status_define
  * Note			- None
  */
uint8 MCAL_NVIC_GetActive(uint8 IRQn);

/**=============================================
  * @Fn				- MCAL_NVIC_SetPriority
  * @brief 			- Set priority for IRQn
  * @param [in] 	- IRQn: Number of interrupt request as defined in vector table or in @ref Interrupt_Requests_Numbers_define
  * @param [in] 	- priority: priority of interrupt as defined in @ref Interrupt_Priorities_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_NVIC_SetPriority(uint8 IRQn, uint8 priority);

/**=============================================
  * @Fn				- MCAL_NVIC_GetPriority
  * @brief 			- Read priority of IRQn
  * @param [in] 	- IRQn: Number of interrupt request as defined in vector table or in @ref Interrupt_Requests_Numbers_define
  * @param [out] 	- Priority value, reutrn value should be one of values in @ref Interrupt_Requests_Numbers_define
  * @retval 		- None
  * Note			- None
  */
uint8 MCAL_NVIC_GetPriority(uint8 IRQn);

/**=============================================
  * @Fn				- MCAL_NVIC_SystemReset
  * @brief 			- Reset the system
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- None
  * Note			- Keeps priority groups unchanged
  */
void MCAL_NVIC_SystemReset(void);

#endif /* INC_NVIC_DRIVER_H_ */
