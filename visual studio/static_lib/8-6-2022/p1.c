//double pointer
#include<stdio.h>
#include<malloc.h>
#include<string.h>

void foo(char **ptr){
	*ptr = malloc(255);
	strcpy(*ptr, "hello world");
}

int main()
{
	char *ptr = NULL;
	
	foo(&ptr);
	printf("%s\n",ptr);

	free(ptr);

	return 0;
}

