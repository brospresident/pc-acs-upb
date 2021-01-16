#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adaugaInFisier(FILE* fisier) {
    char linie[1000];
    while (1) {
        if (strcmp(linie, "EOF") == 0) { 
            return;
        }
        scanf(" %[^\n]s", linie);
        fprintf(fisier, "%s", linie);
        fprintf(fisier, "\n");
    }
}

void afiseazaFisier(FILE* fisier) {
    char linie[1000];
    int nrOrdine = 0;
    while (fgets(linie, 1000, fisier) != NULL || nrOrdine != 20) {
        printf("%s", linie);
        nrOrdine++;
    }
}

void main () {
    FILE* fisier = fopen("P20.txt", "w+");

    if (!fisier) {
        printf("Nu s-a putut deschide!");
        exit(1);
    }

    adaugaInFisier(fisier);

    fseek(fisier, 0, SEEK_SET);
    afiseazaFisier(fisier);
    
    char opt;
    scanf(" %c", &opt);
    while (opt != 's') {
        afiseazaFisier(fisier);
        scanf(" %c", &opt);
    }
}