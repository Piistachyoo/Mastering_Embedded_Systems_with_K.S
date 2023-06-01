/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Student_Information_Management                        */
/* File          : students.h                                            */
/* Date          : Jun 1, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef STUDENTS_H_
#define STUDENTS_H_

/* Section: Includes */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

/* Section: Macros */
#define DPRINTF(...) fflush(stdin); fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdin); fflush(stdout);

#define CHECK_BEFORE_CLEAR()	DPRINTF("\nPress any key to continue....");\
								getch();

/* Section: Data Type Declarations */
#pragma pack(1)
typedef struct{
	char First_Name[50];
	char Last_Name[50];
	uint32_t Roll_Number;
	float GPA;
	uint16_t courses_ids[5];
}students_info;
#pragma pack()

#include "fifo.h"

/* Section: API Declarations */
void Add_Student_File();
void Add_Student_Manually();
void Find_By_RollNum();
void Find_By_FirstName();
void Find_By_Courses();
void Get_Students_Count();
void Delete_Student();
void Update_Student();
void Print_Students();

#endif /* STUDENTS_H_ */
