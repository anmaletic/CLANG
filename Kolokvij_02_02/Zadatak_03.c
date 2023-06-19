




#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char GetMostRepeated(char rijec[])
{
    srand(time(NULL));

    int nizabc[26] = { 0 };
    int najPonavljanja = 0;
    int offset = 0;

    int brZnakova = strlen(rijec);
    for (int i = 0; i<brZnakova; i++)
    {
        if(isalpha(rijec[i]) && isupper(rijec[i]))
        {
            int rnd_offset = rand() % 26;
            rijec[i] = 'a' + rnd_offset;
        }
    }

    for (int i = 0; i<brZnakova; i++)
    {
        nizabc[rijec[i] - 'a']++; 
    }

    for (int i = 0; i<26; i++)
    {
        if (najPonavljanja < nizabc[i])
        {
            najPonavljanja = nizabc[i];
            offset = i;
        }
    }


    printf("%s\n", rijec);
    return 'a' + offset;
}

int main(void)
{
    char rijec[] = "aABCDdhOHhodHIOh";

    printf("%c", GetMostRepeated(rijec));
}
