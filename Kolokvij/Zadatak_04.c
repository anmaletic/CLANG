
#include <stdio.h>

int foo(unsigned broj) {
	while (broj > 9) {
		broj /= 10;
	}
	return broj;
}


int main(void) {
	int br = 234567;
	
	int z = foo(br);

	printf("%d", z);
}