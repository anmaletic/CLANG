
#include <stdio.h>

int main(void) {
	short a, b;

	for (a = -3, b = 24; a <= 3 && b > 0; ++a, b /= 2) {
		if (a % b)
			printf("%hd %hd\n", a, b);
	}

	return 0;
}