/****************************************************************************/
/*                                  主函数                                  */
/*                              main function                               */
/*  				电子科技大学嵌入式避障小车一组版权所有                  */
/*  		  Copyright by Embedded Obstacle Avoidance Team 1, UESTC        */
/****************************************************************************/
#include "ucos_ii.h"
#include "app_task.h"
#include "delay.h"
#include "motor.h"
void OSTick_Init(void)
{
	RCC_ClocksTypeDef RCC_ClocksStructure;
	RCC_GetClocksFreq(&RCC_ClocksStructure);  		//获取系统时钟频率 get system clock frequency
	SysTick_Config(RCC_ClocksStructure.HCLK_Frequency / OS_TICKS_PER_SEC);	 //初始化并启动SysTick和它的中断 initialize and boot systic and its interrupt
}

int main(void)
{
	void *p_null;
	OSInit();
	BSP_Initializes();                             
	OSTick_Init();                                 
	delay_init();
	qianjin_Init();
	TaskCreate(p_null);
	OSStart();
	return 0;
}
