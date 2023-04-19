
#include <stdio.h>
#include <math.h>


void CheckIfStrong(double broj)
{
	if (broj == 1)
	{
		printf("Broj %.lf je snazan!", broj);
		return;
	}

	for (int b = 1; b <= broj / 2; b++)
	{
		for (int a = 1; a <= broj / 2; a++)
		{
			int result = pow(a, 2) * pow(b, 3);

			if (result == broj)
			{
				printf("Broj %.lf je snazan!", broj);
				return;
			}
		}
	}

	printf("Broj %.lf nije snazan!", broj);
}


int main(void)
{
	double unos;

	printf("Unesite broj: ");
	scanf_s("%lf", &unos);

	CheckIfStrong(unos);
	return 0;
}