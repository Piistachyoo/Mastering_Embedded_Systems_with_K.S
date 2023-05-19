/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                                    	 */
/* File          : EX4_Store_Students_Info_Using_Array_Struct.c          */
/* Date          : May 20, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

struct SStudents{
	char name[20];
	int roll_number;
	int marks;
};

int main(){
	struct SStudents students_info[10];
	int index = 0;
	printf("Enter information of students:\n");
	for(; index < 10; index++){
		students_info[index].roll_number = index+1;
		printf("\nFor roll number %i\n", index+1);
		printf("Enter name: ");
		fflush(stdin); fflush(stdout);
		scanf("%s", students_info[index].name);
		printf("Enter marks: ");
		fflush(stdin); fflush(stdout);
		scanf("%i", &students_info[index].marks);
	}
	printf("\nDisplaying information of students:\n");
	for(index = 0; index < 10; index++){
		printf("\nInformation for roll number %i:\nName: %s\nMarks: %i\n", students_info[index].roll_number, students_info[index].name, students_info[index].marks);
	}
	return 0;
}
