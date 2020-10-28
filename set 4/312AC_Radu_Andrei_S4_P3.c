#include <stdio.h>

void main () {
    int vector[10], n;

    printf("Introdu numarul de elemente: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("vector[%d] = ", i);
        scanf("%d", &vector[i]);
    }

    int pozitieStart = 0, pozitieFinal = 0, pozitieStartEx = 0, pozitieFinalEx = 0;

    for (int i = 0; i < n - 1; ++i) {
        pozitieStartEx = i;
        while (vector[i] < vector[i + 1]) {
            i++;
        }
        pozitieFinalEx = i + 1;
        if (pozitieFinal - pozitieStart < pozitieFinalEx - pozitieStartEx) {
            pozitieFinal = pozitieFinalEx;
            pozitieStart = pozitieStartEx;
        }
    }

    for (int i = pozitieStart; i < pozitieFinal; ++i) {
        printf("%d ", vector[i]);
    }

}