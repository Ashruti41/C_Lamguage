#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

int main() {
	printf("Testing SIGSTOP\n");
	raise(SIGSTOP);
	printf("I am back\n");
	return 0;
}

