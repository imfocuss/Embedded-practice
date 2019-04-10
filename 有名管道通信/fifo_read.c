/********************************************
*文件名：fifo_read.c
*创建者：焦点
*创建时间：2019-4-5
*文件说明：有名管道通信
*********************************************/
#include<sys/types.h>
#include<sys/stat.h> 
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>


/********************************************
*函数名：unlink
*参数：文件路径
*返回值：0,成功；1，失败
*函数功能：删除有名管道和文件
*********************************************/

void main()
{
	 int fd;
	 char buf[15];
	 
	 /*打开文件*/
	 fd = open("/tmp/myfifo",O_RDONLY);
	 
	 /*读文件*/
	 read(fd,buf,11);
	 printf("read is %s\n",buf);
	 
	 /*关闭文件*/
	 close(fd);
	 unlink("/tmp/myfifo");
}