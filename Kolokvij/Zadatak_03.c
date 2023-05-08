

#include <stdio.h>

int main(void) {
	int count = 0;

	for (int i = 10000; i < 100000; i++) {
		if (i % 100 == 88 || i % 88 == 0)
		{
			printf("%d\n", i);
			count++;

			if (count == 10)
				break;
		}
	}
	return 0;
}