#include<stdio.h>
#include<setjmp.h>
jmp_buf buf;

void myFunction(){
	printf("in myfunction()\n");
	longjmp(buf,1);

	//not reached
	printf("you will never see this , because I longjmp'd");
}

int main()
{
	if(setjmp(buf))
		printf("back in main\n");
	else{
		printf("first time through\n");
		myFunction();
	}
	return 0;
}
