#include <stdio.h>

void main () {
    int lungime, latime;
    printf("Introduceti lungimea si latimea: \n");
    printf("Introduceti lungimea: ");
    scanf("%d", &lungime);
    printf("Introduceti latimea: ");
    scanf("%d", &latime);
    printf("perimetru = %d", 2 * (lungime + latime));
}