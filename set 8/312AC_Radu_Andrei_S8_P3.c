#include <stdio.h>
#include <limits.h>
#include <string.h>

struct Informatie {
    char firma[24];
    char produs[10];
    int cantitate;
};

void main () {
    int n;

    printf("Introdu numarul de firme: ");
    scanf("%d", &n);

    struct Informatie informatii[10];

    for (int i = 0; i < n; ++i) {
        printf("Introdu informatii despre firma %d: ", i);
        scanf(" %[^\n]s", informatii[i].firma);
        scanf(" %[^\n]s", informatii[i].produs);
        scanf("%d", &informatii[i].cantitate);
    }

    /*for (int i = 0; i < n; ++i) {
        printf("Firma %d: %s %s %d", i, informatii[i].firma, informatii[i].produs, informatii[i].cantitate);
    }*/

    char produsDeCautat[10];
    
    printf("Introdu produsul pe care vrei sa il cauti: ");
    scanf(" %[^\n]s", produsDeCautat);

    // subpunct a
    int cantMaxim = INT_MIN;
    char firmaRezultat[10];
    for (int i = 0; i < n; ++i) {
        if (strcmp(informatii[i].produs, produsDeCautat) == 0) {
            if (informatii[i].cantitate > cantMaxim) {
                cantMaxim = informatii[i].cantitate;
                strcpy(firmaRezultat, informatii[i].firma);
            }
        }
    }

    printf("Firma cu cea mai mare productie pentru produsul %s este %s.\n", produsDeCautat, firmaRezultat);

    // subpunct b
    char Produs[10];
    int cantitate = 0;

    printf("Introdu produsul pentru care vrei sa aflii cantitatea: ");
    scanf(" %[^\n]s", Produs);

    for (int i = 0; i < n; ++i) {
        if (strcmp(informatii[i].produs, Produs) == 0) {
            cantitate += informatii[i].cantitate;
        }
    }

    printf("Cantiteatea totala care poate fi cumparata din produsul %s este %d.", Produs, cantitate);
}