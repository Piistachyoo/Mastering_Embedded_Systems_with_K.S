/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Student_Information_Management                        */
/* File          : fifo.c                           					 */
/* Date          : Jun 1, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef FIFO_H_
#define FIFO_H_

#include <stdint.h>
#include "students.h"

/* Section: Macros */
#define element_type students_info
#define ROLL_NUMBER_UNIQUE	 0
#define ROLL_NUMBER_REPEATED 1

/* Section: Data Types Declaration */
typedef struct{
	element_type *base;
	element_type *head;
	element_type *tail;
	uint16_t count;
	uint16_t length;
}FIFO_t;

typedef enum{
	FIFO_NO_ERROR,
	FIFO_NULL,
	FIFO_FULL,
	FIFO_EMPTY
}FIFO_error_enu;

/* APIs Declarations */
FIFO_error_enu FIFO_init(FIFO_t *fifo, element_type *buffer, uint16_t length);
uint8_t FIFO_RollNum_Check(FIFO_t *fifo, uint32_t Number);
FIFO_error_enu FIFO_Enqueue(FIFO_t *fifo, element_type item);
FIFO_error_enu FIFO_IS_FULL(FIFO_t *fifo);
FIFO_error_enu FIFO_Remove(FIFO_t *fifo, uint32_t Number);
FIFO_error_enu FIFO_Print_RollNum(FIFO_t *fifo, uint32_t Number);
FIFO_error_enu FIFO_Print_First_Name(FIFO_t *fifo, char Name[]);
FIFO_error_enu FIFO_Print_Course(FIFO_t *fifo, uint16_t course_no);
FIFO_error_enu FIFO_print_all(FIFO_t *fifo);
FIFO_error_enu FIFO_Update_Student(FIFO_t *fifo, uint32_t Number);


#endif /* FIFO_H_ */
