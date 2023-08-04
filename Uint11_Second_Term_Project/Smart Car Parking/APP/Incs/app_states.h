/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Smart_Car_Parking_STM32F103  	                     */
/* File          : app_states.h 			                             */
/* Date          : Aug 3, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef INCS_APP_STATES_H_
#define INCS_APP_STATES_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include "ecu.h"

//----------------------------------------------
// Section: User type definitions
//----------------------------------------------
typedef enum{
	Init_STATE,
	Admin_STATE,
	Idle_STATE,
	Enter_Gate_STATE,
	Exit_Gate_STATE,
	Full_STATE
}STATES;

//----------------------------------------------
// Section: Macros Configuration References
//----------------------------------------------

#define STATE_API(_NAME)	void ST_##_NAME (void)
#define STATE_NAME(_NAME)	ST_##_NAME


/*
 * =============================================
 * APIs Supported by "app_states"
 * =============================================
 */

STATE_API(Init_STATE);
STATE_API(Admin_STATE);
STATE_API(Idle_STATE);
STATE_API(Enter_Gate_STATE);
STATE_API(Exit_Gate_STATE);
STATE_API(Full_STATE);

#endif /* INCS_APP_STATES_H_ */
