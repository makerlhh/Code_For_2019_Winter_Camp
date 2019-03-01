#include "delay.h"

void delay_us(uint n )
{
 	 uint m = 8*n ;
	 while(m)
	 {
	  		 m-- ;
	 }
}


void delay_ms(uint n)
{
 	 uint i , j ;
	 for(i=0;i<1141;i++)
	 		for(j=0;j<n;j++)
			;
}