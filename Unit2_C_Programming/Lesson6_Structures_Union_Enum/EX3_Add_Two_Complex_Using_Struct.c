/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                                    	 */
/* File          : EX3_Add_Two_Complex_Using_Struct.c                    */
/* Date          : May 20, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

struct complex_number{
	float real;
	float imaginary;
};

struct complex_number Calculate_Sum_Complex(const struct complex_number n1, const struct complex_number n2);

int main(){
	struct complex_number entered_n1, entered_n2, result;
	printf("For 1st complex number\n");
	printf("Enter real and imaginary respectively: ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f", &(entered_n1.real), &(entered_n1.imaginary));
	printf("\nFor 2nd complex number\n");
	printf("Enter real and imaginary respectively: ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f", &(entered_n2.real), &(entered_n2.imaginary));
	result = Calculate_Sum_Complex(entered_n1, entered_n2);
	printf("Sum=%.1f+%.1fi", result.real, result.imaginary);
	return 0;
}

struct complex_number Calculate_Sum_Complex(const struct complex_number n1, const struct complex_number n2){
	struct complex_number return_result;
	return_result.real = n1.real + n2.real;
	return_result.imaginary = n1.imaginary + n2.imaginary;
	return return_result;
}
