#include <stdio.h>

void main () {
    int n;
    printf("Introduceti un numar: ");
    scanf("%d", &n);
    int a0 = 0, a1 = 1, nr;
    for (int i = 2; i <= n; ++i) {
        nr = a0 + a1;
        a0 = a1;
        a1 = nr;
        printf("%d ", nr);
    }    
}