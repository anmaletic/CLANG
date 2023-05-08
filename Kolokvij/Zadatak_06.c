

#include <stdio.h>

int SpojiNizove(int* niz1, int* niz2, int l1, int l2) {
	for (int i = 0; i < l2; i++) {
		int postoji = 0;

		for (int j = 0; j < l1; j++) {
			if (niz2[i] == niz1[j]) {
				postoji = 1;
				break;
			}
		}

		if (postoji == 0)
		{
			niz1[l1] = niz2[i];
			l1++;
		}
	}

	return l1;
}

int main(void) {
	int niz1[10] = { 3, 7, 5, 2, 9, -1, -1, -1, -1, -1 };
	int niz2[17] = { 3, 7, 5, 2, 9, 4, 6, 3, 7, 5, 2, 9, 1, 4, 11, 2, 32 };

	int len1 = SpojiNizove(niz1, niz2, 5, 17);

	printf("%d\n", len1);

	for (int i = 0; i < 10; i++) {
		if (niz1[i] == -1)
			break;

		printf("%d ", niz1[i]);
	}
}