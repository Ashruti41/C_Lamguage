#include<stdio.h>
#include "myLib.h"

void fun(void)
{
	fun();
	printf("fun() called from a static library");
}

