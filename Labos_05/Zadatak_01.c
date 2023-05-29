//  Definirati strukturu valjak.Napisati funkciju koja prima niz struktura valjak, te vraća valjak najvećeg
//  volumena.U glavnom programu deklarirati i proizvoljno inicijalizirati niz, te pozvati funkciju i izračunati
//  vrijednost volumena najvećeg valjka.
//  Formula za računanje volumena valjka = > V = r2 * v * 3.14, pri čemu je r polumjer baze, a v je visina.


#include <stdio.h>

typedef struct valjak {
    float r;
    float v;
} valjak;


valjak GetNajveci(valjak *valjci, int l) {

    valjak najveciValjak;
    float najveciVolumen, tempVolumen;

    for (int i = 0; i < l; i++)
    {
        tempVolumen = valjci[i].r * valjci[i].r * valjci[i].v * 3.14;

        if (i == 0) {
            najveciValjak = valjci[i];
            najveciVolumen = tempVolumen;
        }
        else {
            if (najveciVolumen < tempVolumen) {
                najveciValjak = valjci[i];
                najveciVolumen = tempVolumen;
            }
        }
    }
    return najveciValjak;
}

int main(void) {
    valjak  valjci[3] = { {1,2}, {2,3}, {4,5} };

    valjak rezultat = GetNajveci(valjci, 3);
    printf("%.f\n", rezultat.r);

    return 0;
}