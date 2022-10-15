#include "stm32f10x.h""

#define CLKENR  *((volatile unsigned int *)0x40021018)

//----------------GPIOA�Ĵ�����ַ -----------------------
#define GPIO_A		*((unsigned volatile int*)0x40010800)
//----------------GPIOB�Ĵ�����ַ -----------------------
#define GPIO_B    	*((unsigned volatile int*)0x40010C00)
//----------------GPIOC�Ĵ�����ַ -----------------------
#define GPIO_C		*((unsigned volatile int*)0x40011004)

//----------------GPIOA���üĴ��� -----------------------
#define GPIOA_CRL		*((unsigned volatile int*)0x40010800)
#define	LED1		*((unsigned volatile int*)0x4001080C)
//----------------GPIOB���üĴ��� -----------------------
#define GPIOB_CRH		*((unsigned volatile int*)0x40010C04)
#define	LED2		*((unsigned volatile int*)0x40010C0C)
//----------------GPIOC���üĴ��� -----------------------
#define GPIOC_CRH		*((unsigned volatile int*)0x40011004)
#define	LED3		*((unsigned volatile int*)0x4001100C)

 void Delay()
 {
   u32 i=0;
   for(;i<10000;i++);
 }
 int main()
 {
		CLKENR|=1<<2|1<<3|1<<4;	  //APB2-GPIOA��GPIOB��GPIOC����ʱ��ʹ��
	 
		GPIOA_CRL&=0xFF0FFFFF;		//����λ ����	
		GPIOA_CRL|=0x00200000;		//PA5����������ѵ�23��22��21��20��Ϊ0010
		LED1&=(0<<4);			//���ó�ʼ��Ϊ��

	 
		GPIOB_CRH&=0xFFFFFF0F;		//����λ ����	
		GPIOB_CRH|=0x00000020;		//PB9����������ѵ�7��6��5��4��Ϊ0010
		LED2&=(0<<5);			//���ó�ʼ��Ϊ��
	 
	 
		GPIOC_CRH&=0xF0FFFFFF;		//����λ ����	
		GPIOC_CRH|=0x02000000;		//PC14����������ѵ�27��26��25��24��Ϊ0010
		LED3&=(0<<14);			//���ó�ʼ��Ϊ��
	 
    while(1)
    {
    	//LED1
			LED1|=1<<5;		//PB5�ߵ�ƽ
			Delay();
			LED1&=(0<<5);		//PB5�͵�ƽ,��Ϊ����0�������ð�λ��
			
			//LED2
			LED2|=1<<9;		//PB9�ߵ�ƽ
			Delay();
			LED2&=(0<<9);		//PB5�͵�ƽ,��Ϊ����0�������ð�λ��
			
			//LED3
			LED3|=1<<14;		//PB14�ߵ�ƽ
			Delay();
			LED3&=(0<<14);		//PB5�͵�ƽ,��Ϊ����0�������ð�λ��
				
    }
    
 }