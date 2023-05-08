
#include <stdio.h>

int main(void) {
	int firstRun = 1, count = 0;
	float unos, minBr, maxBr, suma = 0, arS = 0, arMM = 0;

	while (1) {
		printf("Unos: ");
		scanf_s("%f", &unos);
		suma += unos;
		count++;

		if (firstRun) {
			minBr = unos;
			maxBr = unos;
			firstRun = 0;
		}

		if (minBr > unos) {
			minBr = unos;
		}
		else if (maxBr < unos) {
			maxBr = unos;
		}
		
		arS = suma / count;
		arMM = (minBr + maxBr) / 2;

		printf("arS: %f\n", arS);
		printf("arM: %f\n", arMM);

		if (arS > arMM) {
			break;
		}

	}
}