#ifndef UART_H_
#define UART_H_

#include "Platform_Types.h"

#define UART0DR *((vuint8_t*)((vuint8_t*)0x101f1000))

void Uart_Send_String(uint8* P_tx_string);

#endif