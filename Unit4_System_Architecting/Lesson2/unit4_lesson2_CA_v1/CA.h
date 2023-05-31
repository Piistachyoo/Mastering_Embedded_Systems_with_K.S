/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : unit4_lesson2_CA_v1                                   */
/* File          : CA.h                                                  */
/* Date          : May 30, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef CA_H_
#define CA_H_

#include "state.h"

/* Define states */
typedef enum{
	CA_waiting,
	CA_driving
}CA_states;

extern void (*CA_state)();

/* Declare states functions CA */
STATE_define(CA_waiting);
STATE_define(CA_driving);

#endif /* CA_H_ */
