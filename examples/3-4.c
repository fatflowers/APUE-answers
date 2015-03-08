/*************************************************************************
	> File Name: 3-4.c
	> Author: sunlei
	> Mail: sunleihit@qq.com 
	> Created Time: Sun 08 Mar 2015 10:33:25 AM CST
 ************************************************************************/

#include "/home/sunlei/apue.2e/include/apue2.h"
#include <fcntl.h>

int
main(int argc, char *argv[]){
	printf("%s\n%s", argv[0], argv[1]);
    if(argc != 2){
		err_sys("descriptor #2");
	}

	int filedes;
	if((filedes = fcntl(atoi(argv[1]), F_GETFL, 0)) == -1){
		err_sys("fcntl error!");
	}

	switch(filedes & O_ACCMODE){
		case O_RDONLY:
			printf("read only");
			break;
		case O_WRONLY:
			printf("write only");
			break;
		case O_RDWR:
			printf("read write");
			break;
		default:
			err_dump("unknown access mode");
	}
    if(filedes & O_APPEND)
		printf(", append");
	if(filedes & O_NONBLOCK)
		printf(", nonblock");

#if defined(O_SYNC)
	if(filedes & O_SYNC)
		printf(", synchronous writes");
#endif

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC)
	if(filedes & O_FSYNC)
		printf(", synchronous writes");
#endif
	putchar('\n');

	exit(0);
}
