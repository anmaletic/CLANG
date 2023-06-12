//Napisi funkcijun koja za datoteku u kojoj se u svakom retku nalazi jedan broj i jedna rijec
//ispise na ekran rijec onoliko puta koliko je broj
//npr ako u datotteci pise
//4 jabuka
//2 banana
//na ekran treba napisati
//jabuka jabuka jabuka jabuka
//banana banana


#include <stdio.h>
#include <string.h>

void ispis(FILE* fp) {
    
    int a;
    char rijec[10];

    while (fscanf(fp, "%d %s", &a, rijec) != EOF) {

        for (int i = 0; i < a; i++) {

            printf("%s ", rijec);
        }
        printf("\n");
    }
}


int main(void) {

    FILE* fp;
    fp = fopen("Text.txt", "r");

    if (fp == NULL) {
        return 1;
    }

    ispis(fp);

    return 0;
}
