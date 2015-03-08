/*************************************************************************
	> File Name: testdup.c
	> Author: sunlei
	> Mail: sunleihit@qq.com 
	> Created Time: Sun 08 Mar 2015 06:42:45 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int
main(void){
	int a;
	printf("%d\n", a = dup(0));
	return 1;
}
