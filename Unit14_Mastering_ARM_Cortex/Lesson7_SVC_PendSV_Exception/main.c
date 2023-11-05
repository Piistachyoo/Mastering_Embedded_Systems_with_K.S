/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : main.c 			                            		 */
/* Date          : Jul 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "RCC_driver.h"
#include "gpio_driver.h"
#include "EXTI_driver.h"

#include "core_cm3.h"


uint8 TASKA_flag, TASKB_flag, IRQ_Flag = 0;

#define TaskA_Stack_Size	100	// 100 Bytes
#define TaskB_Stack_Size	100	// 100 Bytes

extern uint32 _estack;
// Main Stack
uint32 _S_MSP = (uint32*)&_estack, _E_MSP;

// Process Stack
uint32 _S_PSP_TA, _E_PSP_TA;
uint32 _S_PSP_TB, _E_PSP_TB;

#define OS_SET_PSP(address)	__asm volatile("mov r0, %0 \n\t msr PSP, r0" : :"r" (address))
#define OS_SET_CPU_PRIVILEGED() __asm volatile("mrs r0, CONTROL \n\t bic r0, r0, #0x1 \n\t msr CONTROL, r0")
#define OS_SET_CPU_UNPRIVILIGED() __asm volatile("mrs r0, CONTROL \n\t orr r0, r0, #0x1 \n\t msr CONTROL, r0")
#define OS_SWITCH_SP_to_PSP() __asm volatile("mrs r0, CONTROL \n\t orr r0, r0, #0x2 \n\t msr CONTROL, r0")
#define OS_SWITCH_SP_to_MSP() __asm volatile("mrs r0, CONTROL \n\t bic r0, r0, #0x2 \n\t msr CONTROL, r0")
#define OS_Generate_Exception() __asm volatile ("SVC #0x3");

enum CPUAccessLevel{
	priviliged,
	unprivileged
};

void Switch_CPU_Access_Level(enum CPUAccessLevel level){
	switch(level){
	case priviliged:
		/* Clear Bit 0 CONTROL Register */
		__asm("mrs r3, CONTROL 		\n\t"
			  "lsr r3, r3, #0x1 	\n\t"
			  "lsl r3, r3, #0x1		\n\t"
			  "msr CONTROL, r3");
		break;
	case unprivileged:
		/* Set Bit 0 CONTROL Register */
		__asm("mrs r3, CONTROL 		\n\t"
			  "orr r3, r3, #0x1 	\n\t"
			  "msr CONTROL, r3");
		break;
	}
}

void EXTI9_Callback(void){
	if(IRQ_Flag == 0){
		TASKA_flag = 1;
		IRQ_Flag = 1;
	}
	else if(IRQ_Flag == 1){
		TASKB_flag = 1;
		IRQ_Flag = 0;
	}

}

int TaskA(int a, int b, int c){
	return a+b+c;
}

int TaskB(int a, int b, int c, int d){
	return a+b+c+d;
}

void MainOS(){
	_E_MSP = _S_MSP - 512;
	_S_PSP_TA = _E_MSP - 8;
	_E_PSP_TA = _S_PSP_TA - TaskA_Stack_Size;
	_S_PSP_TB = _E_PSP_TA - 8;
	_E_PSP_TB = _S_PSP_TB - TaskB_Stack_Size;

	while(TRUE){
		__asm("NOP");
		if(TASKA_flag == 1){
			// Set PSP Register = _S_PSP_TA
			OS_SET_PSP(_S_PSP_TA);

			// SP -> PSP
			OS_SWITCH_SP_to_PSP();

			// Switch from privileged -> unprivileged
			OS_SET_CPU_UNPRIVILIGED();

			TASKA_flag = TaskA(1, 2, 3);

			// Switch from unprivileged -> privileged
			OS_Generate_Exception();

			// SP -> MSP
			OS_SWITCH_SP_to_MSP();
		}
		else if(TASKB_flag == 1){
			// Set PSP Register = _S_PSP_TB
			OS_SET_PSP(_S_PSP_TB);

			// SP -> PSP
			OS_SWITCH_SP_to_PSP();

			// Switch from privileged -> unprivileged
			OS_SET_CPU_UNPRIVILIGED();

			TASKB_flag = TaskB(1, 2, 3, 4);
			// Switch from unprivileged -> privileged
			OS_Generate_Exception();

			// SP -> MSP
			OS_SWITCH_SP_to_MSP();
		}
	}
}

int OS_SVC_Set (int a, int b, int SVC_ID){
	int result;
	switch(SVC_ID){
	case 1: // ADD
		__asm ("svc #0x1");
		break;
	case 2: // SUB
		__asm ("svc #0x2");
		break;
	case 3: // MUL
		__asm ("svc #0x3");
		break;
	case 4: // PendSV
		__asm ("svc #0x4");
		break;
	}
	__asm ("mov %[result], r0": [result]"=r"(result));
	return result;
}

void PendSV_Handler(void){
	SCB->ICSR |= SCB_ICSR_PENDSVCLR_Msk;
}

void OS_SVC_services (uint32 *StackFramePointer){
	/* OS_SVC_Set Stack -> r0 -> argument0 = StackFramePointer
	   OS_SVC_Set : r0,r1,r2,r3,r12,LR,PC,xPSR */
	uint8 SVC_number;
	uint32 arg1, arg2, argg3;
	arg1 = StackFramePointer[0];
	arg2 = StackFramePointer[1];
	SVC_number = *((uint8*)((uint8*)(StackFramePointer[6])) - 2);
	switch(SVC_number){
	case 1: // ADD
		StackFramePointer[0] = arg1 + arg2;
		break;
	case 2: // SUB
		StackFramePointer[0] = arg1 - arg2;
		break;
	case 3: // MUL
		StackFramePointer[0] = arg1 * arg2;
		break;
	case 4: // PendSV
		SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
		break;
	}
}

__attribute ((naked)) void SVC_Handler(void){
	__asm ("tst lr, #4 \n"
		   "ITE EQ \n"
		   "mrseq r0, msp \n"
		   "mrsne r0, psp \n"
		   "B OS_SVC_services");
}

int main(){

//	MCAL_RCC_Enable_Peripheral(RCC_AFIO);
//	MCAL_RCC_Enable_Peripheral(RCC_GPIOB);
//	EXTI_PinConfig_t myEXTI9;
//	myEXTI9.EXTI_PIN = EXTI9PB9;
//	myEXTI9.IRQ_EN = EXTI_IRQ_ENABLE;
//	myEXTI9.Trigger_Case = EXTI_TRIGGER_RISING;
//	myEXTI9.P_IRQ_CallBack = EXTI9_Callback;
//	MCAL_EXTI_GPIO_Init(&myEXTI9);
//	MainOS();

	IRQ_Flag = OS_SVC_Set(5, 3, 1); // ADD
	IRQ_Flag = OS_SVC_Set(5, 3, 2); // SUB
	IRQ_Flag = OS_SVC_Set(5, 3, 3); // MUL


	IRQ_Flag = OS_SVC_Set(0, 0, 4); // PendSV

	while(1){
		if(IRQ_Flag)
			IRQ_Flag = 0;
	}
	return 0;
}


