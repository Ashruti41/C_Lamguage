#include<stdio.h>

int main()
{
	char ch = 0;
	while(isspace(ch = (char)getchar())); //read as long as there are space
	ungetc(ch, stdin);   //put back the non-space

	printf("char is %c\n",getchar());
	return 0;
}

