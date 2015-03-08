/*************************************************************************
	> File Name: 3.2.c
	> Author: sunlei
	> Mail: sunleihit@qq.com 
	> Created Time: Sun 08 Mar 2015 06:45:13 PM CST
 ************************************************************************/

#include "/home/sunlei/apue.2e/include/apue2.h"
#include <unistd.h>

#define MAX_DES 4096


int mydup2(const int filedes, const int filedes2){
	if(filedes == filedes2)
		return filedes;
	
	if(filedes2 < 3)
		err_sys("wrong file descriptor");

	int filedes3 = dup(filedes);
	if(filedes3 == -1)
		err_sys("filedes3 dup failed");
	
	int dess[MAX_DES];
	int current_des = 0;
	dess[current_des++] = filedes3;


	while(filedes3 < filedes2){
		if(filedes3 + 1 == filedes2 && close(filedes2) == -1)
			err_sys("close filedes2 failed");
		if((filedes3 = dup(filedes)) == -1)
			err_sys("dup failed");
		dess[current_des++] = filedes3;
	}
	while(--current_des > 0){
		if(close(dess[current_des]) == -1)
			err_sys("close failed.");
	}

	if(filedes3 > filedes2)
		err_sys("cannot do it...");

	return filedes3;
}


int
main(void){
    printf("%d\n", mydup2(0, 99));
   // printf("%d, %d, %d", mydup2(5, 10), mydup2(5, 4), mydup2(5, 1));
   return 1;
}	
