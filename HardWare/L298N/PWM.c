/************************************PWM.c***********************************/
/* ����PB0,PB1,PA6,PA7��Ϊ��ʱ���������PWM�źţ����ļ���ʼ����ʹ����Щ���� */
/* Mulitplex PB0, PB1, PA6, PA7 as timers to output PWM signals. This file  */
/*                    initializes and enables these pins                    */
/*  				���ӿƼ���ѧǶ��ʽ����С��һ���Ȩ����                  */
/*  		  Copyright by Embedded Obstacle Avoidance Team 1, UESTC        */
/****************************************************************************/
#include "bsp.h"

void TIM2_PWM_Init(u16 arr,u16 psc)
{  
	GPIO_InitTypeDef GPIO_InitStructure;                         //����GPIO��ʼ���ṹ�� declare structure using in GPIO initialization
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;              //������ʱ����ʼ���ṹ�� declare structure using in timer initialization
	TIM_OCInitTypeDef  TIM_OCInitStructure;                      //������ʱ������Ƚϳ�ʼ���ṹ�� declare structure using in timer comparison output initialization
  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);         //ʹ�ܶ�ʱ��3 enable timer3
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);        //ʹ��GPIO����ʱ�� enable clock of GPIO peripheral
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);                                
	                                                                     	
  
  /*���ø�����Ϊ�����������,���TIM_CH2|TIM_CH3��PWM���岨�� set this pin to multiplex output function, output PWM pulse waveform of TIM_CH2 & TIM_CHI3*/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;              //����֪������������� multiplexed push-pull output
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;         //TIM3_CH3|TIM3_CH4
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;            //IO���ٶ�Ϊ50MHz set speed of IO port at 50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);                       //�����趨������ʼ��PA7 initialize PA7 according to parameter
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
  
	TIM_TimeBaseStructure.TIM_Period = arr;                      //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	set the value of auto-reload register period for the load activity of the next update event
	TIM_TimeBaseStructure.TIM_Prescaler =psc;                    //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ set the prescaler value used as the TIMx clock frequency divisor
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;                 //����ʱ�ӷָ�:TDTS = Tck_tim set clock split:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ TIM count up mode
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);              //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ initialize the time base of TIMx according to the parameters specified in TIM_TimeBaseInitStruct	
   
	 TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;            //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2 select timer mode:TIM PWM mode2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//�Ƚ����ʹ�� enable comparison output
	TIM_OCInitStructure.TIM_Pulse = 0;                           //���ô�װ�벶��ȽϼĴ���������ֵ set the pulse value to be loaded into the capture compare register
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;    //�������:TIM����Ƚϼ��Ը� Output polarity: TIM output is relatively high in polarity
	
	TIM_OC1Init(TIM3,&TIM_OCInitStructure);
	TIM_OC2Init(TIM3,&TIM_OCInitStructure);
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);                     //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIM3 initialize TIM3 according to parameter from TIM_OCInitStruct
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);  
	                          	
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);           //CH1Ԥװ��ʹ��	CH1 preload enable 
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);           //CH2Ԥװ��ʹ��	CH2 preload enable
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);           //CH3Ԥװ��ʹ��	CH3 preload enable 
	TIM_OC4PreloadConfig(TIM3, TIM_TRGOSource_Enable);         //CH4Ԥװ��ʹ�� CH4 preload enable
  
	TIM_ARRPreloadConfig(TIM3, ENABLE);                          //ʹ��TIM3��ARR�ϵ�Ԥװ�ؼĴ��� enable TIM3 preload register on ARR
	TIM_CtrlPWMOutputs(TIM3,ENABLE);                             //MOE �����ʹ�� MOE main output enable
	TIM_Cmd(TIM3, ENABLE);                                       //ʹ��TIM3 enable TIM3
	
	
}

