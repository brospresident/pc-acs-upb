#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct persoana {
    char nume[24];
    char prenume[24];
    char adresa[128];
    char sex;
    float greutate;
    int varsta;
    char culoarePar[15];
    char culoareOchi[15];
} Persoana;

void scrieFisier(FILE* fisier, Persoana* persoane, int inceput, int final) {
    for (int i = inceput; i < final; ++i) {
        fprintf(fisier, "Nume: %s\n", persoane[i].nume);
        fprintf(fisier, "Prenume: %s\n", persoane[i].prenume);
        fprintf(fisier, "Adresa: %s\n", persoane[i].adresa);
        fprintf(fisier, "Sex: %c\n", persoane[i].sex);
        fprintf(fisier, "Greutate: %.2f", persoane[i].greutate);
        fprintf(fisier, "Varsta: %d", persoane[i].varsta);
        fprintf(fisier, "Par: %s", persoane[i].culoarePar);
        fprintf(fisier, "Ochi: %s\n", persoane[i].culoareOchi);
    }
}

void citestePersoane(Persoana* persoane, int nrPersoane, int* existente) {
    if (*existente + nrPersoane > 1000) {
        printf("Limita de persoane a fost depasita!");
        return;
    }
    for (int i = *existente; i < nrPersoane + *existente; ++i) {
        printf("Nume: ");
        scanf(" %[^\n]s", persoane[i].nume);

        printf("Prenume:");
        scanf(" %[^\n]s", persoane[i].prenume);

        printf("Adresa: ");
        scanf(" %[^\n]s", persoane[i].adresa);

        printf("Sex: ");
        scanf(" %c", persoane[i].sex);

        printf("Greutate: ");
        scanf(" %lf", persoane[i].greutate);

        printf("Varsta: ");
        scanf(" %d", persoane[i].varsta);

        printf("Par: ");
        scanf(" %[^\n]s", persoane[i].culoarePar);

        printf("Ochi: ");
        scanf(" %[^\n]s", persoane[i].culoareOchi);
    }
    *existente += nrPersoane;
}

void main () {
    Persoana* vectorPersoane = (Persoana*)calloc(1000, sizeof(Persoana));

    FILE* fisier = fopen("P4.txt", "w+");

    if (!fisier) {
        printf("Nu am putut deschide fisierul.");
        exit(1);
    }

    int existente = 0;

    char opt[50];
    printf("Lista optiuni: \n");
    printf("inchide = inchide program\n");
    printf("adauga = citeste date pentru un numar precizat de persoane si le scrie in fisier\n");
    printf("nume = te pune sa citesti un nume si afiseaza datele despre toate persoanele cu numele acela\n");
    printf("daca nume == oricare se afiseaza toata lista de persoane\n");

    while (strcmp(opt, "inchide") != 0) {
        printf("Introdu o optiune: ");
        scanf(" %[^\n]s", opt);

        if (strcmp(opt, "adauga") == 0) {
            int nr;
            printf("Cate persoane vrei sa adaugi? ");
            scanf(" %d", &nr);
            citestePersoane(vectorPersoane, nr, &existente);
            
        }
    }
    
}