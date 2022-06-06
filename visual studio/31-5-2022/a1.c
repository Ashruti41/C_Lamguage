#include<stdio.h>

int main()
{
	int arr_value[10]={0,1,4,9,16};
	int i;

	for(i=5; i<10; ++i)
		arr_value[i]=i*i;

	for(i=0; i<10; ++i)
		printf("array_values[%i]=%i\n",i,arr_value[i]);

	return 0;

}
