#include <stdio.h>

void permutaCircularLaDreapta(int* vector, int len) {
    int element = vector[len - 1];
    for (int i = len - 2; i >= 0; --i) {
        vector[i + 1] = vector[i];
    }
    vector[0] = element; 
}

void main () {
    int matrice[10][10], n;

    printf("Introdu numarul de elemente: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("matrice[%d][%d] = ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        int I = i;
        while (I--) {
            permutaCircularLaDreapta(*(matrice + i), n);
        }
    }

    printf("Matricea cu elementele permutate: \n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}