/*************************************************************************
	> File Name: 3.6.c
	> Author: sunlei
	> Mail: sunleihit@qq.com 
	> Created Time: Sun 08 Mar 2015 09:20:35 PM CST
 ************************************************************************/

#include "/home/sunlei/apue.2e/include/apue2.h"
#include <unistd.h>
#include <fcntl.h>

void write_file(const char *filename){
	int fd = open(filename, O_WRONLY|O_CREAT);
	if (fd == -1)
		err_sys("open failed");
	char *s = "0123456789";
	int i;
	for(i = 0; i < 10; i++)
		if(write(fd, s, 10) == -1)
			err_sys("write failed.");

	if(close(fd) == -1)
		err_sys("close failed.");
}

int
main(){
	write_file("write.tmp");
	int fd = open("write.tmp", O_RDWR);
	if(fd == -1)
		err_sys("open failed.");

	lseek(fd, 3, SEEK_SET);
	if(write(fd, "sunlei", 6) == -1)
		err_sys("write failed.");

	if(close(fd) == -1)
		err_sys("close failed.");

	exit(0);
}
