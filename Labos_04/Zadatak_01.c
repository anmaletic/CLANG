//  Napisati funkciju koja će primiti jedan cijeli broj N, te vratiti dinamički alocirani niz od N jedinstvenih
//  slučajno odabranih brojeva u intervalu[0, 100).
//  Rad funkcije testirati iz glavnog programa.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* GetNiz(int n) {
    int* niz = (int*)malloc(n * sizeof(int));
    
    srand(time(NULL));

    int count = 0;
    int broj;
    int postoji = 0;

    while (count < n) {

        broj = rand() % 100;

        if (count == 0) {
            niz[count] = broj;
            count++;
        }
        else {
            for (int j = 0; j < count; j++) {
                if (niz[j] == broj) {
                    postoji = 1;
                    break;
                }
            }

            if (postoji == 0) {
                niz[count] = broj;
                count++;
            }
            postoji = 0;
        }
    }
    return niz;
}


int main(void) {
    int n = 20;

    int* niz = GetNiz(n);

    for (int i = 0; i < n; i++) {
        printf("%d ", niz[i]);
    }

    free(niz);

    return 0;
}
