#include <stdio.h>
#include <math.h>

int hipotenuza(void) 
{
	double a, b, c;
	int test;

	printf("a = ");
	scanf_s("%lf", &a);

	printf("b = ");
	scanf_s ("%lf", &b);
	printf("\n");

	c = sqrt(a * a + b * b);

	printf("c = %.2lf\n", c);
}
