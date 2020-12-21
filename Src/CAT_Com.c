// CAT_Com.cpp: implementation of the CCAT_Com class.
//
//////////////////////////////////////////////////////////////////////


#include "CAT_Com.h"
#include "main.h"

// huart2 is used for Cat
extern UART_HandleTypeDef huart2;

/**
 * @brief Tx one byte to CAT module
 * 
 * @param x 
 */
void Tx_Byte_To_Cat(unsigned char x)
{
    HAL_UART_Transmit(&huart2, &x, 1, 1000);
}
/**
 * @brief Tx string to Cat module
 * 
 * @param p 
 */
void Tx_String_To_Cat(char *p)
{
    while (*p != NULL)
    {
        Tx_Byte_To_Cat(*p++);
    }
}


