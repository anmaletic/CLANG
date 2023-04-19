


#include <stdio.h>


int faktorijel(int broj) {
	int suma = 1;
	for (int i = 1; i <= broj; i++) {
		suma *= i;
	}
	return suma;
}


int main(void) {
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", faktorijel(i + 1));
	}
	return 0;
}