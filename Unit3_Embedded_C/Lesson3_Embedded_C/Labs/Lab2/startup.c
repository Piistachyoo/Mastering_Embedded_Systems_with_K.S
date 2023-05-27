/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : startup_cortexM3.c         	                 		 */
/* Date          : May 27, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "Platform_Types.h"

extern int main(void);
void Default_Handler();
void Reset_Handler();
void NMI_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void H_Fault_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void MM_Fault_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void Bus_Fault_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void Usage_Fault_Handler() __attribute__ ((weak, alias ("Default_Handler")));

extern uint32 _stack_top;
extern uint32 _E_text;
extern uint32 _S_DATA;
extern uint32 _E_DATA;
extern uint32 _S_BSS;
extern uint32 _E_BSS;

uint32 vectors[] __attribute__((section(".vectors"))) = {
	(uint32) &_stack_top,
	(uint32) &Reset_Handler,
	(uint32) &NMI_Handler,
	(uint32) &H_Fault_Handler,
	(uint32) &MM_Fault_Handler,
	(uint32) &Bus_Fault_Handler,
	(uint32) &Usage_Fault_Handler
};

void Reset_Handler(){
	/* Copy .data from flash to sram */
	uint32 DATA_size = (uint8*)(&_E_DATA) - (uint8*)(&_S_DATA);
	uint8* P_SRC = (uint8*)(&_E_text);
	uint8* P_DST = (uint8*)(&_S_DATA);
	for(int i=0; i<DATA_size; i++, P_DST++, P_SRC++){
		*(uint8*)P_DST = *(uint8*)P_SRC;
	}
	
	/* init .BSS in sram = 0 */
	uint32 bss_size = (uint8*)(&_E_BSS) - (uint8*)(&_S_BSS);
	P_DST = (uint8*)(&_S_BSS);
	for(int i=0; i<bss_size; i++, P_DST){
		*(uint8*)P_DST = (uint8)0;
	}
	
	/* Jump to main() */
	main();
}

void Default_Handler(){
	Reset_Handler();
}
