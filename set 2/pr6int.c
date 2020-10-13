#include <stdio.h>

void main () {
    int n, negative = 0, pozitive = 0;
    
    do {
        printf("Introdu un numar: ");
        scanf("%d", &n);
        if (n < 0) negative ++;
        else pozitive ++;
    } while (n != 0);

    printf("pozitive = %d\n", pozitive);
    printf("negative = %d", negative);
}