#include "ucos_ii.h"
#include "app_task.h"
#include "delay.h"
#include "motor.h"
void OSTick_Init(void)
{
  RCC_ClocksTypeDef RCC_ClocksStructure;
  RCC_GetClocksFreq(&RCC_ClocksStructure);  		//获取系统时钟频率
  SysTick_Config(RCC_ClocksStructure.HCLK_Frequency / OS_TICKS_PER_SEC);	 //初始化并启动SysTick和它的中断
}

int main(void)
{
	float F_length;
	void *p_null;
	OSInit();
  BSP_Initializes();                             //板子底层初始化
	OSTick_Init();                                 //初始化滴答时钟
	delay_init();
	LeftTurn_Init();
	TaskCreate(p_null);
	OSStart();
	return 0;
}
