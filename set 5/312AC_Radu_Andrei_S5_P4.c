#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void transformaCaractere(char *c1, char *c2, char *c3, bool *rezultat) {
    if (isalpha(*c1) && isalpha(*c2) && isalpha(*c3)) {
        *c1 = toupper(*c1);
        *c2 = toupper(*c2);
        *c3 = toupper(*c3);
        *rezultat = true;
    }
    else *rezultat = false;
}

void main () {
    char caracter1, caracter2, caracter3;
    printf("Introdu cele 3 caractere: ");
    scanf("%c %c %c", &caracter1, &caracter2, &caracter3);
    bool succes = false;

    transformaCaractere(&caracter1, &caracter2, &caracter3, &succes);

    if (succes) {
        printf("Transformarea a avut loc cu scucces!\n");
        printf("%c %c %c", caracter1, caracter2, caracter3);
    }
    else {
        printf("Transformarea nu a putut avea loc!");
    }
}