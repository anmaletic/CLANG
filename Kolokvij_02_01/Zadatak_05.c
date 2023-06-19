

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE* ulazna = fopen("ulazna.txt", "r");
    FILE* izlazna = fopen("izlazna.txt", "w+");

    fseek(ulazna, 0, SEEK_SET);
    fseek(izlazna, 0, SEEK_SET);

    char line[255];

    while (fgets(line, sizeof(line), ulazna) != NULL)
    {
        const int brZnakova = strlen(line);

        if(brZnakova < 30)
        {
            if(!isdigit(line[0]))
            {
                int brAlpha = 0;
                int brDigit = 0;
                for (int i = 0; i < brZnakova; i++)
                {
                    if(isdigit(line[i]))
                    {
                        brDigit++;
                    }
                    else if (isalpha(line[i]))
                    {
                        brAlpha++;
                    }
                }

                if (brDigit > brAlpha)
                {
                    fputs(line, izlazna);
                }
            }
        }
    }

    return 0;
}
