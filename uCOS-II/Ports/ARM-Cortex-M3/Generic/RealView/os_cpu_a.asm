

    EXTERN  OSRunning                                           ; 外部引用
    EXTERN  OSPrioCur
    EXTERN  OSPrioHighRdy
    EXTERN  OSTCBCur
    EXTERN  OSTCBHighRdy
    EXTERN  OSIntExit
    EXTERN  OSTaskSwHook
	EXTERN  OS_CPU_ExceptStkBase


    EXPORT  OS_CPU_SR_Save                                      
    EXPORT  OS_CPU_SR_Restore
    EXPORT  OSStartHighRdy
    EXPORT  OSCtxSw
    EXPORT  OSIntCtxSw
    EXPORT  PendSV_Handler


NVIC_INT_CTRL   EQU     0xE000ED04                              ; 中断控制状态寄存器
NVIC_SYSPRI14   EQU     0xE000ED22                              ; 优先级寄存器
NVIC_PENDSV_PRI EQU           0xFF                              ; PendSV异常的优先级
NVIC_PENDSVSET  EQU     0x10000000                              ; 触发PendSV异常的值


    AREA |.text|, CODE, READONLY, ALIGN=2
    THUMB
    REQUIRE8
    PRESERVE8


OS_CPU_SR_Save
    MRS     R0, PRIMASK                                         
    CPSID   I
    BX      LR

OS_CPU_SR_Restore
    MSR     PRIMASK, R0
    BX      LR


;开始优先级最高的任务
OSStartHighRdy
    LDR     R0, =NVIC_SYSPRI14                                  ;存储PendSV异常的优先级
    LDR     R1, =NVIC_PENDSV_PRI
    STRB    R1, [R0]

    MOVS    R0, #0                                              ; 初始化上下文切换调用
    MSR     PSP, R0

    LDR     R0, =OS_CPU_ExceptStkBase                           
    LDR     R1, [R0]
    MSR     MSP, R1    

    LDR     R0, =OSRunning                                      ; OSRunning = TRUE
    MOVS    R1, #1
    STRB    R1, [R0]

    LDR     R0, =NVIC_INT_CTRL                                  ; 触发PendSV异常（上下文切换）
    LDR     R1, =NVIC_PENDSVSET
    STR     R1, [R0]

    CPSIE   I                                                   ; 打开中断

OSStartHang
    B       OSStartHang                                         
	

OSCtxSw
    LDR     R0, =NVIC_INT_CTRL                                  ; 触发PendSV异常
    LDR     R1, =NVIC_PENDSVSET
    STR     R1, [R0]
    BX      LR



OSIntCtxSw
    LDR     R0, =NVIC_INT_CTRL                                  ; 触发PendSV异常
    LDR     R1, =NVIC_PENDSVSET
    STR     R1, [R0]
    BX      LR

;处理PendSV异常
PendSV_Handler
    CPSID   I                                                   ; 上下文切换时不允许中断
    MRS     R0, PSP                                             
    CBZ     R0, OS_CPU_PendSVHandler_nosave                     

    SUBS    R0, R0, #0x20                                       ; R4-R11进栈
    STM     R0, {R4-R11}

    LDR     R1, =OSTCBCur                                       ; 指向新的栈顶
    LDR     R1, [R1]
    STR     R0, [R1]                                            

                                                                
OS_CPU_PendSVHandler_nosave
    PUSH    {R14}                                               ; LR进栈
    LDR     R0, =OSTaskSwHook                                   
    BLX     R0
    POP     {R14}

    LDR     R0, =OSPrioCur                                      ; OSPrioCur = OSPrioHighRdy;
    LDR     R1, =OSPrioHighRdy
    LDRB    R2, [R1]
    STRB    R2, [R0]

    LDR     R0, =OSTCBCur                                       ; OSTCBCur  = OSTCBHighRdy;
    LDR     R1, =OSTCBHighRdy
    LDR     R2, [R1]
    STR     R2, [R0]

    LDR     R0, [R2]                                            
    LDM     R0, {R4-R11}                                        ; 恢复R4-R11
    ADDS    R0, R0, #0x20
    MSR     PSP, R0                                             
    ORR     LR, LR, #0x04                                       
    CPSIE   I
    BX      LR                                                 

    END
