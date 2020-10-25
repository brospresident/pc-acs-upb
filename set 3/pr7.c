#include <stdio.h>

void main () {
    int a[5][5];

    int linii;
    printf("Introdu numarul de linii: ");
    scanf("%d", &linii);

    // e patratica deci linii == coloane

    for (int i = 0; i < linii; ++i) {
        for (int j = 0; j < linii; ++j) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // Subpunct a
    for (int i = 0; i < linii; ++i) {
        for (int j = 0; j < linii; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // Subpunct b
    printf("Diagonala principala: ");
    for (int i = 0; i < linii; ++i) printf("%d ", a[i][i]);

    printf("\nDiagonala secundara: ");
    for (int i = 0; i < linii; ++i) {
        printf("%d ", a[i][linii - i - 1]);
    }

    // Subpunct c
    printf("\nValorile din triunghiul superior: \n");
    for (int i = 0; i < linii; ++i) {
        for (int j = i + 1; j < linii; ++j) {
            printf("%d ", a[i][j]);
        }
    }

    printf("\nValorile din triunghiul inferior: ");
    for (int i = 0; i < linii; ++i) {
        for (int j = 0; j < i; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // Subpunct d
    printf("\nElementele de pe contur:\n ");
    for (int i = 0; i < linii; ++i) {
        printf("%d ", a[0][i]);
    }
    printf("\n");
    for (int i = 0; i < linii; ++i) {
        printf("%d ", a[i][linii - 1]);
    }
    printf("\n");
    for (int i = linii - 1; i >= 0; --i) {
        printf("%d ", a[linii - 1][i]);
    }
    printf("\n");
    for (int i = linii - 1; i >= 0; --i) {
        printf("%d ", a[i][0]);
    }
    printf("\nElementele din interiorul conturului: ");
    for (int i = 1; i < linii - 1; ++i) {
        for (int j = 1; j < linii - 1; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // Subpunct e
    printf("Parcurgerea in spirala: ");
    int contor = 0;
    while (contor < linii) {
        if (contor == linii - 1) {
             printf("%d", a[contor][contor]);
             break;
        }
        for (int i = contor; i < linii; ++i) {
            printf("%d ", a[contor][i]);
        }
        for (int i = contor; i < linii; ++i) {
            printf("%d ", a[i][linii - 1]);
        }
        for (int i = linii - 1; i >= contor; --i) {
            printf("%d ", a[linii - 1][i]);
        }
        for (int i = linii - 1; i >= contor; --i) {
            printf("%d ", a[i][contor]);
        }
        contor++;
        linii--;
        
    }
    

}