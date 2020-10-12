#include <stdio.h>

void main () {
    int n;
    do {
        printf("Introduceti mai multe numere naturale: ");
        scanf("%d", &n);
        printf("Ati introdus numarul %d\n", n);
    } while (n >= 0);

    printf("Ati introdus un numar negativ.");
}