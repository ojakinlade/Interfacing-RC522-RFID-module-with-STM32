#include "stm32f4xx.h"                  // Device header
#include "spi.h"


void SPI1_Init(void)
{
	SPI1->CR1 |= SPI_CR1_SSM | SPI_CR1_MSTR | SPI_CR1_SSI | SPI_CR1_SPE | (3UL << 3);
}

static void SPI1_TransmitByte(uint8_t byte)
{
	while((SPI1->SR & SPI_SR_TXE) != SPI_SR_TXE);
	SPI1->DR = byte;
	while((SPI1->SR & SPI_SR_BSY) == SPI_SR_BSY); //wait while SPI bus is busy
}

void SPI1_TransmitBytes(uint8_t* data, uint8_t len)
{
	uint32_t i = 0;
	uint8_t temp	= 0;
	
	while(i < len)
	{
		while((SPI1->SR & SPI_SR_TXE) != SPI_SR_TXE);// wait to transmision buffer to be emplty
		SPI1->DR= data[i];
		while((SPI1->SR & SPI_SR_BSY) != SPI_SR_BSY);
		i++;
	}
	
	while((SPI1->SR & SPI_SR_TXE) != SPI_SR_TXE);
	while((SPI1->SR & SPI_SR_BSY) == SPI_SR_BSY);
	temp = SPI1->DR;
	temp = SPI1->SR;
}

void SPI1_ReceiveBytes(uint8_t* data, uint32_t len)
{
	for(uint32_t i = 0; i < len; i++)
	{
		SPI1->DR = 0;
		while((SPI1->SR & SPI_SR_RXNE) != SPI_SR_RXNE);
		data[i] = SPI1->DR;
	}
	
}

