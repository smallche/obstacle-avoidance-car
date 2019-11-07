#include "L298N.h"
#include "delay.h"
#include "motor.h"
#include "pwm.h"

void RightTurn_Init(void)//小车左转函数
{    //右轮
	   TIM_SetCompare1(TIM3,700);  	        //产生占空比，数越大越慢
		 GPIO_SetBits(GPIOA,GPIO_Pin_4);     //IN1=1
	   GPIO_ResetBits(GPIOA,GPIO_Pin_5);    //IN2=0
	   //左轮
	   TIM_SetCompare2(TIM3,700);  	        //产生占空比，数越大越慢
		 GPIO_SetBits(GPIOC,GPIO_Pin_14);     //IN3=1
	   GPIO_ResetBits(GPIOC,GPIO_Pin_13);    //IN4=0
	//右轮
	   TIM_SetCompare3(TIM3,700);  	        //产生占空比，数越大越慢
		 GPIO_SetBits(GPIOA,GPIO_Pin_11);     //IN1=1
	   GPIO_ResetBits(GPIOA,GPIO_Pin_8);    //IN2=0
	   //左轮
	   TIM_SetCompare4(TIM3,700);  	        //产生占空比，数越大越慢
		 GPIO_SetBits(GPIOA,GPIO_Pin_12);     //IN3=1
	   GPIO_ResetBits(GPIOA,GPIO_Pin_15);    //IN4=0
}
void LeftTurn_Init(void)
{    //右轮
	   TIM_SetCompare1(TIM3,700);  	        //产生占空比，数越大越慢
		 GPIO_SetBits(GPIOA,GPIO_Pin_5);     //IN1=1
	   GPIO_ResetBits(GPIOA,GPIO_Pin_4);    //IN2=0
	   //左轮
	   TIM_SetCompare2(TIM3,700);  	        //产生占空比，数越大越慢
		 GPIO_SetBits(GPIOC,GPIO_Pin_13);     //IN3=1
	   GPIO_ResetBits(GPIOC,GPIO_Pin_14);    //IN4=0
	//右轮
	   TIM_SetCompare3(TIM3,700);  	        //产生占空比，数越大越慢
		 GPIO_SetBits(GPIOA,GPIO_Pin_8);     //IN1=1
	   GPIO_ResetBits(GPIOA,GPIO_Pin_11);    //IN2=0
	   //左轮
	   TIM_SetCompare4(TIM3,700);  	        //产生占空比，数越大越慢
		 GPIO_SetBits(GPIOA,GPIO_Pin_15);     //IN3=1
	   GPIO_ResetBits(GPIOA,GPIO_Pin_12);    //IN4=0
}

void qianjin_Init(void)//小车前进函数
{    //右轮
	   TIM_SetCompare1(TIM3,700);  	        //产生占空比，数越大越慢
		 GPIO_SetBits(GPIOA,GPIO_Pin_4);     //IN1=1
	   GPIO_ResetBits(GPIOA,GPIO_Pin_5);    //IN2=0
	   //左轮
	   TIM_SetCompare2(TIM3,700);  	        //产生占空比，数越大越慢
		 GPIO_SetBits(GPIOC,GPIO_Pin_13);     //IN3=1
	   GPIO_ResetBits(GPIOC,GPIO_Pin_14);    //IN4=0
	//右轮
	   TIM_SetCompare3(TIM3,700);  	        //产生占空比，数越大越慢
		 GPIO_SetBits(GPIOA,GPIO_Pin_11);     //IN1=1
	   GPIO_ResetBits(GPIOA,GPIO_Pin_8);    //IN2=0
	   //左轮
	   TIM_SetCompare4(TIM3,700);  	        //产生占空比，数越大越慢
		 GPIO_SetBits(GPIOA,GPIO_Pin_15);     //IN3=1
	   GPIO_ResetBits(GPIOA,GPIO_Pin_12);    //IN4=0
}
