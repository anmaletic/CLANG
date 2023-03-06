
// Ucitati 3 broja manja od 30
// Ako neki broj nije manji od 30 ispisati grešku
// a + b > c
// a + c > b
// b + c > a

#include <stdio.h>

int unosNum = 0;
int unos[3];

int Zadatak1(void)
{
	while (unosNum < 3)
	{	
		printf("Unesite duzinu %d. stranice: ", unosNum+1);

		scanf_s("%d", &unos[unosNum]);
	
		if (unos[unosNum] > 0 && unos[unosNum] < 30)
		{
			unosNum++;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%d. stranica: %d\n", i+1, unos[i]);
	}
	

	return 0;
}