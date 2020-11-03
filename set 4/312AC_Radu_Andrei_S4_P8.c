#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void main () {
    int vector[10], n;

    printf("Introdu numarul de elemente: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("vector[%d] = ", i);
        scanf("%d", &vector[i]);
    }

    int minim = INT_MAX, maxim = INT_MIN, pozMin = 0, pozMax = 0;

    for (int i = 0; i < n; ++i) {
        if (vector[i] < minim) {
            minim = vector[i];
            pozMin = i;
        }
        if (vector[i] > maxim) {
            maxim = vector[i];
            pozMax = i;
        }
    }

    int l = pozMin < pozMax ? pozMin : pozMax;
    int u = pozMin > pozMax ? pozMin : pozMax;

    for (int i = l; i <= u - 1; ++i) {
        for (int j = l; j <= u - 1; ++j) {
            if (vector[j] > vector[j + 1]) {
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", vector[i]);
    }
}