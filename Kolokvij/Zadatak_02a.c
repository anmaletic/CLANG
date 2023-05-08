
#include <stdio.h>

int main(void) {
	int a, b = 0;

	for (a = 10; a > 1; ++b) {
		if (a % 3 == 1)
			a = a * 2 + 1;
		else
			a /= 3;
		printf("%d %d\n", b, a);
	}
	return 0;
}