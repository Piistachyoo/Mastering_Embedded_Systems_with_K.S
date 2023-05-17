#include <stdio.h>

int main(){
	float x[5] = {5, 16, 22, 3.5, 15};
	float y;
	int index;
	for(index = 0; index < 5; index++){
		y = 5 * x[index] * x[index] + 3 * x[index] + 2;
		printf("y(%f) = %f\r\n", x[index], y);
	}
	return 0;
}
