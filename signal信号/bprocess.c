/********************************************
*文件名：fifo_read.c
*创建者：焦点
*创建时间：2019-4-5
*文件说明：有名管道通信
*********************************************/
#include<signal.h>
#include<stdio.h>


/********************************************
*函数名：sighandler_t signal(int signum, sighandler_t handler)
*参数：signum：要处理的信号
	   handler：信号处理方式（也可以用SIG_IGN、SIG_DFT、或者自定义函数）
*返回值：成功：返回处理函数的指针
	     失败：返回SIG_ERR
*函数功能：设置信号处理方式
*********************************************/

void myfuc()
{
	printf("process B received SIGINT\n");
}

void main()
{
	signal(SIGINT,myfuc);
	pause();
}


//令打开终端，kill -n SIGINT pid
//pause();是函数