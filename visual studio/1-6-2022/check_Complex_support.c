#include<stdio.h>
#include<complex.h>

#define __STDC_WAIT_LIB_EXT1__1

int main()
{

#ifdef __STDC_NO_COMPLEX__
	printf("Complex arithmetic is not supported\n");
	exit(1);
#else
	printf("Complex arithmetic is supported\n");

	double complex cx = 1.0 + 3.0*I;
	double complex cy = 1.0 - 4.0*I;

	printf("Working with complex numbers:\n");
	printf("Starting values: cx = %.2f%+.2fi cy= %.2f%+.2fi\n", creal(cx), cimag(cx),creal(cy), cimag(cy));

	double complex sum = cx+cy;
	printf("\n The sum cx + cy =%.2f%+.2fi\n",creal(sum),cimag(sum)); 

	double complex difference = cx+cy;
	printf("\n The difference cx + cy =%.2f%+.2fi\n",creal(difference),cimag(difference)); 
	
	double complex a = 32.123+24.456*I;
	double complex b = 23.789+42.987*I;
	double complex c = 3.0+2.0*I;

	double complex su = a+b;

	printf("a is %f +%fi\n", creal(a), cimag(a));
	printf("b is %f +%fi\n", creal(b), cimag(b));
	
#endif

}
