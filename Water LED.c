#include "stm32f10x.h""

#define CLKENR  *((volatile unsigned int *)0x40021018)

//----------------GPIOA寄存器地址 -----------------------
#define GPIO_A		*((unsigned volatile int*)0x40010800)
//----------------GPIOB寄存器地址 -----------------------
#define GPIO_B    	*((unsigned volatile int*)0x40010C00)
//----------------GPIOC寄存器地址 -----------------------
#define GPIO_C		*((unsigned volatile int*)0x40011004)

//----------------GPIOA配置寄存器 -----------------------
#define GPIOA_CRL		*((unsigned volatile int*)0x40010800)
#define	LED1		*((unsigned volatile int*)0x4001080C)
//----------------GPIOB配置寄存器 -----------------------
#define GPIOB_CRH		*((unsigned volatile int*)0x40010C04)
#define	LED2		*((unsigned volatile int*)0x40010C0C)
//----------------GPIOC配置寄存器 -----------------------
#define GPIOC_CRH		*((unsigned volatile int*)0x40011004)
#define	LED3		*((unsigned volatile int*)0x4001100C)

 void Delay()
 {
   u32 i=0;
   for(;i<10000;i++);
 }
 int main()
 {
		CLKENR|=1<<2|1<<3|1<<4;	  //APB2-GPIOA、GPIOB、GPIOC外设时钟使能
	 
		GPIOA_CRL&=0xFF0FFFFF;		//设置位 清零	
		GPIOA_CRL|=0x00200000;		//PA5推挽输出，把第23、22、21、20变为0010
		LED1&=(0<<4);			//设置初始灯为灭

	 
		GPIOB_CRH&=0xFFFFFF0F;		//设置位 清零	
		GPIOB_CRH|=0x00000020;		//PB9推挽输出，把第7、6、5、4变为0010
		LED2&=(0<<5);			//设置初始灯为灭
	 
	 
		GPIOC_CRH&=0xF0FFFFFF;		//设置位 清零	
		GPIOC_CRH|=0x02000000;		//PC14推挽输出，把第27、26、25、24变为0010
		LED3&=(0<<14);			//设置初始灯为灭
	 
    while(1)
    {
    	//LED1
			LED1|=1<<5;		//PB5高电平
			Delay();
			LED1&=(0<<5);		//PB5低电平,因为是置0，所以用按位与
			
			//LED2
			LED2|=1<<9;		//PB9高电平
			Delay();
			LED2&=(0<<9);		//PB5低电平,因为是置0，所以用按位与
			
			//LED3
			LED3|=1<<14;		//PB14高电平
			Delay();
			LED3&=(0<<14);		//PB5低电平,因为是置0，所以用按位与
				
    }
    
 }