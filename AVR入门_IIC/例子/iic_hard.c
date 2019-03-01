#include "iic_hard.h"
#include"delay.h"
void TWI_init(void)
{  
    TWCR=(1<<TWEA)|(1<<TWEN);
    TWBR=32;    //Ϊ����ʱ��С��10
    TWSR=0;   //Ԥ��Ƶ  1
}

uchar TWI_Write(uchar RegAddress,uchar Wdata)
{
   DDRC|=(1<<PC0)|(1<<PC1);
   Start();      		 	   //TWI����
   Wait();
   if(Satus()!=START)   //����״̬
   return FALSE;    
   
   Write8Bit(WD_AT2402C_ADDR); //д AT24C02C��ַ��д��ʽ
   Wait();
   if(Satus()!=MT_SLA_ACK) 
   return FALSE;     
      
   Write8Bit(RegAddress);  	   //д AT24C02C��Ӧ�Ĵ�����ַ
   Wait();
   if(Satus()!=MT_DATA_ACK) 
   return FALSE;        
  
   Write8Bit(Wdata);     	   //д���ݵ� AT24C02C��Ӧ�Ĵ���
   Wait();
   if(Satus()!=MT_DATA_ACK) 
   return FALSE;         
   
   Stop();        	 		   //TWIֹͣ
   delay_us(10);   		   	   //��ʱ
   delay_us(200);///////////////////////++++++++Ҫ�ӣ���Ȼ����д�������
   return TRUE;
}
TWI_Write_str(uchar RegAddress,uchar *Wdata)
{
    //�Լ�дŶ
}



uchar TWI_Read(uchar RegAddress)
{
   uchar temp;
   Start();	   			  	   //TWI����
   Wait();
   if (Satus()!=START) 
    return FALSE;        
    
   Write8Bit(WD_AT2402C_ADDR); //д AT24C02C��ַ��д��ʽ
   Wait(); 
   if (Satus()!=MT_SLA_ACK) 
    return FALSE;        
    
   Write8Bit(RegAddress);      //д AT24C02C��Ӧ�Ĵ�����ַ
   Wait();
   if (Satus()!=MT_DATA_ACK) 
    return FALSE;
    
   Start();            	       //TWI��������
   Wait();
   if (Satus()!=RE_START)  
    return FALSE;
    
   Write8Bit(RD_AT2402C_ADDR); //д AT24C02C��ַ�Ͷ���ʽ
   Wait();
   if(Satus()!=MR_SLA_ACK)  
    return FALSE;      
    
   TWI_READ();          	   //������TWI����ʽ
   Wait();
   if(Satus()!=MR_DATA_NOACK)//����һ����ֹͣ��������,�������յ����ٽ���Ӧ���ź�,����������յ�Ӧ���ź�
   							  //˵��������������������Ϊ����	 													 																		 
    return FALSE;     
    
   temp=TWDR;        		   //��ȡ TWI��������
   Stop();          		   //TWIֹͣ
   return temp;
}


