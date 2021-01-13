#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main () {
    FILE* fisierText = fopen("problema3Text.txt", "w+");
    FILE* fisierBinar = fopen("problema3Binar.bin", "wb");

    if (fisierText == NULL || fisierBinar == NULL) {
        printf("Unul din fisiere nu a putut fi deschis.");
        exit(1);
    }

    int* vector = (int*)calloc(200, sizeof(int));
    int lungime;
    printf("Introdu lungimea vectorului: ");
    scanf("%d", &lungime);

    for (int i = 0; i < lungime; ++i) {
        printf("vector[%d] = ", i);
        scanf("%d", &vector[i]);
        fprintf(fisierText, "%d ", vector[i]);
    }
    fwrite(vector, sizeof(int), sizeof(vector), fisierBinar);
    fclose(fisierBinar);

    int vectorBinar[lungime];
    fisierBinar = fopen("problema3Binar.bin", "rb");
    rewind(fisierText);

    printf("Inputul din fisierul binar: ");
    fread(vectorBinar, sizeof(int), sizeof(vector), fisierBinar);
    for (int i = 0; i < lungime; ++i) {
        printf("%d ", vectorBinar[i]);
    }
    printf("\n");

    char prop[256];
    printf("Inputul din fisierul text: ");
    int contor = 0, vectorText[lungime];
    while (fgets(prop, 256, fisierText)) {
        char* numarString = strtok(prop, " ");
        while (numarString) {
            char nr[10];
            strcpy(nr, numarString);
            int contorCifra = 0;
            vectorText[contor] = 0;
            while (nr[contorCifra] != 0) {
                vectorText[contor] = vectorText[contor] * 10 + (nr[contorCifra] - '0');
                contorCifra++;
            }
            contor++;
            numarString = strtok(NULL, " ");
        }
    }
    for (int i = 0; i < lungime; ++i) {
        printf("%d ", vectorText[i]);
    }
}