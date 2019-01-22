#include"iom16V.h"
#include<macros.h>
#define uint unsigned int
#define M 100

void delay(int ms)
{
   uint i,j;
   for(i=0;i<ms;i++)
   for(j=0;j<1141;j++);
}
void main()
{
   uint i,j;
   while(1)
   {
   for(i=0;i<8;i++)
   {
      DDRA |= (1<<i);
      PORTA |=(1<<i);
      delay(M);
      PORTA &= ~(1<<i);
   }
   
      DDRA |= (1<<0);
      PORTA |=(1<<0);
      delay(M);
      PORTA &= ~(1<<0);
  
   for(j=8;j>0;j--)
   {
      DDRA |= (1<<j);
      PORTA |=(1<<j);
      delay(M);
      PORTA &= ~(1<<j);
   }
   }
}
