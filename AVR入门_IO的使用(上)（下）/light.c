#include"iom16v.h"

/*
��Ƭ���ͺ�Ϊ  ATmegaXX
��Ҫ��ͷ�ļ�  iomXXv.h
����Ӫ����ѧ�ĵ�Ƭ���ͺ�ͳһΪATmega16

�������:
����ߵ�ƽ
DDRX |= (1<<n);PORTX |= (1<<n);
����͵�ƽ
DDRX |= (1<<n);PORTX &= ~(1<<n);
��������
DDRX &= ~(1<<n);PORTX |= (1<<n);
����̬
DDRX &= ~(1<<n);PORTX &= ~(1<<n);
*/

void delay_ms(int ms)//��ʱ����
{
   int i,j;
   for(i=0;i<ms;i++)
   {
       for(j=0;j<1148;j++);
   }
}

void main()
{
   while(1)
   {
      DDRA |= (1<<2);//PA2����ߵ�ƽ 
      PORTA |= (1<<2);
      delay_ms(500);//��ʱ500ms
      PORTA &= ~(1<<2);//PA2����͵�ƽ
   
      DDRB |= (1<<2);
      PORTB |= (1<<2);
      delay_ms(500);
      PORTB &= ~(1<<2);
   }
   
}

