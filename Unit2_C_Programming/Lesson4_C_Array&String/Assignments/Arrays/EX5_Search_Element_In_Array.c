#include <stdio.h>

int main(){
	int myArr[50];
	int array_size, search_element, index, location_result;
	int found_flag = 0;
	printf("Enter no of elements : ");
	fflush(stdin); fflush(stdout);
	scanf("%i", &array_size);
	for(index = 0; index < array_size; index++){
		scanf("%i", &myArr[index]);
	}
	printf("Enter the elements to be searched : ");
	fflush(stdin); fflush(stdout);
	scanf("%i", &search_element);
	for(index = 0; index < array_size; index++){
		if(search_element == myArr[index]){
			found_flag = 1;
			location_result = index+1;
			break;
		}
	}
	if(1 == found_flag){
		printf("Number found at the location = %i", location_result);
	}
	else{
		printf("Error! Number was not found!");
	}
	return 0;
}
