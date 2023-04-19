
#include <stdio.h>

int main()
{
	char slovo;
	int brojSlova = 'z' - 'a' + 1;
	printf("Broj slova: %d\n", brojSlova);

	int niz[26] = { 0 };

	while (1) {
		printf("Unesite slovo: ");
		scanf_s(" %c", &slovo, 1);

		if (slovo < 'a' || slovo > 'z') {
			break;
		}

		++niz[slovo - 'a'];

		for (int i = 0; i < 26; ++i)
		{
			if (niz[i] > 0) {
				printf("%d %c\n", niz[i], i + 'a');
			}
		}
	}
}