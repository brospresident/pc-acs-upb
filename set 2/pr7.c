#include <stdio.h>

void main () {
    int n;
    
    printf("Introduceti un numar: ");
    scanf("%d", &n);

    do {
        if (n >= 0) break;
        printf("Ati introdus un numar negativ. Introduceti o valoare pozitiva: ");
        scanf("%d", &n);
    } while (n < 0);

    printf("Ati introdus numarul pozitiv: %d.", n);
}