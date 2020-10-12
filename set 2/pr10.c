#include <stdio.h>

void main () {
    int n;
    printf("Introduceti un numar: ");
    scanf("%d", &n);
    while (n) {
        printf("%d ", n % 10);
        n /= 10;
    }
}