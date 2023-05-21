// Napisati funkciju koja provjerava da li je neki string palindrom

#include <stdio.h>
#include <string.h>

int palindrom(char* s)
{
    int duzina = strlen(s);

    for (int i = 0; i < duzina/2; i++) {
        if (s[i] != s[duzina - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    printf("%d", palindrom("anavolimilovana"));
}