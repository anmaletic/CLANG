//  U tekstualnoj datoteci rezultati.tt pohranjeni su rezultati sveucilisnog malonogometnog prvenstva na nacin da u svakoj liniji stoji zapis jedne
//  odigrane utakmice u formatu (sva su polja odvojena razmakom)
//      domaci gosti d g
//  Gdje su D i G broj golova domacina, odnosno gostiju.
//  Npr
//      ffzg vsite 1 2
//      dif pmf 1 1
//      vsite pbf 0 1


#include <stdio.h>
#include <string.h>

int main(void)
{
    char naziv[20];
    char domaci[20];
    char gosti[20];
    int golDomaci;
    int golGosti;
    int bodovi = 0;

    FILE* fp = fopen("Rezultati.txt", "r");

    if(fp == NULL)
    {
        return 1;
    }

    printf("Unesite ime kluba: ");
    scanf("%s", naziv);

    while(fscanf(fp, "%s %s %d %d", domaci, gosti, &golDomaci, &golGosti) != EOF)
    {
        if (strcmp(naziv, domaci) == 0)
        {
            if(golDomaci > golGosti)
            {
                bodovi += 3;
            }
            if (golDomaci == golGosti)
            {
                bodovi += 1;
            }
        }

        if (strcmp(naziv, gosti) == 0)
        {
            if(golDomaci < golGosti)
            {
                bodovi += 3;
            }
            if (golDomaci == golGosti)
            {
                bodovi += 1;
            }
        }
    }
    printf("%d", bodovi);
    return 0;
}
