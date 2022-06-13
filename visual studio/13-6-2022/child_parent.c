#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

#define MAX_COUNT 10

void childProcess(void);  //child process
void parentProcess(void);  //parent process

void main(void) {
	pid_t pid;
	pid = fork();

	if(pid ==0)
		childProcess();
	else if(pid>0)
		parentProcess();
	else{
		printf("fork() failed! \n");
		return 1;
	}
}

void childProcess(void) {
	int i=0;

	for(i=1; i<=MAX_COUNT; i++)
		printf("this line is from child, value = %d\n",i);
	printf("**** child is done ***\n");
}
void parentProcess(void) {
	int i=0;

	for(i=1; i<=MAX_COUNT; i++)
		printf("this line is from child, value = %d\n",i);
	printf("*** Parent is done ***\n");
}

