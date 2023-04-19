

#include <stdio.h>

int main() {
	int m1[2][2];
	int m2[2][2];

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("m1[%d][%d]: ", i, j);
			scanf_s("%d", &m1[i][j]);
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("m2[%d][%d]: ", i, j);
			scanf_s("%d", &m2[i][j]);
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			//printf("m1[%d][%d] + m2[%d][%d] = ", i, j, i, j);
			//printf("%d + %d = ", m1[i][j], m2[i][j]);
			//printf("%d\n", m1[i][j] + m2[i][j]);

			printf("%d ", m1[i][j] + m2[i][j]);
		}
		printf("\n");
	}
}