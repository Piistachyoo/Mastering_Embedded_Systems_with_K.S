/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Smart_Car_Parking_STM32F103  	                     */
/* File          : main.c 			                            		 */
/* Date          : Aug 3, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "app_states.h"

extern void (*fp_App_State_Handler)();

int main(){
	/* The system will initialize and run based on a state machine no need to do anything in main */
	while(1)
		fp_App_State_Handler();
	return 0;
}
