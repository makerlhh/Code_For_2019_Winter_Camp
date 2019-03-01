/*
接线：
SCL(PC0)---SCK
SDA(PC1)---SDA

注意：用于24c02外部eeprom，地址：A0~A2为低。
*/
//#ifndef TWI_H_
//#define TWI_H_
#ifndef IIC_HARD_H
#define IIC_HARD_H

#include "DELAY.h"
#include<iom16v.h>
#include<macros.h>
#define ulong unsigned long
#define uint unsigned int
#define uchar unsigned char


//主机模式启动状态码
#define START    	  0x08    //启动      
#define RE_START  	  0x10	  //重新启动 

//主机发送模式状态码
#define MT_SLA_ACK    0x18	  //SLA+W 已发送,接收到 ACK    
#define MT_SLA_NOACK  0x20	  //SLA+W 已发送,接收到 NOT ACK 	   
#define MT_DATA_ACK   0x28	  //数据已发送,接收到 ACK 	 
#define MT_DATA_NOACK 0x30	  //数据已发送,接收到 NOT ACK 

//主机接收模式状态码
#define MR_SLA_ACK    0x40	  //SLA+R 已发送,接收到 ACK	 
#define MR_SLA_NOACK  0x48	  //SLA+R 已发送,接收到 NOT ACK 
#define MR_DATA_ACK   0x50	  //数据已接收,接收到 ACK    
#define MR_DATA_NOACK 0x58    //数据已接收,接收到 NOT ACK	  

//AT24C02C地址格式为 1 0 1 0 A0 A1 A2 R/W 
//前4位器件固定,后三位看连线,最后1位是读写指令位 ,1为读 ，0为写
//#define RD_AT2402C_ADDR 0xA1   
//#define WD_AT2402C_ADDR 0xA0

#define RD_AT2402C_ADDR 0xA1   
#define WD_AT2402C_ADDR 0xA0

#define RD_DS1307_ADDR 0XD1
#define WD_DS1307_ADDR 0XD0

//常用TWI操作(主模式写和读)
#define Start()      (TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN))    	//发出 START 信号 ，清零TWINT、清零start
#define Stop()       (TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN))  	//发送 STOP 信号
#define Wait()       {while(!(TWCR&(1<<TWINT)));}               //等待TWINT 置位 ，TWINT 置位表示START 信号已发出
#define Satus()      (TWSR&0xf8)                                //检验TWI 状态寄存器
#define SetAck       (TWCR|=(1<<TWEA))                          //做出 ACK应答
#define SetNoAck     (TWCR&=~(1<<TWEA))                         //做出 Not Ack应答
#define TWI_READ()   (TWCR=(1<<TWINT)|(1<<TWEN))           		//启动主TWI读方式
#define Write8Bit(x) {TWDR=(x);TWCR=(1<<TWINT)|(1<<TWEN);}      //写数据到TWDR

//定义TWI运行状态的极性
#define TRUE  0
#define FALSE 1

//写操作   已加上延时，可防止连续而出错，       读写操作要避免中断打扰
void TWI_init(void);
uchar TWI_Write(uchar RegAddress,uchar Wdata);
TWI_Write_str(uchar RegAddress,uchar *Wdata);
uchar TWI_Read(uchar RegAddress);

#endif 