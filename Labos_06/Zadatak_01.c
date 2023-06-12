//  U binarnoj datoteci su spremljeni podaci o rezultatima glasovanja na drugom krugu predsjedničkih 
//  izbora. 
//  Podaci su spremljeni uz pomoć strukture:

//  struct glasovi
//  {
//  unsigned id;
//  char zupanija[50 + 1];
//  unsigned glasoviPrviKandidat; 
//  unsigned glasoviDrugiKandidat; 
//  };

//  Id predstavlja id zupanije i ujedno predstavlja redni broj zapisa unutar datoteke (Ako je Id =1 onda je to 
//  prvi zapis u datoteci, Id=2 predstavlja drugi itd.)
//  Napraviti program koji će korisniku dati na izbor dvije opcije: 
//  1. Ispis ukupnih rezultata glasovanja – ispisati koliko je glasova dobio prvi, a koliko drugi kandidat 
//  2. Ispis rezultata za određenu zupaniju – ispisati ime zupanije i glasove. (Korisnik unosi id zupanije za 
//  koju treba ispisati rezultate) 
//  Napomena: potrebno je kreirati i napuniti datoteku testnim podacima kako bi mogli testirati rad 
//  program


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0

typedef  struct glasovi
{
    unsigned id;
    char zupanija[50+1];
    unsigned glasoviPrviKandidat;
    unsigned glasoviDrugiKandidat;
} glasovi;



void GenerateDemoData()
{
    FILE* exist = fopen("Zupanije.bin", "rb");

    if(exist == NULL)
    {
        glasovi rezultati[5];

        rezultati[0].id = 0;
        strcpy(rezultati[0].zupanija, "Zagrebacka");
        rezultati[0].glasoviPrviKandidat = 17;
        rezultati[0].glasoviDrugiKandidat = 32;

        rezultati[1].id = 1;
        strcpy(rezultati[1].zupanija, "Zadarska");
        rezultati[1].glasoviPrviKandidat = 23;
        rezultati[1].glasoviDrugiKandidat = 67;

        rezultati[2].id = 2;
        strcpy(rezultati[2].zupanija, "Karlovacka");
        rezultati[2].glasoviPrviKandidat = 29;
        rezultati[2].glasoviDrugiKandidat = 12;

        rezultati[3].id = 3;
        strcpy(rezultati[3].zupanija, "Varazdinska");
        rezultati[3].glasoviPrviKandidat = 87;
        rezultati[3].glasoviDrugiKandidat = 56;

        rezultati[4].id = 4;
        strcpy(rezultati[4].zupanija, "Istarska");
        rezultati[4].glasoviPrviKandidat = 91;
        rezultati[4].glasoviDrugiKandidat = 89;

        FILE* fp = fopen("Zupanije.bin", "wb+");

        fwrite(rezultati, sizeof(glasovi), 5, fp);        
    }
}



void IspisiRezultat()
{
    glasovi tempRez;
    unsigned prviKandidat = 0;
    unsigned drugiKandidat = 0;
    
    FILE* fp = fopen("Zupanije.bin", "rb");

    for (int i = 0; i < 5; i++)
    {
        fseek(fp, i * sizeof(glasovi), SEEK_SET);
        fread(&tempRez, sizeof(glasovi), 1, fp);
        
        prviKandidat += tempRez.glasoviPrviKandidat;
        drugiKandidat += tempRez.glasoviDrugiKandidat;
    }
    
    printf_s("Prvi kandidat: %u\n", prviKandidat);
    printf_s("Drugi kandidat: %u\n", drugiKandidat);
}

void IspisiRezultatZupanije(int id)
{
    glasovi zupanija;

    FILE* fp = fopen("Zupanije.bin", "rb");
    fseek(fp, id * sizeof(glasovi), SEEK_SET);

    fread(&zupanija, sizeof(glasovi), 1, fp);

    
    printf_s("Zupanija: %s\n", zupanija.zupanija);
    printf_s("Prvi kandidat: %u\n", zupanija.glasoviPrviKandidat);
    printf_s("Drugi kandidat: %u\n", zupanija.glasoviDrugiKandidat);
}

int main(void)
{
    int unosId;

    GenerateDemoData();
    IspisiRezultat();

#if DEBUG
    while (1)
    {
#endif
        printf_s("\nUnesite Id zupanije: ");
        scanf_s("%d", &unosId);

        IspisiRezultatZupanije(unosId);
#if DEBUG
    }
#endif  

    return 0;
}