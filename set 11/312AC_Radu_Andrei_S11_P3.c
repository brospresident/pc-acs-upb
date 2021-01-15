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

int numaraCaractere(FILE* fisier) {
    fseek(fisier, 0, SEEK_SET);
    int caractere = 0;
    char caracter = fgetc(fisier);
    while (caracter != EOF) {
        if (caracter != '\n') caractere++;
        caracter = fgetc(fisier);
    }
    return caractere;
}

int numaraCuvinte(FILE* fisier) {
    fseek(fisier, 0, SEEK_SET);
    int cuvinte = 0;
    char cuvant[100];
    while (fscanf(fisier, "%s", cuvant) != EOF) {
        cuvinte++;
    }
    return cuvinte;
}

int numaraLinii(FILE* fisier) {
    fseek(fisier, 0, SEEK_SET);
    int linii = 0;
    int caracter = fgetc(fisier);
    while (caracter != EOF) {
        if (caracter == '\n') linii++;
        caracter = fgetc(fisier);
    }
    return linii - 1; // functia care adauga text in fisier mai pune o linie inainte sa termine de citit deci scadem o linie care e goala oricum
}

int lungimeaCuvantului(FILE* fisier, int nrOrdine) {
    fseek(fisier, 0, SEEK_SET);
    int cuvinte = 0;
    char cuvant[100];
    while (fscanf(fisier, "%s", cuvant) != EOF) {
        cuvinte++;
        if (cuvinte == nrOrdine) {
            return strlen(cuvant);
        }
    }
    return 0;
}


void main () {
    FILE* fisier = fopen("P3.txt", "w+");

    if (!fisier) {
        printf("Nu s-a putut deschide.");
        exit(1);
    }

    adaugaInFisier(fisier);

    printf("Fisierul contine %d caractere.\n", numaraCaractere(fisier));

    printf("Fisierul are %d cuvinte.\n", numaraCuvinte(fisier));

    printf("Fisierul are %d linii.\n", numaraLinii(fisier));

    int nr;
    printf("Introdu un numar de ordine: ");
    scanf("%d", &nr);

    int lungimeCuvant = lungimeaCuvantului(fisier, nr);

    if (lungimeCuvant != 0) {
        printf("Cuvantul cautat are %d caractere.", lungimeCuvant);
    }
    else {
        printf("Nu exista un cuvant cu acel numar de ordine.");
    }

}