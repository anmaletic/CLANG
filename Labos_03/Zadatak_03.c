
#include <stdio.h>
#include <math.h>
#include <time.h>


int main() {
	int m[3][3];
	int maxV;

	srand(time(NULL));

	// init matrice
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			m[i][j] = rand() % 100 + 1;
		}
	}

	// ispis matrice
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d  ", m[i][j]);
		}
		printf("\n");
	}

	// ispis max
	maxV = m[0][0];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (maxV < m[i][j]) {
				maxV = m[i][j];
			}
		}
	}
	printf("Najveci broj je: %d\n", maxV);

	// ispis dijagonale
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) {
				printf("%d\n", m[i][j]);
			}
		}
	}
}