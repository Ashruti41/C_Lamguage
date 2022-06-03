#include<stdio.h>

int main()
{
	short int w1 = 25 ;                     //0000000000010001
	short int w2 = 77;                      //0000000000101101
	short w3;

	w3 = w1 & w2;
	printf("Ans: %d\n", w3);
	
	w3 = w1 | w2;
	printf("Ans: %d\n", w3);

	w3 = w1 ^ w2;
	printf("Ans: %d\n", w3);
	
	w3 = ~w1;
	printf("Ans: %d\n",w3);

	w3 = ~w2;
	printf("Ans: %d\n",w3);

	return 0;
}

