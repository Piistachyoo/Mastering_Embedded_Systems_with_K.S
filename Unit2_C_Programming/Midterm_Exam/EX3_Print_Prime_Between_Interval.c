/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                                    	 */
/* File          : EX3_Print_Prime_Between_Interval.c                    */
/* Date          : May 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

void print_prime_numbers(int n1, int n2);

int main(){
	int entered_n1, entered_n2;
	printf("Enter two intervals: ");
	fflush(stdin); fflush(stdout);
	scanf("%i %i", &entered_n1, &entered_n2);
	print_prime_numbers(entered_n1, entered_n2);
	return 0;
}

void print_prime_numbers(int n1, int n2){
	int number_index, prime_flag, iterator;
	if(n1 < n2){
		printf("Prime numbers between %i and %i = ", n1, n2);
		for(number_index = n1; number_index <= n2; number_index++){
			prime_flag = 1;
			for(iterator = 2; iterator < number_index; iterator++){
				if(number_index % iterator == 0){
					prime_flag = 0;
					break;
				}
			}
			if(1 == prime_flag){
				printf("%i ", number_index);
			}
		}
	}
	else if(n1 > n2){
		printf("Prime numbers between %i and %i = ", n2, n1);
		for(number_index = n2; number_index <= n1; number_index++){
			prime_flag = 1;
			for(iterator = 2; iterator < number_index; iterator++){
				if(number_index % iterator == 0){
					prime_flag = 0;
					break;
				}
			}
			if(1 == prime_flag){
				printf("%i ", number_index);
			}
		}
	}
	else if(n1 == n2){
		printf("Error! Two numbers are equal!");
	}
	else{ /* Do Nothing */ }

}
