/********************************************
*文件名：pipe.c
*创建者：焦点
*创建时间：2019-4-4
*文件说明：无名管道通信
*********************************************/
#include<unistd.h>
#include<stdio.h>


/********************************************
*函数名：pipe
*参数：fd[2],两个文件描述符
*返回值：0,成功；1，失败
*函数功能：实现父子进程之间的通信
* ********************************************/


void main()
{
	pid_t pid = 0;
	int pipefd[2];
	char c_buf[14];
	
	//2、创建管道
	pipe(pipefd);
	
	//1、创建子进程
	pid = fork();
	
	if (pid>0)
	{
		//父进程写入数据
		write(pipefd[1],"hello world!",14);
		wait();
		close(pipefd[1]);
		exit(0);
	}
	
	if (pid==0)
	{
		//子进程读数据
		read(pipefd[0],c_buf,14);
		printf("child read %s\n",c_buf);
		close(pipefd[0]);
		exit(0);
	}
	
}