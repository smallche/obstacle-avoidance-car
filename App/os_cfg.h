
#ifndef OS_CFG_H
#define OS_CFG_H


                                       
#define OS_APP_HOOKS_EN           0u   // 使能APP应用HOOK函数                                         
#define OS_ARG_CHK_EN             0u   // 参数检查                                                    
#define OS_CPU_HOOKS_EN           1u   // 使能OS_CPU HOOK函数                                        

#define OS_DEBUG_EN               0u   // 使能系统调试功能                                           
#define OS_EVENT_MULTI_EN         0u   // 使用OSEventPendMulti()函数                                  
#define OS_EVENT_NAME_EN          0u   // 使能事件(Sem, Mutex, Mbox and Q)名称                       

#define OS_LOWEST_PRIO           63u   // 定义最低优先级                                   
                                       

#define OS_MAX_EVENTS             5u   // 事件控制块的最大数(应用程序中)                               
#define OS_MAX_FLAGS              5u   // 事件标志组的最大数(应用程序中)                              
#define OS_MAX_MEM_PART           5u   // 内存分区最大数                                              
#define OS_MAX_QS                 5u   // 队列控制块的最大数(应用程序中)                              
#define OS_MAX_TASKS             10u   // 应用程序（任务）的最大数                                    

#define OS_SCHED_LOCK_EN          0u   // 使用OSSchedLock() 和 OSSchedUnlock()函数                    

#define OS_TICK_STEP_EN           0u   // 使能tick stepping                                            
#define OS_TICKS_PER_SEC        100u   //每秒滴答数                                                 

#define OS_TLS_TBL_SIZE           0u   // 线程本地存储表(Thread-Local Storage Table)大小            


                                       
#define OS_TASK_TMR_STK_SIZE    128u   // 定时器任务堆栈大小              
#define OS_TASK_STAT_STK_SIZE   128u   // 统计任务堆栈大小              
#define OS_TASK_IDLE_STK_SIZE   128u   // 空闲任务堆栈大小                 


                                       
#define OS_TASK_CHANGE_PRIO_EN    1u   // 任务优先级切换   
#define OS_TASK_CREATE_EN         1u   // 创建任务           
#define OS_TASK_CREATE_EXT_EN     1u   // 创建扩展版本任务     
#define OS_TASK_DEL_EN            1u   // 删除任务             
#define OS_TASK_NAME_EN           1u   // Get,Set任务名称      
#define OS_TASK_PROFILE_EN        0u   // 包含OS_TCB性能分析                                          
#define OS_TASK_QUERY_EN          1u   // 查询任务(信息)       
#define OS_TASK_REG_TBL_SIZE      0u   // 任务数组变量的大小                 
#define OS_TASK_STAT_EN           0u   // 使能统计任务                                               
#define OS_TASK_STAT_STK_CHK_EN   0u   // 使能检查任务堆栈                                            
#define OS_TASK_SUSPEND_EN        1u   // 任务挂起、继续      
#define OS_TASK_SW_HOOK_EN        1u   //  任务切换HOOK函数


                                       
#define OS_FLAG_EN                0u   // 使能OS_FLAG事件标志所有功能                                
#define OS_FLAG_ACCEPT_EN         0u   //  检查(获取)事件状态 
#define OS_FLAG_DEL_EN            0u   // 删除事件            
#define OS_FLAG_NAME_EN           0u   // 使用事件标志名称
#define OS_FLAG_QUERY_EN          0u   // 查询事件             
#define OS_FLAG_WAIT_CLR_EN       0u   // 使能事件等待清除功能
#define OS_FLAGS_NBITS           16u   // 定义OS_FLAGS数据类类型


                                       
#define OS_MBOX_EN                0u   
#define OS_MBOX_ACCEPT_EN         0u  
#define OS_MBOX_DEL_EN            0u   
#define OS_MBOX_PEND_ABORT_EN     0u   
#define OS_MBOX_POST_EN           0u   
#define OS_MBOX_POST_OPT_EN       0u   
#define OS_MBOX_QUERY_EN          0u  


                                       // 内存管管理
#define OS_MEM_EN                 0u
#define OS_MEM_NAME_EN            0u
#define OS_MEM_QUERY_EN           0u


                                       // 互斥信号量
#define OS_MUTEX_EN               0u  
#define OS_MUTEX_ACCEPT_EN        0u
#define OS_MUTEX_DEL_EN           0u
#define OS_MUTEX_QUERY_EN         0u


                                       //消息队列
#define OS_Q_EN                   0u   
#define OS_Q_ACCEPT_EN            0u   
#define OS_Q_DEL_EN               0u   
#define OS_Q_FLUSH_EN             0u   
#define OS_Q_PEND_ABORT_EN        0u   
#define OS_Q_POST_EN              0u  
#define OS_Q_POST_FRONT_EN        0u 
#define OS_Q_POST_OPT_EN          0u  
#define OS_Q_QUERY_EN             0u 


                                       // 信号量
#define OS_SEM_EN                 0u   
#define OS_SEM_ACCEPT_EN          0u   
#define OS_SEM_DEL_EN             0u   
#define OS_SEM_PEND_ABORT_EN      0u   
#define OS_SEM_QUERY_EN           0u  
#define OS_SEM_SET_EN             0u   


                                       // 时间管理
#define OS_TIME_DLY_HMSM_EN       0u   
#define OS_TIME_DLY_RESUME_EN     0u   
#define OS_TIME_GET_SET_EN        0u  
#define OS_TIME_TICK_HOOK_EN      0u   


                                       //定时器管理
#define OS_TMR_EN                 0u   
#define OS_TMR_CFG_MAX           16u  
#define OS_TMR_CFG_NAME_EN        0u   
#define OS_TMR_CFG_WHEEL_SIZE     7u  
#define OS_TMR_CFG_TICKS_PER_SEC 10u  

#endif
