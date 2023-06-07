/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : unit7_lesson1_section                                 */
/* File          : MemMap.h                                              */
/* Date          : Jun 7, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef MEMMAP_H_
#define MEMMAP_H_

//PORT A
#define PORTA_REG *((volatile unsigned char*) 0x3B)
#define DDRA_REG  *((volatile unsigned char*) 0x3A)
#define PINA_REG  *((volatile unsigned char*) 0x39)

//PORT B
#define PORTB_REG *((volatile unsigned char*) 0x38)
#define DDRB_REG  *((volatile unsigned char*) 0x37)
#define PINB_REG  *((volatile unsigned char*) 0x36)

//PORT C
#define PORTC_REG *((volatile unsigned char*) 0x35)
#define DDRC_REG  *((volatile unsigned char*) 0x34)
#define PINC_REG  *((volatile unsigned char*) 0x33)

//PORT D
#define PORTD_REG *((volatile unsigned char*) 0x32)
#define DDRD_REG  *((volatile unsigned char*) 0x31)
#define PIND_REG  *((volatile unsigned char*) 0x30)

#endif /* MEMMAP_H_ */
