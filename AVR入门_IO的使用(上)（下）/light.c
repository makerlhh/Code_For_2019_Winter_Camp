#include"iom16v.h"

/*
单片机型号为  ATmegaXX
则要加头文件  iomXXv.h
冬令营我们学的单片机型号统一为ATmega16

四种组合:
输出高电平
DDRX |= (1<<n);PORTX |= (1<<n);
输出低电平
DDRX |= (1<<n);PORTX &= ~(1<<n);
上拉输入
DDRX &= ~(1<<n);PORTX |= (1<<n);
高阻态
DDRX &= ~(1<<n);PORTX &= ~(1<<n);
*/

void delay_ms(int ms)//延时函数
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
      DDRA |= (1<<2);//PA2输出高电平 
      PORTA |= (1<<2);
      delay_ms(500);//延时500ms
      PORTA &= ~(1<<2);//PA2输出低电平
   
      DDRB |= (1<<2);
      PORTB |= (1<<2);
      delay_ms(500);
      PORTB &= ~(1<<2);
   }
   
}

