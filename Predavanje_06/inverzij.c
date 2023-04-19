

#include <stdio.h>

void inverzija(int* niz, int v)
{
	for (int i = 0; i < v / 2; i++)
	{
		int t = niz[v-1 - i];
		niz[v-1 - i] = niz[i];
		niz[i] = t;
	}
}

int main()
{
	int niz[6] = { 2, 3, 5, 8, 9, 10 };

	inverzija(niz, 6);

	for (int i = 0; i < 6; i++)
		printf("%d ", niz[i]);
}