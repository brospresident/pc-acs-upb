#include <stdio.h>

void main () {
    int v[25], n, p;

    printf("Introdu numarul de elemente: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }

    printf("Introdu numarul de permutari la dreapta: ");
    scanf("%d", &p);

    // la dreapta
    while (p--) {
        int element = v[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            v[i + 1] = v[i];
        }
        v[0] = element;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }

    printf("\nIntrodu numarul de permutari la stanga: ");
    scanf("%d", &p);

    // la stanga
    while (p--) {
        int element = v[0];
        for (int i = 1; i < n; ++i) {
            v[i - 1] = v[i];
        }
        v[n - 1] = element;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }

}