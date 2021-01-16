#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct maplocalitati {
    char nume[50];
    int persoane;
} mapLocalitati;

/*
    Am implementat o structura mapLocalitati care are o functionare asemanatoare HashMap-urilor din Java. Aceasta contine un camp cheie(nume) si un camp valoare(persoane).
    Pentru aceasta am implementat o functie care verifica daca un nume de oras apare deja in vectorul de structura si o functie care construieste vectorul verificand daca
    o localitate exista deja in vector. In cazul in care exista creste numarul de persoane cu 1 iar in cazul in care nu exista o adauga si seteaza numarul de persoane la 1.
*/

void adaugaInFisier(FILE* fisier) {
    char* linie = (char*)malloc(1000);
    while (strcmp(linie, "EOF") != 0) {
        scanf(" %[^\n]s", linie);
        if (strcmp(linie, "EOF") == 0) { 
            break;
        }
        fprintf(fisier, "%s\n", linie);
    }
    free(linie);
}

int numaraLocalitati(FILE* fisier) {
    fseek(fisier, 0, SEEK_SET);
    int rezultat = 0;
    char linie[1000];
    while (fgets(linie, 1000, fisier) != NULL) {
        rezultat++;
    }
    return rezultat;
}

int contineLocalitate(mapLocalitati* harta, int lungime, char* localitate) {
    for (int i = 0; i < lungime; ++i) {
        char loc[100];
        if (strcmp(harta[i].nume, localitate) == 0) {
            return i;
        }
    }
    return -1;
}

int construiesteMap(FILE* fisier, mapLocalitati* harta, int nrLocalitati) {
    fseek(fisier, 0, SEEK_SET);
    int contor = 0;
    char localitate[1000];
    while (fscanf(fisier, "%s", localitate) != EOF) {
        int rez = contineLocalitate(harta, contor, localitate);
        if (rez != -1) {
            harta[rez].persoane++;
        }
        else {
            strcpy(harta[contor].nume, localitate);
            harta[contor].persoane = 1;
            contor++;
        }
    }
    return contor;
}


void main () {
    FILE* localitati = fopen("P14.txt", "w+");

    if (!localitati) {
        printf("Nu am putut deschide fisierul.");
        exit(1);
    }

    adaugaInFisier(localitati);

    int nrLocalitati = numaraLocalitati(localitati);

    mapLocalitati* map = (mapLocalitati*)malloc(nrLocalitati);

    int lungimeHashMap = construiesteMap(localitati, map, nrLocalitati);

    for (int i = 0; i < lungimeHashMap; ++i) {
        printf("%s -> %d\n", map[i].nume, map[i].persoane);
    }

    free(map);
    fclose(localitati);
}