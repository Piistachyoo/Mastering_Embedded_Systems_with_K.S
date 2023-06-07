
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
#define GPIOA_IDR	*(vint32_t*)(PORTA_BASE + 0x08)
#define GPIOA_ODR	*(vint32_t*)(PORTA_BASE + 0x0C)


#define PORTB_BASE	0x40010C00
#define GPIOB_CRL	*(vint32_t*)(PORTB_BASE)
#define GPIOB_CRH	*(vint32_t*)(PORTB_BASE + 0x04)
#define GPIOB_IDR	*(vint32_t*)(PORTB_BASE + 0x08)
#define GPIOB_ODR	*(vint32_t*)(PORTB_BASE + 0x0C)

void my_wait(int x){
	uint8 i, j;
	for(i = 0; i < x; i++){
		for(j = 0; j < 255; j++);
	}
}

int main(void)
{
	clock_init();
	GPIO_init();
	while(1){
		/* Read PA1 */
		if(((GPIOA_IDR&(1<<1))>>1)==0){
			/* Single press */
			GPIOB_ODR ^= 1<<1;
			while((((GPIOA_IDR&(1<<1))>>1)==0));
		}
		/* Read PA2 */
		if(((GPIOA_IDR&(1<<13))>>1)){
			/* Multi press */
			GPIOB_ODR ^= 1<<13;
		}
		my_wait(1);
	}
	return 0;
}

void clock_init(){
	RCC_APB2ENR |= (1<<2); // Enable RCC Clock for PORTA
	RCC_APB2ENR |= (1<<3); // Enable RCC Clock for PORTB
}

void GPIO_init(){
	/* PA1 input HighZ */
	GPIOA_CRL &= ~(0b1111 << 4);
	GPIOA_CRL |= (1<<6);

	/* PB1 output push pull mode */
	GPIOB_CRL &= ~(0b1111 << 4);
	GPIOB_CRL |= (1<<4);

	/* PA13 input Highz */
	GPIOA_CRH &= ~(0b1111 << 20);
	GPIOA_CRH |= (1<<22);

	/* PB2 output push pull mode */
	GPIOB_CRH &= ~(0b1111 << 20);
	GPIOB_CRH |= (1<<20);

}


