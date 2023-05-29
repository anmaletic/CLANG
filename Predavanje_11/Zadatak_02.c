// Napisati funkciju koja prima pokazivac na prvi clan niza struktura grad :
//  struct  grad {
//      char ime[100];
//      int iduci;
//  };

//  Funkcija neka ispise imena svih gradova niza pocevsi od prvog, redoslijedom definiranim clanovima iduci
//  (iduci zadnjeg clana ima vrijednost -1). 
//  Npr. niz inicijaliziran sa :
//  stuct grad gradovi[] =
//  { {"Du", 3}, {"St", -1}, {"Zg", 4}, {"Ri", 2}, {"Os", 1} };


#include <stdio.h>

typedef struct  grad {
    char ime[100];
    int iduci;
}grad;

void ispisiGradove(grad* g) {

    int id = 0;
    while (1)
    {
        printf("%s\n", g[id].ime);
        id = g[id].iduci;
        
        if (id == -1) {
            break;
        }
    }
}

int main(void) {

    grad gradovi[] = { {"Du", 3}, {"St", -1}, {"Ri", 4}, {"Zg", 2}, {"Os", 1} };

    ispisiGradove(gradovi);

    return 0;
}
