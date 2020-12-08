#include <stdio.h>
#include <string.h>

struct Autor {
    char nume[256], prenume[256], gen;
};

struct Carte {
    char titlul[256];
    int an;
    struct Autor autor;
};

void sortareLexicografica(struct Carte carti[], int n) {
    for (int i = 0; i < n; ++i) {
        struct Carte cheie;
        memcpy(&cheie, &carti[i], sizeof(struct Carte));
        int j = i - 1;

        while (j >= 0 && strcmp(carti[j].titlul, cheie.titlul) > 0) {
            memcpy(&carti[j + 1], &carti[j], sizeof(struct Carte));
            j--;
        }
        memcpy(&carti[j + 1], &cheie, sizeof(struct Carte));
    }
}


void main () {
    int nrCarti;
    struct Carte carti[10];

    printf("Introdu numarul de carti: ");
    scanf("%d", &nrCarti);

    // subpunct a
    for (int i = 0; i < nrCarti; ++i) {
        printf("Cartea %d\n", i);
        printf("Titlu: ");
        scanf(" %[^\n]s", carti[i].titlul);
        printf("Anul: ");
        scanf("%d", &carti[i].an);
        printf("Date autor: ");
        scanf(" %[^\n]s", carti[i].autor.nume);
        scanf(" %[^\n]s", carti[i].autor.prenume);
        scanf(" %c", &carti[i].autor.gen);
    }

    // subpunct b


    // subpunct c
    int an;
    char gen;
    printf("Introdu anul si genul: ");
    scanf("%d %c", &an, &gen);

    for (int i = 0; i < nrCarti; ++i) {
        if (carti[i].an == an && carti[i].autor.gen == gen) {
            printf("%s\n", carti[i].titlul);
        }
    }

    // subpunct d
    printf("\n");
    sortareLexicografica(carti, nrCarti);
    for (int i = 0; i < nrCarti; ++i) {
        printf("%s\n", carti[i].titlul);
    }
}