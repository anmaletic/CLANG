
#include <stdio.h>

int main(void) {
	float planGubitakKilograma;
	float mjerenje;
	float ukupanGubitak = 0;

	printf("Planirani gubitak kilograma: ");
	scanf_s("%f", &planGubitakKilograma);

	printf("Prvo mjerenje: ");
	scanf_s("%f", &mjerenje);

	ukupanGubitak += mjerenje;

	printf("Drugo mjerenje: ");
	scanf_s("%f", &mjerenje);

	ukupanGubitak += mjerenje;

	printf("Trece mjerenje: ");
	scanf_s("%f", &mjerenje);

	ukupanGubitak += mjerenje;

	if (ukupanGubitak - planGubitakKilograma >= 0) {
		printf("Cilj ispunjen.");
	}
	else
	{
		printf("Cilj nije ispunjen.");
	}
}