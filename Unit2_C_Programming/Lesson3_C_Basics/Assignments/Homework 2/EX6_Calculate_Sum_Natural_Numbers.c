#include <stdio.h>

int main(){
	int entered_number;
	int sum=0;
	int index;
	printf("Enter an integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%i", &entered_number);
	for(index = 0;index <= entered_number;index++){
		sum += index;
	}
	printf("Sum = %i", sum);
	return 0;
}
