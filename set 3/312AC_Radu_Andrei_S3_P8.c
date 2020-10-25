#include <stdio.h>

void main () {
    int A[5][5], B[5][5], m, n, p, q;

    printf("Introdu dimensiunile lui A(m, n): ");
    scanf("%d%d", &m, &n);

    printf("Introdu dimensiunile lui B(p, q): ");
    scanf("%d%d", &p, &q);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < q; ++j) {
            printf("B[%d][%d] = ", i, j);
            scanf("%d", &B[i][j]);
        }
    }
    int Suma[5][5];
    // Adunare
    if (m != p || n != q) printf("Nu se poate efectua adunarea!"); // daca numarul de linii sau coloane al lui A este diferit de cel al lui B nu se poate efectua adunarea
    else {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                Suma[i][j] = A[i][j] + B[i][j];
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%d ", Suma[i][j]);
            }
            printf("\n");
        }
    }

    

    // Inmultire
    if (n != p) printf("Nu se poate efectua inmultirea!"); // daca numarul de coloane al lui a e diferit de numarul de coloane al lui b nu se poate efectua inmultirea
    else {
        int Produs[5][5];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < p; ++j) {
                Produs[i][j] = 0;
                for (int k = 0; k < n; ++k) {
                    Produs[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < p; ++j) {
                printf("%d ", Produs[i][j]);
            }
            printf("\n");
        }
    }
}