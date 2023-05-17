#include <stdio.h>

int main(){
	float original_array[3][3];
	float transposed_array[3][3];
	int index1, index2;
	/* Get array values from user */
	for(index1 = 0; index1 < 3; index1++){
		for(index2 = 0; index2 < 3; index2++){
			printf("Enter the item(%i, %i) : ", index1, index2);
			fflush(stdin); fflush(stdout);
			scanf("%f", &original_array[index1][index2]);
		}
	}
	/* Transpose matrix */
	for(index1 = 0; index1 < 3; index1++){
		for(index2 = 0; index2 < 3; index2++){
			transposed_array[index1][index2] = original_array[index2][index1];
		}
	}
	/* Print 2 arrays */
	printf("the matrix is\n");
	for(index1 = 0; index1 < 3; index1++){
		for(index2 = 0; index2 < 3; index2++){
			printf("%.2f\t", original_array[index1][index2]);
		}
		printf("\n\r");
	}
	printf("the Transpose matrix is\n");
	for(index1 = 0; index1 < 3; index1++){
		for(index2 = 0; index2 < 3; index2++){
			printf("%.2f\t", transposed_array[index1][index2]);
		}
		printf("\n\r");
	}
	return 0;
}
