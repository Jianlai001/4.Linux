#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>//系统函数
#include<string.h>

#include<pthread.h>

#include<sys/socket.h>
#include<arpa/inet.h>

#include<ctype.h>

#include<errno.h>
#include<signal.h>

#include<sys/epoll.h>//epoll

#define _SERVERIP "192.168.232.128"
#define _SERVERPORT 8081
#define _BUFFERSIZE 1500
#define _IPSIZE 16
#define _EPOLLSIZE 20000
#define _TIMEOUT 2
#define _DELNUM 10//线程池扩容缩减量
#define _BACKLOG 128

//任务类型
typedef struct 
{
    void *(*task_addr)(void *);//函数指针存储函数地址
    void *arg;//函数参数
}task_t;

//线程池类型
typedef struct 
{
    //线程阈值
    int thread_max;
    int thread_min;
    int thread_alive;
    int thread_busy;
    int thread_shutdowm;
    int thread_exitcode;//线程缩减量

    pthread_t *tids;//消费者线程tid数组的指针

    //管理者线程
    pthread_t mtid;//管理者线程tid

    //任务容器
    task_t *task_list;//任务队列地址
    int front;
    int rear;
    int max;
    int cur;

    //线程安全
    pthread_mutex_t lock;
    pthread_cond_t not_full;
    pthread_cond_t not_empty;

}thread_pool_t;

int epfd;//监听树描述符

pthread_mutex_t server_fd_lock;//防止多个线程同时调用accept使用server_fd冲突

void thread_pool_error(const char *, int); //错误处理

//线程池相关函数
thread_pool_t *thread_pool_create(int tmin, int tmax, int qmax);//线程池创建初始化 创建为堆区变量，各线程共享 需要最大最小线程数，最大任务队列数
int thread_pool_destroy(thread_pool_t *);//线程池销毁

int thread_pool_add_task(thread_pool_t *, task_t);////主线程作为生产者，线程池中的业务队列添加业务

void *customer(void *);//消费者线程工作函数，参数为线程池地址

void *manager(void *);//管理者线程工作函数，参数为线程池地址

int if_thread_alive(pthread_t tid);//通过tid使用信号测试线程是否存活

//网络相关函数
int server_net_init();//服务器网络初始化

int server_epoll_create(int server_fd);//epoll监听树创建初始化

int server_epoll_listen(thread_pool_t* thread_poll, int server_fd);//启用epoll监听，辨别就绪，添加任务
//业务
void *bussiness_accept(void *);
void *bussiness_response(void *);




