// Dut_Com.cpp: implementation of the Dut_Com class.
//
//////////////////////////////////////////////////////////////////////


#include "Dut_Com.h"
#include "main.h"
#include "modbus_master.h"
#include "CAT_Com.h"
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

uint16_t ng_HoldReg[] = {
    100,  //排气高温度保护进入值
    50,   //排气高温保护回复值
    100,  //电磁阀开启排气温度值
    50,   //电磁阀关闭排气温度值
    60,   //风机开启温度
    70,   //风机关闭温度
    200,  //启动延时
    100,  //风机全关闭温度
    3,    //波特率
    0x01, //Modbus地址
    0,    //校验位
    0,    //停止位
    80,   //排气温度设定值
    100,  //阀的初始开度
    5,    //排气温度偏差
    6,    //排气温度偏差
    7,    //目标过热度设定
    5,    //目标过热度设定偏差
    100,  //电磁阀开启排气温度值(补气)
    100   //电磁阀关闭排气温度值(补气)
};
// ng_HoldReg[SYSTEM_RUN_MODE] = 0x01;  //系统运行模式
// ng_HoldReg[RESERVE1_ADDRESS] = 0x01; //预留
// ng_HoldReg[RESERVE2_ADDRESS] = 0x01; //预留



extern uint8_t Modbus_Master_Write(uint8_t *buf,uint8_t length);

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
/**
 * @brief 
 * 
 * @param address 
 * @param onoff 
 * @return uint8_t 
 */
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
/**
 * @brief read holding register
 * 
 * @return unit8_t 
 */
uint8_t  Dut_Get_Multi_HoldReg(void)
{
    int result;
    int i;

    result = ModbusMaster_readHoldingRegisters(0x01, 0x00, 19);
    if (result == 0x00)
    {
        for (i = 0; i < 19; i++)
        {
            ng_HoldReg[i] = ModbusMaster_getResponseBuffer(i);
            printf("%d value is %d\n", i, ng_HoldReg[i]);
        }
    }

    //return value
    return result;
}
/**
 * @brief write multiple register
 * 
 * @return uint8_t 
 */
uint8_t Dut_Set_Multi_HoldReg(void)
{
    int result;
    int i;
    //clear transmit buffer
    ModbusMaster_clearTransmitBuffer();

    // fill the transmit buffer
    for ( i = 0; i < 19; i++)
    {
        ModbusMaster_setTransmitBuffer(i,ng_HoldReg[i]);
    }
    
    // write multiple register
    result=ModbusMaster_writeMultipleRegisters(0x01,0x00,19);
    if(result==0x00)
    {
        printf("write multiple registers successfully\n");
    }
    else
    {
        printf("write multiple registers failed\n");
    }
    
    //return result
    return result;
}

uint8_t Dut_OTA_Firmware(void)
{
    int result;
    uint16_t rs;
    uint8_t rs_upgrade=0x00;
    uint8_t data[512];
    uint8_t header[4];
    //read single coil which address is 0x02
    // get the current status of system
    // 0: bootloader; 1: app
    result = ModbusMaster_readCoils(0x01, 0x02, 1);
    if (result == 0x00)
    {
        // get the current status of system
        rs = ModbusMaster_getResponseBuffer(0);
        rs &= 0x01;

        // the current status of system is app
        if (rs == 0x01)
        {
            // write single coil to switch to bootload
            ModbusMaster_writeSingleCoil(0x01, 0x02, 1);
            result = ModbusMaster_readCoils(0x01, 0x00, 3);
            if (result == 0x00)
            {
                rs = ModbusMaster_getResponseBuffer(0);
                if ((rs & 0x01 == 0x01) && (rs & 0x04 == 0x00))
                {
                    rs_upgrade = 1;
                }
            }
        }
    }

    // permit to upgrade
    // step 1:write app size
    ModbusMaster_writeSingleRegister(0x01,4000,1024);
    // step 2: send appcrc
    ModbusMaster_writeSingleRegister(0x01,4001,0xa1b1);
    // stpe 3 : send firmware number
    ModbusMaster_writeSingleRegister(0x01,4002,0x1001);


    // stpe 4: send bin
    // send firt package
    memset(data,0x01,512);
    header[0]=0x01;// salve id
    header[1]=highByte(4003);//address
    header[2]=lowByte(4003);
    header[3]=0x10; //function code
    Modbus_Master_Write(header,4);
    Modbus_Master_Write(data,512);

    // send second package
    memset(data,0x02,512);
    header[1]=highByte(4004);//address
    header[2]=lowByte(4004);
    Modbus_Master_Write(header,4);
    Modbus_Master_Write(data,512);
}