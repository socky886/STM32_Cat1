// Dut_Com.h: interface for the Dut_Com class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DUT_COM_H__89824BCE_A958_43E4_BED7_DFF7CB6E6E38__INCLUDED_)
#define AFX_DUT_COM_H__89824BCE_A958_43E4_BED7_DFF7CB6E6E38__INCLUDED_
#include <stdint.h>

void Dut_Tx_Byte(unsigned char x);
void Dut_Tx_String(char *p);
uint8_t junfeng_pFun(void *p, uint8_t len);
uint8_t Dut_Get_ReadInputReg(uint16_t *p);
uint8_t Dut_Get_ReadDescreteInput(void);
uint8_t Dut_Get_ReadCoil(void);
uint8_t Dut_Set_SingleCoil(uint16_t address,uint8_t onoff);
#endif // !defined(AFX_DUT_COM_H__89824BCE_A958_43E4_BED7_DFF7CB6E6E38__INCLUDED_)
