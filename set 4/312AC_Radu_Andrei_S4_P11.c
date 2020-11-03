#include <stdio.h>

void main () {
    int matrice[10][10], n;

    printf("Introdu lungimea matricei: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("matrice[%d][%d] = ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }

    char subpunct;
    printf("Ce subpunct vrei sa testezi pe matricea introdusa?: ");
    scanf(" %c", &subpunct);

    printf("Matricea inainte de ordonare: \n");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%d ", matrice[i][j]);
            }
            printf("\n");
        }

    if (subpunct == 'a' || subpunct == 'A') { // voi ordona crescator elementele de pe fiecare linie folosind bubble sort
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                for (int l = 0; l < n - j - 1; ++l) {
                    if (matrice[i][l] > matrice[i][l + 1]) {
                        int temp = matrice[i][l];
                        matrice[i][l] = matrice[i][l + 1];
                        matrice[i][l + 1] = temp;
                    }
                }
            }
        }

        printf("Matricea cu liniile ordonate: \n");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%d ", matrice[i][j]);
            }
            printf("\n");
        }
    }
    else if (subpunct == 'b' || subpunct == 'B') { // voi ordona crescator
    // (sortez decat prima linie iar apoi pentru fiecare element interschimbat de pe prima linie, interschimb coloanele)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (matrice[0][j] > matrice[0][j + 1]) {
                    int temp = matrice[0][j];
                    matrice[0][j] = matrice[0][j + 1];
                    matrice[0][j + 1] = temp;
                    for (int l = 1; l < n; ++l) { // am inceput de la l = 1 deoarece linia 0 e deja sortata
                        int aux = matrice[l][j];
                        matrice[l][j] = matrice[l][j + 1];
                        matrice[l][j + 1] = aux;
                    }
                }
            }
        }

        printf("Matricea dupa efectuarea operatiilor: \n");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%d ", matrice[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("Acel subpunct nu exista.");
    }


}