#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char *buffer = NULL;
	size_t bufsize = 32;
	size_t characters;

	buffer = (char *)malloc(bufsize * sizeof(char));

	if(buffer == NULL) {
		exit(1);
	}

	printf("Type something:");
	characters = getline(&buffer,&bufsize,stdin);

	printf("%zu characters were read.\n",characters);
	printf("you typed: %s\n",buffer);
	
	return 0;
}

