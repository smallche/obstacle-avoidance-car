//异常处理
#include "stm32f10x_it.h"
#include "ucos_ii.h"


//处理NMI异常
void NMI_Handler(void)
{
}

//处理HardFault异常
void HardFault_Handler(void)
{
  while (1)
  {
  }
}

//内存管理异常
void MemManage_Handler(void)
{
  while (1)
  {
  }
}

//处理总线异常
void BusFault_Handler(void)
{
  while (1)
  {
  }
}

//处理使用错误
void UsageFault_Handler(void)
{
  while (1)
  {
  }
}


void SVC_Handler(void)
{
}


void DebugMon_Handler(void)
{
}


void SysTick_Handler(void)
{
  OSIntEnter();
  OSTimeTick();
  OSIntExit();
}
