#include "bsp.h"





void RCC_Configuration(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA  | RCC_APB2Periph_GPIOB  | 
                         RCC_APB2Periph_GPIOC  | RCC_APB2Periph_GPIOD  | 
                         RCC_APB2Periph_GPIOE  | RCC_APB2Periph_GPIOF  | 
                         RCC_APB2Periph_AFIO, ENABLE);							//使能APB2时钟
}

void GPIO_Basic_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_1 | GPIO_Pin_0 | GPIO_Pin_2 | GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;                  //频率(50M)
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;                   //输出类型(推挽式输出)
  GPIO_Init(GPIOA, &GPIO_InitStructure);
}


//定时器4设置
void hcsr04_NVIC()
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
			
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;             
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;         
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;       
	NVIC_Init(&NVIC_InitStructure);
}

//IO口初始化 及其他初始化
void Hcsr04Init()
{  
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;   
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(HCSR04_CLK, ENABLE);
   
    GPIO_InitStructure.GPIO_Pin =FRONT_HCSR04_TRIG | LEFT_HCSR04_TRIG|RIGHT_HCSR04_TRIG;      
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(HCSR04_PORT, &GPIO_InitStructure);
    GPIO_ResetBits(HCSR04_PORT,FRONT_HCSR04_TRIG | LEFT_HCSR04_TRIG|RIGHT_HCSR04_TRIG);
 
	
	
	  GPIO_InitStructure.GPIO_Pin =   FRONT_HCSR04_ECHO|LEFT_HCSR04_ECHO|RIGHT_HCSR04_ECHO;     
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(HCSR04_PORT, &GPIO_InitStructure);  
    GPIO_ResetBits(HCSR04_PORT,FRONT_HCSR04_ECHO|LEFT_HCSR04_ECHO|RIGHT_HCSR04_ECHO);

          
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);   
     
    TIM_DeInit(TIM2);
    TIM_TimeBaseStructure.TIM_Period = (1000-1); 
    TIM_TimeBaseStructure.TIM_Prescaler =(72-1); 
    TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);          
        
    TIM_ClearFlag(TIM4, TIM_FLAG_Update);  
    TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE);    
    hcsr04_NVIC();
    TIM_Cmd(TIM4,DISABLE);     
}


void L298N1_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;                 //声明GPIO初始化结构体
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE); //使能APB2时钟总线下PA端口时钟	
 GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);	                  
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_12; //PA12和PA12端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					       //根据设定参数初始化PA11|PA12
 //GPIO_SetBits(GPIOA,GPIO_Pin_12|GPIO_Pin_11);
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11|GPIO_Pin_15;//PA3端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					       //根据设定参数初始化PA3|PA4
 //GPIO_ResetBits(GPIOA,GPIO_Pin_8|GPIO_Pin_15);

}

void L298N2_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;                 //声明GPIO初始化结构体

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_6; //PA12和PA12端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					       //根据设定参数初始化PA11|PA12
 //GPIO_SetBits(GPIOA,GPIO_Pin_4);
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_7;//PA3端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					       //根据设定参数初始化PA3|PA4
 //GPIO_ResetBits(GPIOA,GPIO_Pin_5);                            

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;//PA3端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOC, &GPIO_InitStructure);					       //根据设定参数初始化PA3|PA4
 //GPIO_SetBits(GPIOC,GPIO_Pin_14);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;//PA3端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOC, &GPIO_InitStructure);					       //根据设定参数初始化PA3|PA4
 //GPIO_Rese336tBits(GPIOC,GPIO_Pin_13);
}

void BSP_Initializes(void)
{
	
  RCC_Configuration();                                               //时钟配置
  GPIO_Basic_Configuration();                                        //IO配置

	NVIC_Configuration(); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(9600);	 	//串口初始化为9600
	Hcsr04Init();
	L298N1_Init();
	L298N2_Init();
	TIM2_PWM_Init(899, 0);
}
