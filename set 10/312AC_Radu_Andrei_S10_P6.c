#include <stdio.h>
#include <stdlib.h>

typedef struct persoana {
    char nume[25];
    char prenume[25];
    float varsta;
} Persoana;

void scrieInFisier(Persoana* pers, FILE* text, FILE* binar) {
    for (int i = 0; i < 1; ++i) {
        printf("Introdu numele persoanei %d: ", i + 1);
        scanf(" %[^\n]s", pers[i].nume);
        printf("Introdu prenumele persoanei %d: ", i + 1);
        scanf(" %[^\n]s", pers[i].prenume);
        printf("Introdu varsta persoanei %d: ", i + 1);
        scanf("%f", &pers[i].varsta);
        fprintf(text, "%s %s %f\n", pers[i].nume, pers[i].prenume, pers[i].varsta);
        fwrite(&pers[i], sizeof(pers), 3, binar);
    }
}


void main () {
    Persoana* persoane = (Persoana*)calloc(5, sizeof(Persoana));

    if (persoane == NULL) {
        printf("Nu am putut aloca vectorul de persoane.");
        exit(1);
    }

    FILE* fisierText = fopen("problema6Text.txt", "w+");
    FILE* fisierBinar = fopen("problema6Binar.txt", "wb");

    scrieInFisier(persoane, fisierText, fisierBinar);

    fclose(fisierText);
    fclose(fisierBinar);
}