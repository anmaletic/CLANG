//  U ulaznoj su tekstualnoj datoteci razmacima odvojene korisničke lozinke. Treba napisati program koji će 
//  pročitati sve zadane lozinke i u izlaznu datoteku prepisati samo one koje smatramo sigurnima. Lozinku 
//  smatramo sigurnom ukoliko je njena duljina barem 8 znakova, te sadrži barem po jedno malo i veliko 
//  slovo engleske abecede, te barem jednu znamenku.


#include <ctype.h>
#include <stdio.h>
#include <string.h>

void ProvjeriLozinke(FILE* fpIn)
{
    FILE* fpOut = fopen("LozinkeOut.txt", "w+");

    int vSlovo = 0;
    int mSlovo = 0;
    int znamenka = 0;
    int pos = 0;

    fseek(fpIn, 0, SEEK_SET);

    while (1)
    {
        char lozinka[20];
        int res = fscanf(fpIn, "%s", lozinka);
        if(res == -1)
        {
            break;
        }

        int brojZnakova = strlen(lozinka);
        pos += brojZnakova + 1;
        fseek(fpIn, pos, SEEK_SET);

        if (brojZnakova >= 8)
        {
            for (int i = 0; i < brojZnakova; i++)
            {
                if(lozinka[i] >= 'a' && lozinka[i] <='z' && mSlovo == 0)
                {
                    mSlovo = 1;
                }

                if(lozinka[i] >= 'A' && lozinka[i] <='Z' && vSlovo == 0)
                {
                    vSlovo = 1;
                }

                if(isdigit(lozinka[i]) && znamenka == 0)
                {
                    znamenka = 1;
                }
            }
            if(mSlovo && vSlovo && znamenka)
            {
                fprintf(fpOut, "%s ", lozinka);

                mSlovo = vSlovo = znamenka = 0;
            }
        }
    }    
}


int main(void)
{
    FILE* fp = fopen("LozinkeIn.txt", "r");

    ProvjeriLozinke(fp);

    return 0;
}