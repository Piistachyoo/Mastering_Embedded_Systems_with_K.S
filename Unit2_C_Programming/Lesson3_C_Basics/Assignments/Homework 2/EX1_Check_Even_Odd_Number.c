#include <stdio.h>

int main(){
	int entered_number;
	printf("Enter an integer you want to check: ");
	fflush(stdin); fflush(stdout);
	scanf("%i", &entered_number);
	if(entered_number%2){
		printf("%i is odd.", entered_number);
	}
	else{
		printf("%i is even.", entered_number);
	}
	return 0;
}
