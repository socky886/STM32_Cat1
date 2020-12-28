// Dut_Com.cpp: implementation of the Dut_Com class.
//
//////////////////////////////////////////////////////////////////////


#include "Dut_Com.h"
#include "main.h"
#include "modbus_master.h"
// USART1 is for DUT
extern UART_HandleTypeDef huart1;
struct
{
    uint8_t ng_index[42];
    uint16_t ng_ReadInputReg[42];
} s_ReadInputReg;

struct
{
    uint16_t ng_index[2];
    uint16_t ng_ReadDiscreteInput[2];
} s_ReadDiscreteInput;

struct
{
    uint16_t ng_index[2];
    uint16_t ng_ReadCoil[2];
} s_ReadCoil;

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

uint8_t junfeng_pFun(void * p, uint8_t len)
{
    // int result;
    // int Input_Result[2];
    // // Dut_Tx_String("this is dut application\n");
    // Tx_String_To_Cat("dut modbus test\n");
    // result = ModbusMaster_readInputRegisters(0x01, 0x2, 2);
    // if (result == 0x00)
    // {
    //   Input_Result[0] = ModbusMaster_getResponseBuffer(0x00);
    //   Input_Result[1] = ModbusMaster_getResponseBuffer(0x01);
    // }
    // return 0x00;

    //weijunfeng test 20201223
    // return Dut_Get_ReadInputReg(NULL);
    // return Dut_Get_ReadDescreteInput();
    // return Dut_Get_ReadCoil();
    Dut_Set_SingleCoil(0x00,1);
    Dut_Set_SingleCoil(0x00,0);
    return 0x00;
    
}

/**
 * @brief Get Read input Register 
 *        the function code is 0x04
 * 
 * @param p 
 * @return uint8_t 
 */
uint8_t Dut_Get_ReadInputReg(uint16_t *p)
{
    int result;
    int i;
    char xx[20];
    result = ModbusMaster_readInputRegisters(0x01, 0x00, 42);
    if (result == 0x00)
    {
        for (i = 0; i < 42; i++)
        {
            s_ReadInputReg.ng_index[i] = 0;
            if (s_ReadInputReg.ng_ReadInputReg[i] != ModbusMaster_getResponseBuffer(i))
            {
                s_ReadInputReg.ng_ReadInputReg[i] = ModbusMaster_getResponseBuffer(i);
                s_ReadInputReg.ng_index[i] = 1;
            }
            //s_ReadInputReg.ng_ReadInputReg[i]=ModbusMaster_getResponseBuffer(i);
            sprintf(xx, "%d is 0x%04x\n", i, s_ReadInputReg.ng_ReadInputReg[i]);
            Tx_String_To_Cat(xx);
        }
        return 0x00;
    }
    else
    {
        Tx_String_To_Cat("read input register error\n");
        return 0x01;
    }
}

/**
 * @brief Read Descrete Input 
 *        the function code is 0x02
 * 
 * @return uint8_t 
 */
uint8_t Dut_Get_ReadDescreteInput(void)
{
    int result;
    int i,k;
    int m,n;
    char xx[20];
    result=ModbusMaster_readDiscreteInputs(0x01, 0x00, 21);
    if (result==0x00)
    {
        s_ReadDiscreteInput.ng_index[0]=0x00;
        s_ReadDiscreteInput.ng_index[1]=0x00;

        // return byte count is (21+7)/8
        k=(21+7)>>3;
        // each two byte combine one unit
        k=(k+1)>>1;
       for ( i = 0,n=0; i < k; i++,n++)
       {
           s_ReadDiscreteInput.ng_index[i]=s_ReadDiscreteInput.ng_ReadDiscreteInput[i]^ModbusMaster_getResponseBuffer(i);
           s_ReadDiscreteInput.ng_ReadDiscreteInput[i]=ModbusMaster_getResponseBuffer(i);
           result=ModbusMaster_getResponseBuffer(i);
           for ( m = 0; m < 16; m++)
           {
               if (result & 0x01)
               {
                   sprintf(xx, "%d is on\n", m+n*16);
                   Tx_String_To_Cat(xx);
               }
               else
               {
                   sprintf(xx, "%d is off\n", m+n*16);
                   Tx_String_To_Cat(xx);
               }
               result>>=1;
               if((m+n*16)==20)
                break;
           }
           
        //    sprintf(xx, "%d is 0x%04x\n", i, ModbusMaster_getResponseBuffer(i));
        //    Tx_String_To_Cat(xx);
       }
       
       return 0x00;
    }

    return 0x01;
    
}

/**
 * @brief Read Coil which function code is 0x01
 * 
 * @return uint8_t 
 */
uint8_t Dut_Get_ReadCoil(void)
{
     int result;
    int i,k;
    int m,n;
    char xx[20];
    result= ModbusMaster_readCoils(0x01, 0x00, 4);
    if (result==0x00)
    {
        s_ReadCoil.ng_index[0]=0x00;
        s_ReadCoil.ng_index[1]=0x00;

        // return byte count is (4+7)/8
        k=(4    +7)>>3;
        // each two byte combine one unit
        k=(k+1)>>1;
       for ( i = 0,n=0; i < k; i++,n++)
       {
           s_ReadCoil.ng_index[i]=s_ReadCoil.ng_ReadCoil[i]^ModbusMaster_getResponseBuffer(i);
           s_ReadCoil.ng_ReadCoil[i]=ModbusMaster_getResponseBuffer(i);
           result=ModbusMaster_getResponseBuffer(i);
           for ( m = 0; m < 16; m++)
           {
               if (result & 0x01)
               {
                   sprintf(xx, "%d is on\n", m+n*16);
                   Tx_String_To_Cat(xx);
               }
               else
               {
                   sprintf(xx, "%d is off\n", m+n*16);
                   Tx_String_To_Cat(xx);
               }
               result>>=1;
               if((m+n*16)== 3) //you should replace the real value 
                break;
           }
           
        //    sprintf(xx, "%d is 0x%04x\n", i, ModbusMaster_getResponseBuffer(i));
        //    Tx_String_To_Cat(xx);
       }
       
       return 0x00;
    }

    return 0x01;
}

uint8_t Dut_Set_SingleCoil(uint16_t address,uint8_t onoff)
{
    int result;
    int i, k;
    int m, n;
    char xx[20];
    result=ModbusMaster_writeSingleCoil(0x01, address, onoff);
    if (result==0x00)
    {
    //    i=ModbusMaster_getResponseBuffer(0);
    //    i&=0x01;
       if(onoff==0x00)
       {
           printf("the state is off\n");
          
       }
       else
       {
            printf("the state is on\n");
       }
       return 0x00;
    }
    return 0x01;
    
}