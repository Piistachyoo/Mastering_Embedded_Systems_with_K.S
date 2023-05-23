#include "uart.h"

uint8 string_buffer[100] = "Learn-In-Depth: Omar Yamany";

void main(void){
	Uart_Send_String(string_buffer);
}