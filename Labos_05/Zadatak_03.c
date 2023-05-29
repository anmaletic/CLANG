//Definirajte dvije strukture : farmer i domaća životinja.
//Struktura farmer u sebi ima puno ime i prezime farmera te pokazivač na niz domaćih životinja.
//Struktura domaća životinja sadrži podatak o vrsti, količini životinja te vrste te o broju vrsta životinja koje
//farmer ima.
//Napišite funkciju koja prima više farmera te vraća pokazivač na prvog farmera na kojeg naiđe koji ima
//više od 10 kokoši.Ako niti jedan farmer ne odgovara kriterijima, funkcija vraća NULL.
//Testirati rad funkcije pozivom iz glavnog programa.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct DomZivotinja {
    char vrsta[20];
    int kolicina;
    int brojVrsta;
} DomZivotinja;

typedef struct Farmer {
    char ime[30];
    char prezime[30];
    DomZivotinja* zivotinje;
} Farmer;


Farmer* GenerateDemoData() {

    Farmer* farmeri = (Farmer*)malloc(3*sizeof(Farmer));

    if (farmeri != NULL) {

        // Farmer 1
        strcpy(farmeri[0].ime, "Pero");
        strcpy(farmeri[0].prezime, "Peric");
        farmeri[0].zivotinje = (DomZivotinja*)malloc(2 * sizeof(DomZivotinja));

        //     Zivotinja 1
        strcpy(farmeri[0].zivotinje[0].vrsta, "Krava");
        farmeri[0].zivotinje[0].kolicina = 7;
        farmeri[0].zivotinje[0].brojVrsta = 2;

        //     Zivotinja 2
        strcpy(farmeri[0].zivotinje[1].vrsta, "Svinja");
        farmeri[0].zivotinje[1].kolicina = 12;
        farmeri[0].zivotinje[1].brojVrsta = 2;


        // Farmer 2
        strcpy(farmeri[1].ime, "Hrvoje");
        strcpy(farmeri[1].prezime, "Horvat");
        farmeri[1].zivotinje = (DomZivotinja*)malloc(3 * sizeof(DomZivotinja));

        //     Zivotinja 1
        strcpy(farmeri[1].zivotinje[0].vrsta, "Konj");
        farmeri[1].zivotinje[0].kolicina = 2;
        farmeri[1].zivotinje[0].brojVrsta = 3;

        //     Zivotinja 2
        strcpy(farmeri[1].zivotinje[1].vrsta, "Kokos");
        farmeri[1].zivotinje[1].kolicina = 18;
        farmeri[1].zivotinje[1].brojVrsta = 3;

        //     Zivotinja 3
        strcpy(farmeri[1].zivotinje[2].vrsta, "Ovca");
        farmeri[1].zivotinje[2].kolicina = 42;
        farmeri[1].zivotinje[2].brojVrsta = 3;


        // Farmer 3
        strcpy(farmeri[2].ime, "Mare");
        strcpy(farmeri[2].prezime, "Maric");
        farmeri[2].zivotinje = (DomZivotinja*)malloc(2 * sizeof(DomZivotinja));

        //     Zivotinja 1
        strcpy(farmeri[2].zivotinje[0].vrsta, "Ovca");
        farmeri[2].zivotinje[0].kolicina = 5;
        farmeri[2].zivotinje[0].brojVrsta = 2;

        //     Zivotinja 2
        strcpy(farmeri[2].zivotinje[1].vrsta, "Kokos");
        farmeri[2].zivotinje[1].kolicina = 5;
        farmeri[2].zivotinje[1].brojVrsta = 2;
    }

    return farmeri;
}

Farmer* GetFarmer(Farmer* farmeri, int l) {

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < farmeri[i].zivotinje->brojVrsta; j++)
        {
            if (strcmp(farmeri[i].zivotinje[j].vrsta, "Kokos") == 0)
            {
                if (farmeri[i].zivotinje[j].kolicina > 10) {
                    return &farmeri[i];
                }
            }
        }
    }
    return NULL;
}

int main(void) {

    Farmer* farmeri = GenerateDemoData();

    // ispis generiranog niza
    for (int i = 0; i < 3; i++)
    {
        printf("%s %s", farmeri[i].ime, farmeri[i].prezime);
        printf("\n");

        for (int j = 0; j < farmeri[i].zivotinje->brojVrsta; j++)
        {
            printf("    %s: %d", farmeri[i].zivotinje[j].vrsta, farmeri[i].zivotinje[j].kolicina);
            printf("\n");
        }
    }        
    printf("\n");


    Farmer* farmer = GetFarmer(farmeri, 3);

    if (farmer == NULL) {
        printf("Nije pronaden niti jedan farmer.");
        printf("\n");
    }
    else {
        printf("%s %s", farmer->ime, farmer->prezime);
        printf("\n");

        for (int j = 0; j < farmer->zivotinje->brojVrsta; j++)
        {
            printf("    %s: %d", farmer->zivotinje[j].vrsta, farmer->zivotinje[j].kolicina);
            printf("\n");
        }
    }

    free(farmeri);

    return 0;
}