/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : main.c 			                            		 */
/* Date          : Jul 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "I2C_EEPROM.h"

int main(){

	uint8 buffer1[] = {0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7};
	uint8 buffer2[7] = {0};

	EEPROM_Init();
	EEPROM_Write_nBytes(0xAF, buffer1, 7);
	EEPROM_Read_nBytes(0xAF, buffer2, 7);

	buffer1[0] = 0xA;
	buffer1[1] = 0xB;
	buffer1[2] = 0xC;
	buffer1[3] = 0xD;

	EEPROM_Write_nBytes(0xFFF, buffer1, 4);
	EEPROM_Read_nBytes(0xFFF, buffer2, 4);

	while(1);
	return 0;
}

void clock_init(void){

}
