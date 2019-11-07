#include "sys.h"
#include "usart.h"


#ifndef _SR04_H
#define _SR04_H

#define HCSR04_PORT     GPIOB
#define HCSR04_CLK      RCC_APB2Periph_GPIOB
#define FRONT_HCSR04_TRIG     GPIO_Pin_11
#define FRONT_HCSR04_ECHO     GPIO_Pin_10
#define LEFT_HCSR04_TRIG     GPIO_Pin_13
#define LEFT_HCSR04_ECHO     GPIO_Pin_12
#define RIGHT_HCSR04_TRIG     GPIO_Pin_15
#define RIGHT_HCSR04_ECHO     GPIO_Pin_14

#define FRONT_TRIG_Send  PBout(11)
#define FRONT_ECHO_Reci  PBin(10)
#define LEFT_TRIG_Send  PBout(13)
#define LEFT_ECHO_Reci  PBin(12)
#define RIGHT_TRIG_Send  PBout(15)
#define RIGHT_ECHO_Reci  PBin(14)

static void OpenTimerForHc(void);
static void CloseTimerForHc(void);
void TIM4_IRQHandler(void);
u32 GetEchoTimer(void);
float Hcsr04GetLength_FRONT(void );
float Hcsr04GetLength_LEFT(void );
float Hcsr04GetLength_RIGHT(void );
#endif
