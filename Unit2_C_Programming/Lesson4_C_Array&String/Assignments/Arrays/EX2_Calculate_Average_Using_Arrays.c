#include <stdio.h>

int main(){
	int data_size, index;
	float sum = 0;
	float result;
	float data_array[50];
	printf("Enter the numbers of data: ");
	fflush(stdin); fflush(stdout);
	scanf("%i", &data_size);
	for(index = 0; index < data_size; index++){
		printf("%i. Enter number: ", index+1);
		fflush(stdin); fflush(stdout);
		scanf("%f", &data_array[index]);
		sum += data_array[index];
	}
	/* implicit casting occurs for data_size int -> float */
	result = sum / data_size;
	printf("Average = %.2f", result);
	return 0;
}
