/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : LIFO_buffer                                    	 	 */
/* File          : lifo.h                           					 */
/* Date          : May 29, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef LIFO_H_
#define LIFO_H_

#include <stdio.h>
#include <stdlib.h>

/* Type Definitions */
typedef struct{
	unsigned int  length;
	unsigned int  count;
	unsigned int* base;
	unsigned int* head;
}LIFO_Buf_t;

typedef enum{
	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFO_EMPTY,
	LIFO_NULL
}LIFO_status_t;

/* APIs */
LIFO_status_t LIFO_Init(LIFO_Buf_t* lifo_buf, unsigned int* buff_base, unsigned int size);
LIFO_status_t LIFO_Add_Item(LIFO_Buf_t* lifo_buf, unsigned int item);
LIFO_status_t LIFO_Get_Item(LIFO_Buf_t* lifo_buf, unsigned int *item);


#endif /* LIFO_H_ */
