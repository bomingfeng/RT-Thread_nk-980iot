/*
 * 程序清单：空闲任务钩子例程
 *
 * 这个例程创建一个线程，通过延时进入空闲任务钩子，用于打印进入空闲钩子的次数
 */
 
#include <rtthread.h>
#include <rthw.h>

#define THREAD_PRIORITY         25
#define THREAD_STACK_SIZE       512
#define THREAD_TIMESLICE        5

/* 指向线程控制块的指针 */
static rt_thread_t tid = RT_NULL;
 
/* 空闲函数钩子函数执行次数 */
volatile static int hook_times = 0;
 
/* 空闲任务钩子函数 */
static void idle_hook()
{
    if (0 == (hook_times % 10000))
    {
        rt_kprintf("enter idle hook %d times.\n", hook_times);
    }
 
    rt_enter_critical();  //临界区的保护，防止其他优先级高的线程打断 hook_times++ 执行
    hook_times++;
    rt_exit_critical();    //解除临界区的保护
}
 
static void hook_of_scheduler(struct rt_thread* from, struct rt_thread* to)
{
    rt_kprintf("from: %s -->  to: %s \n", from->name , to->name);
}

/* 线程入口 */
static void thread_entry(void *parameter)
{
    int i = 5;
    while (i--)
    {
        rt_kprintf("enter thread1.\n");
        rt_enter_critical();
        hook_times = 0;
        rt_exit_critical();
 
        /* 休眠500ms */
        rt_kprintf("thread1 delay 50 OS Tick.\n", hook_times);  //一个系统滴答10ms
        rt_thread_mdelay(500);  //系统进入空闲线程运行，相应的钩子函数就得到运行
    }
    rt_kprintf("delete idle hook.\n");
    
    /* 删除空闲钩子函数 */
    rt_thread_idle_delhook(idle_hook);  //删除钩子函数后，进入空闲线程时，设置的钩子函数就不会运行了
    rt_kprintf("thread1 finish.\n");
}
 



int usual_hook_sample(void)
{
    /* 设置空闲线程钩子 */
    rt_thread_idle_sethook(idle_hook);
 
 /* 设置调度器钩子 */
 //   rt_scheduler_sethook(hook_of_scheduler);

    /* 创建线程 */
    tid = rt_thread_create("thread1",
                           thread_entry, RT_NULL, 
                           THREAD_STACK_SIZE, 
                           THREAD_PRIORITY, THREAD_TIMESLICE);
    if (tid != RT_NULL)
        rt_thread_startup(tid);
 
    return 0;
}
 
/* 导出到 msh 命令列表中 */
MSH_CMD_EXPORT(usual_hook_sample, usual hook sample);
