#include"iom16v.h"
//#include"macros.h"
//#define  uint  unsigned int
#define  uchar unsigned char
void timer_init(void)
{                   
 TCCR0 =0x00;//计时器的名称     
 TCNT0 =  0 ;//初值
 TCCR0 =0b00000010 ;//普通模式八分频
}
const table[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};//共阴不带小数点的0~9
const table1[10]={0xbf,0x86,0xdb,0xcf,0xe6,0xed,0xfd,0x87,0xff,0xef};//共阴带小数点的0~9
void delay(int ms)//延时函数
{int i,j;
  for(i=0;i<ms;i++)
   {
   for(j=0;j<1141;j++);
   }
 }
 void time(void)
 {
   
    int i;
      for(i=0;i<10;i++)//1ms
       {                     
         while(1)
          {
            if(TCNT0==100)
              {                    
                 TCNT0=0;
                 break;
              } 
          }
       }
   
}
char key_press(void)//按下按键的函数
{
    char j;
    DDRD|=0X0F;
	PORTD|=0X0F;
	DDRD&=0XF0;
	j=PIND;
	j=j&0X0F;//00001111
}
void scan(int a,int b ,int c,int d,int e,int f,int g,int h)//检测开始后有无再按下其他开关
{
	char j,k;
    DDRD|=0X0F;//检测按键
	PORTD|=0X0F;
	DDRD&=0XF0;
	j=PIND;
	j=j&0X0F;
	if(j==0X0D)//复位
	 {while(1){
	for(k=0;k<8;k++){
	  PORTA=~(1<<k);
	  if(k%2==0&&k!=0)//让特定的位置带小数点
      PORTB=table1[0];
	  else
	  PORTB=table[0];
      delay(1);
	  DDRD|=0X0F;//再次检测按键
	  PORTD|=0X0F;
	  DDRD&=0XF0;
	  j=PIND;
	  j=j&0X0F;
	  if(j==0X07){//复位时检测到‘开始’的按键即开始
       zhanshi();
	        }
	     }
	   }
	  } 
	else if(j==0X0B)//暂停
	{while(1){//动态显示
	 PORTA=~(1<<7);
     PORTB=table[h];
     delay(1);
     PORTA=~(1<<6);
     PORTB=table1[g];
     delay(1);
     PORTA=~(1<<5);
     PORTB=table[f];
     delay(1);
     PORTA=~(1<<4);
     PORTB=table1[e];
     delay(1);
     PORTA=~(1<<3);
     PORTB=table[d];
     delay(1);
     PORTA=~(1<<2);
     PORTB=table1[c];
     delay(1);
     PORTA=~(1<<1);
     PORTB=table[b];
     delay(1);
     PORTA=~(1<<0);
     PORTB=table[a];
     delay(1);
	 delay(10);
	 DDRD|=0X0F;
	 PORTD|=0X0F;
	 DDRD&=0XF0;
	 j=PIND;
	 j=j&0X0F;
	 if(j==0X0D)//暂停时可以检测复位按键
	 {while(1){
	  for(k=0;k<8;k++){
	  PORTA=~(1<<k);
	  if(k%2==0&&k!=0)
      PORTB=table1[0];
	  else
	  PORTB=table[0];
      delay(1);
	  DDRD|=0X0F;
	  PORTD|=0X0F;
	  DDRD&=0XF0;
	  j=PIND;
	  j=j&0X0F;
	  if(j==0X07){
       zhanshi();
	        }
	     }
	   }
	  }
	else if(j==0X0E){//继续运行
	 break;
	 }
	}
	}
}

void zhanshi()//显示计数
{
int a,b,c,d,e,f,g,h,l,z,j;
while(1){
for(h=0;h<10;h++){
for(g=0;g<10;g++){
for(f=0;f<6;f++) {
for(e=0;e<10;e++){
for(d=0;d<6;d++) {
for(c=0;c<10;c++){
for(b=0;b<10;b++){
for(a=0;a<10;a++){
int i=7;
time();
PORTA=~(1<<i--);
PORTB=table[h];
delay(1);
PORTA=~(1<<i--);
PORTB=table1[g];
delay(1);
PORTA=~(1<<i--);
PORTB=table[f];
delay(1);
PORTA=~(1<<i--);
PORTB=table1[e];
delay(1);
PORTA=~(1<<i--);
PORTB=table[d];
delay(1);
PORTA=~(1<<i--);
PORTB=table1[c];
delay(1);
PORTA=~(1<<i--);
PORTB=table[b];
delay(1);
PORTA=~(1<<i--);
PORTB=table[a];
delay(1);
scan(a,b,c,d,e,f,g,h);
}
}
}
}
}
}
}
}
}
}

void main(void)
{
int a,b,c,d,e,f,g,h,l,z,j,k;
timer_init();
DDRA|=0XFF;
PORTA|=0X00;
DDRB|=0XFF;
PORTB|=0X3F;
while(1){
	for(k=0;k<8;k++){
	  PORTA=~(1<<k);
	  if(k%2==0&&k!=0)
      PORTB=table1[0];
	  else
	  PORTB=table[0];
      delay(1);

	  DDRD|=0X0F;
	PORTD|=0X0F;
	DDRD&=0XF0;
	j=PIND;
	j=j&0X0F;
	  if(j==0X07){

     zhanshi();
       }
     }
  }
}