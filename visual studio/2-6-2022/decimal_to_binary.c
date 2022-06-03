//decimal to binary conversion

#include<stdio.h>
#include<math.h>

int convert(int );
int main()
{
	int n;
	printf("enter the decimal number");
	scanf("%d",&n);
	printf("the binary number is: %d",convert(n));
	return 0;
}

int convert(int n)
{
	long long bin=0;
	int base=1,rem;

	while(n!=0)
	{
		rem = n%2;
		n /=2;
		bin = bin + rem *base;
		base = base * 10; 
	}
	return bin;
}
