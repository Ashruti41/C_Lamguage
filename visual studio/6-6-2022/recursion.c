#include<stdio.h>
#include<stdlib.h>

int factorial(int n) {
	int result = 0;

	if(n==0)
		result =1;

	else
		result = n* factorial(n-1);

	return result;
}

int main()
{
	int n;
	printf("ENTER THE NUMBER: ");
	scanf("%d",&n);

	printf("%d",factorial(n));
	return 0;
}
