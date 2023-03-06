#include <stdio.h>

int ifelse(void)
{
	int x = 2;
	int y = 4;
	int izracun;

	if (x > y)
	{
		izracun = x + y;
		printf("%d\n", izracun);
	}
	else if (x < y)
	{
		izracun = x * y;
		printf("%d\n", izracun);
	}

	return 0;
}