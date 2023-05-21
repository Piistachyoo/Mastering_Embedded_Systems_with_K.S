/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                                    	 */
/* File          : Lab2_Dump_Memory_Function.c                           */
/* Date          : May 21, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

void dump_memory_location(char *base_address, int size);

struct hamada{
	char data1;
	long data2;
	char data3;
	short data4;
}data;

int main(){
	data.data1 = 0xCA;
	data.data2 = 0xEDEF1A89;
	data.data3 = 0xEE;
	data.data4 = 0xDCBA;
	dump_memory_location((char*)&data, sizeof(data));
	return 0;
}

void dump_memory_location(char *base_address, int size){
	int index = 0;
	for(;index < size; index++, base_address++){
		printf("Add: %p\tVal: 0x%X\n", base_address, (unsigned char)*base_address);
	}
}
