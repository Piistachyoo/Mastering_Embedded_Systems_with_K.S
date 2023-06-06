/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : EXTI                                    				 */
/* File          : main.c                          						 */
/* Date          : Jun 6, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#define F_CPU 8000000UL

int main(){
	/* Configure GPIO PORTS */
	DDRD = 0b11100000;

	/* Configure EXTI */
	GICR = 0b11100000;
	MCUCR = 0b00001101;
	MCUCSR &= ~(1<<6);

	/* Enable global interrupts */
	sei();

	while(1){
		PORTD = 0;

	}
	return 0;
}

ISR(INT0_vect){
	PORTD |= (1<<5);
	_delay_ms(1000);
}

ISR(INT1_vect){
	PORTD |= (1<<6);
	_delay_ms(1000);
}

ISR(INT2_vect){
	PORTD |= (1<<7);
	_delay_ms(1000);
}
