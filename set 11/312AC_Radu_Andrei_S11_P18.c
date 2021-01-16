#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void unesteFisiere(FILE* output, FILE* primul, FILE* alDoilea) {
    fseek(output, 0, SEEK_SET);
    fseek(primul, 0, SEEK_SET);
    fseek(alDoilea, 0, SEEK_SET);

    char linie1[1000], linie2[1000];

    while (fgets(linie1, 1000, primul) != NULL && fgets(linie2, 1000, alDoilea) != NULL) {
        if (linie1 != NULL) {
            fprintf(output, "%s", linie1);
        }
        if (linie2 != NULL) {
            fprintf(output, "%s", linie2);
        }
    }
}

void main () {
    FILE* fisierOutput = fopen("P18.txt", "w+");
    FILE* fisier1 = fopen("fis1.txt", "w+");
    FILE* fisier2 = fopen("fis2.txt", "w+");

    if (!fisierOutput || !fisier1 || !fisier2) {
        printf("Nu am putut deschide unul din fisiere.");
        exit(1);
    }

    printf("Scrie continutul primului fisier: \n");
    adaugaInFisier(fisier1);

    printf("Scrie continutul celui de-al doilea fisier: \n");
    adaugaInFisier(fisier2);

    unesteFisiere(fisierOutput, fisier1, fisier2);

}