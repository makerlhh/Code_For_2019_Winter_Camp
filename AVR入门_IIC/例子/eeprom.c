#include "eeprom.h"

void eeprom_write(uint address,uint data)
{
	SREG &= ~BIT(7);           //��ùر����жϣ�������š�
	while(EECR&BIT(EEWE));     //�ȴ���һ��д����
	EEAR = address;
	EEDR = data;
	EECR |= BIT(EEMWE);       //����дʹ��
	EECR |= BIT(EEWE);       //дʹ��
	SREG |= BIT(7);         //�����ж�
}
uchar eeprom_read(uint address)
{
	uchar data;
	//SREG &= ~BIT(7);         //û��Ҫ�ɣ�
	while(EECR&BIT(EEWE));     //�ȴ���һ��д����
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


