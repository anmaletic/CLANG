
#include <stdio.h>
#include <string.h>

// a, b
typedef struct student
{
    char ime[64+1];
    char prezime[80+1];
    int bodovi;
    int prolaznost;
} student;


int main(void)
{
    // c)
    student studenti[3];


    // d)
    strcpy(studenti[0].ime, "Antonio");
    strcpy(studenti[0].prezime, "Maletic");
    studenti[0].bodovi = 73;
    studenti[0].prolaznost = 1;

    // e)
    strcpy((studenti+1)->ime, "Antonio");
    strcpy((studenti+1)->prezime, "Maletic");
    (studenti+1)->bodovi = 37;
    (studenti+1)->prolaznost = 0;
    
    printf("%s\n", studenti[0].ime);
    printf("%s\n", studenti[0].prezime);
    printf("%d\n", studenti[0].bodovi);
    printf("%d\n", studenti[0].prolaznost);
    printf("\n");

    printf("%s\n", studenti[1].ime);
    printf("%s\n", studenti[1].prezime);
    printf("%d\n", studenti[1].bodovi);
    printf("%d\n", studenti[1].prolaznost);
    printf("\n");
}