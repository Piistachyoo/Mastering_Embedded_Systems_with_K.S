/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                                    	 */
/* File          : EX1_Function_Sums_All_Digits.c                        */
/* Date          : May 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

int sum_digits(int _number);

int main(){
	printf("Sum of 123 = %i\n", sum_digits(123));
	printf("Sum of 4565 = %i\n", sum_digits(4565));
	return 0;
}

int sum_digits(int _number){
	int result = 0;
	int digit;
	while(0 != _number){
		digit = _number % 10;
		result += digit;
		_number /= 10;
	}
	return result;
}
