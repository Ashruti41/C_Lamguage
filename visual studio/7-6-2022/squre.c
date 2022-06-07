#include<stdio.h>

#define SQUARE(x) (x*x)
#define CUBE(x) (x*x*x)

int main()
{

	int n;

	printf("Square: %d",SQUARE(2));
	printf("cube: %d",CUBE(2));

	return 0;
}
