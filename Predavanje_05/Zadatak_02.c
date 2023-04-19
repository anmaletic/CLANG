
#include <stdio.h>

int odrediDatum(int datum, int* dan, int* mjesec, int* godina)
{
	int kontrolna = datum % 10;

	*dan = datum / 10000000;
	*mjesec = datum / 100000 % 100;
	*godina = datum / 10 % 10000;

	int zbroj = 0;
	datum = datum / 10;

	while (datum > 0)
	{
		zbroj += datum % 10;
		datum = datum / 10;
	}

	printf("%d\n", zbroj % 10);

	return 0;
}

int main(void)
{
	int datum = 21120095;
	int *dan, *mjesec, *godina;

	odrediDatum(datum, &dan, &mjesec, &godina);

	printf("%d %d %d", dan, mjesec, godina);

	return 0;
}