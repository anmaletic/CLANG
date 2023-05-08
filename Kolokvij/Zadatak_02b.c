

#include <stdio.h>

void foo(char* slovo) {
	printf("%c", -- * slovo);
}

int main(void) {
	short i = 4;
	char c = 'd', * p = &c;

	while (--i) {
		foo(p);
		printf("%c", c);
	}

	return 0;
}