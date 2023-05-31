/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : unit4_lesson2_CA_v1                                   */
/* File          : main.c                                                */
/* Date          : May 30, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "CA.h"

void setup(){
	/* Init drivers */
	/* Init IRQ */
	/* Init HAL US_Driver DC_Driver */
	/* Init Block */
	/* Set states pointers for each block */
	CA_state = STATE(CA_waiting);
}

int main(){
	setup();
	while(1){
		CA_state();
	}
	return 0;
}
