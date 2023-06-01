/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Student_Information_Management                        */
/* File          : main.c                            	                 */
/* Date          : Jun 1, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "students.h"


FIFO_t FIFO_Students;
#pragma pack(1)
students_info myStudents[50];
#pragma pack()

int main(){
	FIFO_init(&FIFO_Students, myStudents, 50);
	uint8_t user_choice;
	DPRINTF("Welcome to the Student Management System\n");
//	for(uint32_t i = 50000000; i != 0; i--);
	while(1){
		system("cls");
		DPRINTF("Choose the task that you want to perform: \n");
		DPRINTF("1. Add the Student Details Manually\n");
		DPRINTF("2. Add the Student Details From Text File\n");
		DPRINTF("3. Find the Student Details by Roll Number\n");
		DPRINTF("4. Find the Student Details by First Name\n");
		DPRINTF("5. Find the Student Details by Course ID\n");
		DPRINTF("6. Find the Total number of Students\n");
		DPRINTF("7. Delete a Student Details by Roll Number\n");
		DPRINTF("8. Update a Student Details by Roll Number\n");
		DPRINTF("9. Show all students information\n");
		DPRINTF("10. Exit\n");
		DPRINTF("Enter your choice to perform the task: ");
		scanf("%d", (int*)&user_choice);
		switch(user_choice){
		case 1:
			Add_Student_Manually();
			break;
		case 2:
			Add_Student_File();
			break;
		case 3:
			Find_By_RollNum();
			break;
		case 4:
			Find_By_FirstName();
			break;
		case 5:
			Find_By_Courses();
			break;
		case 6:
			Get_Students_Count();
			break;
		case 7:
			Delete_Student();
			break;
		case 8:
			Update_Student();
			break;
		case 9:
			Print_Students();
			break;
		case 10:
			DPRINTF("Thanks for using our system!\n\n");
			return 1;
			break;
		default:
			DPRINTF("[ERROR] Enter a valid choice!\n\n");
			CHECK_BEFORE_CLEAR();
		break;
		}
	}
	return 0;
}
