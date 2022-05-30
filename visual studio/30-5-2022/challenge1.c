//find perimeter and area of rectangle
//perimeter=2*(height+width)
//area = height* width


#include<stdio.h>

int main()
{
	int h,w,area,p;
	printf("Enter the value of width and height: ");
	scanf("%d %d", &w, &h);

	p=2*(h+w);
	printf("The perimeter is: %d",p);

	area=h*w;
	printf("\nArea of triangle is: %d", area);

	return 0;

}

