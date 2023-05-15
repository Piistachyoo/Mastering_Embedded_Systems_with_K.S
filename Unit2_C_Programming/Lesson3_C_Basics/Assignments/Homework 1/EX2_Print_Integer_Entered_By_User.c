#include <stdio.h>

int main(){
	int entered_number;
	printf("Enter a integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%i", &entered_number);
	printf("You entered: %i", entered_number);
	return 0;
}
