/*
 * �����嵥����������������
 *
 * ������̴���һ���̣߳�ͨ����ʱ������������ӣ����ڴ�ӡ������й��ӵĴ���
 */
 
#include <rtthread.h>
#include <rthw.h>

#define THREAD_PRIORITY         25
#define THREAD_STACK_SIZE       512
#define THREAD_TIMESLICE        5

/* ָ���߳̿��ƿ��ָ�� */
static rt_thread_t tid = RT_NULL;
 
/* ���к������Ӻ���ִ�д��� */
volatile static int hook_times = 0;
 
/* ���������Ӻ��� */
static void idle_hook()
{
    if (0 == (hook_times % 10000))
    {
        rt_kprintf("enter idle hook %d times.\n", hook_times);
    }
 
    rt_enter_critical();  //�ٽ����ı�������ֹ�������ȼ��ߵ��̴߳�� hook_times++ ִ��
    hook_times++;
    rt_exit_critical();    //����ٽ����ı���
}
 
static void hook_of_scheduler(struct rt_thread* from, struct rt_thread* to)
{
    rt_kprintf("from: %s -->  to: %s \n", from->name , to->name);
}

/* �߳���� */
static void thread_entry(void *parameter)
{
    int i = 5;
    while (i--)
    {
        rt_kprintf("enter thread1.\n");
        rt_enter_critical();
        hook_times = 0;
        rt_exit_critical();
 
        /* ����500ms */
        rt_kprintf("thread1 delay 50 OS Tick.\n", hook_times);  //һ��ϵͳ�δ�10ms
        rt_thread_mdelay(500);  //ϵͳ��������߳����У���Ӧ�Ĺ��Ӻ����͵õ�����
    }
    rt_kprintf("delete idle hook.\n");
    
    /* ɾ�����й��Ӻ��� */
    rt_thread_idle_delhook(idle_hook);  //ɾ�����Ӻ����󣬽�������߳�ʱ�����õĹ��Ӻ����Ͳ���������
    rt_kprintf("thread1 finish.\n");
}
 



int usual_hook_sample(void)
{
    /* ���ÿ����̹߳��� */
    rt_thread_idle_sethook(idle_hook);
 
 /* ���õ��������� */
 //   rt_scheduler_sethook(hook_of_scheduler);

    /* �����߳� */
    tid = rt_thread_create("thread1",
                           thread_entry, RT_NULL, 
                           THREAD_STACK_SIZE, 
                           THREAD_PRIORITY, THREAD_TIMESLICE);
    if (tid != RT_NULL)
        rt_thread_startup(tid);
 
    return 0;
}
 
/* ������ msh �����б��� */
MSH_CMD_EXPORT(usual_hook_sample, usual hook sample);
