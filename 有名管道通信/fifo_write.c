/********************************************
*文件名：fifo_write.c
*创建者：焦点
*创建时间：2019-4-5
*文件说明：有名管道通信
*********************************************/
#include<sys/types.h>
#include<sys/stat.h> 
#include<fcntl.h>
#include<stdio.h>


/********************************************
*函数名：mkfifo
*参数：文件路径，文件权限
*返回值：0,成功；1，失败
*函数功能：创建一个有名管道
*********************************************/

void main()
{
	int fd;
	/*1、创建有名管道*/
	mkfifo("/tmp/myfifo",0666);
	
	/*2、打开文件*/
	fd = open("/tmp/myfifo",O_WRONLY);
	
	/*3、写入文件*/
	write(fd,"hello fifo",11);
	close(fd);
	
}