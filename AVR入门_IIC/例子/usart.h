#ifndef USART_H
#define USART_H
#include<iom16v.h>
#include<macros.h>
#define ulong unsigned long
#define uint unsigned int
#define uchar unsigned char

void usart_init(void);    //    9600,8,1,无奇偶校验          初始化
void usart_send_char(uchar i);          //发送字符
void usart_send_str(char *zifu);        //发送 字符串
void usart_send(int num);    //发送4位数字




/*
#pragma interrupt_handler RX_int:12           //接收中断
void RX_int(void)     //接收单个字符
{
	char i;
	i=UDR;         //接收
	usart_send_char(13);           //过行
}
char a[30];    //一定要  char   ！！
void RX_int(void)     //接收整个字符串
{
	char b[]="adc";
	int temp=0,flag=1;
	a[z]=UDR;         //接收
	z++;
	if(a[z-1]==13)   //检测到换行
	{
	a[z-1]='\0';         //    !!!
	while(*(a+temp))
	{
		if(*(a+temp)==*(b+temp))
		{
			temp++;
		}
		else
		{
			flag=0;
			usart_send_str("wrong!");
			break;
		}
	}
	if(flag)
	{
		temp=adc_one();
		usart_send_char(temp/1000%10+48);
		usart_send_char(temp/100%10+48);
		usart_send_char(temp/10%10+48);
		usart_send_char(temp%10+48);
	}
	usart_send_char(13);           //过行
	for(z=0;z<20;z++)a[z]='\0';
	z=0;
	}
}
*/
#endif