#ifndef EEPROM_H
#define EEPROM_H
//Ƭ�ڵ�eeprom
#include<iom16v.h>
#include<macros.h>
#define ulong unsigned long
#define uint unsigned int
#define uchar unsigned char

void eeprom_write(uint address,uint data);    //�� ��ַ д�� 1�ַ�
uchar eeprom_read(uint address);              //�� ��ַ ��ȡ 1�ַ�
void eeprom_write_str(uint i,uchar *data);    //�� ������ַ д���ַ���




#endif