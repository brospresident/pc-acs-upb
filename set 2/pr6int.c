#include <stdio.h>

void main () {
    int n;
    int pozitive = 0, negative = 0;
    do {
        printf("Introdu un numar: ");
        scanf("%d", &n);
        if (n < 0) negative ++;
        else if (n > 0) pozitive ++;
    } while (n != 0);
    printf("pozitive = %d\n", pozitive);
    printf("negative = %d", negative);
}