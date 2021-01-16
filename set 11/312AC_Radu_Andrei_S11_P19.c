#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adaugaInFisier(FILE* fisier) {
    char linie[1000];
    while (strcmp(linie, "EOF") != 0) {
        scanf(" %[^\n]s", linie);
        if (strcmp(linie, "EOF") == 0) { 
            break;
        }
        fprintf(fisier, "%s\n", linie);
    }
}

void afiseazaColoane(FILE* fisier, int m, int n) {
    char linie[1000];
    fseek(fisier, 0, SEEK_SET);
    while (fgets(linie, 1000, fisier)) {
        for (int i = m; i <= n; ++i) {
            printf("%c", linie[i]);
        }
        printf("\n");
    }
}

void main () {
    FILE* fisier = fopen("P19.txt", "w+");

    if (!fisier) {
        printf("Nu s-a putut deschide!");
        exit(1);
    }

    adaugaInFisier(fisier);

    int m, n;
    scanf("%d%d", &m, &n);

    afiseazaColoane(fisier, m, n);
}