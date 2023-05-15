#include <stdio.h>

int main(){
	int sum = 0;
	int index = 0;
	for(index = 1;index <= 99; index++){
		sum += index;
	}
	printf("Summation of values between (1 and 99) is : %i", sum);
	return 0;
}
