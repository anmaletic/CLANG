


#include <stdio.h>
#include <string.h>

int usporedi(FILE* dat1, FILE* dat2, float prag)
{
    fseek(dat1, 0, SEEK_SET);
    fseek(dat2, 0, SEEK_SET);

    int brRazlicitihRedaka = 0;

    while(1)
    {
        char red1[1024];
        char red2[1024];


        if(fgets(red1,sizeof(red1), dat1) != NULL)
        {
            fgets(red2,sizeof(red2), dat2);


            int brIstih = 0;
            int brZnakova1 = strlen(red1);
            int brZnakova2 = strlen(red2);

            if (brZnakova1 == brZnakova2)
            {                
                for (int i = 0; i<brZnakova1; i++)
                {
                    if(red1[i] == red2[i])
                    {
                        brIstih++;
                    }
                }
            }

            if(((float)brIstih / brZnakova1) < prag)
            {
                brRazlicitihRedaka++;
            }
        }
        else
        {
            break;
        }
    }

    return brRazlicitihRedaka;
}


int main(void)
{
    FILE* dat1 = fopen("prva.txt", "r");
    FILE* dat2 = fopen("druga.txt", "r");

    int rez = usporedi(dat1, dat2, 0.25);
    printf("%d", rez);
}
