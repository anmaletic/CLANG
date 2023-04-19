
#include <stdio.h>
#include <math.h>
#include <time.h>



void foo(int *niz, int l, int* minV, int* maxV, double *arS) {
	*minV = niz[0];
	*maxV = niz[0];
	double suma = 0;

	for (int i = 0; i < l; i++) {
		if (niz[i] < *minV) {
			*minV = niz[i];
		}
		else if (niz[i] > *maxV) {
			*maxV = niz[i];
		}

		suma += niz[i];
	}
	*arS = suma / l;
}



int main() {
	int niz[8];
	int minV, maxV;
	double arS;

	srand(time(NULL));

	// unos niza
	for (int i = 0; i < 8; i++)
	{
		niz[i] = rand() % 10 + 1;
	}

	// ispis niza
	printf("Elementi niza:\n");
	for (int i = 0; i < 8; i++)
	{
		printf("%d\n", niz[i]);
	}

	foo(niz, 8, &minV, &maxV, &arS);

	printf("Najmanji element je: %d\n", minV);
	printf("Najveci element je: %d\n", maxV);
	printf("Aritmeticka sredina je: %lf\n", arS);
}