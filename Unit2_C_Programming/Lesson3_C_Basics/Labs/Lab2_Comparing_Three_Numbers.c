#include <stdio.h>

int main(){
	int Number_One, Number_Two, Number_Three;
	printf("=== Enter three numbers ===\n");
	printf("\nEnter number one : ");
	fflush(stdout); fflush(stdin);
	scanf("%i", &Number_One);
	printf("\nEnter number two : ");
	fflush(stdout); fflush(stdin);
	scanf("%i", &Number_Two);
	printf("\nEnter number three : ");
	fflush(stdout); fflush(stdin);
	scanf("%i", &Number_Three);
	if((Number_One > Number_Two) && (Number_One > Number_Three)){
		printf("\nThe largest value is : %i", Number_One);
	}
	else if((Number_Two > Number_One) && (Number_Two > Number_Three)){
		printf("\nThe largest value is : %i", Number_Two);
	}
	else if((Number_Three > Number_One) && (Number_Three > Number_Two)){
		printf("\nThe largest value is : %i", Number_Three);
	}
	else{ printf("\nTwo numbers or more are identical!"); }
	return 0;
}
