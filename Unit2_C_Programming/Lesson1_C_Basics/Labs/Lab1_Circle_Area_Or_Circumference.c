#include <stdio.h>


int main(){
	int radius;
	char user_selection;
	const float pi = 3.141593;
	float result;
	printf("Enter circle radius : ");
	fflush(stdout); fflush(stdin);
	scanf("%i", &radius);
	printf("Enter your choice (a to print the area, c to print the circumference) : ");
	fflush(stdout); fflush(stdin);
	scanf(" %c", &user_selection);
	if('a' == user_selection){
		result = pi * radius * radius;
		printf("\n\nArea = %.2f", result);
	}
	else if('c' == user_selection){
		result = 2 * pi * radius;
		printf("\n\nCircumference = %.2f", result);
	}
	else{
		printf("\n\nWrong choice!");
	}
	return 0;
}
