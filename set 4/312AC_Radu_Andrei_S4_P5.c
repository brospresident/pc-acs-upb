#include <stdio.h>

void main () {
    int vector[10], n, vectorS[10];

    printf("Introdu numarul de elemente: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("vector[%d] = ", i);
        scanf("%d", &vector[i]);
        vectorS[i] = vector[i];
    }

    // metoda 1
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (vector[j] < vector[j + 1]) {
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", vector[i]);
    }

    printf("\n");

    // metoda 2
    int j = 0;
    for (int i = 1; i < n; ++i) {
        for (j = 0; j < i && vectorS[j] >= vectorS[i]; ++j);
        int temp = vectorS[i];
        for (int k = i - 1; k >= j; --k) {
            vectorS[k + 1] = vectorS[k];
        }
        vectorS[j] = temp;

    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", vectorS[i]);
    }
}