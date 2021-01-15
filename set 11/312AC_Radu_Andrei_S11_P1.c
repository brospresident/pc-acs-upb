#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool verificaCuvant(char* cuvant, int len) { // daca nu contine doar litere, cifre sau cratima false
    for (int i = 0; i < len - 1; ++i) {
        if (isalpha(cuvant[i])) continue;
        else if (isdigit(cuvant[i])) continue;
        else if (cuvant[i] == '-');
        else return false;
    }
    if (cuvant[len - 1] == '.' || cuvant[len - 1] == '!' || cuvant[len - 1] == '?') return true;
}

int verificaPropozitie(char* propozitie, int lungime) {
    int count = 0;
    for (int i = 0; i < lungime; ++i) {
        if (propozitie[i] == '.' || propozitie[i] == '!' || propozitie[i] == '?') count++;
        if (propozitie[i] == 0 && isalpha(propozitie[i - 1])) count++;
    }
    return count;
}

int numaraCuvinte(FILE* fisier) {
    int cuvinte = 0;
    char cuvant[100];
    fseek(fisier, 0, SEEK_SET);

    while (fscanf(fisier, "%s", cuvant) != EOF) {
        int lungime = strlen(cuvant);
        if (verificaCuvant(cuvant, lungime)) cuvinte++;
    }

    return cuvinte;
}

int numaraPropozitii(FILE* fisier) {
    fseek(fisier, 0, SEEK_SET);
    int propozitii = 0;
    char propozitie[1000];
    while (fgets(propozitie, 1000, fisier)) {
        int lungime = strlen(propozitie);
        int nr = verificaPropozitie(propozitie, lungime);
        propozitii += nr;
    }
    return propozitii;
}

void adaugaInFisier(FILE* fisier) {
    char optiune = 'D';
    do {
        char linie[1000];
        printf("Scrie o noua linie pentru a o adauga in fisier: \n");
        scanf(" %[^\n]s", linie);
        fprintf(fisier, "%s", linie);
        printf("Vrei sa adaugi o noua linie? (D / N) ");
        scanf(" %c", &optiune);
        fprintf(fisier, "\n");
    } while (optiune != 'N');
}

void main () {
    FILE* fisierPropozitii = fopen("P1.txt", "w+");

    if (fisierPropozitii == NULL) {
        printf("Nu s-a putut deschide fisierul.");
        exit(1);
    }

    adaugaInFisier(fisierPropozitii);
    fseek(fisierPropozitii, 0, SEEK_SET);

    int cuv = numaraCuvinte(fisierPropozitii);
    printf("Fisierul are %d cuvinte.\n", cuv);

    int prop = numaraPropozitii(fisierPropozitii);
    printf("Fisierul are %d propozitii.\n", prop);

}