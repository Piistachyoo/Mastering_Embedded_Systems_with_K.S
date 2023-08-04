/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : systick_driver.h			                             */
/* Date          : Jun 20, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef MCAL_INC_SYSTICK_DRIVER_H_
#define MCAL_INC_SYSTICK_DRIVER_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include <STM32F103x8.h>

//----------------------------------------------
// Section: User type definitions
//----------------------------------------------
typedef struct{
	uint8  running_mode; 	 // @ref stk_running_mode_define
	uint8  clock_config; 	 // @ref stk_clock_config_define
	uint8  interrupt_config; // @ref stk_interrupt_config_define
	uint32 reload_value;
	void (*Callback_Function)(void);
}STK_config_t;

//----------------------------------------------
// Section: Macros Configuration References
//----------------------------------------------

#define STK_INTERRUPT_MASK		0x02UL
#define STK_CLK_MASK			0x04UL
#define STK_RELOAD_MASK			0x00FFFFFFUL

// @ref stk_cpu_freq_define
#define STK_FCPU				8000000UL

// @ref stk_interrupt_config_define
#define STK_INTERRUPT_ENABLED	0x02UL
#define STK_INTERRUPT_DISABLED	0x00UL

// @ref stk_clock_config_define
#define STK_CLK_AHB				0x04UL
#define STK_CLK_AHB_8			0x00UL

// @ref stk_running_mode_define
#define STK_PERIODIC_MODE		0x01U
#define STK_ONE_SHOT_MODE		0x00U

/*
 * =============================================
 * APIs Supported by "SysTick"
 * =============================================
 */

/**=============================================
  * @Fn				- MCAL_STK_Config
  * @brief 			- Configures the SysTick clock and interrupt
  * @param [in] 	- _cfg: Pointer to struct containing systick configuration
  * @param [out] 	- None
  * @retval 		- None
  * Note			- This function stops the timer and you have to re-enable it
  */
void MCAL_STK_Config(STK_config_t *_cfg);

/**=============================================
  * @Fn				- MCAL_STK_SetReload
  * @brief 			- Sets the reload value of the SysTick timer
  * @param [in] 	- value: Value to be set as reload value
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_STK_SetReload(uint32 value);

/**=============================================
  * @Fn				- MCAL_STK_SetCallback
  * @brief 			- Sets the callback function of the systick timer interrupt
  * @param [in] 	- pfCallback: Pointer to the callback function
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_STK_SetCallback(void (*pfCallback)(void));

/**=============================================
  * @Fn				- MCAL_STK_StartTimer
  * @brief 			- Starts the SysTick timer
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- None
  * Note			- MCAL_STK_Config should be called first to configure the SysTick timer unless you want to use the default values
  */
void MCAL_STK_StartTimer();

/**=============================================
  * @Fn				- MCAL_STK_StopTimer
  * @brief 			- Stops the SysTick timer
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_STK_StopTimer();

/**=============================================
  * @Fn				- MCAL_STK_Delay
  * @brief 			- Starts the SysTick timer one time for specific number of ticks
  * @param [in] 	- delay_ticks: Number of ticks required
  * @param [out] 	- None
  * @retval 		- None
  * Note			- Restores previous configuration and reload value of the SysTick timer
  */
void MCAL_STK_Delay(uint32 delay_ticks);

/**=============================================
  * @Fn				- MCAL_STK_Delay1ms
  * @brief 			- Delays the system for specific number of milliseconds
  * @param [in] 	- delay_ms: Number of milliseconds delay needed
  * @param [out] 	- None
  * @retval 		- None
  * Note			- User must define the frequency of the SysTick timer in @ref stk_cpu_freq_define
  */
void MCAL_STK_Delay1ms(uint32 delay_ms);

#endif /* MCAL_INC_SYSTICK_DRIVER_H_ */
