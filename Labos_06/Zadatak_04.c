//  Kreirajte datoteku input.txt i u nju unesite proizvoljan tekst. Napišite program koji otvara tu datoteku i 
//  svaku riječ u datoteci koja počinje s malim ili velikom slovom P zapisuje u novu datoteku imena 
//  output.txt kao novu liniju u toj datoteci.


#include <stdio.h>
#include <string.h>

void FindWords(FILE* fpIn)
{
    FILE* fpOut = fopen("output.txt", "w+");

    int pos = 0;

    while (1)
    {
        char rijec[30];
        int res = fscanf(fpIn,"%s", rijec);
        if (res == -1)
        {
            break;
        }

        pos += strlen(rijec) + 1;
        fseek(fpIn, pos, SEEK_SET);

        if (rijec[0] == 'P' || rijec[0] == 'p')
        {
            fprintf(fpOut, "%s\n", rijec);
        }
    }

    fclose(fpOut);
}

int main(void)
{    
    FILE* fpIn = fopen("input.txt", "r");

    if(fpIn == NULL)
        return 1;

    FindWords(fpIn);

    fclose(fpIn);

    return 0;
}
