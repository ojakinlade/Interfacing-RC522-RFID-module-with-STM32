#include "stm32f4xx.h"                  // Device header
#include "stdio.h"



struct __FILE {int handle;/* Add whatever you need here */};

FILE __stdout;
FILE __stdin;

int fputc(int ch, FILE *f)
{
	//uart_write(ch);
  ITM_SendChar(ch);
  return(ch);
}


	
