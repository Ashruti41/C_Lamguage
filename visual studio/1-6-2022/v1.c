#include<stdio.h>

int main()
{
	size_t size=5;
	int arr[size],sum=0,i;
	printf("enter the elements:");
	for(i=0; i<size; i++)
	{
		scanf("%d",&arr[i]);
		
		sum=sum+arr[i];
	}

	printf("Sum: %d",sum);
}
