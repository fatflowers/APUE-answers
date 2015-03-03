/*************************************************************************
	> File Name: 1-5.c
	> Author: sunlei
	> Mail: sunleihit@qq.com 
	> Created Time: Tue 03 Mar 2015 09:40:30 AM CST
 ************************************************************************/
#include "/home/sunlei/apue.2e/include/apue2.h"
#include <sys/wait.h>

int 
main(void){
	char buf[MAXLINE];
	pid_t pid;
	int status;

	printf("%% ");
	while(fgets(buf, MAXLINE, stdin) != NULL){
		if(buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0;

		if((pid = fork()) < 0)
			err_sys("fork error");
		else if(pid == 0){ /* child */
			execlp(buf, buf, (char *)0);
			err_ret("couldn't execute %s", buf);
			exit(127);
		}

		if((pid = waitpid(pid, &status, 0)) < 0)
			err_sys("waitpid error");

		printf("%% ");
	}
}
