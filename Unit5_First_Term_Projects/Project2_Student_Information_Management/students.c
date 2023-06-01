/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Student_Information_Management                        */
/* File          : students.c                                            */
/* Date          : Jun 1, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "students.h"

extern FIFO_t FIFO_Students;
extern students_info myStudents[50];

void Add_Student_File(){
	students_info new_student;
	FILE *file = fopen("students_data.txt", "r");
	int found_count = 0;
	if(!file){
		DPRINTF("[ERROR] Couldn't import data from file (file was not found)!\n");
		CHECK_BEFORE_CLEAR();
	}
	else{
		while(!feof(file)){
			fscanf(file, "%d", &(new_student.Roll_Number));
			if(ROLL_NUMBER_REPEATED == FIFO_RollNum_Check(&FIFO_Students, new_student.Roll_Number)){
				DPRINTF("[ERROR] Roll Number %d is repeated!\n", new_student.Roll_Number);
				fscanf(file, "%*[^\n]");
			}
			else{
				fscanf(file, "%s", new_student.First_Name);
				fscanf(file, "%s", new_student.Last_Name);
				fscanf(file, "%f", &(new_student.GPA));
				for(int i = 0; i < 5; i++){
					fscanf(file, "%u", &(new_student.courses_ids[i]));
				}
				if(FIFO_NO_ERROR == FIFO_Enqueue(&FIFO_Students, new_student)){
					DPRINTF("[INFO] Added %s with roll number %d!\n", new_student.First_Name, new_student.Roll_Number);
					found_count++;
				}
				else{
					DPRINTF("[ERROR] Couldn't add user with roll number: %d", new_student.Roll_Number);
				}
			}
			DPRINTF("----------------------\n");
		}
		DPRINTF("[INFO] Added %d users!\n", found_count);
		DPRINTF("--------------------------------------------\n");
		DPRINTF("[INFO] The total number of students is %d\n", FIFO_Students.count);
		DPRINTF("[INFO] You can add up to %d Students\n", FIFO_Students.length);
		DPRINTF("[INFO] You can add %d more students\n", (FIFO_Students.length - FIFO_Students.count));
		CHECK_BEFORE_CLEAR();
	}
}

void Add_Student_Manually(){
	students_info new_student;
	char temp[50];
	system("cls");
	DPRINTF("Add the students Details\n");
	DPRINTF("------------------------\n\n");
	DPRINTF("Enter the unique Roll Number: ");
	getchar();
	gets(temp);
	if(FIFO_RollNum_Check(&FIFO_Students, atoi(temp))){
		DPRINTF("Roll number is not unique, please retry with another one!\n");
		CHECK_BEFORE_CLEAR();
	}
	else{
		new_student.Roll_Number = atoi(temp);
		DPRINTF("Enter the first name of student: ");
		gets(temp);
		strcpy((char*)new_student.First_Name, temp);
		DPRINTF("Enter the last name of student: ");
		gets(temp);
		strcpy((char*)new_student.Last_Name, temp);
		DPRINTF("Enter the GPA of student: ");
		gets(temp);
		new_student.GPA = (float)atof(temp);
		DPRINTF("Enter the course ID of each course\n");
		for(int i = 0; i < 5; i++){
			DPRINTF("Course %d id: ", i+1);
			gets(temp);
			new_student.courses_ids[i] = (uint16_t)atoi(temp);
		}
		FIFO_Enqueue(&FIFO_Students, new_student);
		DPRINTF("[INFO] Student Details is added Successfully\n");
		DPRINTF("--------------------------------------------\n");
		DPRINTF("[INFO] The total number of students is %d\n", FIFO_Students.count);
		DPRINTF("[INFO] You can add up to %d Students\n", FIFO_Students.length);
		DPRINTF("[INFO] You can add %d more students\n", (FIFO_Students.length - FIFO_Students.count));
		CHECK_BEFORE_CLEAR();
	}
}

void Find_By_RollNum(){
	char temp[50];
	system("cls");
	DPRINTF("Enter the roll number of the student: ");
	getchar();
	gets(temp);
	FIFO_Print_RollNum(&FIFO_Students, atoi(temp));
	CHECK_BEFORE_CLEAR();
}

void Find_By_FirstName(){
	char temp[50];
	system("cls");
	DPRINTF("Enter the first name of the student: ");
	getchar();
	gets(temp);
	FIFO_Print_First_Name(&FIFO_Students, temp);
	CHECK_BEFORE_CLEAR();
}

void Find_By_Courses(){
	char temp[50];
	system("cls");
	DPRINTF("Enter the course ID: ");
	getchar();
	gets(temp);
	FIFO_Print_Course(&FIFO_Students, atoi(temp));
	CHECK_BEFORE_CLEAR();
}

void Get_Students_Count(){
	system("cls");
	DPRINTF("[INFO] The total number of students is %d\n", FIFO_Students.count);
	DPRINTF("[INFO] You can add up to %d Students\n", FIFO_Students.length);
	DPRINTF("[INFO] You can add %d more students\n", (FIFO_Students.length - FIFO_Students.count));
	CHECK_BEFORE_CLEAR();
}

void Delete_Student(){
	char temp[50];
	system("cls");
	DPRINTF("Enter the roll number you want to delete: ");
	getchar();
	gets(temp);
	FIFO_Remove(&FIFO_Students, atoi(temp));
	CHECK_BEFORE_CLEAR();
}

void Update_Student(){
	char temp[50];
	system("cls");
	DPRINTF("Enter the roll number you want to update: ");
	getchar();
	gets(temp);
	FIFO_Update_Student(&FIFO_Students, atoi(temp));
	CHECK_BEFORE_CLEAR();
}

void Print_Students(){
	system("cls");
	FIFO_print_all(&FIFO_Students);
	CHECK_BEFORE_CLEAR();
}
