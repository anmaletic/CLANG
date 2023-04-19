
#include <stdio.h>
#include <math.h>


int neparnini(int broj) {
	int potencija = 0;
	int noviBroj = 0;

	while (broj > 0) {
		int z = broj % 10;
		if (z % 2 != 0 ) {
			noviBroj += z * pow(10, potencija);
			potencija += 1;
		}
		broj /= 10;
	}
	return noviBroj;
}

int main()
{
	printf("%d", neparnini(578236));
	return 0;
}