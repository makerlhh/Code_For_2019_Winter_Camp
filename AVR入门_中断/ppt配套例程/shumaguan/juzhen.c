#include <iom16v.h>
#include <macros.h>
#define  uchar unsigned char
#define  uint  unsigned int

table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d, 0x07,
		           0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

void delay(uint ms)
{
        uint i,j;
	   for(i=0;i<ms;i++)
	   {
	   for(j=0;j<1141;j++);
       }
}
	      //数据    管口
void show(uchar i,uchar j)//在j管口输出i
{
   PORTA&=~BIT(j);   //是那个管口输出低电平
   PORTC=table[i];
   delay(1);
   PORTA|=BIT(j);
}

uchar key_press()
{
   if(PIND!=0X0F)
   return 1;
   else
   return 0;
}	

uchar key_scan()
{
  uchar key,temp;
    delay(10);
	if(key_press())
	{
	   PORTD=0XEF;
	   temp=PIND;
	   temp&=0X0F;
	   switch(temp)
	   {
	      case 0X0E:key=1;break;
		  case 0x0D:key=5;break; 
          case 0x0B:key=9;break; 
          case 0x07:key=13;break;            
	   }
	   PORTD=0XDF;
	   temp=PIND;
	   temp&=0X0F;
	   switch(temp)
	   {
	      case 0X0E:key=2;break;
		  case 0x0D:key=6;break; 
          case 0x0B:key=10;break; 
          case 0x07:key=14;break;            
	   }
	   PORTD=0XBF;
	   temp=PIND;
	   temp&=0X0F;
	   switch(temp)
	   {
	      case 0X0E:key=3;break;
		  case 0x0D:key=7;break; 
          case 0x0B:key=11;break; 
          case 0x07:key=15;break;            
	   }
	   PORTD=0X7F;
	   temp=PIND;
	   temp&=0X0F;
	   switch(temp)
	   {
	      case 0X0E:key=4;break;
		  case 0x0D:key=8;break; 
          case 0x0B:key=12;break; 
          case 0x07:key=16;break;            
	   }
	   
	}PORTD=0X0F;return key;
	
}


   
void main()
{     
   uchar i,j,shu=3;          
     DDRD|=0XFF;      //1111 1111
	 DDRD&=0XF0;      //1111 0000  
	                  //1111 0000 
	 PORTD|=0X0F;     //0000 1111  
	 DDRA|=0X03;   
	 PORTA|=0X03;    //输出高电平  
	 DDRC=0XFF;      //数码管输出
	   while(1)
		{
		  if(key_press())
		    {
			while(1)
			  {
		       if(key_press())
		       shu=key_scan();
		    
		       show(shu/10,0);
		       show(shu%10,1);  
		      }
			}
		}
	 
}
				   