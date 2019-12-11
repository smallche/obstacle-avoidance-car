#include "SR_04.h"
#include "delay.h"
//超声波计数
u16 msHcCount = 0;

//打开定时器4
static void OpenTimerForHc()  
{
   TIM_SetCounter(TIM4,0);
   msHcCount = 0;
   TIM_Cmd(TIM4, ENABLE); 
}

//关闭定时器4
static void CloseTimerForHc()    
{
   TIM_Cmd(TIM4, DISABLE); 
}

//定时器4终中断
void TIM4_IRQHandler(void)  
{
   if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)  
   {
       TIM_ClearITPendingBit(TIM4, TIM_IT_Update  ); 
       msHcCount++;
   }
}
 

//获取定时器4计数器值
u32 GetEchoTimer(void)
{
   u32 t = 0;
   t = msHcCount*1000;
   t += TIM_GetCounter(TIM4);
   TIM4->CNT = 0;  
   delay_ms(50);
   return t;
}
 //通过定时器4计数器值推算正前方距离
float Hcsr04GetLength_FRONT(void )
{
   u32 t = 0;
   int i = 0;
   float lengthTemp = 0;
   float sum = 0;
   while(i!=5)
   {
      FRONT_TRIG_Send = 1;      
      delay_us(20);
      FRONT_TRIG_Send = 0;
      while(FRONT_ECHO_Reci == 0);      
      OpenTimerForHc();        
      i = i + 1;
      while(FRONT_ECHO_Reci == 1);
      CloseTimerForHc();        
      t = GetEchoTimer();        
      lengthTemp = ((float)t/58.0);//cm
      sum = lengthTemp + sum ;
        
    }
    lengthTemp = sum/5.0;
    return lengthTemp;
}
//通过定时器4计数器值推算左边距离
float Hcsr04GetLength_RIGHT(void )
{
   u32 t = 0;
   int i = 0;
   float lengthTemp = 0;
   float sum = 0;
   while(i!=5)
   {
      LEFT_TRIG_Send = 1;      
      delay_us(20);
      LEFT_TRIG_Send = 0;
      while(LEFT_ECHO_Reci == 0);      
      OpenTimerForHc();        
      i = i + 1;
      while(LEFT_ECHO_Reci == 1);
      CloseTimerForHc();        
      t = GetEchoTimer();        
      lengthTemp = ((float)t/58.0);//cm
      sum = lengthTemp + sum ;
        
    }
    lengthTemp = sum/5.0;
    return lengthTemp;
}

//通过定时器4计数器值推算右边距离
float Hcsr04GetLength_LEFT(void )
{
   u32 t = 0;
   int i = 0;
   float lengthTemp = 0;
   float sum = 0;
   while(i!=5)
   {	
		 RIGHT_TRIG_Send = 1;
		 delay_us(20);
		 RIGHT_TRIG_Send = 0;
      while(RIGHT_ECHO_Reci == 0);      
      OpenTimerForHc();        
      i = i + 1;
      while(RIGHT_ECHO_Reci == 1);
      CloseTimerForHc();        
      t = GetEchoTimer();        
      lengthTemp = ((float)t/58.0);//cm
      sum = lengthTemp + sum ;
        
    }
    lengthTemp = sum/5.0;
    return lengthTemp;
}
