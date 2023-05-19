/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                                    	 */
/* File          : EX1_Store_Student_Info_Using_Struct.c                 */
/* Date          : May 20, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

struct SStudents{
	char name[20];
	int roll_number;
	float marks;
};

int main(){
	struct SStudents student1;
	printf("Enter information of students:\n\n");
	printf("Enter name: ");
	fflush(stdin); fflush(stdout);
	gets(student1.name);
	printf("Enter roll number: ");
	fflush(stdin); fflush(stdout);
	scanf("%i", &student1.roll_number);
	printf("Enter marks: ");
	fflush(stdin); fflush(stdout);
	scanf("%f", &student1.marks);
	printf("\nDisplaying Information\n");
	printf("name: %s\nRoll: %i\nMarks: %.2f\n", student1.name, student1.roll_number, student1.marks);
	return 0;
}
