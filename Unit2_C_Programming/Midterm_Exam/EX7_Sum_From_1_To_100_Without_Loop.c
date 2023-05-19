/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                                    	 */
/* File          : EX7_Sum_From_1_To_100_Without_Loop.c                  */
/* Date          : May 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

int find_sum(int start);

int main(){
	printf("Sum from 1 to 100 is: %i", find_sum(1));
	return 0;
}

int find_sum(int start){
	if(start < 100){
		return (start + find_sum(start+1));
	}
	else{
		return start;
	}
}
