#include <stdio.h>
#include <limits.h>

void gasesteMaximLiniiColoane(int mat[][10], int len, int* maxL, int* maxCol) {
    int sumaL = 0, sumaLin = 0, sumaC = 0, sumaCol = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            sumaL += mat[i][j];
        }
        if (sumaL > sumaLin) { 
            *maxL = i;
            sumaLin = sumaL;
        }
    }

    for (int i = 0; i < len; ++i) {
        int linie = 0;
        while (linie < len) {
            sumaC += mat[linie][i];
            linie++;
        }
        if (sumaC > sumaCol) {
            *maxCol = i;
            sumaCol = sumaC;
        }
    }
}

void main () {
    int matrice[10][10], n;

    printf("Introdu dimensiunile matricei: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("matrice[%d][%d] = ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }

    int maximLinie = INT_MIN, maximColoana = INT_MIN;

    gasesteMaximLiniiColoane(matrice, n, &maximLinie, &maximColoana);

    printf("Suma maxima pe linii se afla pe linia %d.\n", maximLinie);
    printf("Suma maxima pe coloane se afla pe coloana %d.", maximColoana);
}
