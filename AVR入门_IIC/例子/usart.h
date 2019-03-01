#ifndef USART_H
#define USART_H
#include<iom16v.h>
#include<macros.h>
#define ulong unsigned long
#define uint unsigned int
#define uchar unsigned char

void usart_init(void);    //    9600,8,1,����żУ��          ��ʼ��
void usart_send_char(uchar i);          //�����ַ�
void usart_send_str(char *zifu);        //���� �ַ���
void usart_send(int num);    //����4λ����




/*
#pragma interrupt_handler RX_int:12           //�����ж�
void RX_int(void)     //���յ����ַ�
{
	char i;
	i=UDR;         //����
	usart_send_char(13);           //����
}
char a[30];    //һ��Ҫ  char   ����
void RX_int(void)     //���������ַ���
{
	char b[]="adc";
	int temp=0,flag=1;
	a[z]=UDR;         //����
	z++;
	if(a[z-1]==13)   //��⵽����
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
	usart_send_char(13);           //����
	for(z=0;z<20;z++)a[z]='\0';
	z=0;
	}
}
*/
#endif