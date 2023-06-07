/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : unit7_lesson1_section                                 */
/* File          : main.c                              	 			   	 */
/* Date          : Jun 7, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "MemMap.h"
#include "Utils.h"
#include "util/delay.h"

int main(){
	DDRD_REG = 0b11110000;

	while(1){
		if(GET_BIT(PIND_REG, 0) == 1){
			SET_BIT(PORTD_REG, 4);
			_delay_ms(500);
			CLR_BIT(PORTD_REG, 4);
			while(GET_BIT(PIND_REG, 0) == 1);
		}
		else if(GET_BIT(PIND_REG, 1) == 1){
			SET_BIT(PORTD_REG, 5);
			_delay_ms(200);
			SET_BIT(PORTD_REG, 6);
			_delay_ms(200);
			SET_BIT(PORTD_REG, 7);
			_delay_ms(200);
			CLR_BIT(PORTD_REG, 7);
			_delay_ms(200);
			CLR_BIT(PORTD_REG, 6);
			_delay_ms(200);
			CLR_BIT(PORTD_REG, 5);
			_delay_ms(200);
			while(GET_BIT(PIND_REG, 1) == 1);
		}
		else if(GET_BIT(PIND_REG, 2) == 1){
			if((PIND_REG&0b11100000) == 0b00000000){
				SET_BIT(PORTD_REG, 7);
			}
			else if((PIND_REG&0b11100000) == 0b10000000){
				SET_BIT(PORTD_REG, 6);
			}
			else if((PIND_REG&0b11100000) == 0b11000000){
				SET_BIT(PORTD_REG, 5);
			}
			else if((PIND_REG&0b11100000) == 0b11100000){
				CLR_BIT(PORTD_REG, 7);
			}
			else if((PIND_REG&0b11100000) == 0b01100000){
				CLR_BIT(PORTD_REG, 6);
			}
			else if((PIND_REG&0b11100000) == 0b00100000){
				CLR_BIT(PORTD_REG, 5);
			}
			while(GET_BIT(PIND_REG, 2) == 1);
		}
	}
	return 0;
}
