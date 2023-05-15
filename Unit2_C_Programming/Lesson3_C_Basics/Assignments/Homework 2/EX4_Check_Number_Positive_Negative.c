#include <stdio.h>

int main(){
	float entered_number;
	printf("Enter a number: ");
	fflush(stdin); fflush(stdout);
	scanf("%f", &entered_number);
	if(0 == entered_number){
		printf("You entered zero.");
	}
	else if(0 < entered_number){
		printf("%.2f is positive.", entered_number);
	}
	else if(0 > entered_number){
		printf("%.2f is negative.", entered_number);
	}
	else{ /* Do Nothing */ }
	return 0;
}
