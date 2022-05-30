//create and use of enum data type

#include<stdio.h>

int main()
{
	enum Company{ GOGGLE,FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT};

	enum Company xerox= XEROX;
	enum Company goggle= GOGGLE;
	enum Company ebay= EBAY;

	printf("\nthe value is : %d",xerox);
	printf("\nThe value is : %d",goggle);
	printf("\nThe value is :%d", ebay);

}

