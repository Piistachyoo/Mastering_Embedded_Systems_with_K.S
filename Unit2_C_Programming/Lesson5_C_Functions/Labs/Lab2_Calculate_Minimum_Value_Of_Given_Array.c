/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project		 : C_Programming				 						 */
/* File          : Lab2_Calculate_Minimum_Value_Of_Given_Array.c    	 */
/* Date          : May 18, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

int calcMin(const int values[], const int n);

int main(){
	int xvalues[10] = {35, 67, 27, 54, 76, 44, 59, 32, 43, 25};
	int yvalues[5] = {28, 71, 67, 83, 62};
	int zvalues[13] = {87, 21, 74, 36, 27, 64, 87, 63, 27, 86, 48, 32, 76};
	printf("The minimum of x, y, z values is (%d, %d, %d)\n", calcMin(xvalues, 10), calcMin(yvalues, 5), calcMin(zvalues, 13));
	return 0;
}

int calcMin(const int values[], const int n){
	int minimum_value = values[0];
	int index = 0;
	for(;index < n; index++){
		if(values[index] < minimum_value){
			minimum_value = values[index];
		}
	}
	return minimum_value;
}
