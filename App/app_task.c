
#include "ucos_ii.h"
#include "app_task.h"
#include "bsp.h"
#include "motor.h"
#include "delay.h"



#define S 40//危险距离
#define FrontDanger 80

//三个任务的堆栈
OS_STK Task1_Stk[TASK1_STK_SIZE];
OS_STK Task2_Stk[TASK2_STK_SIZE];
OS_STK Task3_Stk[TASK3_STK_SIZE];


void TaskLedOn1(void *p_arg)
{
		volatile float a0=0;

float a1=0;
	float b0=0;
	float b1=0;
	float c0=0;
	float c1=0;
	float *F_length;
	float *L_length;
	float *R_length;
 
	F_length = (float *)0x20000200;
	L_length = (float *)0x20000204;
	R_length = (float *)0x20000208;
	
	
  while(1){
			*F_length = Hcsr04GetLength_FRONT();
		  printf("Front:%.2f\n",*F_length);
		  *L_length = Hcsr04GetLength_LEFT();
	    printf("Left:%.2f\n",*L_length);
		  *R_length = Hcsr04GetLength_RIGHT();
			printf("Right:%.2f\n",*R_length);
      
			
		
    a1=*F_length;
      b1=*L_length;
     c1=*R_length;
   
	        
//	    if(b0>b1){
//				printf("2_R\n");
//				RightTurn_Init();
//			}
//			if(c0>c1){
//				printf("2_L\n");
//				LeftTurn_Init();
//			}
			
			//qianjin_Init();
			
			a0=a1;
			b0=b1;
			c0=c1;
			
			
			
		}


	}

	void TaskLedOn2(void *p_arg)
{
		volatile float a0=0;

float a1=0;
	float b0=0;
	float b1=0;
	float c0=0;
	float c1=0;
		float *F_length;
	float *L_length;
	float *R_length;
		F_length = (float *)0x20000200;
	L_length = (float *)0x20000204;
	R_length = (float *)0x20000208;
	
	
	while(1){
    a1=*F_length;
      b1=*L_length;
     c1=*R_length;
			if((a1 <= FrontDanger && b1 <= S && c1 <= S)){
				RollBack_Init();
				printf("1_Roll\n");
				delay_ms(500);
				printf("1_Rotate\n");
				Rotate_Init();
			}else if(a1 <= FrontDanger && b1 > 2*S && c1 > 2*S){
				printf("2_Roll\n");
				RollBack_Init();
				delay_ms(500);
				printf("2_Rotate\n");
				Rotate_Init();
				delay_ms(500);
				//delay_ms(100);
			}
      else if((a1<= FrontDanger&&b1<c1) || (b1<S)){
				printf("1_R\n");
          RightTurn_Init();		
      }else if((a1<=FrontDanger&&b1>c1) || (c1<S)){
				printf("1_L\n");
		      LeftTurn_Init();
	    }
			else{
				printf("1_Q\n");
				qianjin_Init();
			}
	        
//	    if(b0>b1){
//				printf("2_R\n");
//				RightTurn_Init();
//			}
//			if(c0>c1){
//				printf("2_L\n");
//				LeftTurn_Init();
//			}
			
			//qianjin_Init();
			
			a0=a1;
			b0=b1;
			c0=c1;
			
			
			

		}

	}

void TaskCreate(void *p_arg){
  OSTaskCreate((void (*)(void *)) TaskLedOn1,//函数指针
              (void           *) 0,//参数
              (OS_STK         *)&Task1_Stk[TASK1_STK_SIZE-1],//堆栈栈顶指针
              (INT8U           ) TaskLedDisPrio//优先级
              );
							  OSTaskCreate((void (*)(void *)) TaskLedOn2,//函数指针
              (void           *) 0,//参数
              (OS_STK         *)&Task2_Stk[TASK2_STK_SIZE-1],//堆栈栈顶指针
              (INT8U           ) TaskLedDisPrio2//优先级
              );
				
}
