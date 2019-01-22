#include "iom16v.h"
#define uint unsigned int
void delay(uint n);

void main()
{
    //心形外环LED
    DDRA = 0XFF;
    PORTA = 0X3F;
	DDRB = 0XFF;
	PORTB = 0X44;
	//外环LED
	DDRC = 0XFF;
	PORTC = 0XFF;
    DDRD = 0XFF;
	PORTD = 0XFF;
	//心形内闪烁
	while(1)
	{
	    PORTB |= (1<<4);
		delay(1);
		PORTB &= ~(1<<4);
		delay(1);
		
		PORTB |= (1<<3);
		delay(1);
		PORTB &= ~(1<<3);
		delay(1);
		
		PORTB |= (1<<0);	
		PORTA |= (1<<6);
		delay(1);
		PORTB &= ~(1<<0);	
		PORTA &= ~(1<<6);
		delay(1);
		
		PORTA |= (1<<7);
		PORTB |= (1<<5);
		delay(1);
		PORTA &= ~(1<<7);
		PORTB &= ~(1<<5);
		delay(1);	
		PORTB |= (1<<7);
		delay(1);	
	    PORTB &= ~(1<<7);
		delay(1);
	}	
}

void delay(uint n)  //延时n*100ms  
{
    uint i,j,m;
    for(n;n>0;n--)
    {
        for(m = 2;m>0;m--)
        {
             for(i = 250;i>0;i--)
             {
   	             for(j = 230;j>0;j--);
             }
        }
    }
}