//  Cezarova enkripcija (Julije Cezar, 44. g. p.n.e.) sastoji se od zamjene svakog slova slovom koje u abecedi stoji iza njega za 3 mjesta.
//  'a' tako postaje 'd', 'b' postaje 'e' itd. Abeceda ce gledati ciklicki, pa tako slovo y postaje 'b', a 'z' postaje 'c'.
//  Napisati program koji ce za tekst ucitan od korisnika ispisati njegovu enkriptiranu verziju. Maksimalna duljina teksta je 100 znakova.


#include <stdio.h>

int main(void) {
    char s[101] = "abcyz";

    int i = 0;

    gets(s);

    while (s[i] != '\0') {

        if ((s[i] >= 'a' && s[i] <= 'z')) {

            char temp = s[i] + 3;
            if (temp > 'z') {
                temp = temp - ('z' - 'a') - 1;
            }
            s[i] = temp;
        }


        if ((s[i] >= 'A' && s[i] <= 'Z')) {

            char temp = s[i] + 3;
            if (temp > 'Z') {
                temp = temp - ('Z' - 'A') - 1;
            }
            s[i] = temp;
        }

        i++;
    }

    printf("%s", s);
}