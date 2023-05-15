//  Potrebno je kreirati niz cijelih brojeva pri čemu korisnik unosi veličinu niza.Niz inicijalizirati unosom od
//  korisnika te izračunati aritmetičku sredinu elemenata u nizu.Nakon toga niz izmijeniti na način da se iz
//  njega izbace svi elementi manji od aritmetičke sredine(realokacija).


#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int n = 10;
    float suma = 0;
    float ars = 0;

    printf("Unesite velicinu niza: ");
    scanf_s("%d", &n);

    int* niz = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Unesite %d. broj: ", i+1);
        scanf_s("%d", &niz[i]);
        
        suma += niz[i];
    }

    ars = suma / n;
    printf("\n");
    printf("Ars: %2f", ars);

    int* temp = (int*)malloc(n * sizeof(int));
    int newSize = 0;

    for (int i = 0; i < n; i++) {
        if (niz[i] >= ars) {
            temp[newSize] = niz[i];
            newSize++;
        }
    }

    niz = realloc(niz, newSize * sizeof(int));

    for (int i = 0; i < newSize; i++) {
        niz[i] = temp[i];
    }

    printf("\n");
    for (int i = 0; i < newSize; i++) {

        printf("%d ", niz[i]);
    }

    free(temp);
    free(niz);

    return 0;
}