//  Kod primitka dolaznog poziva, mobitel automatski pretražuje interni adresar, te ispisuje naziv
//  pozivatelja ukoliko je on u imeniku.Zbog različitih načina zapisivanja istog broja(npr. 0915551234 i
//      + 385915551234), mobitel ne uspoređuje cijeli telefonski broj, već dva broja proglašava identičnima
//      ukoliko im je identično posljednjih 8 znamenki.
//      Neka su zapisi iz telefonskog imenika pohranjeni u strukturama oblika :
//  struct kontakt {
//      char ime[40];
//      char prezime[40];
//      char broj[15];
//  };
//  Napišite funkciju koja primi podatke iz adresara(kao niz struktura kontakt) i broj pozivatelja, te vrati
//  pokazivač na prvi kontakt koji zadovoljava gornje uvjete, odnosno NULL ukoliko je broj pozivatelja
//  nepoznat.
//  Testirati rad funkcije pozivom iz glavnog programa.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>#include <string.h>
#include <ctype.h>


#define DEBUG 0

typedef struct kontakt {
    char ime[40];
    char prezime[40];
    char broj[15];
} kontakt;


kontakt* GenerateDemoData() {
    char* imena[5] = { "Pero", "Marko", "Tina", "Marija", "Tomislav" };
    char* prezimena[5] = { "Peric", "Horvat", "Drakula", "Irha", "Starman" };
    //char* predbroj[6] = { "+38598", "098", "+38591", "091", "+38595", "095" };
    char* broj[20] = { "0951800092", "0980580092", "+385988626092", "0915847092", "0988678982",
                       "+385957980192", "+385957980192", "+385957980192", "+385957980192", "+385912938982",
                       "0916997092", "+385917605092", "0956724192", "+385951204192", "0989900092",
                       "+385982264192", "0987224192", "+385988032982", "0916299982", "0915831292" };

    kontakt* adresar = (kontakt*)malloc(20 * sizeof(kontakt));

    for (int i = 0; i < 20; i++)
    {
        kontakt osoba;
        strcpy(osoba.ime, imena[rand() % 5]);
        strcpy(osoba.prezime, prezimena[rand() % 5]);
        strcpy(osoba.broj, broj[i]);

        // Generate random number
        //int rndBroj = rand() % 6599999 + 2891272;
        //char tempbroj[15] = "";

        //for (int i = 0; i < 7; i++)
        //{
        //    tempbroj[i] = rndBroj % 10 + '0';
        //    rndBroj = rndBroj / 10;
        //}
        //char broj[15];

        //strcpy(broj, predbroj[rand() % 6]);
        //strcat(broj, tempbroj);
        //strcpy(osoba.broj, broj);

        adresar[i] = osoba;
    }

    for (int i = 0; i < 20; i++)
    {
        printf("%s %s %s", adresar[i].ime, adresar[i].prezime, adresar[i].broj);
        printf("\n");
    }

    return adresar;
}

kontakt* GetKontakt(kontakt* adresar, int l, char pozivateljBroj[15]) {

    int pbL = strlen(pozivateljBroj);
    char tempBroj[9] = "";

    if (pbL > 8) {

        int offset = pbL - 8;

        for (int i = 0; i < 8; i++)
        {
            tempBroj[i] = pozivateljBroj[i + offset];
        }
        printf("%s\n", tempBroj);
    }
    else {

        strcpy(tempBroj, pozivateljBroj);
    }

    for (int i = 0; i < l; i++)
    {
        if (strstr(adresar[i].broj, tempBroj) != NULL) {

            return &adresar[i];
        }
    }
    return NULL;
}

int main(void) {

    srand(time(NULL));

    kontakt* adresar = GenerateDemoData();


#if DEBUG
    while (1)
    {
#endif    
        char pozivateljBroj[15];
        printf_s("Upisite broj pozivatelja: ");

        gets(pozivateljBroj);

        kontakt* pozivatelj = GetKontakt(adresar, 20, pozivateljBroj);

        if (pozivatelj == NULL) {
            printf("Nije pronaden niti jedan kontakt!\n");
        }
        else {
            printf("Ime: %s\n", pozivatelj->ime);
            printf("Prezime: %s\n", pozivatelj->prezime);
            printf("Broj: %s\n", pozivatelj->broj);
        }
#if DEBUG
    }
#endif   

    free(adresar);
    return 0;
}
