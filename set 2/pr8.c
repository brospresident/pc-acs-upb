#include <stdio.h>

void main () {
    int n;
    char varianta;
    do {
        printf("Introdu un numar: ");
        scanf("%d", &n);
        printf("Ati introuds numarul %d. \n", n);
        printf("Doriti sa continuati? D/N: ");
        scanf(" %c", &varianta);
    } while (varianta != 'N');
}

/* In citirea variabilei varianta a fost folosit un spatiu liber inainte de %c pentru a face scanf() sa sara peste caracterul \n care e inaintea caracterului pe care vrem sa il citim.*/