#include "iic_hard.h"
#include"delay.h"
void TWI_init(void)
{  
    TWCR=(1<<TWEA)|(1<<TWEN);
    TWBR=32;    //为主机时不小于10
    TWSR=0;   //预分频  1
}

uchar TWI_Write(uchar RegAddress,uchar Wdata)
{
   DDRC|=(1<<PC0)|(1<<PC1);
   Start();      		 	   //TWI启动
   Wait();
   if(Satus()!=START)   //检验状态
   return FALSE;    
   
   Write8Bit(WD_AT2402C_ADDR); //写 AT24C02C地址和写方式
   Wait();
   if(Satus()!=MT_SLA_ACK) 
   return FALSE;     
      
   Write8Bit(RegAddress);  	   //写 AT24C02C相应寄存器地址
   Wait();
   if(Satus()!=MT_DATA_ACK) 
   return FALSE;        
  
   Write8Bit(Wdata);     	   //写数据到 AT24C02C相应寄存器
   Wait();
   if(Satus()!=MT_DATA_ACK) 
   return FALSE;         
   
   Stop();        	 		   //TWI停止
   delay_us(10);   		   	   //延时
   delay_us(200);///////////////////////++++++++要加，不然连续写会出错！！
   return TRUE;
}
TWI_Write_str(uchar RegAddress,uchar *Wdata)
{
    //自己写哦
}



uchar TWI_Read(uchar RegAddress)
{
   uchar temp;
   Start();	   			  	   //TWI启动
   Wait();
   if (Satus()!=START) 
    return FALSE;        
    
   Write8Bit(WD_AT2402C_ADDR); //写 AT24C02C地址和写方式
   Wait(); 
   if (Satus()!=MT_SLA_ACK) 
    return FALSE;        
    
   Write8Bit(RegAddress);      //写 AT24C02C相应寄存器地址
   Wait();
   if (Satus()!=MT_DATA_ACK) 
    return FALSE;
    
   Start();            	       //TWI重新启动
   Wait();
   if (Satus()!=RE_START)  
    return FALSE;
    
   Write8Bit(RD_AT2402C_ADDR); //写 AT24C02C地址和读方式
   Wait();
   if(Satus()!=MR_SLA_ACK)  
    return FALSE;      
    
   TWI_READ();          	   //启动主TWI读方式
   Wait();
   if(Satus()!=MR_DATA_NOACK)//读完一个数停止接收数据,主机接收到不再接收应答信号,如果继续接收到应答信号
   							  //说明主机继续接收数据则为错误	 													 																		 
    return FALSE;     
    
   temp=TWDR;        		   //读取 TWI接收数据
   Stop();          		   //TWI停止
   return temp;
}


