/************************************sys.c*********************************/
/*              ������Ƕ�ص������������Ա�֤�ж�����ִ��                  */
/*			 Configure Nested Vectored Interrupt Controller               */
/*				to enable normal execution of interrupts	  			  */
/**************************************************************************/
#include "sys.h"

void NVIC_Configuration(void)
{

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�

}
