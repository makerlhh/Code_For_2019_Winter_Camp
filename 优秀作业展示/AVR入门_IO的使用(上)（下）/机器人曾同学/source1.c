#include<iom16v.h>
#define uint unsigned int
#define uchar unsigned char

int crol(int a,int i)//循环左移函数
{
 	int temp;
 	temp=a>>(8-i);
 	a=a<<i;
 	a=a|temp;
	return a;
}

void delay(int z)
{	 
	 uint x,y;
 	 for(x=0;x<z;x++)
	 	for(y=0;y<1148;y++);
}

void main()//PA,PB控制行，PC,PD控制列，从上往下，从右往左
{	int x,y,flag;
	x=y=flag=0;
	DDRA=0xff;
	DDRB=0xff;
	DDRC=0xff;
	DDRD=0xff;
	
	PORTA=0x01;
	PORTB=0x00;
	PORTC=0xfe;
	PORTD=0xff; 
	delay(10);
	
 	while(1)
	{		
			if(x<7)
			{
			PORTA = crol(PORTA,1);	
			delay(10);	
			}
			if(x>8)
			{
			PORTB = crol(PORTB,1);
			delay(10);
			}			
			x++;
			if(x==8)
			{
			PORTA=0X00;
			PORTB=0x01;
			delay(10);
			}
			if(x==16)
			{
			x=0;
			y++;
			if(y==8)
			{
			 PORTC=0xff;
			 PORTD=0xfe;
			}
			if(y==16)
			{
			y=0;
			PORTC=0xfe;
			PORTD=0xff;
			}
			if(y<8)
			PORTC=crol(PORTC,1);
			if(y>8)
			PORTD=crol(PORTD,1);
			PORTA=0x01;
			PORTB=0x00;		
			delay(10);
			}		

	}
}