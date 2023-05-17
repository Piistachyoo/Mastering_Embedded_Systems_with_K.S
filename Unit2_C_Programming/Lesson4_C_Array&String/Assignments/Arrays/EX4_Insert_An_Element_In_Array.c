#include <stdio.h>

int main(){
	int myArray[50];
	int array_size, index;
	int element_inserted, location, temp;
	printf("Enter no of elements : ");
	fflush(stdin); fflush(stdout);
	scanf("%i", &array_size);
	for(index = 0; index < array_size; index++){
		scanf("%i", &myArray[index]);
	}
	printf("Enter the element to be inserted : ");
	fflush(stdin); fflush(stdout);
	scanf("%i", &element_inserted);
	printf("Enter the location : ");
	fflush(stdin); fflush(stdout);
	scanf("%i", &location);
	if(location <= array_size){
		array_size++;
		for(index = location-1; index < array_size; index++){
			temp = myArray[index];
			myArray[index] = element_inserted;
			element_inserted = temp;
		}
		for(index = 0; index < array_size; index++){
			printf("%i ", myArray[index]);
		}
	}
	else{
		printf("\nLocation out of range!");
	}
	return 0;
}
