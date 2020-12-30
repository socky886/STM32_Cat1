// Dut_Com.h: interface for the Dut_Com class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DUT_COM_H__89824BCE_A958_43E4_BED7_DFF7CB6E6E38__INCLUDED_)
#define AFX_DUT_COM_H__89824BCE_A958_43E4_BED7_DFF7CB6E6E38__INCLUDED_
#include <stdint.h>

// typedef enum
// {
//     N_EXHAUST_HIGH_TEMPERATURE_PROTECT_ENTER_VALUE = 0,     //排气高温度保护进入值
//     N_EXHAUST_HIGH_TEMPERATURE_PROTECT_REPLY_VALUE = 1,     //排气高温保护回复值
//     N_ELECTRIC_VALVE_TURNON_EXHAUST_TEMPERATURE_VALUE = 2,  //电磁阀开启排气温度值
//     N_ELECTRIC_VALVE_TURNOFF_EXHAUST_TEMPERATURE_VALUE = 3, //电磁阀关闭排气温度值
//     N_FAN_TURNON_TEMPERATURE_VALUE = 4,                     //风机开启温度
//     N_FAN_TURNOFF_TEMPERATURE_VALUE = 5,                    //风机关闭温度
//     N_TURNON_DELAY = 6,                                     //启动延时
//     N_FAN_ALL_TURN_OFF_TEMPERATURE_VALUE = 7,               //风机全关闭温度
//     N_BAUD_RATE = 8,                                        //波特率
//     N_MODBUS_ADDRESS = 9,                                  //Modbus地址
//     N_CHECK_BIT = 10,                                       //校验位
//     N_STOP_BIT = 11,                                        //停止位
//     N_EXHAUST_TEMPERATURE_TEMPERATURE_SET_VALUE = 12,       //排气温度设定值
//     N_VALVE_INIT_OPEN_DEGREE = 13,                          //阀的初始开度
//     N_EXHAUST_TEMPERATUE_DIFFER = 14,                       //排气温度偏差
//     N_TARGET_OVER_HEAT_TEMPERATURE_SETTING = 15,            //目标过热度设定
//     N_TARGET_OVER_HEAT_TEMPERATURE_SETTING_DIFFER = 16,     //目标过热度设定偏差
//     N_ELETRIC_VALVE_TURNON_EXHAUST_TEMPERATURE_VALUE = 17,  //电磁阀开启排气温度值(补气)
//     N_ELETRIC_VALVE_TURNOFF_EXHAUST_TEMPERATURE_VALUE = 18, //电磁阀关闭排气温度值(补气)

//     N_SYSTEM_RUN_MODE = 200,  //系统运行模式
//     N_RESERVE1_ADDRESS = 201, //预留
//     N_RESERVE2_ADDRESS = 202 //预留

// } ReadHoldRegIndex_t;

void Dut_Tx_Byte(unsigned char x);
void Dut_Tx_String(char *p);
uint8_t junfeng_pFun(void *p, uint8_t len);
uint8_t Dut_Get_ReadInputReg(uint16_t *p);
uint8_t Dut_Get_ReadDescreteInput(void);
uint8_t Dut_Get_ReadCoil(void);
uint8_t Dut_Set_SingleCoil(uint16_t address,uint8_t onoff);
uint8_t Dut_Set_Multi_HoldReg(void);
uint8_t Dut_Get_Multi_HoldReg(void);
uint8_t Dut_OTA_Firmware(void);
uint32_t CalcCRC32(uint8_t * ptr, uint32_t startIndex, uint32_t len,int32_t seed);
uint8_t Dut_Crc_test(void);

//below function is used to test the cli
uint8_t WriteReg_pFun(void * p, uint8_t len);
uint8_t ReadReg_pFun(void * p, uint8_t len);
uint8_t ReadInputReg_pFun(void * p, uint8_t len);
uint8_t Fireware_OTA_pFun(void * p, uint8_t len);
#endif // !defined(AFX_DUT_COM_H__89824BCE_A958_43E4_BED7_DFF7CB6E6E38__INCLUDED_)
