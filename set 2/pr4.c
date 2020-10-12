#include <stdio.h>

void main () {
    int n;
    printf("Introdu un numar n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) printf("%d ", i);
    }
}