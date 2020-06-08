/************************************motor.c***********************************/
/* ÿ������������������ſ��ƣ�ͨ�����ĸ�������ָ������ת�����ﵽǰ�������˺� */
/*                                 ת���Ч��                                 */
/*   Each wheel is controlled by two output pins. By turning the four wheels  */
/*    in the specified direction, the forward, backward and turning effects   */
/*                                  are achieved.                             */ 
/*  				���ӿƼ���ѧǶ��ʽ����С��һ���Ȩ����                    */
/*  		  Copyright by Embedded Obstacle Avoidance Team 1, UESTC          */
/******************************************************************************/
#include "L298N.h"
#include "delay.h"
#include "motor.h"
#include "pwm.h"

void LeftTurn_Init(void)//С����ת���� function of letting vehicle turn left
{    //����
	TIM_SetCompare1(TIM3,500);  	        //����ռ�ձȣ���Խ��Խ�� generate duty cycle
	 GPIO_SetBits(GPIOA,GPIO_Pin_4);     //IN1=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);    //IN2=0
	//����
	TIM_SetCompare2(TIM3,500);  	        
	 GPIO_SetBits(GPIOC,GPIO_Pin_13);     //IN3=1
	GPIO_ResetBits(GPIOC,GPIO_Pin_14);    //IN4=0
	//����
	TIM_SetCompare3(TIM3,500);  	        
	 GPIO_SetBits(GPIOA,GPIO_Pin_11);     //IN1=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_8);    //IN2=0
	//����
	TIM_SetCompare4(TIM3,500);  	        
	 GPIO_SetBits(GPIOA,GPIO_Pin_15);     //IN3=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);    //IN4=0
}
void RightTurn_Init(void)//С��ǰ������
{    //����
	TIM_SetCompare1(TIM3,500);  	        //����ռ�ձȣ���Խ��Խ�� generate duty cycle
	 GPIO_SetBits(GPIOA,GPIO_Pin_5);     //IN1=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);    //IN2=0
	//����
	TIM_SetCompare2(TIM3,500);  	        
	 GPIO_SetBits(GPIOC,GPIO_Pin_14);     //IN3=1
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);    //IN4=0
	//����
	TIM_SetCompare3(TIM3,500);  	        
	 GPIO_SetBits(GPIOA,GPIO_Pin_8);     //IN1=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_11);    //IN2=0
	//����
	TIM_SetCompare4(TIM3,500);  	        
	 GPIO_SetBits(GPIOA,GPIO_Pin_12);     //IN3=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_15);    //IN4=0
}

void qianjin_Init(void){   
	//����
	TIM_SetCompare1(TIM3,660);  	        //����ռ�ձȣ���Խ��Խ�� generate duty cycle
	 GPIO_SetBits(GPIOA,GPIO_Pin_4);     //IN1=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);    //IN2=0
	//����
	TIM_SetCompare2(TIM3,690);
	 GPIO_SetBits(GPIOC,GPIO_Pin_14);     //IN3=1                                                               
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);    //IN4=0
	//����
	TIM_SetCompare3(TIM3,690);
	 GPIO_SetBits(GPIOA,GPIO_Pin_11);     //IN1=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_8);    //IN2=0
	//����
	TIM_SetCompare4(TIM3,660);
	 GPIO_SetBits(GPIOA,GPIO_Pin_12);     //IN3=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_15);    //IN4=0
}

void RollBack_Init(){
	TIM_SetCompare1(TIM3,400);					//����ռ�ձȣ���Խ��Խ�� generate duty cycle
	GPIO_SetBits(GPIOA,GPIO_Pin_5);     //IN1=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);    //IN2=0
	//����
	TIM_SetCompare2(TIM3,400);
	GPIO_SetBits(GPIOC,GPIO_Pin_13);     //IN3=1                                                               
	GPIO_ResetBits(GPIOC,GPIO_Pin_14);    //IN4=0
	//����
	TIM_SetCompare3(TIM3,400);
	GPIO_SetBits(GPIOA,GPIO_Pin_8);     //IN1=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_11);    //IN2=0
	//����
	TIM_SetCompare4(TIM3,400);
	GPIO_SetBits(GPIOA,GPIO_Pin_15);     //IN3=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);    //IN4=0
}

void Rotate_Init(void){
	TIM_SetCompare1(TIM3,600);  	        //����ռ�ձȣ���Խ��Խ��
	 GPIO_SetBits(GPIOA,GPIO_Pin_4);     //IN1=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);    //IN2=0
	//����
	TIM_SetCompare2(TIM3,600);  	        //����ռ�ձȣ���Խ��Խ��
	 GPIO_SetBits(GPIOC,GPIO_Pin_13);     //IN3=1                                                               
	GPIO_ResetBits(GPIOC,GPIO_Pin_14);    //IN4=0
	//����
	TIM_SetCompare3(TIM3,600);  	        //����ռ�ձȣ���Խ��Խ��
	 GPIO_SetBits(GPIOA,GPIO_Pin_8);     //IN1=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_11);    //IN2=0
	//����
	TIM_SetCompare4(TIM3,600);  	        //����ռ�ձȣ���Խ��Խ��
	 GPIO_SetBits(GPIOA,GPIO_Pin_12);     //IN3=1
	GPIO_ResetBits(GPIOA,GPIO_Pin_15);    //IN4=0
}
