/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : unit4_lesson2_CA_v2                                   */
/* File          : CA.h                                                  */
/* Date          : May 31, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef CA_H_
#define CA_H_

#include "state.h"
#include <stdio.h>

/* Define states */
typedef enum{
	CA_waiting,
	CA_driving
}CA_states;

/* State pointer to function */
extern void (*CA_state)();

/* Declare states functions */
STATE_define(CA_waiting);
STATE_define(CA_driving);

#endif /* CA_H_ */
