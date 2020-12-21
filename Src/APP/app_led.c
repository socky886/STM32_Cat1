


#include <stdio.h>
#include "sys_command_line.h"
#include "sys_queue.h"
#include "app_led.h"
#include "main.h"

/**
 * @brief  LED init
 * @param  ��
 * @retval ��
 */
void LED_Init(void)
{
    //LED_GPIO_Config();
}


/**
 * @brief  LED command init
 * @param  null
 * @retval return True means ok
 */
uint8_t CLI_LED_Init(void)
{
    LED_Init();

    return TRUE;
}


/**
 * @brief  LED command line
 * @param  null
 * @retval null
 */
uint8_t CLI_LED(void *para, uint8_t len)
{
    uint8_t *pTemp;
    pTemp = (uint8_t *)para;
    if ((0 < len) && (NULL != pTemp)) {
        pTemp++; /* skip a blank space */
        if ('1' == *pTemp) {
            /* LED ON */
            //LED1_ON;
            NL1();
            DBG("led on\r\n");
        } else if ('0' == *pTemp) {
            /* LED OFF */
            //LED1_OFF;
            NL1();
            DBG("led off\r\n");
        } else {
            /* para. wrong */
            return FALSE;
        }
    }

    /* led command ok */
    return TRUE;
}



/*********************************************END OF FILE**********************/
