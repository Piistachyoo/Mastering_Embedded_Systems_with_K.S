/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                                    	 */
/* File          : EX2_Calculate_Square_Root.c                           */
/* Date          : May 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>
#include <math.h>

double Calculate_Sqaure_Root(int _number);

int main(){
	float output;
	output = Calculate_Sqaure_Root(4);
	if(-1 == output){
		printf("4 has no square root!\n");
	}
	else{
		printf("Square root of 4 is %.3f\n", output);
	}
	output = Calculate_Sqaure_Root(10);
	if(-1 == output){
		printf("10 has no square root!\n");
	}
	else{
		printf("Square root of 10 is %.3f\n", output);
	}
	return 0;
}

double Calculate_Sqaure_Root(int _number){
	double root = _number;
	double precision = 0.001;
	if(_number <= 0){
		root = -1;
	}
	else{
		/* Using newton-raphson method */
		while((root * root - _number) > precision){
			root = (root + (_number / root)) / 2;
		}
	}
	return root;
}
