//binary to decimal convert
#include<stdio.h>
#include<math.h>

int convert(long long);

int main()
{
	long long bin;
	printf("enter the binary number: ");
	scanf("%lld",&bin);
	printf("the decimal number is :%d",convert(bin));
	return 0;
}

int convert(long long bin)
{
	int dec=0, rem,base=1;

	while(bin!=0)
	{
		rem = bin % 10;
		dec = dec +rem * base;
		bin/= 10;
		base = base *2;
	
	}
	return dec;
}
	

