#include <stdio.h>

int main(){
	float students_degrees[10];
	int index;
	for(index = 0; index < 10; index++){
		printf("\nEnter student %i degree : ", (index+1));
		fflush(stdin); fflush(stdout);
		scanf("%f", &students_degrees[index]);
	}
	for(index = 0; index < 10; index++){
		printf("\nStudent %i degree degree is %f", (index+1), students_degrees[index]);
	}
	return 0;
}
