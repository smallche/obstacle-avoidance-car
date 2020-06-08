/************************************PWM.c***********************************/
/* 复用PB0,PB1,PA6,PA7作为定时器，来输出PWM信号，该文件初始化并使能这些引脚 */
/* Mulitplex PB0, PB1, PA6, PA7 as timers to output PWM signals. This file  */
/*                    initializes and enables these pins                    */
/*  				电子科技大学嵌入式避障小车一组版权所有                  */
/*  		  Copyright by Embedded Obstacle Avoidance Team 1, UESTC        */
/****************************************************************************/
#include "bsp.h"

void TIM2_PWM_Init(u16 arr,u16 psc)
{  
	GPIO_InitTypeDef GPIO_InitStructure;                         //声明GPIO初始化结构体 declare structure using in GPIO initialization
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;              //声明定时器初始化结构体 declare structure using in timer initialization
	TIM_OCInitTypeDef  TIM_OCInitStructure;                      //声明定时器输出比较初始化结构体 declare structure using in timer comparison output initialization
  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);         //使能定时器3 enable timer3
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);        //使能GPIO外设时钟 enable clock of GPIO peripheral
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);                                
	                                                                     	
  
  /*设置该引脚为复用输出功能,输出TIM_CH2|TIM_CH3的PWM脉冲波形 set this pin to multiplex output function, output PWM pulse waveform of TIM_CH2 & TIM_CHI3*/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;              //查表可知，复用推挽输出 multiplexed push-pull output
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;         //TIM3_CH3|TIM3_CH4
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;            //IO口速度为50MHz set speed of IO port at 50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);                       //根据设定参数初始化PA7 initialize PA7 according to parameter
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
  
	TIM_TimeBaseStructure.TIM_Period = arr;                      //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	set the value of auto-reload register period for the load activity of the next update event
	TIM_TimeBaseStructure.TIM_Prescaler =psc;                    //设置用来作为TIMx时钟频率除数的预分频值 set the prescaler value used as the TIMx clock frequency divisor
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;                 //设置时钟分割:TDTS = Tck_tim set clock split:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式 TIM count up mode
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);              //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位 initialize the time base of TIMx according to the parameters specified in TIM_TimeBaseInitStruct	
   
	 TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;            //选择定时器模式:TIM脉冲宽度调制模式2 select timer mode:TIM PWM mode2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//比较输出使能 enable comparison output
	TIM_OCInitStructure.TIM_Pulse = 0;                           //设置待装入捕获比较寄存器的脉冲值 set the pulse value to be loaded into the capture compare register
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;    //输出极性:TIM输出比较极性高 Output polarity: TIM output is relatively high in polarity
	
	TIM_OC1Init(TIM3,&TIM_OCInitStructure);
	TIM_OC2Init(TIM3,&TIM_OCInitStructure);
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);                     //根据TIM_OCInitStruct中指定的参数初始化外设TIM3 initialize TIM3 according to parameter from TIM_OCInitStruct
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);  
	                          	
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);           //CH1预装载使能	CH1 preload enable 
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);           //CH2预装载使能	CH2 preload enable
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);           //CH3预装载使能	CH3 preload enable 
	TIM_OC4PreloadConfig(TIM3, TIM_TRGOSource_Enable);         //CH4预装载使能 CH4 preload enable
  
	TIM_ARRPreloadConfig(TIM3, ENABLE);                          //使能TIM3在ARR上的预装载寄存器 enable TIM3 preload register on ARR
	TIM_CtrlPWMOutputs(TIM3,ENABLE);                             //MOE 主输出使能 MOE main output enable
	TIM_Cmd(TIM3, ENABLE);                                       //使能TIM3 enable TIM3
	
	
}

