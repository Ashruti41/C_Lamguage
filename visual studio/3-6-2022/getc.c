#include<stdio.h>

int main()
{
	char ch = '\0';

	ch = getc(stdin);
	printf("read in character %c\n",ch);

	return 0;
}
