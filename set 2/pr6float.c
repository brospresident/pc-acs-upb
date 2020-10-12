#include <stdio.h>

void main () {
    float numar;
    
    int pozitive = 0, negative = 0;
    do {
        printf("Introduceti un numar: ");
        scanf("%f", &numar);
         if (numar < 0) negative ++;
        else if (numar > 0) pozitive ++;
    } while (numar != 0);
    printf("pozitive = %d\n", pozitive);
    printf("negative = %d", negative);
}