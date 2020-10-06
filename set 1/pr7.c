#include <stdio.h>

void main () {
    int nr;
    do {
        printf("Introduceti un numar mai mare sau egal cu 3: ");
        scanf("%d", &nr);
    } while (nr < 3);
    // afisarea in linie
    printf("%d %d %d\n", nr - 1, nr, nr + 1);
    // afisarea in coloana
    printf("%d\n%d\n%d", nr - 1, nr, nr + 1);
}