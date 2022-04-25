#include "stm32f4xx.h"                  // Device header
#include "gpio.h"


void GPIO_Init(void)
{
	GPIOA->MODER |= GPIO_MODER_MODE8_0 | GPIO_MODER_MODE5_1 |
									GPIO_MODER_MODE6_1 | GPIO_MODER_MODE7_1;
	GPIOA->AFR[0] |= (5UL << 20) | (5UL << 24) | (5UL << 28);
	GPIOB->MODER |= GPIO_MODER_MODE0_0;
}
