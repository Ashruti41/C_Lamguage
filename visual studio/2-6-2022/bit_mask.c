#include<stdio.h>

int main()
{
	int num, position, newNum, bitStatus;

	//input number from user
	printf("Enter any number: ");
	scanf("%d",&num);

	//input bit position you want to set
	printf("ENter nth bit to check and set(0-31): ");
	scanf("%d",&position);

	//right shift num, position times amd perform bitwise AND with 1
	bitStatus = (num>>position) & 1;
	printf("the %d bit is set to %d\n",position, bitStatus);

	//left shift 1, n times and perform bitwise OR with num
	newNum = (1 << position) | num;
	printf("\n bit set successfully\n\n");

	printf("Number before setting %d bit: %d(in decimal)\n", position,num);
	printf("Number after setting %d bit: %d (in decimal)\n",position, newNum);
	return 0;
}
