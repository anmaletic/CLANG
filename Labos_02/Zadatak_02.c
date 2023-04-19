
#include <stdio.h>

void PrintTrokut(int broj)
{
	int red = 1;
	int count = 0;

	for (int i = 1; i <= broj; i++)
	{
		printf("%d ", i);
		count++;
		
		if (count == red)
		{
			printf("\n");
			count = 0;
			red++;
		}
	}
}


int main(void)
{
	PrintTrokut(10);
	return 0;
}