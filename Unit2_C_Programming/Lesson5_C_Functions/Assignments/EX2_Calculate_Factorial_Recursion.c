/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : EX2_Calculate_Factorial_Recursion.c            	     */
/* Date          : May 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

int Get_Factorial(int _number);

int main(){
	int entered_number;
	printf("Enter an positive integer: ");
	fflush(stdout); fflush(stdin);
	scanf("%i", &entered_number);
	printf("Factorial of %i = %i", entered_number, Get_Factorial(entered_number));
	return 0;
}

int Get_Factorial(int _number){
	static int result = 1;
	if(0 < _number){
		result *= _number;
		Get_Factorial(--_number);
	}
	else{ /* Do Nothing */ }
	return result;
}
