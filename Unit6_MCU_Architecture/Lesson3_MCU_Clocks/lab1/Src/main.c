/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "Platform_Types.h"


// register addresses

#define RCC_BASE	0x40021000
#define PORTA_BASE	0x40010800

#define RCC_APB2ENR	*(vint32_t*)(RCC_BASE + 0x18)
#define GPIOA_CRH	*(vint32_t*)(PORTA_BASE + 0x04)
#define GPIOA_ODR	*(vint32_t*)(PORTA_BASE + 0x0C)

typedef union{
	vint32_t all_fields;
	struct{
		vint32_t reserved:13;
		vint32_t pin13	 :1;
		vint32_t pin14	 :1;
		vint32_t pin15	 :1;
	}ODR_field;
}R_ODR_t;

volatile R_ODR_t *R_ODR = (volatile R_ODR_t *)(PORTA_BASE + 0x0C);

int main(void)
{
	RCC_APB2ENR |= (1<<2); // Enable RCC Clock
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
	while(1){
		R_ODR->ODR_field.pin13 = 1;
		for(int i=0; i<100000;i++);
		R_ODR->ODR_field.pin13 = 0;
		for(int i=0; i<100000;i++);
	}
	return 0;
}
