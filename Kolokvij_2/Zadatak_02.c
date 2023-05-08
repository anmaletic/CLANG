
#include <stdio.h>

int main(void) {
	int djelCount = 0;
	int broj = 30;

	while (djelCount < 15) {
		for (int i = 1; i <= broj; i = i + 2) {
			if (broj % i == 0) {
				djelCount++;

				//printf("%d: %d\n", djelCount, i);
			}
		}

		if (djelCount >= 15) {
			printf("%d", broj);
		}
		else {
			//printf("\n");
			djelCount = 0;
			broj++;
		}
	}
}