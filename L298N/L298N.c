#include "L298N.h"

void L298N_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;                 //声明GPIO初始化结构体
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE); //使能APB2时钟总线下PA端口时钟	
 GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);	                  
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_12; //PA12和PA12端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					       //根据设定参数初始化PA11|PA12
 GPIO_SetBits(GPIOA,GPIO_Pin_8|GPIO_Pin_12);
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11|GPIO_Pin_15;//PA3端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					       //根据设定参数初始化PA3|PA4
 GPIO_ResetBits(GPIOA,GPIO_Pin_11|GPIO_Pin_15);

}
