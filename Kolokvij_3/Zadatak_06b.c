
#include <stdio.h>

int main(void) {
	int foo[5] = { -2, -1, 0, 1, 2 }, * bar = foo;
	for (;;) {
		if (*bar > 0) {
			*bar -= 2;
			bar -= 2;
			continue;
		}
		else if (*bar < 0) {
			*bar += 3;
			bar += 3;
		}
		else {
			break;
		}
		printf("%d ", *bar);
	}
	printf("%d ", *bar);

	return 0;
}