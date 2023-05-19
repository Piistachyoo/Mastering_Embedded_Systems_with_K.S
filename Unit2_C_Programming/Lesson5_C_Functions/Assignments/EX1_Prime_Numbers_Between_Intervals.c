/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project		 : C_Programming				 						 */
/* File          : EX1_Prime_Numbers_Between_Intervals.c         		 */
/* Date          : May 19, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

void print_prime_numbers(int n1, int n2);

int main(){
	int entered_n1, entered_n2;
	printf("Enter two numbers(intervals): ");
	fflush(stdin); fflush(stdout);
	scanf("%i %i", &entered_n1, &entered_n2);
	print_prime_numbers(entered_n1, entered_n2);
	return 0;
}

void print_prime_numbers(int n1, int n2){
	if(n1 == n2){
		printf("Errors! Numbers are equal!");
	}
	else if(n1 < n2){
		int index = n1;
		int iterator;
		int prime_flag;
		printf("Prime numbers between %i and %i are: ", n1, n2);
		for(;index <= n2; index++){
			prime_flag = 1;
			for(iterator = 2; iterator < (index/2); iterator++){
				if(index%iterator == 0)
					prime_flag = 0;
			}
			if(1 == prime_flag)
				printf("%d ", index);
		}
	}
	else if(n1 > n2){

	}
	else{ /* Do Nothing */ }
}
