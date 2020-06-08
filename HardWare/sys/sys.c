/************************************sys.c*********************************/
/*              配置内嵌重点向量控制器以保证中断正常执行                  */
/*			 Configure Nested Vectored Interrupt Controller               */
/*				to enable normal execution of interrupts	  			  */
/**************************************************************************/
#include "sys.h"

void NVIC_Configuration(void)
{

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//设置NVIC中断分组2:2位抢占优先级，2位响应优先级

}
