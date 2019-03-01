#include "eeprom.h"

void eeprom_write(uint address,uint data)
{
	SREG &= ~BIT(7);           //最好关闭总中断，避免打扰。
	while(EECR&BIT(EEWE));     //等待上一次写结束
	EEAR = address;
	EEDR = data;
	EECR |= BIT(EEMWE);       //开总写使能
	EECR |= BIT(EEWE);       //写使能
	SREG |= BIT(7);         //开总中断
}
uchar eeprom_read(uint address)
{
	uchar data;
	//SREG &= ~BIT(7);         //没必要吧？
	while(EECR&BIT(EEWE));     //等待上一次写结束
	EEAR = address;
	EECR |= BIT(EERE);
	data = EEDR;
	//SREG |= BIT(7);
	return data;
}
void eeprom_write_str(uint i,uchar *data)
{
	while (*data) 
	{
    	eeprom_write(i,*data);
    	data++;
		i++;
	}	
}


