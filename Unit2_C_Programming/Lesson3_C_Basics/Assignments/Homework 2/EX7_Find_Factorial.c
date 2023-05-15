#include <stdio.h>

int main(){
	int entered_number;
	int factorial = 1;
	int index;
	printf("Enter an integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%i", &entered_number);

	if(0 > entered_number){
		printf("Error!!! Factorial of negative number doesn't exist.");
	}
	else{
		for(index = 1;index <= entered_number;index++){
			factorial *= index;
		}
		printf("Factorial = %i", factorial);
	}
	return 0;
}
