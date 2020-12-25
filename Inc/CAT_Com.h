// CAT_Com.h: interface for the CCAT_Com class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAT_COM_H__1C19F60E_1AF5_4227_A5D6_250D31B51481__INCLUDED_)
#define AFX_CAT_COM_H__1C19F60E_1AF5_4227_A5D6_250D31B51481__INCLUDED_

// read register, support function code of 0x04
#define MACHINE_START_NUMBER_H 0                             //机器启停数H
#define MACHINE_START_NUMBER_H 1                             //机器启停数L
#define CURRENT_FAULT_CODE 2                                 //当前故障代码
#define LATEST15_FAULT_RECORDS 3                             //近15次故障记录
#define LATEST14_FAULT_RECORDS 4                             //近14次故障记录
#define LATEST13_FAULT_RECORDS 5                             //近13次故障记录
#define LATEST12_FAULT_RECORDS 6                             //近12次故障记录
#define LATEST11_FAULT_RECORDS 7                             //近11次故障记录
#define LATEST10_FAULT_RECORDS 8                             //近10次故障记录
#define LATEST9_FAULT_RECORDS 9                              //近9次故障记录
#define LATEST8_FAULT_RECORDS 10                             //近8次故障记录
#define LATEST7_FAULT_RECORDS 11                             //近7次故障记录
#define LATEST6_FAULT_RECORDS 12                             //近6次故障记录
#define LATEST5_FAULT_RECORDS 13                             //近5次故障记录
#define LATEST4_FAULT_RECORDS 14                             //近4次故障记录
#define LATEST3_FAULT_RECORDS 15                             //近3次故障记录
#define LATEST2_FAULT_RECORDS 16                             //近2次故障记录
#define LATEST1_FAULT_RECORDS 17                             //近1次故障记录
#define EXHAUST_AIR_TEMPERATURE 18                           //排气温度
#define CONDENSE_TEMPERATURE 19                              //冷凝温度
#define ELECTRONIC_EXPANSION_VALVE_OPEN_DEGREE 20            //电子膨胀阀开度
#define ECONOMIZER_INLET_TEMPERATURE 21                      //经济器进口温度
#define ECONOMIZER_OUTLET_TEMPERATURE 22                     //经济器出口温度
#define REVERSE_PHASE_ALARM_SIGNAL 23                        //逆相报警信号
#define OVER_CURRENT_ALRAM_SIGNAL 24                         //过电流报警信号
#define HIGH_VOLTAGE_ALARM_SIGNAL 25                         //高压报警信号
#define PRESSURE_SWITCH_SGINAL 26                            //压力开关信号
#define EXTERNAL_SWITCH_SIGNAL 27                            //外部开关信号
#define COMPRESS_MOTOR_OVER_TEMPERATURE_ALARM 28             //压缩机电机温度过高报警
#define EXHAUST_SENSE_TEMPERATURE_PACKAGE_FAULT 29           //排气感温包故障
#define CONDENSE_SENSE_TEMPERATURE_PACKAGE_FAULT 30          //冷凝感温包故障
#define ECONOMIZER_INLET_SENSE_TEMPERATURE_PACKAGE_FAULT 31  //经济器进口感温包故障
#define ECONOMIZER_OUTLET_SENSE_TEMPERATURE_PACKAGE_FAULT 32 //经济器出口感温包故障
#define COMPRESSOR_STATUS 33                                 //压缩机状态
#define SOLENOID_VALVE_SWITCH 34                             //电磁阀开关
#define FAN_MOTOR1_MIDDLE_SPEED_ONOFF 35                     //风扇电机1中速启动停止
#define FAN_MOTOR1_HIGH_SPEED_ONOFF 36                       //风扇电机1高速启动停止
#define HEATING_BELT_CONTROL_onoff 37                        //加热带控制
#define FAULT_OUTPUT_SIGNAL_onoff 38                         //故障输出信号（ON有效）
#define START_DELAY_INTERVAL_OUTPUT_ONOFF 39                 //启动延时间隔输出
#define FAN_MOTOR2_MIDDLE_SPEED_ONOFF 40                     //风扇电机2中速启动停止
#define FAN_MOTOR2_HIGH_SPEED_ONOFF 41                       //风扇电机2高速启动停止

//read only coil data, support 0x02 function code
#define COMPRESSOR_RUNING_STATUS 0                             //压缩机运行状态
#define EXTERNAL_FAN_RUNNING_STATUS 1                          //外风机运行状态
#define OIL_RETURN_STATUS 2                                    //回油状态
#define DEFROSTING_STATUS 3                                    //化霜状态
#define AUXILIARY_ELECTRIC_HEATING_SWITCH_STATUS 4             //辅助电加热开关状态
#define HIGH_VOLTAGE_SWITCH_STATUS 5                           //高压开关状态
#define LOW_VOLTAGE_SWITCH_STATUS 6                            //低压开关状态
#define WATURE_PUMP_SWITCH_STATUS 7                            //水泵开关状态
#define REVERSE_PALSE_PROTECT_STATUS 8                         //逆相保护
#define EXHAUST_HIGH_TEMPERATURE_PROTECT_STATUS 9              //排气高温保护
#define OVER_CURRENT_PROTECT_STATUS 10                         //过流保护
#define HIGH_VOLTAGE_PROTECT_STATUS 11                         //高压保护
#define LOW_VOLTAGE_PROTECT_STATUS 12                          //低压保护
#define OUTDOOR_E2_FAULT 13                                    //室外E方故障
#define COMPRESSOR_OVER_HEAT_FAULT 14                          //压缩机过热故障
#define OUTDOOR_ENVI_TEMPERATURE_SENSE_PACKAGE_FAULT 15        //室外环境温度感温包故障
#define OUTDOOR_COIL_TEMPERATURE_SENSE_PACKAGE_FAULT 16        //室外盘管温度感温包故障
#define OUTDOOR_EXHAUST_TEMPERATURE_SENSE_PACKAGE_FAULT 17     //室外排气温度感温包故障
#define OUTDOOR_INSPIRATORY_TEMPERATURE_SENSE_PACKAGE_FAULT 18 //室外吸气温度感温包故障
#define INDOOR_COIL_TEMPERATURE_SENSE_PACKAGE_FAULT 19         //室内盘管感温包故障
#define INDOOR_ENVI_TEMPERATURE_SENSE_PACKAGE_FAULT 20         //室内环温感温包故障

//read-write coil data, supprot 0x01,0x05,0x0f function code
#define SYSTEM_UPGRADE_NEED_COMMAND 0 //系统升级需求命令
#define CHECK_RESULT_AFTER_UPGRADE 1  //升级后程序校验结果
#define SYTEM_CURRENT_STATUS 2        //系统当前状态

#define SYSTEM_TURN_ONOFF_COMMAND 1 //系统开关机命令 ????????????????????

//read-write register, support 0x03,0x06,0x10 function code
#define EXHAUST_HIGH_TEMPERATURE_PROTECT_ENTER_VALUE 0     //排气高温度保护进入值
#define EXHAUST_HIGH_TEMPERATURE_PROTECT_REPLY_VALUE 1     //排气高温保护回复值
#define ELECTRIC_VALVE_TURNON_EXHAUST_TEMPERATURE_VALUE 2  //电磁阀开启排气温度值
#define ELECTRIC_VALVE_TURNOFF_EXHAUST_TEMPERATURE_VALUE 3 //电磁阀关闭排气温度值
#define FAN_TURNON_TEMPERATURE_VALUE 4                     //风机开启温度
#define FAN_TURNOFF_TEMPERATURE_VALUE 5                    //风机关闭温度
#define TURNON_DELAY 6                                     //启动延时
#define FAN_ALL_TURN_OFF_TEMPERATURE_VALUE 7               //风机全关闭温度
#define BAUD_RATE 8                                        //波特率
#define MODBUS_ADDRESS 9                                   //Modbus地址
#define CHECK_BIT 10                                       //校验位
#define STOP_BIT 11                                        //停止位
#define EXHAUST_TEMPERATURE_TEMPERATURE_SET_VALUE 12       //排气温度设定值
#define VALVE_INIT_OPEN_DEGREE 13                          //阀的初始开度
#define EXHAUST_TEMPERATUE_DIFFER 14                       //排气温度偏差
#define TARGET_OVER_HEAT_TEMPERATURE_SETTING 15            //目标过热度设定
#define TARGET_OVER_HEAT_TEMPERATURE_SETTING_DIFFER 16     //目标过热度设定偏差
#define ELETRIC_VALVE_TURNON_EXHAUST_TEMPERATURE_VALUE 17  //电磁阀开启排气温度值(补气)
#define ELETRIC_VALVE_TURNOFF_EXHAUST_TEMPERATURE_VALUE 18 //电磁阀关闭排气温度值(补气)

#define SYSTEM_RUN_MODE 200  //系统运行模式
#define RESERVE1_ADDRESS 201 //预留
#define RESERVE1_ADDRESS 202 //预留

//read-write register is used to upgrade the application, support 0x03,0x10 function code
#define FIRMWRE_SIZE 4000            //APP大小
#define crc_check_value 4001         //CRC校验码
#define FIRMWARE_PACKAGE_NUMBER 4002 //烧录固件编号
#define bin_start_address 4003       //固件包的首地址，每包512bytes


//cat1 network register command
#define  AT_TEST  "AT\n"  //PWR_key
#define  QUERY_SIM_CARD_STATUS "AT+CPIN?\n"  //查询SIM卡状态
#define  QUERY_RSSI "AT+CSQ\n"    //查询信号强度
#define  QUERY_DATA_TRANSACTION_ATTACH "AT+CGREG?\n" //查询数据业务附着
#define  QUERY_IMSI_NUMBER "AT+CIMI\n" //查询sim卡IMSI号
#define  Query_IMEI_NUMBER "AT+CGSN\n" //查询模块IMEI号
#define  QUERY_NETWORK_REGISTER_STATUS "AT+QNWINFO\n" //当前网络注册状态

//MQTT related command
#define CONFIG_RECEIVE_DATA_MODE "AT+QMTCFG=\"recv/mode\",0,0,1\n"  //配置接收数据的模式
#define OPEN_MQTT_SERVER "AT+QMTOPEN=0,\"47.102.222.71\",1883\n"  //MQTT客户端打开网络
#define CREATE_MQTT_CONNECTION "AT+QMTCONN=0,\"12345\",\"sxtest\",\"test1215\"\n" //连接MQTT服务器
#define MQTT_SUBSCRIBE_TOPIC  "AT+QMTSUB=0,1,\"Topic/flexem/Box/12345/system/WriteData\",1\n" //订阅主题
#define MQTT_SEND_MESSAGE "AT+QMTPUBEX=0,0,0,0,\"Topic/flexem/Box/12345/system/WriteData\",30\n"  //发送数据
#define MQTT_RECEIVE_MESSAGE "+QMTRECV: 0,0,\"Topic/flexem/Box/12345/system/WriteData\",5,\"hello\"\n" //接收到topic数据的串口打印



void Tx_Byte_To_Cat(unsigned char x);
void Tx_String_To_Cat(char *p);

#endif // !defined(AFX_CAT_COM_H__1C19F60E_1AF5_4227_A5D6_250D31B51481__INCLUDED_)
