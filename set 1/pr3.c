#include <stdio.h>

void main () {
    int numar;
    // citire
    printf("Introduceti un numar de la tastatura: ");
    scanf("%d", &numar);

    numar *= 2; // dublul numarului

    // afisare in bazele cerute
    printf("In baza 10: %d\n", numar);
    printf("In baza 8: %o\n", numar);
    printf("In baza 16: %x\n", numar);

}