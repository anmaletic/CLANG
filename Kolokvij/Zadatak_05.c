
#include <stdio.h>
#include <time.h>
#include <math.h>

int main(void) {
	srand(time(NULL));

	unsigned niz[7] = { 0 };
	int pos = 0;

	while (pos < 7) {
		int postoji = 0;
		unsigned br = rand() % 39 + 1;
		
		for (int i = 0; i < pos; i++) {
			if (niz[i] == br) {
				postoji = 1;
				break;
			}
		}

		if (pos == 0 || postoji == 0) {
			niz[pos] = br;
			pos++;
		}
	}

	//for (int i = 0; i < 7; i++) {
	//	printf("%d: %u\n", i+1, niz[i]);
	//}
}