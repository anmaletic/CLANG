
#include <stdio.h>


int main(void) {
	float cijena = 12;
	int kolicina;

	printf("Unesite kolicinu: ");
	scanf_s("%d", &kolicina);

	if (kolicina < 5) {
		printf("Nema popusta.");
		printf("Cijena bez popusta: %.2f", cijena * kolicina);
	}
	else if (kolicina >= 5 && kolicina < 10) {
		printf("Cijena bez popusta: %.2f", cijena * kolicina);
		printf("Cijena sa popustom: %.2f", (cijena *0.95) * kolicina);
	}
	else {
		printf("Cijena bez popusta: %.2f", cijena * kolicina);
		printf("Cijena sa popustom: %.2f", (cijena * 0.9) * kolicina);
	}
}