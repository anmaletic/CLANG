
#include <stdio.h>

int main(void) {
	int john = 1000;
	int* gill = &john;
	int you = *gill;

	printf("%d\n", you);
	printf("%p\n", gill);
	printf("%d\n", john);

}