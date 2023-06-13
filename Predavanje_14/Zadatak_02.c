//  Prepisati ulaznu datoteku u izlaznu izbacujuci sva uzastopna pojavljivanja istog slova.
//  npr
//      qwwwerrttty
//  prepisati u:
//      qwerty

#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE* fp1;
    FILE* fp2;
    char c;
    char izlaz[100];
    int pos = 0;

    fp1 = fopen("ulazna.txt", "r");

    if (fp1 == NULL)
    {
        return 1;
    }

    fp2 = fopen("izlazna.txt", "w");

    if(fp2 == NULL)
    {
        fclose(fp1);
        return 1;
    }

    while((c = fgetc(fp1)) != EOF)
    {
        if(izlaz[pos-1] != c)
        {
            izlaz[pos] = c;
            pos++;
        }
    }
    izlaz[pos] = '\0';

    fwrite(izlaz, strlen(izlaz) * sizeof(char), 1, fp2);
}
