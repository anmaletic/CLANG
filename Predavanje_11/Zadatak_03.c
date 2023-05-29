//  Napisite funkciju koja ce primiti informacije o svim bazninm stanicama i trenutne koordinate jednog korisnika,
//  te ce kao povratnu vrijednost vratiti broj baznih stanica koje su mu u dometu.

#include <stdio.h>
#include <math.h>


typedef struct Point {
    float x;
    float y;
} Point;

typedef struct BaznaStanica {
    Point t;
    float domet;
} BaznaStanica;

int bazneStaniceUBlizini(BaznaStanica* stanice, int v, Point korisnik) {
    int brojac = 0;
    for (int i = 0; i < v; i++) {
        float udaljenost = sqrt(pow(stanice[i].t.x - korisnik.x, 2) + pow(stanice[i].t.y - korisnik.y, 2));

        if (udaljenost <= stanice[i].domet) {
            brojac++;
        }
    }
    return brojac;
}

int main(void) {
    BaznaStanica s[3] = {
        { { 1, 1 }, 1 },
        { { 2, 3 }, 3 },
        { { 5, 8 }, 4 }
    };

    Point k = { 1, 1 };
    printf("%d", bazneStaniceUBlizini(s, 3, k));

    return 0;
}