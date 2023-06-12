//  Ispisati broj slova, znamenki te znakova koji nisu ni slova ni znamenke u datoteci

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {

    FILE* fp;
    char c;
    int brojacDigit = 0;
    int brojacAlpha = 0;
    int brojacOstalo = 0;
    fp = fopen("zadatak_03.txt", "r");

    if (fp == NULL) {
        return 1;
    }

    while ((c = fgetc(fp)) != EOF) {

        if (isdigit(c)) {
            brojacDigit++;
        }
        else if (isalpha(c)) {
            brojacAlpha++;
        }
        else {
            brojacOstalo++;
        }

    }

    printf("%d %d %d", brojacDigit, brojacAlpha, brojacOstalo);
}
