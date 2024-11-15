/*
 * myLib.c
 *
 *  Created on: Nov 15, 2024
 *      Author: user
 */
#include "main.h"
extern UART_HandleTypeDef huart2;
int __io_putchar(int ch) // Lowest output Function
{
	HAL_UART_Transmit(&huart2, &ch, 1, 10); // timeout: 10ms
	return ch;
}
void ProgramStart(char *str)
{
	//printf("\033[2J\033[0;0H"); // printf("\033[2J"); : 화면 Clear
	cls();
	Cursor(0,0);
	printf("Program Name - %s\r\n", str);
	printf("Press Blue-button(B1) to Start ...\r\n");
	standby();
}

void standby()
{
	while(HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin));
}

void cls() // 화면 clear
{
	printf("\033[2J");
}

void Cursor(int x, int y)
{
	char buf[20];
	sprintf(buf, "\033[%d;%dH", y,x);
	puts(buf);
}
