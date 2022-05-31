#include<stdio.h>

int main()
{
	int grades[10];    //Array storing 10 values
	int count=10;      //Number of values to be read
	long sum=0;       //SUm of the number
	float average=0.0f;     //Average of the numbers

	printf("\n Enter the 10 grades: \n");   //Prompt for the input

	//REad the ten numbers to be averaged
	int i;
	for(i=0; i<count; ++i)
	{
		printf("%2u> ",i+1);
		scanf("%d",&grades[i]);
		sum +=grades[i];
	}

	average = (float)sum/count;
	printf("\nAverage of the ten grades entered is: %.2f\n",average);

	return 0;
}


