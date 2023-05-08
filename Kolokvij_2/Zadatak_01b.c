
#include <stdio.h>

void foo(int a, int* b) {
	++a;
	*b = *b > 0 ? -(*b / 2) : *b + 5;
}


int main(void) {

	int i, j;
	i = j = 8;

	while (j) {
		foo(i, &j);
		printf("%d %d\n", i, j);
	}
	return 0;
}