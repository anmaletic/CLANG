
#include <stdio.h>

void PrintParne(int min, int max)
{
	for (int i = 100; i <= 400; i++)
	{
		if ((i / 100) % 2 == 0 &&
			((i / 10) % 10) % 2 == 0 &&
			i % 2 == 0)
		{
			printf("%d ", i);
		}
			 
	}
}

int main(void)
{
	PrintParne(100, 400);
	return 0;
}