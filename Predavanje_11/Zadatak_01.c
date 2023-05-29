//  Definirati strukturu valjak. Napisati funkciju koja prima niz struktura valjak,
//  te vraca valjak najveceg volumena. U glavnom programu deklarirati i proizvoljno inicijalizirati
//  niz, te pozvati funkciju i izracunati vrijednost volumena najveceg valjka.

#include <stdio.h>

struct valjak {
    float r;
    float visina;
};

struct valjak getNajveci(struct valjak* v, int n) {

    struct valjak najveci = v[0];
    float najveciVolumen = v[0].r * v[0].r * v[0].visina * 3.14;

    for (int i = 1; i < n; i++) {
        float volumen = v[i].r * v[i].r * v[i].visina * 3.14;
        
        if (volumen > najveciVolumen)
        {
            najveciVolumen = volumen;
            najveci = v[i];
        }
    }
    return najveci;
}


int main(void) {
    struct valjak  valjci[3] = { {1,2}, {2,3}, {4,5} };

    struct valjak rezultat = getNajveci(valjci, 3);
    printf("%.f\n", rezultat.r);

    return 0;
}