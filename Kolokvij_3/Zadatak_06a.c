
#include <stdio.h>

int main(void) {
	unsigned char x = 7, y = 2;

	printf("%d\n", x / y);
	printf("%d\n", x >> y);
	printf("%d\n", x & y);
	printf("%d\n", x || y);
	printf("%d\n", sizeof(x) + sizeof(y));

	return 0;
}