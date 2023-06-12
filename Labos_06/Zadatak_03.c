//  Božićni duh je ušao u firmu „Export-Import d.o.o.“ te su odlučili organizirati tombolu kojom će podijeliti 
//  poklone svojim zaposlenicima. 
//  Uz zadane strukture: 
//  struct osoba
//  {
    //  char ime[25 + 1];
    //  char prezime[25 + 1];
//  };
//  struct poklon
//  {
    //  char naziv[50 + 1];
    //  int dodijeljen;
//  };
//  napisati program koji će simulirati izvlačenje nagrada na tomboli (za potrebe zadatka definirati da 
//  imamo 5 osoba i 5 poklona). 
//  Napuniti niz s osobama, te nakon toga jednoj po jednoj osobi slučajnim odabirom dodijeliti poklon. 
//  Pokloni se čitaju iz binarne datoteke (potrebno je dakle prije napuniti datoteku podacima). 
//  Kada se neki poklon dodijeli potrebno mu je ažurirati zastavicu dodijeljeno kako ga ne bi opet dodijelili 
//  nekom drugome te ispisati koja je nagrada kome dodijeljena.
//   Primjer ispisa:
//  Osoba Ana Anic je dobila Cokolada
//  Osoba Pero Peric je dobila Knjiga
//  Osoba Mario Maric je dobila Kapa
//  Osoba Jure Juric je dobila Pegla
//  Osoba Ante Antic je dobila Mobitel


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct osoba
{
    char ime[25 + 1];
    char prezime[25 + 1];
}osoba;

typedef struct poklon
{
    char naziv[50 + 1];
    int dodijeljen;
}poklon;


void GeneratePokloniData()
{
    FILE* exist = fopen("Pokloni.bin", "rb");

    if(exist == NULL)
    {
        poklon pokloni[5];

        strcpy(pokloni[0].naziv, "Cokolada");
        pokloni[0].dodijeljen = 0;

        strcpy(pokloni[1].naziv, "Knjiga");
        pokloni[1].dodijeljen = 0;

        strcpy(pokloni[2].naziv, "Kapa");
        pokloni[2].dodijeljen = 0;

        strcpy(pokloni[3].naziv, "Pegla");
        pokloni[3].dodijeljen = 0;

        strcpy(pokloni[4].naziv, "Mobitel");
        pokloni[4].dodijeljen = 0;

        FILE* fp = fopen("Pokloni.bin", "wb+");

        fwrite(pokloni, sizeof(poklon), 5, fp);
        fclose(fp);
    }
}

osoba* GenerateOsobeData()
{
    osoba* osobe = (osoba*)malloc(5*sizeof(osoba));
    
    strcpy(osobe[0].ime, "Ana");
    strcpy(osobe[0].prezime, "Anic");

    strcpy(osobe[1].ime, "Pero");
    strcpy(osobe[1].prezime, "Peric");
    
    strcpy(osobe[2].ime, "Mario");
    strcpy(osobe[2].prezime, "Maric");
    
    strcpy(osobe[3].ime, "Jure");
    strcpy(osobe[3].prezime, "Juric");
    
    strcpy(osobe[4].ime, "Ante");
    strcpy(osobe[4].prezime, "Antic");

    return osobe;
}

void DodijeliPoklone(osoba* osobe, int l)
{
    poklon pokloni[5];

    FILE* fp = fopen("Pokloni.bin", "rb");
    fread(pokloni, sizeof(poklon), 5, fp);

    for (int i=0; i<l; i++)
    {
        while(1)
        {
            int poklonId = rand() % 5;
            
            if (pokloni[poklonId].dodijeljen == 0)
            {
                printf("Osoba %s %s je dobila %s.\n", osobe[i].ime, osobe[i].prezime, pokloni[poklonId].naziv);
                pokloni[poklonId].dodijeljen = 1;
                break;
            }
        }

    }

    fclose(fp);
}


int main(void)
{
    srand(time(NULL));

    GeneratePokloniData();

    osoba* osobe = GenerateOsobeData();

    DodijeliPoklone(osobe, 5);
}