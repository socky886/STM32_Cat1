// Dut_Com.cpp: implementation of the Dut_Com class.
//
//////////////////////////////////////////////////////////////////////


#include "Dut_Com.h"
#include "main.h"
// USART1 is for DUT
extern UART_HandleTypeDef huart1;

/**
 * @brief DUT Tx one byte to control board
 * 
 * @param x 
 */
void Dut_Tx_Byte(unsigned char x)
{
    HAL_UART_Transmit(&huart1, &x, 1, 1000);
}

/**
 * @brief DUT tx string to control board
 * 
 * @param p 
 */
void Dut_Tx_String(char *p)
{
    while (*p != NULL)
    {
        Dut_Tx_Byte(*p++);
    }
}
