#ifndef EEPROM_H
#define EEPROM_H
//片内的eeprom
#include<iom16v.h>
#include<macros.h>
#define ulong unsigned long
#define uint unsigned int
#define uchar unsigned char

void eeprom_write(uint address,uint data);    //在 地址 写入 1字符
uchar eeprom_read(uint address);              //在 地址 读取 1字符
void eeprom_write_str(uint i,uchar *data);    //在 连续地址 写入字符串




#endif