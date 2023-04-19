
#include <stdio.h>


int main(void) {
	int dozvoljenaBrzina;
	int brzina;

	printf("Unesite dozvoljenu brzinu: ");
	scanf_s("%d", &dozvoljenaBrzina);

	printf("Zabiljezena brzina: ");
	scanf_s("%d", &brzina);

	if (brzina - dozvoljenaBrzina >= 40) {
		printf("Oduzimanje vozacke dozvole.");
	}
	else if (brzina - dozvoljenaBrzina >= 20) {
		printf("Dva kaznena boda.");
	}
	else if (brzina - dozvoljenaBrzina > 0) {
		printf("Jedan kazneni bod.");
	}
	else {
		printf("Hvala na sigurnoj voznji.");
	}
}