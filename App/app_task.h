#ifndef _APP_TASK_H
#define _APP_TASK_H

#include "ucos_ii.h"
#include "bsp.h"
#include "SR_04.h"



void TaskCreate(void *p_arg);
void Task1(void *p_arg);
void Task2(void *p_arg);
void TaskLedOn3(void *p_arg);


#define TaskInitPrio                        3
#define TaskLedDisPrio                             7
#define TaskLedDisPrio2                             8

#define TaskTurnPrio                             9
#define TaskLedOn3Prio                             10

#define TASK_START_STK_SIZE                    64
#define TASK1_STK_SIZE                         64
#define TASK2_STK_SIZE                         64
#define TASK3_STK_SIZE                         64

#endif


