/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : FIFO_buffer                                    		 */
/* File          : fifo.h                                                */
/* Date          : May 29, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef FIFO_H_
#define FIFO_H_

#include <stdio.h>
#include <stdint.h>

/* User Configuration */

/* Select element data type (uint8_t/uint16_t/uint32_t/...) */
#define	element_type uint8_t

/* Select buffer width */
#define width 5

/* Create your buffer below or in your application */
//element_type buffer[width];

/* Data Types */

typedef struct{
	unsigned int  length;
	unsigned int  count;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_buffer_t;

typedef enum{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL
}FIFO_buffer_status;

/* APIs */
FIFO_buffer_status FIFO_Init(FIFO_buffer_t* fifo, element_type* buffer, unsigned int length);
FIFO_buffer_status FIFO_Enqueue(FIFO_buffer_t* fifo, element_type item);
FIFO_buffer_status FIFO_Dequeue(FIFO_buffer_t* fifo, element_type* item);
FIFO_buffer_status FIFO_IS_FULL(FIFO_buffer_t* fifo);
void FIFO_Print(FIFO_buffer_t* fifo);

#endif /* FIFO_H_ */
