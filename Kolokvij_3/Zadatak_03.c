
#include <stdio.h>

int GetNizType(int* niz, int l) {

	int tniz = 0;
	int ar;

	// aritmeticki
	for (int i = 1; i < l; i++)
	{
		if (i == 1) {
			ar = niz[i] - niz[i - 1];
		}
		else if (niz[i] - niz[i - 1] != ar) {
			tniz = 0;
			break;
		}

		tniz = 1;
	}

	if (tniz == 0) {
		for (int i = 2; i < l; i++)
		{
			if (niz[i - 2] + niz[i - 1] != niz[i]) {
				tniz = 0;
				break;
			}

			tniz = 2;
		}
	}

	return tniz;
}


int main(void) {
	//int niz[6] = { 3, 6, 9, 12, 15, 18 };
	int niz[6] = { 3, 7, 10, 17, 27, 44 };

	int tip = GetNizType(niz, 6);

	printf("%d", tip);
}