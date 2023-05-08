
#include <stdio.h>


void sum(short* a, short* b) {
	*a += b != NULL ? *b : 1;
}



int main(void) {
	short a = 5;
	short b[] = { 2, 4, 6, 8 };

	// a
	//sum(&a, NULL);
	//printf("%d", a);

	// b
	//sum(b, &b[3]);
	//printf("%d", b[0]);

	// c
	sum(&b[0], &a);
	sum(&b[1], &a);
	sum(&b[2], &a);
	sum(&b[3], &a);

	printf("%d\n", b[0]);
	printf("%d\n", b[1]);
	printf("%d\n", b[2]);
	printf("%d\n", b[3]);
}