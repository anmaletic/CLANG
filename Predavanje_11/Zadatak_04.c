//  Napisite funkciju normaliziraj koja prima jedan sting i izmjeni ga na nacin:
//      - kapitalizira Prva Slova Svake Rijeci
//      - sva ostala velika slova zamijeni malima
//      - sve znakove koji nisu slova, znamenke ili razmaci zamijeni znakom ?
//  Funkcija neka vrati broj izmjenjenih znakova.

#include <stdio.h>
#include <ctype.h>


int izmijeni(char* s) {
    int brojac = 0;
    int d = strlen(s);

    for (int i = 0; i < d; i++) {
        if (i == 0 && isalpha(s[i]) && islower(s[i])) {
            s[i] = toupper(s[i]);
            brojac++;
        }
        else if (isalpha(s[i]) && !islower(s[i])) {
            s[i] = tolower(s[i]);
            brojac++;
        }
        else if (!isalnum(s[i]) && !isspace(s[i])) {
            s[i] = '?';
            brojac++;
        }
        else if (isspace(s[i]) && !isupper(s[i+1])) {
            s[i + 1] = toupper(s[i + 1]);
            i++;
            brojac++;
        }
    }

    printf("%s\n", s);
    return brojac;
}

int main(void) {

    char s[] = "oVo jE: tE+T";
    printf("%d\n", izmijeni(s));
}