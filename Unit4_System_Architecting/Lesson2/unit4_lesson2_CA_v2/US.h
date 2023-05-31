/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : unit4_lesson2_CA_v2                                 	 */
/* File          : US.h                                                  */
/* Date          : May 31, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef US_H_
#define US_H_

#include "state.h"
#include <stdio.h>
#include <stdlib.h>

/* Define states */
typedef enum{
	US_busy
}US_states;

/* State pointer to function */
extern void (*US_state)();

/* Declare states functions */
void US_init();
STATE_define(US_busy);


#endif /* US_H_ */
