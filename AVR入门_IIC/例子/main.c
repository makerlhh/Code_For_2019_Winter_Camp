#include<iom16v.h>
#include<macros.h>

#include"delay.h"
#include"eeprom.h"
#include"usart.h"
#include"iic_hard.h"


void time1_init(void)   //1s        定时器1初始化
{
	TCCR1B|=BIT(CS12);    //256分频
	TCNT1H=(65536-31250)/256;
	TCNT1L=(65536-31250)%256;
	TIMSK|=BIT(2);      //计时小开关
	SREG|=BIT(7);
}
uint sec=0,min=0,hour=0,day=0;



void main(void)
{
	char enter[]="      ";
	uchar i,j=0,key_try_times=3,time_temp;
	uint left_sec;
	usart_init();
	TWI_init();
	time1_init();

		
	eeprom_write_str(0,"123456");   //eeprom写密码	
	TWI_Write_str(0,"Please enter PIN");    //0~15    16
	TWI_Write_str(16,"welcome ^0^");        //16~26   11
	TWI_Write_str(27,"choose function~");   //27~42   16
	TWI_Write_str(43,"enter old PIN");      //43~55   13
	TWI_Write_str(56,"wrong old PIN!");     //69      14
	TWI_Write_str(70,"enter new PIN");      //82      13
	TWI_Write_str(83,"new PIN finish");     //96      14
	
	while(1)
	{		

		for(i=0;i<16;i++)  usart_send_char(TWI_Read(i));                //24c02读取字符串
		delay_ms(2000);
	}
}
#pragma interrupt_handler time1:9             //定时器1   中断
void time1(void)
{
	TCNT1H=(65536-31250)/256;
	TCNT1L=(65536-31250)%256;
	sec++;
	if(sec==60)
	{
		sec=0;
		min++;
	}
	if(min==60)
	{
		min=0;
		hour++;
	}
	if(hour==24)
	{
		hour=0;
		day++;		
	}
	
	TWI_Write(200,day/1000%10+48);        //向24c02储存day,hour,min,sec数值的字符，函数已加延时
	TWI_Write(201,day/100%10+48);
	TWI_Write(202,day/10%10+48);
	TWI_Write(203,day%10+48);
	TWI_Write(204,hour/10%10+48);
	TWI_Write(205,hour%10+48);
	TWI_Write(206,min/10%10+48);
	TWI_Write(207,min%10+48);
	TWI_Write(208,sec/10%10+48);
	TWI_Write(209,sec%10+48);	
	
}