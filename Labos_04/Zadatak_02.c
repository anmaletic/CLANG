//  Potrebno je kreirati niz cijelih brojeva pri čemu korisnik unosi veličinu niza.Niz napuniti slučajnim, prostim
//  brojevima iz raspona 1 - 3000. Broj je prost ukoliko djeljiv samo sa 1 sa samim sobom.Kreirani niz ispisati.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int IsProst(int br) {
    for (int i = 2; i < br / 2 + 1; i++) {
        if (br % i == 0) {
            return 0;
        }
    }
    return 1;
}


int* GetNiz(int n) {
    int* niz = (int*)malloc(n * sizeof(int));

    srand(time(NULL));

    int count = 0;
    int broj;

    while (count < n) {
        broj = rand() % 3000 + 1;

        if (broj != 1 && IsProst(broj)) {
            niz[count] = broj;
            count++;
        }
    }

    return niz;
}


int main(void) {
    int n = 20;

    printf("Unesite velicinu niza: ");
    scanf_s("%d", &n);

    int* niz = GetNiz(n);

    for (int i = 0; i < n; i++) {
        printf("%d ", niz[i]);
    }


    free(niz);

    return 0;
}
