
#include <stdio.h>


int main(void) {
	float a, b, h;

	printf("a = ");
	scanf_s("%f", &a);

	printf("b = ");
	scanf_s("%f", &b);

	printf("h = ");
	scanf_s("%f", &h);

	float m = (a + b) / 2;
	float p = m * h;

	printf("Povrsina trapeza iznosi: %.2f", p);
}