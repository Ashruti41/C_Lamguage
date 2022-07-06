#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *print_message_function(void *ptr);

int main() {
	pthread_t thread1, thread2;
	char *m1 = "thread 1";
	char *m2 = "thread 2";
	int iret1=0, iret2 = 0;

	iret1 = pthread_create(&thread1, NULL,print_message_function, (void*) m1);
	iret2 = pthread_create(&thread2,NULL,print_message_function,(void*) m2);

	pthread_join(thread1,NULL);
	pthread_join(thread2, NULL);

	printf("Thread 1 returns: %d\n", iret1);
	printf("Thread 2 returns : %d\n",iret2);
	pthread_exit(NULL);
	exit(0);
}

void *print_message_function(void *ptr) {
	char *message;
	message = (char *) ptr;
	printf("%s\n", message);
}


