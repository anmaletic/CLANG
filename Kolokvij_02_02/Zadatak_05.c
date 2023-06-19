




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct Artikl
{
    int sifra;
    char naziv[100];
    float cijena;
} Artikl;



void generateRandomData(Artikl* artikl, int i) {
    // Generate a random code
    artikl->sifra = i;

    // Generate a random name
    char randomName[100];
    sprintf(randomName, "Artikl-%d", rand() % 100);
    strncpy(artikl->naziv, randomName, sizeof(artikl->naziv));

    // Generate a random price between 1.00 and 100.00
    artikl->cijena = ((float)rand() / RAND_MAX) * 99.0 + 1.0;
}

void generateDemoFile() {
    // Initialize the random number generator
    srand(time(NULL));

    FILE* demo = fopen("demo", "wb+");
    if (demo == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Artikl artikli[10];

    for (int i = 0; i < 10; i++) {
        generateRandomData(&artikli[i], i);
    }

    fwrite(artikli, sizeof(Artikl), 10, demo);
    fclose(demo);
}

void readDemoFileAndPrintData() {
    FILE* demo = fopen("demo", "rb");
    if (demo == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Artikl artikli[30];

    // Read the data from the file
    fread(artikli, sizeof(Artikl), 10, demo);

    // Print the data
    printf("Data from demo file:\n");
    for (int i = 0; i < 10; i++) {
        printf("Artikl %d:\n", i + 1);
        printf("Sifra: %d\n", artikli[i].sifra);
        printf("Naziv: %s\n", artikli[i].naziv);
        printf("Cijena: %.2f\n", artikli[i].cijena);
        printf("-----------------------\n");
    }

    fclose(demo);
}



int* generiraj(int *brojSifri)
{
    int count = *brojSifri;
	int* sifre = (int*)malloc(count * sizeof(int));


    while(1)
    {        
        count++;

        int unos;

        printf("Unesite %d. sifru: ", count);
        scanf_s("%d", &unos);

        if(unos != -1)
        {
            sifre = (int*)realloc(sifre, sizeof(int) * count);
            sifre[count-1] = unos;
        }
        else
        {
            count--;
            break;
        }
    }

    *brojSifri = count;
    return sifre;
}


void azuriraj(int *polje, int n, FILE* f)
{
    for (int i=0; i<n; i++)
    {
        Artikl artikl;

        fseek(f, polje[i] * sizeof(Artikl), SEEK_SET);
        fread(&artikl, sizeof(Artikl),1,f);

        artikl.cijena = artikl.cijena * 1.1;

        fseek(f, polje[i] * sizeof(Artikl), SEEK_SET);
        fwrite(&artikl, sizeof(Artikl), 1, f);
    }
}

int main(void)
{
    //generateDemoFile();
    readDemoFileAndPrintData();

    int num = 0;

    int *sifre = generiraj(&num);

    for (int i=0; i<num; i++)
    {
        printf("%d ", sifre[i]);
    }

    FILE* demo1 = fopen("demo", "rb+");
    azuriraj(sifre, num, demo1);
    fclose(demo1);

    readDemoFileAndPrintData();
}
