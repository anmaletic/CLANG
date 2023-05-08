#include <stdio.h>
#include <stdlib.h>


int* SpojiNizove(int* a, int l_a, int* b, int l_b) {
	int* c = (int*)malloc((l_a + l_b) * sizeof(int));

	if (c == NULL) {
		return NULL;
	}

	for (int i = 0; i < l_a; i++) {
		c[i] = a[i];
	}

	for (int i = 0; i < l_b; i++) {
		c[i+l_a] = b[i];
	}

	return c;
}



int main(void) {
	int a[3] = { 2, 3, 4 };
	int b[4] = { 6, 7, 8, 9 };

	int* c = SpojiNizove(a, 3, b, 4);
	if (c == NULL) {
		return 1;
	}

	for (int i = 0; i < 7; i++) {
		printf("%d ", c[i]);
	}

	free(c);

	return 0;
}