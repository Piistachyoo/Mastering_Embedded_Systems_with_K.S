#include <stdio.h>

int main(){
	int Number_One, Number_Two;
	printf("=== Enter two numbers ===");
	printf("\n\nEnter Number One : ");
	fflush(stdin); fflush(stdout);
	scanf("%i", &Number_One);
	printf("\nEnter Number Two : ");
	fflush(stdin); fflush(stdout);
	scanf("%i", &Number_Two);
	if(Number_One < Number_Two){
		printf("\n\n The minimum is %i", Number_One);
	}
	else if(Number_Two < Number_One){
		printf("\n\n The minimum is %i", Number_Two);
	}
	else{ printf("\n\n The two numbers are equal!"); }
	return 0;
}
