#include <stdio.h>
#include <limits.h>

void main () {
    int A[10][10], n;

    printf("Introdu numarul de elemente: ");
    scanf("%d", &n);

    // subpunct a
    int minim = INT_MAX, maxim = INT_MIN;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
            if (A[i][j] < minim) minim = A[i][j];
            if (A[i][j] > maxim) maxim = A[i][j];
        }
    }

    printf("Maximul gasit in matrice este %d.\n", maxim);
    printf("Minimul gasit in matrice este %d.\n", minim);

    // subpunct b
    for (int i = 0; i < n; ++i) {
        A[i][i] = maxim;
    }
    printf("Matricea A dupa inlocuirea elementelor de pe diagonala principala cu maximul gasit: \n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // subpunct c
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j >= n - i) {
                A[i][j] = minim;
            }
        }
    }
    printf("Matricea A dupa inlocuirea elementelor de sub diagonala secundara cu minimul gasit: \n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

}