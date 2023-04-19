
#include <stdio.h>
#include <math.h>



int GetFactorial(int broj)
{
	int fact = 1;

	for (int i = 2; i <= broj; i++)
	{
		fact *= i;
	}

	printf("%d: ", broj);
	printf("%d\n", fact);

	return fact;
}


void CheckIfStrong(int unos)
{
	if (unos == 1)
	{
		printf("Broj %d je snazan!", unos);
		return;
	}

	int result = 0;
	int tempUnos = unos;

	while (tempUnos > 0)
	{
		int tempDigit = tempUnos % 10;
		result += GetFactorial(tempDigit);
		tempUnos = tempUnos / 10;
	}

	if (result == unos)
	{
		printf("Broj %.d je snazan!", unos);
	}
	else
	{
		printf("Broj %.d nije snazan!", unos);
	}
}


// 1, 2, 145, 40585
int main(void)
{
	int unos;

	printf("Unesite broj: ");
	scanf_s("%d", &unos);

	CheckIfStrong(unos);

	return 0;
}