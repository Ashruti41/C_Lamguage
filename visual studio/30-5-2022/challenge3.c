//convert minutes into days and years


#include<stdio.h>
#include<stdlib.h>

int main()
{
	int minutes=0;
	double years=0.0;
	double days=0.0;

	double minutesInyear=0;

	printf("Enter minutes: ");
	scanf("%d",&minutes);

	minutesInyear=(60 * 24 * 365);
	
	years=( minutes/ minutesInyear);

	days=(minutes/ 60.0) / 24.0;

	printf("\nthe value of year is :%f", years);
	printf("\nthe value of days is :%f", days);
 	return 0;
}

	


