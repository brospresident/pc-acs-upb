#include <stdio.h>

void main () {
    int mat[10][10], n, m;

    printf("Introdu dimensiunile matricii: ");
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("mat[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }


    printf("Matricea inainte de ordonarea elementelor pare de pe linie para: \n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < n; i += 2) {
        int linie = i;
        for (int l = 0; l < m - 1; ++l) {
            for (int k = 0; k < m - l - 1; ++k) {
                if (mat[linie][k] % 2 == 0) {
                    int kVechi = k;
                    k++;
                    while (mat[linie][k] % 2 != 0 && k < m - l - 1) {
                        k++;
                    }
                    if (mat[linie][kVechi] > mat[linie][k]) {
                        int temp = mat[linie][kVechi];
                        mat[linie][kVechi] = mat[linie][k];
                        mat[linie][k] = temp;
                    }
                }
            }
        }
    }

    printf("Matricea dupa ordonarea elementelor pare de pe linie para: \n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

}