#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void main () {
    int nrPropozitii;
    printf("Introdu numarul de propozitii: ");
    scanf("%d", &nrPropozitii);
    
    FILE* fisier = fopen("problema2.txt", "w+");

    if (fisier == NULL) {
        printf("Nu a putut fi deschis fisierul pentru problema 2.");
        exit(1);
    }

    for (int i = 0; i < nrPropozitii; ++i) {
        char propozitie[256];
        scanf(" %[^\n]s", propozitie);
        fputs(propozitie, fisier);
        fputs("\n", fisier);
    }

    // SUBPUNCT A
    rewind(fisier);
    printf("\n");
    char prop[256];
    while (fgets(prop, 256, fisier)) { // citesc fiecare linie si o afisez
        printf("%s", prop);
    }

    // SUBPUNCT B
    char cuvantCautat[256];
    int linie = 0;
    printf("Introdu cuvantul pe care vrei sa il cauti: ");
    scanf(" %s", cuvantCautat);
    rewind(fisier);
    printf("Liniile pe care apare cuvantul %s sunt: ", cuvantCautat);
    while (fgets(prop, 256, fisier)) {
        char* cuv = strtok(prop, " \n"); // parcurg cuvant cu cuvant fisierul dupa separatorii spatiu sau \n
        while (cuv) {
            //printf("%s %s\n", cuv, cuvantCautat);
            if (strcmp(cuv, cuvantCautat) == 0) {
                printf("%d ", linie + 1);
                break; // daca l-am gasit deja pe linia pe care ma aflu opresc while si trec la urmatoarea.
            }
            cuv = strtok(NULL, " \n");
        }
        linie++;
    }
    printf("\n");

    // SUBPUNCT C
    rewind(fisier);
    int cuvinte = 0, caractere = 0;
    while (fgets(prop, 256, fisier)) {
        char* cuv = strtok(prop, " \n");
        while (cuv) {
            cuvinte++;
            caractere += strlen(cuv);
            cuv = strtok(NULL, " \n");
        } // nu am considerat spatiile si liniile noi drept caractere. doar literele
    }
    printf("Fisierul contine %d cuvinte si %d caractere.\n", cuvinte, caractere);

    // SUBPUNCT D
    rewind(fisier);
    int lungimeMaxima = INT_MIN;
    while (fgets(prop, 256, fisier)) { // parcurg fisierul si aflu lungimea maxima a fiecarei linii apoi il mai parcurg o data si afisez liniile care au lungimea respectiva
        int lungimeCurenta = strlen(prop);
        if (lungimeMaxima < lungimeCurenta) { 
            lungimeMaxima = lungimeCurenta;
        }
    }

    rewind(fisier);
    printf("Propozitia cu lungime maxima este: \n");
    while (fgets(prop, 256, fisier)) {
        if (lungimeMaxima == strlen(prop)) {
            printf("%s\n", prop);
        }
    }

    fclose(fisier);
}