/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                                    	 */
/* File          : EX5_Ptr_To_Array_To_Ptr_To_Structure.c                */
/* Date          : May 21, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

struct employees{
	char name[20];
	int  ID;
};

int main(){
	struct employees emp1 = {"Alex", 1002};
	struct employees emp2 = {"John", 1003};
	struct employees *emp_ptr[2];
	emp_ptr[0] = &emp1;
	emp_ptr[1] = &emp2;
	struct employees (*(*ptr_ptr_emp)[2]);
	ptr_ptr_emp = &emp_ptr;

	printf("Employee Name: %s\n", (*ptr_ptr_emp)[0]->name);
	printf("Employee ID: %i\n", (*ptr_ptr_emp)[0]->ID);
	printf("Employee Name: %s\n", (*ptr_ptr_emp)[1]->name);
	printf("Employee ID: %i\n", (*ptr_ptr_emp)[1]->ID);
	return 0;
}
