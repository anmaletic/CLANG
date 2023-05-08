
#include <stdio.h>


int GetSuma(int n) {
	int suma = 0;

	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			suma += i;
		}
	}
	return suma;
}

int main(void) {
	int manjkav = 0;
	int savrsen = 0;
	int obilan = 0;

	int br = 56;

	for (int i = 1; i <= br; i++) {
		int suma = GetSuma(i);

		if (suma < i) {
			manjkav++;
		}
		else if (suma == i) {
			savrsen++;
		}
		else {
			obilan++;
		}
	}

	printf("Manjkavih: %d\nSavrsenih: %d\nObilnih: %d\n", manjkav, savrsen, obilan);
}