/*************************************************************************
	> File Name: 2.3.c
	> Author: sunlei
	> Mail: sunleihit@qq.com 
	> Created Time: Tue 03 Mar 2015 07:57:22 PM CST
 ************************************************************************/

/**
 * 用getrlimit得到每个进程的最大打开文件描述fu数
 */


#include "/home/sunlei/apue.2e/include/apue2.h"
#include <limits.h>
#include <sys/resource.h>

#define OPEN_MAX_GUESS 256

long 
open_max(void)
{
	long openmax;
	struct rlimit rl;
	
	if((openmax = sysconf(_SC_OPEN_MAX)) < 0 || openmax == LONG_MAX){
		if(getrlimit(RLIMIT_NOFILE, &rl) < 0)
			err_sys("can't get file limit.");
		if(rl.rlim_max == RLIM_INFINITY)
			openmax = OPEN_MAX_GUESS;
		else
			openmax = rl.rlim_MAX;
	}

	return openmax;
}
