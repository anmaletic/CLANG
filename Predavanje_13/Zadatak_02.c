//  Imamo datoteku u kojoj su spremljeni brojevi tipa double
//  Ispisati 3 slucajnih brojeva


#include <stdio.h>

int main(void) {

    double niz[5] = { 1, 2, 3, 4, 5 };
    double broj;
    int r;
    srand(time(NULL));

    FILE* fp = fopen("Test.bin", "wb+");

    fwrite(niz, sizeof(double), 5, fp);

    fseek(fp, 0, SEEK_SET);


    for (int i = 0; i < 3; i++) {

        r = rand() % 5;

        fseek(fp, r * sizeof(double), SEEK_SET);

        fread(&broj, sizeof(double), 1, fp);

        printf("%0.f", broj);
        printf("\n");
    }
}