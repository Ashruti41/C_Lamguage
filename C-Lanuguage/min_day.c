#include <stdio.h>

int main()
{
    int min = 0;
    double year = 0.0;
    double days = 0.0;
    double minInYears = 0.0;
    
    printf("Enter the min\n");
    scanf("%d",&min);
    
    minInYears = (60 * 24 * 365);
    
    year = (min / minInYears);
    
    days = (min / 60.0 ) / 24;
    
    printf("%d min is %f year and %f days", min, year, days);
    
    return 0;
}
