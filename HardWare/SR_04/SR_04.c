/************************************SR_04.c*******************************/
/*          初始化超声波模块，通过超声波模块获取和障碍物之间的距离        */
/*				  距离需要通过公式计算而来:S=(TIME*1.7)/100               */
/*                     Initialize SR04 ultrasonic module,                 */
/*					and obtain distance from obstacle by it               */
/*  				电子科技大学嵌入式避障小车一组版权所有                */
/*  		  Copyright by Embedded Obstacle Avoidance Team 1, UESTC      */
/**************************************************************************/
#include "SR_04.h"
#include "delay.h"
//超声波计数 ultrasonic counter
u16 msHcCount = 0;

//打开定时器4 turn on the timer4
static void OpenTimerForHc()  
{
   TIM_SetCounter(TIM4,0);
   msHcCount = 0;
   TIM_Cmd(TIM4, ENABLE); 
}

//关闭定时器4 turn off the timer4
static void CloseTimerForHc()    
{
   TIM_Cmd(TIM4, DISABLE); 
}

//定时器4中断处理 interrupt handler of timer 4
void TIM4_IRQHandler(void)  
{
   if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)  
   {
       TIM_ClearITPendingBit(TIM4, TIM_IT_Update  ); 
       msHcCount++;
   }
}
 

//获取定时器4计数器值 get the count value of the timer4
u32 GetEchoTimer(void)
{
   u32 t = 0;
   t = msHcCount*1000;
   t += TIM_GetCounter(TIM4);
   TIM4->CNT = 0;  
   delay_ms(50);
   return t;
}
 //通过定时器4计数器值推算正前方距离 use the timer4 value to estimate the distance from obstacle ahead
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
//通过定时器4计数器值推算左边距离 use the timer4 value to estimate the distance from obstacle left
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

//通过定时器4计数器值推算右边距离 use the timer4 value to estimate the distance from obstacle right
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
