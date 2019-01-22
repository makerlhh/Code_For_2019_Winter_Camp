#include"iom16V.h"

void delay_ms(int ms) //延迟函数
{
    int i,j;
    for(i=0;i<ms;i++)
	{
	    for(j=0;j<1148;j++);
	}
}

void port_init(void)
{
    DDRA=0x00;
    PORTA=0x00;
}

void main()
{
    port_init();
    while(1)
	{
       DDRA |= (1<<2);  //输出高电平
	   PORTA |= (1<<2);
	   delay_ms(500);
	   DDRA |= (1<<2);
	   PORTA &= ~(1<<2); //输出低电平
	   delay_ms(500);
	}
}