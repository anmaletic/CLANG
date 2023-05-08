//  Upitajte korisnika za broj studenata koji su kolokvirali kolegij CLANG i alocirajate niz dovoljno velik
//  za pohranu ocjene svakog studenta. Upitajte pojedinacne ocjene studenata i izracunajte prosjek ocjena. 
//  Nakon toga upitajte korisnika za broj studenta koji su ispit polozili na redovnik rokovima, prosirite 
//  prethodni niz za prihvat i njihovih ocjena, unesite nove ocjene, te izracunajte prosjek


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	int n2;
	int suma = 0;
	int* ocjene;
	int* ocjene2;

	scanf_s("%d", &n);

	ocjene = (int*)malloc(n * sizeof(int));
	if (ocjene == NULL) {
		return 1;
	}

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &ocjene[i]);
		suma += ocjene[i];
	}

	printf("%2f", (float)suma / n);

	scanf_s("%d", &n2);

	ocjene2 = realloc(ocjene, (n + n2) * sizeof(int));
	if (ocjene2 == NULL) {
		return 1;
	}

	ocjene = ocjene2;

	for (int i = n; i < n + n2; i++) {
		scanf_s("%d", &ocjene[i]);
		suma += ocjene[i];
	}

	printf("%2f", (float)suma / (n+n2));
	free(ocjene);
	return 0;
}