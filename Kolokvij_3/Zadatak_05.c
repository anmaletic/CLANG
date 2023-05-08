
#include <stdio.h>

int GetSuma(int broj) {
	int suma = 0;

	for (int i = 1; i < broj; i++) {
		if (broj % i == 0) {
			suma += i;
		}
	}
	return suma;
}

void PrintFrend(int m, int n) {
	for (int i = m; i <= n; i++) {
		for (int j = m; j <= n; j++) {
			if (i != j) {
				if (i == GetSuma(j) && j == GetSuma(i) && i < j)
				{
					printf("%d %d\n", i, j);
				}
			}
		}
	}
}

int main(void) {
	int m = 100, n = 300;

	PrintFrend(m, n);
}