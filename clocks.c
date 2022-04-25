#include "stm32f4xx.h"                  // Device header
#include "clocks.h"


void Clocks_Init(void)
{
	while((RCC->CR & RCC_CR_HSIRDY) != RCC_CR_HSIRDY);
	//SET APB2 prescaler to 2 i.e APB2 clock = 16MHz / 2 = 8MHz 
	//Set sysclk prescaler to 2 i.e AHB clock = 8MHz
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV2 | RCC_CFGR_HPRE_DIV2;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN;
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
}
