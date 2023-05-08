
#include <stdio.h>

void foo(int* niz, int l, int* ponavljanja) {
	for (int i = 0; i < l; i++) {
		while (niz[i] > 0) {
			int znam = niz[i] % 10;
			ponavljanja[znam]++;
			niz[i] = niz[i] / 10;
		}
	}
}

int main(void) {
	int niz[9] = { 12, 15, 56, 1827, 35, 804, 99, 93, 12 };
	int ponavljanja[10] = { 0 };

	int min, max;

	foo(niz, 9, ponavljanja);

	//for (int i = 0; i < 10; i++) {
	//	printf("%d  ", i);
	//}
	//printf("\n");
	//for (int i = 0; i < 10; i++) {
	//	printf("%d  ", ponavljanja[i]);
	//}

	min = max = ponavljanja[0];
	int pz = 0, dz = 0;

	for (int i = 1; i < 10; i++) {
		if (min >= ponavljanja[i]) {
			min = ponavljanja[i];
			dz = i;
		}
		else if (max <= ponavljanja[i]) {
			max = ponavljanja[i];
			pz = i;
		}
	}

	int br = pz * 10 + dz;
	printf("%d", br);
}


