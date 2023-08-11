/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : NVIC_driver.c 			                             */
/* Date          : Jun 20, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "NVIC_driver.h"

/**=============================================
  * @Fn				- MCAL_NVIC_SetPriorityGrouping
  * @brief 			- Set the priority grouping
  * @param [in] 	- priority_grouping: Configuration of priority grouping @ref priority_groups_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_NVIC_SetPriorityGrouping(uint32 priority_grouping){
	uint32 reg_value;

	/* Make sure only bits 8-10 are set */
	priority_grouping &= NVIC_PRIGROUP_SET_MASK;

	/* Get current register status */
	reg_value = SCB->AIRCR;

	/* Convert VECTKEYSTAT to VECTKEY */
	reg_value ^= SCB_VECTKEY_MASK;

	/* Clear previous priority grouping configuration */
	reg_value &= NVIC_PRIGROUP_CLEAR_MASK;

	/* Add current configuration */
	reg_value |= priority_grouping;

	/* Set value back to register */
	SCB->AIRCR = reg_value;
}

/**=============================================
  * @Fn				- MCAL_NVIC_GetPriorityGrouping
  * @brief 			- Set the priority grouping
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- Configuration of priority grouping @ref priority_groups_define
  * Note			- None
  */
uint32 MCAL_NVIC_GetPriorityGrouping(void){
	return ((SCB->AIRCR & NVIC_PRIGROUP_SET_MASK) >> 8);
}

/**=============================================
  * @Fn				- MCAL_NVIC_EnableIRQ
  * @brief 			- Enable IRQn
  * @param [in] 	- IRQn: Number of interrupt request as defined in vector table or in @ref Interrupt_Requests_Numbers_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_NVIC_EnableIRQ(uint8 IRQn){
	/* Check which ISER register to write into */
	uint8 reg_index = IRQn/32;

	/* Get IRQn with respect to current register */
	uint8 IRQ_index = IRQn%32;

	NVIC->ISER[reg_index] = (1U<<IRQ_index);
}

/**=============================================
  * @Fn				- MCAL_NVIC_DisableIRQ
  * @brief 			- Disable IRQn
  * @param [in] 	- IRQn: Number of interrupt request as defined in vector table or in @ref Interrupt_Requests_Numbers_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_NVIC_DisableIRQ(uint8 IRQn){
	/* Check which ICER register to write into */
	uint8 reg_index = IRQn/32;

	/* Get IRQn with respect to current register */
	uint8 IRQ_index = IRQn%32;

	NVIC->ICER[reg_index] = (1U<<IRQ_index);
}

/**=============================================
  * @Fn				- MCAL_NVIC_GetPendingIRQ
  * @brief 			- Return true (IRQ-Number) if IRQn is pending
  * @param [in] 	- IRQn: Number of interrupt request as defined in vector table or in @ref Interrupt_Requests_Numbers_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
uint8 MCAL_NVIC_GetPendingIRQ(uint8 IRQn){
    uint8 ret_val;
    /* Check which ISPR register to write into */
	uint8 reg_index = IRQn/32;

	/* Get IRQn with respect to current register */
	uint8 IRQ_index = IRQn%32;

    ret_val = ((NVIC->ISPR[reg_index])>>IRQ_index) & 0x01UL;
    return ret_val;
}

/**=============================================
  * @Fn				- MCAL_NVIC_SetPendingIRQ
  * @brief 			- Set IRQn pending
  * @param [in] 	- IRQn: Number of interrupt request as defined in vector table or in @ref Interrupt_Requests_Numbers_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
 void MCAL_NVIC_SetPendingIRQ(uint8 IRQn){
    /* Check which ISPR register to write into */
	uint8 reg_index = IRQn/32;

	/* Get IRQn with respect to current register */
	uint8 IRQ_index = IRQn%32;

    NVIC->ISPR[reg_index] |= (1UL<<IRQ_index);
 }

/**=============================================
  * @Fn				- MCAL_NVIC_ClearPendingIRQ
  * @brief 			- Clear IRQn pending status
  * @param [in] 	- IRQn: Number of interrupt request as defined in vector table or in @ref Interrupt_Requests_Numbers_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_NVIC_ClearPendingIRQ(uint8 IRQn){
    /* Check which ICPR register to write into */
	uint8 reg_index = IRQn/32;

	/* Get IRQn with respect to current register */
	uint8 IRQ_index = IRQn%32;

    NVIC->ICPR[reg_index] |= (1U<<IRQ_index);
}

/**=============================================
  * @Fn				- MCAL_NVIC_GetActive
  * @brief 			- Return the IRQ number of the active interrupt
  * @param [in] 	- IRQn: Number of interrupt request as defined in vector table or in @ref Interrupt_Requests_Numbers_define
  * @param [out] 	- None
  * @retval 		- returns 1 or 0 based on @ref interrupt_status_define
  * Note			- None
  */
uint8 MCAL_NVIC_GetActive(uint8 IRQn){
	uint8 ret_val;

	/* Check which ICPR register to write into */
	uint8 reg_index = IRQn/32;

	/* Get IRQn with respect to current register */
	uint8 IRQ_index = IRQn%32;

	if(NVIC->IABR[reg_index] & (0x01UL<<IRQ_index)){
		ret_val = NVIC_INTERRUPT_ACTIVE;
	}
	else{ ret_val = NVIC_INTERRUPT_INACTIVE; }

    return ret_val;
}

/**=============================================
  * @Fn				- MCAL_NVIC_SetPriority
  * @brief 			- Set priority for IRQn
  * @param [in] 	- IRQn: Number of interrupt request as defined in vector table or in @ref Interrupt_Requests_Numbers_define
  * @param [in] 	- priority: priority of interrupt as defined in @ref Interrupt_Priorities_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_NVIC_SetPriority(uint8 IRQn, uint8 priority){
    /* Check which IPR register to write into */
	uint8 reg_index = IRQn/32;

	/* Get IRQn with respect to current register */
	uint8 IRQ_index = IRQn%32;

    NVIC->IP[(4*reg_index + IRQ_index)] = priority;
}

/**=============================================
  * @Fn				- MCAL_NVIC_GetPriority
  * @brief 			- Read priority of IRQn
  * @param [in] 	- IRQn: Number of interrupt request as defined in vector table or in @ref Interrupt_Requests_Numbers_define
  * @param [out] 	- Priority value, reutrn value should be one of values in @ref Interrupt_Requests_Numbers_define
  * @retval 		- None
  * Note			- None
  */
uint8 MCAL_NVIC_GetPriority(uint8 IRQn){
    /* Check which IPR register to write into */
	uint8 reg_index = IRQn/32;

	/* Get IRQn with respect to current register */
	uint8 IRQ_index = IRQn%32;

    return NVIC->IP[(4*reg_index + IRQ_index)];
}

/**=============================================
  * @Fn				- MCAL_NVIC_SystemReset
  * @brief 			- Reset the system
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- None
  * Note			- Keeps priority groups unchanged
  */
void MCAL_NVIC_SystemReset(void){
    SCB->AIRCR = SCB_VECTKEY | (SCB->AIRCR & NVIC_PRIGROUP_SET_MASK) | (1UL << 2);

    /* Wait until reset */
    while(1);
}
