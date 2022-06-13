#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<time.h>

#include<signal.h>
#include<sys/signal.h>

void nothing(int signum) { /*do nothing */ }

int main() {
	signal(SIGINT, nothing);
	while(1);

}

