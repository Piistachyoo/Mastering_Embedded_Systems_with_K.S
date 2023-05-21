/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                                    	 */
/* File          : EX1_Handle_Pointers.c                          		 */
/* Date          : May 21, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

int main(){
	int m = 29;
	printf("Address of m : 0x%x\n", &m);
	printf("Value of m : %d\n", m);

	int *ab = &m;
	printf("\nNow ab is assigned with the address of m.\n");

	printf("Address of pointer ab : 0x%x\n", ab);
	printf("Content of pointer ab : %d\n", *ab);

	m = 34;
	printf("\nThe value of m assigned to 34 now.\n");

	printf("Address of pointer ab : 0x%x\n", ab);
	printf("Content of pointer ab : %d\n", *ab);

	*ab = 7;
	printf("\nThe pointer variable ab is assigned with the value 7 now.\n");

	printf("Address of m : 0x%x\n", &m);
	printf("Value of m : %d\n", m);
	return 0;
}
