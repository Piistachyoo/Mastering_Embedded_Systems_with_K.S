#include <stdio.h>

int main(){
	int original_array[50][50];
	int rows, cols;
	int index_rows, index_cols;
	printf("Enter rows and column of matrix: ");
	fflush(stdin); fflush(stdout);
	scanf("%i %i", &rows, &cols);
	printf("\nEnter elements of matrix:\n");
	for(index_rows = 0; index_rows < rows; index_rows++){
		for(index_cols = 0; index_cols < cols; index_cols++){
			printf("Enter elements a%i%i: ", index_rows+1, index_cols+1);
			fflush(stdin); fflush(stdout);
			scanf("%i", &original_array[index_rows][index_cols]);
		}
	}
	printf("\nEntered Matrix:\n");
	for(index_rows = 0; index_rows < rows; index_rows++){
		for(index_cols = 0; index_cols < cols; index_cols++){
			printf("%i\t", original_array[index_rows][index_cols]);
		}
		printf("\n");
	}
	printf("\nEntered Matrix:\n");
	for(index_cols = 0; index_cols < cols; index_cols++){
		for(index_rows = 0; index_rows < rows; index_rows++){
			printf("%i\t", original_array[index_rows][index_cols]);
		}
		printf("\n");
	}
	return 0;
}
