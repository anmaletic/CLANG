
#include <stdio.h>

int foo(int* broj)
{
	while (*broj > 10)
	{
		*broj /= 10;
	}
	return *broj;
}

int main(void)
{
	int a= 432;
	int* broj = &a;

	printf("%d\n", a);
	printf("%d\n", foo(broj));
}

