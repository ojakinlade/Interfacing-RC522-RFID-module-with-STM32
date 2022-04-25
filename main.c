#include "stm32f4xx.h"                  // Device header
#include <stdbool.h>
#include "rc522.h"
#include "Systick.h"

uint8_t rfid_IDs[4] = {0};

int main(void)
{
	rc522_Init();
	
	while(1)
	{
		rc522_checkCard(rfid_IDs);
		SysTick_DelayMs(1000);
	}
}
