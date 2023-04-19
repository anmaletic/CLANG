
#include <stdio.h>

int minBroj(int* niz, int v)
{
	int min = *niz; // moze i niz[0];

	for (int i = 1; i < v; i++)
	{
		if (min > niz[i])
		{
			min = niz[i];
		}
	}
	return min;
}

int main(void) 
{
	int niz[5] = { 10, 12, 3, 4, 1 };

	int a = minBroj(niz, 5);

	printf("%d", a);
}