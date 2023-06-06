
#include "Platform_Types.h"

void clock_init();
void GPIO_init();

// register addresses

// RCC
#define RCC_BASE	0x40021000
#define RCC_APB2ENR	*(vint32_t*)(RCC_BASE + 0x18)

// GPIO
#define PORTA_BASE	0x40010800
#define GPIOA_CRL	*(vint32_t*)(PORTA_BASE)
#define GPIOA_CRH	*(vint32_t*)(PORTA_BASE + 0x04)
#define GPIOA_ODR	*(vint32_t*)(PORTA_BASE + 0x0C)

// EXTI
#define EXTI_BASE	0x40010400
#define EXTI_IMR	(*(vint32_t*)(EXTI_BASE ))
#define EXTI_RTSR	(*(vint32_t*)(EXTI_BASE + 0x08))
#define EXTI_FTSR	(*(vint32_t*)(EXTI_BASE + 0x0C))
#define EXTI_PR		(*(vint32_t*)(EXTI_BASE + 0x14))

// AFIO
#define AFIO_BASE	 0x40010000
#define AFIO_EXTICR1 (*(vint32_t*)(AFIO_BASE + 0x08))

#define NVIC_EXTIE0  (*(vint32_t*)(0xE000E100))

void main(void)
{
	/* EXTI0 = PORTA0 */
	AFIO_EXTICR1 = 0;

	/* Set EXTI Line 0 on rising edge */
	EXTI_RTSR |= (1<<0);

	/* Enable EXTI Line 0 (Mask 1) */
	EXTI_IMR |= (1<<0);

	/* Enable NVIC EXTI0 */
	NVIC_EXTIE0 |= (1<<6);

	clock_init();
	GPIO_init();
	while(1);
}

void clock_init(){
	RCC_APB2ENR |= (1<<2); // Enable RCC Clock for PORTA
	RCC_APB2ENR |= (1<<0); // Enable RCC Clock for AFIO
}

void GPIO_init(){
	/* Configure PORTA0 as input EXTI*/
	GPIOA_CRL &= ~(0b11);
	GPIOA_CRL |= (1<<2);

	/* Configure PORTA1 as output */
	GPIOA_CRL |= (1<<4);
	GPIOA_CRL &= ~(0b11<<6);
}

void EXTI0_IRQHandler(void){
	/* EXTI0 on PORTA PIN0 */

	/* Clear pending request */
	EXTI_PR |= (1<<0);

	/* Toggle LED on PORTA PIN1 */
	GPIOA_ODR ^= (1<<1);

}
