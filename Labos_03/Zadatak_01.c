
#include <stdio.h>



int jedinstveni(int niz[], int v) {

	int isJedinstveni = 0;
	int brojJedinstvenih = 0;

	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			if (i != j) {
				if (niz[i] != niz[j]) {
					isJedinstveni = 1;
				}
				else {
					isJedinstveni = 0;
					break;
				}
			}
		}

		if (isJedinstveni == 1)
		{
			brojJedinstvenih++;
			printf("Jedinstveni= %d\n", niz[i]);
			isJedinstveni = 0;
		}
	}

	return brojJedinstvenih;
}


int main() {
	int unos[5];

	// unos
	for (int i = 0; i < 5; i++) {
		printf("Unesite %d. broj: ", i + 1);
		scanf_s("%d", &unos[i]);
	}

	// ispis
	printf("Elementi niza:\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", unos[i]);
	}

	printf("U nizu se nalazi %d jedinstvenih elemenata.", jedinstveni(unos, 5));
}


