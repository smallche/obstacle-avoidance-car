/************************************L298N.c*********************************/
/*              初始化两个L298N电机驱动模块所要使用的部分引脚               */
/*              注意：四个作为PWM输出的引脚已在PWM.c中初始化                */
/*            Initialize some pins of L298N motor drive module.             */
/*     Note: The four pins as PWM outputs have been initialized in PWM.c    */
/*  				电子科技大学嵌入式避障小车一组版权所有                  */
/*  		  Copyright by Embedded Obstacle Avoidance Team 1, UESTC        */
/****************************************************************************/
#include "L298N.h"

void L298N_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;                 //声明GPIO初始化结构体 declare the structure using in GPIO initialization
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE); //使能APB2时钟总线下PA端口时钟	enable the PA port clock under the APB2 clock bus
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);	                  

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_12; //PA12和PA12端口配置 configure PA12 and its port
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出 push-pull output
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz set speed of IO port at 50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);					       //根据设定参数初始化PA11|PA12 initialize PA11 and PA12 according parameter
	GPIO_SetBits(GPIOA,GPIO_Pin_8|GPIO_Pin_12);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11|GPIO_Pin_15;//PA3端口配置 configure PA3 port
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出 push-pull output
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz set speed of IO port at 50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);					       //根据设定参数初始化PA3|PA4 initialize PA3 and PA4 according parameter
	GPIO_ResetBits(GPIOA,GPIO_Pin_11|GPIO_Pin_15);

}
