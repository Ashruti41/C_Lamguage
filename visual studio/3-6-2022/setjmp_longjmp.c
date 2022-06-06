//example of setjmp and longjmp

#include<stdio.h>
#include<setjmp.h>

jmp_buf buf;

int main()
{
	int i= setjmp(buf);
	printf("i=%d\n",i);

	longjmp(buf,42);
	printf("Does this line get printed?\n");
	return 0;
}	
