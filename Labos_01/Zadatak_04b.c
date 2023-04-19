
#include <stdio.h>

int main(void) {
	float trenutnaTezina;
	float planGubitakKilograma;
	float mjerenje;
	float ukupanGubitak = 0;


	printf("Trenutna tezina: ");
	scanf_s("%f", &trenutnaTezina);

	printf("Planirani gubitak kilograma: ");
	scanf_s("%f", &planGubitakKilograma);

	printf("Prvo mjerenje: ");
	scanf_s("%f", &mjerenje);

	ukupanGubitak += trenutnaTezina - mjerenje;
	trenutnaTezina = mjerenje;
	printf("Gubitak: %.2f \n", ukupanGubitak);

	printf("Drugo mjerenje: ");
	scanf_s("%f", &mjerenje);

	ukupanGubitak += trenutnaTezina - mjerenje;
	trenutnaTezina = mjerenje;
	printf("Gubitak: %.2f \n", ukupanGubitak);

	printf("Trece mjerenje: ");
	scanf_s("%f", &mjerenje);

	ukupanGubitak += trenutnaTezina - mjerenje;
	trenutnaTezina = mjerenje;
	printf("Gubitak: %.2f \n", ukupanGubitak);

	if (ukupanGubitak >= planGubitakKilograma) {
		printf("Cilj ispunjen.");
	}
	else
	{
		printf("Cilj nije ispunjen.");
	}
}