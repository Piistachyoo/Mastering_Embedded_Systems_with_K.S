/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : unit4_lesson2_CA_v2                                   */
/* File          : DC.h                                                  */
/* Date          : May 31, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef DC_H_
#define DC_H_

#include "state.h"
#include <stdio.h>

/* Define states */
typedef enum{
	DC_idle,
	DC_busy
}DC_states;

/* State pointer to function */
extern void (*DC_state)();

/* Declare states functions */
void DC_init();
STATE_define(DC_idle);
STATE_define(DC_busy);

#endif /* DC_H_ */
