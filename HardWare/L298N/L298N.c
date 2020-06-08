/************************************L298N.c*********************************/
/*              ��ʼ������L298N�������ģ����Ҫʹ�õĲ�������               */
/*              ע�⣺�ĸ���ΪPWM�������������PWM.c�г�ʼ��                */
/*            Initialize some pins of L298N motor drive module.             */
/*     Note: The four pins as PWM outputs have been initialized in PWM.c    */
/*  				���ӿƼ���ѧǶ��ʽ����С��һ���Ȩ����                  */
/*  		  Copyright by Embedded Obstacle Avoidance Team 1, UESTC        */
/****************************************************************************/
#include "L298N.h"

void L298N_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;                 //����GPIO��ʼ���ṹ�� declare the structure using in GPIO initialization
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE); //ʹ��APB2ʱ��������PA�˿�ʱ��	enable the PA port clock under the APB2 clock bus
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);	                  

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_12; //PA12��PA12�˿����� configure PA12 and its port
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //������� push-pull output
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz set speed of IO port at 50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);					       //�����趨������ʼ��PA11|PA12 initialize PA11 and PA12 according parameter
	GPIO_SetBits(GPIOA,GPIO_Pin_8|GPIO_Pin_12);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11|GPIO_Pin_15;//PA3�˿����� configure PA3 port
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //������� push-pull output
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz set speed of IO port at 50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);					       //�����趨������ʼ��PA3|PA4 initialize PA3 and PA4 according parameter
	GPIO_ResetBits(GPIOA,GPIO_Pin_11|GPIO_Pin_15);

}
